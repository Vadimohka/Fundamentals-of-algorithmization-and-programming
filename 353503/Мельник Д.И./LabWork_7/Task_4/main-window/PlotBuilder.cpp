#include "PlotBuilder.h"
#include "CommonHash.h"
#include "HashTable.h"
#include <QRandomGenerator64>
#include <QSet>
#include <cstddef>
#include <qcontainerfwd.h>
#include <qelapsedtimer.h>
#include <qline.h>
#include <qlineseries.h>
#include <qnamespace.h>
#include <qrandom.h>
#include <qtypes.h>
#include <qvalueaxis.h>

QVector<unsigned long long> PlotBuilder::generateRandomKeys(size_t sz) {
  auto rg = QRandomGenerator::securelySeeded();
  QVector<quint64> vect(sz);
  for (int i = 0; i < sz; ++i) {
    vect[i] = rg.generate64();
  }
  return std::move(vect);
}

void PlotBuilder::hashComparisonPlot(QChartView *view, size_t ht_size) {
  view->chart()->removeAllSeries();

  auto keys = generateRandomKeys(ht_size);
  {
    QLineSeries *modulo_series = new QLineSeries;
    modulo_series->useOpenGL();

    HashTable<long, ModuloHash> ht(ht_size);
    int cnt = 0;
    for (auto key : keys) {
      ht.insert(key, std::rand());
      modulo_series->append(cnt, ht.collisions());
      ++cnt;
    }
    modulo_series->setName("Modulo hashing");
    modulo_series->setColor(Qt::green);
    view->chart()->addSeries(modulo_series);
  }

  {
    QLineSeries *universal_series = new QLineSeries;
    universal_series->useOpenGL();
    HashTable<long, UniversalHash> ht(ht_size);
    int cnt = 0;
    for (auto key : keys) {
      ht.insert(key, std::rand());
      universal_series->append(cnt, ht.collisions());
      ++cnt;
    }
    universal_series->setName("Universal hashing");
    universal_series->setColor(Qt::red);
    view->chart()->addSeries(universal_series);
  }

  view->chart()->createDefaultAxes();
  view->chart()->axes(Qt::Horizontal).first()->setTitleText("Insertions");
  view->chart()->axes(Qt::Vertical).first()->setTitleText("Collisions");
}

void PlotBuilder::speedComparisonPlot(QChartView *view, size_t ht_size) {

  view->chart()->removeAllSeries();
  QElapsedTimer *timer = new QElapsedTimer;

  auto keys = generateRandomKeys(ht_size);
  {
    QLineSeries *modulo_series = new QLineSeries;
    modulo_series->useOpenGL();

    HashTable<long, ModuloHash> ht(ht_size);
    int cnt = 0;
    timer->start();
    for (auto key : keys) {
      ht.insert(key, std::rand());
      modulo_series->append(cnt, timer->nsecsElapsed());
      ++cnt;
      timer->restart();
    }
    timer->invalidate();
    modulo_series->setName("Modulo hashing");
    modulo_series->setColor(Qt::green);
    view->chart()->addSeries(modulo_series);
  }

  {
    QLineSeries *universal_series = new QLineSeries;
    universal_series->useOpenGL();
    HashTable<long, UniversalHash> ht(ht_size);
    int cnt = 0;
    timer->start();
    for (auto key : keys) {
      ht.insert(key, std::rand());
      universal_series->append(cnt, timer->nsecsElapsed());
      ++cnt;
      timer->restart();
    }
    timer->invalidate();
    universal_series->setName("Universal hashing");
    universal_series->setColor(Qt::red);
    view->chart()->addSeries(universal_series);
  }

  view->chart()->createDefaultAxes();
  view->chart()->axes(Qt::Horizontal).first()->setTitleText("Insertions");
  view->chart()->axes(Qt::Vertical).first()->setTitleText("Time (nsecs approx.)");

  delete timer;
}
