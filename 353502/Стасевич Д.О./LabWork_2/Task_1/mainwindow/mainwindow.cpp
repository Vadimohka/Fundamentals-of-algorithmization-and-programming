#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>

#include <QDebug>

using namespace std;

mainwindow::mainwindow(): ui(new Ui::mainwindow), scene (new QGraphicsScene(this)) {

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    connect(ui->closeButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->previousDayButton, SIGNAL(clicked(bool)), this, SLOT(onPrevious_clicked()));
    connect(ui->isLeapButton, SIGNAL(clicked(bool)), this, SLOT(isLeap_clicked()));
    connect(ui->weekNumberButton, SIGNAL(clicked(bool)), this, SLOT(weekNumber_clicked()));
    connect(ui->birthdayButton, SIGNAL(clicked()), this, SLOT(whenBirthday_clicked()));
    connect(ui->durationButton, SIGNAL(clicked()), this, SLOT(duration_clicked()));
    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(addData_clicked()));
    connect(ui->changeButton, SIGNAL(clicked()), this, SLOT(changeData_clicked()));
    connect(ui->addBirthdayButton, SIGNAL(clicked(bool)), this, SLOT(addbirthday_clicked()));
    connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(oncell_clicked(int,int)));
    connect(ui->openButton, SIGNAL(clicked()), this, SLOT(openFile()));


    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void mainwindow::openFile() {
    if(open)
        return;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Text files (*.txt)"));
    fileRem = fileName;
    if(fileName.size() == 0)
    {
        QMessageBox message;
        message.setText("Can't open file");
        message.exec();
        return;
    }
    file.setFileName(fileName);
    file.open(QIODevice::ReadWrite);
    QTextStream fileLine(&file);

    QString s;
    int line = 0;
    while(!fileLine.atEnd())
    {
        s = fileLine.readLine();
        try
        {
            Date add = Date::StringToDate(s);
            date.push_back(add);
        }
        catch(...)
        {
            QMessageBox message;
            QString l = QString::number(line);
            message.setText("Incorrect data in file in line " + l);
            message.exec();
            date.clear();
            return;
        }
        line ++;
    }
    open = true;
    file.close();
    ShowTable();

}

void mainwindow::onPrevious_clicked() {
    QString s;
    for(int i = 0; i < date.size(); i ++)
    {
        auto x = date[i];
        try
        {
            Date d = x.PreviousDay();
            s = Date::DayToString(d);
        }
        catch(const char* error_message)
        {
            s = error_message;
        }
        model->setData(model->index(i, 3), s);
    }
}

void mainwindow::isLeap_clicked() {
    QString s;
    for(int i = 0; i < date.size(); i ++)
    {
        auto x = date[i];
        try
        {
            bool d = x.IsLeap();
            s = QString::number(d);
        }
        catch(const char* error_message)
        {
            s = error_message;
        }
        model->setData(model->index(i, 3), s);
    }

}

void mainwindow::weekNumber_clicked() {
    QString s;
    for(int i = 0; i < date.size(); i ++)
    {
        auto x = date[i];
        try
        {
            short d = Date::WeekNumber(x);
            s = QString::number(d);
        }
        catch(const char* error_message)
        {
            s = error_message;
        }
        model->setData(model->index(i, 3), s);
    }
}

void mainwindow::whenBirthday_clicked() {
    QString s;
    if(birthdayDay.empty())
    {
        ui->labelDaysTillBirthday->setText(":(");
        return;
    }
    try
    {
        int d = birthdayDay[0].DaysTillYourBirthday(birthdayDay[0]);
        s = QString::number(d);
    }
    catch(const char* error_message)
    {
        s = ":(";
    }
    ui->labelDaysTillBirthday->setText(s);
}

void mainwindow::duration_clicked() {
    QString s;
    for(int i = 0; i < date.size(); i ++)
    {
        auto x = date[i];
        try
        {
            int d = Date::Duration(x);
            s = QString::number(d);
        }
        catch(const char* error_message)
        {
            s = error_message;
        }
        model->setData(model->index(i, 3), s);
    }
}

