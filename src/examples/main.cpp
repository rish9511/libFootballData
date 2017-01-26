#include <iostream>
#include <cstring>
#include "UpcomingFixtures.h"


int main(int argc, const char* argv[])
{

    const char ** arguments = argv;
    while((*arguments)!= NULL)
    {
        if (strcmp((*arguments),"upcoming") == 0)
        {
            UpcomingFixtures upf;
            upf.processRequest();
        }
        arguments++;
    }

    // c1har * buffer = "rishabh"
    // while(buffer++){
    //     cout << *(b)
    // }
    /**This function must be the first function to call, and it returns a CURL easy handle that
	you must use as input to other functions **/
    // string buffer;
    //
    // CURL *curl = curl_easy_init();
	// if (curl) {
	// 	// the url to get
	// 	curl_easy_setopt(curl, CURLOPT_URL, "http://api.football-data.org/v1/competitions");
	// 	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
    //     curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);
	// 	curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
	// 	curl_easy_perform(curl);
    //     curl_easy_cleanup(curl);
    //     // cout << sizeof(buffer);
    //
	// }
    // // cout<< buffer << endl;
    // Document doc;
    // // const char *json = "[{\"name\":\"rishabh\"},{\"class\":\"4a\"}]";
    // // cout << json;
    // doc.Parse(buffer.c_str());
    // assert(doc.IsArray());
    // for(auto it=doc.Begin(); it != doc.End(); it++){
    //
    //     for(auto it2=(*it).MemberBegin(); it2!=(*it).MemberEnd(); it2++){
    //         // cout << typeid(*(it2)).name() << endl;
    //         cout << (*it2).name.GetString() << " "<< (*it2).value.GetString() << endl;
    //     }
    // }
}
