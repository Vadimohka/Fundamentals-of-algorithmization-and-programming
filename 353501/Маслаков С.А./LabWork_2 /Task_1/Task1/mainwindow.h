#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFile>
#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include "date.h"
#include <QTableWidgetItem>
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
    QVector<Date> days;

private slots:
    void on_openfilebutton_clicked();

    void on_coundaysbut_clicked();

    void on_pushButton_clicked();

    void on_calendar_clicked(const QDate &date);

    void on_pushButton_2_clicked();

    void on_calendaredit_clicked(const QDate &date);

private:
    int index;
    QDate date;
    int vectorlength = 0;
    void addDate(QString date);
    QString pathToFile;
    QFile file;
    Date * dateline;
    Ui::MainWindow *ui;
    bool checkstr(QString date);
    void FromFiletoarr();
    void EditFile(int index,QString edit);
};
#endif // MAINWINDOW_H
