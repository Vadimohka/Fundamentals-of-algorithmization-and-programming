#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Демонстрация методов");
    ui->tabWidget->setTabText(1, "Решение задачи");
    /*
    ui->pushButton->setStyleSheet("QPushButton {"
                                  "  background-color: #008631;"
                                  "}"
                                  "QPushButton:disabled {"
                                  "  background-color: #CCCCCC;"
                                  "  color: #666666;"
                                  "}");
    ui->popButton->setStyleSheet("QPushButton {"
                                 "  background-color: #008631;"
                                 "}"
                                 "QPushButton:disabled {"
                                 "  background-color: #CCCCCC;"
                                 "  color: #666666;"
                                 "}");
    ui->insertButton->setStyleSheet("QPushButton {"
                                    "  background-color: #008631;"
                                    "}"
                                    "QPushButton:disabled {"
                                    "  background-color: #CCCCCC;"
                                    "  color: #666666;"
                                    "}");
    ui->fillButton->setStyleSheet("QPushButton {"
                                  "  background-color: #008631;"
                                  "}"
                                  "QPushButton:disabled {"
                                  "  background-color: #CCCCCC;"
                                  "  color: #666666;"
                                  "}");
    */
    ui->insertButton->setDisabled(true);
    ui->popButton->setDisabled(true);
    ui->insertButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->popButton->setDisabled(false);
    deque.push(ui->insertedElComboBox->value());
    showQueue(ui->demoMethodsList, deque);
}


void MainWindow::on_popButton_clicked()
{
    deque.pop();
    if (deque.size() == 0)
        ui->popButton->setDisabled(true);
    showQueue(ui->demoMethodsList, deque);
}

void MainWindow::on_fillButton_clicked()
{
    ui->insertButton->setDisabled(false);
    deque1.clear();

    for (int i = 0; i < 20; ++i) {
        deque1.push(QRandomGenerator64::global()->bounded(100));
    }

    showQueue(ui->queue1Widget, deque1);
}

void MainWindow::on_insertButton_clicked()
{
    deque1.swapMinMax();

    showQueue(ui->queue1Widget, deque1);
}

void MainWindow::showQueue(QListWidget *showingWidget, Deque<int> &showedQueue)
{
    showingWidget->clear();
    for (auto el : showedQueue.toVector())
        showingWidget->addItem(QString::number(el));
}

