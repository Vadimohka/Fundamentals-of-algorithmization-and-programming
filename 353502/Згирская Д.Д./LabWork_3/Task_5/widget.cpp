#include "widget.h"
#include "./ui_widget.h"
#include "NumberOfFiles.h"

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


void Widget::on_selectDirectory_clicked() {
    _path = QFileDialog::getExistingDirectory(nullptr, "Open Files", "../Files", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QDir dir;
    dir.setPath(_path);
    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot );
    qDebug() << dir.count();
}


void Widget::on_getResult_clicked() {
    if (_path != nullptr) {
        int numberOfDirectories = NumberOfFiles::calculateNumberOfFiles(_path).numberOfDirectories;
        int numberOfFiles = NumberOfFiles::calculateNumberOfFiles(_path).numberOfFiles;
        ui->numberOfDirectories_show->setText("Dirs: " + QString::number(numberOfDirectories));
        ui->numberOfFiles_show->setText("Files: " + QString::number(numberOfFiles));
    }
    else {
        ui->numberOfDirectories_show->setText("Directory not selected!");
        ui->numberOfFiles_show->setText("Directory not selected!");
    }
}

