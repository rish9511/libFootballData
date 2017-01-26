#include <unordered_map>
#include <string>
#include <curl/curl.h>

class FavTeamFixtures
{
public:
    FavTeamFixtures(const  char* name);
    std::string processRequest();
    void parseData(std::string&);
    static size_t receivedData(void *data, size_t size, size_t nmemb, std::string& recData);
private:
    const char* teamName;
    std::unordered_map<std::string,std::string> supportedTeams;
    CURL* curl;
    struct curl_slist* list;
};
