//
// Created by acryoz on 25.05.24.
//

#ifndef LAB7_LIB_BST_MAINWINDOW_H_
#define LAB7_LIB_BST_MAINWINDOW_H_

#include <QGridLayout>
#include <QIntValidator>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "graphview.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   public slots:
    void add();
    void del();

   private:
    QVBoxLayout* vbox;
    QGridLayout* grid;
    QPushButton* add_button;
    QPushButton* del_button;
    QLineEdit* add_edit;
    QLineEdit* del_edit;
    QIntValidator* validator;
    TreeGraph* tree;
    Ui::MainWindow* ui;
};


#endif  //LAB7_LIB_BST_MAINWINDOW_H_
