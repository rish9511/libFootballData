#include <iostream>
#include <cstring>
#include <string>
#include "../FavTeamFixtures.h"

/*
	Dependencies:
	* CURL
	* RapidJson

	Build Instructions:
	g++ -g -std=c++11 -o favteam ../FavTeamFixtures.cpp favteam.cpp -lcurl

	Usage:
	./favteam arsenal barcelona
*/

int main(int argc, const char* argv[])
{
	const char ** arguments = &argv[1];
	while((*arguments)!= NULL) {

	   FavTeamFixtures favteam;
	   favteam.processRequest(*arguments);

	   //results in string format
       std::string resultString = favteam.getResultString();
       std::cout << resultString << std::endl;

	   // result in map foramt
       std::unordered_map<std::string, std::string> resultMap = favteam.getResultMap();
       std::cout << resultMap["home_team"] << std::endl;
	   std::cout << resultMap["away_team"] << std::endl;
	   std::cout << resultMap["date"] << std::endl;
	   std::cout << resultMap["time"] << std::endl;
       arguments++;
    }

}
