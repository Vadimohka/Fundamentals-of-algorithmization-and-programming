//
// Created by acryoz on 26.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->chart_view = new QChartView;

    this->collisions = new QCheckBox("collisions");

    this->label1 = new QLabel("size");
    this->label2 = new QLabel("tests");

    this->table_size = new QSpinBox;
    this->table_size->setMinimum(16);
    this->table_size->setMaximum(2048);

    this->tests = new QSpinBox;
    this->tests->setMinimum(1);
    this->tests->setMaximum(20);

    this->hbox = new QHBoxLayout;
    this->hbox->addWidget(this->label1);
    this->hbox->addWidget(this->table_size);
    this->hbox->addWidget(this->label2);
    this->hbox->addWidget(this->tests);
    this->hbox->addWidget(this->collisions);

    this->task_button = new QPushButton("Do task");
    QObject::connect(this->task_button, SIGNAL(clicked()), this,
                     SLOT(doTask()));

    this->vbox = new QVBoxLayout;
    this->vbox->addLayout(this->hbox);
    this->vbox->addWidget(this->chart_view);
    this->vbox->addWidget(this->task_button);

    this->setLayout(this->vbox);
}

void MainWindow::doTask() {
    this->chart_view->setUpdatesEnabled(false);
    this->chart_view->chart()->removeAllSeries();

    int test_cases_count = this->tests->value();
    int elem_count = this->table_size->value();
    bool include_collisions = !this->collisions->isChecked();

    QVector<float> averages(elem_count, 0);

    QVector<QScatterSeries*> adding;
    for (int i = 0; i < test_cases_count; i++) {
        HashTable2<int> table(elem_count);
        QScatterSeries* series = new QScatterSeries();
        series->setUseOpenGL(true);
        series->setName(QString("Test No. %1").arg(i));
        series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
        series->setMarkerSize(4);
        series->setPen(Qt::NoPen);
        for (int j = 0; j < elem_count; j++) {
            int new_key = rand();
            while (table.contains(new_key)) {
                new_key = rand();
            }
            table.insert(rand(), rand());
            int val = table.collisionCount();
            if (include_collisions) {
                table.resetCollisionCount();
            }
            series->append(j, val);
            averages[j] += val;
        }
        adding.push_back(series);
    }
    QLineSeries* average_series = new QLineSeries();
    average_series->setUseOpenGL(true);
    average_series->setName(QString("averages"));
    //{
    QPen pen = average_series->pen();
    pen.setWidth(4);
    QColor color = Qt::red;
    pen.setColor(color);
    average_series->setPen(pen);
    //}
    for (int i = 0; i < elem_count; i++) {
        average_series->append(i, averages[i] / test_cases_count);
    }
    for (auto ser : adding) {
        this->chart_view->chart()->addSeries(ser);
    }
    this->chart_view->chart()->createDefaultAxes();
    this->chart_view->chart()->axes(Qt::Horizontal)[0]->setTitleText(
        "Key count");
    this->chart_view->chart()->axes(Qt::Vertical)[0]->setTitleText(
        "Collision count");
    this->chart_view->setUpdatesEnabled(true);
}

MainWindow::~MainWindow() {
    delete ui;
}
