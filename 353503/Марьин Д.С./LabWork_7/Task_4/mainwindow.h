#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtWidgets/qgraphicsscene.h"
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QElapsedTimer>
#include <QRandomGenerator>

#include "hashtable.h"

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
    void LoadFactor(HashTable<int>& HT);
    void CollisionFactor(HashTable<int>& HT,int size);
    void Fill(HashTable<int>& HT, size_t size);
    void SetChart();
    qreal TimeSearch(HashTable<int>& HT, size_t size);
private slots:

    void on_On_LoadFactor_16_clicked();

    void on_On_LoadFactor_64_clicked();

    void on_On_LoadFactor_128_clicked();

    void on_On_LoadFactor_2048_clicked();

private:
    Ui::MainWindow *ui;
    HashTable<int> table_16;
    HashTable<int> table_64;
    HashTable<int> table_128;
    HashTable<int> table_2048;
    QGraphicsScene* scene;
};
#endif // MAINWINDOW_H
