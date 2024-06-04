#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDirIterator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, "Выберите папку", QDir::homePath());

    if (!folderPath.isEmpty()) {
        int subfolderCount = countSubfolders(folderPath);
        int fileCount = countFiles(folderPath);

        QMessageBox::information(this, "Статистика", QString("Количество подпапок: %1\nКоличество файлов: %2")
             .arg(subfolderCount).arg(fileCount));
    }
}

int MainWindow::countSubfolders(const QString &folderPath)
{
    int count = 0;

    QDirIterator it(folderPath, QDir::Dirs | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        count++;
    }

    return count;
}

int MainWindow::countFiles(const QString &folderPath)
{
    int count = 0;

    QDirIterator it(folderPath, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        count++;
    }

    return count;
}
