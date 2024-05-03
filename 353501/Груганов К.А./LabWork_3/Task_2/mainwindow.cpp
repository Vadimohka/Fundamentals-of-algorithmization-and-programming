#include "mainwindow.h"
#include <QPixmap>
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int w = ui->image->width();
    int h = ui->image->height();
    QPixmap pix(":/akkerman/Снимок экрана от 2024-03-28 02-47-13.png");
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

MainWindow::~MainWindow()
{
    delete ui;
}

ull MainWindow::Akkerman(int m, int n)
{
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return Akkerman(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return Akkerman(m - 1, Akkerman(m, n - 1));
    } else
        return 0;
}

void MainWindow::on_calculate_clicked()
{
    bool okM, okN;
    if (ui->mEdit->text().isEmpty() && ui->nEdit->text().isEmpty()) {
        QMessageBox::information(this, "Ввод данных", "Надо ввести m и n.");
    } else {
        int m = ui->mEdit->text().toInt(&okM);
        int n = ui->nEdit->text().toInt(&okN);
        if (m < 0 || m > 4) {
            QMessageBox::warning(this,
                                 "Ошибка ввода",
                                 "Значение m должно быть в пределах от 0 до 4.");
            return;
        }

        if (m == 4 && n > 1) {
            QMessageBox::warning(this, "Ошибка ввода", "При m = 4 значение n должно быть меньше 1.");
            return;
        }

        if (!okM && !okN) {
            QMessageBox::warning(this, "Ошибка ввода", "Неверный ввод для m и n.");
            return;
        }

        if (!okN) {
            QMessageBox::warning(this, "Ошибка ввода", "Неверный ввод для n.");
            return;
        }
        if (!okM) {
            QMessageBox::warning(this, "Ошибка ввода", "Неверный ввод для m.");
            return;
        }

        ull result = Akkerman(m, n);
        ui->result->setText(QString::number(result));
    }
}
