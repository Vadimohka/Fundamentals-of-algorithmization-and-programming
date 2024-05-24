#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRandomGenerator>

#include "myvector.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void outputVec(MyVec<int> &v);

private slots:

    void on_firstPushBtn_clicked();
    void on_popBackBtn_clicked();
    void on_clearBtn_clicked();
    void on_secondInsertBtn_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MyVec<int> vec;
    QString str;
};
#endif // MAINWINDOW_H
