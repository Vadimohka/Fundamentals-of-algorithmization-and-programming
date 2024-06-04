//
// Created by darina on 3/31/24.
//

#ifndef TASK1_MAINWINDOW_H
#define TASK1_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <qgraphicsscene.h>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

#include "../Date/Date.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class mainwindow;
}
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    mainwindow();

private:
    QVector<Date> date;
    QAbstractItemModel *model;
    QVector<Date> birthdayDay;
    int raw = -1;
    QFile file;
    bool open = false;
    void ShowTable();
    QString fileRem;

protected:
    Ui::mainwindow *ui;
    QGraphicsScene *scene;

public slots:
    void onPrevious_clicked();
    void isLeap_clicked();
    void weekNumber_clicked();
    void whenBirthday_clicked();
    void duration_clicked();
    void addData_clicked();
    void changeData_clicked();
    void addbirthday_clicked();
    void oncell_clicked(int row, int column);
    void openFile();

};


#endif //TASK1_MAINWINDOW_H
