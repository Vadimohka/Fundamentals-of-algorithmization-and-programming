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

    ui->graphicsView->setScene(scene);

    ui->graphicsView->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

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

    array.clear();
    inititalizeArray();
    initializeColumns();
    drawColumns();
}

void MainWindow::swap(int i, int j)
{
    std::swap(array[i], array[j]);
}

long long MainWindow::binPow(long long digit, long long powder, long long mod)
{
    long long result = 1;
    while (powder) {
        if (powder & 1) {
            result = (result * digit) % mod;
        }
        digit = (digit * digit) % mod;
        powder >>= 1;
    }
    return result;
}


void MainWindow::sorting()
{
    steps.clear();

    ui->random_btn->setEnabled(false);
    ui->sort_btn->setEnabled(false);
    ui->binSearch->setEnabled(false);

    if (ui->sorts_comboBox->currentText() == "Heap Sort") {
        heapSort();
        isSorted = true;
    } else if (ui->sorts_comboBox->currentText() == "Quick Sort") {
        quickSort(0, array.size() - 1);
        isSorted = true;
    } else if (ui->sorts_comboBox->currentText() == "Interpolation Sort") {
        interpolationSort();
        isSorted = true;
    } else if (ui->sorts_comboBox->currentText() == "Merge Sort") {
        mergeSort(0, array.size() - 1);
        isSorted = true;
    }

    ui->random_btn->setEnabled(isSorted);
    ui->binSearch->setEnabled(isSorted);
}


void MainWindow::quickSort(int start, int end)
{
    if (start < end) {
        int p = partition(start, end);
        quickSort(start, p - 1);
        quickSort(p + 1, end);
    }
}

int MainWindow::partition(int start, int end)
{
    int pivot = array[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(i, j);
            swapColumns(*columns.at(i), *columns.at(j));
        }
    }
    swap(i + 1, end);
    swapColumns(*columns.at(i + 1), *columns.at(end));

    return (i + 1);
}

void MainWindow::heapify(int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(i, largest);
        swapColumns(*columns.at(i), *columns.at(largest));
        heapify(n, largest);
    }
}

void MainWindow::heapSort()
{
    int n = array.size();

    for (int i = (n - 1) / 2; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(0, i);
        swapColumns(*columns.at(0), *columns.at(i));
        heapify(i, 0);
    }
}


void MainWindow::merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    QVector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            swapColumns(*columns.at(k), L[i]);
            i++;
        } else {
            array[k] = R[j];
            swapColumns(*columns.at(k), R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        swapColumns(*columns.at(k), L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        swapColumns(*columns.at(k), R[j]);
        j++;
        k++;
    }


}

void MainWindow::mergeSort(int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);

        merge(l, m, r);
    }
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
