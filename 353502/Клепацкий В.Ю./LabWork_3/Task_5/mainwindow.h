#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QDirIterator>
#include <QFileDialog>
#include <QFileInfoList>
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
    int folder_count(QString);
    int file_count(QString);
};
#endif // MAINWINDOW_H
