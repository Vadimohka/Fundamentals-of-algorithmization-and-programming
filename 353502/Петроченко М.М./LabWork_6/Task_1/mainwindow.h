//
// Created by acryoz on 15.05.24.
//

#ifndef LAB6_SRC_MAINWINDOW_H_
#define LAB6_SRC_MAINWINDOW_H_

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRegExp>
#include <QRegExpValidator>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include "../include/smartphone.h"


QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

static const int INPUT_LINE_WIDTH = 400;

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   public slots:
    void doTask();

   private:
    QTextEdit* text_edit1;
    QTextEdit* text_edit2;
    QTextEdit* text_edit3;
    QTextEdit* text_edit4;

    QVBoxLayout* vbox;
    QHBoxLayout* te_hbox;
    QHBoxLayout* u_hbox;

    QLineEdit* input_edit;
    QRegExpValidator* validator;

    QPushButton* button;


    Ui::MainWindow* ui;
};


#endif  //LAB6_SRC_MAINWINDOW_H_
