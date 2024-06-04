#include "onepieceanimation.h"

constexpr int AnimationDuration = 1000;

OnePieceAnimation::OnePieceAnimation(QGraphicsScene* scene, QObject* parent)
    : QObject(parent), m_scene(scene), m_currentIndex(0), m_animation(nullptr), m_stopped(true) {}

void OnePieceAnimation::animate(QVector<QGraphicsItem *> items, int searchedValue) {
    resetAnimation();
    m_searchedValue = searchedValue;
    m_currentIndex = 0;
    m_stopped = false;
    m_items = items;
    m_hiddenItems.resize(m_items.size());
    for (int i = 0; i < m_hiddenItems.size(); ++i) {
        m_hiddenItems[i] = false;
    }
    if (!m_items.isEmpty()) {
        startNextAnimation();
    }
}

void OnePieceAnimation::stopAnimation() {
    m_stopped = true;
    if (m_animation) {
        m_animation->pause();
    }
}

void OnePieceAnimation::continueAnimation() {
    if (m_stopped && m_animation) {
        m_stopped = false;
        m_animation->resume();
    }
}

void OnePieceAnimation::completeCurrentAnimation() {
    if (m_animation) {
        m_animation->stop();
        disconnect(m_animation, &QVariantAnimation::finished, this, &OnePieceAnimation::animationFinishedHandler);
        delete m_animation;
        m_animation = nullptr;
        animationFinishedHandler();
    }
}

void OnePieceAnimation::updateItems(const QVector<QGraphicsItem*>& items) {
    completeCurrentAnimation();
    m_items.clear();
    for (auto item : items) {
        if (item) {
            m_items.append(item);
        }
    }
    m_hiddenItems.resize(m_items.size());
    for (int i = 0; i < m_hiddenItems.size(); ++i) {
        m_hiddenItems[i] = false;
    }
    resetAnimation();
}

void OnePieceAnimation::resetAnimation() {
    if (m_animation) {
        m_animation->stop();
        delete m_animation;
        m_animation = nullptr;
    }
    setItemsBrushToWhite();
    m_currentIndex = 0;
    m_stopped = true;
}

void OnePieceAnimation::startNextAnimation() {
    while (m_currentIndex < m_items.size() && m_hiddenItems[m_currentIndex]) {
        ++m_currentIndex;
    }

    if (m_currentIndex >= m_items.size() || m_stopped) {
        emit animationFinished();
        return;
    }

    QGraphicsItem* item = m_items[m_currentIndex];
    int value = item->data(0).toInt();

    m_animation = new QVariantAnimation(this);
    m_animation->setDuration(AnimationDuration);

    QColor startColor;

    if (item->type() == QGraphicsRectItem::Type) {
        startColor = static_cast<QGraphicsRectItem*>(item)->brush().color();
    } else if (item->type() == QGraphicsEllipseItem::Type) {
        startColor = static_cast<QGraphicsEllipseItem*>(item)->brush().color();
    }

    QColor endColor = (value == m_searchedValue) ? QColor(Qt::green) : QColor(Qt::red);

    setItemBrush(item, startColor);

    connect(m_animation, &QVariantAnimation::valueChanged, [this, item](const QVariant& value) {
        setItemBrush(item, value.value<QColor>());
    });
    connect(m_animation, &QVariantAnimation::finished, this, &OnePieceAnimation::animationFinishedHandler);

    m_animation->setStartValue(startColor);
    m_animation->setEndValue(endColor);

    m_animation->start();
}

void OnePieceAnimation::animationFinishedHandler() {
    if (m_currentIndex < 0 || m_currentIndex >= m_items.size() || m_stopped) {
        emit animationFinished();
        return;
    }

    if (!m_hiddenItems[m_currentIndex]) {
        QGraphicsItem* item = m_items[m_currentIndex];
        if (item->data(0).toInt() == m_searchedValue) {
            m_stopped = true;
            emit animationFinished();
            return;
        }
        setItemsBrushToWhite();
    }

    m_currentIndex++;
    startNextAnimation();
}

void OnePieceAnimation::handleItemDeleted(int index) {
    if (index < 0 || index >= m_items.size()) return;
    m_hiddenItems[index] = true;
    m_items[index] = nullptr;

    m_items.erase(std::remove(m_items.begin(), m_items.end(), nullptr), m_items.end());

    if (m_currentIndex == index) {
        if (m_animation) {
            m_animation->stop();
            delete m_animation;
            m_animation = nullptr;
        }
        m_currentIndex++;
        startNextAnimation();
    }
}

bool OnePieceAnimation::isStopped() const {
    return m_stopped;
}

int OnePieceAnimation::currentIndex() const {
    return m_currentIndex;
}

void OnePieceAnimation::setItemsBrushToWhite() {
    for (auto item : qAsConst(m_items)) {
        if (!item) continue;
        if (auto rectItem = qgraphicsitem_cast<QGraphicsRectItem*>(item)) {
            rectItem->setBrush(QColor(Qt::white));
        } else if (auto ellipseItem = qgraphicsitem_cast<QGraphicsEllipseItem*>(item)) {
            ellipseItem->setBrush(QColor(Qt::white));
        }
    }
}

void OnePieceAnimation::setItemBrush(QGraphicsItem *item, const QColor &color) {
    if (!item) return;
    if (item->type() == QGraphicsRectItem::Type) {
        static_cast<QGraphicsRectItem*>(item)->setBrush(color);
    } else if (item->type() == QGraphicsEllipseItem::Type) {
        static_cast<QGraphicsEllipseItem*>(item)->setBrush(color);
    }
}
