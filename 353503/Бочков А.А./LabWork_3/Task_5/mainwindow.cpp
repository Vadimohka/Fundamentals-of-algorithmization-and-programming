#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::countFilesAndDirs(const QString &path, int &fileCount, int &dirCount)
{
    QDir dir(path);
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot
                                           | QDir::Hidden | QDir::NoSymLinks);

    foreach (QFileInfo fileInfo, list) {
        if (fileInfo.isDir()) {
            dirCount++;
            countFilesAndDirs(fileInfo.absoluteFilePath(), fileCount, dirCount);
        } else if (fileInfo.isFile()) {
            fileCount++;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;

    //qDebug() << path << x << y;
}

void MainWindow::on_pushButton_clicked()
{
    path = QFileDialog::getExistingDirectory(nullptr, "Выберете папку", QDir::homePath());
    countFilesAndDirs(path, x, y);
    msgBox.setText("Количество файлов: " + QString::number(x)
                   + "\nКоличество папок: " + QString::number(y));
    x = 0;
    y = 0;
    msgBox.exec();
}
