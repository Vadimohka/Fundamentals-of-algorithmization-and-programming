#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::calculateMedians);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateMedians() {
    QString input = ui->lineEdit->text();
    QStringList list = input.split(",");
    QVector<double> a;
    for (const QString &str : list) {
        a.push_back(str.trimmed().toDouble());
    }

    QVector<double> b;
    for (int i = 0; i < a.size(); i += 3) {
        QVector<double> temp;
        for (int j = i; j < std::min(static_cast<qsizetype>(i + 3), a.size()); ++j) {
            temp.push_back(a[j]);
        }
        std::sort(temp.begin(), temp.end());
        if (temp.size() == 3) {
            b.push_back(temp[1]);
        } else {
            double sum = 0;
            for (double val : temp) {
                sum += val;
            }
            b.push_back(sum / temp.size());
        }
    }

    QString output;
    for (double val : b) {
        output += QString::number(val) + ", ";
    }
    output.chop(2);
    ui->textEdit->setText(output);
}
