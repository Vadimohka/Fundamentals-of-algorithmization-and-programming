#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QElapsedTimer>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    on_pushButton_2_clicked();
}

void MainWindow::display(){
    ui->label_16->clear();
    ui->label_64->clear();
    ui->label_128->clear();
    ui->label_2048->clear();
    auto vec16 = table16->toVec();
    QString ans16;
    for (int i = 0; i < vec16.size(); ++i) {
        ans16 += QString::number(i) + ": ";
        ans16 += QString::number(vec16[i].first) + "," + QString::number(vec16[i].second) + "\n\n";
    }
    ui->textEdit_16->setText(ans16);

    auto vec64 = table64->toVec();
    QString ans64;
    for (int i = 0; i < vec64.size(); ++i) {
        ans64 += QString::number(i) + ": ";
        ans64 += QString::number(vec64[i].first) + "," + QString::number(vec64[i].second) + "\n\n";
    }
    ui->textEdit_64->setText(ans64);

    auto vec128 = table128->toVec();
    QString ans128;
    for (int i = 0; i < vec128.size(); ++i) {
        ans128 += QString::number(i) + ": ";
        ans128 += QString::number(vec128[i].first) + "," + QString::number(vec128[i].second) + "\n\n";
    }
    ui->textEdit_128->setText(ans128);

    auto vec2048 = table2048->toVec();
    QString ans2048;
    for (int i = 0; i < vec2048.size(); ++i) {
        ans2048 += QString::number(i) + ": ";
        ans2048 += QString::number(vec2048[i].first) + "," + QString::number(vec2048[i].second) + "\n\n";
    }
    ui->textEdit_2048->setText(ans2048);

}

void MainWindow::on_pushButton_clicked()
{
    ui->label_16->clear();
    ui->label_64->clear();
    ui->label_128->clear();
    ui->label_2048->clear();


    QElapsedTimer timer;
    timer.start();
    int result16 = table16->search(ui->spinBox->value());
    qint64 elapsed16 = timer.nsecsElapsed() / 50;
    ui->label_16->setText("res: " + QString::number(result16) + " time: " + QString::number(timer.nsecsElapsed()) + " ns");

    timer.start();
    int result64 = table64->search(ui->spinBox->value());
    qint64 elapsed64 = timer.nsecsElapsed() / 50;
    ui->label_64->setText("res: " + QString::number(result64) + " time: " + QString::number(timer.nsecsElapsed()) + " ns");

    timer.start();
    int result128 = table128->search(ui->spinBox->value());
    qint64 elapsed128 = timer.nsecsElapsed() / 50;
    ui->label_128->setText("res: " + QString::number(result128) + " time: " + QString::number(timer.nsecsElapsed()) + " ns");

    timer.start();
    int result2048 = table2048->search(ui->spinBox->value());
    qint64 elapsed2048 = timer.nsecsElapsed() / 50;
    ui->label_2048->setText("res: " + QString::number(result2048) + " time: " + QString::number(timer.nsecsElapsed()) + " ns");
    
    QGraphicsView *view = ui->graphicsView;
    QGraphicsScene *scene = new QGraphicsScene(this);
    view->setScene(scene);
    QGraphicsRectItem *bar1 = new QGraphicsRectItem(0, -(elapsed16), 50, elapsed16);
    bar1->setBrush(QBrush(Qt::red));
    QGraphicsRectItem *bar2 = new QGraphicsRectItem(55, -(elapsed64), 50, elapsed64);
    bar2->setBrush(QBrush(Qt::red));
    QGraphicsRectItem *bar3 = new QGraphicsRectItem(110, -(elapsed128), 50, elapsed128);
    bar3->setBrush(QBrush(Qt::red));
    QGraphicsRectItem *bar4 = new QGraphicsRectItem(165, -(elapsed2048), 50, elapsed2048);
    bar4->setBrush(QBrush(Qt::red));
    scene->addItem(bar1);
    scene->addItem(bar2);
    scene->addItem(bar3);
    scene->addItem(bar4);

    
}

void MainWindow::on_deleteButton_clicked(){
    table16->deleteItem(ui->spinBox->value());

    table64->deleteItem(ui->spinBox->value());

    table128->deleteItem(ui->spinBox->value());

    table2048->deleteItem(ui->spinBox->value());
    display();
}

void MainWindow::on_insertButton_clicked(){
    if(!table16->insertItem(ui->spinBox->value(), ui->spinBox_2->value())){
        table16->insertItem(ui->spinBox->value(), ui->spinBox_2->value());
    };

    if(!table64->insertItem(ui->spinBox->value(), ui->spinBox_2->value())){
        table64->insertItem(ui->spinBox->value(), ui->spinBox_2->value());
    }

    if(!table128->insertItem(ui->spinBox->value(), ui->spinBox_2->value())){
        table128->insertItem(ui->spinBox->value(), ui->spinBox_2->value());
    }

    if(!table2048->insertItem(ui->spinBox->value(), ui->spinBox_2->value())){
        table2048->insertItem(ui->spinBox->value(), ui->spinBox_2->value());
    }
    display();
}

void MainWindow::on_pushButton_2_clicked()
{
    table16 = new HashTable(16);
    table64 = new HashTable(64);
    table128 = new HashTable(128);
    table2048 = new HashTable(2048);
    for (int i = 0; i < 16; ++i) {
        if(!table16->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100))){
            table16->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
        }
    }

    for (int i = 0; i < 64; ++i) {
        if(!table64->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100))){
            table64->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
        }
    }

    for (int i = 0; i < 128; ++i) {
        if(!table128->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100))){
            table128->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
        };
    }

    for (int i = 0; i < 2048; ++i) {
        if(!table2048->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100))){
            table2048->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
        }
    }

    display();

}
