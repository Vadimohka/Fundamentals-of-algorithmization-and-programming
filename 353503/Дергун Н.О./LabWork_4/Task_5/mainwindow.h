#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myvector.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QMainWindow>
#include <QProcess>
#include <QRandomGenerator>
#include <QProcess>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    My::Vector<My::Pair<My::Vector<int>,
                        My::Vector<My::Pair<int,double>>>> _vec;
    QProcess* _process;

    void _setNotEditable(QTableWidget* table);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void visualize();

public slots:
    void showVec();
    void slotRandomize();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
