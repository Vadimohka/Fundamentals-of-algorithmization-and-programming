#pragma once

#include <QMainWindow>
#include <qdatetime.h>
#include <qgraphicsscene.h>
#include <QFileDialog>
#include <qtablewidget.h>
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
    MainWindow();

private slots:
    void openFile();
    void addToFile(QString date);
    void editFile(QString edit);
    void readFile();
    void populateTable(const QVector<Date> &dates);
    void refreshFile();
    void handleTableRowClicked(QTableWidgetItem* item);
    void setBday(QDate date);

    void addDate();
    void editDate();

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

private:
    int index = -1;
    int column_count = 0;
    QFile file;
    QString fileName;
    QVector<Date> dates;
    Date bday{01, 01, 2000};

    int new_day = 1;
    int new_month = 1;
    int new_year = 2000;

protected:
    Ui::MainWindow *ui;

};