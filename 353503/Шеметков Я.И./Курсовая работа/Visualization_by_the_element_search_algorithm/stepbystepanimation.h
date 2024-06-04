#ifndef STEPBYSTEPANIMATION_H
#define STEPBYSTEPANIMATION_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVector>
#include <QTimer>

#include "arraymanager.h"
#include "graphmanager.h"

class StepByStepAnimation : public QObject {
    Q_OBJECT

public:
    StepByStepAnimation(QGraphicsScene *scene, QObject *parent = nullptr);
    void animate(QVector<QGraphicsItem *> items, int searchedValue,bool);
    void completeCurrentAnimation();
    void updateItems(const QVector<QGraphicsItem *> &);
    void resetAnimation();
    void nextStep();
    void previousStep();
    void startFromIndex(int index);
    void setAnimationComplete(bool complete);
    int currentIndex() const;
    void setItemPenColor(QGraphicsItem *, const QColor &);

signals:
    void animationFinished();

private slots:


private:
    void highlightCurrentItem();
    void resetLastItemColor();// New method to highlight the current item

    QGraphicsScene *m_scene;
    QVector<QGraphicsItem *> m_items;
    int m_currentIndex;
    bool m_animationComplete;
    int m_searchedValue;
};

#endif // STEPBYSTEPANIMATION_H
