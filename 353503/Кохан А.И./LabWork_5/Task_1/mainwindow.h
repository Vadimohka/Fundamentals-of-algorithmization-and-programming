#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QInputMethod>
#include <QKeyEvent>
#include <QMainWindow>
#include <QTimer>
#include "pressonkeyboard.h"
#include "qpushbutton.h"
#include "textwork.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void updateInfo();

    void on_comboBox_currentIndexChanged(int index);

    void on_spinBox_valueChanged(int arg1);

    void on_generateButton_clicked();

    void on_startEdit_selectionChanged();

public slots:
    void buttonPressed(int, bool);
    void buttonReleased(int);

private:
    void initKeyboard();
    void setKeyboard(int);
    void buttonSetWhiteColor();

    QTimer *timer;
    TextWork *textWork;
    QVector<QString> dictionary;
    QVector<QString> tranningText;
    QVector<QMap<int, QString>> keyboard;
    QVector<QPushButton *> keysButton;
    Ui::MainWindow *ui;

private:
    bool errorSymbol = false;
    int passedTime = 0;
    short amountWords = 0;
    short localizationType = 0;
    short errorInput = 0;
    short amountSymbol = 0;
};
#endif // MAINWINDOW_H
