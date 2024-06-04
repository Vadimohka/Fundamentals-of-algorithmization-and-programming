#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openDirectoryDialog();

private:
    Ui::MainWindow *ui;

    unsigned long long countFoldersRecursively(const QString& directoryPath);
    unsigned long long countFilesRecursively(const QString& directoryPath);
};

#endif // MAINWINDOW_H

