#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "continent.h"
#include <QMainWindow>

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
    void showMenu(int menuChoice);
    void writeTextToFile();
    void readTextFromFile();
    void writeArrayToFile();
    void readArrayFromFile();
    void writeContinentToFile();
    void readStructuresFromFile();
    void saveContinentToFile();
    void readContinentFromFile();
    void WriteAndSaveSentences();
   void ReadSentences();
private:
    Ui::MainWindow *ui;
 Continent continent;
};

#endif // MAINWINDOW_H
