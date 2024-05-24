#include "filefunctions.h"
#include "ui_filefunctions.h"

FileFunctions::FileFunctions(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FileFunctions)
{
    ui->setupUi(this);
}

FileFunctions::~FileFunctions()
{
    delete ui;
}
