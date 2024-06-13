#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QFileDialog>
#include <QFile>
#include <QMainWindow>
#include <QKeyEvent>
#include <QMap>
#include <QPushButton>
#include <QTimer>
#include <QVector>
#include <QDebug>
#include "language.h"

const QString DEFAULT_COLOR_MODE = "";
const QString GREEN_COLOR_MODE = "color: rgb(51, 209, 122);";
const QString RED_COLOR_MODE = "color: rgb(224, 27, 36);";


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
    void keyPressEvent(QKeyEvent* e) override;

private:
    Ui::MainWindow *ui;
    QTimer* timer = new QTimer();
    QTimer* lightningTimer = new QTimer();
    Language* language = new Language();
    QMap<int, QString> currentLanguage;
    QVector<QPushButton*> keys;
    QString test = "";
    QString part = "";
    QString seconds = "", minutes = "", time = "";
    int sec = 0;
    int min = 0;
    int tics = 0, lights = 0;
    int pos = 0;
    int currentNumberOfWords = 0;

    void startTraining();
    void changeLanguage(int index);
    void finishTraining();
    QString readFromFile(QString path);

private slots:
    void onTimeout();
    void onLightningTimerTimeout();
    void on_languageBox_activated(int index);
};
#endif // MAINWINDOW_H
