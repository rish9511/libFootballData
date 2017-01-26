#include "FavTeamFixtures.h"
#include <rapidjson/document.h>
#include  <iostream>
using namespace rapidjson;

FavTeamFixtures::FavTeamFixtures(const  char* name):teamName(name),
                                                    curl(NULL),
                                                    list(NULL)
{
    supportedTeams.insert({"liverpool","64"});
    supportedTeams.insert({"arsenal","57"});
    supportedTeams.insert({"chelsea","64"});
    supportedTeams.insert({"manchesterunited","66"});
    supportedTeams.insert({"tottenhamhotspur","73"});
    supportedTeams.insert({"barcelona","81"});
    supportedTeams.insert({"realmadrid","86"});

    //setup curl
    curl = curl_easy_init();

}

size_t FavTeamFixtures::receivedData(void *data, size_t size, size_t nmemb, std::string& serverReply)
{
        serverReply.append((char*) data, size * nmemb);
        return size * nmemb;
}


std::string FavTeamFixtures::processRequest()
{
    //check if the team supported
    auto search = supportedTeams.find(teamName);
    if(search != supportedTeams.end()) {

        auto uid = search->second;
        std::string serverReply;
        std::string url = "http://api.football-data.org/v1/teams/" + uid + "/fixtures?timeFrame=n2";
        if(curl) {
            CURLcode res;
            list = curl_slist_append(list, "X-Auth-Token: 06439b300b664499bf3d201d44d63c45");
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, receivedData);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, serverReply);
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                std::cout << "curl_easy_perform failed "<< curl_easy_strerror(res) << std::endl;
            }
            else {
                // parse the data;
                if(!serverReply.empty()){
                    parseData(serverReply);
                }

            }
        }
        return serverReply;
    }

    return "";
}

void FavTeamFixtures::parseData(std::string& serverReply)
{
    const char* jsonData = serverReply.c_str();
    Document document;
    document.Parse(jsonData);
    const char* date = "";
    const char* homeTeam = "";
    const char* awayTeam = "";
    serverReply  = "";
    for (auto  itr = document.MemberBegin(); itr != document.MemberEnd(); ++itr)
    {
        if(strcmp(itr->name.GetString(),"fixtures") == 0)
        {
             for(auto itr2 =  itr->value.Begin(); itr2 != itr->value.End(); itr2++)
             {
                 for (auto itr3 = itr2->MemberBegin(); itr3 != itr2->MemberEnd(); itr3++)
                 {
                     if(strcmp(itr3->name.GetString(),"homeTeamName") == 0)
                     {
                         homeTeam = itr3->value.GetString();
                     }
                     if(strcmp(itr3->name.GetString(),"awayTeamName") == 0)
                     {
                        awayTeam = itr3->value.GetString();
                     }
                     if(strcmp(itr3->name.GetString(),"date") == 0)
                     {
                         date =  itr3->value.GetString();
                     }

                 }

                 while(*homeTeam != NULL){
                     serverReply.push_back(*homeTeam);
                     homeTeam++;
                 }
                 serverReply.push_back(' ') ;
                 serverReply.push_back('v') ;
                 serverReply.push_back('s') ;
                 serverReply.push_back(' ') ;
                 while(*awayTeam != NULL){
                     serverReply.push_back(*awayTeam);
                     awayTeam++;
                 }
                 serverReply.push_back(' ');
                 serverReply.push_back('o');
                 serverReply.push_back('n');
                 serverReply.push_back(' ');
                 while(*date != NULL){
                     serverReply.push_back(*date);
                     date++;
                 }
                 serverReply.push_back('\n');

             }

        }
        // cout << itr->name.GetString() << " " << itr->value.GetType()<< endl;
    }

}
