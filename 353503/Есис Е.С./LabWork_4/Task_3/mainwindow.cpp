#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "median_treaples.h"

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




void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    QStringList stringList = text.split(" ");

    QVector<long long> myVector;
    for (int i = 0; i < myVector.size(); ++i) {
        myVector[i] = stringList[i].toInt(); // Преобразуем каждую подстроку в число
    }

    median_treaples *mt = new median_treaples();
    QVector<long long> sorted_vector = mt->getMedianTriples(myVector);
    std::string s;
    for(int i = 0; i < sorted_vector.size(); i++) {
        s += std::to_string(sorted_vector[i]);
        if(i != sorted_vector.size() - 1) {
            s += " ";
        }
        ui->lineEdit->setText(QString::fromStdString(s));
    }
}

