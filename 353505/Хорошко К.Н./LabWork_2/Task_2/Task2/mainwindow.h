#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QToolBar>
#include <QStackedWidget>
#include <QActionGroup>
#include <QResizeEvent>
#include <widget.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void resizeEvent(QResizeEvent *event);

    widget* widget1;
    widget* widget2;
    widget* widget3;
    widget* widget4;
    widget* widget5;

    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *action5;

    QToolBar* navToolBar;
    QStackedWidget *stackedWidget;
    QVBoxLayout *mainLayout;
    QWidget *centralWidget;

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
