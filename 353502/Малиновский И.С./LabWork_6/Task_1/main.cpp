#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QInputDialog>

class Toy {
public:
    int id;
    double price;
    char category;
    bool isAvailable;
    static const int MAX_CHARS = 10;
    static const int MAX_NUMS = 5;
    char name[MAX_CHARS];
    int ratings[MAX_NUMS];
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Toy toy1 = {1, 19.99, 'D', true, "Doll", {5, 4, 5, 3, 4}};

    qDebug() << "Toy 1: " << toy1.id << " | " << toy1.price << " | " << toy1.category << " | "
             << toy1.isAvailable << " | " << QString(toy1.name) << " | "
             << toy1.ratings[0] << " " << toy1.ratings[1] << " " << toy1.ratings[2] << " "
             << toy1.ratings[3] << " " << toy1.ratings[4];

    Toy toy2;
    toy2.id = 2;
    toy2.price = 24.99;
    toy2.category = 'C';
    toy2.isAvailable = false;
    strcpy(toy2.name, "Car");
    toy2.ratings[0] = 1;
    toy2.ratings[1] = 2;
    toy2.ratings[2] = 3;
    toy2.ratings[3] = 4;
    toy2.ratings[4] = 5;

    qDebug() << "Toy 2: " << toy2.id << " | " << toy2.price << " | " << toy2.category << " | "
             << toy2.isAvailable << " | " << QString(toy2.name) << " | "
             << toy2.ratings[0] << " " << toy2.ratings[1] << " " << toy2.ratings[2] << " "
             << toy2.ratings[3] << " " << toy2.ratings[4];

    Toy toy3;
    bool ok;
    toy3.id = QInputDialog::getInt(nullptr, "Enter toy ID", "ID:", 0, 0, 1000, 1, &ok);
    toy3.price = QInputDialog::getDouble(nullptr, "Enter toy price", "Price:", 0.0, 0.0, 1000.0, 2, &ok);
    toy3.category = QInputDialog::getText(nullptr, "Enter toy category", "Category:", QLineEdit::Normal, "", &ok).toUtf8().at(0);
    toy3.isAvailable = QInputDialog::getInt(nullptr, "Is toy available?", "Available (1 for yes, 0 for no):", 0, 0, 1, 1, &ok);
    QString name = QInputDialog::getText(nullptr, "Enter toy name", "Name:", QLineEdit::Normal, "", &ok);
    QByteArray nameBytes = name.toUtf8();
    strcpy(toy3.name, nameBytes.constData());
    qDebug() << "Enter toy ratings (5 integers):";
    for (int i = 0; i < Toy::MAX_NUMS; ++i) {
        toy3.ratings[i] = QInputDialog::getInt(nullptr, "Enter toy rating", QString("Rating %1:").arg(i + 1), 0, 0, 10, 1, &ok);
    }

    qDebug() << "Toy 3: " << toy3.id << " | " << toy3.price << " | " << toy3.category << " | "
             << toy3.isAvailable << " | " << QString(toy3.name) << " | "
             << toy3.ratings[0] << " " << toy3.ratings[1] << " " << toy3.ratings[2] << " "
             << toy3.ratings[3] << " " << toy3.ratings[4];

    Toy* toyPtr = &toy1;
    qDebug() << "Toy 1 (via pointer): " << toyPtr->id << " | " << toyPtr->price << " | " << toyPtr->category << " | "
             << toyPtr->isAvailable << " | " << QString(toyPtr->name) << " | "
             << toyPtr->ratings[0] << " " << toyPtr->ratings[1] << " " << toyPtr->ratings[2] << " "
             << toyPtr->ratings[3] << " " << toyPtr->ratings[4];

    Toy& toyRef = toy2;
    qDebug() << "Toy 2 (via reference): " << toyRef.id << " | " << toyRef.price << " | " << toyRef.category << " | "
             << toyRef.isAvailable << " | " << QString(toyRef.name) << " | "
             << toyRef.ratings[0] << " " << toyRef.ratings[1] << " " << toyRef.ratings[2] << " "
             << toyRef.ratings[3] << " " << toyRef.ratings[4];

    return a.exec();
}
