#include "borrowing.h"

Borrowing::Borrowing() {}

QString Borrowing::getIssueDate()
{
    return issueDate;
}

QString Borrowing::getDueDate()
{
    return dueDate;
}

QString Borrowing::getReturnDate()
{
    return returnDate;
}

int Borrowing::getReaderCode()
{
    return readerCode;
}

int Borrowing::getBookCode()
{
    return bookCode;
}

void Borrowing::setReaderCode(int r)
{
    readerCode = r;
}

void Borrowing::setBookCode(int b)
{
    bookCode = b;
}

void Borrowing::setIssueDate(QString i)
{
    issueDate = i;
}

void Borrowing::setDueDate(QString d)
{
    dueDate = d;
}

void Borrowing::setReturnDate(QString r)
{
    returnDate = r;
}
