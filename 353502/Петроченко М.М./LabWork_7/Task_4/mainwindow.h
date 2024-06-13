//
// Created by acryoz on 26.05.24.
//

#ifndef LAB7_TASK4_MAINWINDOW_H_
#define LAB7_TASK4_MAINWINDOW_H_

#include <QChartView>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineSeries>
#include <QPushButton>
#include <QScatterSeries>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>
#include "HashTable.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private slots:
    void doTask();

   private:
    QLabel* label1;
    QLabel* label2;
    QCheckBox* collisions;
    QSpinBox* table_size;
    QSpinBox* tests;
    QHBoxLayout* hbox;
    QVBoxLayout* vbox;
    QChartView* chart_view;
    QPushButton* task_button;
    Ui::MainWindow* ui;
};


#endif  //LAB7_TASK4_MAINWINDOW_H_
