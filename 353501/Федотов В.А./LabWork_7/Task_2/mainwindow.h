#pragma once

#include "solver.h"

#include <QMainWindow>
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>
#include <qtablewidget.h>
#include <qtreewidget.h>
#include <qwidget.h>

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
    void add();
    void remove();
    void balance();
    void countNumNodesLeftBranch();

    void preorder();
    void inorder();
    void postorder();

    void updateTable(QVector<QPair<int, QString>>);


protected:
    QTreeWidget *treeWidget;
    QTableWidget *table;
    Solver *solver;
    Ui::MainWindow *ui;
};
