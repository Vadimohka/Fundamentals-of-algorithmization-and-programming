//
// Created by acryoz on 3.3.24.
//

#include "../headers/QTableViewModel.h"


QTableViewModel::QTableViewModel(QObject *parrent):
    QAbstractListModel(parrent){
    values = new QVector<Date>;
}


int QTableViewModel::rowCount(const QModelIndex &) const {
    return values->count();
}


int QTableViewModel::columnCount(const QModelIndex &) const {
    return 7;
}


QVariant QTableViewModel::data(const QModelIndex &index, int role) const {
    QVariant val;
    switch (role) {
        case Qt::DisplayRole: {
            switch (index.column()) {
                case 0:
                    val = this->values->at(index.row()).toQstring();
                    break;
                case 1:
                    if(this->values->at(index.row()).nextDay().isValid()){
                        val = this->values->at(index.row()).nextDay().toQstring();
                    }
                    else{
                        val = QString("Invalid date");
                    }
                    break;
                case 2:
                    if(this->values->at(index.row()).previousDay().isValid()){
                        val = this->values->at(index.row()).previousDay().toQstring();
                    }
                    else{
                        val = QString("Invalid date");
                    }
                    break;
                case 3:
                    if(this->values->at(index.row()).isValid()){
                        if(this->values->at(index.row()).isLeap()){
                            val = QString("Leap");
                        }
                        else{
                            val = QString("Not leap");
                        }
                    }
                    else{
                        val = QString("Invalid date");
                    }
                    break;
                case 4:
                    if(this->values->at(index.row()).isValid()){
                        val = this->values->at(index.row()).weekNumber();
                    }
                    else{
                        val = QString("Invalid date");
                    }
                    break;
                case 5:
                    if(this->values->at(index.row()).isValid()){
                        if(index.row() < this->values->size() - 1){
                            val = this->values->at(index.row()).daysTo(this->values->at(index.row() + 1));
                        }
                        else{
                            val = QString("No next day");
                        }
                    }
                    else{
                        val = QString("Invalid date");
                    }
                    break;
                case 6:
                    if(this->values->at(index.row()).isValid()){
                        if(this->bday.isValid()){
                            val = this->values->at(index.row()).daysTillYourBirthday(this->bday);
                        }
                        else {
                            val = QString("No valid birthday");
                        }
                    }
                    else{
                        val = QString("Invalid date");
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return val;
}


void QTableViewModel::setBday(const Date& new_bday) {
    this->bday = new_bday;
    emit dataChanged(createIndex(0,0), createIndex(this->rowCount(QModelIndex()) - 1, 6));
}

void QTableViewModel::populate(QVector<Date> *new_values) {
    int n = new_values->count();
    this->beginInsertRows(QModelIndex(), 1, n);
        this->values = new_values;
    endInsertRows();
    emit dataChanged(createIndex(0,0), createIndex(this->rowCount(QModelIndex()) - 1, 6));
}

QVariant QTableViewModel::headerData(int section, Qt::Orientation orientation, int role) const{
    QVariant val = QVariant();
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole){
        switch (section) {
            case 0:
                val = QString("Date");
                break;
            case 1:
                val = QString("Next day");
                break;
            case 2:
                val = QString("Previous day");
                break;
            case 3:
                val = QString("Is leap");
                break;
            case 4:
                val = QString("Week number");
                break;
            case 5:
                val = QString("Days until next entry");
                break;
            case 6:
                val = QString("Days until your birthday");
                break;
            default:
                break;
        }
    }
    return val;
}


void QTableViewModel::append(const Date& date){
    int new_row_id = this->values->count() + 1;
    this->beginInsertRows(QModelIndex(), new_row_id, new_row_id);
        this->values->push_back(date);
    endInsertRows();
}


void QTableViewModel::del(int row){
    this->beginRemoveRows(QModelIndex(),row, row);
        this->values->remove(row);
    endRemoveRows();
}


void QTableViewModel::redact(const Date& new_date, int row){
    this->values[0][row] = new_date;
    emit dataChanged(this->index(row,0), this->index(row , 6));
}