#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QListView>
#include <QMainWindow>
#include "work.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_otmenaButton_clicked();

    void on_zadanieButton_clicked();

    void on_projectButton_clicked();

    void on_srokButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Work *> company;
    QString fileName = "/home/vlad-klepatskiy/файл/Firma1.txt";
    void createUI();
    //void addRow(Work* firma, int row);
    QVector<Work *> readFile(QString fileName);
    void sortByRykovoditel(QString nameRykovoditel);
    void sortBySotrydnik(QString nameSotrydnik);
    void sortByproject(QString nameSotrydnik);
    void sortBySrok();
};
#endif // MAINWINDOW_H
