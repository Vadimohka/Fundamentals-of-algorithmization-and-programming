#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->keyEdit, &QLineEdit::textChanged, this, [&](){
        currentKey = ui->keyEdit->text().toInt(&correctKey);
    });
    QObject::connect(ui->dataEdit, &QLineEdit::textChanged, this, [&](){
        currentData = ui->dataEdit->text();
        correctData = (currentData.size() != 0);
    });
    //QObject::connect(ui->randomButton, &QPushButton::clicked, this, &MainWindow::fillTableRandom);
    QObject::connect(ui->sizeEdit, &QLineEdit::textChanged, this, [&](){
        size = ui->sizeEdit->text().toInt(&correctSize);
        //if (!ok) return;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillHashtable()
{
    hashTable = new HashTable<QString>(size);
    for (int i = 0; i < 5 * size; i++){
        hashTable->insert(rand() % (10 * size), "val" + QString::number(i));
    }
}

void MainWindow::fillTableRandom(bool random)
{
    if (random){
    if (!correctSize) return;

    fillHashtable();
    }
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setColumnCount(20);


    for (int i = 0; i < size; i++){
        HashTable<QString>::Entry *entr = hashTable->entries[i];
        if (entr == nullptr)
            continue;

        //int firstRow = ui->tableWidget->rowCount();
        int spannedRows = 1;
        int colomn = 1;
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        while (entr != nullptr) {

            ui->tableWidget->setItem(row, colomn, new QTableWidgetItem(QString::number(entr->key)));
            ui->tableWidget->setItem(row, colomn + 1, new QTableWidgetItem(entr->val));
            entr = entr->next;
            spannedRows++;
            colomn += 2;

        }

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(hashTable->hash(hashTable->entries[i]->key))));
        //if (spannedRows > 1)
            //ui->tableWidget->setSpan(firstRow, 0, spannedRows, 1);
    }

}

void MainWindow::on_insertButton_clicked()
{
    if (!correctKey || !correctData) return;

    hashTable->insert(currentKey, currentData);
    fillTableRandom(false);
}


void MainWindow::on_randomButton_clicked()
{
    fillTableRandom(true);
}


void MainWindow::on_eraseButton_clicked()
{
    if (!correctKey) return;

    hashTable->remove(currentKey);
    fillTableRandom(false);
}

