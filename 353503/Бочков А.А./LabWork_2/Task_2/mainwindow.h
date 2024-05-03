#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "disk.h"
#include <QFileDialog>
#include <QFile>
#include <QKeyEvent>
#include "form.h"

const int nCol = 5, dec = 10;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_open_clicked();

    void on_add_clicked();

    void on_edit_clicked();

    void on_delete_2_clicked();

    void on_sortName_clicked();

    void on_sortAuthor_clicked();

    void on_findAuthor_clicked();

    void on_findType_clicked();

    void on_findName_clicked();

    void on_showAll_clicked();

private:
    int count;
    bool flag;
    Form form;
    QString *curr = new QString[nCol];
    void writeString(QString str);
    QChar zero = '0';
    bool editable = false, ok = false;
    char *c = new char[0];
    void fileEdit();
    static bool comp1(disk, disk);
    static bool comp2(disk, disk);
    disk currDisk;
    QString path, currname, currtype, currauthor, currprim, str, space = " ", enter = "\n";
    int currcost, n = 0, typeAct, nRow = 0, currCol = -1, currRow = -1;
    QVector<disk> arr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
