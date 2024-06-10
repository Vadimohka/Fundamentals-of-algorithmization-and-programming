#ifndef L8_T2_MAINWINDOW_H
#define L8_T2_MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QTreeWidgetItem>
#include "HeapArray.h"
#include "HeapList.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_Button_clicked();
    void on_showMaxValue_Button_clicked();

private:
    Ui::MainWindow *ui;
    HeapArray* heapArray;
    HeapList heapList;

    void updateTreeDisplay();
    void addNodeToTree(QTreeWidgetItem *parent, int index);
};


#endif //L8_T2_MAINWINDOW_H
