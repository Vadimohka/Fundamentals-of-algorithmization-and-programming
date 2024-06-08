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

private slots:
    void on_openFolder_clicked();

    void on_closeButton_clicked();

private:
    Ui::MainWindow *ui;
    int countFiles = 0;
    int countFolders = 0;
    void printDirectoryTree(const QString &dirPath,
                            int &countFiles,
                            int &countFolders,
                            const QString &indent);
};
#endif // MAINWINDOW_H
