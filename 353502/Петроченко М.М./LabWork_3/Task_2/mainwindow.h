//
// Created by acryoz on 08.06.24.
//

#ifndef LAB3_TASK2_MAINWINDOW_H_
#define LAB3_TASK2_MAINWINDOW_H_

#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "ackerman.h"


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

   private:
    QLabel* label;
    QLineEdit* line_edit1;
    QLineEdit* line_edit2;
    QIntValidator* validator1;
    QIntValidator* validator2;
    QVBoxLayout* vbox;
    QPushButton* button;
    Ui::MainWindow* ui;
   private slots:
    void doTask();
};


#endif  //LAB3_TASK2_MAINWINDOW_H_
