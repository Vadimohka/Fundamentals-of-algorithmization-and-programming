#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "medianvector.h"
#include <QMessageBox>
// #include <QStringList>
// #include <QInputDialog>

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

void MainWindow::on_calculateButton_clicked()
{
    bool ok;
    QString input = ui->inputLineEdit->text();
    QStringList inputList = input.split(",", Qt::SkipEmptyParts);
    QVector<int> arr;

    for (const QString& str : inputList) {
        int element = str.trimmed().toInt(&ok);
        if (ok) {
            arr.push_back(element);
        } else {
            QMessageBox::critical(this, "Error", "Invalid input");
            return;
        }
    }

    MedianVector medianVectorObj;
    QVector<double> medianVector = medianVectorObj.buildMedianVector(arr);

    QString result = "Median vector: ";
    for (int i = 0; i < medianVector.size(); ++i) {
        result += QString::number(medianVector[i]);
        if (i < medianVector.size() - 1) {
            result += ", ";
        }
    }

    QMessageBox::information(this, "Result", result);
}
