#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainUpdating = new bool;
    *mainUpdating = false;
    serchUpd = new bool;
    *serchUpd = false;

    toolBar->setParent(this);
    toolBar->setGeometry(1200, 0, 300 ,1500);

    sortButton->setParent(toolBar);
    sortButton->setGeometry(0,0,300,30);
    sortButton->setText("Выполнить сортировку");

    searchButton->setParent(toolBar);
    searchButton->setGeometry(0,280,300,30);
    searchButton->setText("Найти элемент");

    quantityTextEdit->setParent(toolBar);
    quantityTextEdit->setText("Введите количество элементов");
    quantityTextEdit->setGeometry(0, 40, 300, 30);

    sizeSpinBox->setParent(toolBar);
    sizeSpinBox->setRange(1,100);
    sizeSpinBox->setGeometry(0, 80, 300, 30);

    sortComboBox->setParent(toolBar);
    sortComboBox->setGeometry(0, 120, 300, 30);
    QStringList sotrComboBoxList = {"QuickSort", "MergeSort", "HeapSort"};
    sortComboBox->addItems(sotrComboBoxList);

    timeLabel->setParent(toolBar);
    timeLabel->setGeometry(0, 160, 300, 30);

    findLabel->setParent(toolBar);
    findLabel->setGeometry(0, 200, 300,30);
    findLabel->setText("выберите элемент для поиска");

    findSpinBox->setParent(toolBar);
    findSpinBox->setRange(1,100);
    findSpinBox->setGeometry(0, 240, 300, 30);

    ansFindLabel->setParent(toolBar);
    ansFindLabel->setGeometry(0, 320, 300,30);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, [&](){
        update();
        sortButton->setEnabled(!*mainUpdating);
        sortButton->setPalette(QPalette((!*mainUpdating)? Qt::white : Qt::gray));
        sizeSpinBox->setEnabled(!*mainUpdating);
        sizeSpinBox->setPalette(QPalette((!*mainUpdating)? Qt::white : Qt::gray));

        if (isSort()){
            searchButton->setEnabled(!*mainUpdating);
            searchButton->setPalette(QPalette((!*mainUpdating)? Qt::white : Qt::gray));
        }
        else{
            searchButton->setEnabled(false);
            searchButton->setPalette(QPalette(Qt::gray));
        }

        if (size != sizeSpinBox->value() && !*mainUpdating){
            size = sizeSpinBox->value();
            createNewArr();
        }


    });
    timer->start(30);

    QPushButton::connect(sortButton, SIGNAL(pressed()), this, SLOT(on_sortButton_clicked()));
    QPushButton::connect(searchButton, SIGNAL(pressed()), this, SLOT(on_searchButton_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::randomNumberGenerate()
{
    QRandomGenerator rand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QVector<int> randomNumbers;
    for (int i = 0; i < sizeSpinBox->value(); ++i) {
        int randomNum = rand.bounded(1, 101);
        while (randomNumbers.contains(randomNum)) {
            randomNum = rand.bounded(1, 101);
        }
        randomNumbers.append(randomNum);
        arr[i] = randomNumbers[i];
    }


}

void MainWindow::showSort()
{
    int* i = new int;
    *i = 0;
    QTimer* thisTimer = new QTimer();
    thisTimer->start();
    thisTimer->setInterval(30);
    *mainUpdating = true;
    QElapsedTimer startTime;
    startTime.start();
    connect(thisTimer, &QTimer::timeout, [=](){
        if (*i < motionVector.size()){
            ind1 = motionVector[*i].first;
            ind2 = motionVector[*i].second;
            QRectF* rect1 = new QRectF(RectsVector[ind2]->x(), 20, 10, RectsVector[ind1]->height());
            QRectF* rect2 = new QRectF(RectsVector[ind1]->x(), 20, 10, RectsVector[ind2]->height());
            RectsVector[ind1] = rect1;
            RectsVector[ind2] = rect2;
            std::swap(RectsVector[ind1], RectsVector[ind2]);
            (*i)++;
        }
        else{
            *mainUpdating = false;
            thisTimer->stop();
            ind1 = ind2 = -1;
            timeLabel->setText("Затраченное время: " + QString::number(startTime.elapsed()));

        }


    });
}

void MainWindow::showSearch()
{
    QTimer *tm = new QTimer(this);
    int* i = new int;
    *i = 0;
    connect(tm, &QTimer::timeout, [=](){
        if (*i < searchVector.size()){
            ind1 = searchVector[*i].first;
            ind2 = searchVector[*i].second;
            *mainUpdating = true;
            MID1 = -1;
            (*i)++;
        }
        else{
            ind1 = -1;
            ind2= -1;
            MID1 = MID2;
            *mainUpdating = false;
            tm->stop();
        }

    });
    tm->start(300);

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);

    // Определение высоты и ширины прямоугольника
    int rect_width = 10;

    // Перемещение столбцов вниз относительно нижней границы окна
    int vertical_offset = height();

    // Отрисовка отсортированных столбцов
    for (int i = 0; i < RectsVector.size(); i++)
    {
        QRectF rect = *RectsVector[i];
        rect.moveBottom(vertical_offset); // Смещение столбца вниз

        if (i == ind1 || i == ind2 || i == MID1)
            paint.setBrush(Qt::green);
        else
            paint.setBrush(Qt::white);

        paint.drawRect(rect);
    }
}

void MainWindow::createNewArr()
{
    *serchUpd = true;
    ansFindLabel->setText("");
    timeLabel->setText("");
    MID2 = -1;
    MID1 = -1;
    ind1 = -1;
    ind2 = -1;
    delete[] arr;
    arr = new int[sizeSpinBox->value()];
    for (int i = 0; i < RectsVector.size(); ++i){
        delete RectsVector[i];
    }
    RectsVector.clear();
    motionVector.clear();
    randomNumberGenerate();
    for (int i = 0; i < sizeSpinBox->value(); ++i){
        // QRectF *rect = new QRectF(30 + 10 * i, 20, 10, 20 + 13 * arr[i]);
        QRectF *rect = new QRectF(30 + 10 * i, height() - (20 + 8 * arr[i]), 10, 20 + 8 * arr[i]);
        RectsVector.append(rect);
    }


}

bool MainWindow::isSort()
{
    for (int i = 1; i < sizeSpinBox->value(); ++i){
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int MainWindow::binsearch(int digit)
{

    searchVector.clear();
    int ind11 = 0;
    int ind22 = sizeSpinBox->value() - 1;
    if (arr[ind11] > digit || arr[ind22] < digit) return -1;
    while (ind11 <= ind22){
        searchVector.append(QPair<int, int>(ind11, ind22));
        int mid = ind11 + (ind22 - ind11) / 2;
        if (arr[mid] == digit){
            ind11 = mid;
            ind22 = mid;
            MID2 = mid;
            return mid;

        }
        if (arr[mid] < digit) ind11 = mid +1;
        else ind22 = mid - 1;
    }


    return -1;
}

void MainWindow::on_sortButton_clicked()
{
    int n = 0;
    if (!isSort()){
        if (sortComboBox->currentText() == "QuickSort"){
            QuickSort::qiuckSort(arr, 0, sizeSpinBox->value() - 1, motionVector, n);
            qDebug() << n;
        }
        else if(sortComboBox->currentText() == "MergeSort"){
            mergeSort::MergeSort(arr, 0, sizeSpinBox->value() - 1, motionVector);
        }
        else{
            HeapSort::heapSort(arr, sizeSpinBox->value(), motionVector);
        }
        showSort();
    }
    else QMessageBox::information(this, "Внимание", "Массив и так отсортирован");
}

void MainWindow::on_searchButton_clicked()
{
    MID1 = -1;
    ansFindLabel->setText(QString::number(binsearch(findSpinBox->value())));
    showSearch();

}
