//
// Created by acryoz on 3.3.24.
//

#ifndef UNTITLED5_QTABLEVIEWMODEL_H
#define UNTITLED5_QTABLEVIEWMODEL_H


#include <QModelIndex>
#include "Date.h"


class QTableViewModel: public QAbstractListModel {
public:
    QTableViewModel(QObject* parrent = nullptr);
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &, int ) const;
    void populate(QVector<Date> *newValues);
    void setBday(const Date& newBday);
    QVariant headerData(int, Qt::Orientation , int) const;
    void append(const Date&);
    void del(int);
    void redact(const Date&, int);
private:
    Date bday;
    QVector<Date>* values;
};


#endif //UNTITLED5_QTABLEVIEWMODEL_H
