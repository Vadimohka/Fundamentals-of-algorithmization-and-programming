#include "candidate.h"

Candidate::Candidate() {

}

void Candidate::makeAge()
{
    QDate nowDate = QDate::currentDate();
    candAge = nowDate.year() - candBirthday.year() - 1;
    if(candBirthday.month() < nowDate.month())
        candAge++;
    else if(candBirthday.month() == nowDate.month() && candBirthday.day() == nowDate.day())
        candAge++;
}
