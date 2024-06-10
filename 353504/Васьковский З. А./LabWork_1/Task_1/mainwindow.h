#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QVector>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QResizeEvent>
#include <QTimer>
#include "customscene.h"
#include "eyes.h"
#include "black_eye.h"
#include "face.h"
#include "mouth.h"

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
    QGraphicsItemGroup *head;
    Face *face;
    Eyes *Reye_ball;
    Eyes *Leye_ball;
    Black_eye *b_r;
    Black_eye *b_l;
    Mouth *mouth;
};
#endif // MAINWINDOW_H
