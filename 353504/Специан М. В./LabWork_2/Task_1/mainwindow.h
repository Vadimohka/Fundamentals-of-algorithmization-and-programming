#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Date.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void AddDate(QString stringDate, bool over);
    void UpdateTable();
    bool event(QEvent *e);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

    Date* m_pBirthdayDate = nullptr;
    Date* m_pDates;
    int m_datesNum = 0;
    QString m_fileName = "";
};
#endif // MAINWINDOW_H
