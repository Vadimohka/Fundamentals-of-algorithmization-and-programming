#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "date.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QSaveFile>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void changeEvent(QEvent * e) override;

private slots:
    void dateAddButton_clicked();
    void dateEditButton_clicked();
    void updateBirthdayDays(const QDate &date);
    bool fileCheck(QString date);
    void fileOpen_2_clicked();
    void fileSave_2_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName = "";
    QFile file;
    void update();
    QString pass;

};

#endif // MAINWINDOW_H
