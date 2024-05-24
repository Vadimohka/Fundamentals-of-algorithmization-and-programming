#ifndef DIALOGINPUTDATA_H
#define DIALOGINPUTDATA_H

#include <QDialog>
#include "Sportsman.h"

namespace Ui {
class DialogInputData;
}

class DialogInputData : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInputData(QWidget *parent = nullptr);
    ~DialogInputData();

private:
    Ui::DialogInputData *ui;
    bool isWritedName, isWritedSex;

public slots:
    Sportsman getSportsman();
};


#endif // DIALOGINPUTDATA_H
