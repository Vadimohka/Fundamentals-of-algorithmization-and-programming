#include "statesetter.h"

StateSetter::StateSetter(QWidget *parent)
    : QWidget{parent}
{
    loadUiFile(this);
    QPushButton* ui_findButton = findChild<QPushButton*>("findButton");
}
