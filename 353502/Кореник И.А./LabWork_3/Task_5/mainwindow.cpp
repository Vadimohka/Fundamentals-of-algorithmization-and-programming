#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>


MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    fileFont.setItalic(true);
    ui->treeWidget->setColumnWidth(0, 400);
}



QPair<long, long> MainWindow::setTree(const QString &folderPath, QTreeWidgetItem *parentItem) {
    QDir folder(folderPath);
    QFileInfoList entries = folder.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);


    int folderCount = 0;
    int fileCount = 0;
    QPair<long, long> ret;
    for (const QFileInfo &entry : entries) {
        if (entry.fileName() == "."){
            ret = {1, 0};
            continue;
        }
        else{

        if (entry.isDir()) {


            QTreeWidgetItem *subfolderItem = new QTreeWidgetItem(parentItem);
            subfolderItem->setText(0, entry.fileName());

            QPair<long, long> childCount = setTree(entry.filePath(), subfolderItem);
            folderCount += (1 + childCount.first);
            fileCount += childCount.second;
            parentItem->setText(2, QString::number(fileCount));
            }


         else if (entry.isFile()) {
            QTreeWidgetItem *fileItem = new QTreeWidgetItem(parentItem);
            fileItem->setText(0, entry.fileName());
            fileItem->setFont(0, fileFont);

            ++fileCount;


    }
        }
    parentItem->setText(1, QString::number(folderCount));
    parentItem->setText(2, QString::number(fileCount));

    ret  ={folderCount, fileCount};



    }
    return ret;

}

void MainWindow::on_openFileButton_clicked()
{
    QFileDialog dialog;
    dialog.setOption(QFileDialog::DontUseNativeDialog, false);  // Use non-native dialog for consistency
    dialog.setFileMode(QFileDialog::AnyFile);  // Adjust based on whether you need files, directories, or both
    dialog.setDirectory(QDir::currentPath());  // Starting directory, adjust as needed

    // Setting the filter
    dialog.setFilter(QDir::Hidden);

    //QString rootFolderPath = fileDialog->getExistingDirectory(
      // nullptr, "Open Folder", QDir::homePath());
    QString rootFolderPath;

        rootFolderPath = dialog.getExistingDirectory( nullptr, "Open Folder", QDir::homePath());
        if (rootFolderPath.isEmpty()) {
            return;
        }



    ui->treeWidget->clear();
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);
    rootItem->setText(0, rootFolderPath);

    setTree(rootFolderPath, rootItem);
}

