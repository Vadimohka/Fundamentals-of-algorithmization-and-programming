#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <QCursor>
#include <math.h>
#include "Balloon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, QScreen *screen0 = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void MoveBalloon();

private:
    Balloon m_balloon;
    Ui::MainWindow *ui;
    QTimer *m_timer = new QTimer;
    QPainter m_painter;
    bool m_isHited = false;
    QScreen *m_screen0;
};
#endif // MAINWINDOW_H
