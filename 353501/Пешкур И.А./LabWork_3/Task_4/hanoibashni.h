#ifndef HANOIBASHNI_H
#define HANOIBASHNI_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QVector>
#include <QString>
#include "tryagain.h"

namespace Ui {
class HanoiBashni;
}

class HanoiBashni : public QDialog
{
    Q_OBJECT

public:
    explicit HanoiBashni(QWidget *parent = nullptr);
    ~HanoiBashni();

private:
    Ui::HanoiBashni *ui;
    QGraphicsScene* scene;
    QGraphicsRectItem* item;
    QGraphicsRectItem** disks;
    QBrush brush;
    QPen pen;
    long long Ammount;
    QChar* whereDisk;
    QChar* whereMove;
    QString shtuki= "";
    long long moveSpeed = 100;


public:
    void makeBashni( long long Ammount );
    void moveToBashni( long long pos );
    void moveFunct( long long pos );
    void moveY( long long pos , long long newY );

private slots:
    void on_pushButtonStart_clicked();
    void on_horizontalSlider_valueChanged(int value);
};

#endif // HANOIBASHNI_H
