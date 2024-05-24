#pragma once

#include <QComboBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>
#include <QWidget>
#include "item.h"
#include "linker.h"
#include "optionmgr.h"
#include "sorter.h"

class Window : public QWidget {
  Q_OBJECT
 public:
  Window(QWidget* parent, QGraphicsScene*, QGraphicsView*);
  void INCRCMP();
 public slots:
  void run();
  void done();
  void Resize(int);
  void kill();
  void abort();
  void play();
  void pause();

 private:
  QWidget* m_parent;
  QGraphicsScene* m_scene;
  QGraphicsView* m_view;
  QComboBox* m_chooseAlgo;
  QComboBox* m_chooseOption;
  OptionMgr* m_optmgr;
  QComboBox* m_chooseDistrib;
  QComboBox* m_chooseScramble;
  QComboBox* m_chooseSize;
  QLabel* m_nbCmp;
  QPushButton* m_start;
  QPushButton* m_exit;
  QPushButton* m_abort;
  QPushButton* m_playpause;
  QVBoxLayout* m_chooseMenu;
  Linker* m_link;
  Sorter* m_sort;
  item* m_array;
  bool playing;
};
