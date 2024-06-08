#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "pair.h"
#include "vector.h"
#include <QMainWindow>
#include <QGraphicsScene>
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
    Vector<Pair<int,int>> para;
    QGraphicsScene* scene;
    QString vect;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_erasespin_valueChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_insert_size_textChanged(const QString &arg1);

    void on_insert_size_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
