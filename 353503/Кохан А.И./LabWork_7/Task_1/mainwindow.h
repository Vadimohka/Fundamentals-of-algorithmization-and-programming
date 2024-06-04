#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "CircleDeque.h"

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

private:
    void addPathToImage();
    void addName();
    void addDate();

private slots:
    void on_prevButton_clicked();

    void on_nextButton_clicked();

    void on_autoButton_clicked();

    void updateAuto();

private:
    Ui::MainWindow *ui;
    CircleDeque<QString> pathToImage;
    CircleDeque<QString> name;
    CircleDeque<QString> date;
    CircleDeque<QString>::iterator iterImage;
    CircleDeque<QString>::iterator iterName;
    CircleDeque<QString>::iterator iterDate;
    QTimer *autoTimer;
};
#endif // MAINWINDOW_H
