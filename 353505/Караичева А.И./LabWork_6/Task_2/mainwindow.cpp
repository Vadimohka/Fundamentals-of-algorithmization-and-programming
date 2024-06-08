#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stream_in(&text_in)
    , stream_out(&text_out)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->lineEdit->setEnabled(false);
}


void MainWindow::ShowMenu() {
    while (true) {
        QCoreApplication::processEvents();
        stream_out << menu;
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()) {
            QCoreApplication::processEvents();
        }
        int choice;
        stream_in >> choice;
        if (stream_in.status() != QTextStream::Ok) {
            text_in.clear();
            stream_in.resetStatus();
        } else {
            text_in.remove(0, stream_in.pos());
            stream_out << choice << '\n';
        }
        stream_in.seek(0);
        ui->lineEdit->setText(text_in);
        PrintMenu(choice);
    }
}


void MainWindow::PrintMenu(int choice) {
    switch (choice) {
    case 1:
        SaveTextToFile();
        break;
    case 2:
        GetFileContents();
        break;
    case 3:
        SaveArrayToFile();
        break;
    case 4:
        GetArrayContents();
        break;
    case 5:
        SaveSmartphoneToFile();
        break;
    case 6:
        GetSmartphoneContents();
        break;
    case 7:
        SaveSmartphoneToBinaryFile();
        break;
    case 8:
        GetSmartphoneFromBinaryFileContents();
        break;
    case 9:
        AddTextToFile();
        break;
    case 10:
        GetStringToFile();
        break;
    case 11:
        stream_out << "Выход из программы.\n";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        close();
        break;
    default:
        stream_out << "Некорректный ввод. Пожалуйста, выберите пункт меню от 1 до 11.\n";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
    }
    stream_out << "\n";
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->lineEdit->setReadOnly(true);
}


void MainWindow::SaveTextToFile() {
    QString fileName = "KaraichevaLab6.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out << "Вы выбрали пункт 1\nВведите абзац текста";
    ui->lineEdit->clear();
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    text_in.clear();
    ui->lineEdit->setReadOnly(false);

    while (text_in.isEmpty()) {
        QCoreApplication::processEvents();
    }
    ui->lineEdit->setReadOnly(true);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для записи\n";
    } else {
        for (int i = 0; i < text_in.length(); ++i) {
            file_stream << text_in.at(i);
        }
        text_in.clear();
        ui->lineEdit->setText(text_in);
        stream_in.readAll();
        stream_out << "\nТекст был добавлен в файл\n";
        file.close();
    }
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::GetFileContents() {
    QString fileName = "KaraichevaLab6.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out << "Вы выбрали пункт 2 (отображение содержимого файла: " << fileName << ")\n";
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!file_stream.atEnd()) {
            QChar ch;
            file_stream >> ch;
            stream_out << ch;
        }
        file.close();
    }
    ui->textEdit->setText(text_in);
    ui->textEdit->moveCursor(QTextCursor::End);
}


