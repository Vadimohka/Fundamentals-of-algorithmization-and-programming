#pragma once
#include "ArrayHeap.h"
#include <QMainWindow>
#include <qgraphicsscene.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
  
public:
    ArrayHeap* heapar;
    MainWindow();

private slots:
    void on_extractMaxBut_clicked();
    void on_insertBut_clicked();
    void on_clearBut_clicked();
protected:
  Ui::MainWindow *ui;
};