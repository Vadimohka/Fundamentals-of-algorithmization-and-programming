#include "mainwindow.h"
#include <QDebug>

void MainWindow::buttonPressed(int code, bool correct, int &numSimvol)
{
    if(correct){
        QTextCursor cursor = ui->textEdit_input->textCursor();
        cursor.setPosition(numSimvol);
        cursor.setPosition(++numSimvol, QTextCursor::KeepAnchor);
        QTextCharFormat format;
        format.setForeground(Qt::green);
        cursor.setCharFormat(format);

        ++correctPresses;
        ui->correctSymbolsLabel->setText(QString::number(correctPresses));

        if(code == -1){
            ++words;
            ui->wordLabel->setText(QString::number(words));
        }
    }
    else{
        ++incorrectPresses;
        ui->incorrectSymbolsLabel->setText(QString::number(incorrectPresses));
    }
    qDebug() << numSimvol << ui->textEdit_input->toPlainText().length() << "\n";
    if(numSimvol == ui->textEdit_input->toPlainText().length()){
        numSimvol = 0;
        timer->stop();
        ui->pushButton_start->setEnabled(false);
        ui->lineEdit_input->numSimvol = 0;
        ui->lineEdit_input->chineseWritenWords.resize(0);
        currentText.clear();
        ++words;
        ui->wordLabel->setText(QString::number(words));
        ui->lineEdit_input->setEnabled(false);
        for(int i = 0; i < keyboard.size(); i++){
            keyboard[i]->setStyleSheet("background-color: #f0f0f0;color: #000000");
        }
    }
}

void MainWindow::buttonReleased(int code)
{
    qDebug() << "button";
}