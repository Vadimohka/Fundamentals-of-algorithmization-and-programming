#ifndef MAINWIOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QTextStream>
#include <QVector>
#include <QString>
#include <QFile>
#include <QDir>
#include "date.h"
#include "errormessage.h"
#include "nichevo.h"
#include "ura.h"

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

    void on_pushButtonEnterValue_clicked();
    void on_pushButtonNextDay_clicked();
    void on_pushButtonPrevDay_clicked();
    void on_pushButtonBirth_clicked();

    void on_pushButton_clicked();

    void on_pushButtonWriteDown_clicked();

private:

    Ui::MainWindow *ui;
    QString PathS;
    long long Lines = 0;
    QVector < Date > Dates;
    Date birthdayDate;

private:

    bool CheckIfOK( QString line );
    void PutDateToTable();
    void Vsio_Huinja();

};
#endif // MAINWINDOW_H
