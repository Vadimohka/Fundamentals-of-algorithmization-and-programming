#include "mainwindow.h"
#include "HashMap.h"
#include "ui_mainwindow.h"
#include <QChartView>
#include <QLineSeries>
#include <QScatterSeries>
#include <qchartview.h>
#include <qnamespace.h>
#include <qscatterseries.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->calc, &QPushButton::clicked, this, &MainWindow::onCalc);

  chartView = new QChartView();
  ui->gridLayout->replaceWidget(ui->chartContainer, chartView);

  // chartView->chart()->setTitle("");
  chartView->chart()->legend()->setVisible(false);
  chartView->chart()->createDefaultAxes();
  chartView->chart()->setDropShadowEnabled(false);
  chartView->setRenderHint(QPainter::Antialiasing);
  chartView->setRubberBand(QChartView::RectangleRubberBand);
}

void MainWindow::onCalc() {
  chartView->setUpdatesEnabled(false);
  chartView->chart()->removeAllSeries();

  int runs = ui->runs->value();
  int tableSize = ui->size->value();
  bool resetCollisions = !ui->total->isChecked();

  QVector<float> avgs(tableSize, 0);

  QVector<QScatterSeries *> toAdd;
  for (int i = 0; i < runs; i++) {
    HashMap<int> map(tableSize);
    QScatterSeries *series = new QScatterSeries();
    series->setUseOpenGL(true);
    series->setName(QString("Run %1").arg(i));
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(4);
    series->setPen(Qt::NoPen);

    for (int i = 0; i < tableSize; i++) {
      int new_key = rand();
      while (map.contains(new_key)) {
        new_key = rand();
      }

      map.insert(rand(), rand());
      int val = map.getCollisionCount(resetCollisions);
      series->append(i, val);
      avgs[i] += val;
    }

    toAdd.push_back(series);
  }

  QLineSeries *avgSeries = new QLineSeries();
  avgSeries->setUseOpenGL(true);
  avgSeries->setName(QString("Average"));
  {
    QPen pen = avgSeries->pen();
    pen.setWidth(4);
    QColor color = Qt::red;
    // color.setAlphaF(0.5);
    pen.setColor(color);
    avgSeries->setPen(pen);
  }
  for (int i = 0; i < tableSize; i++) {
    avgSeries->append(i, avgs[i] / runs);
  }

  for (auto s : toAdd)
    chartView->chart()->addSeries(s);
  
  // Don't show the average series
  // chartView->chart()->addSeries(avgSeries);


  chartView->chart()->createDefaultAxes();
  chartView->chart()->axes(Qt::Horizontal)[0]->setTitleText("Keys inserted");
  chartView->chart()->axes(Qt::Vertical)[0]->setTitleText("Total collisions");

  chartView->setUpdatesEnabled(true);

}