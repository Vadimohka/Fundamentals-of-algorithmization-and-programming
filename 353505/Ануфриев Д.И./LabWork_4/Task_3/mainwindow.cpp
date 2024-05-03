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

    // connect(ui->spinSearch, &QSpinBox::valueChanged, [this](){
    //     ui->buttonBinSearch->setEnabled(true);
    //     ui->lineIndex->setText("");
    //     array->resetColors();
    //     ui->lineIndex->setStyleSheet("QLineEdit:disabled { background-color: white; }");
    // });

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

    ui->buttonMedian->setEnabled(true);

    int count = ui->spinCountIndexes->value();
    scene->setSceneRect(ui->graphicsView->rect());

    array->clear();


    for(int i = 0; i < count; i++)
    {
        int index = rand() % 250 - 125;
        array->push_back(index, QColor(0, 179, 134, index + 130));
    }
}

void MainWindow::on_buttonMedian_clicked()
{
    ui->buttonMedian->setEnabled(false);

    ui->buttonGenerate->setEnabled(false);
    ui->spinCountIndexes->setEnabled(false);

    array->lookingForMedians();

    QMessageBox::information(this, "Сборка массива завершена", "Массив медиан был построен успешно!");

    ui->buttonGenerate->setEnabled(true);
    ui->spinCountIndexes->setEnabled(true);
    if(array->size() >= 3) ui->buttonMedian->setEnabled(true);
}


void MainWindow::on_buttonClose_clicked()
{
    this->close();
}

