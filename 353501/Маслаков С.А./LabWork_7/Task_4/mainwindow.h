#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "HashMapUi.h"
QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
Q_OBJECT
    HashMapUI hashMap = HashMapUI();

public:
    MainWindow();
    QGraphicsScene* scene;

private slots:
void on_insertBut_clicked();
void on_removeBut_clicked();
void on_getBut_clicked();
void on_clearBut_clicked();
protected:
    Ui::MainWindow *ui;
};
