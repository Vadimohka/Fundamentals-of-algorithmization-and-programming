#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::open);
}

void MainWindow::countFoldersAndFiles(const QString& path, int& folderCount, int& fileCount)
{
    QDir dir(path);
     if (!dir.exists()) {
        return;
    }

    //Флаг QDir::NoDotAndDotDot указывает на то, что элементы . (текущая директория) и .. (родительская директория) должны быть исключены из результата.
    QFileInfoList entries = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for (const QFileInfo& entry : entries) {
        if (entry.isDir()) {
            folderCount++;
            countFoldersAndFiles(entry.filePath(), folderCount, fileCount);

            
        } else if (entry.isFile()) {
            fileCount++;
        }
    }
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

            ++fileCount;
        }
    }

    QPair<long, long> ret {folderCount, fileCount}; 
    return ret;
}

void MainWindow::open()
{
    QString dir = QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    int folderCount = 0;
    int fileCount = 0;
    countFoldersAndFiles(dir, folderCount, fileCount);

    ui->treeWidget->clear();
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);
    rootItem->setText(0, dir);

    setTree(dir, rootItem);

    ui->foldersLabel->setText(QString::number(folderCount));
    ui->filesLabel->setText(QString::number(fileCount));

}