#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    array = new ArrayObj[70]();
    for (int i = 0; i < 70; ++i) {
        array[i].index = i + 1;
    }
    generator = new QRandomGenerator;
    ArrayObj::arr = new int[70];
    for (int i = 0; i < 70; ++i) {
        ArrayObj::arr[i] = generator->bounded(100, 800);
    }
    for (int i = 0; i < 70; ++i) {
        scene->addItem(&array[i]);
    }
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), scene, SLOT(update()));
    timer->start(50);
    ui->pushButton_3->setEnabled(false);

    ui->pushButton_4->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] array;
    array = nullptr;
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    QElapsedTimer timer;
    timer.start();
    Sort::InterpolationSort(ArrayObj::arr, 70);
    for (int i = 0; i < 70; ++i) {
        qDebug() << ArrayObj::arr[i];
    }
    ui->label_3->setText(QString::number(timer.elapsed()));
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}


void MainWindow::on_pushButton_2_clicked()
{
    for (int i = 0; i < 70; ++i) {
        ArrayObj::arr[i] = generator->bounded(100, 800);
    }
    ui->pushButton_3->setEnabled(false);

    ui->pushButton_2->setEnabled(false);

    ui->lineEdit->setText("");
}


void MainWindow::on_pushButton_3_clicked()
{
    int index = Sort::BinarySearch(ArrayObj::arr, 70, ui->lineEdit->text().toShort());
    if (index != -1) {
        ui->label_6->setText(QString::number(index));
        ui->pushButton_4->setEnabled(true);
    } else {
        ui->label_6->setText("Не найден");
        ui->pushButton_4->setEnabled(false);
    }
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    if (arg1 == "")
        ui->pushButton_3->setEnabled(false);
    else
        ui->pushButton_3->setEnabled(true);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->label_8->setText(QString::number(
        Sort::BinPow(ui->label_6->text().toShort(), 70, ui->lineEdit->text().toShort())));
}

