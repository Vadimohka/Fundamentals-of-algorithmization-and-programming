#include "student.h"

student::student()
{

}
string student::get_name() const
{
    return name;
}
ll student::get_math() const
{
    return math;
}
ll student::get_physics() const
{
    return physics;
}
ll student::get_rus() const
{
    return rus;
}
bool check(string name)
{
    ll x = 0;
    for(ll i = 0; i < name.length(); i++)
    {
        if(name[i] == ' ')
            x++;
    }
    if(x == 2)
        return 1;
    else
        return 0;
}
void student::set_name(const string &name)
{
    if(!check(name))
        throw "Ошибка имени";
    this->name = name;
}
void student::set_math(ll math)
{
    if(!math)
        throw "Ошибка Математики";
    this->math = math;
}
void student::set_physics(ll physics)
{
    if(!physics)
        throw "Ошибка физики";
    this->physics = physics;
}
void student::set_rus(ll rus)
{
    if(!rus)
    throw "Ошибка русского";
    this->rus = rus;
}
student& student::operator = (const student& other)
{
    name= other.name;
    math = other.math;
    physics = other.physics;
    rus = other.rus;
    return *this;
}
