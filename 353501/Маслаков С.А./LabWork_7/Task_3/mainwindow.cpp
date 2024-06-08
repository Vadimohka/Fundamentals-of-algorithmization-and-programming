#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->table->setColumnCount(3);
    QStringList headers = {"Bucket","Key","Value"};
    ui->table->setHorizontalHeaderLabels(headers);
    hashMap.fillTable(ui->table);
}
void MainWindow::on_insertBut_clicked() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 12);
    int num = dis(gen);
    hashMap.insert(rand() % 1000,num);
    ui->table->clear();
    ui->table->setRowCount(0);
    hashMap.printMap(ui->table);
}
void MainWindow::on_removeBut_clicked() {
    int k = ui->removeSpin->value();
    hashMap.remove(k);
    ui->table->clear();
    ui->table->setRowCount(0);
    hashMap.printMap(ui->table);
}
void MainWindow::on_getBut_clicked() {
    int key = ui->getSpin->value();

    try {
        int value = hashMap.get(key);
        ui->getLabel->setText(QString::number(value));
    } catch (const std::out_of_range& e) {
        ui->getLabel->setText("Key not found");
    } catch (const std::exception& e) {
        ui->getLabel->setText("Unexpected error: " + QString::fromStdString(e.what()));
    } catch (...) {
        ui->getLabel->setText("Unknown error");
    }
}
void MainWindow::on_clearBut_clicked() {
    hashMap.clear();
    ui->table->clear();
    ui->table->setRowCount(0);
    hashMap.printMap(ui->table);
}
void MainWindow::on_removeEvenKeysBut_clicked(){
    hashMap.removeAllEvenKeys(hashMap);
    ui->table->clear();
    ui->table->setRowCount(0);
    hashMap.printMap(ui->table);
}