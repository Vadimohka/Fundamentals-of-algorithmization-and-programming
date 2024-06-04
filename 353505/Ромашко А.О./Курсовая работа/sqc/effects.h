#ifndef EFFECTS_H
#define EFFECTS_H

#include <QObject>

#include "CardCharHDDE.h"

class Effects : public QObject
{
    Q_OBJECT
public:
    explicit Effects(QObject *parent = nullptr);

private:

signals:

};

#endif // EFFECTS_H
