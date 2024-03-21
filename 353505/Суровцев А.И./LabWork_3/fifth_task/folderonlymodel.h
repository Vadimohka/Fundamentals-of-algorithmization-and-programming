#ifndef FOLDERONLYMODEL_H
#define FOLDERONLYMODEL_H

#include <QFileSystemModel>

class FolderOnlyModel : public QFileSystemModel
{
public:
    FolderOnlyModel(QObject *parent = nullptr) : QFileSystemModel(parent) {}
    QVariant data(const QModelIndex &index, int role) const override
    {
        if (role == Qt::DisplayRole) {

            if(index.column() != 0) return "   ";
            QString path = QDir::toNativeSeparators(filePath(index));
            QFileInfo fileInfo(path);
            return fileInfo.fileName();
        }
        return QVariant();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const {
        return 1;
    }
};
#endif // FOLDERONLYMODEL_H
