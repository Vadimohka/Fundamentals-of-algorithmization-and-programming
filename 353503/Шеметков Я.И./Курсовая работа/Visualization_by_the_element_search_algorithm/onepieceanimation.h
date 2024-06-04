#ifndef ONEPIECEANIMATION_H
#define ONEPIECEANIMATION_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVector>
#include <QVariantAnimation>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

class OnePieceAnimation : public QObject {
    Q_OBJECT

public:
    explicit OnePieceAnimation(QGraphicsScene* scene, QObject* parent = nullptr);

    void animate(QVector<QGraphicsItem *> items, int searchedValue);
    void stopAnimation();
    void continueAnimation();
    void completeCurrentAnimation();
    void updateItems(const QVector<QGraphicsItem*>& items);
    void resetAnimation();
    void handleItemDeleted(int index);
    bool isStopped() const;
    int currentIndex() const;
    void setItemsBrushToWhite();
   void setItemBrush(QGraphicsItem *item, const QColor &color);

signals:
    void animationFinished();

private slots:
    void startNextAnimation();
    void animationFinishedHandler();

private:
    QGraphicsScene* m_scene;
    QVector<QGraphicsItem *> m_items;
    QVector<bool> m_hiddenItems;
    QVariantAnimation* m_animation;
    int m_currentIndex;
    int m_searchedValue;
    bool m_stopped;
};

#endif // ONEPIECEANIMATION_H
