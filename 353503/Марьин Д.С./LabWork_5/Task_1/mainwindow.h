#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTimer>
#include <QTextCharFormat>

#include "keyboardvisualizer.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setTextToWrite(QString& text);
    void ColorText(QChar newChar);
    void skip(int ms);
    void outputStat();

private slots:
    void updateTimer();

    void on_pushButton_chooseText_clicked();

    void on_ChangeLang_currentIndexChanged(int index);

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_TextInput_textChanged(const QString &arg1);

private:
    Ui::MainWindow* ui;
    KeyboardVisualizer* _keyboard;

    QString _currentText = "Grisha and Kolya went to the forest. They were picking mushrooms and berries.";

    QTimer* _timer;
    int time_sec = 0;
    int time_Msec = 0;
    int time_min = 0;

    QTextCharFormat _redF;
    QTextCharFormat _greenF;
    QTextCharFormat _blackF;

    int _charCntr = 0;
    float mistakes = 0;
    float correct = 0;
    int lang = 0;
    int words = 0;
    int isCorrect = 0;
    QVector <QString> KeyLayout;
};
#endif // MAINWINDOW_H
