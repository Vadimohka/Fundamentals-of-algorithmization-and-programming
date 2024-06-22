#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QTextEdit *text;

private:
    QLabel *L1;
    QLabel *L2;
    QLabel *L3;
    QLabel *L4;
    QLabel *L5;
    QPushButton *butt;
    QCheckBox *check;
    QLineEdit *E1, *E2, *E3, *E4, *E5;
    QGridLayout *lay;
    void InicialisateImplicit();

private slots:
    void create();
};
#endif // MAINWINDOW_H
