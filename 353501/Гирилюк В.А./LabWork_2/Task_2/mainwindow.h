#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QDialog>
#include <QVector>

#include "groupcomplete.h"
#include "product.h"
#include "incompleteintimedialog.h"
#include "searchdialog.h"

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
    void on_actionOpen_file_triggered();

    void on_openDialogGroupComplete_clicked();

    void on_incompleteInTime_clicked();

    void on_searchDutton_clicked();

    void on_sortPushButton_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void closeEvent(QCloseEvent* event);

private:
    Ui::MainWindow *ui;
    QVector<Product> list;

    QFile *File = nullptr;
    QString filePath = "/home/vlad/Qt/projects/2 sem/";
    GroupComplete *groupComplete = nullptr;
    IncompleteInTimeDialog *incomplete = nullptr;
    SearchDialog *search = nullptr;
};
#endif // MAINWINDOW_H
