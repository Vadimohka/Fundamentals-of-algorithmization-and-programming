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
    void removeSubtree();
    void insertSecond();

    void preorder();
    void inorder();
    void postorder();

    void setMain();
    void setSecond();

    void findLowestCommon();

    void updateTable(QVector<QPair<int, QString>>);
    void handleTreeClicked(QTreeWidgetItem *item, int column);

    void generateRandomNode();


protected:
    QTreeWidget *currentTreeWidget;
    QTableWidget *table;
    Solver *mainTree;
    Solver *secondTree;
    Solver *currentTree;

    Ui::MainWindow *ui;
};
