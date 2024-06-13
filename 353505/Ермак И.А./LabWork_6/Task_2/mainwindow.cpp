#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonEnterParagraph, &QPushButton::clicked, this, &MainWindow::enterParagraph);
    connect(ui->buttonReadParagraph, &QPushButton::clicked, this, &MainWindow::readParagraph);
    connect(ui->buttonSaveArray, &QPushButton::clicked, this, &MainWindow::saveArray);
    connect(ui->buttonReadArray, &QPushButton::clicked, this, &MainWindow::readArray);
    connect(ui->buttonSaveStruct, &QPushButton::clicked, this, &MainWindow::saveStructToText);
    connect(ui->buttonReadStruct, &QPushButton::clicked, this, &MainWindow::readStructFromText);
    connect(ui->buttonSaveStructBinary, &QPushButton::clicked, this, &MainWindow::saveStructToBinary);
    connect(ui->buttonReadStructBinary, &QPushButton::clicked, this, &MainWindow::readStructFromBinary);
    connect(ui->buttonSaveSentence, &QPushButton::clicked, this, &MainWindow::saveSentence);
    connect(ui->buttonReadSentences, &QPushButton::clicked, this, &MainWindow::readSentences);
    connect(ui->buttonExit, &QPushButton::clicked, this, &MainWindow::exitApplication);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterParagraph()
{
    bool ok;
    QString text = QInputDialog::getMultiLineText(this, "Введите текст", "Текст:", "", &ok);
    if (ok && !text.isEmpty()) {
        QFile file("ЕрмакЛаб09.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out.setEncoding(QStringConverter::Utf8);
            for (const QChar &ch : text) {
                out << ch;
            }
            file.close();
            QMessageBox::information(this, "Успех", "Текст сохранен.");
        } else {
            QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла.");
        }
    }
}

void MainWindow::readParagraph()
{
    QFile file("ЕрмакЛаб09.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        in.setEncoding(QStringConverter::Utf8);
        QString text;
        in >> text;
        file.close();
        QMessageBox::information(this, "Чтение текста", text);
    } else {
        QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла.");
    }
}

void MainWindow::saveArray()
{
    bool ok;
    int size = QInputDialog::getInt(this, "Размер массива", "Введите размер массива:", 0, 0, 100, 1, &ok);
    if (ok) {
        int* array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = QInputDialog::getInt(this, "Элементы массива", QString("Введите элемент %1:").arg(i+1), 0, -2147483648, 2147483647, 1, &ok);
            if (!ok) {
                delete[] array;
                return;
            }
        }
        QFile file("ФамилияЛаб20_0.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            for (int i = 0; i < size; ++i) {
                out << array[i];
                if (i < size - 1) out << '\'';
            }
            file.close();
            delete[] array;
            QMessageBox::information(this, "Успех", "Массива сохранен.");
        } else {
            QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла.");
            delete[] array;
        }
    }
}

void MainWindow::readArray()
{
    QFile file("ЕрмакЛаб09_0.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString text = in.readAll();
        QStringList elements = text.split('\'');
        QString output;
        for (const QString &element : elements) {
            output += element + " ";
        }
        file.close();
        QMessageBox::information(this, "Чтение массива", output.trimmed());
    } else {
        QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла.");
    }
}

void MainWindow::saveStructToText()
{
    Movie movie;
    bool ok;

    movie.id = QInputDialog::getInt(this, "ID фильма", "Введите ID фильма:", 0, -2147483648, 2147483647, 1, &ok);
    if (!ok) return;

    movie.rating = QInputDialog::getDouble(this, "Рейтинг фильма", "Введите рейтинг фильма:", 0, -1e9, 1e9, 1, &ok);
    if (!ok) return;

    QString genre = QInputDialog::getText(this, "Жанр", "Введите жанр фильма (один символ):", QLineEdit::Normal, "", &ok);
    if (!ok || genre.isEmpty()) return;
    movie.genre = genre.at(0).toLatin1();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Доступность", "Фильм доступен?",
                                  QMessageBox::Yes | QMessageBox::No);
    movie.isAvailable = (reply == QMessageBox::Yes);

    QString title = QInputDialog::getText(this, "Название фильма", "Введите название фильма:", QLineEdit::Normal, "", &ok);
    if (!ok || title.isEmpty()) return;
    strncpy(movie.title, title.toUtf8().constData(), Movie::TITLE_SIZE);

    QFile file("ЕрмакЛаб09_1.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream out(&file);
        out << movie.id << "|" << movie.rating << "|" << movie.genre << "|" << movie.isAvailable << "|" << movie.title << "\n";
        file.close();
        QMessageBox::information(this, "Успех", "Фильма сохранен.");
    } else {
        QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла.");
    }
}

