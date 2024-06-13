#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "rbtree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTreeWidget *treeWidget;
    QPushButton *insert, *erase;
    QLineEdit *insertKey, *insertVal, *eraseKey;
    QLabel *keyI, *keyE, *val;

    void treeInsert();
    void treeErase();

    RBTree tree;
};
#endif // MAINWINDOW_H
