#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "RedBlackTree.h"
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleMapInsert();
    void handleMapRemove();
    void handleMapContains();
    void handleMapClear();
    void handleSetInsert();
    void handleSetRemove();
    void handleSetContains();
    void handleSetClear();

private:
    void updateMapDisplay();
    void updateSetDisplay();

    Map<int, int> mapTree;
    Set<int> setTree;

protected:
  Ui::MainWindow *ui;
};