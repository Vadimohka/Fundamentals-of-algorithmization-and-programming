#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list.h>
#include <findstudent.h>
#include <groupsort.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString name_find = nullptr;;
    QString surname_find = nullptr;
    QString dadsname_find = nullptr;
    QString groupname = nullptr;

private slots:
    void on_addStudent_clicked();

    void on_chooseFile_clicked();

    void on_comboBox_activated(const QString &arg1);

    void openFinder();

    void openGroup();

    void on_listStudents_clicked();

    void on_sort_clicked();

private:
    bool ALLOW = false;
    Ui::MainWindow *ui;
    QVector <List> list_for_students;
    QString reserv;
};

#endif // MAINWINDOW_H

