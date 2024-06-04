#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString help_string = nullptr;
    QVector<Date> list_for_dates;
    int month_amount_days[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month_vis_amount_days[13]{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    QString reserve;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_days_birthday_linkActivated(const QString &link);

    void on_days_date_linkActivated(const QString &link);

    void on_choose_file_clicked();

    void on_lineEdit_3_editingFinished();

    void on_input_date_clicked();

private:
    Ui::MainWindow *ui;
    Date helper;
    bool ALLOW = false;

};
#endif // MAINWINDOW_H

