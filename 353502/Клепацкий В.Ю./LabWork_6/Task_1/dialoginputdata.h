#ifndef DIALOGINPUTDATA_H
#define DIALOGINPUTDATA_H

#include <QDialog>
#include "Kinoserial.h"

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
    bool isWritedName, isWritedglavnu;

public slots:
    Kinoserial getKinoserial();
};

#endif // DIALOGINPUTDATA_H
