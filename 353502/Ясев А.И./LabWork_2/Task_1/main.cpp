#include "widget.h"

#include <QApplication>
#include <QDebug>
#include <QFileDialog>
#include <QTableWidgetItem>
#include "mydate.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    // QString s;
    // QString fl = QFileDialog::getOpenFileName(&w,"","/home/lq-84i/QTProjects/Task_1/resources/");
    // qDebug() << fl;
    // QFile f(fl);
    // f.open(QIODevice::ReadWrite);
    // QTextStream stream(&f);
    // QVector<MyDate> vector;

    // while(!stream.atEnd()){
    //     s=stream.readLine();
    //     MyDate date(s);
    //     vector.append(date);
    // }
    // MyDate current = MyDate::current();
    // MyDate birthday(14, 05, 2006);
    // w.table->setRowCount(vector.count());
    // for(int i = 0; i < vector.size(); ++i){
    //     MyDate myDate = vector.at(i);
    //     w.table->setItem(i, 0, new QTableWidgetItem(myDate.toString()));
    //     w.table->setItem(i, 1, new QTableWidgetItem(myDate.nextDay().toString()));
    //     w.table->setItem(i, 2, new QTableWidgetItem(myDate.PreviousDay().toString()));
    //     w.table->setItem(i, 3, new QTableWidgetItem(QString::number(myDate.daysBetween(current))));
    //     w.table->setItem(i, 4, new QTableWidgetItem(QString::number(myDate.daysTillBirthday(birthday))));
    // }


    // stream.flush();

    // QString fl = QFileDialog::getOpenFileName(&w,"","/home/lq-84i/QTProjects/Task_1/resources/");
    // QFile f(fl);
    // f.open(QIODevice::ReadWrite);
    // QTextStream stream(&f);
    // stream.seek(1);
    // stream.flush();
    // QString str = "12345qf7890";
    // bool ok;
    //     str.toLongLong(&ok);
    return a.exec();
}
