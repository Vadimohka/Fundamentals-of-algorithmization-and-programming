#ifndef WORKERWINDOW_H
#define WORKERWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QTextStream>
#include <QDebug>

namespace Ui {
class WorkerWindow;
}

class WorkerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WorkerWindow(QWidget *parent = nullptr);
    ~WorkerWindow();

    void getDataFromFile();
    int getAge(int numberOfWorker);
    QVector<QStringList> getWorkersList();

private slots:
    void on_addWorkerButton_clicked();

    void on_changeWorkerButton_clicked();


private:
    Ui::WorkerWindow *ui;
    QStandardItemModel *model;
    QStringList strings;
    QVector<QStringList> workersList;
    int numberOfRow = 0;
};

#endif // WORKERWINDOW_H
