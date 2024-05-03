#include "Date.h"



Date::Date(int DD, int MM, int YY)
    :
    m_day(DD), m_mounth(MM), m_year(YY)
{
    if(IsLeap()) m_dayNumPerMounces[1] = 29;

    try{
        if(m_mounth > 12 || m_mounth < 1) throw "Incorrect month!!";

        if(m_day > m_dayNumPerMounces[m_mounth - 1] || m_day < 0) throw "Incorrect date!!";

        if(m_year < 0) throw "Incorrect year!!";
    }
    catch(const char* exeption){
        QMessageBox box;
        box.critical(nullptr, "Incorrect data!", exeption);
        m_day = (rand() % 27);
        m_mounth = ((rand() % 12) +1);
        m_year = (rand() % 3000);

        //assert(false);
    }
}
Date::Date() : Date(2, 11, 2005){}

Date Date::NextDay(){
    if(m_dayNumPerMounces[m_mounth - 1] > m_day)
        return Date(m_day + 1, m_mounth, m_year);
    else if(m_mounth == 12)
        return Date(1, 1, m_year + 1);
    else
        return Date(1, m_mounth + 1, m_year);
}
Date Date::PreviousDay(){
    if(m_day == 1){
        if(m_mounth == 1){
            return Date(31, 13, m_year - 1);
        }
        else{
            return Date(m_dayNumPerMounces[m_mounth - 1], m_mounth - 1, m_year);
        }
    }
    else{
        return Date(m_day - 1, m_mounth, m_year);
    }
}
int Date::DaysTillYourBirthday(Date birthdayDate){
    return this->Duration(birthdayDate);
}

bool Date::IsLeap(){
    return (m_year % 100 != 0 && m_year % 4 == 0) || m_year % 400 == 0;
    return m_year % 4 == 0;
}

short Date::WeekNumber(){
    int days = m_day;

    for (int i = 0; i < m_mounth; i++){
        days += m_dayNumPerMounces[i];
    }

    return ((days / 7) + 1);
}

int Date::Duration(Date date){
    int thisDaysFromChrist = 0;
    for(int i =0; i <= m_year; i++){
        if((i % 100 != 0 && i % 4 == 0) || i % 400 == 0){
            thisDaysFromChrist += 366;
        }
        else thisDaysFromChrist += 365;
    }

    if(m_mounth == 1){
        thisDaysFromChrist += m_day;
    }

    for(int i = 0; i < m_mounth; i++){
        if(i == m_mounth - 1){
            thisDaysFromChrist += m_day;
        }
        else{
            thisDaysFromChrist += m_dayNumPerMounces[i];
        }
    }

    int otherDaysFromChrist = 0;
    for(int i =0; i <= date.m_year; i++){
        if((i % 100 != 0 && i % 4 == 0) || i % 400 == 0){
            otherDaysFromChrist += 366;
        }
        else otherDaysFromChrist += 365;
    }

    if(date.m_mounth == 1){
        otherDaysFromChrist += date.m_day;
    }

    for(int i = 0; i < date.m_mounth; i++){
        if(i == date.m_mounth - 1){
            otherDaysFromChrist += date.m_day;
        }
        else{
            otherDaysFromChrist += date.m_dayNumPerMounces[i];
        }
    }

    return std::abs(thisDaysFromChrist - otherDaysFromChrist);
}

QString Date::ToString(Date date){
    std::string name;
    if(date.m_day <= 9) name.push_back('0');
    name += std::to_string(date.m_day) + ".";

    if(date.m_mounth <= 9) name.push_back('0');
    name += std::to_string(date.m_mounth) + ".";

    if(date.m_year <= 9) name.push_back('0');
    if(date.m_year <= 99) name.push_back('0');
    if(date.m_year <= 999) name.push_back('0');
    name += std::to_string(date.m_year);

    return QString(name.c_str());
}
