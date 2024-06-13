#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    hashTable = new myHash(5);

}

void MainWindow::on_generateRandom_clicked(){
    hashTable->generateRandomHashTable(ui->spinBox->value());
    QVector<QVector<QPair<int, int>>> vec = hashTable->hashTableToVector();
    QString ans;
    for (int j = 0; j < vec.size(); ++j) {
        ans += QString::number(j) + ": ";
        for (auto& i : vec[j]){
            ans += "key " + QString::number(i.first) + "|" + "value " + QString::number(i.second) + " | | | | | ";
        }
        ans += "\n\n";
    }
    ui->textEdit->setText(ans);
}

void MainWindow::update(){
    QVector<QVector<QPair<int, int>>> vec = hashTable->hashTableToVector();
    QString ans;
    for (int j = 0; j < vec.size(); ++j) {
        ans += QString::number(j) + ": ";
        for (QPair<int, int>& i : vec[j]){
            ans += "key " + QString::number(i.first) + "|" + "value " + QString::number(i.second) + " | | | | | ";
        }
        ans += "\n\n";
    }
    ui->textEdit->setText(ans);
}

void MainWindow::on_insertButton_clicked()
{
    hashTable->insertItem(ui->spinBox_key->value(), ui->spinBox_value->value());
    update();
}

void MainWindow::on_deleteButton_clicked()
{
    try{
        hashTable->deleteItem(ui->spinBox_key->value());
    }
    catch (const char* error) {
        ui->label_6->setText("Stack underflow");
    }
    update();
}

void MainWindow::on_findMin_clicked(){
    int min = hashTable->findStackWithMinKey();
    ui->label_4->setText("stack number: " + QString::number(min));
    update();
}

void MainWindow::on_getByKey_clicked(){
    int value = hashTable->get(ui->spinBox_key->value());
    ui->label_7->setText("value : " + QString::number(value));
    update();
}