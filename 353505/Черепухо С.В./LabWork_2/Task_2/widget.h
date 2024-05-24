#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <student.h>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QList>
#include <iostream>

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

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_pushButton_8_clicked();

private:
    Ui::Widget *ui;

    QString str;

    bool IsFileOpened = false;

    QVector <Student> arrr;

    QStandardItemModel* model = new QStandardItemModel(1, 6);
};
#endif // WIDGET_H
