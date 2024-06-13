#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QTimer>
#include "vector.h"

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
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_deleteAllButton_clicked();

    void on_comboBoxActivated();

    void on_comboBox_2Activated();

    void on_addButton_2_clicked();

    void on_deleteButton_2_clicked();

    void on_deleteAllButton_2_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_helpButton_clicked();

    void on_helpButton_2_clicked();

private:
    void keyPressEvent(QKeyEvent *event) override;
    Ui::MainWindow *ui;
    Vector<int> myVector, myVector2;
    QTimer *timer;
};
#endif // MAINWINDOW_H
