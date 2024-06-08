#include "mainwindow.h"
#include "./ui_mainwindow.h"
#define TAB_SIZE 5
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

void MainWindow::countFilesAndDirs(const QDir &dir, long long &fileCount, long long &dirCount , int nesting)
{
    qDebug() << _str;
    QFileInfoList list = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::AllDirs);
    for (const QFileInfo& entry : list)
    {
        if (entry.isDir())
        {
            ++dirCount;
            QString tab = QString((nesting + 1) * 2, ' ');
            _str += tab + "-| Dir " + entry.fileName() + "\n";
            QDir subDirrectory(entry.filePath());
            countFilesAndDirs(subDirrectory, fileCount, dirCount , nesting + 1);
            ui->lineEdit_NumFiles->setText(QString::number(fileCount));
            ui->lineEdit_NumDirs->setText(QString::number(dirCount));

        }
        else if (entry.isFile())
        {
            ++fileCount;
            QString tab = QString((nesting + 1) * TAB_SIZE, ' ');
            _str += tab + "-| File " + entry.fileName() + "\n";
            ui->lineEdit_NumFiles->setText(QString::number(fileCount));
            ui->lineEdit_NumDirs->setText(QString::number(dirCount));
        }
         ui->listWidget->addItem(_str);
    }
}

void MainWindow::on_button_ChooseDir_clicked()
{
    _files = 0;
    _dirs = 0;
    QString pathToFile = QFileDialog::getExistingDirectory(this, "Choose directory:", QDir::homePath());
    QDir path(pathToFile);
    if (pathToFile.isEmpty() && path.exists())
    {
        QMessageBox::warning(this, "Error!!!", "No one file selected.");
        return;
    }
    QCoreApplication::processEvents();
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->listWidget->clear();
    countFilesAndDirs(path,_files, _dirs, 0);
    ui->lineEdit_NumFiles->setText(QString::number(_files));
    ui->lineEdit_NumDirs->setText(QString::number(_dirs));
    QApplication::restoreOverrideCursor();
}

