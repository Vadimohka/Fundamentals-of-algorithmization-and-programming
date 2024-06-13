#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include "searchtree.h"

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
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_findLCAButton_clicked();

private:
    Ui::MainWindow *ui;
    SearchTree<int> tree;

    // Кнопки
    QLineEdit *insertLine, *eraseLine, *val1Line, *val2Line;
    QPushButton *insertButton;
    QPushButton *deleteButton;
    QPushButton *findLCAButton;
    QTreeWidget *treeWidget;
};

#endif // MAINWINDOW_H