void MainWindow::readStructFromText()
{
    QFile file("ЕрмакЛаб09_1.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QStringList movies;
        while (!in.atEnd()) {
            QString line = in.readLine();
            movies.append(line);
        }
        file.close();
        QString output;
        for (const QString &movie : movies) {
            output += movie + "\n";
        }
        QMessageBox::information(this, "Фильмы", output);
    } else {
        QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла.");
    }
}

void MainWindow::saveStructToBinary()
{
    Movie movie;
    bool ok;

    movie.id = QInputDialog::getInt(this, "ID фильма", "Введите ID фильма:", 0, -2147483648, 2147483647, 1, &ok);
    if (!ok) return;

    movie.rating = QInputDialog::getDouble(this, "Рейтинг фильма", "Введите рейтинг фильма:", 0, -1e9, 1e9, 1, &ok);
    if (!ok) return;

    QString genre = QInputDialog::getText(this, "Жанр", "Введите жанр фильма (один символ):", QLineEdit::Normal, "", &ok);
    if (!ok || genre.isEmpty()) return;
    movie.genre = genre.at(0).toLatin1();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Доступность", "Фильм доступен?",
                                  QMessageBox::Yes | QMessageBox::No);
    movie.isAvailable = (reply == QMessageBox::Yes);

    QString title = QInputDialog::getText(this, "Название фильма", "Введите название фильма:", QLineEdit::Normal, "", &ok);
    if (!ok || title.isEmpty()) return;
    strncpy(movie.title, title.toUtf8().constData(), Movie::TITLE_SIZE);

    QFile file("ЕрмакЛаб09_2.bin");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        file.write(reinterpret_cast<char*>(&movie), sizeof(Movie));
        file.close();
        QMessageBox::information(this, "Успех", "Фильм успешно сохранен в двоичном файле.");
    } else {
        QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла.");
    }
}

void MainWindow::readStructFromBinary()
{
    QFile file("ЕрмакЛаб09_2.bin");
    if (file.open(QIODevice::ReadOnly)) {
        QString output;
        while (!file.atEnd()) {
            Movie movie;
            file.read(reinterpret_cast<char*>(&movie), sizeof(Movie));
            output += QString("ID: %1; Рейтинг: %2; Жанр: %3; Доступность: %4; Название: %5\n")
                          .arg(movie.id)
                          .arg(movie.rating)
                          .arg(movie.genre)
                          .arg(movie.isAvailable ? "Да" : "Нет")
                          .arg(movie.title);
        }
        file.close();
        QMessageBox::information(this, "Фильмы", output);
    } else {
        QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла.");
    }
}

void MainWindow::saveSentence()
{
    bool ok;
    QString sentence = QInputDialog::getText(this, "Введите предложение", "Предложение:", QLineEdit::Normal, "", &ok);
    if (ok && !sentence.isEmpty()) {
        QFile file("ЕрмакЛаб09_3.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            QTextStream out(&file);
            out.setEncoding(QStringConverter::Utf8);
            out << sentence << "\n";
            file.close();
            QMessageBox::information(this, "Успех", "Предложение успешно сохранено.");
        } else {
            QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла.");
        }
    }
}

void MainWindow::readSentences()
{
    QFile file("ЕрмакЛаб09_3.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        in.setEncoding(QStringConverter::Utf8);
        QString output;
        while (!in.atEnd()) {
            output += in.readLine() + "\n";
        }
        file.close();
        QMessageBox::information(this, "Предложения", output);
    } else {
        QMessageBox::warning(this, "Ошибка", "Ошибка открытия файла.");
    }
}

void MainWindow::exitApplication()
{
    QApplication::quit();
}
