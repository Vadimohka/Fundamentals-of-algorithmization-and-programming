#include "foot.h"

Foot::Foot(const QString &str)
{
    int cnt = 0, counter = 1;
    QString temp = "";
    for (int i = cnt; i < str.size(); ++i)
    {
        if (str[i] != ' ' && i != str.size()-1)
        {
            temp.push_back(str[i]);
        }
        else
        {
            switch (counter) {
            case 1:
                totalNumber = temp.toInt();
                break;
            case 2:
                price = temp.toDouble();
                break;
            case 3:
                type = temp[0];
                cnt += 2;
                break;
            case 4:
                isUniversal = (temp == "true" ? true : false);
                break;
            case 5:
                for (int j = 0; j < temp.size(); ++j)
                {
                    season[j] = temp[j].toLatin1();
                    if (j == temp.size())
                    {
                        for (int k = j; k < 6; ++k)
                        {
                            season[j] = ' ';
                        }
                    }
                }
                break;
            case 6:
                QString now = "";
                int counter1 = 0;
                for (int j = 0; j < temp.size(); ++j)
                {
                    if (temp[j] != ',' && j != temp.size()-1)
                    {
                        now.push_back(temp[j]);
                    }
                    else
                    {
                        if (j == temp.size()-1) now.push_back(temp[j]);
                        sz[counter1] = now.toInt();
                        ++counter1;
                        now = "";
                        if (j == temp.size()-1)
                        {
                            for (int k = counter1; k < 20; ++k)
                            {
                                sz[k] = 0;
                            }
                        }
                    }
                }
                break;
            }

            temp = "";
            ++cnt;
            ++counter;
        }
    }
}

QString Foot::toString()
{
    QString ans = "", temp = "";
    temp = QString::number(totalNumber);
    ans += temp + " | ";

    temp = "";
    temp = QString::number(price);
    ans += temp + " | ";

    temp = "";
    temp.push_back(type);
    ans += temp + " | ";

    temp = "";
    temp = (isUniversal ? "true" : "false");
    ans += temp + " | ";

    temp = "";
    for (int i = 0; i < 6; ++i)
    {
        if (season[i] < 'A' || season[i] > 'Z') break;
        temp.push_back(season[i]);
    }
    ans += temp + " | ";

    temp = "";
    for (int i = 0; i < 20; ++i)
    {
        if (sz[i] == 0) break;
        temp += QString::number(sz[i]) + ",";
    }
    temp.remove(temp.size()-1, 1);
    ans += temp;

    return ans;
}


