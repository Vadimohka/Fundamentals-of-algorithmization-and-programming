#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "BSTui.h"
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
    BSTui tree = BSTui();
    BSTui secTree;
    void insertTreeIntoTree(Node<int, QString>* srcRoot, BSTui& destTree);
private slots:
    void on_insertBut_clicked();
    void on_removeBut_clicked();
    void on_findBut_clicked();
    void on_printInOrderBut_clicked();
    void on_printPostOrderBut_clicked();
    void on_printPreOrderBut_clicked();
    void on_removeSubTreeBut_clicked();
    void on_subTreeLeft_toggled(bool checked);
    void on_subTreeRight_toggled(bool checked);
    void on_balanceBut_clicked();
    void on_clearBut_clicked();
    void on_addSubTreeBut_clicked();
    void on_confirmBut_clicked();
    void on_insertBut_2_clicked();
    void on_removeBut_2_clicked();
protected:
  Ui::MainWindow *ui;
};