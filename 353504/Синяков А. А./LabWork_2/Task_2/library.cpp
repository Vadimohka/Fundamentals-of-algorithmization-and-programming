#include "library.h"
#include <QMessageBox>
#include <QDate>
#include <QFile>
#include <QTextStream>
void Library::addBook(int code, const QString& author, const QString& title, int year, const QString& language) {
    Book newBook(code, author, title, year, language);
    m_books.append(newBook);
}

void Library::removeBook(int code) {
    // Итерируем по списку книг
    for (auto it = m_books.begin(); it != m_books.end(); ++it) {
        // Если найден код книги, удаляем книгу из списка
        if (it->getCode() == code) {
            it = m_books.erase(it);
            return; // После удаления книги прекращаем выполнение метода
        }
    }
}
QList<Book> Library::findBooksByTitle(const QString& title)
{
    QList<Book> result;

    // Ищем книги с заданным названием
    for (const Book& book : m_books) {
        if (book.getTitle() == title) {
            result.append(book);
        }
    }

    return result;
}

void Library::addReader(const Reader& reader) {

    m_readers.append(reader);
}
QList<Reader> Library::findReadersByFullName(const QString& fullName) {
    QList<Reader> foundReaders;
    // Пройти по списку читателей
    for (const Reader& reader : m_readers) {
        // Проверить, содержит ли ФИО читателя заданное полное имя
        if (reader.getFullName() == fullName) {
            foundReaders.append(reader); // Добавить читателя в список найденных
        }
    }
    return foundReaders;
}

// Метод проверки наличия читателя по коду
bool Library::hasReader(int code) const {
    for (const auto& reader : m_readers) {
        if (reader.getCode() == code) {
            return true;
        }
    }
    return false;
}
// Метод проверки наличия книги по коду
bool Library::hasBook(int code) const {
    for (const auto& book : m_books) {
        if (book.getCode() == code) {
            return true;
        }
    }
    return false;
}
// Метод добавления записи о выдаче книги читателю
void Library::addBookLoan(int readerCode, int bookCode, const QString& issueDate,const QString& dueDate, const QString& returnDate) {
    // Проверяем, что читатель существует в библиотеке
    if (!hasReader(readerCode)) {
        QMessageBox::critical(nullptr, "Ошибка", "Книга с кодом " + QString::number(bookCode) + " не найдена в библиотеке");

        return;
    }

    // Проверяем, что книга существует в библиотеке
    if (!hasBook(bookCode)) {
        QMessageBox::critical(nullptr, "Ошибка", "Книга с кодом " + QString::number(bookCode) + " не найдена в библиотеке");

        return;
    }
    // Проверяем корректность введенных дат
    QDate issueDt = QDate::fromString(issueDate, "dd.MM.yyyy");
    QDate dueDt = QDate::fromString(dueDate, "dd.MM.yyyy");
    QDate returnDt = QDate::fromString(returnDate, "dd.MM.yyyy");

    if (!issueDt.isValid() || !dueDt.isValid() || !returnDt.isValid()) {
        QMessageBox::critical(nullptr, "Ошибка", "Одна из дат введена некорректно");
        return;
    }

    if (returnDt < issueDt) {
        QMessageBox::critical(nullptr, "Ошибка", "Дата возврата не может быть раньше даты выдачи");
        return;
    }
    // Добавляем запись о выдаче книги
    BookLoan newLoan(readerCode, bookCode, issueDate,dueDate, returnDate);
    m_bookLoans.append(newLoan);

    // Вычисляем разницу в днях между реальной и требуемой датами возврата
    int daysOverdue = dueDt.daysTo(returnDt);

    // Проверяем, превышает ли разница 10 дней
    if (daysOverdue > 10) {
        QMessageBox::critical(nullptr, "Ошибка", "Книга просрочена более чем на 10 дней");

        // Найдем запись о выдаче книги
        for (auto& loan : m_bookLoans) {
            if (loan.getReaderCode() == readerCode && loan.getBookCode() == bookCode && loan.getIssueDate() == issueDate && loan.getDueDate() == dueDate && loan.getReturnDate() == returnDate) {
                // Добавляем просроченную книгу в список должников
                m_overdueBooks.append(loan);
                break;
            }
        }


        return ;
    }

}



void Library::writeDataToFile(const QList<Book>& books, const QList<Reader>& readers, const QList<BookLoan>& bookLoans, const QList<BookLoan>& overdueBooks, const QString& fileName) {
    // Создаем объект для работы с файлом
    QFile file(fileName);

    // Пытаемся открыть файл в режиме записи
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл для записи";
        return;
    }

    // Создаем объект для записи текста в файл
    QTextStream out(&file);

    // Записываем информацию о книгах
    out << "=== Список книг ===\n";
    for (const Book& book : books) {
        out << "Код: " << book.getCode() << "\n";
        out << "Автор: " << book.getAuthor() << "\n";
        out << "Название: " << book.getTitle() << "\n";
        out << "Год издания: " << book.getYear() << "\n";
        out << "Язык: " << book.getLanguage() << "\n\n";
    }

    // Записываем информацию о читателях
    out << "=== Список читателей ===\n";
    // Записываем информацию о читателях в файл
    for (const Reader& reader : readers) {
        out << "Код читателя: " << reader.getCode() << "\n";
        out << "ФИО читателя: " << reader.getFullName() << "\n";
        out << "Адрес: " << reader.getAddress() << "\n";
        out << "Номер телефона читателя: " << reader.getPhoneNumber() << "\n\n";
    }

    // Записываем информацию о выдаче книг
    out << "=== Список выдачи книг ===\n";
    for (const BookLoan& loan : bookLoans) {
        out << "Код читателя: " << loan.getReaderCode() << "\n";
        out << "Код книги: " << loan.getBookCode() << "\n";
        out << "Дата выдачи: " << loan.getIssueDate() << "\n";
        out << "Требуемый срок возврата: " << loan.getDueDate() << "\n";
        out << "Реальная дата возврата: " << loan.getReturnDate() << "\n\n";
    }

    // Записываем информацию о просроченных книгах
    out << "=== Список просроченных книг ===\n";
    for (const BookLoan& overdueBook : overdueBooks) {
        out << "Код читателя: " << overdueBook.getReaderCode() << "\n";
        out << "Код книги: " << overdueBook.getBookCode() << "\n";
        out << "Дата выдачи: " << overdueBook.getIssueDate() << "\n";
        out << "Требуемый срок возврата: " << overdueBook.getDueDate() << "\n";
        out << "Реальная дата возврата: " << overdueBook.getReturnDate() << "\n\n";
    }

    // Закрываем файл после записи
    file.close();
}

