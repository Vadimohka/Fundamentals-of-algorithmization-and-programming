#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QFileDialog>
#include <QFileInfoList>
#include <QMainWindow>
#include <QMessageBox>

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
    QMessageBox msgBox;
    QString path;
    int x = 0, y = 0;
    void countFilesAndDirs(const QString &path, int &fileCount, int &dirCount);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
