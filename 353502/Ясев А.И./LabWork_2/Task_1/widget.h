#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTableWidget>
#include <QFile>
#include <QFileDialog>
#include<QMessageBox>
#include "qdebug.h"
#include "dialog.h"
#include "mydate.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    QTableWidget *table;
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_deleteButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    void update();
    QString dialog(QString label = "");
    QFile readWriteFile;
    QVector<MyDate> vector;
};
#endif // WIDGET_H
