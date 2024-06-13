#include "checkstr.h"

bool CheckStrCorrect(QString str)
{
    if (str == "") {
        return false;
    }
    if (str[0] == ' ' || str[str.size()-1] == ' ') {
        return false;
    }
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            return true;
        }
    }
    return false;
}
