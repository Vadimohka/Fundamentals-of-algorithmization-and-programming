#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QKeyEvent>
#include "binaryheap_massive.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void processKeyPress(QSpinBox *spinBox, QSpinBox *outputBox, binaryheap_massive<int> &heap);
    void processPopButton(QSpinBox *outputBox, QSpinBox *sizeBox, binaryheap_massive<int> &heap);

private slots:
    void on_popButton_clicked();
    void on_popButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    binaryheap_massive<int> heap;
    binaryheap_massive<int> heap2;
};

#endif // MAINWINDOW_H
