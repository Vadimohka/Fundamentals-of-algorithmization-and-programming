#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QRegularExpression>
#include <QDebug>
#include "student.h"

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
    QString path;
    QFile file;
    QString s = "fa";
    QVector<Student> students;

private slots:
    void on_open_clicked();
    void on_DebtorsList_clicked();
    void on_DismissList_clicked();
    void on_StudentsList_clicked();
    void on_sort_clicked();
    void on_stud_activated(int index);

    void on_add_clicked();

private:
    Ui::MainWindow *ui;
    QString newStudent;
};
#endif // MAINWINDOW_H
