//
// Created by acryoz on 15.05.24.
//

#ifndef LAB6_SRC2_MAINWINDOW_H_
#define LAB6_SRC2_MAINWINDOW_H_

#include <QComboBox>
#include <QDebug>
#include <QEvent>
#include <QFile>
#include <QFileDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRegExp>
#include <QRegExpValidator>
#include <QStackedWidget>
#include <QStringList>
#include <QTextEdit>
#include <QTextStream>
#include <QVBoxLayout>
#include <QWidget>
#include <fstream>
#include "../include/smartphone.h"


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
    QComboBox* combo_box;
    QStackedWidget* stacked_widget;
    QWidget* first_page;
    QWidget* second_page;
    QWidget* third_page;
    QWidget* fourth_page;
    QWidget* fifth_page;

    QGridLayout* first_grid;
    QGridLayout* second_grid;
    QGridLayout* third_grid;
    QGridLayout* fourth_grid;
    QGridLayout* fifth_grid;

    QHBoxLayout* second_hbox;
    QHBoxLayout* third_hbox;
    QHBoxLayout* fourth_hbox;

    QTextEdit* first_input;
    QLineEdit* second_input_1;
    QLineEdit* second_input_2;
    QLineEdit* third_input;
    QLineEdit* fourth_input;
    QTextEdit* fifth_input;

    QPushButton* second_button;
    QPushButton* third_button;
    QPushButton* third_button_2;
    QPushButton* fourth_button;
    QPushButton* fourth_button_2;

    QTextEdit* first_output;
    QLabel* second_output;
    QTextEdit* third_output;
    QTextEdit* fourth_output;
    QTextEdit* fifth_output;

    QVBoxLayout* main_vbox;
    Ui::MainWindow* ui;

    QIntValidator* int_validator;
    QRegExpValidator* second_validator;
    QRegExpValidator* third_validator;
    QRegExpValidator* fourth_validator;

    bool eventFilter(QObject* object, QEvent* event) override;
   public slots:
    void firstTask();
    void firstTaskPrint();
    void secondTask();
    void secondTaskPrint();
    void thirdTask();
    void thirdTaskPrint();
    void fourthTask();
    void fourthTaskPrint();
    void fifthTask();
    void fifthTaskPrint();
};


#endif  //LAB6_SRC2_MAINWINDOW_H_
