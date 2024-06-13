#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openDir();
    void openFile();

private:
    Ui::MainWindow *ui;
    QString _filePath = "";
    long long countSubfolders(QString path);
    long long countFiles(QString path);
};
#endif // MAINWINDOW_H
