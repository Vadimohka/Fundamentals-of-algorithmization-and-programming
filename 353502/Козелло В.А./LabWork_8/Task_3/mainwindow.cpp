#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    umap.insert(1, "one");
    umap.insert(2, "two");

    QString str;

    if (umap.contains(1)) {
        qDebug() << str.fromStdString(umap.at(1));
    }

    umap.erase(1);

    if (!umap.contains(1)) {
        qDebug() << "1 была удалена";
    }

    QRegExpValidator *validator = new QRegExpValidator(QRegExp("[A-Za-z]"), ui->lineEdit);
    ui->lineEdit->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertButton_clicked()
{
    tree.insert(ui->insertBox->value(), *ui->lineEdit->text().toStdString().c_str());
    tree.buildTreeWidget(ui->treeWidget);
}

void MainWindow::on_atButton_clicked()
{
    char val{};
    try {
        val = tree.getValue(ui->atBox->value());
        ui->atLine->setText(QString(val));
    } catch (...) {
    }
}

void MainWindow::on_removeButton_clicked()
{
    try {
        tree.remove(ui->removeBox->value());
        tree.buildTreeWidget(ui->treeWidget);
    } catch (...) {
    }
}
