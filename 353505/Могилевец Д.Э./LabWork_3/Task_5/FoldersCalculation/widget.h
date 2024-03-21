#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include "dirscounter.h"
#include <QThread>
#include <QFileSystemModel>
#include <QStyledItemDelegate>


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

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    DirsCounter counter;
    QString selectedDirectory;
    long long files, dirs;
    FolderOnlyModel* model;
};
#endif // WIDGET_H
