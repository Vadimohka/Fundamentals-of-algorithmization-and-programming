#include "filemodel.h"

FileModel::FileModel(QObject *parent): QFileSystemModel(parent) {}

int FileModel::columnCount(const QModelIndex &) const
{
    return 1;
}

QVariant FileModel::data(const QModelIndex &ind, int role) const
{
    if(role == Qt::DecorationRole){
        return {};
    } else {
        return QFileSystemModel::data(ind, role);
    }
}
