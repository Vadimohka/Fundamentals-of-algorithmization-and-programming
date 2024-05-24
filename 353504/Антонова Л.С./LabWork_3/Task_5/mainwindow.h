#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileSystemModel>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void Count(QString path, long &directoriesAmount, long long &filesAmount);

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    QFileSystemModel *model;
    QString filePath;
    long direct;
    long long files;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
