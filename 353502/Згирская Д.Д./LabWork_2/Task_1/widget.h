#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QDebug>
#include <fstream>
#include "Date.h"
#include "ctime"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
private:
    QString _path = nullptr;
    std::ifstream input;
    std::ofstream output; //write
    Date birthday;
    Date nextBirthday;
    Date previousBirthday;
    bool isBirthdaySet = 0;
    Date currentTime = Date();
    void fromFileToVector();
    void showTable();
    bool checkInput(QString text);
    QVector<Date> _dateVector;
    QVector<QTableWidgetItem*> _tableNowVector;
    QVector<QTableWidgetItem*> _tablePreviousVector;
    QVector<QTableWidgetItem*> _tableNextVector;
    QVector<QTableWidgetItem*> _tableWeekNumberVector;
    QVector<QTableWidgetItem*> _tableDurationVector;
    QVector<QTableWidgetItem*> _tableTillBirthdayVector;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void error();

    void on_open_file_clicked();

    void on_add_to_file_clicked();

    void addToFile(QString added);

    void on_set_birthday_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
