#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , iterImage(pathToImage.begin())
    , iterName(name.begin())
    , iterDate(date.begin())
    , autoTimer(new QTimer(this))
{
    ui->setupUi(this);
    addPathToImage();
    addName();
    addDate();
    connect(autoTimer, &QTimer::timeout, this, &MainWindow::updateAuto);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPathToImage()
{
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Lenin.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Stalin.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Malenkov.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Hryschev.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Breznev.jpeg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Andropov.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Chernenko.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Gorbachev.jpg);}");
}

void MainWindow::addName()
{
    name.push_back("В.И.Ленин");
    name.push_back("И.В.Сталин");
    name.push_back("Г.М.Маленков");
    name.push_back("Н.С.Хрущёв");
    name.push_back("Л.И.Брежнев");
    name.push_back("Ю.В.Андропов");
    name.push_back("К.У.Черненко");
    name.push_back("М.С.Горбачёв");
}

void MainWindow::addDate()
{
    date.push_back("1917-1924");
    date.push_back("1924-1953");
    date.push_back("1953");
    date.push_back("1953-1964");
    date.push_back("1964-1982");
    date.push_back("1982-1984");
    date.push_back("1984-1985");
    date.push_back("1985-1991");
}

void MainWindow::on_prevButton_clicked()
{
    --iterImage;
    --iterDate;
    --iterName;
    ui->imageLabel->setStyleSheet(*iterImage);
    ui->nameLabel->setText(*iterName);
    ui->dateLabel->setText(*iterDate);
}

void MainWindow::on_nextButton_clicked()
{
    ++iterImage;
    ++iterDate;
    ++iterName;
    ui->imageLabel->setStyleSheet(*iterImage);
    ui->nameLabel->setText(*iterName);
    ui->dateLabel->setText(*iterDate);
}

void MainWindow::on_autoButton_clicked()
{
    (ui->autoButton->isChecked()) ? autoTimer->start(ui->spinBox->value()) : autoTimer->stop();
}

void MainWindow::updateAuto()
{
    ++iterImage;
    ++iterDate;
    ++iterName;
    ui->imageLabel->setStyleSheet(*iterImage);
    ui->nameLabel->setText(*iterName);
    ui->dateLabel->setText(*iterDate);
}
