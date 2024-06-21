#include "t3win.h"
#include "ui_t3win.h"

constexpr int STEP = 10;

T3Win::T3Win(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::T3Win)
{
    ui->setupUi(this);
}

T3Win::~T3Win()
{
    delete ui;
}

void T3Win::on_resultButton_clicked()
{
    l1 = STEP;
    l2 = STEP;
    countC(ui->inputLabel->text().toLongLong());

    if (ui->inputLabel->text().length() > 19)
    {
        ui->outputlabel->setText("too big");
        return;
    }
    ui->outputlabel->setText(QString::number(reverseNum(ui->inputLabel->text().toLongLong())));
}

int64_t T3Win::reverseNum(int64_t num)
{
    if (l1 / l2 >= STEP)
    {
        int64_t buf = (num % l1 - num % (l1 / STEP)) / (l1 / STEP);
        int64_t buf2 = (num % l2 - num % (l2 / STEP)) / (l2 / STEP);

        num -= buf * (l1 / STEP);
        num += buf2 * (l1 / STEP);
        num -= buf2 * (l2 / STEP);
        num += buf * (l2 / STEP);

        l1 /= STEP;
        l2 *= STEP;
        qDebug() << num;
        return reverseNum(num);
    }
    return num;
}

void T3Win::countC(int64_t num)
{
    if (num % l1 != num)
    {
        l1 *= STEP;
        countC(num);
    }
}

