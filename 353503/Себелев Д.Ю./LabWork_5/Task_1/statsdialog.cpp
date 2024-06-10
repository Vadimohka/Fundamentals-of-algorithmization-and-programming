#include "statsdialog.h"
#include "ui_statsdialog.h"

StatsDialog::StatsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StatsDialog)
{
    ui->setupUi(this);

    setWindowTitle("Statistics");

    connect(ui->close_btn, SIGNAL(clicked()), this, SLOT(closeDialog()));
}

StatsDialog::~StatsDialog()
{
    delete ui;
}

void StatsDialog::setInfo(int err, double accur, double wpm)
{
    ui->errors_label->setText(QString::number(err));
    ui->accur_label->setText(QString::number(accur) + "%");
    ui->wpm_label->setText(QString::number(wpm));
}

void StatsDialog::closeDialog()
{
    close();
}
