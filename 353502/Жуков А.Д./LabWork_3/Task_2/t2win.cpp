#include "t2win.h"
#include "ui_t2win.h"

constexpr int ONE = 1;

T2Win::T2Win(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::T2Win)
{
    ui->setupUi(this);
}

T2Win::~T2Win()
{
    delete ui;
}

void T2Win::on_pushButton_clicked()
{
    bool ok = false;
    int64_t m = ui->inputM->text().toULongLong(&ok);
    int64_t n = ui->inputN->text().toULongLong(&ok);
    if (!ok || m < 0 || n < 0)
    {
        ui->label->setText("invalid input");
        return;
    }

    int64_t a = A(m, n);
    ui->label->setText(a <= -ONE ? "too big" : QString::number(a));
}

int64_t T2Win::A(int64_t m, int64_t n)
{
    if (m == 0)
    {
        return n + ONE;
    }
    else if (m == ONE)
    {
        return n + 2;
    }
    else if (m == 2)
    {
        return 2 * n - 3;
    }
    else if (m == 3 && n < 61)
    {
        return power(2, n + 3) - 3;
    }
    else if (m == 4)
    {
        if (n < 2)
        {
            if (n)
            {
                return 65533;
            }
            else if (!n)
            {
                return 13;
            }
        }
        return -ONE;
    }
    if (m == 5 && n == 0)
    {
        return 65533;
    }
    else
    {
        return -ONE;
    }
}

int64_t T2Win::power(int64_t base, int64_t exponent) {
    int64_t result = ONE;

    while (exponent > 0)
    {
        if (exponent % 2 == ONE)
        {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }

    return result;
}
