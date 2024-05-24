#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QIntValidator>
#include <QRandomGenerator>
#include <QTreeWidget>
#include <QTimer>


#include "rings.h"

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
    void on_Count_of_rings_line_textChanged(const QString &arg1);

    void on_Solve_button_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;

    QGraphicsRectItem* First_column;
    QGraphicsRectItem* Second_column;
    QGraphicsRectItem* Third_column;

    QIntValidator* val;
    QList <Rings*> list_A;
    QList <Rings*> list_B;
    QList <Rings*> list_C;

    void Rings_add_to_list(int count);
    void Add_columns_to_scene();

    void hanoi(int, QString, QString, QString);
    void hanoi_to_scene(int);
    void hanoi_ring_up(Rings*, qreal, QString);
    void hanoi_ring_right(Rings*, qreal, QString);

};
#endif // MAINWINDOW_H
