#include "mainwindow.h"
#include <QDebug>

void MainWindow::bp(int c, bool corr, int &n)
{
    if(corr){
        QTextCursor cursor = ui->te->textCursor();
        cursor.setPosition(n);
        cursor.setPosition(++n, QTextCursor::KeepAnchor);
        QTextCharFormat f;
        f.setForeground(Qt::green);
        cursor.setCharFormat(f);

        ++cp;
        ui->c->setText(QString::number(cp));

        if(c == -1){
            ++w;
            ui->w->setText(QString::number(w));
        }
    }
    else{
        ++ip;
        ui->i->setText(QString::number(ip));
    }
    qDebug() << n << ui->te->toPlainText().length() << "\n";
    if(n == ui->te->toPlainText().length()){
        n = 0;
        t->stop();
        ui->pb->setEnabled(false);
        ui->l->n = 0;
        ui->l->cw.resize(0);
        ct.clear();
        ++w;
        ui->w->setText(QString::number(w));
        ui->l->setEnabled(false);
        for(int i = 0; i < kb.size(); i++){
            kb[i]->setStyleSheet("background-color: #f0f0f0;color: #000000");
        }
    }
}

void MainWindow::br(int c)
{
    qDebug() << "button";
}
