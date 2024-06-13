#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>
#include <QKeyEvent>
#include <QLocale>
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

const int TEXT_SIZE = 100;
const int PROBABILITY_OF_SPACE = 4;
const double TIMER_INTERVAL = 20;
const int MILLISECONDS_IN_SECOND = 1000;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addButtonsFromLayout(const QLayout* layout);

public slots:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

private:
    QVector<QPushButton*> buttons;
    Ui::MainWindow *ui;
    QLocale locale;
    QString alphabet;
    int wrongPressed;
    int rightPressed;
    int prevWrongPressed;
    int rightWords;
    QString textToWrite;
    QString writtenText;
    QTimer timer;
    double currentTime;
};
#endif // MAINWINDOW_H
