#ifndef ENERGY_H
#define ENERGY_H

#include <QObject>
#include <QDebug>

class Energy : public QObject
{
    Q_OBJECT
public:
    explicit Energy(QObject *parent = nullptr);
    void upEnergy(int en);
    void upEnergy(Energy *en);
    void downEnergy();
    void downEnergy(int en){this->energy-=en;}
    void downEnergy(Energy *en){this->energy-=en->setEnergy();}

    int setEnergy();
    void doNull(){this->energy = 0;}
private:
    int energy=0;
signals:
};

#endif // ENERGY_H
