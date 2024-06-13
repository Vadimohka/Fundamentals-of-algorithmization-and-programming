//
// Created by acryoz on 26.05.24.
//

#ifndef LAB7_TASK3_MAINWINDOW_H_
#define LAB7_TASK3_MAINWINDOW_H_

#include <QGridLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>
#include "TaskSolver.h"


QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;
   public slots:
    void rand();
    void doTask();
    void find();

   private:
    void upd();
    QLineEdit* line_edit;
    QPushButton* find_button;
    QPushButton* random_button;
    QLabel* label;
    TaskSolver* solver;
    QPushButton* do_task_button;
    QTableWidget* table;
    QGridLayout* grid;
    QVBoxLayout* vbox;
    Ui::MainWindow* ui;
};


#endif  //LAB7_TASK3_MAINWINDOW_H_
