#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
using namespace std;

class Observer;

class Subject
{
public:
    Subject();
    void notifyObservers();
    void registerObserver(Observer* ob);

private:
    vector<Observer*> obs;

};

#endif // SUBJECT_H
