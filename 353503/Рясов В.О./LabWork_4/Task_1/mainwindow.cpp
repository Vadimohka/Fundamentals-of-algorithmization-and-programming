#include "mainwindow.h"
#include "ConstSort.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene)
    , timer(new QTimer)
    , timerElapsed(new QElapsedTimer)
{
    ui->setupUi(this);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setScene(scene);

    connect(timer, &QTimer::timeout, this, &MainWindow::visualizeSort);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::visualizeSort()
{
    if (ui->quickSortButton->isChecked()) {
        timerElapsed->start();
        QuickSort::quickSort(numbers,
                             rects,
                             textNumbers,
                             sceneHeight,
                             maxNumber,
                             sceneWidth,
                             ui->spinBox_2->value(),
                             scene,
                             0,
                             numbers.size() - 1);
        elapsedTime = timerElapsed->elapsed();

        for (auto &rect : rects) {
            rect->setBrush(Qt::gray);
        }
    }

    /*else if (ui->bubbleSortButton->isChecked()) {
        timerElapsed->start();
        BubbleSort::bubbleSort(numbers,
                               rects,
                               textNumbers,
                               sceneHeight,
                               maxNumber,
                               sceneWidth,
                               ui->spinBox_2->value(),
                               scene);
        elapsedTime = timerElapsed->elapsed();
    }*/

    else if (ui->heapSortButton->isChecked()) {
        timerElapsed->start();
        HeapSort::heapSort(numbers,
                           rects,
                           textNumbers,
                           sceneHeight,
                           maxNumber,
                           sceneWidth,
                           ui->spinBox_2->value(),
                           scene);
        elapsedTime = timerElapsed->elapsed();
    }

    else if (ui->mergeSortButton->isChecked()) {
        timerElapsed->start();
        MergeSort::mergeSort(numbers,
                             rects,
                             sceneHeight,
                             maxNumber,
                             sceneWidth,
                             ui->spinBox_2->value(),
                             scene,
                             0,
                             numbers.size() - 1);
        elapsedTime = timerElapsed->elapsed();
    }

    else if (ui->binSearchButton->isChecked()) {
        QuickSort::quickSort(numbers,
                             rects,
                             textNumbers,
                             sceneHeight,
                             maxNumber,
                             sceneWidth,
                             ui->spinBox_2->value(),
                             scene,
                             0,
                             numbers.size() - 1);
        for (auto &rect : rects) {
            rect->setBrush(Qt::gray);
        }
        if (vector_has_negative_number) {
            BinSearch::binsearch(numbers,
                                 ui->spinBox->value() + SUM_FOR_FIXED_ERROR,
                                 rects,
                                 scene,
                                 ui->spinBox_2->value());
        }

        else {
            BinSearch::binsearch(numbers, ui->spinBox->value(), rects, scene, ui->spinBox_2->value());
        }
    }

    else if (ui->interpolationSortButton->isChecked()) {
        timerElapsed->start();
        InterpolationSort::interpolationSort(numbers,
                                             rects,
                                             sceneHeight,
                                             maxNumber,
                                             sceneWidth,
                                             ui->spinBox_2->value(),
                                             scene);
        elapsedTime = timerElapsed->elapsed();
    }

    timer->stop();
    completeSort = true;
    ui->lineSpeed->setText(QString::number(elapsedTime));
}

void MainWindow::on_startSort_clicked()
{
    if ((/*ui->bubbleSortButton->isChecked() ||*/

         ui->quickSortButton->isChecked() || ui->heapSortButton->isChecked()
         || ui->mergeSortButton->isChecked() || ui->binSearchButton->isChecked()
         || ui->interpolationSortButton->isChecked())
        && !timer->isActive() && numbers.size() != 0) {
        if (completeSort) {
            scene->clear();
            numbers.clear();
            rects.clear();
            textNumbers.clear();

            QStringList strList = ui->lineElement->text().split(" ");

            for (int i = 0; i < strList.size() - 1; ++i) {
                numbers.push_back(strList[i].toInt());
            }

            completeSort = false;
        }

        for (int number : numbers) {
            if (number <= 0) {
                vector_has_negative_number = true;
                for (int &number : numbers) {
                    number += SUM_FOR_FIXED_ERROR;
                }
                break;
            }
        }

        maxNumber = *std::max_element(numbers.begin(), numbers.end());
        sceneHeight = ui->graphicsView->height() - DELTA_SIZE_WINDOW;
        sceneWidth = ui->graphicsView->width() - DELTA_SIZE_WINDOW;

        for (int i = 0; i < numbers.size(); ++i) {
            int rectHeight = (numbers[i] * sceneHeight / maxNumber);
            int rectWidth = sceneWidth / numbers.size();
            QGraphicsRectItem *rect = scene->addRect(i * rectWidth,
                                                     sceneHeight - rectHeight,
                                                     rectWidth,
                                                     rectHeight);

            QGraphicsTextItem *text = nullptr;

            if (vector_has_negative_number && !ui->mergeSortButton->isChecked()
                && !ui->interpolationSortButton->isChecked()) {
                text = new QGraphicsTextItem(QString::number(numbers[i] - SUM_FOR_FIXED_ERROR),
                                             rect);
                text->setPos(rect->rect().center() - text->boundingRect().center());
                textNumbers.append(text);
            }

            else if (!ui->mergeSortButton->isChecked()
                     && !ui->interpolationSortButton->isChecked()) {
                text = new QGraphicsTextItem(QString::number(numbers[i]), rect);
                text->setPos(rect->rect().center() - text->boundingRect().center());
                textNumbers.append(text);
            }

            rect->setBrush(Qt::gray);
            rects.append(rect);
            timer->start(speedTimer);
        }
    }
}

void MainWindow::on_addElement_clicked()
{
    if (!timer->isActive()) {
        numbers.push_back(ui->spinBox->value());
        QString nowText = ui->lineElement->text();

        for (int i = 0; i < numbers.size(); ++i) {
            ui->lineElement->setText(nowText + QString::number(ui->spinBox->value()) + " ");
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        && ui->spinBox->hasFocus()) {
        if (!timer->isActive()) {
            numbers.push_back(ui->spinBox->value());
            QString nowText = ui->lineElement->text();

            for (int i = 0; i < numbers.size(); ++i) {
                ui->lineElement->setText(nowText + QString::number(ui->spinBox->value()) + " ");
            }
        }
    }
}
void MainWindow::on_deleteButton_clicked()
{
    if (!numbers.empty() && !timer->isActive()) {
        numbers.pop_back();
        ui->lineElement->setText("");
        for (int i : numbers) {
            if (vector_has_negative_number) {
                ui->lineElement->setText(ui->lineElement->text()
                                         + QString::number(i - SUM_FOR_FIXED_ERROR) + " ");
            }

            else {
                ui->lineElement->setText(ui->lineElement->text() + QString::number(i) + " ");
            }
        }
    }
}

void MainWindow::on_deleteAllButton_clicked()
{
    if (!numbers.empty() && !timer->isActive()) {
        numbers.clear();
        vector_has_negative_number = false;
        ui->lineElement->setText("");
    }
}
