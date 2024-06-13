#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QMessageBox>
#include "heaparray.h"

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

    //QStandardItem* createItemForNode(const HeapArray& heap, const QString& position);
    QStandardItem* createItemForNode(const HeapArray& heap, int index, const QString& position);
    void updateHeapView();

private slots:
    void on_insertBtn_clicked();
    void on_extractMaxBtn_clicked();
    void on_getMaxBtn_clicked();
    void on_isEmptyBtn_clicked();

private:
    Ui::MainWindow *ui;
    HeapArray *heap;
};
#endif // MAINWINDOW_H
