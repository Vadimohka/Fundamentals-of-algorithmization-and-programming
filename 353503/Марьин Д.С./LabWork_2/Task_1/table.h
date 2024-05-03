#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVector>
#include <QWidget>

#include "QtCore/qfile.h"
#include "date.h"

class Table : public QTableWidget
{
    Q_OBJECT
public:
    Table();
    void updateRowSize();
    void updateInfo();
    void remove_Row(int i);
    void DelRow(QFile*, int n);
    void EditRow(Date d, int n);
    void setTableInfo(QVector<Date*>);
    void setRow(Date*,int);
    void addRow(Date*);
private:
    QVector<Date*>dates;
};

#endif // TABLE_H
