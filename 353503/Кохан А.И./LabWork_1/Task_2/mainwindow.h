#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCursor>
#include <QResizeEvent>
#include <QActionGroup>
#include "customscene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CustomScene *scene;
    QTimer *timer;
    QActionGroup* actionGroup;
    QTimer* timerInfo;

private:
   void resizeEvent(QResizeEvent * event);

private slots:
    // Таймер для изменения размеров сцены при изменении размеров Окна приложения
    void slotTimer();
    void setTextLabel();

    void on_actionRect_triggered();
    void on_actionRomb_triggered();
    void on_actionTriangle3_triggered();
    void on_actionEllipse_triggered();
    void on_actionCircle_triggered();
    void on_actionSquare_triggered();
    void on_actionHexagon_triggered();
    void on_actionTriangle90_triggered();
    void on_actionStar5_triggered();
    void on_actionStar6_triggered();
    void on_actionStar8_triggered();
    void on_actionDelete_triggered();
    void on_actionMove_triggered();
    void on_actionBroom_triggered();
    void on_actionRestart_triggered();
    void on_actionRotation_triggered();
    void on_actionScale_triggered();
    void on_actionLine_triggered();
};
#endif // MAINWINDOW_H
