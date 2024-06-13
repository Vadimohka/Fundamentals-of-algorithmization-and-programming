//
// Created by acryoz on 6.4.24.
//

#ifndef LAB4_SRC_MAINWINDOW_H_
#define LAB4_SRC_MAINWINDOW_H_

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRegExp>
#include <QRegExpValidator>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include "../headers/binpow.h"
#include "../headers/binsearch.h"
#include "../headers/mainwindow.h"
#include "../headers/sortingalgs.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

const long long MOD = 1e9 + 7;
const int SPLIT_SIZE = 3;
const int PROCENTILE = 2;

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   public slots:
    void evaluate();

   private:
    QRegExp* regex;
    QRegExpValidator* regex_validator;
    QHBoxLayout* hbox;
    QIntValidator* int_validator;
    QLineEdit* arr_line_edit;
    QLineEdit* num_line_edit;
    QLabel* found_num;
    QLabel* elapsed_times;
    QTextEdit* text_edit;
    QPushButton* eval_button;
    QVBoxLayout* vbox;
    Sorting* sorter;

    Ui::MainWindow* ui;
};

QVector<int> split(QString, QChar);

#endif  //LAB4_SRC_MAINWINDOW_H_
