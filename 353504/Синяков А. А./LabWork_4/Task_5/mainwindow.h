#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dvector.h"
#include "mypair.h"

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


    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Dvector<MyPair<Dvector<int>, Dvector<MyPair<int, double>>>> vecOfPairs;
Dvector<int> vec;
    void displayMatrices();
    void createMatrices();
    void create_emplace();
      void createassign();
      void createback();
      void create_emplace_back();
      void createdata();
      void createfront();
      void  createinsert();
    void  createclear();
   void Сheckingmethods();

};

#endif // MAINWINDOW_H
