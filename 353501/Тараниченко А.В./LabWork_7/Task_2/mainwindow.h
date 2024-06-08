#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "treechild.h"
#include "treechild.cpp"

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

    void updateTree();

private slots:
    void on_insertButton_clicked();

    void on_removeButton_clicked();

    void on_searchButton_clicked();

    void on_keyInsert_valueChanged(int arg1);

    void on_searchButton_2_clicked();

    void on_searchButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QTreeWidgetItem *beginItem;
    TreeChild<int, QString> tree;
};
#endif // MAINWINDOW_H
