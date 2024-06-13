#ifndef FIRMWINDOW_H
#define FIRMWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QTextStream>
#include <QDebug>

namespace Ui {
class FirmWindow;
}

class FirmWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FirmWindow(QWidget *parent = nullptr);
    ~FirmWindow();

    void getDataFromFile();
    QVector<QStringList> getVacancyList();

private slots:

    void on_changeWorkerButton_clicked();

    void on_addWorkerButton_clicked();

private:
    Ui::FirmWindow *ui;
    QStandardItemModel *model;
    QModelIndex index;
    QStringList strings;
    QVector<QStringList> vacancyList;
    int numberOfRow = 0;
};

#endif // FIRMWINDOW_H
