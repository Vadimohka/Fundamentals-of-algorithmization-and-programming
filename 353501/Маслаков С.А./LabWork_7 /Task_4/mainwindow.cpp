#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QElapsedTimer>
#include <QGraphicsRectItem>
MainWindow::MainWindow() : ui(new Ui::MainWindow),scene(new QGraphicsScene(this)) {
    ui->setupUi(this);
    ui->table->setColumnCount(3);
    QStringList headers = {"Bucket","Key","Value"};
    ui->table->setHorizontalHeaderLabels(headers);
    hashMap.fillTable(ui->table);
    ui->removelineEdit->setPlaceholderText("Enter key");
    ui->getLineEdit->setPlaceholderText("Enter key");
    ui->table->setColumnWidth(1,250);
    ui->graphicsView->setScene(scene);
}
void MainWindow::on_insertBut_clicked() {
    QString k = hashMap.generateRandomString(8);
    QString v = hashMap.generateRandomString(4);
    hashMap.insert(k,v);
    ui->table->clear();
    ui->table->setRowCount(0);
    hashMap.printMap(ui->table);
}
void MainWindow::on_removeBut_clicked() {
    QString k = ui->removelineEdit->text();
    hashMap.remove(k);
    ui->table->clear();
    ui->table->setRowCount(0);
    hashMap.printMap(ui->table);
}
void MainWindow::on_getBut_clicked() {
    QString k = ui->getLineEdit->text();
    QElapsedTimer timer;
    timer.start();

    try {
        QString value = hashMap.get(k);
        ui->getLineEdit->setText(value);
    } catch (const std::out_of_range& e) {
        ui->getLineEdit->setText("Key not found");
    } catch (const std::exception& e) {
        ui->getLineEdit->setText("Unexpected error: " + QString::fromStdString(e.what()));
    } catch (...) {
        ui->getLineEdit->setText("Unknown error");
    }

    qint64 elapsed = timer.elapsed();

    int barWidth = 10;
    int barHeight = elapsed + 10;
    int xPosition = scene->items().size()*barWidth;
    int yPosition = -barHeight;
    QGraphicsRectItem *bar = new QGraphicsRectItem(xPosition, yPosition, barWidth, barHeight);

    QBrush brush(Qt::blue);
    bar->setBrush(brush);

    scene->addItem(bar);

    QRectF sceneRect = scene->itemsBoundingRect();
    scene->setSceneRect(sceneRect);

    // Сдвиг сцены так, чтобы нижний левый угол был видимым
    ui->graphicsView->fitInView(sceneRect, Qt::KeepAspectRatio);
    ui->graphicsView->centerOn(xPosition, 0);
}
void MainWindow::on_clearBut_clicked() {
    hashMap.clear();
    ui->table->clear();
    ui->table->setRowCount(0);
    hashMap.printMap(ui->table);
}

