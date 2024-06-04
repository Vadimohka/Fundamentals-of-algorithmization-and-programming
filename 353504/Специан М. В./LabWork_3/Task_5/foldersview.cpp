#include "foldersview.h"

FoldersView::FoldersView(QObject *parent) : QFileSystemModel(parent) {}

QVariant FoldersView::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {

        if(index.column() != 0)
        {
            return "";
        }

        QString path = QDir::toNativeSeparators(filePath(index));
        QFileInfo fileInfo(path);
        return fileInfo.fileName();
    }
    return QVariant();
}

int FoldersView::columnCount(const QModelIndex&) const
{
    return 1;
}
