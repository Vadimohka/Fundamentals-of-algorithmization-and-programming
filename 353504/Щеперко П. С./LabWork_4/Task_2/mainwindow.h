#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QTimer>
#include <QElapsedTimer>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include "arrayobj.h"
#include "sort.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    int *arr;
    ArrayObj *array;
    QRandomGenerator *generator;
    QTimer *timer;
    int typeOfSort;
};
#endif // MAINWINDOW_H
