#include "TimelineScene.h"
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPainter>
#include <QPainterPath>
#include <algorithm>

#include "AudioPixmap.h"
#include "CoreAudio.h"
#include "CoreInfo.h"
#include "EffectSelection.h"
#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>
#include <qalgorithms.h>
#include <qcolor.h>
#include <qdebug.h>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qnamespace.h>
#include <qtimer.h>
#include <qtmetamacros.h>

TimelineScene::TimelineScene(QWidget *widget) : QGraphicsScene(widget) {
  // buffer = {nullptr, nullptr, 0, 0, false};
  updater = new QTimer(this);

  connect(updater, &QTimer::timeout, this, &TimelineScene::updatePosPointer);
  updater->start(64);
}

TimelineScene::~TimelineScene() {
  delete posPointer;
  delete updater;
  selectedEffect = nullptr;
  qDeleteAll(effects);
}

// void TimelineScene::setBuffer(StereoAudioBuffer buffer_) {
//   buffer = buffer_;
// }

void TimelineScene::drawWaveform() {
  if (leftPixmap)
    removeItem(leftPixmap);
  if (rightPixmap)
    removeItem(rightPixmap);
  // removeItem(posPointer); posPointer = nullptr;

  viewWidth = views().first()->width();
  viewHeight = views().first()->height();

  auto buffer = ae::CoreAudio::getBuffer();
  if (buffer.size == 0 || views().size() == 0) {
    qDebug() << "No buffer or no views";
    return;
  }

  AudioPixmap leftWaveform(buffer.left, buffer.size, viewWidth, viewHeight / 2,
                           LEFT_WAVEFORM_COLOR);
  AudioPixmap rightWaveform(buffer.right, buffer.size, viewWidth,
                            viewHeight / 2, RIGHT_WAVEFORM_COLOR);

  
  leftPixmap = new QGraphicsPixmapItem(leftWaveform);
  rightPixmap = new QGraphicsPixmapItem(rightWaveform);

  leftPixmap->setPos(0, 0);
  rightPixmap->setPos(0, viewHeight / 2);

  addItem(leftPixmap);
  addItem(rightPixmap);

  // qDebug() << "l s " << leftPixmap->scene();
  // qDebug() << "r s " << rightPixmap->scene();
  setSceneRect(0, 0, viewWidth, viewHeight);
}

void TimelineScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mousePressEvent(event);
  pressed = true;
  views().first()->setFocus();
  if (mBehaviour == MouseBehaviour::Selection) {
    selectionPress(event);
  } else if (mBehaviour == MouseBehaviour::Navigation) {
    navigate(event);
  }
}

void TimelineScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  if (!pressed) {
    return;
  }
  QGraphicsScene::mouseMoveEvent(event);
  if (mBehaviour == MouseBehaviour::Selection) {
    selectionMove(event);
  } else if (mBehaviour == MouseBehaviour::Navigation) {
    navigate(event);
  }
}
void TimelineScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  pressed = false;
}

void TimelineScene::selectionPress(QGraphicsSceneMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    selectionStart = event->scenePos().x();
    selectionEnd = selectionStart;
  }

  if (selectionRect) {
    removeItem(selectionRect);
    delete selectionRect;
    selectionRect = nullptr;
  }
}

void TimelineScene::selectionMove(QGraphicsSceneMouseEvent *event) {
  selectionEnd = std::min(std::max(0.0, event->scenePos().x()), width());
  emit selectionChanged(selectionStart, selectionEnd);
  drawSelection();
}

void TimelineScene::navigate(QGraphicsSceneMouseEvent *event) {
  auto x = event->scenePos().x();
  qDebug() << x;
  auto buf_size = ae::CoreAudio::getBuffer().size;
  int ind = ((double)x / width()) * buf_size;
  ae::CoreAudio::setCurrentIndex(ind);
  updatePosPointer();
}

void TimelineScene::drawSelection() {
  auto left = selectionStart;
  auto right = selectionEnd;
  if (right < left) {
    std::swap(left, right);
  }

  if (!selectionRect) {
    selectionRect = addRect(left, 0, right - left, views().first()->height(),
                            QPen(Qt::gray, 1), SELECTION_COLOR);
  } else {
    selectionRect->setRect(left, 0, right - left, views().first()->height());
  }
}

// DANGEROUS TEST
void TimelineScene::updatePosPointer() {
  using namespace ae;
  auto buf = CoreAudio::getBuffer();
  auto cur = buf.current;
  auto size = buf.size;

  if (!posPointer) {
    posPointer = new QGraphicsLineItem(0, 0, 0, height());
    posPointer->setPen(posPtrPen);
    posPointer->setZValue(16.0);
    addItem(posPointer);
  }

  posPointer->setPos((float)cur / size * viewWidth, 0);
  MainWindow::getInstance()->setTimeLabel(CoreInfo::getTimeString(cur));
}

std::pair<int, int> TimelineScene::getSelection() const {
  const auto bufSize = ae::CoreAudio::getBuffer().size;
  int samplesPerPx = bufSize / width();

  int beg = samplesPerPx * selectionStart;
  int end = samplesPerPx * selectionEnd;
  if (beg > end) {
    std::swap(beg, end);
  }
  if (beg < 0) {
    beg = 0;
  }
  if (end >= bufSize) {
    end = bufSize - 1;
  }
  qDebug() << "scene width" << width();
  qDebug() << "end: " << end;
  qDebug() << "bufsize:" << bufSize;
  return {beg, end};
}

void TimelineScene::setMouseBehaviour(MouseBehaviour mb) {
  mBehaviour = mb;

  if (mb == MouseBehaviour::Navigation) {
    if (selectionRect) {
      removeItem(selectionRect);
      selectionRect = nullptr;
    }
    selectionStart = 0;
    selectionEnd = 0;
  }
}

void TimelineScene::pushEffect(int beg, int end) {
  auto buf = ae::CoreAudio::getBuffer();

  long samplesPerPx = buf.size / sceneRect().width();

  auto beg_pos = beg / samplesPerPx;
  auto end_pos = end / samplesPerPx;

  auto new_eff =
      new EffectSelection(0, 0, end_pos - beg_pos, viewHeight, beg, end);
  new_eff->setPos(beg_pos, 0);
  new_eff->setZValue(8.0);
  addItem(new_eff);
  effects.push_back(new_eff);
  selectEffect(effects.size() - 1);
}

void TimelineScene::selectEffect(int i) {
  if (selectedEffect) {
    selectedEffect->setSelected(false);
    selectedEffect->setZValue(8.0);
  }
  if (i == -1) {
    return;
  }

  selectedEffect = effects[i];
  selectedEffect->setSelected(true);
  selectedEffect->setZValue(9.0);
}

void TimelineScene::resetEffects() {
  qDeleteAll(effects);
  effects.clear();
  selectedEffect = nullptr;
}

const QColor &TimelineScene::getLastEffectColor() {
  return effects.back()->brush().color();
}

void TimelineScene::selectAll() {
  selectionStart = 0;
  selectionEnd = views().first()->width();
  emit selectionChanged(selectionStart, selectionEnd);
  drawSelection();    
  
}
