#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelArr->setWordWrap(true);
    ui->searchEdit->setMaximum(600);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->sizeEdit->setText("200");
    index = 0;

    timer = new QElapsedTimer();
    for (int i = 0; i < 200; i++) {
        arr.push_back(QRandomGenerator::global()->bounded(50, 550));
    }
    printArr();
    connect(ui->sizeEdit, &QLineEdit::textChanged, this, &MainWindow::changeArrSize);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int sceneW = ui->graphicsView->width();
    int sceneH = ui->graphicsView->height();
    double rectW = static_cast<double>(sceneW) / arr.size();
    ui->graphicsView->scene()->clear();
    for (int i = 0; i < arr.size(); i++) {
        QRect rect(10 + i * rectW, sceneH - arr[i], rectW, arr[i]+50);
        QGraphicsRectItem *rectItem = scene->addRect(rect);
        rectItem->setBrush(Qt::white);
        rectItem->setPen(QPen(Qt::black));
    }
}

void MainWindow::RandomArr(int size)
{
    arr.clear();
    for (int i = 0; i < size; i++) {
        arr.push_back(QRandomGenerator::global()->bounded(50, 550));
    }
}

bool MainWindow::isSorted()
{
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void MainWindow::changeArrSize()
{
    bool ok;

    int size = ui->sizeEdit->text().toInt(&ok);
    if (ok && size > 0 && size <= 400) {
        currIndex = -1;
        ui->graphicsView->scene()->clear();
        ui->label->clear();
        ui->labelSearch->clear();
        ui->searchEdit->clear();
        RandomArr(size);
        printArr();
        ui->sort->setEnabled(true);
        update();
    } else {
        QMessageBox::warning(this, "Ошибка", "Введите положительное целое число до 400");
    }
}

void MainWindow::merge(QVector<int> &arr, int l, int m, int r)
{
    int n1 = m + 1 - l;
    int n2 = r - m;
    QVector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (stop) {
            return;
        }
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            update();
            QThread::msleep(20);
            printArr();
            QCoreApplication::processEvents();
            i++;
        } else {
            arr[k] = R[j];
            update();
            printArr();
            QThread::msleep(20);
            QCoreApplication::processEvents();
            j++;
        }
        k++;
    }
    while (i < n1) {
        if (stop) {
            return;
        }
        arr[k++] = L[i++];
        update();
        printArr();
        QThread::msleep(20);
        QCoreApplication::processEvents();
    }
    while (j < n2) {
        if (stop) {
            return;
        }
        arr[k++] = R[j++];
        printArr();
        update();
        QThread::msleep(20);
        QCoreApplication::processEvents();
    }
}

void MainWindow::MergeSort(QVector<int> &, int l, int r)
{
    if (stop) {
        return;
    }
    if (l < r) {
        int m = (l + r) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
        update();
        printArr();
        QThread::msleep(20);
        QCoreApplication::processEvents();
    }
}

void MainWindow::QuickSort(QVector<int> &arr, int low, int high)
{
    if (stop) {
        return;
    }
    if (low < high) {
        int pi = partition(arr, low, high);
        printArr();
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
        if (stop) {
            return;
        }
    }
}

int MainWindow::partition(QVector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            update();
            printArr();
            QThread::msleep(20);
            QCoreApplication::processEvents();
        }
    }
    std::swap(arr[i + 1], arr[high]);
    printArr();
    return (i + 1);
}

void MainWindow::heapify(QVector<int> &arr, int n, int i)
{
    if (stop) {
        return;
    }
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        update();
        QThread::msleep(20);
        QCoreApplication::processEvents();
        printArr();
        heapify(arr, n, largest);
    }
}

void MainWindow::HeapSort(QVector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        if (stop) {
            return;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        update();
        QThread::msleep(20);
        QCoreApplication::processEvents();
        heapify(arr, i, 0);
        if (stop) {
            return;
        }
    }
    printArr();
}

void MainWindow::on_sort_clicked()
{
    timer->start();

    ui->sortBox->setEnabled(false);
    ui->sort->setEnabled(false);
    ui->searchButton->setEnabled(false);
    ui->searchEdit->setEnabled(false);
    stop = false;
    ui->sizeEdit->setEnabled(0);
    if (ui->sortBox->currentIndex() == 0) {
        MergeSort(arr, 0, arr.size() - 1);
    } else if (ui->sortBox->currentIndex() == 1) {
        QuickSort(arr, 0, arr.size() - 1);
    } else if (ui->sortBox->currentIndex() == 2) {
        HeapSort(arr, arr.size());
    } else if (ui->sortBox->currentIndex() == 3) {
        Isort = new InterpolationSort();
        connect(Isort, SIGNAL(arrChanged()), this, SLOT(Updatee()));
        Isort->sort(arr);
    }
    ui->searchButton->setEnabled(true);
    ui->searchEdit->setEnabled(true);
    ui->sortBox->setEnabled(true);

    ui->sizeEdit->setEnabled(true);
    if (isSorted()) {
        qint64 Time = timer->elapsed();
        ui->label->setText(QString::number(Time) + " мс");
    }
}

void MainWindow::Updatee()
{
    update();
    printArr();
    QThread::msleep(20);
    QCoreApplication::processEvents();
}

void MainWindow::on_restart_clicked()
{
    currIndex = -1;
    stop = true;
    ui->label->clear();
    ui->searchEdit->clear();
    ui->labelSearch->clear();
    RandomArr(arr.size());
    printArr();
    ui->sortBox->setEnabled(true);
    ui->sort->setEnabled(true);

    update();
}

int MainWindow::binsearch(QVector<int> &arr, int size, int digit)
{
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        leftIndex = left;
        rightIndex = right;
        int mid = (left + right) / 2;
        if (arr[mid] == digit) {
            currIndex = mid;
            return mid;
        }
        if (arr[mid] < digit) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void MainWindow::on_searchButton_clicked()
{
    int digit = ui->searchEdit->text().toInt();

    if (!isSorted()) {
        ui->searchEdit->setEnabled(false);
        QMessageBox::warning(this, "Ошибка", "Массив должен быть отсортирован перед поиском");
    } else if (digit == 0 && ui->searchEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите число для поиска");
        return;
    } else {
        int index = binsearch(arr, arr.size(), digit);
        ui->labelSearch->setText(QString::number(index));
    }
}

void MainWindow::printArr(){
    QString arrayStr = "";
    for (int i = 0; i < arr.size(); i++) {
        arrayStr += QString::number(arr[i]);
            arrayStr += ", ";
    }
    arrayStr.chop(2);
    ui->labelArr->setText(arrayStr);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->labelSearch->text() == ""){
       QMessageBox::warning(this, "Ошибка", "Сначала найдите индекс");
        return;
    }
    long long answer = Binpow::binpow(ui->labelSearch->text().toLongLong(), arr.size(), ui->modulNumber->value());
    ui->labelSearchAfterBinPow->setText(QString::number(answer));
}

