#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , iterImage(pathToImage.begin())
    , iterName(name.begin())
    , iterMusician(musucian.begin())
    , autoTimer(new QTimer(this))
{
    ui->setupUi(this);
    addPathToImage();
    addName();
    addDate();
    connect(autoTimer, &QTimer::timeout, this, &MainWindow::updateAuto);
    on_nextButton_clicked();
    ui->autoButton->setText((QChar)9654);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPathToImage()
{
    pathToImage.push_back("QLabel { image: url(:/new/img/image/All Apologies.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/The Adults.jpeg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Notion.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/In Rainbows.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Everlong.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Ok Computer.jpg);}");
    pathToImage.push_back("QLabel { image: url(:/new/img/image/Currents.jpg);}");
}

void MainWindow::addName()
{
    name.push_back("All Apologies");
    name.push_back("The Adults Are Talking");
    name.push_back("Notion");
    name.push_back("All I Need");
    name.push_back("Everlong");
    name.push_back("No Surprices");
    name.push_back("Let It Happen");
}

void MainWindow::addDate()
{
    musucian.push_back("Nirvana");
    musucian.push_back("The Strokes");
    musucian.push_back("The Rare Ocations");
    musucian.push_back("Radiohead");
    musucian.push_back("Foo Fighters");
    musucian.push_back("Radiohead");
    musucian.push_back("Tame Impala");
}

void MainWindow::on_prevButton_clicked()
{
    iterImage--;
    iterMusician--;
    iterName--;
    ui->imageLabel->setStyleSheet(*iterImage);
    ui->nameLabel->setText(*iterName);
    ui->dateLabel->setText(*iterMusician);
}

void MainWindow::on_nextButton_clicked()
{
    iterImage++;
    iterMusician++;
    iterName++;
    ui->imageLabel->setStyleSheet(*iterImage);
    ui->nameLabel->setText(*iterName);
    ui->dateLabel->setText(*iterMusician);
}

void MainWindow::on_autoButton_clicked()
{
    static bool isPlaying = false;
    if(isPlaying) isPlaying = false;
    else isPlaying = true;
    (isPlaying) ? autoTimer->start(850) : autoTimer->stop();
    (isPlaying) ? ui->autoButton->setText((QChar)0x23F8) : ui->autoButton->setText((QChar)9654);
}

void MainWindow::updateAuto()
{
    iterImage++;
    iterMusician++;
    iterName++;
    ui->imageLabel->setStyleSheet(*iterImage);
    ui->nameLabel->setText(*iterName);
    ui->dateLabel->setText(*iterMusician);
}
