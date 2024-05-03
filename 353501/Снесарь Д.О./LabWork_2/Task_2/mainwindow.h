#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QSaveFile>
#include <QMessageBox>
#include <QTextEdit>
#include "dialogadd.h"
#include "dialogedit.h"
#include "plane.h"
#include "flight.h"
#include <QVector>


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
    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_deleteButton_clicked();

    void on_showButton_clicked();

    void on_openFileButton_clicked();

    void on_saveFileButton_clicked();

    void on_flightsTable_itemSelectionChanged();

    void on_pushButton_4_clicked();

    void on_sortDistanceButton_clicked();

    void on_sortDepartureButton_clicked();

    void on_calcButton_clicked();

private:

    double calculate();
    void addPlanes();
    void actualTable();
    void fromFile();
    void toFile();
    void currentShow();
    QFile file;
    QString planesFilePath;
    QString filePath;
    QVector<Flight> flVec;
    QVector<Plane> planeVec;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
