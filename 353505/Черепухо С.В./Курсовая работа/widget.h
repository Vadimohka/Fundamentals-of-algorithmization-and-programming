#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QStandardItemModel>
#include <QKeyEvent>
#include <QLayout>
#include <QVector>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFileDialog>

#include <drawer.h>
#include <sprite.h>
#include <scene.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void timeout();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_spinBox_valueChanged(int arg1);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::Widget *ui;

    void paintEvent(QPaintEvent *e);

    QPainter painter;

    QTimer *timer;

    QStandardItemModel *blocks = new QStandardItemModel(), *script = new QStandardItemModel(), *sprits = new QStandardItemModel(0, 2), *sound = new QStandardItemModel();

    void moving();
    void operators();
    void vision();
    void sensors();
    void sounds();
    void ifers();
    void doings();
    void variables();

    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    bool mlb = false;

    int WorkPlaceType = 0;

    Scene *scene = new Scene();

    Drawer *drawer;
    QPoint drawerCurrent, setDrawerMlbClick;
    int drawType = 0;

    void changeWorkPlaceType(int index);

    QVector <Sprite> sprites;

    void SpriteSort(QVector <Sprite> array);

    //sprite moving zone

    QPoint cr; // курсор
    Sprite *busy = nullptr; // указатель на передвигаемый спрайт

    //spirte moveng end zone

    QVector <QString> sound_ar;
};
#endif // WIDGET_H
