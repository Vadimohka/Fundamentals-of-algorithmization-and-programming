#pragma once

#include <unistd.h>
#include <QApplication>
#include <QColor>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QWidget>
#include <vector>
#include "item.h"

#define WHITE QColor(255, 255, 255)
#define GREEN QColor(55, 200, 0)
#define BLUE QColor(11, 97, 164)
#define RED QColor(255, 57, 0)
#define ORANGE QColor(255, 191, 0)
#define APPLE QColor(165, 255, 0)
#define PURPLE QColor(124, 7, 169)

class Window;

class Linker {
 public:
    Linker(Window*, item*, int, QGraphicsScene*);
  ~Linker();
  void done(int);
  item get(int);
  item* send(int);
  bool cmp_ii(int, int);
  bool cmp_ei(item*, int);
  bool cmp_ie(int, item*);
  bool cmp_ee(item*, item*);
  void set(int, item);
  void receive(int, item*);
  void flip(int, int);
  void solved(int);
  void tmpsolve(int);
  int getSize();
  void setSize(int);
  void setBinHeapLv(int);
  void setTerHeapLv(int);
  void flip_ifn_cmp(int, int);

 private:
  void render(int, QColor);
  void setHeapLv(int, int);

  QGraphicsScene* m_scene;
  std::vector<QGraphicsRectItem*> m_rects;
  std::vector<QGraphicsLineItem*> m_lines;
  item* m_mem;
  item** m_array;
  int m_size;
  Window* m_parent;
  int m_width;
  int frame_num;
};
