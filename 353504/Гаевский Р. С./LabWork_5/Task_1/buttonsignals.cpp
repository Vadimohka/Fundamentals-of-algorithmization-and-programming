#include <mainwindow.h>
#include <QDebug>

void MainWindow::buttonPressed(int code, bool sp)
{
    if (sp && ui->lineEdit_input && !ui->lineEdit_input->text().isEmpty())
    {
        QString str(ui->lineEdit_input->text().back());
        QString key;
        if (str != " ")
        {
            for (int j = 0; j < 66 && key.isEmpty(); ++j)
            {
                if(keys[j] != nullptr && keys[j])
                {
                    if (str == keyboard[locale][j + 1])
                    {
                        code = j + 1;
                    }
                }
            }
            if (locale == 2 || (code != -1 && keys[code - 1]->text() != str))
            {
                code = -1;
            }
        }
        if (ui->textEdit_input->toPlainText().endsWith(' '))
        {
            ++words;
        }
        if (ui->lineEdit_input->text().size() != 0 && ui->lineEdit_input->text().back() == ui->lineEdit_train->text().front())
        {
            if (str == " ")
            {
                ui->textEdit_input->insertHtml("<span style='background-color: rgba(0, 128, 0, 0.1);'>&nbsp;</span>");
            }
            else
            {
                ui->textEdit_input->insertHtml("<font color='green'>" + str + "</font>");
            }
            ++correctSymbols;

            QString nextText = ui->lineEdit_train->text();
            nextText.remove(0, 1);
            ui->lineEdit_train->setText(nextText);
            textManager->AddTextToNext();

            ++symbols;
            ui->label_accuracy_value->setText(QString::number(100. * correctSymbols / symbols) + " %");

            if(ui->lineEdit_train->text() == "")
            {
                timer->stop();
                QMessageBox::information(nullptr, "Information", "Training completed!\n\nAccuracy: " + ui->label_accuracy_value->text() + "\nWords per minute: " + ui->label_wpm_value->text() + "\nElapsed time: " + ui->label_elapsed_value->text());
                on_pushButton_stop_clicked();
            }
        }
        else
        {
            if (str == " ")
            {
                ui->textEdit_input->insertHtml("<span style='background-color: rgba(128, 0, 0, 0.1);'>&nbsp;</span>");
            }
            else
            {
                ui->textEdit_input->insertHtml("<font color='red'>" + str + "</font>");
            }
            ++symbols;
            ui->label_accuracy_value->setText(QString::number(100. * correctSymbols / symbols) + " %");
        }
    }
    if (code == -1)
    {
        return;
    }
    if(code < 67 && keys[code - 1] != nullptr && keys[code - 1])
    {
        if (code == 66)
        {
            keys[code - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
        }
        else if (code == 50 || code == 62)
        {
            keys[50 - 1]->setStyleSheet("QPushButton:disabled {background-color: green;color: #000000;}");
            keys[62 - 1]->setStyleSheet("QPushButton:disabled {background-color: green;color: #000000;}");
        }
        else
        {
            keys[code - 1]->setStyleSheet("QPushButton:disabled {background-color: green;color: #000000;}");
        }
    }
    if(ui->lineEdit_train->text() == "" || ui->lineEdit_input->isReadOnly())
    {
        buttonReleased(code);
    }
}

void MainWindow::buttonReleased(int code)
{
    if(code < 67 && keys[code - 1] != nullptr && keys[code - 1])
    {
        if (code != 66)
        {
            if (code == 50 || code == 62)
            {
                keys[50 - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
                keys[62 - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
            }
            else
            {
                keys[code - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
            }
        }
    }
}
