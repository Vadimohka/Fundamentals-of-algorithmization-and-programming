#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "firmwindow.h"
#include "workerwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addWorkerButton_clicked();

    void on_addVacancyButton_clicked();

    void on_acceptedVacancyButton_clicked();

    void on_deficitVacancyButton_clicked();

    void on_deficitWorkerButton_clicked();

private:
    Ui::MainWindow *ui;
    FirmWindow addFirm;
    WorkerWindow addWorker;
    QStandardItemModel* model;
};
#endif // MAINWINDOW_H
