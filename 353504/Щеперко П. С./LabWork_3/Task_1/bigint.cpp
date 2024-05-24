#include "bigint.h"
#include "qdebug.h"

QPair<QString, QString> BigInt::DivisionBy2(QString num)
{
    std::string stdStrNum;
    stdStrNum = num.toStdString();
    std::reverse(stdStrNum.begin(), stdStrNum.end());
    QPair<QString, QString> quotientAndRemain;
    if ((static_cast<qint16> (stdStrNum.at(0)) - 48) % 2 == 1) {
        quotientAndRemain.second = "1";
        stdStrNum.at(0) -= 1;
    } else {
        quotientAndRemain.second = "0";
    }
    stdStrNum.at(0) = static_cast<char> (((static_cast<qint16> (stdStrNum.at(0)) - 48) / 2) + 48);
    for (qsizetype i = 1; i < num.size(); ++i) {
        stdStrNum.at(i - 1) += (static_cast<qint16> (stdStrNum.at(i)) - 48) * 5 % 10;
        stdStrNum.at(i) = static_cast<char> (((static_cast<qint16> (stdStrNum.at(i)) - 48) * 5 / 10) + 48);
    }
    std::reverse(stdStrNum.begin(), stdStrNum.end());
    num = QString::fromStdString(stdStrNum);
    quotientAndRemain.first = num;
    return quotientAndRemain;
}

QPair<QString, QString> BigInt::MultipicationBy2(QString num)
{
    std::string stdStrNum;
    stdStrNum = num.toStdString();
    std::reverse(stdStrNum.begin(), stdStrNum.end());
    QPair<QString, QString> multAndRemain;
    for (int i = 0; stdStrNum.at(i) == '0'; ++i) {
        stdStrNum.erase(i,1);
        --i;
    }
    for (quint16 i = 0; i < stdStrNum.size(); ++i) {
        if (stdStrNum.at(i) == '.') {
            ++i;
        }
        stdStrNum.at(i) -= 48;
    }
    for (quint16 i = 0; i < stdStrNum.size(); ++i) {
        if (stdStrNum.at(i) == '.') {
            ++i;
        }
        stdStrNum.at(i) = static_cast<qint16> (stdStrNum.at(i)) * 2;
    }
    for (quint16 i = 0; i < stdStrNum.size(); ++i) {
        if (stdStrNum.at(i) == '.') {
            ++i;
        }
        if (i == stdStrNum.size() - 1) {
            break;
        }
        if (stdStrNum.at(i) >= 10) {
            if (stdStrNum.at(i + 1) == '.') {
                multAndRemain.second = "1";
                stdStrNum.at(i) = stdStrNum.at(i) % 10;
                break;
            }
            stdStrNum.at(i + 1) += stdStrNum.at(i) / 10;
            stdStrNum.at(i) = stdStrNum.at(i) % 10;
        } else {
            multAndRemain.second = "0";
        }
    }
    for (quint16 i = 0; i < stdStrNum.size(); ++i) {
        if (stdStrNum.at(i) == '.') {
            ++i;
        }
        stdStrNum.at(i) += 48;
    }
    std::reverse(stdStrNum.begin(), stdStrNum.end());
    stdStrNum.at(0) = '0';
    num = QString::fromStdString(stdStrNum);
    multAndRemain.first = num;
    return multAndRemain;
}
