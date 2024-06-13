#include "ConstKeys.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::buttonPressed(int code, bool space)
{
    if (space && ui->startEdit && !ui->startEdit->text().isEmpty()) {
        errorSymbol = false;
        ++amountSymbol;
        QString str(ui->startEdit->text().back());
        if (str != " ") {
            for (int j = 0; j <= SIZE_KEYS_ARRAY; ++j) {
                if (keysButton[j] != nullptr && keysButton[j]) {
                    if (str == keyboard[localizationType][j + 1]) {
                        code = j + 1;
                    }
                }
            }
        }
        if (ui->startEdit->text().size() != 0
            && ui->startEdit->text().back() == ui->progressTextEdit->text().front()) {
            if (str == " ") {
                ui->inputTextEdit->insertHtml(
                    "<span style='background-color: rgba(0, 128, 0, 0.1);'>&nbsp;</span>");
                ++amountWords;
            } else {
                ui->inputTextEdit->insertHtml("<font color='green'>" + str + "</font>");
            }

            QString nextText = ui->progressTextEdit->text();
            nextText.remove(0, 1);
            ui->progressTextEdit->setText(nextText);
            textWork->AddTextToProgressLine();

            if (ui->progressTextEdit->text() == "") {
                timer->stop();
                ui->lcdAmountWords->display(ui->lcdAmountWords->value() + 1);
                QMessageBox::information(nullptr,
                                         "Information",
                                         "Completed!\n\nWords per minute: "
                                             + QString::number(ui->lcdAmountWords->value())
                                             + "\nYour time: " + ui->timeEdit->text()
                                             + "\nAmount mistake: " + QString::number(errorInput)
                                             + "\nAmount symbols: " + QString::number(amountSymbol)
                                             + "\nTrue percent : "
                                             + QString::number((amountSymbol - errorInput) * 100
                                                               / amountSymbol)
                                             + "%");
                on_stopButton_clicked();
            }
        } else {
            if (str == " ") {
                ui->inputTextEdit->insertHtml(
                    "<span style='background-color: rgba(128, 0, 0, 0.1);'>&nbsp;</span>");
            } else {
                ui->inputTextEdit->insertHtml("<font color='red'>" + str + "</font>");
            }
            ++errorInput;
            errorSymbol = true;
        }
    }
    if (code == NOTHING_CODE) {
        return;
    }
    if (!errorSymbol && code <= SIZE_KEYS_ARRAY && keysButton[code - 1] != nullptr) {
        keysButton[code - 1]->setStyleSheet("QPushButton:disabled {background-color: green;}");
    } else if (errorSymbol && code <= SIZE_KEYS_ARRAY && keysButton[code - 1] != nullptr) {
        keysButton[code - 1]->setStyleSheet("QPushButton:disabled {background-color: red;}");
    }
}

void MainWindow::buttonReleased(int code)
{
    if (code <= SIZE_KEYS_ARRAY && keysButton[code - 1] != nullptr && keysButton[code - 1]) {
        keysButton[code - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;}");
    }
}
