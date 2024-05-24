#include "log.h"

void add_log(std::string s)
{
    std::ofstream log;
    log.open("session.log", std::ios::app);
    log<<"["<<clock()<<"] "<<s<<'\n';
}

void cl()
{
    std::ofstream c("session.log");

}
