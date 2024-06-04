#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include "input.h"
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

    int languageIndex;

    QTimer* timer;
    int seconds = 0;

    int letters = 0;
    int incorrectPresses = 0;
    int correctPresses = 0;
private:
    Ui::MainWindow *ui;
    QVector<QPushButton*> keyboard;

    QVector<QString> symbols;
    QVector<QString> SYMBOLS;
    QVector<QVector<QString>> dictionary;
    QVector<QString> sampleText;
    QString currentText;

    void selectLanguage();
    void initializeKeyboard();
    void initializeAlphabet();
    void generateText();
    void initializeDictionaries();
    void reset();
public slots:
    void buttonPressed(int, bool, int &);
    void buttonReleased(int);
    void updateTimer();
};
#endif // MAINWINDOW_H
