#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include "keyboardwidget.h"

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
protected:
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void on_languageChangeComboBox_currentIndexChanged(int index);

    void on_stopButton_clicked();

    void on_startButton_clicked();

    void on_openTestButton_clicked();
private:
    QStringList currTest;

    Ui::MainWindow *ui;
    KeyboardWidget* keyboard = new KeyboardWidget();

    int currLocal;

    bool checkTest();

    bool isTesting = false;

    int currNeededSimb = 0;
    int currTestNum = 0;

    void setButtons();

    QElapsedTimer* timer = new QElapsedTimer();
    QTimer* updateTimer = new QTimer();

    int words = 0;
    int rightSymbols = 0;
    int allSymbols = 0;

    void updateInfo();

    void workWithEvent(QKeyEvent *event);


    void setText();
};
#endif // MAINWINDOW_H
