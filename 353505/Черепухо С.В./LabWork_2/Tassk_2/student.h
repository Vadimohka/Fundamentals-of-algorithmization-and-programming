#ifndef STUDENT_H
#define STUDENT_H
#include "bibl.h"
class student
{
private:
    string name;
    ll math;
    ll physics;
    ll rus;
public:
    student();
    string get_name() const;
    ll get_math() const;
    ll get_physics() const;
    ll get_rus() const;
    void set_name(const string&);
    void set_math(ll);
    void set_physics(ll);
    void set_rus(ll);
    student& operator = (const student&);
};
#endif
