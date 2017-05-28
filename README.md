# libFootballData
C++ library for  football-data.org(http://api.football-data.org/index)

## Features
* Fixtures of supported teams
## Supported teams
* Liverpool
* Arsenal
* Chelsea
* Manchester United
* Tottenham Hotspur
* Barcelona
* Real Madrid

## Dependencies
* Curl
* rapidjson (https://github.com/miloyip/rapidjson)

### Install Dependencies
sudo apt-get install curl libcurl3 libcurl3-gnutls libcurl4-gnutls-dev rapidjson-dev

## Usage
* Get the soruce : git clone https://github.com/rish9511/libFootballData.git
* Build examples:
    *  cd path/to/libfootballdata/
    *  cd src/examples
    *  g++ -std=c++11 -o favteam ../FavTeamFixtures.cpp favteam.cpp -lcurl
    *  ./favteam arsenal barcelona realmadrid
