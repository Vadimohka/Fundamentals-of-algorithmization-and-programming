#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        QString folder = QFileDialog::getExistingDirectory(nullptr, QObject::tr("Выбор папки"), "/home/yauheni", QFileDialog::ShowDirsOnly);
        if (!folder.isEmpty()){
            ui->folderLabel->setText(QString::number(searchFolders(folder)));
            ui->fileLabel->setText(QString::number(searchFiles(folder)));
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

uint64_t Widget::searchFolders(QString folder){
    uint64_t foldersCount = 0;

    QDir directory(folder);

    QFileInfoList folders = directory.entryInfoList(QDir::Dirs | QDir::NoDot | QDir::NoDotDot);

    foreach(QFileInfo folder, folders)
    {
        foldersCount += (1 + searchFolders(folder.filePath()));
    }

    return foldersCount;
};

uint64_t Widget::searchFiles(QString folder){
    uint64_t filesCount = 0;

    QDir directory(folder);

    QFileInfoList items = directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDot | QDir::NoDotDot);

    foreach(QFileInfo item, items)
    {
        filesCount += (1 + searchFiles(item.filePath()));
    }

    return filesCount;
};
