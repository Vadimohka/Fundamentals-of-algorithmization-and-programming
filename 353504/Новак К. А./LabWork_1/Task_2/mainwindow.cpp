#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
    ui->graphicsView->setScene(scene);
    /*ellips *item = new ellips(QPointF(0,0));
    scene->addItem(item);
    item->setFinalPoint(QPointF(100,100));*/
    ui->comboBox->addItems({"эллипс","прямоугольник","равнобедренный треугольник","прямоугольный треугольник","ромб",
                            "шестиугольник","пятиконечная звезда","шестиконечная звезда","восьмиконечная звезда"});
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Info = new QTimer(this);
    connect(Info, SIGNAL(timeout()), this, SLOT(Info_slot()));
    Info->start(100);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimer()));
    timer->start(100);
    ui->radioButton->animateClick();
}

void MainWindow::Info_slot() {
    ui->label->setText("Center: ("+QString::number(scene->getCenter().x())+","+QString::number(scene->getCenter().y())+")");
    ui->label_2->setText("Square: "+QString::number(scene->getSquare()));
    ui->label_3->setText("Perimetr: "+QString::number(scene->getPerim()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_comboBox_activated(int index)
{
    scene->setTypeFigure(index);
    on_radioButton_clicked(true);
    ui->radioButton->animateClick();
}


void MainWindow::on_radioButton_clicked(bool checked)
{
    if (checked) {
        scene->setTypeAct(0);
    }
}


void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if (checked) {
        scene->setTypeAct(1);
    }
}


void MainWindow::on_radioButton_3_clicked(bool checked)
{
    if (checked) {
        scene->setTypeAct(3);
    }
}


void MainWindow::on_radioButton_4_clicked(bool checked)
{
    if (checked) {
        scene->setTypeAct(4);
    }
}


void MainWindow::on_radioButton_5_clicked(bool checked)
{
    if (checked) {
        scene->setTypeAct(2);
    }
}

