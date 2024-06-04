#ifndef BD4DE6C6_612D_4E47_9B93_0B23993245D8
#define BD4DE6C6_612D_4E47_9B93_0B23993245D8
#include <QGraphicsItem>
#include <qgraphicsitem.h>
#include <qgraphicssceneevent.h>
#include <qpainter.h>

class EffectSelection : public QGraphicsRectItem{

    static const int DEF_SATURATION = 190;
    static const int DEF_OPACITY = 60;
    static const int DEF_VALUE = 100;
    static const int HUE_STEP = 45;
    static const int FONT_SIZE = 9;

    int beg = 0, end = 0;

    QColor color;
    static int cur_hue;

    QGraphicsTextItem *begText = nullptr, *endText = nullptr;
    QGraphicsRectItem* selectionRect;

    bool selection = false;

public:
EffectSelection(qreal, qreal, qreal, qreal, int, int);
    void setSelected(bool);
    virtual ~EffectSelection();
    
};

#endif /* BD4DE6C6_612D_4E47_9B93_0B23993245D8 */