void MainWindow::SaveArrayToFile() {
    QString fileName = "KaraichevaLab6_0.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out << "Вы выбрали пункт 3\nВведите размер массива и массив типа short int, разделяя элементы символом пробела\n";
    ui->lineEdit->clear();
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для запси\n";
    } else {
        stream_out << "Введте размер массива: ";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        int n;
        stream_in >> n;
        if (stream_in.status() != QTextStream::Ok || n < 0) {
            stream_out << "\nНеверный ввод размера массива\n";
            ui->textEdit->setText(text_out);
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        }
        else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << n << '\n';
        }
        ui->lineEdit->setText(text_in);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            short int c;
            stream_out << "Введите " << i+1 << "-й из " << n << " символа(ов) желаемого: ";
            ui->textEdit->setText(text_out);
            ui->textEdit->moveCursor(QTextCursor::End);
            while (text_in.isEmpty()) {
                QCoreApplication::processEvents();
            }
            stream_in >> c;
            if (stream_in.status() != QTextStream::Ok) {
                stream_out << "\nНеверный ввод символа\n";
                stream_in.seek(0);
                stream_in.resetStatus();
                text_in.clear();
                ok = false;
                return;
            }
            else {
                text_in.remove(0, stream_in.pos());
                stream_in.seek(0);
                stream_out << c << '\n';
            }
            ui->lineEdit->setText(text_in);
            file_stream << c << '|';
        }
        file.close();
        if (ok) stream_out << "\nМассив записан в файл " << fileName << "\n";
    }
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::GetArrayContents() {
    QString fileName = "KaraichevaLab6_0.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out << "Вы выбрали пункт 4 (отображение содержимого файла: " << fileName << ")\n";
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!file_stream.atEnd()) {
            QString line = file_stream.readLine();
            QStringList charArray = line.split("|", Qt::SkipEmptyParts);
            for (const QString &ch : charArray) {
                stream_out << ch << " ";
            }
            stream_out << "\n";
        }
        file.close();
    }
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::SaveSmartphoneToFile() {
    QString fileName = "KaraichevaLab6_1.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out << "Вы выбрали пункт 5\nВведите данные о смартфоне: год выпуска, цена, класс экологичности, является ли новым (0 — нет, 1 — да)\n";
    ui->lineEdit->clear();
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->lineEdit->setReadOnly(false);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для запси\n";
    } else {
        Smartphone smartphone;
        stream_out << "Введите год выпуска (int): ";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> smartphone.release_year;
        if (stream_in.status() != QTextStream::Ok || smartphone.release_year < 0) {
            stream_out << "\nНеверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << smartphone.release_year << '\n';
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();
        stream_out << "Введите цену (double): ";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> smartphone.price;
        if (stream_in.status() != QTextStream::Ok || smartphone.price < 0) {
            stream_out << "\nНеверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << smartphone.price << "$\n";
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();
        stream_out << "Введите класс экологичности (например H или A): ";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> smartphone.eco_class;
        if (stream_in.status() != QTextStream::Ok ) {
            stream_out << "\nНеверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << smartphone.eco_class << '\n';
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();
        stream_out << "Введите является ли новым (0 — нет, 1 — да): ";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        int isNew;
        stream_in >> isNew;
        if (stream_in.status() != QTextStream::Ok || (isNew != 0 && isNew != 1)) {
            stream_out << "\nНеверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            smartphone.IsNew = (isNew == 1);
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << (smartphone.IsNew ? "Новый" : "Б/у") << '\n';
        }
        ui->lineEdit->setText(text_in);
        file_stream << smartphone.release_year << " " << smartphone.price << " " << smartphone.eco_class << " " << (smartphone.IsNew ? "1" : "0") << "\n";
        file.close();
    }
    stream_out << "\nДанные о смартфоне успешно записаны в файл " << fileName << "\n";
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::GetSmartphoneContents() {
    QString fileName = "KaraichevaLab6_1.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out << "Вы выбрали пункт 6\nСодержимое файла " << fileName << ":\n";
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!file_stream.atEnd()) {
            QString line = file_stream.readLine();
            QStringList SmartphoneData = line.split(" ", Qt::SkipEmptyParts);
            if (SmartphoneData.size() != 4) {
                stream_out << "\nНеверный формат строки в файле.\n";
                continue;
            }
            Smartphone smartphone;
            smartphone.release_year = SmartphoneData[0].toInt();
            smartphone.price = SmartphoneData[1].toDouble();
            smartphone.eco_class = SmartphoneData[2][0].toLatin1();
            smartphone.IsNew = (SmartphoneData[3].toInt() != 0);

            stream_out << "Год выпуска: " << smartphone.release_year << " | ";
            stream_out << "Цена: " << smartphone.price << "$ | ";
            stream_out << "Класс экологичности: " << smartphone.eco_class << " | ";
            stream_out << "Новый: " << (smartphone.IsNew ? "Да" : "Нет") << "\n";
        }
        file.close();
    }
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::SaveSmartphoneToBinaryFile() {
    QString fileName = "KaraichevaLab6_2.bin";
    std::ofstream file(fileName.toStdString(), std::ios::binary | std::ios::app);
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    stream_out << "Вы выбрали пункт 7\nВведите данные о смартфоне: год выпуска, цена, класс экологичности, является ли новым (0 — нет, 1 — да)\n";
    ui->lineEdit->clear();
    if (!file.is_open()) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для запси\n";
    } else {
        Smartphone smartphone;
        stream_out << "Введите год выпуска (int): ";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> smartphone.release_year;
        if (stream_in.status() != QTextStream::Ok || smartphone.release_year < 0) {
            stream_out << "\nНеверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << smartphone.release_year << '\n';
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();
        stream_out << "Введите цену (double): ";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> smartphone.price;
        if (stream_in.status() != QTextStream::Ok || smartphone.price < 0) {
            stream_out << "Неверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << smartphone.price << "$\n";
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();
        stream_out << "Введите класс экологичности (например H или A): ";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        stream_in >> smartphone.eco_class;
        if (stream_in.status() != QTextStream::Ok ) {
            stream_out << "\nНеверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << smartphone.eco_class << '\n';
        }
        ui->lineEdit->setText(text_in);
        ui->lineEdit->clear();
        stream_out << "Введите является ли новым (0 — нет, 1 — да): ";
        ui->textEdit->setText(text_out);
        ui->textEdit->moveCursor(QTextCursor::End);
        ui->lineEdit->setReadOnly(false);
        while (text_in.isEmpty()){
            QCoreApplication::processEvents();
        }
        int IsNew;
        stream_in >> IsNew;
        if (stream_in.status() != QTextStream::Ok || (IsNew != 0 && IsNew != 1)) {
            stream_out << "\nНеверный ввод\n";
            stream_in.resetStatus();
            text_in.clear();
            file.close();
            stream_in.seek(0);
            return;
        } else {
            smartphone.IsNew = (IsNew == 1);
            text_in.remove(0, stream_in.pos());
            stream_in.seek(0);
            stream_out << (smartphone.IsNew ? "Новый" : "Б/у") << '\n';
        }
        ui->lineEdit->setText(text_in);

        file.write(reinterpret_cast<const char*>(&smartphone), sizeof(smartphone));
        file.close();
    }
    ui->textEdit->setText(text_out);
    stream_out << "Данные о смартфоне успешно записаны в бинарный файл " << fileName << "\n";
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::GetSmartphoneFromBinaryFileContents() {
    QString fileName = "KaraichevaLab6_2.bin";
    std::ifstream file(fileName.toStdString(), std::ios::binary);
    stream_out << "Вы выбрали пункт 8\nСодержимое файла " << fileName << ":\n";
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);

    if (!file.is_open()) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        Smartphone smartphone;
        while (!file.eof()) {
            file.read(reinterpret_cast<char*>(&smartphone), sizeof(smartphone));
            if (file.eof()) break;
            stream_out << "Год выпуска: " << smartphone.release_year << "; ";
            stream_out << "Цена: " << smartphone.price << "$; ";
            stream_out << "Класс экологичности: " << smartphone.eco_class << "; ";
            stream_out << "Новый: " << (smartphone.IsNew ? "Да" : "Нет") << "\n";
        }
        file.close();
    }

    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}


void MainWindow::AddTextToFile() {
    QString fileName = "KaraichevaLab6_3.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out << "Вы выбрали пункт 9\nВведите текст для добавления в файл " << fileName << "\n";
    ui->lineEdit->clear();
    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->lineEdit->setReadOnly(false);
    while (text_in.isEmpty()) {
        QCoreApplication::processEvents();
    }
    ui->lineEdit->setReadOnly(true);

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для записи\n";
    } else {
        file_stream << text_in << "\n";
        file.close();
        text_in.clear();
        ui->lineEdit->setText(text_in);
        stream_in.readAll();
        stream_out << "Текст успешно добавлен в файл " << fileName << "\n";
    }

    ui->textEdit->setText(text_out);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::GetStringToFile() {
    QString fileName = "KaraichevaLab6"
                       "_3.txt";
    QFile file(fileName);
    QTextStream file_stream(&file);
    stream_out << "Вы выбрали пункт 10 (построчно считать из текстового файла " << fileName << " все предложения и вывести их на экран)\n";
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        stream_out << "\nНе удалось открыть файл" << fileName << "для чтения\n";
    } else {
        while (!file_stream.atEnd()) {
            QChar ch;
            file_stream >> ch;
            stream_out << ch;
        }
        file.close();
    }
    ui->textEdit->setText(text_in);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::on_lineEdit_returnPressed()
{
    if (!ui->lineEdit->isReadOnly())
        text_in += ui->lineEdit->text();
}
void MainWindow::on_menu_clicked()
{
    ui->lineEdit->setEnabled(true);
    ShowMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}


