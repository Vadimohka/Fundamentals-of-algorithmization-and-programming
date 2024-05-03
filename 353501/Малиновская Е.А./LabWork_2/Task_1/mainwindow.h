#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "date.h"
#include "dateeditdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleDateEdited(const Date& editedDate);
    void on_nextDayButton_clicked();
    void on_previousDayButton_clicked();
    void on_leapYearButton_clicked();
    void on_weekNumberButton_clicked();
    void on_durationButton_clicked();
    void on_birthdayButton_clicked();
    void on_openFileButton_clicked();
    void on_addDateButton_clicked();
    void on_saveFileButton_clicked();
    void on_editDateButton_clicked();
    //void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QVector<Date> dates; // Динамический массив объектов класса Date
    QTableWidgetItem *item;
    DateEditDialog *dialog;
    Date *currentDate;
    void displayDates(); // Отображение дат в таблице

};

#endif // MAINWINDOW_H
