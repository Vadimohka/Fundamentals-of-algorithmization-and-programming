#include "bookloan.h"

BookLoan::BookLoan(int readerCode, int bookCode, const QString& issueDate, const QString& dueDate,const QString& returnDate)
    : m_readerCode(readerCode), m_bookCode(bookCode), m_issueDate(issueDate), m_dueDate(dueDate),m_returnDate(returnDate) {}

BookLoan::~BookLoan() {}

