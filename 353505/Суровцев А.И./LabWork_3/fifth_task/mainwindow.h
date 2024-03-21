#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFileDialog>
#include <QThread>
#include <QFileSystemModel>
#include "folder_counting.h"
#include "folderonlymodel.h"
#include <QMainWindow>

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
    int cnt_of_dir = 0;
    int cnt_of_files = 0;
    Folder_counting counter;
    FolderOnlyModel *model;
};
#endif // MAINWINDOW_H
