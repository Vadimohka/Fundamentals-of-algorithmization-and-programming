#ifndef FOLDERBROWSER_H
#define FOLDERBROWSER_H

#include <QWidget>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QTreeWidgetItem>

class FolderBrowser : public QWidget
{
    Q_OBJECT

public:
    FolderBrowser(QWidget *parent = nullptr);
    ~FolderBrowser();

private slots:
    void selectFolder();
    void itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    void fillFolderTree(const QString &path, QTreeWidgetItem *parentItem, int &folderCount, int &fileCount);

    QVBoxLayout layout;
    QPushButton selectFolderButton;
    QTreeWidget folderTree;
    QPushButton closeButton;
};

#endif // FOLDERBROWSER_H
