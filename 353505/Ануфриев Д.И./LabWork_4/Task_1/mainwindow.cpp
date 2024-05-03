#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }"
                  "QComboBox:disabled{ color: gray; background-color: lightgray; }"
                  "QSpinBox:disabled{ color: gray; background-color: lightgray; }");

    srand(time(NULL));
    ui->setupUi(this);

    connect(ui->spinSearch, &QSpinBox::valueChanged, [this](){
        ui->buttonBinSearch->setEnabled(true);
        ui->lineIndex->setText("");
        array->resetColors();
        ui->lineIndex->setStyleSheet("QLineEdit:disabled { background-color: white; }");
    });

    scene = new QGraphicsScene(this);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(ui->graphicsView->rect());
    scene->setBackgroundBrush(QColor(230, 255, 247));

    ui->graphicsView->setScene(scene);

    array = new PicturedArray();
    scene->addItem(array);
    array->setScene(scene);

    ui->spinCountIndexes->setRange(2, 500);
    ui->spinCountIndexes->setValue(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonGenerate_clicked()
{
    ui->spinSearch->setValue(0);
    ui->spinSearch->setEnabled(false);

    ui->buttonSort->setEnabled(true);
    ui->comboSorts->setEnabled(true);
    ui->buttonBinSearch->setEnabled(false);

    ui->lineIndex->setText("");
    ui->lineIndex->setStyleSheet("QLineEdit:disabled { background-color: white; }");

    ui->buttonGenerate->setEnabled(false);

    int count = ui->spinCountIndexes->value();
    scene->setSceneRect(ui->graphicsView->rect());

    array->clear();


    if(count > 200)
    {
        QMessageBox::information(this, "Info", "Массив генерируется, подождите, пожалуйста)");
    }

    for(int i = 0; i < count; i++)
    {
        int index = rand() % 250 - 125;
        array->push_back(index, QColor(0, 179, 134, index + 130));
    }

    if(count > 200)
    {
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, &QEventLoop::quit);
        loop.exec();
    }

    ui->buttonGenerate->setEnabled(true);
}

void MainWindow::on_buttonSort_clicked()
{
    long long time = 0;

    ui->buttonSort->setEnabled(false);
    ui->comboSorts->setEnabled(false);

    ui->buttonGenerate->setEnabled(false);
    ui->spinCountIndexes->setEnabled(false);

    if(ui->comboSorts->currentIndex() == 0)
    {
        time = array->timeMergeSort();
        array->mergesort(0, array->size() - 1);
    }
    else if(ui->comboSorts->currentIndex() == 1)
    {
        time = array->timeQuickSort();
        array->QuickSort(0, array->size() - 1);
    }
    else if(ui->comboSorts->currentIndex() == 2)
    {
        time = array->timeHeapSort();
        array->heapSort(array->size());
    }

    QMessageBox::information(this, "Сортировка завершена", "Сортировка прошла успешно!\nВремя сортировки: " + QString::number(time) + " мкс");

    ui->buttonGenerate->setEnabled(true);
    ui->spinCountIndexes->setEnabled(true);

    ui->buttonBinSearch->setEnabled(true);
    ui->spinSearch->setEnabled(true);
}


void MainWindow::on_buttonClose_clicked()
{
    this->close();
}


void MainWindow::on_buttonBinSearch_clicked()
{
    ui->buttonBinSearch->setEnabled(false);

    ui->buttonGenerate->setEnabled(false);
    ui->spinCountIndexes->setEnabled(false);

    int index = array->BinSearch(ui->spinSearch->value());

    if(index != -1)
    {
        ui->lineIndex->setText(QString::number(index));
        ui->lineIndex->setStyleSheet("QLineEdit:disabled { background-color: rgb(32, 223, 32); }");

    }
    else
    {
        ui->lineIndex->setText("Элемента нет!");
        ui->lineIndex->setStyleSheet("QLineEdit:disabled { background-color: rgb(223, 32, 32); }");
    }

    ui->buttonGenerate->setEnabled(true);
    ui->spinCountIndexes->setEnabled(true);

}

