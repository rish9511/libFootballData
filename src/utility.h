#include <ctime>
#include <sstream>
#include <iomanip>
struct tm* get_utc_time(time_t utc_rawtime)
{
	return gmtime(&utc_rawtime);
}
struct tm* get_local_time(time_t local_rawtime)
{
	return localtime(&local_rawtime);
}
double time_difference()
{
    time_t utc;
    time_t local;
    utc = mktime(get_utc_time(time(NULL)));
    local =  mktime(get_local_time(time(NULL)));

    return difftime(local,utc);
}

std::string check_date(const char* datetime)
{
    struct tm tm;
    strptime(datetime, "%Y-%m-%dT%H:%M:%S%z", &tm);
    time_t matchdate =  mktime(&tm) + (time_t)time_difference();

    std::stringstream mdate;
    mdate << std::put_time(get_local_time(matchdate), "%d-%m-%y");

    std::stringstream tdate;
    tdate << std::put_time(get_local_time(time(NULL)), "%d-%m-%y");

    if(tdate.str() == mdate.str())
        return "Today";
    else
        return mdate.str();
}

std::string get_date(const char* datetime)
{
    struct tm tm;
    strptime(datetime, "%Y-%m-%dT%H:%M:%S%z", &tm);
    time_t matchdate =  mktime(&tm) + (time_t)time_difference();

    std::stringstream mdate;
    mdate << std::put_time(get_local_time(matchdate), "%d-%m-%Y");
    return mdate.str();
}
std::string get_time(const char* datetime)
{

    struct tm tm;
    strptime(datetime, "%Y-%m-%dT%H:%M:%S%z", &tm);
    time_t matchtime =  mktime(&tm) + (time_t)time_difference();

    std::stringstream mtime;
    mtime << std::put_time(get_local_time(matchtime), "%I:%M %p");
    return mtime.str();
}
