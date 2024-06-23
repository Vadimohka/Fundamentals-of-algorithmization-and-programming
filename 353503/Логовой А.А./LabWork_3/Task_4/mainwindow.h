#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <magicnumber.h>
#include <QRegularExpressionValidator>
#include <QValidator>
#include <hanoi.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QRegularExpressionValidator* validator;

};
#endif // MAINWINDOW_H
