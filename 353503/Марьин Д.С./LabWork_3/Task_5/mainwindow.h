#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QDir>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileInfoList>

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
    ~MainWindow() override;
    void countFilesAndDirs(const QDir&, long long &, long long & , int);
private slots:
    void on_button_ChooseDir_clicked();

private:
    Ui::MainWindow *ui;
    long long _dirs = 0;
    long long _files = 0;
    QString _str;
};
#endif // MAINWINDOW_H
