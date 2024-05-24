#include "dialogfindstudent.h"
#include "ui_dialogfindstudent.h"

DialogFindStudent::DialogFindStudent(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogFindStudent)
{
    ui->setupUi(this);
}

DialogFindStudent::~DialogFindStudent()
{
    delete ui;
}

QString DialogFindStudent::getStudentsName()
{
    return ui->lineName->text();
}
