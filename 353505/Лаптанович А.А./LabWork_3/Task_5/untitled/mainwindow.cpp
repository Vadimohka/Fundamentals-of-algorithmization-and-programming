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

void count(const QDir& dir, unsigned long long & fileCount, unsigned long long & dirCount, int& n) {
    QFileInfoList entries = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for (const QFileInfo& entry : entries) {
        n++;
        if (entry.isDir()) {
            ++dirCount;
            QDir subDir(entry.filePath());
            count(subDir, fileCount, dirCount, n);
        } else if (entry.isFile()) {
            ++fileCount;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    n = 0;
    QString directoryPath = QFileDialog::getExistingDirectory(nullptr, "Выберите директорию", QDir::homePath());
    QDir path(directoryPath);
    if (path.exists()){
        unsigned long long d = 0, f = 0;

        count(path, f, d, n);
        ui->label_sf->setText(QString::number(d) + " Папок");
        ui->label_files->setText(QString::number(f) + " Файлов");
        ui->label_n->setText("n = " + QString::number(n));
    }

}

