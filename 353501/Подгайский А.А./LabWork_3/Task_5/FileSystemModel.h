#ifndef FS_MODEL
#define FS_MODEL

#include <QFileSystemModel>

class FileSystemModel : public QFileSystemModel{
    Q_OBJECT

    public:
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& ind, int role) const override;
    explicit FileSystemModel(QObject* parent = nullptr);
};

#endif