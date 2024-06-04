#include "searchanimator.h"
#include <QPropertyAnimation>

SearchAnimator::SearchAnimator(QGraphicsScene *scene, Pointer *pointer, QVector<QGraphicsRectItem *> &items, QObject *parent)
    : QObject(parent), m_scene(scene), m_pointer(pointer), m_items(items), m_timer(new QTimer(this)), m_targetValue(0), m_currentIndex(0)
{
    connect(m_timer, &QTimer::timeout, this, &SearchAnimator::advance);
    m_animationGroup = new QParallelAnimationGroup(this);
}

SearchAnimator::~SearchAnimator()
{
    m_timer->stop();
    delete m_timer;
}

void SearchAnimator::stopSearch()
{
    m_timer->stop();
    m_pointer->setVisible(false);
    m_animationGroup->stop();
}
