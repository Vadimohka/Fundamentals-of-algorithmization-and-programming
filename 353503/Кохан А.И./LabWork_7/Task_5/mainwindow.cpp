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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (ui->pushBox->hasFocus()) {
        if (event->key() == Qt::Key_Return) {
            deque.push_front(ui->pushBox->value());
            outputDeque();
        } else if (event->key() == Qt::Key_Enter) {
            deque.push_back(ui->pushBox->value());
            outputDeque();
        }
    }
}

void MainWindow::outputDeque()
{
    ui->dequeEdit->clear();
    for (size_t i = 0; i < deque.size(); ++i) {
        ui->dequeEdit->setText(ui->dequeEdit->toPlainText() + QString::number(deque.at(i)) + ' ');
    }
}

void MainWindow::on_push_front_Button_clicked()
{
    deque.push_front(ui->pushBox->value());
    outputDeque();
}

void MainWindow::on_push_back_Button_clicked()
{
    deque.push_back(ui->pushBox->value());
    outputDeque();
}

void MainWindow::on_sizeButton_clicked()
{
    ui->infoEdit->setText(QString::number(deque.size()));
}

void MainWindow::on_clearButton_clicked()
{
    deque.clear();
    ui->dequeEdit->clear();
}

void MainWindow::on_emptyButton_clicked()
{
    ui->infoEdit->setText((deque.empty()) ? "True" : "False");
}

void MainWindow::on_pop_front_Button_clicked()
{
    deque.pop_front();
    outputDeque();
}

void MainWindow::on_pop_back_Button_clicked()
{
    deque.pop_back();
    outputDeque();
}
