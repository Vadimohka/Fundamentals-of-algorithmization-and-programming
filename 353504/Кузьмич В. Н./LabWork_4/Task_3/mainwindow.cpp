#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString v, a = "([,][+-]?[0-9]{1,16})";
    v.insert(0, a.repeated(1200));
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[-+]?[0-9]{1,16}" + v),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QVector <double> numbers, got_mas;
    QString input = ui -> lineEdit -> text();
    QStringList numbersAsStrings = input.split(",");
    for(const QString& str : numbersAsStrings) {
        long long num = str.toLongLong();
        numbers.append(num);
    }
    for (int i = 2; i < numbers.size(); i += 3){
        int a = numbers[i - 2], b = numbers[i - 1], c = numbers[i];
        if (a > b) std::swap(a, b);
        if (a > c) std::swap(a, c);
        if (b > c) std::swap(b, c);
        got_mas.append(b);
    }
    long long sum = 0;
    if (numbers.size() % 3 == 1){
        got_mas.append(numbers[numbers.size() - 1]);
    }
    else if (numbers.size() % 3 == 2){
        got_mas.append((double)(numbers[numbers.size() - 1] + numbers[numbers.size() - 2]) / 2);
    }
    QString mas {"{"};
    for (int i = 0; i < got_mas.size(); i++) {
        mas += QString::number(got_mas[i]);
        if (i < got_mas.size() - 1) mas += ",";
        else mas += "}";
    }
    ui->textEdit->setText("Ответ: " + mas);
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}

