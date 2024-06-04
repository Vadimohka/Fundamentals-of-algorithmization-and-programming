#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "constSize.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , modTable(new HashModTable<QString>(SIZE_HASHTABLE_16))
    , multTable(new HashMultTable<QString>(SIZE_HASHTABLE_16))
    , timerFind(new QElapsedTimer)
{
    ui->setupUi(this);
    plotSearchTimes(ui->widget, timesMod, timesMult);
    fillHashTableRandomValue(SIZE_HASHTABLE_16);
    setCollisions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::plotSearchTimes(QCustomPlot *customPlot,
                                 QVector<double> &times1,
                                 QVector<double> &times2)
{
    customPlot->clearGraphs();
    QVector<double> x(times1.size());
    for (int i = 0; i < times1.size(); ++i) {
        x[i] = i;
    }

    // Добавляем данные на график
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, times1);
    customPlot->graph(0)->setPen(QPen(Qt::blue));  // Цвет линии - синий
    customPlot->graph(0)->setName("HashModTable"); // Название графика

    customPlot->addGraph();
    customPlot->graph(1)->setData(x, times2);
    customPlot->graph(1)->setPen(QPen(Qt::red));    // Цвет линии - красный
    customPlot->graph(1)->setName("HashMultTable"); // Название графика

    // Устанавливаем оси
    customPlot->xAxis->setLabel("Номер попытки");
    customPlot->yAxis->setLabel("Время поиска");

    // Устанавливаем легенду
    customPlot->legend->setVisible(true);

    // Автомасштабирование осей
    customPlot->rescaleAxes();

    // Перерисовываем график
    customPlot->replot();
}

unsigned int MainWindow::generateRandomNumber()
{
    return QRandomGenerator::global()->bounded(INT_MAX);
}

QString MainWindow::generateRandomString(unsigned int length)
{
    QString randomString;
    static const char alphanum[] = "0123456789"
                                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz";

    for (unsigned int i = 0; i < length; ++i) {
        randomString
            += alphanum[QRandomGenerator::global()->bounded(static_cast<int>(sizeof(alphanum) - 1))];
    }

    return randomString;
}

void MainWindow::fillHashTableRandomValue(unsigned int size)
{
    modTable = new HashModTable<QString>(size);
    multTable = new HashMultTable<QString>(size);
    for (unsigned int i = 0; i < size; ++i) {
        modTable->insert(generateRandomNumber(), generateRandomString(size));
        multTable->insert(generateRandomNumber(), generateRandomString(size));
    }
}

void MainWindow::speedFindHashModTable()
{
    timerFind->start();
    for (int i = 0; i < AMOUNT_ITERATION_FIND; ++i) {
        modTable->findMax();
    }
    elapsedTime = timerFind->elapsed();
    timesMod.push_back(elapsedTime);
}

void MainWindow::speedFindHashMultTable()
{
    timerFind->start();
    for (int i = 0; i < AMOUNT_ITERATION_FIND; ++i) {
        modTable->findMax();
    }
    timesMult.push_back(timerFind->elapsed());
}

void MainWindow::setCollisions()
{
    ui->amountModCollisions->display(static_cast<int>(modTable->amountСollisions()));
    ui->amountMultCollisions->display(static_cast<int>(multTable->amountСollisions()));
}

void MainWindow::on_buildButton_clicked()
{
    plotSearchTimes(ui->widget, timesMod, timesMult);
}

void MainWindow::on_timeFindButton_clicked()
{
    for (int i = 0; i < AMOUNT_ITERATION_MEASUREMENTS; ++i) {
        speedFindHashModTable();
        speedFindHashMultTable();
    }
    ui->amountNumber->display(ui->amountNumber->value() + AMOUNT_ITERATION_MEASUREMENTS);
}

void MainWindow::on_clearButton_clicked()
{
    timesMod.clear();
    timesMult.clear();
    ui->amountNumber->display(0);
}

void MainWindow::on_checkBox16_clicked()
{
    on_clearButton_clicked();
    fillHashTableRandomValue(SIZE_HASHTABLE_16);
    setCollisions();
}

void MainWindow::on_checkBox64_clicked()
{
    on_clearButton_clicked();
    fillHashTableRandomValue(SIZE_HASHTABLE_64);
    setCollisions();
}

void MainWindow::on_checkBox128_clicked()
{
    on_clearButton_clicked();
    fillHashTableRandomValue(SIZE_HASHTABLE_128);
    setCollisions();
}

void MainWindow::on_checkBox2048_clicked()
{
    on_clearButton_clicked();
    fillHashTableRandomValue(SIZE_HASHTABLE_2048);
    setCollisions();
}
