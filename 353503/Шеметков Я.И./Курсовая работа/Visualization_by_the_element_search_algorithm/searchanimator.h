#ifndef SEARCHANIMATOR_H
#define SEARCHANIMATOR_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QVector>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "pointer.h" // добавляем заголовочный файл для класса Pointer

class SearchAnimator : public QObject
{
    Q_OBJECT
public:
    explicit SearchAnimator(QGraphicsScene *scene, Pointer *pointer, QVector<QGraphicsRectItem *> &items, QObject *parent = nullptr); // изменяем тип аргумента на Pointer
    virtual ~SearchAnimator();

    virtual void startSearch(int targetValue) = 0;
    void stopSearch();

protected:
    virtual void advance() = 0;

    QGraphicsScene *m_scene;
    Pointer *m_pointer; // изменяем тип указателя
    QVector<QGraphicsRectItem *> &m_items;
    QTimer *m_timer;
    int m_targetValue;
    int m_currentIndex;
    QParallelAnimationGroup *m_animationGroup;
};

#endif // SEARCHANIMATOR_H
