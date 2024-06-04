#include "stepbystepanimation.h"

constexpr int AnimationDelay = 1000;

StepByStepAnimation::StepByStepAnimation(QGraphicsScene *scene, QObject *parent)
    : QObject(parent), m_scene(scene), m_currentIndex(0), m_animationComplete(false), m_searchedValue(0) {}

void StepByStepAnimation::animate(QVector<QGraphicsItem *> items, int searchedValue,bool isGenerated) {
    if (!isGenerated) resetAnimation();
    m_searchedValue = searchedValue;
    m_items = items;
    m_currentIndex = 0;
}

void StepByStepAnimation::completeCurrentAnimation() {
    if (m_currentIndex >= 0 && m_currentIndex < m_items.size()) {
        QGraphicsItem *item = m_items[m_currentIndex];
        setItemPenColor(item, Qt::black);
    }
    m_currentIndex = m_items.size();
}

void StepByStepAnimation::resetAnimation() {
    for (auto &item : m_items) {
        setItemPenColor(item, Qt::black);
    }
    m_currentIndex = 0;
    m_animationComplete = false;
}

void StepByStepAnimation::nextStep() {
    if (m_items.isEmpty() || m_currentIndex >= m_items.size()) {
        return;
    }

    if (m_currentIndex > 0 && m_currentIndex <= m_items.size()) {
        setItemPenColor(m_items[m_currentIndex - 1], Qt::black);
    }


    if (m_currentIndex < m_items.size()) {
        QGraphicsItem *item = m_items[m_currentIndex];
        int value = item->data(0).toInt();
        QColor penColor = (value == m_searchedValue) ? QColor(Qt::green) : QColor(Qt::red);
        setItemPenColor(item, penColor);
        m_currentIndex++;
    }

    if (m_currentIndex >= m_items.size()) {
        emit animationFinished();
        QTimer::singleShot(AnimationDelay, this, &StepByStepAnimation::resetLastItemColor);
        m_currentIndex = m_items.size();
    }
}

void StepByStepAnimation::previousStep() {
    if (m_items.isEmpty() || m_currentIndex <= 0) {
        return;
    }

    if (m_currentIndex <= m_items.size()) {
        setItemPenColor(m_items[m_currentIndex - 1], Qt::black);
    }

    m_currentIndex--;

    if (m_currentIndex > 0) {
        QGraphicsItem *item = m_items[m_currentIndex - 1];
        int value = item->data(0).toInt();
        QColor penColor = (value == m_searchedValue) ? QColor(Qt::green) : QColor(Qt::red);
        setItemPenColor(item, penColor);
    } else if (m_currentIndex == 0) {
        QGraphicsItem *item = m_items[0];
        int value = item->data(0).toInt();
        QColor penColor = (value == m_searchedValue) ? QColor(Qt::green) : QColor(Qt::red);
        setItemPenColor(item, penColor);
    }
}

void StepByStepAnimation::startFromIndex(int index) {
    if (index >= 0 && index < m_items.size()) {
        resetAnimation();
        m_currentIndex = index;
        highlightCurrentItem();
    }
}

void StepByStepAnimation::setAnimationComplete(bool complete) {
    m_animationComplete = complete;
}

int StepByStepAnimation::currentIndex() const {
    return m_currentIndex;
}

void StepByStepAnimation::highlightCurrentItem() {
    if (m_currentIndex >= 0 && m_currentIndex < m_items.size()) {
        QGraphicsItem *item = m_items[m_currentIndex];
        int value = item->data(0).toInt();
        QColor penColor = (value == m_searchedValue) ? QColor(Qt::green) : QColor(Qt::red);
        setItemPenColor(item, penColor);
    }
}

void StepByStepAnimation::setItemPenColor(QGraphicsItem *item, const QColor &color) {
    if (!item) return;
    if (auto rectItem = qgraphicsitem_cast<QGraphicsRectItem *>(item)) {
        rectItem->setPen(QPen(color));
    } else if (auto ellipseItem = qgraphicsitem_cast<QGraphicsEllipseItem *>(item)) {
        ellipseItem->setPen(QPen(color));
    }
}

void StepByStepAnimation::resetLastItemColor() {
    if (!m_items.isEmpty()) {
        setItemPenColor(m_items.last(), Qt::black);
    }
}
