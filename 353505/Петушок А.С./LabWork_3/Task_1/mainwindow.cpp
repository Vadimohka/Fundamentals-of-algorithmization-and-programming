#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ConvertButton_clicked()
{

    long double number = ui -> EnterLine -> value();
    ui -> AnswerLine -> setText(b_number.ToBinary(number));

}
bool MainWindow::check_input()
{
    bool answer;
    QString enter = ui -> EnterLine -> text();
    for (QChar c : enter) {
        if ( c.isLetter() || c == ',') {
            return false;
        }
    }
}