void mainwindow::addData_clicked() {
    if(!open)
        return;
    QString str;
    QString t = QString::number(ui->dateEdit->date().day());
    if(t.size() == 1)
        str += "0";
    str += t;
    str += ".";
    t = QString::number(ui->dateEdit->date().month());
    if(t.size() == 1)
        str += "0";
    str += t;
    str += ".";
    t = QString::number(ui->dateEdit->date().year());
    int add = 4 - t.size();
    while(add --)
        str += "0";
    str += t;
    auto x = Date::StringToDate(str);
    date.push_back(x);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    QString s = Date::DayToString(x);
    model = ui->tableWidget->model();
    model->setData(model->index(date.size() - 1,0),s);
    try
    {
        Date d = x.NextDay();
        s = Date::DayToString(d);
        file.setFileName(fileRem);
        file.open(QIODevice::Append);
        QTextStream fileLine(&file);
        fileLine << "\n" << Date::DayToString(x);
        file.close();

    }
    catch(const char* error_message) {
        s = error_message;
    }
    model->setData(model->index(date.size() - 1, 1), s);
    if(date.size() - 1 - 1 >= 0)
        s = QString::number(Date::Duration(date[date.size() - 1 - 1], date[date.size() - 1]));
    else
        s = "-";
    model->setData(model->index(date.size() - 1, 2), s);

}

void mainwindow::changeData_clicked() {
    if(!open)
        return;
    if(raw == -1)
        return;
    QString str;
    QString t = QString::number(ui->dateEdit->date().day());
    if(t.size() == 1)
        str += "0";
    str += t;
    str += ".";
    t = QString::number(ui->dateEdit->date().month());
    if(t.size() == 1)
        str += "0";
    str += t;
    str += ".";
    t = QString::number(ui->dateEdit->date().year());
    int add = 4 - t.size();
    while(add --)
        str += "0";
    str += t;
    auto x = Date::StringToDate(str);
    date[raw] = x;
    int i = raw;
    QString s = Date::DayToString(x);
    model = ui->tableWidget->model();
    model->setData(model->index(i,0),s);
    try
    {
        Date d = x.NextDay();
        s = Date::DayToString(d);
        file.setFileName(fileRem);
        file.open(QIODevice::ReadWrite);
        qint64 pos = raw * 11;
        file.seek(pos);
        QTextStream fileLine(&file);
        fileLine << Date::DayToString(x) << "\n";
        file.close();
    }
    catch(const char* error_message)
    {
        s = error_message;
    }

    model->setData(model->index(i, 1), s);
    if(i - 1 >= 0)
        s = QString::number(Date::Duration(date[i - 1], date[i]));
    else
        s = "-";
    model->setData(model->index(i, 2), s);
}

void mainwindow::addbirthday_clicked() {

    QString str;
    QString t = QString::number(ui->dateBirthdayEdit->date().day());
    if(t.size() == 1)
        str += "0";
    str += t;
    str += ".";
    t = QString::number(ui->dateBirthdayEdit->date().month());
    if(t.size() == 1)
        str += "0";
    str += t;
    str += ".";
    t = QString::number(ui->dateBirthdayEdit->date().year());
    int add = 4 - t.size();
    while(add --)
        str += "0";
    str += t;
    auto x = Date::StringToDate(str);
    qDebug() << "k";
    qDebug() << "k";

    QString s = Date::DayToString(x);
   // s = "abaabaabaabaabaaba";
    qDebug() << "k";

    birthdayDay.clear();
    birthdayDay.push_back(x);
    qDebug() << "k";

    ui->labelBirthday->setText(s);
    qDebug() << "k";

}

void mainwindow::oncell_clicked(int row, int column) {
    raw = row;
}

void mainwindow::ShowTable() {
    for (int i = 0; i < date.size(); i++) {
        auto x = date[i];
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        QString s = Date::DayToString(x);
        model = ui->tableWidget->model();
        model->setData(model->index(i, 0), s);
        try {
            Date d = x.NextDay();
            s = Date::DayToString(d);
        }
        catch (const char *error_message) {
            s = error_message;
        }
        model->setData(model->index(i, 1), s);
        if (i - 1 >= 0)
            s = QString::number(Date::Duration(date[i - 1], date[i]));
        else
            s = "-";
        model->setData(model->index(i, 2), s);
    }
}