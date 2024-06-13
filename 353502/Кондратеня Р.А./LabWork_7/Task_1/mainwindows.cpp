#include "mainwindows.h"
#include "ui_mainwindows.h"



MainWindows::MainWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindows)
{
    ui->setupUi(this);

    //ui->textEdit->setEnabled(false);

    cursor = ui->textBrowser->textCursor();
}

MainWindows::~MainWindows()
{
    delete ui;


}

void MainWindows::on_randomButton_clicked()
{
    QString string;
    for(int i = 0; i < 15; ++i)
    {
        int randomNumber = QRandomGenerator::global()->bounded(100);
        dq.pushBack(randomNumber);
        string.push_back(QString::number(randomNumber) + "\n");
    }
    dq.makeCircular();
    buf = dq.front;
    ui->textBrowser->setText(string);
    ui->valueBrowser->setText(QString::number(buf->data));
    highlightLine(pos);
}

void MainWindows::highlightLine(int pos)
{
    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.movePosition(QTextCursor::Start);

    // Перемещение курсора к началу нужной строки
    for (int i = 0; i < pos; ++i) {
        cursor.movePosition(QTextCursor::Down);
    }

    // Выделение строки
    cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);

    // Установка курсора и выделение текста
    ui->textBrowser->setTextCursor(cursor);
}


void MainWindows::on_leftButton_clicked()
{
    buf = buf->prev;
    ui->valueBrowser->setText(QString::number(buf->data));
    if(pos == 0)
        pos = 14;
    else
        pos--;
    highlightLine(pos);
}


void MainWindows::on_rightButton_clicked()
{
    buf = buf->next;
    ui->valueBrowser->setText(QString::number(buf->data));
    if(pos == 14)
        pos = 0;
    else
        pos++;
    highlightLine(pos);
}

