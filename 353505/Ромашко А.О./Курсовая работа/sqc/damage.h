#ifndef DAMAGE_H
#define DAMAGE_H

#include <QObject>

class Damage : public QObject
{
    Q_OBJECT
public:
    explicit Damage(QObject *parent = nullptr);
    void upDamage(int d);
    void downDamage(int d);
    int damage();

private:
    int damag=0;
signals:
};

#endif // DAMAGE_H
