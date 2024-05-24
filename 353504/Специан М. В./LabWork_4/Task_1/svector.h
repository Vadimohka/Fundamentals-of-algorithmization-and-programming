#ifndef SVECTOR_H
#define SVECTOR_H

#include <QObject>
#include <vector.h>
#include <QTime>

class SVector : public QObject, public Vector<int>
{
    Q_OBJECT
public:
    void emitSignal(int, int);
signals:
    void valueChange(int);
};

#endif // SVECTOR_H
