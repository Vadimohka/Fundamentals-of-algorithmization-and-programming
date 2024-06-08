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
        int subfolder = subfolders(folderPath);
        int file = files(folderPath);

        QMessageBox::information(this, "Информация", QString("Количество подпапок: %1\nКоличество файлов: %2")
                                                         .arg(subfolder).arg(file));
    }
}

int MainWindow::subfolders(const QString &folderPath)
{
    int count = 0;

    QDirIterator it(folderPath, QDir::Dirs | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        count++;
    }

    return count;
}

int MainWindow::files(const QString &folderPath)
{
    int count = 0;

    QDirIterator it(folderPath, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        count++;
    }

    return count;
}
