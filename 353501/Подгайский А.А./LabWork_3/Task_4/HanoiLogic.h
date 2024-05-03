
#include <QVector>
#include <QPair>

class HanoiLogic{
    QVector<QPair<short, short>> actions;
    int ringCount[3];

private:
    void moveStack(int amount, short src, short dst);
    
public:
    QVector< QPair<short, short> > Hanoi(int n);
};