#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsRectItem>
#include <QBrush>
#include <QRandomGenerator>
#include <QTimer>
#include <QThread>
#include <QFileDialog>
#include <QLibrary>
#include <QMessageBox>
#include <QtConcurrent/QtConcurrentRun>

MainWindow *MainWindow::mw = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_spinBox_n_valueChanged(ui->spinBox_n->value());
    on_spinBox_delay_valueChanged(ui->spinBox_delay->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::arrayToSceneCallback(QVector<int> data, QSet<int> look, QSet<int> good, unsigned int read, unsigned int write, unsigned int compare) {
    if (mw) {
        mw->arrayToScene(data, look, good, read, write, compare);
    }
}

void MainWindow::arrayToScene(QVector<int> & data, QSet<int> & look, QSet<int> & good, unsigned read, unsigned write, unsigned compare){
    if (abort) return;
    ui->label_read->setText(QString::number(read));
    ui->label_write->setText(QString::number(write));
    ui->label_compare->setText(QString::number(compare));
    QGraphicsView *view = ui->graphicsView;
    delete view->scene();
    QGraphicsScene *scene = new QGraphicsScene(this);
    view->setScene(scene);

    int barWidth;
    if      (size <= 50)  barWidth = 20;
    else if (size <= 53)  barWidth = 19;
    else if (size <= 56)  barWidth = 18;
    else if (size <= 59)  barWidth = 17;
    else if (size <= 63)  barWidth = 16;
    else if (size <= 67)  barWidth = 15;
    else if (size <= 72)  barWidth = 14;
    else if (size <= 77)  barWidth = 13;
    else if (size <= 84)  barWidth = 12;
    else if (size <= 91)  barWidth = 11;
    else if (size <= 100) barWidth = 10;
    else if (size <= 112) barWidth =  9;
    else if (size <= 126) barWidth =  8;
    else if (size <= 144) barWidth =  7;
    else if (size <= 168) barWidth =  6;
    else if (size <= 201) barWidth =  5;
    else if (size <= 252) barWidth =  4;
    else if (size <= 336) barWidth =  3;
    else                  barWidth =  2;
    int xPos = 0;
    int height;
    int n = size;
    for (int i = 0; i < data.size(); ++i)
    {
        height = 1. * (view->height() - 10) / n * data[i];
        QGraphicsRectItem *bar = new QGraphicsRectItem(xPos, -height, barWidth, height);
        if (look.contains(i))
            bar->setBrush(QBrush(Qt::red));
        else if (good.contains(i))
            bar->setBrush(QBrush(Qt::green));
        else
            bar->setBrush(QBrush(Qt::yellow));
        scene->addItem(bar);
        xPos += barWidth;
    }
}

void MainWindow::on_spinBox_n_valueChanged(int arg1)
{
    size = arg1;
}

void MainWindow::on_comboBox_rand_activated(int index)
{
    rand = index;
}

QVector<int> MainWindow::generateVec(int n, int r){
    QVector<int> result;
    if (r == 0) {
        for (int i = 1; i <= n; ++i) {
            result.append(i);
        }
        std::random_shuffle(result.begin(), result.end());
    } else
        if (r == 1) { //low
            int number1, number2, number3;
            for (int i = 0; i < n; ++i) {
                number1 = QRandomGenerator::global()->bounded(1, n + 1);
                number2 = QRandomGenerator::global()->bounded(1, n + 1);
                number3 = QRandomGenerator::global()->bounded(1, n + 1);
                result.append(qMin(number1, qMin(number2, number3)));
            }
        } else
            if (r == 2) { //high
                int number1, number2, number3;
                for (int i = 0; i < n; ++i) {
                    number1 = QRandomGenerator::global()->bounded(1, n + 1);
                    number2 = QRandomGenerator::global()->bounded(1, n + 1);
                    number3 = QRandomGenerator::global()->bounded(1, n + 1);
                    result.append(qMax(number1, qMax(number2, number3)));
                }
            } else
                if (r == 3) {  //norm
                    int number;
                    for (int i = 0; i < n; ++i) {
                        number = QRandomGenerator::global()->bounded(1, n + 1);
                        result.append(number);
                    }
                }
    return result;

}

void MainWindow::on_spinBox_delay_valueChanged(int arg1)
{
    delay = arg1 - 1;
}

typedef void (*ArrayToSceneFunction)(QVector<int>, QSet<int>, QSet<int>, unsigned, unsigned, unsigned);
typedef void (*SortFunction)(QVector<int>&, ArrayToSceneFunction, unsigned &, bool&, bool&);

void MainWindow::on_pushButton_proc_clicked()
{
    mw = this;
    auto data = generateVec(size, rand);
    pause = false;
    abort = false;
    if (abort == false){
        ui->comboBox_rand->setEnabled(false);
        ui->spinBox_n->setEnabled(false);
    }


    QString fileName = QFileDialog::getOpenFileName(this, tr("Open DLL"), "D://Projects/Qt/dll", tr("DLL Files (*.dll);;All Files (*)"));;
    if (fileName.isEmpty()){
        abort = true;
        ui->comboBox_rand->setEnabled(true);
        ui->spinBox_n->setEnabled(true);
        return;
    }
    QLibrary library(fileName);
    if (!library.load()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to load DLL"));
        abort = true;
        ui->comboBox_rand->setEnabled(true);
        ui->spinBox_n->setEnabled(true);
        return;
    }

    SortFunction sort = (SortFunction)library.resolve("sort");
    if (!sort) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to resolve function in DLL"));
        abort = true;
        ui->comboBox_rand->setEnabled(true);
        ui->spinBox_n->setEnabled(true);
        return;
    }


    sort(data, arrayToSceneCallback, delay, pause, abort);

    if (abort == true){
        ui->comboBox_rand->setEnabled(true);
        ui->spinBox_n->setEnabled(true);
    }
}

void MainWindow::on_pushButton_pause_clicked()
{
    pause = !pause;
}


void MainWindow::on_pushButton_abort_clicked()
{
    abort = true;
}
