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

void MainWindow::count(const QString& path){
    QDir dir(path);
    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);

    QFileInfoList fileList = dir.entryInfoList();

    foreach(const QFileInfo& fileInfo, fileList){
        if(fileInfo.isDir()){
            ++directories;
            count(fileInfo.filePath());
        }
        else{
            ++files;
        }
    }
}

void MainWindow::on_pushButtonOpenFolder_clicked(){
    path = new QString(QFileDialog::getExistingDirectory(this, "Open directory", QDir::homePath()));

    if(path->isEmpty()){
        QMessageBox::information(this, "Info", "Directory doesn't select");
    }
    else{
        ui->treeWidget->clear();
        directories = 0;
        files = 0;
        count(*path);
        ui->labelFiles->setText(QString::number(files));
        ui->labelFolders->setText(QString::number(directories));
        QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);
        rootItem->setText(0, *path);
        addTree(*path, rootItem);
    }
}

void MainWindow::addTree(const QString &path, QTreeWidgetItem *parentItem){
    QDir dir(path);
    QFileInfoList entries = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

    for(const QFileInfo &entry:entries){
        if (entry.isDir()){
            QTreeWidgetItem *folderNext = new QTreeWidgetItem(parentItem);
            folderNext->setText(0 , entry.fileName());
            addTree(entry.filePath(), folderNext);
        }
        else if (entry.isFile()){
            QTreeWidgetItem *fileItem = new QTreeWidgetItem(parentItem);
            fileItem->setText(0, entry.fileName());
        }
    }
}

