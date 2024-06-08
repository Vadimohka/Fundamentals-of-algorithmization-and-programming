#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QTimer>
#include <QInputDialog>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include "plane.h"
#include "QKeyEvent"
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
    void start();
signals:
    void clickedt();

private:
    int n;
    Ui::MainWindow *ui;
    QTimer timer;
    PLANE pl1;
protected:
    void keyPressEvent(QKeyEvent* event) override;
};
#endif // MAINWINDOW_H
