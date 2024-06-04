#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <hanoisolver.h>
#include <hanoivisuals.h>

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
    void on_pushButton_clicked();

    void on_tableWidget_itemSelectionChanged();

    void on_spinBox_2_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QVector<QPair<int, int>> list;
    HanoiVisuals *visuals;
};
#endif // MAINWINDOW_H
