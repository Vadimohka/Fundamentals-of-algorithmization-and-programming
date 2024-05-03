#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <qcontainerfwd.h>
#include <qfont.h>
#include <qpushbutton.h>
#include <qtreewidget.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //Шрифт для файлов
    fileFont.setItalic(true);

    connect(ui->openFileButton, &QPushButton::pressed, this, &MainWindow::openFolder);
    ui->treeWidget->setColumnWidth(0, 400);
}

void MainWindow::openFolder() {
    QString rootFolderPath = QFileDialog::getExistingDirectory(
        nullptr, "Open Folder", QDir::homePath());

    if (rootFolderPath.isEmpty()) {
      return;
    }

    ui->treeWidget->clear();
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);
    rootItem->setText(0, rootFolderPath);

    setTree(rootFolderPath, rootItem);
}

QPair<long, long> MainWindow::setTree(const QString &folderPath, QTreeWidgetItem *parentItem) {
    QDir folder(folderPath);
    QFileInfoList entries = folder.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Files);

    int folderCount = 0;
    int fileCount = 0; 

    for (const QFileInfo &entry : entries) {
        if (entry.isDir()) {
            QTreeWidgetItem *subfolderItem = new QTreeWidgetItem(parentItem);
            subfolderItem->setText(0, entry.fileName());

            QPair<long, long> childCount = setTree(entry.filePath(), subfolderItem);
            folderCount += (1 + childCount.first);
            fileCount += childCount.second;
            parentItem->setText(2, QString::number(fileCount));

        } else if (entry.isFile()) {
            QTreeWidgetItem *fileItem = new QTreeWidgetItem(parentItem);
            fileItem->setText(0, entry.fileName());
            fileItem->setFont(0, fileFont);

            ++fileCount;
        }
    }

    parentItem->setText(1, QString::number(folderCount));
    parentItem->setText(2, QString::number(fileCount));

    QPair<long, long> ret {folderCount, fileCount}; 
    return ret;
}
