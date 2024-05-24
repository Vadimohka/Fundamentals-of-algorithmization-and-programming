#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QKeyEvent>
#include "mylineedit.h"
#include <QTimer>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    MyLineEdit* line;
    QTimer* updateTimer;
    int time = 0;
    int n = 0;

private slots:
    void menu_click_A();
    void menu_click_D();
    void menu_click_F();
    void menu_click_K();
    void menu_click_B();
    void menu_click_I();

public:
    void Result(int res);
    void Res(QString t);

private:
#include <cstdlib>
#include <QDebug>

    void changeKeyboardLayout(const QString &layoutId)
    {
        QString command = "setxkbmap " + layoutId;
        int result = std::system(command.toUtf8().constData());
        if (result == 0) {
            qDebug() << "Раскладка клавиатуры успешно изменена.";
        } else {
            qDebug() << "Ошибка при изменении раскладки клавиатуры.";
        }


    }
};
#endif // MAINWINDOW_H
