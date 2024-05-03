#include "table.h"
#include "QtWidgets/qheaderview.h"

static bool Comp_year (Book* a, Book* b)
{
    return (a->getYear() < b->getYear());
}
static bool Comp_publ (Book* a, Book* b)
{
    return (a->getPublisher() < b->getPublisher());
}
Table::Table(QTableWidget *table)
{
    this->table = table;
}

void Table::setTableInfo(QVector<Book*> b)
{
    library = b;
    table->setColumnCount(5);
    QStringList headers;
    headers << "AUTHOR" << "TITLE" << "PUBLISHER" << "YEAR" << "PAGES";
    table->setHorizontalHeaderLabels(headers);

    table->setStyleSheet("QTableView { gridline-color: #FFFFFF; }");

    table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    table->resizeColumnsToContents();
    table->resizeRowsToContents();

    table->horizontalHeader()->setStretchLastSection(true);
    table->resizeColumnsToContents();
    table->setAlternatingRowColors(true);
    for(int i = 0; i < b.count(); ++i)
    {
        this->setRow(b.at(i),i);
    }
    this->updateRowSize();
    table->setColumnWidth(0,100);
    table->setColumnWidth(1,150);
    table->setColumnWidth(2,150);
    table->setColumnWidth(3,50);
}

void Table::setRow(Book *book, int n)
{
     if(table->rowCount()-1 < n)
    table->insertRow(n);
    QTableWidgetItem *newItem = new QTableWidgetItem(book->getAuthor());
    table->setItem(n,0, newItem);
    Qt::ItemFlags flags = newItem->flags();
    flags = flags & ~Qt::ItemIsEditable;
    newItem->setFlags(flags);

    newItem = new QTableWidgetItem(book->getTitle());
    table->setItem(n,1, newItem);
    flags = newItem->flags();
    flags = flags & ~Qt::ItemIsEditable;
    newItem->setFlags(flags);

    newItem = new QTableWidgetItem(book->getPublisher());
    table->setItem(n,2, newItem);
    flags = newItem->flags();
    flags = flags & ~Qt::ItemIsEditable;
    newItem->setFlags(flags);

    newItem = new QTableWidgetItem(QString::number(book->getYear()));
    table->setItem(n,3, newItem);
    flags = newItem->flags();
    flags = flags & ~Qt::ItemIsEditable;
    newItem->setFlags(flags);

    newItem = new QTableWidgetItem(QString::number(book->getPages()));
    table->setItem(n,4, newItem);
    flags = newItem->flags();
    flags = flags & ~Qt::ItemIsEditable;
    newItem->setFlags(flags);
}

void Table::updateRowSize()
{
    int tableHeight = 0;
    for (int i = 0; i < int(table->rowCount()); ++i)
        tableHeight += int(table->rowHeight(i));
    table->setFixedHeight(tableHeight + 25);
}

void Table::SortByYear()
{
    std::sort(library.begin(),library.end(),Comp_year);
    updateInfo();
}

void Table::SortByPublisher()
{
    std::sort(library.begin(),library.end(),Comp_publ);
    updateInfo();
}

void Table::addRow(QFile* file,Book *book)
{
    library.push_back(book);
    this->setRow(book,table->rowCount());
    if(library.size() < 14)
        this->updateRowSize();
    file->open(QIODevice::ReadWrite);
    QString str;
    QTextStream fileStream(file);
    fileStream.seek((table->rowCount()) * (3 * sizeof(QString) + 2 * sizeof(int) + 5 * sizeof(char)));
    fileStream << book->toString();
    file->close();
}

void Table::updateInfo()
{
    for (int i = 0; i < library.count(); ++i)
    {
        setRow(library.at(i),i);
    }
}

void Table::ShowNecessary(QString name)
{
    table->clear();
    for (int i = 0; i < library.count(); ++i)
    {
        if(library.at(i)->getTitle().contains(name))
            setRow(library.at(i),i);
    }

}

 void Table::DelRow(QFile* file, int n)
{
     table->removeRow(n - 1);
     library.removeAt(n - 1);
     this->updateRowSize();
     file->open(QIODevice::WriteOnly);
     QTextStream fileStream(file);
     for (int i = 0; i < library.size(); ++i)
     {
         if(i != n-1 )
             fileStream << library.at(i)->toString();
     }
     file->close();
}
