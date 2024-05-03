#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>
#include <QMessageBox>
#include "flight.h"
#include "plane.h"

namespace Ui {
class DialogEdit;
}

class DialogEdit : public QDialog
{
    Q_OBJECT

public:

     explicit DialogEdit(QVector<Flight>& flights, QVector<Plane>& planes, int num);
    ~DialogEdit();

 private slots:
     void on_OkButton_2_clicked();

     void on_CancelButton_clicked();

 private:
    int index;
    Ui::DialogEdit *ui;
    QVector<Flight>& flightsHere;
    QVector<Plane>& planesHere;
};

#endif // DIALOGEDIT_H
