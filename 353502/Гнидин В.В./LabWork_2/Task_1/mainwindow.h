//
// Created by volodya-petarda on 4/3/24.
//

#ifndef LAB2_1_MAINWINDOW_H
#define LAB2_1_MAINWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QTableView>
#include <QFile>
#include <QTextStream>
#include "Date.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;
    void readFile(QString path);
    void showDates();
private:
    QString path;
    Date birthday = Date(23, 8, 2005);
    std::vector<Date> dates;
    Ui::mainwindow *ui;
private slots:
    void openFile();
    void setBirthday();
    void setNewDate();
    void addDate();
};


#endif //LAB2_1_MAINWINDOW_H
