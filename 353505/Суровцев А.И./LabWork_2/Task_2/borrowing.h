#ifndef BORROWING_H
#define BORROWING_H
#include <QString>
class Borrowing
{
public:
    Borrowing();
    QString getIssueDate();
    QString getDueDate();
    QString getReturnDate();
    int getReaderCode();
    int getBookCode();
    void setReaderCode(int r);
    void setBookCode(int b);
    void setIssueDate(QString i);
    void setDueDate(QString d);
    void setReturnDate(QString r);
private:
    int readerCode;
    int bookCode;
    QString issueDate;
    QString dueDate;
    QString returnDate;
};

#endif // BORROWING_H
