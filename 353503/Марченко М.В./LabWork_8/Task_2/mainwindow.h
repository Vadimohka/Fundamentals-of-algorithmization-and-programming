#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <heaparray.h>
#include <heaplist.h>

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
public slots:
    void addElement();
    void removeElement();
    void heapifyArray();
    void getTop();
    void isEmptyHeap();
    void clearHeap();
private:
    HeapArray<int> m_heap;
     //HeapList<int> m_heap;
    void updateTreeWidget();
    void updateTreeWidgetRecursive(QTreeWidgetItem* parent, int index, const HeapArray<int>& heap);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
