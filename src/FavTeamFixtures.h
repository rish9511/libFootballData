#include <unordered_map>
#include <string>
#include <curl/curl.h>
/*
    class FavTeamFixtures
    Return fixture of the asked team scheduled for the day
*/
typedef std::unordered_map<std::string,std::string> Map;
class FavTeamFixtures
{
public:
    FavTeamFixtures();

    void processRequest(const char* teamName);
    void parseData(std::string&);
    static size_t receivedData(void *data, size_t size, size_t nmemb, std::string& recData);

    std::string getResultString();
    Map getResultMap();
private:
    Map supportedTeams;
    std::string resultString;
    Map resultMap;
    CURL* curl;
    struct curl_slist* list;
};
