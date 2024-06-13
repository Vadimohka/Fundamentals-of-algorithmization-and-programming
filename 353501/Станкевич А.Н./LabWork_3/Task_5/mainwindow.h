#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void countFoldersAndFiles(const QString &folderPath, int &folderCount, int &fileCount);
    void displayFoldersAndFiles(const QString &folderPath);
};

#endif // MAINWINDOW_H
