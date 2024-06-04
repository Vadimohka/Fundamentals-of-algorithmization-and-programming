#pragma once

#include "Bitset.h"
#include <QMainWindow>
#include <cstddef>
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
    MainWindow();

private slots:
    void create();
    void reset();
    void all();
    void any();
    void count();
    void flip();
    void test();
    void size();

protected:
    void updateLineEdit();

    Bitset *bitset = nullptr;
    Ui::MainWindow *ui;
};
