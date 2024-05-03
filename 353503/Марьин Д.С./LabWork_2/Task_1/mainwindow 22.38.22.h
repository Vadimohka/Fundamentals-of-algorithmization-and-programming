#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QTableView>
#include <QTableWidget>
#include <QWidget>

#include "date.h"
#include "table.h"

////ctrl + shift + s
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

    void openFile();
    void putDataFromFileToTable();
    void setTodayDate();

private slots:

    void on_btn_select_clicked();
    void on_lineEdit_returnPressed();
    void on_line_addDate_returnPressed();
    void on_line_deleteRow_returnPressed();
    void on_lineToEdit_returnPressed();
    void on_lineEdit_2_returnPressed();

private:

    Ui::MainWindow *ui;
    QVector<Date*>tableDate;
    QFile file;
    Table *table;
    QString birthdaydate;
    QString pathToFile;
    QString EditDate;
    bool WasOpen = false;
    bool WasTableCreated = false;
    QSqlTableModel *model;
};
#endif // MAINWINDOW_H
