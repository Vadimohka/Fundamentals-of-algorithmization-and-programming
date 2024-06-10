#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>
#include <QThread>

constexpr int NumOfColumns = 200;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    scene(new QGraphicsScene(this))
{
    ui->setupUi(this);

    ui->graphicsView->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    ui->graphicsView->setScene(scene);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->binSearch->setEnabled(false);
    ui->index_lineEdit->setReadOnly(true);

    connect(ui->sort_btn, SIGNAL(clicked()), this, SLOT(sorting()));
    connect(ui->random_btn, SIGNAL(clicked()), this, SLOT(randomize()));
    connect(ui->binSearch, SIGNAL(clicked()), this, SLOT(binSearch()));

    prepareScene();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->graphicsView->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    drawColumns();

    QMainWindow::resizeEvent(event);
}

void MainWindow::prepareScene()
{
    inititalizeArray();
    initializeColumns();
    drawColumns();
}

void MainWindow::changeColumnColor(int index, const QColor &color)
{
    columns[index]->setBrush(QBrush(color));
    scene->update();
}

void MainWindow::swapColumns(QGraphicsRectItem &item1, QGraphicsRectItem &item2)
{
    qreal height1 = item1.rect().height();
    qreal height2 = item2.rect().height();


    item1.setRect(item1.rect().x(), item1.rect().y(), item1.rect().width(), height2);
    item2.setRect(item2.rect().x(), item2.rect().y(), item2.rect().width(), height1);

    item1.setBrush(Qt::red);
    item2.setBrush(Qt::red);

    QCoreApplication::processEvents();
    QThread::msleep(20);

    scene->update();

    item1.setBrush(Qt::black);
    item2.setBrush(Qt::black);
}

void MainWindow::swapColumns(QGraphicsRectItem &item, qreal height)
{
    item.setRect(item.rect().x(), item.rect().y(), item.rect().width(), -(height * ui->graphicsView->height() / 100));

    item.setBrush(Qt::red);

    QCoreApplication::processEvents();
    QThread::msleep(20);

    scene->update();

    item.setBrush(Qt::black);
}

void MainWindow::inititalizeArray()
{
    for (int i = 0; i < NumOfColumns; ++i) {
        array.push_back(QRandomGenerator::global()->bounded(100));
    }
}

void MainWindow::initializeColumns()
{
    scene->clear();
    columns.clear();

    QPen pen(Qt::black);
    QBrush brush(Qt::black);

    float width = ui->graphicsView->width();
    float height = ui->graphicsView->height();

    float columnWidth = width / array.size();

    for (int i = 0; i < array.size(); ++i) {
        float columnHeight = array[i] * height / 100;

        if (array[i] < 0) columnHeight = -columnHeight;

        QGraphicsRectItem *column = new QGraphicsRectItem(i * columnWidth + 2, height, columnWidth, -columnHeight);
        column->setPen(pen);
        column->setBrush(brush);
        columns.append(column);

        scene->addItem(column);
    }
}

void MainWindow::drawColumns()
{
    float width = ui->graphicsView->width();
    float height = ui->graphicsView->height();

    float columnWidth = width / array.size();

    for (int i = 0; i < array.size(); ++i) {
        float columnHeight = array[i] * height / 100;

        if (array[i] < 0) columnHeight = -columnHeight;

        columns[i]->setRect(i * columnWidth + 2, height, columnWidth, -columnHeight);
    }

    scene->update();
}

void MainWindow::randomize()
{
    if (findedIndex != -1) changeColumnColor(findedIndex, Qt::black);

    ui->sort_btn->setEnabled(true);

    ui->binsearch_lineEdit->clear();
    ui->index_lineEdit->clear();
    ui->binPow_lineEdit->clear();

    array.clear();
    inititalizeArray();
    initializeColumns();
    drawColumns();
}

void MainWindow::swap(int i, int j)
{
    std::swap(array[i], array[j]);
}

long long MainWindow::binPow(long long base, long long exponent, long long modulus)
{
    long long output = 1;
    while (exponent) {
        if (exponent % 2 == 1) {
            output = (output * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return output;
}



void MainWindow::sorting()
{
    steps.clear();

    ui->random_btn->setEnabled(false);
    ui->sort_btn->setEnabled(false);
    ui->binSearch->setEnabled(false);


    if (ui->sorts_comboBox->currentText() == "Interpolation Sort") {
        interpolationSort();
        isSorted = true;
    }


    ui->random_btn->setEnabled(isSorted);
    ui->binSearch->setEnabled(isSorted);
}

void MainWindow::interpolationSort()
{
    QVector<int> divideSize;
    int end = array.size();
    divideSize.push_back(end);
    while (!divideSize.empty()) {
        divide(divideSize, end);
    }
}

void MainWindow::divide(QVector<int> &divideSize, int& end)
{
    int size = divideSize.back();
    divideSize.pop_back();
    int start = end - size;
    int min = array[start];
    int max = array[start];
    for (int i = start + 1; i < end; i++) {
        if (array[i] < min) {
            min = array[i];
        } else if (array[i] > max) {
            max = array[i];
        }
    }
    if (min == max) {
        end = end - size;
    }
    else {
        int p = 0;
        QVector<QVector<int>> bucket(size);
        for (int i = start; i < end; i++) {
            p = std::floor(((array[i] - min ) / (double)(max - min ) ) * (size - 1 ));
            bucket[p].push_back(array[i]);
        }
        for (int i = 0; i < size; i++) {
            if (!bucket[i].empty()) {
                for (int j = 0; j < bucket[i].size(); j++) {
                    array[start++] = bucket[i][j];
                    swapColumns(*columns.at(start - 1), bucket[i][j]);
                }
                divideSize.push_back(bucket[i].size());
            }
        }
    }
}

int MainWindow::binSearch()
{
    if (findedIndex != -1) changeColumnColor(findedIndex, Qt::black);

    bool flag = false;
    int x = ui->binsearch_lineEdit->text().toInt(&flag);
    if (!flag) {
        ui->index_lineEdit->setText("Incorrect input!");
        return -1;
    }

    int l = 0;
    int r = array.size() - 1;
    int m = 0;
    while (l <= r) {
        m = l + (r - l) / 2;

        changeColumnColor(m, Qt::red);

        QCoreApplication::processEvents();
        QThread::msleep(40);

        changeColumnColor(m, Qt::black);


        if (array[m] == x) {
            changeColumnColor(m, Qt::green);
            ui->index_lineEdit->setText(QString::number(m));

            long long result = binPow(m, array.size(), array[m]);
            ui->binPow_lineEdit->setText(QString::number(result));

            findedIndex = m;
            return m;
        }
        if (array[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    ui->index_lineEdit->setText("Number not found!");
    return -1;
}
