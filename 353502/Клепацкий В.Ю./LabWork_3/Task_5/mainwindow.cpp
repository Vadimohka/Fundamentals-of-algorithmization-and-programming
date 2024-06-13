#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    QString folder, file;
    QString fileStart = QFileDialog::getExistingDirectory(this,
                                                          "Choose directory",
                                                          QDir::homePath());
    folder = QString::number(folder_count(fileStart));
    file = QString::number(file_count(fileStart));
    ui->textEdit->setPlainText("folder:" + folder + '\n' + "file:" + file + '\n');
}

int MainWindow::folder_count(QString filestart)
{
    int foldercount = 0;
    QDirIterator it(filestart, QDir::Dirs, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        foldercount++;
    }
    return foldercount;
}

int MainWindow::file_count(QString filestart)
{
    int filecount = 0;

    QDirIterator it(filestart, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        filecount++;
    }
    return filecount;
}
