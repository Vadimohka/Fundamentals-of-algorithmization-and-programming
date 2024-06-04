#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->elementsBox->setValue(52);
    ui->timeText->setReadOnly(true);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    //countElements = ui->elementsBox->value();
    on_createArrButton_clicked();
    sorted = false;
    timer = new QTimer;
    connect(timer, &QTimer::timeout, [=]{
        if (sizeList == list.size() - 1) {
            ui->elementsBox->setDisabled(false);
            ui->sortButton->setDisabled(sorted);
            ui->searchElButton->setDisabled(!sorted);
            return;
        }
        ui->elementsBox->setDisabled(true);
        ui->sortButton->setDisabled(true);
        ui->searchElButton->setDisabled(true);
        sizeList++;
        DisplayArr();
    });
    timer->start(50);
    on_createArrButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_createArrButton_clicked()
{
    countElements = ui->elementsBox->value();
    arr.clear();
    arrAnima.clear();
    list.clear();
    sizeList = 0;
    sorted = false;
    quint32 element;

    for (int i = 0; i < countElements; ++i) {
        element = QRandomGenerator::global()->bounded(1, 100);
        arr.append(element);
        arrAnima.append(element);
    }
    list.append(arrAnima);
    DisplayArr();
}


void MainWindow::on_sortButton_clicked()
{
    clock_t start;
    clock_t end;
    size_t duration = end - start;
    QuickSort *Qsort = new QuickSort();
    MergeSort *Msort = new MergeSort();
    HeapSort *Hsort = new HeapSort();
    InterpolationSort *Isort = new InterpolationSort();
    double time;
    switch (ui->SortBox->currentIndex()) {
    case 0: {
        start = clock();
        Qsort->quickSort(arr);
        end = clock();
        duration = end - start;
        time = duration * 1000000 / CLOCKS_PER_SEC;
        ui->timeText->setText(QString::number(time) + " мкс");
        Qsort->quickSort(arrAnima, list);
        sorted = true;
        break;
    }
    case 1:
        start = clock();
        Msort->mergeSort(arr);
        end = clock();
        duration = end - start;
        time = duration * 1000000 / CLOCKS_PER_SEC;
        ui->timeText->setText(QString::number(time) + " мкс");
        Msort->mergeSort(arrAnima, list);
        sorted = true;
        break;
    case 2:
        start = clock();
        Hsort->heapSort(arr);
        end = clock();
        duration = end - start;
        time = duration * 1000000 / CLOCKS_PER_SEC;
        ui->timeText->setText(QString::number(time) + " мкс");
        Hsort->heapSort(arrAnima, list);
        sorted = true;
        break;
    case 3:
        start = clock();
        Isort->interpolationSort(arr);
        end = clock();
        duration = end - start;
        time = duration * 1000000 / CLOCKS_PER_SEC;
        ui->timeText->setText(QString::number(time) + " мкс");
        Isort->interpolationSort(arrAnima, list);
        sorted = true;
        break;
    default:
        break;
    }
}


void MainWindow::on_searchElButton_clicked()
{
    //isElement = true;
    BinarySearch *BS = new BinarySearch(arr, ui->searchElBox->value());
    int result = BS->binarySearch(0, arr.size() - 1);
    if (result == -1) {
        QMessageBox::information(this, "Бинарный поиск", "Элемент отсутствует");
    }
    else {
        QMessageBox::information(this, "Бинарный поиск", "Номер элемента " +
                                                             QString::number(result + 1) + "\n binpow(" + QString::number(arrAnima[result]) + ", " +
                                                             QString::number(result + 1) + ", " + ui->BinPowBox->text() + ") = " +
                                                             QString::number(binpow(arrAnima[result], result + 1, ui->BinPowBox->value())));
}

}



void MainWindow::DisplayArr() {
    scene->clear();
    rectArr.clear();
    double width = 990;
    QRectF *rect;
    for (int i = 0; i < countElements; ++i) {
        rect = new QRectF(30 + i * width / countElements, 10, width / countElements, list[sizeList][i] * 6);
        scene->addRect(*rect, QPen("#FBB117"), QBrush("#FDD017"));
        rectArr.append(rect);
    }
}

long long MainWindow::binpow(long long base, long long pow, long long mod)
{
    if (pow == 0) return 1;
    long long half = binpow(base, pow / 2, mod);
    if (pow % 2 == 0) {
        return (half * half) % mod;
    }
    else {
        return (((half * half) % mod) * (base % mod)) % mod;
    }
}







