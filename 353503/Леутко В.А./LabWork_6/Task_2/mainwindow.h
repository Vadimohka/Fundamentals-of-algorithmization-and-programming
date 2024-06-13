#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "autorepairshop.h"
#include <QInputDialog>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDir>
#include <QButtonGroup>

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
    QString printInfo(const AutoRepairShop& shop);

private slots:
    void on_inputBtn_clicked();
    void on_outputBtn_clicked();

private:
    Ui::MainWindow *ui;
    QString currentFilePath;

    void recordTextToFile();
    void appendTextToFile();
    void readTextFromFile();
    void recordArrayToFile();
    void readArrayFromFile();
    void appendStructToFile();
    void readStructFromFile();
    void appendStructToFileBin();
    void readStructFromFileBin();
    void updateOutputText();
};
#endif // MAINWINDOW_H
