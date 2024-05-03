#ifndef LIBRARY_H
#define LIBRARY_H


#include "book.h"
#include "bookloan.h"
#include "reader.h"
#include <QList>

class Library {
public:


    void addBook(int code, const QString& author, const QString& title, int year, const QString& language);
     void removeBook(int code);
    QList<Book> findBooksByTitle(const QString& title);
      QList<Reader> findReadersByFullName(const QString& fullName);
    QList<Book> getBooks() const {
        return m_books;
    }
    QList<Reader>  getReaders(){

        return m_readers;
    }
     QList<BookLoan> getBookLoans() const {
         return m_bookLoans;
     }
     QList<BookLoan> getOverdueBooks()const{
         return m_overdueBooks;
     }
    void addReader(const Reader& reader);
     bool hasBook(int code) const;
      bool hasReader(int code) const;
     void addBookLoan(int readerCode, int bookCode, const QString& issueDate,const QString& dueDate, const QString& returnDate);
      void writeDataToFile(const QList<Book>& books, const QList<Reader>& readers, const QList<BookLoan>& bookLoans, const QList<BookLoan>& overdueBooks, const QString& fileName);


private:
    QList<Book> m_books;
   QList<Reader> m_readers;
    QList<BookLoan> m_bookLoans;
   QList<BookLoan> m_overdueBooks;
};

#endif // LIBRARY_H
