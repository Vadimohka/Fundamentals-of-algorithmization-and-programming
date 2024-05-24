#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    static long CountElements(const QString& path);

private slots:
    void on_OpenButton_clicked();

private:
    Ui::MainWindow *ui;
    void countFoldersAndFiles(const QString& path, int& folderCount, int& fileCount);

};
#endif // MAINWINDOW_H
