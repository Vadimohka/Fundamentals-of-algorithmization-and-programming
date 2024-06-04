#pragma once

#include "RectArray.h"
#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    void updateScene();

protected:
    Ui::MainWindow* ui;
    RectArray* array;
    QGraphicsScene* scene;
    QTimer* timer;
    int sortType;
    int numberToSearch;
    int cnt;
    int number;
    bool sortAllowed = true;
    bool isSearching = true;
    long long mod;

    long long securePower(int base, int exponent, int modulus);

private slots:
    void on_spinBox_valueChanged(int newValue);
    void on_spinBox_2_valueChanged(int newValue);
    void on_spinBox_3_valueChanged(int newValue);
    void on_refresh_clicked();
    void on_sort_clicked();
    void on_search_clicked();
    void on_comboBox_currentIndexChanged(int newIndex);
};
