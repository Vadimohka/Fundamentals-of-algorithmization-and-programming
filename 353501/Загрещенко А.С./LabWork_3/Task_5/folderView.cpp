#include "folderView.h"

FoldersView::FoldersView(QObject* parent) : QFileSystemModel(parent) {}

QVariant FoldersView::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
     
        return QFileSystemModel::data(index, Qt::DisplayRole);
    }

    return QVariant();
}

int FoldersView::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 1; 
}
