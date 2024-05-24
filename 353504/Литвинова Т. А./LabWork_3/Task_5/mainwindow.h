#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "folder.h"
#include <QThread>
#include <QFileSystemModel>
#include <QStyledItemDelegate>


/*QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
*/


class FolderOnlyModel : public QFileSystemModel
{
public:
    FolderOnlyModel(QObject *parent = nullptr) : QFileSystemModel(parent) {}
    QVariant data(const QModelIndex &index, int role) const override
    {
        if (role == Qt::DisplayRole) {

            if(index.column() != 0) return "   ";
            QString path = QDir::toNativeSeparators(filePath(index));
            QFileInfo fileInfo(path);
            return fileInfo.fileName();
        }
        return QVariant();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const {
        return 1;
    }
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Folder counter;
    QString selectedDirectory;
    long long files, dirs;
    FolderOnlyModel* model;
};
#endif // MAINWINDOW_H
