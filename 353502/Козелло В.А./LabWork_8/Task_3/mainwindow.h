#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QRegExpValidator>
#include "RBTree.h"
#include "unorderedmap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_insertButton_clicked();

    void on_atButton_clicked();

    void on_removeButton_clicked();

private:
    Ui::MainWindow *ui;
    RBTree<int, char> tree;
    UnorderedMap<int, std::string> umap;
};
#endif // MAINWINDOW_H
