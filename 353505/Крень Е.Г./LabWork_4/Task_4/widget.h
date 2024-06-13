#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QTableWidget>
#include "vector.h"
#include <QMessageBox>
#include <QHeaderView>

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

private:
    const QStringList name = {"Индекс","Значение"};
    void refreshTable();
    Ui::Widget *ui;
    Vector<int> data;
};
#endif // WIDGET_H
