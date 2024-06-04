#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QFile>
#include <QFileDialog>
#include <QVector>
#include "MyStruct.h"

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
    QFile File;
    QString NowStr = "";
    int NumbOfCommand;
    watch Watch;

    void MainFunc();

private:
    Ui::MainWindow *ui;

private slots:
    void keyPressEvent(QKeyEvent* event);
    void closeEvent(QCloseEvent *event);



};
#endif // MAINWINDOW_H
