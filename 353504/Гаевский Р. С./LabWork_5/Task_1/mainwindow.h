#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <inputmanager.h>
#include <textmanager.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QInputMethod *inputMethod = QApplication::inputMethod();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    TextManager *textManager;
    QVector<QString> dictionary;
    QVector<QString> trainingText;
    QVector<QMap<int, QString>> keyboard;
    QVector<QPushButton*> keys;

    int seconds = 0;
    int words = 0;
    int symbols = 0;
    int correctSymbols = 0;
    int locale;

    void initKeyboard();
    void setKeyboard(int);

public slots:
    void buttonPressed(int, bool);
    void buttonReleased(int);

private slots:
    void on_pushButton_start_clicked();
    void on_pushButton_reset_clicked();
    void on_pushButton_load_clicked();
    void on_comboBox_currentIndexChanged(int);
    void on_spinBox_valueChanged(int);
    void timerTick();

    void on_pushButton_stop_clicked();
};

#endif // MAINWINDOW_H
