#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QFileDialog"
#include "QVector"
#include "date.h"
#include "QDate"
#include "form.h"

const int nCol = 6;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    QChar zero = '0';
    char *c = new char[0];
    QString path, str;
    int n=0, currRow, typeAct = 0;
    Date birthday;
    QString Today = QDate::currentDate().toString("dd.MM.yyyy");
    Date today = Date(Today), currDate;
    QVector<Date> arr;
    Ui::MainWindow *ui;
    Form form;
};
#endif // MAINWINDOW_H
