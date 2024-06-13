#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "HashTable.h"
#include <QRandomGenerator>

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
    void on_pushButton_2_clicked();

private:
    void testLinHashMap(LinearHashTable);
    void testQuadHashMap(QuadHashTable);
    void fillMaps();
    void buildGraphics();

    Ui::MainWindow *ui;

    LinearHashTable a1 = LinearHashTable(16), b1 = LinearHashTable(64), c1 = LinearHashTable(128), d1 = LinearHashTable(2048);
    QuadHashTable a2 = QuadHashTable(16), b2 = QuadHashTable(64), c2 = QuadHashTable(128), d2 = QuadHashTable(2048);
};
#endif // MAINWINDOW_H
