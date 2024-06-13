#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <TaskTree.h>

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
    ~MainWindow() override;

private slots:
    void on_add_clicked();
    void on_erase_clicked();
    void on_find_clicked();

private:
    Ui::MainWindow *ui;
    TaskTree<QString> _tree;

    void rebuildTree();
    void addTreeNodes(QTreeWidgetItem *parentItem, TaskTree<QString>::Node *node);
};
#endif // MAINWINDOW_H
