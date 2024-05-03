#include "library.h"

Library::Library() {}

void Library::addBook(const Book &book)
{
    books.append(book);
}

void Library::addReader(const Reader &reader)
{
    readers.append(reader);
}

void Library::addBorrowing(const Borrowing &borrowing)
{
    borrowings.append(borrowing);
}

QVector<Book> Library::getBooks()
{
    return books;
}

QVector<Reader> Library::getReaders()
{
    return readers;
}

QVector<int> Library::getCodeReaders()
{
    QVector<int>ans;
    for (Reader& reader : readers) {
        ans.push_back(reader.getCode());
    }
    return ans;
}

QVector<int> Library::getCodeBooks()
{
    QVector<int>ans;
    for (Book& book : books) {
        ans.push_back(book.getCode());
    }
    return ans;
}

void Library::bubbleSortBooksByName()
{
    for (int i = 0; i < books.size() - 1; ++i) {
        for (int j = 0; j < books.size() - i - 1; ++j) {
            if (!compareBooks(books[j].getAuthor(), books[j + 1].getAuthor())) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void Library::bubbleSortBooksByTitle()
{
    for (int i = 0; i < books.size() - 1; ++i) {
        for (int j = 0; j < books.size() - i - 1; ++j) {
            if (!compareBooks(books[j].getTitle(), books[j + 1].getTitle())) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void Library::bubbleSortBooksByYear()
{
    for (int i = 0; i < books.size() - 1; ++i) {
        for (int j = 0; j < books.size() - i - 1; ++j) {
            if (books[j].getYear() > books[j + 1].getYear()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void Library::bubbleSortReadersByFIO()
{
    for (int i = 0; i < readers.size() - 1; ++i) {
        for (int j = 0; j < readers.size() - i - 1; ++j) {
            if (!compareBooks(readers[j].getFullName(), readers[j + 1].getFullName())) {
                Reader temp = readers[j];
                readers[j] = readers[j + 1];
                readers[j + 1] = temp;
            }
        }
    }
}

bool Library::compareBooks(const QString &a, const QString &b)
{
    QString strA = a.toLower();
    QString strB = b.toLower();
    QString russianAlphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    int minLen = qMin(strA.length(), strB.length());
    for (int i = 0; i < minLen; ++i) {
        QChar charA = strA[i];
        QChar charB = strB[i];
        int indexA = russianAlphabet.indexOf(charA);
        int indexB = russianAlphabet.indexOf(charB);
        if (indexA != -1 && indexB != -1) {
            if (indexA < indexB) {
                return true;
            } else if (indexA > indexB) {
                return false;
            }
        } else if (charA != charB) {
            return charA < charB;
        }
    }
    return strA.length() < strB.length();
}

QVector<Book> Library::getBooksByAuthor(const QString &authorName)
{
    QVector<Book>BooksByAuthor;
    for (Book& book : books) {
        if (book.getAuthor() == authorName) BooksByAuthor.append(book);
    }
    return BooksByAuthor;
}

QVector<Book> Library::getBooksByTitle(const QString &bookTitle)
{
    QVector<Book> BooksByTitle;
    for (Book& book : books) {
        if (book.getTitle() == bookTitle) BooksByTitle.append(book);
    }
    return BooksByTitle;
}

bool Library::whereThisName(const QString &fullName)
{
    for (Reader& reader : readers) {
        if (reader.getFullName() == fullName) return true;
    }
    return false;
}

Reader* Library::getReadersByFullName(const QString &fullName)
{
    for (Reader& reader : readers) {
        if (reader.getFullName() == fullName) return &reader;
    }
    return nullptr;
}

bool Library::whereThisBook(int code)
{
    for (Book& book : books) {
        if (book.getCode() == code) return true;
    }
    return false;
}

Book* Library::getBookByCode(int code)
{
    for (Book& book : books) {
        if (book.getCode() == code) return &book;
    }
    return nullptr;
}

Reader* Library::getReaderByCode(int code)
{
    for (Reader& reader : readers) {
        if (reader.getCode() == code) return &reader;
    }
    return nullptr;
}

QVector<Book> Library::getBooksByReader(Reader* reader)
{
    QVector<Book>BooksByReader;
    for (Borrowing& borrowing : borrowings) {
        if (borrowing.getReaderCode() == reader->getCode()) {
            if (whereThisBook(borrowing.getBookCode())) BooksByReader.append(*getBookByCode(borrowing.getBookCode()));
        }
    }
    return BooksByReader;
}

QVector<Borrowing> Library::getOverdueBorrowings()
{
    QVector<Borrowing> overdueBorrowings;

    for (Borrowing& borrowing : borrowings) {
        QDate dueDate = QDate::fromString(borrowing.getDueDate(), "dd.MM.yyyy");
        QDate returnDate = QDate::fromString(borrowing.getReturnDate(), "dd.MM.yyyy");
        if (returnDate > dueDate.addDays(10)) {
            overdueBorrowings.append(borrowing);
        }
    }

    return overdueBorrowings;
}

QVector<QString> Library::getNameOfBook()
{
    QVector<QString> ans;
    for (Book& book : books) {
        ans.push_back(book.getTitle());
    }
    return ans;
}

QVector<QString> Library::getFIOOfReader()
{
    QVector<QString> ans;
    for (Reader& reader : readers) {
        ans.push_back(reader.getFullName());
    }
    return ans;
}

int Library::getIndBorrowingByCodeBook(int code)
{
    for (int i = 0; i < borrowings.size(); ++i) {
        if (borrowings[i].getBookCode() == code) return i;
    }
    return -1;
}

int Library::getIndBookByCodeBook(int code)
{
    for (int i = 0; i < books.size(); ++i) {
        if (books[i].getCode() == code) return i;
    }
    return -1;
}

int Library::getIndReaderByCodeReader(int code)
{
    for (int i = 0; i < readers.size(); ++i) {
        if (readers[i].getCode() == code) return i;
    }
    return -1;
}

int Library::getIndBorrowingByCodeReader(int code)
{
    for (int i = 0; i < borrowings.size(); ++i) {
        if (borrowings[i].getReaderCode() == code) return i;
    }
    return -1;
}


void Library::loadBooksFromFile()
{
    QFile file("/home/fort3mio/Downloads/Labs_qt/second_lab/second_task/book_file.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the file for reading.";
        return;
    }
    QTextStream in(&file);
    books.clear();
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(';');
        if (parts.size() != 5) {
            qDebug() << "Invalid line format: " << line;
            continue;
        }
        bool ok;
        int code = parts[0].toInt(&ok);
        if (!ok) {
            qDebug() << "Invalid code: " << parts[0];
            continue;
        }
        QString author = parts[1];
        QString title = parts[2];
        int year = parts[3].toInt(&ok);
        if (!ok) {
            qDebug() << "Invalid year: " << parts[3];
            continue;
        }
        QString language = parts[4];
        Book book;
        book.setCode(code);
        book.setAuthor(author);
        book.setTitle(title);
        book.setYear(year);
        book.setLanguage(language);
        books.append(book);
    }

    file.close();
}

void Library::loadReadersFromFile()
{
    QFile file("/home/fort3mio/Downloads/Labs_qt/second_lab/second_task/reader_file.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);
    readers.clear();
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(';');
        if (parts.size() != 4) {
            continue;
        }
        bool ok;
        int code = parts[0].toInt(&ok);
        if (!ok) {
            continue;
        }
        QString fullName = parts[1];
        QString address = parts[2];
        QString phoneNumber = parts[3];
        Reader reader;
        reader.setCode(code);
        reader.setFullName(fullName);
        reader.setAddress(address);
        reader.setPhoneNumber(phoneNumber);
        readers.append(reader);
    }

    file.close();
}

void Library::loadBorrowingsFromFile()
{
    QFile file("/home/fort3mio/Downloads/Labs_qt/second_lab/second_task/borrowing_file.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the file for reading.";
        return;
    }
    borrowings.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(';');
        if (parts.size() != 5) {
            qDebug() << "Invalid line format: " << line;
            continue;
        }
        bool ok;
        int readerCode = parts[0].toInt(&ok);
        if (!ok) {
            qDebug() << "Invalid reader code: " << parts[0];
            continue;
        }
        int bookCode = parts[1].toInt(&ok);
        if (!ok) {
            qDebug() << "Invalid book code: " << parts[1];
            continue;
        }
        QString issueDate = parts[2];
        QString dueDate = parts[3];
        QString returnDate = parts[4];
        Borrowing borrowing;
        borrowing.setReaderCode(readerCode);
        borrowing.setBookCode(bookCode);
        borrowing.setIssueDate(issueDate);
        borrowing.setDueDate(dueDate);
        borrowing.setReturnDate(returnDate);
        borrowings.append(borrowing);
    }
    file.close();
}
