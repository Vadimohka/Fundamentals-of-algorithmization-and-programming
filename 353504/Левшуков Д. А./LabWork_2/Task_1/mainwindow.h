#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dyarray_data.h"
#include "data.h"
#include <QThread>
#include <QTableWidgetItem>
#include <QShortcut>
#include <QFileDialog>
#include <fstream>
#include <iostream>
#include <string>
#include <QMessageBox>
#include <QItemDelegate>

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
    void FileRead();
    void ShowTable();
    void Today();
    void FileUpdate(int ind, std::string s, Date nw);
    void FileAdd(std::string s);
private slots:
    void on_OpenFileButton_clicked();

    void on_DateOfBirthday_textChanged();

    void on_Table_itemChanged(QTableWidgetItem *item);

    void on_Add_textChanged();

private:
    Ui::MainWindow *ui;
    dyarray *data=new dyarray;
    Date birthday;
    Date current;
    QString file="";
    Date t;
    QShortcut *ctrlo;
    bool showing;
    std::string s,file_inside;
    char ch;
};
class NonEditTableColumnDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    NonEditTableColumnDelegate(QObject * parent = 0) : QItemDelegate(parent) {}
    virtual QWidget * createEditor ( QWidget *, const QStyleOptionViewItem &,
                                  const QModelIndex &) const
    {
        return 0;
    }
};
#endif // MAINWINDOW_H
