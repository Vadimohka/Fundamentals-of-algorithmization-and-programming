// main.cpp
#include <QCoreApplication>
#include <QDebug>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include "Toy.h"

QDataStream &operator<<(QDataStream &out, const Toy &toy) {
    out << toy.id << toy.name << toy.price;
    return out;
}

QDataStream &operator>>(QDataStream &in, Toy &toy) {
    in >> toy.id >> toy.name >> toy.price;
    return in;
}


void displayMenu() {
    qDebug() << "1. Enter Toy (Text File)";
    qDebug() << "2. Read Toys (Text File)";
    qDebug() << "3. Enter Toy (Binary File)";
    qDebug() << "4. Read Toys (Binary File)";
    qDebug() << "5. Enter Sentence";
    qDebug() << "6. Read Sentences";
    qDebug() << "7. Exit";
}

void enterToyText() {
    Toy toy;
    toy.id = QInputDialog::getInt(nullptr, "Enter Toy ID", "ID:", 0);
    toy.price = QInputDialog::getDouble(nullptr, "Enter Toy Price", "Price:", 0.0);
    toy.category = QInputDialog::getText(nullptr, "Enter Toy Category", "Category:", QLineEdit::Normal)[0];
    toy.isAvailable = QInputDialog::getInt(nullptr, "Is Toy Available?", "Available (1 for Yes, 0 for No):", 0, 0, 1);
    toy.name = QInputDialog::getText(nullptr, "Enter Toy Name", "Name:", QLineEdit::Normal);
    int ratingCount = QInputDialog::getInt(nullptr, "Enter Number of Ratings", "Number of Ratings:", 0, 0, 1000);
    for (int i = 0; i < ratingCount; ++i) {
        toy.ratings.append(QInputDialog::getInt(nullptr, QString("Enter Rating %1").arg(i + 1), "Rating:", 0, INT_MIN, INT_MAX, 1));
    }

    QFile file("МалиновскийЛаб20.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << toy.id << "," << toy.price << "," << toy.category << "," << toy.isAvailable << "," << toy.name << ",";
        for (int rating : toy.ratings) {
            out << rating << ",";
        }
        out << "\n";
        file.close();
        qDebug() << "Toy data saved to text file МалиновскийЛаб20.txt";
    } else {
        qDebug() << "Failed to open file for writing.";
    }
}

void readToysText() {
    QFile file("МалиновскийЛаб20.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            qDebug() << line;
        }
        file.close();
    } else {
        qDebug() << "Failed to open file for reading.";
    }
}

void enterToyBinary() {
    Toy toy;
    toy.id = QInputDialog::getInt(nullptr, "Enter Toy ID", "ID:", 0);
    toy.price = QInputDialog::getDouble(nullptr, "Enter Toy Price", "Price:", 0.0);
    toy.category = QInputDialog::getText(nullptr, "Enter Toy Category", "Category:", QLineEdit::Normal)[0];
    toy.isAvailable = QInputDialog::getInt(nullptr, "Is Toy Available?", "Available (1 for Yes, 0 for No):", 0, 0, 1);
    toy.name = QInputDialog::getText(nullptr, "Enter Toy Name", "Name:", QLineEdit::Normal);
    int ratingCount = QInputDialog::getInt(nullptr, "Enter Number of Ratings", "Number of Ratings:", 0, 0, 1000);
    for (int i = 0; i < ratingCount; ++i) {
        toy.ratings.append(QInputDialog::getInt(nullptr, QString("Enter Rating %1").arg(i + 1), "Rating:", 0, INT_MIN, INT_MAX, 1));
    }

    QFile file("МалиновскийЛаб20_0.bin");
    if (file.open(QIODevice::Append)) {
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_15);
        out << toy;
        file.close();
        qDebug() << "Toy data saved to binary file МалиновскийЛаб20_0.bin";
    } else {
        qDebug() << "Failed to open file for writing.";
    }
}

void readToysBinary() {
    QFile file("МалиновскийЛаб20_0.bin");
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_5_15);
        Toy toy;
        while (!in.atEnd()) {
            in >> toy;
            qDebug() << "ID:" << toy.id << "Price:" << toy.price << "Category:" << toy.category << "Available:" << toy.isAvailable << "Name:" << toy.name;
        }
        file.close();
    } else {
        qDebug() << "Failed to open file for reading.";
    }
}

void enterSentence() {
    QString sentence = QInputDialog::getText(nullptr, "Enter Sentence", "Sentence:");
    QFile file("МалиновскийЛаб20_3.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << sentence << "\n";
        file.close();
        qDebug() << "Sentence saved to text file МалиновскийЛаб20_3.txt";
    } else {
        qDebug() << "Failed to open file for writing.";
    }
}

void readSentences() {
    QFile file("МалиновскийЛаб20_3.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString sentence = in.readLine();
            qDebug() << sentence;
        }
        file.close();
    } else {
        qDebug() << "Failed to open file for reading.";
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    int choice = 0;
    while (true) {
        displayMenu();
        choice = QInputDialog::getInt(nullptr, "Menu", "Enter your choice:", 1, 1, 7);
        switch (choice) {
        case 1:
            enterToyText();
            break;
        case 2:
            readToysText();
            break;
        case 3:
            enterToyBinary();
            break;
        case 4:
            readToysBinary();
            break;
        case 5:
            enterSentence();
            break;
        case 6:
            readSentences();
            break;
        case 7:
            qDebug() << "Exiting program...";
            return 0;
        default:
            qDebug() << "Invalid choice. Please try again.";
            break;
        }
    }

    return a.exec();
}
