#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QVector>
#include <QSet>

#include <QErrorMessage>
#include <QMessageBox>
#include <QDebug>

#include "vacancy.h"
#include "candidate.h"

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
    void on_pushButton_2_clicked();
    void on_comboBox_del_activated(int index);

    void on_pushButton_add_clicked();

    void on_comboBox_2_activated(int index);

    void on_pushButton_save_clicked();

    void on_pushButton_def_clicked();


    void on_pushButton_noCand_clicked();

    void on_comboBox_change_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool isCandOnScreen = false;
    bool openCand = false;
    int indChange = -1;
    QString sFilePath;
    Candidate* cand;
    Vacancy* vac;
    QVector <Candidate*> vecCand;
    QVector <Vacancy*> vecVacancy;

};
#endif // MAINWINDOW_H
