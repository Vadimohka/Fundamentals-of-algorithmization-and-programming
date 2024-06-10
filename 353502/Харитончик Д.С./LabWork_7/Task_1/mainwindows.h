#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QTextCursor>

#include "myQueue.h"

namespace Ui {
class MainWindows;
}

class MainWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindows(QWidget *parent = nullptr);
    ~MainWindows();

    void highlightLine(int pos);

private slots:
    void on_randomButton_clicked();

    void on_leftButton_clicked();

    void on_rightButton_clicked();

private:
    Ui::MainWindows *ui;

    Deque dq;
    Node* buf;

    QTextCursor cursor;

    int pos = 0;
signals:
};

#endif // MAINWINDOWS_H
