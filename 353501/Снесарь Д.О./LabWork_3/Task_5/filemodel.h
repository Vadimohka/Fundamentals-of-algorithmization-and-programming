#ifndef FILEMODEL_H
#define FILEMODEL_H

#include <QFileSystemModel>

class FileModel: public QFileSystemModel
{
    Q_OBJECT
public:
    FileModel(QObject* = nullptr);
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    QVariant data(const QModelIndex& ind, int role) const override;
};

#endif // FILEMODEL_H
