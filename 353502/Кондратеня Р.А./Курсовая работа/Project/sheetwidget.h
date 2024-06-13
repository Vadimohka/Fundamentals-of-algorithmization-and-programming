#ifndef SHEETWIDGET_H
#define SHEETWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QComboBox>
#include <QMenu>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QLineEdit>
#include <QLabel>
#include <QtCharts>
#include <QFontDialog>
#include <QObject>
#include <QPalette>

#include "itemmodel.h"
#include "customtableview.h"
#include "filterwindow.h"

class SheetWidget : public QWidget
{
    Q_OBJECT
private:
    CustomTableView* table;
    ItemModel* model;
    QString action;
    FilterWindow* window;
//private slots:
//    void sortSelectedRange();
public:
    SheetWidget();
    ItemModel* getModel();
    QModelIndexList getSelectedIndexes();
    void setTableViewAction(QString action);
    void setFont(QFontDialog* fontDialog,CustomTableView* tableView,ItemModel* newModel);
    void setColorOfCells(CustomTableView* tableView);
    void setFontColorOfCells(CustomTableView* tableView);
signals:
    void filterTableSignal(double minValue, double maxValue);
protected slots:
    void setFiltration(double minValue, double maxValue);
};

#endif // SHEETWIDGET_H
