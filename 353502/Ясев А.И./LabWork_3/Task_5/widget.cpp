#include "widget.h"
#include "ui_widget.h"

#include <QWidget>
#include<QTableWidget>
#include <QFile>
#include <QFileDialog>
#include<QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}


Widget::~Widget()
{
    delete ui;
}

void Widget::countFoldersAndFiles(QString path, qint64 &foldersCount, qint64 &filesCount)
{
    qint64 currentFoldersCount = 0, currentFilesCount = 0;
    QDir dir(path);
    QStringList subdirs = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    QStringList files = dir.entryList(QDir::Files);

    for (const QString& subdir : subdirs) {
        currentFoldersCount++;
        countFoldersAndFiles(path + "/" + subdir, currentFoldersCount, currentFilesCount);
    }

    for (const QString& file : files) {
        currentFilesCount++;
    }
    foldersCount+=currentFoldersCount;
    filesCount += currentFilesCount;
}



void Widget::on_pushButton_clicked()
{
    QString fl = QFileDialog::getExistingDirectory(parentWidget(),"","/home/lq-84i/QTProjects/");
    ui->basic->setText(fl);
    qint64 folders = 0, files = 0;
    countFoldersAndFiles(fl, folders, files);
    QString info = "Folders: ";
    info.append(QString::number(folders)).append(", files: ").append(QString::number(files));
    ui->info->setText(info);
}

