#ifndef PLANE_H
#define PLANE_H
#include <QChar>
struct PLANE
{
    int course_number;
    double time_duartion;
    char type;
    char name[7];
    int people_amount[4];
    bool fall;
};

#endif // PLANE_H
