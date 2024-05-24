#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include "inputmanager.h"
#include <QRandomGenerator>
#include <QFileDialog>
#include <QMessageBox>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int lanIndex;

    QTimer* timer;
    int seconds = 0;

    int words = 0;
    int incorrectPresses = 0;
    int correctPresses = 0;
private:
    Ui::MainWindow *ui;
    QVector<QPushButton*> keyboard;

    QVector<QString> SIMVOLS;
    QVector<QString> simvols;
    QVector<QVector<QString>> dictionary;
    QVector<QString> testText;
    QString currentText;

    void setLanguage();
    void initKeyboard();
    void initSymbolsOfAlphabet();
    void generateText();
    void initDictionaryes();
    void on_pushButton_reset_clicked();
public slots:
    void buttonPressed(int, bool, int &);
    void buttonReleased(int);
    void updateTimer();
//private slots:
    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
   // void on_pushButton_load_clicked();
    void on_pushButton_open_clicked();
//};
};
#endif // MAINWINDOW_H