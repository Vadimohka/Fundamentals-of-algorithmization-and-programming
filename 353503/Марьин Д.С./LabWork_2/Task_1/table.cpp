#include "QtWidgets/qheaderview.h"
#include "table.h"

Table::Table():QTableWidget()
{}

void Table::updateRowSize()
{
    int tableHeight = 0;
    for (int i = 0; i < int(rowCount()); ++i)
        tableHeight += int(rowHeight(i));
    setFixedHeight(tableHeight + 25);
}

void Table::updateInfo()
{
    for (int i = 0; i < dates.size(); ++i)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(dates.at(i)->Duration((dates.size() > i + 1) ? *dates.at(i + 1) : *dates.at(0))));
        this->setItem(i,5, newItem);
    }
    this->update();
}

void Table::remove_Row(int i)
{
    this->removeRow(i - 1);
    dates.removeAt(i - 1);
    this->updateInfo();
    this->updateRowSize();
    this->update();
}

void Table::DelRow(QFile *file , int n)
{
    file->open(QIODevice::WriteOnly);
    QTextStream fileStream(file);
    for (int i = 0; i < dates.size(); ++i)
    {
        if(i != n-1 )
        fileStream << dates.at(i)->toString() <<"\n";
    }
    file->close();
}

void Table::EditRow(Date d, int n)
{
    dates[n-1] = &d;
    this->setRow(&d,n-1);
    this->updateInfo();
}

void Table::setTableInfo(QVector<Date*> p)
{
    dates = p;
    this->setColumnCount(6);
    QStringList headers;
    headers << "Given Date" << "Next Day" << "PreviousDay" << "Leap" << "WeekNumber"<< "Duration";
    this->setHorizontalHeaderLabels(headers);

    this->setStyleSheet("QTableView { gridline-color: #FFFFFF; }");

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->horizontalHeader()->setStretchLastSection(true);
    this->resizeColumnsToContents();
    this->setAlternatingRowColors(true);
    for(int i = 0; i < p.count(); ++i)
    {
        this->setRow(p.at(i),i);
    }
    this->updateRowSize();
}

void Table::setRow(Date *date,int i)
{
    if(this->rowCount()-1 < i)
        this->insertRow(i);
    QTableWidgetItem *newItem = new QTableWidgetItem(date->toString());
    this->setItem(i,0, newItem);
    Qt::ItemFlags flags = newItem->flags();
    flags = flags & ~Qt::ItemIsEditable;
    newItem->setFlags(flags);

    newItem = new QTableWidgetItem(date->NextDay().toString());
    this->setItem(i,1, newItem);
    flags = newItem->flags();
    flags = flags & ~Qt::ItemIsEditable;
    newItem->setFlags(flags);

    newItem = new QTableWidgetItem(date->PreviousDay().toString());
    this->setItem(i,2, newItem);
    flags = newItem->flags();
    flags = flags & ~Qt::ItemIsEditable;
    newItem->setFlags(flags);

    newItem = new QTableWidgetItem(date->isLeap() ? "YES" : "NO" );
    this->setItem(i,3, newItem);
    flags = newItem->flags();
    flags = flags & ~Qt::ItemIsEditable;
    newItem->setFlags(flags);

    newItem = new QTableWidgetItem(QString::number(date->WeekNumber()));
    this->setItem(i,4, newItem);
    flags = newItem->flags();
    flags = flags & ~Qt::ItemIsEditable;
    newItem->setFlags(flags);

    newItem = new QTableWidgetItem(QString::number(date->Duration((dates.size() > i + 1) ? *dates.at(i + 1) : *dates.at(0))));
    this->setItem(i,5, newItem);
    flags = newItem->flags();
    flags = flags & ~Qt::ItemIsEditable;
    newItem->setFlags(flags);
}

void Table::addRow(Date *d)
{
    dates.push_back(d);
    this->setRow(d,rowCount());
    this->updateInfo();
    if(dates.size() < 14)
    this->updateRowSize();
}
