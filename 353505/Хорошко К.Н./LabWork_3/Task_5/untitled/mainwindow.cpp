#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void calculateCounts(const QDir& directory, unsigned long long & fileCounter, unsigned long long & dirCounter, int& counter) {
    QFileInfoList entryList = directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for (const QFileInfo& entry : entryList) {
        counter++;
        if (entry.isDir()) {
            ++dirCounter;
            QDir subDirectory(entry.filePath());
            calculateCounts(subDirectory, fileCounter, dirCounter, counter);
        } else if (entry.isFile()) {
            ++fileCounter;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    int counter = 0;
    QString dirPath = QFileDialog::getExistingDirectory(this, "Выберите директорию", QDir::homePath());
    QDir directory(dirPath);
    if (directory.exists()){
        unsigned long long directoryCount = 0, fileCount = 0;

        calculateCounts(directory, fileCount, directoryCount, counter);
        ui->label_sf->setText(QString::number(directoryCount) + " Папок");
        ui->label_files->setText(QString::number(fileCount) + " Файлов");
        ui->label_n->setText("n = " + QString::number(counter));
    }
}
