#include "FileSystemModel.h"

FileSystemModel::FileSystemModel(QObject* parent) : QFileSystemModel(parent) {  }

int FileSystemModel::columnCount(const QModelIndex &parent) const{
    return 1;
}

QVariant FileSystemModel::data(const QModelIndex& ind, int role) const {
if(role == Qt::DecorationRole){
    return {};
} else {
    return QFileSystemModel::data(ind, role);
}
} 
