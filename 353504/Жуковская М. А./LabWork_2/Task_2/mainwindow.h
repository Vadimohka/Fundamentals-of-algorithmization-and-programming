#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include "student.h"
#include <QTimer>
#include "dialoginputstudent.h"
#include "dialogfindstudent.h"
#include <QMessageBox>

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

private slots:
    void on_exitButton_clicked();

    void on_openButton_clicked();

    void on_saveButton_clicked();

    void on_addButton_clicked();

    void on_editButton_clicked();

    void printStudentsInListWidget();

    void on_deleteButton_clicked();

    void on_findButton_clicked();

    void comboFilterUpdate();

    void on_sortButton_clicked();

private:
    Ui::MainWindow *ui;

    QFile *openedFile;
    QString openedFileName;

    QVector <Student> studentsList;

    QList<QString> GROUPS;
};
#endif // MAINWINDOW_H
