#ifndef ARRAYMANAGER_H
#define ARRAYMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class ArrayManager : public QObject
{
    Q_OBJECT
public:
    explicit ArrayManager(QGraphicsScene *scene, QObject *parent = nullptr);

    void setupArray(int elementCount, int minValue, int maxValue);
    void addElement(int value);
    void deleteElement(int value);
    QVector<QGraphicsRectItem *> getItems() const;
    void setAnimationRunning(bool running);
    bool isAnimationRunning() const;
    void sortArray(); // Новый метод
    //void clearArray();

signals:
    void itemDeleted(int index);

private:
    void addRect(int value,qreal);
    void updateItemPositions();

    QGraphicsScene *m_scene;
    QVector<QGraphicsRectItem *> m_items;
    bool m_animationRunning;
};

#endif // ARRAYMANAGER_H
