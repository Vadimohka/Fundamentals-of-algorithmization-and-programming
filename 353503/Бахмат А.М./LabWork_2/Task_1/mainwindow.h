#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include "date.h"
#include "QEvent"

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
    void on_openFileButton_clicked();

    void on_pushButtonBirthdayDate_clicked();

    void on_pushButtonAddDate_clicked();

    void on_pushButtonEdit_clicked();



private:
    Ui::MainWindow *ui;
    QVector<Date> dates;
    void readTextFile();
    bool checkDateLine(QString date);
    void addDateToVector(QString date);
    QString _filePath = "";
    QFile _file;
    QDate _currentDate;
    QString _birthdayDate = "01.01.0001";
    bool _isBirthdayShow = false;
    void changeEvent(QEvent * e) override;
    void update();
signals:
};
#endif // MAINWINDOW_H
