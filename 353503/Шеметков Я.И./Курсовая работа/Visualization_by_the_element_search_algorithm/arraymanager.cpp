#include "arraymanager.h"
#include <QRandomGenerator>
#include <QGraphicsTextItem>
#include <QPen>
#include <QFont>
#include <algorithm>

constexpr int RECT_SIZE = 30;
constexpr int TEXT_FONT_SIZE = 10;
constexpr int RECT_Y = 230;

ArrayManager::ArrayManager(QGraphicsScene *scene, QObject *parent)
    : QObject(parent), m_scene(scene), m_animationRunning(false) {}

void ArrayManager::setupArray(int elementCount, int minValue, int maxValue) {
    m_scene->clear();
    m_items.clear();

    qreal sceneWidth = m_scene->width();
    qreal sceneHeight = m_scene->height();
    qreal totalWidth = elementCount * RECT_SIZE;
    qreal startX = (sceneWidth - totalWidth) / 2;

    for (int i = 0; i < elementCount; ++i) {
        qreal x = startX + i * RECT_SIZE;
        int value = QRandomGenerator::global()->bounded(minValue, maxValue + 1);
        addRect(value, x);
    }
}

void ArrayManager::addElement(int value) {
    if (m_animationRunning) return;

    addRect(value, 0);
    updateItemPositions();
}

void ArrayManager::deleteElement(int value) {
    for (int i = 0; i < m_items.size(); ++i) {
        if (m_items[i]->data(0).toInt() == value) {
            emit itemDeleted(i);
            m_items[i]->hide();
            m_items.remove(i);
            break;
        }
    }
    updateItemPositions();
}

QVector<QGraphicsRectItem *> ArrayManager::getItems() const {
    return m_items;
}

void ArrayManager::addRect(int value, qreal x) {
    QGraphicsRectItem *rect = new QGraphicsRectItem(x, RECT_Y, RECT_SIZE, RECT_SIZE);
    rect->setPen(QPen(Qt::black));
    rect->setBrush(Qt::NoBrush);
    rect->setData(0, value);
    m_scene->addItem(rect);

    QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(value), rect);
    text->setDefaultTextColor(Qt::black);
    text->setFont(QFont("Arial", TEXT_FONT_SIZE, QFont::Bold));
    QRectF rectBounds = rect->boundingRect();
    QRectF textBounds = text->boundingRect();
    text->setPos(rectBounds.center() - textBounds.center());

    m_items.append(rect);
}

void ArrayManager::updateItemPositions() {
    if (m_items.isEmpty()) return;

    qreal sceneWidth = m_scene->width();
    qreal sceneHeight = m_scene->height();
    qreal totalWidth = m_items.size() * RECT_SIZE;
    qreal startX = (sceneWidth - totalWidth) / 2;
    qreal centerY = (sceneHeight - RECT_SIZE) / 2;

    for (int i = 0; i < m_items.size(); ++i) {
        m_items[i]->setRect(startX + i * RECT_SIZE, centerY, RECT_SIZE, RECT_SIZE);
        auto childItems = m_items[i]->childItems();
        if (!childItems.isEmpty()) {
            QGraphicsTextItem *text = dynamic_cast<QGraphicsTextItem *>(childItems.first());
            if (text) {
                QRectF rectBounds = m_items[i]->boundingRect();
                QRectF textBounds = text->boundingRect();
                text->setPos(rectBounds.center() - textBounds.center());
            }
        }
    }
}

void ArrayManager::setAnimationRunning(bool running) {
    m_animationRunning = running;
}

bool ArrayManager::isAnimationRunning() const {
    return m_animationRunning;
}

void ArrayManager::sortArray() {
    std::sort(m_items.begin(), m_items.end(), [](QGraphicsRectItem *a, QGraphicsRectItem *b) {
        return a->data(0).toInt() < b->data(0).toInt();
    });
    updateItemPositions();
}
