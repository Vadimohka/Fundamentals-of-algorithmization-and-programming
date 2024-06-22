#include "mus.h"
#include <cstring>

mus::mus() : title(nullptr), listeners(0), rating(0.0), cat('\0'), isExplicit(false)
{
    length[0] = length[1] = length[2] = 0;
}

mus::mus(const char* title, int listeners, double rating, const int* length, char cat, bool isExplicit)
    : listeners(listeners), rating(rating), cat(cat), isExplicit(isExplicit)
{
    this->title = title ? new char[strlen(title) + 1] : nullptr;
    if (this->title) {
        strcpy(this->title, title);
    }
    this->length[0] = length[0];
    this->length[1] = length[1];
    this->length[2] = length[2];
}

QString mus::ret()
{
    QString result = "";
    result += title;
    result += " | " + QString::number(listeners);
    result += " | " + QString::number(rating) + " | " + QString::number(length[0]) + ":" + QString::number(length[1]) + ":" + QString::number(length[2]) + " | " + cat + " | ";
    if (isExplicit==true) result+="explicit";
    return result;
}

mus::~mus() {
    delete[] title;
}
