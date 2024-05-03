#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "samosval.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Samosval *sam = new Samosval;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slotUP();
    // void slotSTOP();
    void slotDOWN();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    Ui::MainWindow *ui;
    QTimer *timer = new QTimer;
private slots:
    void button1Pressed();
    void button2Pressed();
    void button1Released();
    void button2Released();
   };

#endif // MAINWINDOW_H
