#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QSpinBox>
#include "customtextedit.h"
#include "Plant.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    Plant plant;
    CustomTextEdit* textEdit;
private slots:
    void setCount();
    void on_spinBox_valueChanged(int arg1);
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
