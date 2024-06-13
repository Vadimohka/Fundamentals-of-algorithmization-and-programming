//
// Created by acryoz on 26.05.24.
//

#ifndef LAB7_TASK5_MAINWINDOW_H_
#define LAB7_TASK5_MAINWINDOW_H_

#include <QGridLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "deque.h"


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

   private slots:
    void popFront();
    void popBack();
    void pushFront();
    void pushBack();


   private:
    void upd();
    QPushButton* pop_back_button;
    QPushButton* push_back_button;
    QPushButton* pop_front_button;
    QPushButton* push_front_button;
    QLineEdit* line_edit;
    QLabel* deque_rep;
    Deque<int> deque;
    QGridLayout* grid;
    QVBoxLayout* vbox;
    Ui::MainWindow* ui;
};


#endif  //LAB7_TASK5_MAINWINDOW_H_
