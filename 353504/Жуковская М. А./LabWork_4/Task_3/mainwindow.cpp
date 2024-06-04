#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    int el = ui->spinBox->value();

    vector.push_back(el);

    printVector();
}

void MainWindow::printVector() {
    QString strVector = "";

    for (int i = 0; i < vector.size(); i++) {
        strVector += QString::number(vector[i]);

        if (i != vector.size() - 1) {
            strVector += ", ";
        }
    }

    ui->label->setText("["+strVector+"]");
}

void MainWindow::printB() {
    QString strVector = "";

    for (int i = 0; i < b.size(); i++) {
        strVector += QString::number(b[i]);

        if (i != b.size() - 1) {
            strVector += ", ";
        }
    }

    ui->label_2->setText("Вектор b из медиан: ["+strVector+"]");
}


void MainWindow::on_pushButton_2_clicked()
{
    b.clear();
    std::vector<int> troiki;
    int count = 0;

    for (int i = 0; i < vector.size(); i++) {
        troiki.push_back(vector[i]);
        count++;

        if (count == 3) {
            std::sort(troiki.begin(), troiki.end());
            b.push_back(troiki[1]);
            troiki.clear();
            count = 0;
        }
    }

    if (troiki.size() != 0) {
        int sum = 0;
        for (int i = 0; i < troiki.size(); i++) {
            sum += troiki[i];
        }

        b.push_back(sum/troiki.size());
    }

    printB();

}


void MainWindow::on_pushButton_4_clicked()
{
    vector.pop_back();
    printVector();
}


void MainWindow::on_pushButton_3_clicked()
{
    vector.clear();
    printVector();
}

