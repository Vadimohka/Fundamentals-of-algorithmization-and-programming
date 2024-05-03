#ifndef BOOKLOAN_H
#define BOOKLOAN_H
#include <QString>

class BookLoan
{
public:
    BookLoan(int readerCode, int bookCode, const QString& issueDate, const QString& dueDate,const QString& returnDate);
    ~BookLoan();


    int getReaderCode() const { return m_readerCode; }
    int getBookCode() const { return m_bookCode; }
    QString getIssueDate() const { return m_issueDate; }
    QString getDueDate() const { return m_dueDate; }
    QString getReturnDate() const { return m_returnDate; }



private:
    int m_readerCode;
    int m_bookCode;
    QString m_issueDate;
    QString m_dueDate;
    QString m_returnDate;


};

#endif // BOOKLOAN_H


