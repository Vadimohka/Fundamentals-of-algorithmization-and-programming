#include "dialogupdatetable.h"
#include "ui_dialogupdatetable.h"

DialogUpdateTable::DialogUpdateTable(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogUpdateTable)
{
    ui->setupUi(this);
}

DialogUpdateTable::~DialogUpdateTable()
{
    delete ui;
}
