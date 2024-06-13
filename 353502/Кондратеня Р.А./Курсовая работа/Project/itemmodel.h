#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QObject>
#include <QDebug>

#include "item.h"

class ItemModel : public QStandardItemModel
{
    Q_OBJECT
private:
    QModelIndexList selectedIndexes;
public:
    int NumberOfRows = 26;
    int NumberOfColumns = 26;

public:
    ItemModel();
    void saveTableInFile(QWidget* widget);
    void loadTableFromFile(QWidget* widget);
    void getSumOfCells(QModelIndexList selectedIndexes, QModelIndex selectedCell);
    void getMultOfCells(QModelIndexList selectedIndexes, QModelIndex selectedCell);
    void getAverageOfCells(QModelIndexList selectedIndexes, QModelIndex selectedCell);
    void getRandomValue(QModelIndexList selectedIndexes);
    QList<QList<QString>> ascendingGnomeSort(QList<QList<QString>> range, int sortingColumn);
    QList<QList<QString>> descendingGnomeSort(QList<QList<QString>> range, int sortingColumn);
    QList<QList<QString>> ascendingCombSort(QList<QList<QString>> range, int sortingColumn);
    QList<QList<QString>> descendingCombSort(QList<QList<QString>> range, int sortingColumn);
    void addRow();
    void addColumn();
    void deleteRow();
    void deleteColumn();

};

#endif // ITEMMODEL_H
