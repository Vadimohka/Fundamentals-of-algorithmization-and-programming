#include "mydata.h"

mydata::mydata(){}

void mydata::set(QStandardItemModel *model, QModelIndex &index)
{
    model->setData(index, dates);
}

void mydata::get(QString string)
{
    dates = string;
}

QString mydata::ret()
{
    return dates;
}

mydata mydata::PreviousDay()
{
    QString day = "";
    int d;
    QString month = "";
    int m;
    QString year = "";
    int y;
    for(int i = 0; i < dates.length(); i++)
    {
        if(i <= 1)
        {
            day += dates[i];
        }
        else if(i > 2 && i <= 4)
        {
            month += dates[i];
        }
        else if(i > 5)
        {
            year += dates[i];
        }
    }
    d = day.toInt();
    m = month.toInt();
    y = year.toInt();

    day = "";
    month = "";
    year = "";


    if(m == 1 && d - 1 <= 0)
    {
        day = "31";
        month = "12";
        y--;
        year = QString::number(y);
    }
    else if(m > 0 && d - 1 <= 0)
    {
        m--;
        if(m / 10 == 0)
        {
            month = '0';
        }
        month += QString::number(m);
        day = "01";
        year = QString::number(y);
    }
    else if(d - 1 > 0)
    {
        d--;
        if(d / 10 == 0)
        {
            day = '0';
        }
        day += QString::number(d);
        if(m / 10 == 0)
        {
            month = '0';
        }
        month += QString::number(m);
        year = QString::number(y);
    }
    mydata temp;
    temp.dates = day + '.' + month + '.' + year;
    return temp;
}

mydata mydata::NextDay()
{
    QString day = "";
    int d;
    QString month = "";
    int m;
    QString year = "";
    int y;
    for(int i = 0; i < dates.length(); i++)
    {
        if(i <= 1)
        {
            day += dates[i];
        }
        else if(i > 2 && i <= 4)
        {
            month += dates[i];
        }
        else if(i > 5)
        {
            year += dates[i];
        }
    }
    d = day.toInt();
    m = month.toInt();
    y = year.toInt();

    day = "";
    month = "";
    year = "";

    bool isLeaf;
    if(y % 4 == 0 && (y % 100 != 0 || (y % 100 == 0 && y % 400 == 0)))
    {
        isLeaf = true;
    }
    else
    {
        isLeaf = false;
    }

    if((m == 1 || m == 3 || m == 5 || m ==7 || m == 8 || m == 10 || m == 12) && (d + 1 <= 31))
    {
        d++;
        if(d / 10 == 0)
        {
            day = '0';
        }
        day += QString::number(d);
        if(m / 10 == 0)
        {
            month = '0';
        }
        month += QString::number(m);
        year = QString::number(y);
    }
    else if(((m == 1 || m == 3 || m == 5 || m ==7 || m == 8 || m == 10) && m != 12) && (d + 1 > 31))
    {
        m++;
        if(m / 10 == 0)
        {
            month = '0';
        }
        month += QString::number(m);
        day = "01";
        year = QString::number(y);
    }
    else if(m == 2 && !isLeaf && d + 1 >= 29)
    {
        m++;
        if(m / 10 == 0)
        {
            month = '0';
        }
        month += QString::number(m);
        day = "01";
        year = QString::number(y);
    }
    else if((m == 2 && !isLeaf && d + 1 <= 28))
    {
        d++;
        if(d / 10 == 0)
        {
            day = '0';
        }
        day += QString::number(d);
        if(m / 10 == 0)
        {
            month = '0';
        }
        month += QString::number(m);
        year = QString::number(y);
    }
    else if(m == 2 && isLeaf && d + 1 >= 30)
    {
        m++;
        if(m / 10 == 0)
        {
            month = '0';
        }
        month += QString::number(m);
        day = "01";
        year = QString::number(y);
    }
    else if(m == 2 && isLeaf && d + 1 <= 29)
    {
        d++;
        if(d / 10 == 0)
        {
            day = '0';
        }
        day += QString::number(d);
        if(m / 10 == 0)
        {
            month = '0';
        }
        month += QString::number(m);
        year = QString::number(y);
    }
    else if((m != 1 || m != 2 || m != 3 || m != 5 || m !=7 || m != 8 || m != 10) && m != 12 && (d + 1 > 30))
    {
        m++;
        if(m / 10 == 0)
        {
            month = '0';
        }
        month += QString::number(m);
        day = '0';
        d = 1;
        day += QString::number(d);
        year = QString::number(y);
    }
    else if((m != 1 || m != 2 || m != 3 || m != 5 || m !=7 || m != 8 || m != 10) && m != 12 && (d + 1 <= 30))
    {
        d++;
        if(d / 10 == 0)
        {
            day = '0';
        }
        day += QString::number(d);
        if(m / 10 == 0)
        {
            month = '0';
        }
        month += QString::number(m);
        year = QString::number(y);
    }
    else if(m == 12 && d + 1 > 31)
    {
        m = 1;
        month = '0' + QString::number(m);
        day = "01";
        y++;
        year = QString::number(y);
    }
    else if(m == 12 && d + 1 > 31)
    {
        month = "01";
        day = "01";
        y++;
        year = QString::number(y);
    }

    mydata temp;
    temp.dates = day + '.' + month + '.' + year;
    return temp;
}

