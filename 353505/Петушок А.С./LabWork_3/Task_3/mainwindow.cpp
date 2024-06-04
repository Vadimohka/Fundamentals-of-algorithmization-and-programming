#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_SolutionButton_clicked()
{
    // bool acces = CheckInput();
    // if(acces == false){
        ui -> AnswerLine -> setText("Incorrect Input1");
    // }
    // else{


    long long n = ui -> NValue -> text().toLongLong();
    long long a = 0;
    if (n % 10 == 0) {
        ui -> AnswerLine -> setText("Incorrect Input2");
    } else {
        ui -> AnswerLine -> setText(QString::number(number.rev(n, a)));
    }
    //}
}

bool MainWindow::CheckInput()
{
    bool answer;
    QString value = ui -> NValue -> text();
    for (QChar c : value) {
        if ( c.isLetter()) {

            ui -> AnswerLine -> setText("Incorrect Input3");
            return 0;
        }
        else if(c == ','){
            ui -> AnswerLine -> setText("Incorrect Input4");
            return 0;
        }
    }
}
