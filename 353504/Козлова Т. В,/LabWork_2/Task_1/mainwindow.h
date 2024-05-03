#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
#include <ctime>
#include <vector>
#include <QMessageBox>
#include <QFileDialog>

#include "date.h"

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

protected:
    Date* getCurrentDate();
    void getDatesFromFile();
    void fillTable();
    void clearTable();
    void setDaysTillBirthday(Date birthdayDate);
    void addDateInTable();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Date* m_currentDate;
    std::vector<Date> m_datesFromFile;
    Ui::MainWindow *ui;
    std::string m_filePath;
};
#endif // MAINWINDOW_H
