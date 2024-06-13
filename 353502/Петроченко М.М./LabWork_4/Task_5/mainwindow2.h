//
// Created by acryoz on 4/26/24.
//

#ifndef LAB4_SRC_MAINWINDOW2_H_
#define LAB4_SRC_MAINWINDOW2_H_

#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include "../lib/library.cpp"
#include "../lib/pair.cpp"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow2;
}

QT_END_NAMESPACE

class MainWindow2 : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow2(QWidget* parent = nullptr);
    ~MainWindow2() override;

   private:
    Pair<Vector<int>, Vector<Pair<int, double>>> pair_;
    QLabel* first_matrix;
    QLabel* second_matrix;
    QHBoxLayout* hbox;
    Ui::MainWindow2* ui;
};


#endif  //LAB4_SRC_MAINWINDOW2_H_
