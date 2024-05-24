#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mystring.h"

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    String _mainStr;
    String _addStr;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void slotMainChanged(const QString &arg1);
    void slotAddChanged(const QString &arg1);
    void pushBack();
    void popBack();
    void insert();
    void erase();
    void find();
    void rFind();
    void plus();
    void clear();
    void shrink();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
