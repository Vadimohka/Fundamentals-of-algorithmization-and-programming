#ifndef COURIER_FUNC_H
#define COURIER_FUNC_H
#include "courier.h"
courier();
courier(std::string numb,std::string nick,short int tf,short int tt,unsigned long long mw);
//Get functions

std::string getNumber() const;
void setNumber(const std::string &newNumber);

std::string getName() const;
void setName(const std::string &newName);

short getTime_to() const;
void setTime_to(short newTime_to);

short getTime_from() const;
void setTime_from(short newTime_from);


unsigned long long getMax_weight() const;
void setMax_weight(unsigned long long newMax_weight);

std::string get_in_string();
std::string get_time_to_in_string();
std::string get_time_from_in_string();
std::string get_in_file_format();
bool operator < (courier b);
#endif // COURIER_FUNC_H
