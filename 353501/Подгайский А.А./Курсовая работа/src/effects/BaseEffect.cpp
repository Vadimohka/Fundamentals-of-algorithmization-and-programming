#include "BaseEffect.h"
#include "CoreAudio.h"
#include "mainwindow.h"
#include <QApplication>
#include <QFormLayout>
#include <QMessageBox>
#include <QtConcurrent>
#include <qalgorithms.h>
#include <qapplication.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include <qlayout.h>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qtconcurrentrun.h>
#include <qthreadpool.h>
#include <qtmetamacros.h>

using namespace ae;

void BaseEffect::setUpUi(QWidget *widget) {
  gui = widget;
  layout = new QFormLayout(widget);

  applyBtn = new QPushButton("Apply", widget);
  layout->insertRow(0, applyBtn);
  layout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
  applyBtn->setFocusPolicy(Qt::NoFocus);
  widget->setFocusPolicy(Qt::NoFocus);
  connect(applyBtn, &QPushButton::clicked, this, &BaseEffect::apply);
}

void BaseEffect::apply() {
  finished = false;

  if (!gui) {
    qDebug() << "BaseEffect: No gui installed!";
    finished = true;
    return;
  }

  auto window = MainWindow::getInstance();

  updateProperties();

  auto tl = window->getTimeline();
  auto sel = tl->getSelection();
  auto buf = CoreAudio::getBuffer();

  auto beg = sel.first;
  auto size = sel.second - sel.first;

  if (size <= 1) {
    QMessageBox::information(window, "Info", "Select an audio area.");
    finished = true;
    return;
  }

  auto max = buf.size - sel.first;

  gui->setEnabled(false);
  window->blockAudio(true);

  QThreadPool::globalInstance()->start([=] {
    reset();
    _process(&buf.left[beg], size, max, 0);
    reset();
    _process(&buf.right[beg], size, max, 1);
    
    emit modifiedBuffer(beg, beg + size, objectName());
    gui->setEnabled(true);
    window->blockAudio(false);
    finished = true;
  });
}

BaseEffect::~BaseEffect() { qDeleteAll(gui->children()); }

void BaseEffect::reset() {}

void BaseEffect::requestStop() {
  stopRequest = true;    
}

bool BaseEffect::hasStopped(){
  return finished;
}
