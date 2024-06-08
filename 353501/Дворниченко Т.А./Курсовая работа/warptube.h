#ifndef WARPTUBE_H
#define WARPTUBE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include "objecttype.h"


class WarpTube : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:
     explicit WarpTube(QGraphicsItem *parent = 0);
     enum { Type = UserType + warpTubeType };
     int type() const;

private:

};


#endif // WARPTUBE_H
