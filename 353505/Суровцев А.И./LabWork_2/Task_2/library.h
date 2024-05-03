#ifndef LIBRARY_H
#define LIBRARY_H
#include <QVector>
#include <QDate>
#include <QFile>
#include "book.h"
#include "borrowing.h"
#include "reader.h"
class Library
{
public:
    Library();
    void addBook(const Book& book);
    void addReader(const Reader& reader);
    void addBorrowing(const Borrowing& borrowing);
    QVector<Book> getBooks();
    QVector<Reader> getReaders();
    QVector<int>getCodeReaders();
    QVector<int>getCodeBooks();

    void bubbleSortBooksByName();
    void bubbleSortBooksByTitle();
    void bubbleSortBooksByYear();
    void bubbleSortReadersByFIO();
    bool compareBooks(const QString& a, const QString& b);

    QVector<Book> getBooksByAuthor(const QString& authorName);
    QVector<Book> getBooksByTitle(const QString& bookTitle);
    bool whereThisName(const QString& fullName);
    Reader* getReadersByFullName(const QString& fullName);
    bool whereThisBook(int code);
    Book* getBookByCode(int code);
    Reader* getReaderByCode(int code);
    QVector<Book> getBooksByReader(Reader* reader);
    QVector<Borrowing> getOverdueBorrowings();

    QVector<QString> getNameOfBook();
    QVector<QString> getFIOOfReader();
    int getIndBorrowingByCodeBook(int code);
    int getIndBookByCodeBook(int code);
    int getIndReaderByCodeReader(int code);
    int getIndBorrowingByCodeReader(int code);


    void loadBooksFromFile();
    void loadReadersFromFile();
    void loadBorrowingsFromFile();
private:
    QVector <Book> books;
    QVector <Reader> readers;
    QVector <Borrowing> borrowings;
};

#endif // LIBRARY_H
