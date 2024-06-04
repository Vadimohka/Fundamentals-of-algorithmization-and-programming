#include "linker.h"
#include "allConst.h"
#include "window.h"

Linker::Linker(Window* parent, item* array, int size, QGraphicsScene* scene)
    : m_scene(scene),
      m_mem(array),
      m_size(size),
      m_parent(parent),
      frame_num(0) {

  m_width = std::max(BOUNDARY_SIZE / m_size, 1);
  m_array = new item*[m_size];

  for (int i = 0; i < m_size; i++) {
    m_array[i] = &m_mem[i];
  }

  for (int i = 0; i < m_size; i++) {
    m_array[i]->place = i + 1;
    int height = (m_array[i]->val + 1) * m_width;
    float left = 10 + i * m_width;
    int intleft = std::floor(left);

    if (left - intleft < 0.1) {
      left = intleft;
    } else if (left - intleft < 0.6) {
      left = intleft + 0.5;
    } else {
      left = intleft + 1;
    }
    int up = MAX_LINE - height;

    if (m_size <= 256) {
      QPen pen = QPen(Qt::black);
      QBrush brush = QBrush(ORANGE);
      m_rects.push_back(
          m_scene->addRect(left, up, m_width, height, pen, brush));
    } else {
      QPen pen = QPen(ORANGE, 1, Qt::SolidLine);
      m_lines.push_back(m_scene->addLine(left, up, left, MAX_LINE, pen));
    }
  }
}

void Linker::render(int i, QColor C) {
  int height = (m_array[i]->val + 1) * m_width;
  int left = 10 + i * m_width;
  int up = MAX_LINE - height;
  if (m_size <= (BOUNDARY_SIZE / 2)) {
    QPen pen = QPen(Qt::black);
    QBrush brush = QBrush(C);
    m_rects[i]->setBrush(brush);
    m_rects[i]->setPen(pen);
    m_rects[i]->setRect(QRect(left, up, m_width, height));
  } else {
    QPen pen = QPen(C, 1, Qt::SolidLine);
    m_lines[i]->setPen(pen);
    m_lines[i]->setLine(left, up, left, MAX_LINE);
  }
}

Linker::~Linker() {
  if (m_size <= (BOUNDARY_SIZE / 2)) {
    for (int i = 0; i < m_size; i++) {
      m_scene->removeItem(m_rects[i]);
      delete m_rects[i];
    }
  } else {
    for (int i = 0; i < m_size; i++) {
      m_scene->removeItem(m_lines[i]);
      delete m_lines[i];
    }
  }
  delete[] m_array;
}

item Linker::get(int i) {
  render(i, RED);
  render(i, ORANGE);
  return *m_array[i];
}

item* Linker::send(int i) {
  render(i, RED);
  render(i, ORANGE);
  return m_array[i];
}

bool Linker::cmp_ii(int i, int j) {
  render(i, BLUE);
  render(j, BLUE);
  m_parent->INCRCMP();
  render(i, ORANGE);
  render(j, ORANGE);
  return (*m_array[i] < *m_array[j]);
}

bool Linker::cmp_ee(item* a, item* b) {
  m_parent->INCRCMP();
  return (*a < *b);
}

bool Linker::cmp_ie(int i, item* a) {
  render(i, BLUE);
  m_parent->INCRCMP();
  render(i, ORANGE);
  return (*m_array[i] < *a);
}

bool Linker::cmp_ei(item* a, int i) {
  render(i, BLUE);
  m_parent->INCRCMP();
  render(i, ORANGE);
  return (*a < *m_array[i]);
}

void Linker::set(int i, item val) {
  *m_array[i] = val;
  render(i, PURPLE);
  render(i, ORANGE);
}

void Linker::receive(int i, item* val) {
  m_array[i] = val;
  render(i, PURPLE);
  render(i, ORANGE);
}

void Linker::flip(int i, int j) {
  item* tmp = m_array[i];
  m_array[i] = m_array[j];
  m_array[j] = tmp;
  render(i, PURPLE);
  render(j, PURPLE);
  render(i, ORANGE);
  render(j, ORANGE);
}

void Linker::solved(int i) {
  render(i, GREEN);
  QApplication::processEvents();
}

void Linker::tmpsolve(int i) {
  render(i, APPLE);
  QApplication::processEvents();
}

int Linker::getSize() {
  return m_size;
}

void Linker::setBinHeapLv(int idx) {
  setHeapLv(idx, 2);
}

void Linker::setTerHeapLv(int idx) {
  setHeapLv(idx, 3);
}

void Linker::setSize(int size) {
  m_size = size;
}

void Linker::setHeapLv(int idx, int base) {
  int lv = std::floor(std::log(idx + 1) / std::log(base) + 0.001);
  QColor c;
  c.setHsv(lv * 255 / 8, 100, 255);
  render(idx, c);
  QApplication::processEvents();
}

void Linker::flip_ifn_cmp(int i, int j) {
  render(i, BLUE);
  render(j, BLUE);
  m_parent->INCRCMP();
  if (*m_array[i] > *m_array[j]) {
    item* tmp = m_array[i];
    m_array[i] = m_array[j];
    m_array[j] = tmp;
  }
  render(i, ORANGE);
  render(j, ORANGE);
}
