#ifndef CUSTOMTABLEVIEW_H
#define CUSTOMTABLEVIEW_H

#include <QTableView>
#include <QStandardItemModel>
#include <QMouseEvent>
#include <QMenu>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QtCharts>
#include <QObject>

#include "function.h"
#include "itemmodel.h"
#include "filterwindow.h"


class CustomTableView : public QTableView
{
private:
    QModelIndexList selectedIndexes;
    QModelIndex selectedCell;
    QString action;
    QString executingFunction = "nothing";
public:
    CustomTableView(QWidget *parent = nullptr);
    ItemModel* getModel();
    void setAction(QString action);
    void buildLineDiagram(QModelIndexList selectedIndexes);
    void buildGraphic(QModelIndexList selectedIndexes);
    void buildPieDiagram(QModelIndexList selectedIndexes);
    void sortSelectedRange();

    bool checkCorrectInputForPieDiagram(QModelIndexList selectedIndexes);

    bool checkCorrectInputForLineDiagram(QModelIndexList selectedIndexes);

    bool checkCorrectInputForGraphic(QModelIndexList selectedIndexes);

    bool isValues(QModelIndexList selectedIndexes);

    bool checkCorrectnessOfValues(int firstRow, int lastRow, int firstColumn, int lastColumn);

    bool checkCorrectnessOfDiapason(QModelIndexList selectedIndexes);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    void filterTable(double minValue, double maxValue);
};

#endif // CUSTOMTABLEVIEW_H
