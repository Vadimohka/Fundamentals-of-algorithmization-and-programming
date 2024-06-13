#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "date.h"

#include <QMainWindow>
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
    void checkFormat(QString input);

    void addDateToTable();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    std::vector<Date> _dates;
    Date *_birthday;
    int _index = 0, _fileSize = 37;
    QMessageBox messageBox;
    bool isCorrect;
    Ui::MainWindow *ui;
    QString _pathToDateFile, _birthdiff;

    bool entered = false;

    std::vector<Date> readFromFile();
    void addDateToFile();
};
#endif // MAINWINDOW_H
