#ifndef FOLDERSVIEW_H
#define FOLDERSVIEW_H

#include <QFileSystemModel>

class FoldersView : public QFileSystemModel
{
public:
    FoldersView(QObject* = nullptr);

    QVariant data(const QModelIndex&, int) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
};

#endif 