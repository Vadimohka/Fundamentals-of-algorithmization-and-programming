#include "mynewmainwindow.h"

MyNewMainWindow::MyNewMainWindow(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant MyNewMainWindow::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex MyNewMainWindow::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex MyNewMainWindow::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int MyNewMainWindow::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int MyNewMainWindow::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant MyNewMainWindow::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
