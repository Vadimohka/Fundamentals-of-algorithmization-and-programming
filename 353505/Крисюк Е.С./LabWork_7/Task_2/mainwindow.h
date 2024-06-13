#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>

#include "binarytree.h"
#include "add_new_element_window.h"
#include "delete_element_window.h"


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

    void Add_element_to_window(QString &, int &);
    void Delete_element_from_window(int);;
    void on_Add_button_clicked();

    void on_Balance_button_clicked();

    void on_Delete_button_clicked();

    void on_Get_right_nodes_cout_clicked();

private:
    Ui::MainWindow *ui;
    Add_new_element_window* add_new_element_window;
    Delete_element_window* delete_element_window;

    BinaryTree* tree;
    QStandardItemModel* standart_model;


    QList<Node*> node_list;

    void Update_treeview();
    void Update(QStandardItem* parent, Node* node, QString);

};
#endif // MAINWINDOW_H
