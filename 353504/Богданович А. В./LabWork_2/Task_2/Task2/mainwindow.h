#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>

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

private slots:
    void addError(QString);
    void clearForm();
    void clearEditForm();
    void activateEditBtns();
    void deactivateEditBtns();
    bool isGroupExist(QString);
    bool isGroupCorrect(QString);

    void on_AddButton_clicked();

    void on_studentSelect_comboBox_currentIndexChanged(int index);

    void on_edit_button_clicked();

    void on_delete_button_clicked();

    void on_saveFile_button_clicked();

    void on_openFile_button_clicked();

    void on_selectGroup_comboBox_currentIndexChanged(int index);

    void on_sort_button_clicked();

    void on__createVed_button_clicked();

    void on_find_button_clicked();

private:
    Ui::MainWindow *ui;
    Student* students = new Student[100];
    Student* filtered = new Student[100];
    QString* groups = new QString[50];
    int groupsCount = 0;
    int curInd = 0;
    int studentsCount = 0;
    int filteredCount = 0;

};
#endif // MAINWINDOW_H
