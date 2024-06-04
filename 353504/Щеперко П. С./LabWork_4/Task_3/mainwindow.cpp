#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("([0-9][ ])*")));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PrintMedianVector()
{
    QString strMedianVector = "";

    for (int i = 0; i < medianVector.size(); i++) {
        strMedianVector += QString::number(medianVector[i]);

        if (i != medianVector.size() - 1) {
            strMedianVector += " ";
        }
    }
    ui->label_3->setText(strMedianVector);
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    if (arg1.isEmpty())
        ui->pushButton->setEnabled(false);
    else
        ui->pushButton->setEnabled(true);
}


void MainWindow::on_pushButton_clicked()
{
    medianVector.clear();
    QStringList list = ui->lineEdit->text().split(" ");

    QString strVector = "";
    QVector<int> three;
    int count = 0;

    for (int i = 0; i < list.size(); i++) {
        three.push_back(list[i].toInt());
        count++;

        if (count == 3) {
            std::sort(three.begin(), three.end());
            medianVector.push_back(three[1]);
            three.clear();
            count = 0;
        }
    }

    if (three.size() != 0) {
        int sum = 0;
        for (int i = 0; i < three.size(); i++) {
            sum += three[i];
        }

        medianVector.push_back(sum / three.size());
    }
    PrintMedianVector();
}


