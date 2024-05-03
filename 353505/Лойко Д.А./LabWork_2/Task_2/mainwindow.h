#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include<QTableWidget>
#include<QMessageBox>
#include<QInputDialog>
#include "components.h"
#include"additemdialog.h"
#include"view_dialog.h"
#include"rangedialog.h"
#include"searchdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addToFile(const QString &fileName,const Components& item);

    void updateInFile(const QString&fileNaem, const QVector<Components>& components);

    void deleteFromFile(const QString &fileName,int itemNum);

    void findGroups(QList<Components>& components, double minPrice, double maxPrice, QList<Components>& currentGroup, int currentIndex, QList<QList<Components>>& groups);

private slots:

    void on_change_clicked();

    void on_open_clicked();

    void on_add_clicked();

    void on_fileCheck_clicked();

    void on_delete_2_clicked();

    void on_search1_clicked();

    void on_search_2_clicked();

    void on_sort_clicked();

private:
    QVector<Components> components;
    Ui::MainWindow *ui;
    QString path = "/home/kostyanych2005/Qt/Labs/Lab 2/Task2";
    QString fileName;
    QTableWidgetItem type;
    QTableWidgetItem firm;
    QTableWidgetItem model;
    QTableWidgetItem parameters;
    QTableWidgetItem price;
    QTableWidgetItem available;

};
#endif // MAINWINDOW_H
