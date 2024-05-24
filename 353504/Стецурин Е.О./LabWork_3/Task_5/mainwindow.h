#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int fileCount;
    int folderCount;
    QFile *file;
    MainWindow();
    ~MainWindow();

protected:
    Ui::MainWindow *ui;
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
