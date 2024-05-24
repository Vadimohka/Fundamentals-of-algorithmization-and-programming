#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    // Установка стилей для кнопок
    QString buttonStyle = "QPushButton {"
                          "border: 2px solid #F44708;"
                          "border-radius: 5px;"
                          "color: #FAA613;"
                          "font-size: 14px;"
                          "padding: 8px 13px;"
                          "}"
                          "QPushButton:hover {"
                          "background-color: #558C8C;"
                          "color: #E8DB7D;"
                          "}"
        ;

    ui->addBook->setStyleSheet(buttonStyle);

    ui->removeBook->setStyleSheet(buttonStyle);
    ui->findBooksByTitle->setStyleSheet(buttonStyle);
    ui->addReader->setStyleSheet(buttonStyle);
    ui->findReadersByFullName->setStyleSheet(buttonStyle);
    ui->addBookLoan->setStyleSheet(buttonStyle);
    ui->saveData->setStyleSheet(buttonStyle);
    QString labelStyle = "QLabel {"
                         "color: #F44708;"

                         "}";
    QString labelStyle2 = "QLabel {"
                          "color: #FAA613;"

                          "}";

    ui->label_17->setStyleSheet(labelStyle2);
    ui->label_18->setStyleSheet(labelStyle2);
    ui->label_19->setStyleSheet(labelStyle2);
    ui->label_21->setStyleSheet(labelStyle2);
    ui->label->setStyleSheet(labelStyle);
    ui->label_2->setStyleSheet(labelStyle);
    ui->label_3->setStyleSheet(labelStyle);
    ui->label_4->setStyleSheet(labelStyle);
    ui->label_5->setStyleSheet(labelStyle);
    ui->label_6->setStyleSheet(labelStyle);
    ui->label_7->setStyleSheet(labelStyle);
    ui->label_8->setStyleSheet(labelStyle);
    ui->label_9->setStyleSheet(labelStyle);
    ui->label_10->setStyleSheet(labelStyle);
    ui->label_11->setStyleSheet(labelStyle);
    ui->label_12->setStyleSheet(labelStyle);
    ui->label_13->setStyleSheet(labelStyle);
    ui->label_14->setStyleSheet(labelStyle);
    ui->label_15->setStyleSheet(labelStyle);
    ui->label_16->setStyleSheet(labelStyle);












}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addBook_clicked()
{
    // Получаем данные о книге из QLineEdit
    int code = ui->bookCodeLineEdit->text().toInt();
    QString author = ui->authorLineEdit->text();
    QString title = ui->titleLineEdit->text();
    QString language = ui->languageLineEdit->text();
    QString yearStr = ui->yearLineEdit->text();

    // Проверяем, что введенные данные не пусты
    if (author.isEmpty() || title.isEmpty() || language.isEmpty() || yearStr.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Пожалуйста, заполните все поля.");
        return;
    }

    // Проверяем, что год издания введен корректно как целое число
    bool ok;
    int year = yearStr.toInt(&ok);
    if (!ok || year < 1000 || year > 9999 || yearStr.length() != 4) {
        QMessageBox::critical(this, "Ошибка", "Некорректный год издания.");
        return;
    }

    // Проверяем, что код книги введен корректно
    if (code <= 0) {
        QMessageBox::critical(this, "Ошибка", "Некорректный код книги.");
        return;
    }

    // Добавляем книгу в библиотеку
    library.addBook(code, author, title, year, language);

    // Очищаем поля ввода после добавления книги
    ui->bookCodeLineEdit->clear();
    ui->authorLineEdit->clear();
    ui->titleLineEdit->clear();
    ui->yearLineEdit->clear();
    ui->languageLineEdit->clear();
    displayBookList();

}
void MainWindow::sortBooksByCode(QList<Book>& books) {
    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getCode() < b.getCode();
    });
}
void MainWindow::sortReaderByCode(QList<Reader>& redears) {
    std::sort(redears.begin(), redears.end(), [](const Reader& a, const Reader& b) {
        return a.getCode() < b.getCode();
    });
}
void MainWindow::displayBookList() {
    // Получаем список книг из библиотеки
    QList<Book> books = library.getBooks();
    sortBooksByCode(books);
    // Очищаем текущий текст в textEdit перед выводом нового списка книг
    ui->bookListTextEdit->clear();

    // Выводим каждую книгу из списка в textEdit
    for (const Book& book : books) {
        ui->bookListTextEdit->append("Code: " + QString::number(book.getCode()));
        ui->bookListTextEdit->append("Author: " + book.getAuthor());
        ui->bookListTextEdit->append("Title: " + book.getTitle());
        ui->bookListTextEdit->append("Year: " + QString::number(book.getYear()));
        ui->bookListTextEdit->append("Language: " + book.getLanguage());
        ui->bookListTextEdit->append("------------------------------------");
    }
}

