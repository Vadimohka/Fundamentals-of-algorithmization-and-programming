#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "HeapArray/heaparray.h"
#include "HeapList/heaplist.h"

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
void appendToTextEdit(const QString &text);

private slots:
    void on_insertArrayButton_clicked();

    void on_extractMaxArrayButton_clicked();

    void on_extractMaxListButton_clicked();

    void on_getMaxArrayButton_clicked();

    void on_insertListButton_clicked();

    void on_getMaxListButton_clicked();

private:
    Ui::MainWindow *ui;
    HeapArray heapArray;
    HeapList heapList;

};
#endif // MAINWINDOW_H