int mydata::Duration(mydata date)
{
    int arrNotLeaf[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
    int arrLeaf[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

    int count = 0;
    bool leaf;
    QString day1 = "";
    int d1;
    QString month1 = "";
    int m1;
    QString year1 = "";
    int y1;

    QString day2 = "";
    int d2;
    QString month2 = "";
    int m2;
    QString year2 = "";
    int y2;

    for(int i = 0; i < dates.length(); i++)
    {
        if(i <= 1)
        {
            day1 += dates[i];
        }
        else if(i > 2 && i <= 4)
        {
            month1 += dates[i];
        }
        else if(i > 5)
        {
            year1 += dates[i];
        }
    }
    d1 = day1.toInt();
    m1 = month1.toInt();
    y1 = year1.toInt();


    for(int i = 0; i < date.dates.length(); i++)
    {
        if(i <= 1)
        {
            day2 += date.dates[i];
        }
        else if(i > 2 && i <= 4)
        {
            month2 += date.dates[i];
        }
        else if(i > 5)
        {
            year2 += date.dates[i];
        }
    }
    d2 = day2.toInt();
    m2 = month2.toInt();
    y2 = year2.toInt();

    if(y2 < y1)
    {
        int temp;
        temp = d1;
        d1 = d2;
        d2 = temp;

        temp = m1;
        m1 = m2;
        m2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    if(y2 % 4 == 0 && (y2 % 100 != 0 || (y2 % 100 == 0 && y2 % 400 == 0)))
    {
        leaf = true;
    }
    else
    {
        leaf = false;
    }

    if(!leaf && m2 > m1)
    {
        count += arrNotLeaf[m1 - 1] - d1;
        m1++;
        while(m1 != m2)
        {
            count += arrNotLeaf[m1 - 1];
            m1++;
        }
        count += d2;
    }
    else if(!leaf && m2 < m1)
    {
        int m = 1;
        while(m != m2)
        {
            count += arrNotLeaf[m - 1];
            m++;
        }
        count += d2;
    }
    else if(leaf && m2 > m1)
    {
        count += arrLeaf[m1 - 1] - d1;
        m1++;
        while(m1 != m2)
        {
            count += arrLeaf[m1 - 1];
            m1++;
        }
        count += d2;
    }
    else if(leaf && m2 < m1)
    {
        int m = 1;
        while(m != m2)
        {
            count += arrLeaf[m - 1];
            m++;
        }
        count += d2;
    }
    else if(m1 == m2 && d2 > d1)
    {
        count += d2 - d1;
    }
    else if(m1 == m2 && d2 < d1)
    {
        count += d1 - d2 - 1;
    }

    if(m2 < m1)
    {
        if(y1 % 4 == 0 && (y1 % 100 != 0 || (y1 % 100 == 0 && y1 % 400 == 0)))
        {
            count += 366 - d1;
            y1++;
            m1--;
            while(m1 != 0)
            {
                count -= arrLeaf[m1 - 1];
                m1--;
            }
        }
        else
        {
            count += 365 - d1;
            y1++;
            m1--;
            while(m1 != 0)
            {
                count -= arrNotLeaf[m1 - 1];
                m1--;
            }
        }
    }

    while(y1 < y2)
    {
        if(y1 % 4 == 0 && (y1 % 100 != 0 || (y1 % 100 == 0 && y1 % 400 == 0)))
        {
            count += 366;
            y1++;
        }
        else
        {
            count += 365;
            y1++;
        }
    }
    count++;
    return count;
}

bool mydata::leaf()
{

    QString year1 = "";
    int y1;

    for(int i = 0; i < dates.length(); i++)
    {
        if(i > 5)
        {
            year1 += dates[i];
        }
    }
    y1 = year1.toInt();

    if(y1 % 4 == 0 && (y1 % 100 != 0 || (y1 % 100 == 0 && y1 % 400 == 0)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

short mydata::WeekNumber()
{
    QString day = "";
    int d;
    QString month = "";
    int m;
    QString year = "";
    int y;
    for(int i = 0; i < dates.length(); i++)
    {
        if(i <= 1)
        {
            day += dates[i];
        }
        else if(i > 2 && i <= 4)
        {
            month += dates[i];
        }
        else if(i > 5)
        {
            year += dates[i];
        }
    }
    d = day.toInt();
    m = month.toInt();
    y = year.toInt();

    bool isLeaf;
    if(y % 4 == 0 && (y % 100 != 0 || (y % 100 == 0 && y % 400 == 0)))
    {
        isLeaf = true;
    }
    else
    {
        isLeaf = false;
    }

    int arrCodeNotLeaf[] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
    int arrCodeLeaf[] = {0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};

    int dayWeek;
    int yearCode;

    if(y / 100 == 21)
    {
        yearCode = (4 + y % 100 + ((y % 100) / 4)) % 7;
    }
    else if(y / 100 == 20)
    {
        yearCode = (6 + y % 100 + ((y % 100) / 4)) % 7;
    }
    else if(y / 100 == 19)
    {
        yearCode = (0 + y % 100 + ((y % 100) / 4)) % 7;
    }
    else if(y / 100 == 18)
    {
        yearCode = (2 + y % 100 + ((y % 100) / 4)) % 7;
    }
    else if(y / 100 == 17)
    {
        yearCode = (4 + y % 100 + ((y % 100) / 4)) % 7;
    }
    else if(y / 100 == 16)
    {
        yearCode = (6 + y % 100 + ((y % 100) / 4)) % 7;
    }

    if(isLeaf)
    {
        dayWeek = (d + arrCodeLeaf[m - 1] + yearCode) % 7;
    }
    else
    {
        dayWeek = (d + arrCodeNotLeaf[m - 1] + yearCode) % 7;
    }
    return dayWeek;
}

int mydata::DaysTillYourBithday(mydata bithdaydate)
{
    int arrNotLeaf[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
    int arrLeaf[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

    int count = 0;
    bool leaf;
    QString day1 = "";
    int d1;
    QString month1 = "";
    int m1;
    QString year1 = "";
    int y1;


    QString day2 = "";
    int d2;
    QString month2 = "";
    int m2;




    for(int i = 0; i < dates.length(); i++)
    {
        if(i <= 1)
        {
            day1 += dates[i];
        }
        else if(i > 2 && i <= 4)
        {
            month1 += dates[i];
        }
        else if(i > 5)
        {
            year1 += dates[i];
        }

    }
    d1 = day1.toInt();
    m1 = month1.toInt();
    y1 = year1.toInt();


    for(int i = 0; i < bithdaydate.dates.length(); i++)
    {
        if(i <= 1)
        {
            day2 += bithdaydate.dates[i];
        }
        else if(i > 2 && i <= 4)
        {
            month2 += bithdaydate.dates[i];
        }

    }
    d2 = day2.toInt();
    m2 = month2.toInt();

    if(y1 % 4 == 0 && (y1 % 100 != 0 || (y1 % 100 == 0 && y1 % 400 == 0)))
    {
        leaf = true;
    }
    else
    {
        leaf = false;
    }

    bool state = true;
    if(m2 < m1)
    {
        int temp;
        temp = d1;
        d1 = d2;
        d2 = temp;

        temp = m1;
        m1 = m2;
        m2 = temp;

        state = false;
    }

    if(!leaf && m2 > m1)
    {
        count += arrNotLeaf[m1 - 1] - d1;
        m1++;
        while(m1 != m2)
        {
            count += arrNotLeaf[m1 - 1];
            m1++;
        }
        count += d2;
    }
    else if(leaf && m2 > m1)
    {
        count += arrLeaf[m1 - 1] - d1;
        m1++;
        while(m1 != m2)
        {
            count += arrLeaf[m1 - 1];
            m1++;
        }
        count += d2;
    }
    else if(m1 == m2)
    {
        count += d2 - d1 -1;
    }
    count++;

    if(!state)
    {
        count *= (-1);
    }
    return count;
}
