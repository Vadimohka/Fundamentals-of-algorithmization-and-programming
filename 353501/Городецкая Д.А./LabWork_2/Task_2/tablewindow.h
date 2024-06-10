#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QList>
#include <QPair>
#include "women.h"
#include "man.h"

class TableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableWindow(QTableWidget* tableWidget, QWidget* parent = nullptr);
    void populateTable();
    ~TableWindow();

private:
    QTableWidget *tableWidget;
    QList<Women> womenList;
    QList<Man> menList;
};

#endif // TABLEWINDOW_H
