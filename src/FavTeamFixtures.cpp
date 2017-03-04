#include "FavTeamFixtures.h"
#include <rapidjson/document.h>
#include "utility.h"
#include  <iostream>
using namespace rapidjson;

FavTeamFixtures::FavTeamFixtures():curl(NULL),list(NULL)
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

void FavTeamFixtures::processRequest(const char* teamName)
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
    }
}

std::string FavTeamFixtures::getResultString()
{
    return resultString;
}

Map FavTeamFixtures::getResultMap()
{
    return resultMap;
}

void FavTeamFixtures::parseData(std::string& serverReply)
{
    const char* jsonData = serverReply.c_str();
    Document document;
    document.Parse(jsonData);
    if(document["fixtures"].IsArray()) {
        // fixtues is an array
        const Value& fixtures = document["fixtures"];
        for(auto it = fixtures.Begin(); it!= fixtures.End(); it++) {
            if(it->IsObject()) {

                // store the result in string
                resultString.append((*it)["homeTeamName"].GetString());
                resultString.append(" Vs ");
                resultString.append((*it)["awayTeamName"].GetString());
                resultString.append("\n");
                resultString.append(check_date((*it)["date"].GetString()));
                resultString.append(" at ");
                resultString.append(get_time((*it)["date"].GetString()));

                //store the result in the map
                resultMap.insert({"home_team", (*it)["homeTeamName"].GetString()});
                resultMap.insert({"away_team", (*it)["awayTeamName"].GetString()});
                resultMap.insert({"date", get_date((*it)["date"].GetString())});
                resultMap.insert({"time", get_time((*it)["date"].GetString())});
            }
        }
    }
}