void MainWindow::on_removeBook_clicked()
{
    // Получаем код книги из lineEdit
    QString codeText = ui->bookCodeLineEdit->text();
    if (codeText.isEmpty()) {
        QMessageBox::information(this, "Внимание", "Для удаления книги введите код книги");
        return;
    }

    // Проверяем, является ли введенный код числом
    bool ok;
    int code = codeText.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Неверный код. Введите число.");
        return;
    }

    // Если код введен правильно, вызываем функцию для удаления книги
    library.removeBook(code);

    // Очищаем поле ввода кода книги после удаления
    ui->bookCodeLineEdit->clear();
    // После удаления книги обновляем список книг в интерфейсе
    displayBookList();
}


void MainWindow::on_findBooksByTitle_clicked()
{
    // Получаем название книги из QLineEdit
    QString title = ui->titleLineEdit->text();

    // Если строка поиска пуста, выводим сообщение об ошибке
    if (title.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите название книги для поиска.");
        return;
    }

    // Ищем книги по названию в библиотеке
    QList<Book> books = library.findBooksByTitle(title);

    // Очищаем поле вывода результатов перед новым поиском
    ui->titleLineEdit->clear();


    if (books.isEmpty()) {
        ui->bookListTextEdit->append("Книги с названием \"" + title + "\" не найдены.");
        ui->bookListTextEdit->append("------------------------------------");
    } else {
        ui->bookListTextEdit->append("Результаты поиска по названию \"" + title + "\":");
        for (const Book& book : books) {
            ui->bookListTextEdit->append("Код: " + QString::number(book.getCode()));
            ui->bookListTextEdit->append("Автор: " + book.getAuthor());
            ui->bookListTextEdit->append("Название: " + book.getTitle());
            ui->bookListTextEdit->append("Год издания: " + QString::number(book.getYear()));
            ui->bookListTextEdit->append("Язык: " + book.getLanguage());
            ui->bookListTextEdit->append("------------------------------------");
        }
    }
}


void MainWindow::on_addReader_clicked()
{
    // Получаем данные о новом читателе из QLineEdit
    int code = ui->readerCodeLineEdit->text().toInt();
    QString fullName = ui->fullNameLineEdit->text();
    QString address = ui->addressLineEdit->text();
    QString phoneNumber = ui->phoneNumberLineEdit->text();

    // Проверяем, что данные не пусты
    if (fullName.isEmpty() || address.isEmpty() || phoneNumber.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Пожалуйста, заполните все поля.");
        return;
    }

    // Добавляем читателя в библиотеку
    Reader newReader(code, fullName, address, phoneNumber);
    library.addReader( newReader);

    // Очищаем поля ввода после добавления читателя
    ui->readerCodeLineEdit->clear();
    ui->fullNameLineEdit->clear();
    ui->addressLineEdit->clear();
    ui->phoneNumberLineEdit->clear();
    displayReaderList();
}

void MainWindow::displayReaderList() {
    // Получаем список читателей из библиотеки
    QList<Reader> readers = library.getReaders();
    sortReaderByCode(readers);
    // Очищаем текущий текст в textEdit перед выводом нового списка читателей
    ui->ReaderListTextEdit->clear();

    // Выводим каждого читателя из списка в textEdit
    for (const Reader& reader : readers) {
        ui->ReaderListTextEdit->append("Код читателя: " + QString::number(reader.getCode()));
        ui->ReaderListTextEdit->append("ФИО читателя: " + reader.getFullName());
        ui->ReaderListTextEdit->append("Адрес: " + reader.getAddress());
        ui->ReaderListTextEdit->append("Номер телефона читателя: " + reader.getPhoneNumber());
        ui->ReaderListTextEdit->append("------------------------------------");
    }
}

void MainWindow::on_findReadersByFullName_clicked()
{


    // Получаем название книги из QLineEdit
    QString Name = ui-> fullNameLineEdit->text();

    // Если строка поиска пуста, выводим сообщение об ошибке
    if (Name.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите ФИО для поиска.");
        return;
    }

    // Ищем книги по названию в библиотеке
    QList<Reader> readers = library.findReadersByFullName( Name);

    // Очищаем поле вывода результатов перед новым поиском
    ui->fullNameLineEdit->clear();


    if (readers.isEmpty()) {
        ui->ReaderListTextEdit->append(" читатель \"" + Name + "\" не найден");
        ui->ReaderListTextEdit->append("------------------------------------");
    } else {
        ui->ReaderListTextEdit->append("Результаты поиска по ФИО \"" + Name + "\":");
        for (const Reader& reader : readers) {
            ui->ReaderListTextEdit->append("Код читателя: " + QString::number(reader.getCode()));
            ui->ReaderListTextEdit->append("ФИО: " + reader.getFullName());
            ui->ReaderListTextEdit->append("Адрес: " + reader.getAddress());
            ui->ReaderListTextEdit->append("Телефон: " + reader.getPhoneNumber());
            ui->ReaderListTextEdit->append("------------------------------------");
        }
    }
}


