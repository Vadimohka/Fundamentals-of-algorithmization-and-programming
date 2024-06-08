#include "plane.h"


bool check_lifting(std::string l)
{

    if(l.size()==0)
        return false;
    for(auto& i:l)
    {
        if(!(i>='0'&&i<='9'))
            return false;
    }

    long long lifting;
    try
    {
        lifting=stoll(l);
    }catch(...){
        return false;
    }
    return true;
}

bool check_name(std::string name)
{
    if(name.size()==0)
        return false;
    return true;
}

bool check_cost(std::string ca)
{

    if(ca.size()==0)
        return false;

    bool point=false;
    for(auto& i:ca)
    {
        if(i=='.')
        {
            if(point)return false;
            point=true;
        }else
            if(!(i>='0'&&i<='9'))
                return false;
    }

    double cost;
    try
    {
        cost=stod(ca);
    }catch(...){
        return false;
    }

    return true;
}

bool check_sank(std::string san)
{
    if(san.size()>1||san.size()==0)
        return false;

    char s=san[0];

    if(!(s=='1'||s=='0'))
        return false;

    return true;
}

bool check_type(std::string ty)
{

    if(ty.size()>1||ty.size()==0)
        return false;

    char type=ty[0];

    if(!(type=='W'||type=='P'||type=='C'||type=='F'||type=='Y'||type=='U'))
        return false;
    return true;
}

bool check_staff(std::string st)
{

    if(st.size()==0)
        return false;
    for(auto& i:st)
    {
        if(!(i>='0'&&i<='9'))
            return false;
    }

    int staff;
    try
    {
        staff=stoi(st);
    }catch(...){
        return false;
    }
    return true;
}

bool check_capacity(std::string cap)
{

    if(cap.size()==0)
        return false;
    for(auto& i:cap)
    {
        if(!(i>='0'&&i<='9'))
            return false;
    }



    long long c;
    try
    {
        c=stoll(cap);
    }catch(...){
        return false;
    }
    return true;
}
