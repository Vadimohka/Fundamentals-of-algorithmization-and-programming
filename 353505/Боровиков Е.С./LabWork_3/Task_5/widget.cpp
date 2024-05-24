#include "widget.h".h"
#include <QDir>

FolderBrowser::FolderBrowser(QWidget *parent)
    : QWidget(parent)
{
    selectFolderButton.setText("Выбрать папку");
    layout.addWidget(&selectFolderButton);
    layout.addWidget(&folderTree);
    layout.addWidget(&closeButton);
    setLayout(&layout);

    folderTree.setHeaderLabels(QStringList() << "Содержимое папки");

    connect(&selectFolderButton, &QPushButton::clicked, this, &FolderBrowser::selectFolder);
    connect(&folderTree, &QTreeWidget::itemDoubleClicked, this, &FolderBrowser::itemDoubleClicked);

    closeButton.setText("Закрыть");
    closeButton.setMinimumSize(100, 50);
    connect(&closeButton, &QPushButton::clicked, this, &FolderBrowser::close);
}

FolderBrowser::~FolderBrowser()
{
}

void FolderBrowser::selectFolder()
{
    QString folderPath = QFileDialog::getExistingDirectory(nullptr, "Выберите папку", QDir::homePath());

    if (!folderPath.isEmpty()) {
        folderTree.clear();

        QTreeWidgetItem *rootItem = new QTreeWidgetItem();
        rootItem->setText(0, folderPath);
        folderTree.addTopLevelItem(rootItem);

        int folderCount = 0;
        int fileCount = 0;
        fillFolderTree(folderPath, rootItem, folderCount, fileCount);

        folderTree.setHeaderLabel(QString("Содержимое папки (%1 папок, %2 файлов)").arg(folderCount).arg(fileCount));
    }
}

void FolderBrowser::itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if (item->childCount() > 0 && !item->isExpanded()) {
        item->setExpanded(true);
    }
}

void FolderBrowser::fillFolderTree(const QString &path, QTreeWidgetItem *parentItem, int &folderCount, int &fileCount)
{
    QDir dir(path);
    QFileInfoList list = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);

    foreach (QFileInfo fileInfo, list) {
        QTreeWidgetItem *item = new QTreeWidgetItem(parentItem);
        item->setText(0, fileInfo.fileName());
        if (fileInfo.isDir()) {
            ++folderCount;
            fillFolderTree(fileInfo.absoluteFilePath(), item, folderCount, fileCount);
            item->setExpanded(false);
        } else {
            ++fileCount;
        }
    }
}
