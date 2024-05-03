#ifndef DIALOGADD_H
#define DIALOGADD_H

#include <QDialog>
#include <QVector>
#include <QMessageBox>
#include "flight.h"
#include "plane.h"

namespace Ui {
class DialogAdd;
}

class DialogAdd : public QDialog
{
    Q_OBJECT

public:

    explicit DialogAdd(QVector<Flight>& flights, QVector<Plane>& planes);
    ~DialogAdd();

private slots:
    void on_OkButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DialogAdd *ui;
    QVector<Flight>& flightsHere;
    QVector<Plane>& planesHere;
};

#endif // DIALOGADD_H