void MainWindow::on_addBookLoan_clicked()
{
    int readerCode = ui->readerCodeLineEdit2->text().toInt();
    int bookCode = ui->bookCodeLineEdit2->text().toInt();
    QString issueDate = ui->issueDatelineEdit->text();
    QString dueDate=ui->dueDatelineEdit->text();
    QString returnDate = ui->returnDateLineEdit->text();

    // Проверяем, что введенные данные не пусты
    if (issueDate.isEmpty() || returnDate.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Пожалуйста, заполните все поля.");
        return;
    }

    // Проверяем, что читатель существует в библиотеке
    if (!library.hasReader(readerCode)) {
        QMessageBox::critical(this, "Ошибка", "Читатель с таким кодом не найден.");
        return;
    }

    // Проверяем, что книга существует в библиотеке
    if (!library.hasBook(bookCode)) {
        QMessageBox::critical(this, "Ошибка", "Книга с таким кодом не найдена.");
        return;
    }

    // Выдаем книгу читателю
    library.addBookLoan( readerCode,  bookCode,  issueDate, dueDate,  returnDate);

    // Очищаем поля ввода после выдачи книги
    ui->readerCodeLineEdit2->clear();
    ui->bookCodeLineEdit2->clear();
    ui->issueDatelineEdit->clear();
    ui->dueDatelineEdit->clear();
    ui->returnDateLineEdit->clear();
    displayOverdueBooksLoanList();
    displayBookLoanList();


}

void MainWindow::displayBookLoanList() {
    // Очищаем текущий текст в textEdit перед выводом нового списка


    // Получаем список записей о выдаче книг из библиотеки
    QList<BookLoan> loans = library.getBookLoans();
    ui->bookLoanListTextEdit->clear();
    // Выводим каждую запись о выдаче книги из списка в textEdit
    for (const BookLoan& loan : loans) {
        ui->bookLoanListTextEdit->append("Код читателя: " + QString::number(loan.getReaderCode()));
        ui->bookLoanListTextEdit->append("Код книги: " + QString::number(loan.getBookCode()));
        ui->bookLoanListTextEdit->append("Дата выдачи: " + loan.getIssueDate());
        ui->bookLoanListTextEdit->append("Требуемый срок возврата: " + loan.getDueDate());
        ui->bookLoanListTextEdit->append("Реальная дата возврата книги: " + loan.getReturnDate());
        ui->bookLoanListTextEdit->append("------------------------------------");
    }
}





void MainWindow::displayOverdueBooksLoanList() {
    // Очищаем текущий текст в textEdit перед выводом нового списка должников
    ui->overdueBookListTextEdit->clear();

    // Выводим каждую просроченную книгу из списка в textEdit
    for (const BookLoan& overdueBook : library.getOverdueBooks()) {
        ui->overdueBookListTextEdit->append("Код читателя: " + QString::number(overdueBook.getReaderCode()));
        ui->overdueBookListTextEdit->append("Код книги: " + QString::number(overdueBook.getBookCode()));
        ui->overdueBookListTextEdit->append("Дата выдачи: " + overdueBook.getIssueDate());
        ui->overdueBookListTextEdit->append("Требуемый срок возврата: " + overdueBook.getDueDate());
        ui->overdueBookListTextEdit->append("Реальная дата возврата книги: " + overdueBook.getReturnDate());
        ui->overdueBookListTextEdit->append("------------------------------------");
    }
}





void MainWindow::on_saveData_clicked()
{
    // Формируем путь к файлу "Library.txt" в папке "Downloads" домашней директории пользователя
    QString filePath = QDir::homePath() + "/Downloads/Library.txt";

    // Получаем списки книг, читателей, выдачи книг и просроченных книг из библиотеки
    QList<Book> books = library.getBooks();
    QList<Reader> readers = library.getReaders();
    QList<BookLoan> bookLoans = library.getBookLoans();
    QList<BookLoan> overdueBooks = library.getOverdueBooks();

    // Вызываем функцию записи данных в файл
    library.writeDataToFile(books, readers, bookLoans, overdueBooks, filePath);

    // Выводим сообщение об успешном сохранении
    QMessageBox::information(this, "Информация", "Данные успешно сохранены в файл Library.txt в папке Downloads.");
}
void MainWindow::closeEvent(QCloseEvent *event) {
    // Формируем путь к файлу "Library.txt" в папке "Downloads" домашней директории пользователя
    QString filePath = QDir::homePath() + "/Downloads/Library.txt";

    // Удаляем файл
    QFile file(filePath);
    file.remove();

    // Вызываем базовую реализацию метода closeEvent для закрытия приложения
    QMainWindow::closeEvent(event);
}
