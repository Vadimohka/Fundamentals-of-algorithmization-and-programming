#ifndef MUS_H
#define MUS_H

#include <QString>

struct mus
{
public:
    char* title;
    int listeners;
    double rating;
    int length[3];
    char cat;
    bool isExplicit;


    mus();
    mus(const char* title, int listeners, double rating, const int* length, char cat, bool isExplicit);
    QString ret();
    ~mus();
};

#endif // MUS_H
