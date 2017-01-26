// #include "UpcomingFixtures.h"
//
// #include <iostream>
// #include  <string>
//
// #include <rapidjson/document.h>
// #include <curl/curl.h>
//
// using namespace rapidjson;
// using namespace std;
//
// UpcomingFixtures::UpcomingFixtures():IRequestController(),
//                                     serverReply("")
// {
//
// }
//
// size_t UpcomingFixtures::receivedData(void *data, size_t size, size_t nmemb, std::string& serverReply)
// {
//         serverReply.append((char*) data, size * nmemb);
//         return size * nmemb;
// }
// std::string UpcomingFixtures::processRequest()
// {
//     // users wants to see the upcoming fixtures
//     // CURL* curl = IRequestController::setupCurl();
//     CURLcode res;
    // struct curl_slist* list;
//     CURL *curl = curl_easy_init();
//     if(curl)
//     {
//         // set the options that all the curl requests are going to use
//         // list = curl_slist_append(list, "Auth-Token: 06439b300b664499bf3d201d44d63c45");
//         // list = curl_slist_append(list, "Response-Control: minified");
//         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, receivedData);
//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, serverReply);
//         const char* url = "http://api.football-data.org/v1/competitions/426/fixtures?timeFrame=n10";
//         //url for team fixtures "http://api.football-data.org/v1/teams/64/fixtures?timeFrame=n2"
//         curl_easy_setopt(curl, CURLOPT_URL, url);
//         res = curl_easy_perform(curl);
//         if(res != CURLE_OK) {
//             fprintf(stderr, "curl_easy_perform() failed: %s\n",
//             curl_easy_strerror(res));
//         }
//         else{
//             if(!serverReply.empty()){
//                 parseData(serverReply);
//             }
//
//         }
//         curl_easy_cleanup(curl);
//     }
//     cout << serverReply;
//     return serverReply;
// }
//
// void UpcomingFixtures::parseData(std::string & receivedData)
// {
//     const char* jsonData = receivedData.c_str();
//     Document document;
//     document.Parse(jsonData);
//     const char* date = "";
//     const char* homeTeam = "";
//     const char* awayTeam = "";
//     serverReply  = "";
//     for (auto  itr = document.MemberBegin(); itr != document.MemberEnd(); ++itr)
//     {
//         if(strcmp(itr->name.GetString(),"fixtures") == 0)
//         {
//              for(auto itr2 =  itr->value.Begin(); itr2 != itr->value.End(); itr2++)
//              {
//                  for (auto itr3 = itr2->MemberBegin(); itr3 != itr2->MemberEnd(); itr3++)
//                  {
//                      if(strcmp(itr3->name.GetString(),"homeTeamName") == 0)
//                      {
//                          homeTeam = itr3->value.GetString();
//                      }
//                      if(strcmp(itr3->name.GetString(),"awayTeamName") == 0)
//                      {
//                         awayTeam = itr3->value.GetString();
//                      }
//                      if(strcmp(itr3->name.GetString(),"date") == 0)
//                      {
//                          date =  itr3->value.GetString();
//                      }
//
//                  }
//
//                  while(*homeTeam != NULL){
//                      serverReply.push_back(*homeTeam);
//                      homeTeam++;
//                  }
//                  serverReply.push_back(' ') ;
//                  serverReply.push_back('v') ;
//                  serverReply.push_back('s') ;
//                  serverReply.push_back(' ') ;
//                  while(*awayTeam != NULL){
//                      serverReply.push_back(*awayTeam);
//                      awayTeam++;
//                  }
//                  serverReply.push_back(' ');
//                  serverReply.push_back('o');
//                  serverReply.push_back('n');
//                  serverReply.push_back(' ');
//                  while(*date != NULL){
//                      serverReply.push_back(*date);
//                      date++;
//                  }
//                  serverReply.push_back('\n');
//
//              }
//
//         }
//         // cout << itr->name.GetString() << " " << itr->value.GetType()<< endl;
//     }
//
// }
