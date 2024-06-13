#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "avltree.h"

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

    QStandardItem* createItemForNode(std::shared_ptr<Node> root, const QString& position = "");
    void printDirect(std::shared_ptr<Node> node);
    void printReverse(std::shared_ptr<Node> node);
    void printIncreaseKey(std::shared_ptr<Node> node);

private slots:
    void on_addBtn_clicked();
    void on_deleteBtn_clicked();
    void on_findBtn_clicked();
    void on_directBtn_clicked();
    void on_reverseBtn_clicked();
    void on_IncreaseKeyBtn_clicked();
    void on_countLeftNodesBtn_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Node> root_;
    QStandardItemModel* model;
};
#endif // MAINWINDOW_H
