#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow), _hanoi(new Hanoi)
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
    delete _hanoi;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    bool isNumber = false;
    _ui->textBrowser->setText("");

    int numberOfTowers = arg1.toInt(&isNumber);

    if (isNumber and numberOfTowers < MAX_LIMIT_OF_TOWER and numberOfTowers > MIN_LIMIT_OF_TOWER){
        _hanoi->solution(numberOfTowers);
        _ui->textBrowser->setText(_hanoi->getStepInfo());
    }
    else{
        _ui->textBrowser->setText("ВВедите число от 3 до 19");
    }
}

