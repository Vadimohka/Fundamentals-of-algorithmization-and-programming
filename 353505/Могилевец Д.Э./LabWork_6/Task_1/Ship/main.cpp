#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

struct Ship {
    int shipId;
    double shipLength;
    char shipType;
    bool isDocked;
    static const int maxNameLength = 20;
    char shipName[maxNameLength];
    static const int maxCrewSize = 100;
    int crewSize;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Ship Information");

    QLineEdit idLineEdit;
    QLineEdit lengthLineEdit;
    QLineEdit typeLineEdit;
    QLineEdit dockedLineEdit;
    QLineEdit nameLineEdit;
    QLineEdit crewLineEdit;

    QPushButton submitButton("Submit");

    QFormLayout formLayout;
    formLayout.addRow("ID:", &idLineEdit);
    formLayout.addRow("Length:", &lengthLineEdit);
    formLayout.addRow("Type:", &typeLineEdit);
    formLayout.addRow("Docked (1 for yes, 0 for no):", &dockedLineEdit);
    formLayout.addRow("Name:", &nameLineEdit);
    formLayout.addRow("Crew Size:", &crewLineEdit);
    formLayout.addRow(&submitButton);

    QLabel ship1Label;
    QLabel ship2Label;
    QLabel ship3Label;
    QLabel ship4Label;
    QLabel ship5Label;

    formLayout.addRow("Ship 1:", &ship1Label);
    formLayout.addRow("Ship 2:", &ship2Label);
    formLayout.addRow("Ship 3:", &ship3Label);
    formLayout.addRow("Ship 4:", &ship4Label);
    formLayout.addRow("Ship 5:", &ship5Label);

    window.setLayout(&formLayout);

    QObject::connect(&submitButton, &QPushButton::clicked, [&]() {
        Ship newShip;
        newShip.shipId = idLineEdit.text().toInt();
        newShip.shipLength = lengthLineEdit.text().toDouble();
        newShip.shipType = typeLineEdit.text().isEmpty() ? '\0' : typeLineEdit.text().at(0).toLatin1();
        newShip.isDocked = dockedLineEdit.text().toInt();
        qstrcpy(newShip.shipName, nameLineEdit.text().toUtf8().constData());
        newShip.crewSize = crewLineEdit.text().toInt();

        ship1Label.setText(QString::number(newShip.shipId) + " | " + QString::number(newShip.shipLength) + " | " +
                           newShip.shipType + " | " + (newShip.isDocked ? "true" : "false") + " | " +
                           QString(newShip.shipName) + " | " + QString::number(newShip.crewSize));

        Ship ship2;
        ship2.shipId = 2;
        ship2.shipLength = 100.2;
        ship2.shipType = 'B';
        ship2.isDocked = false;
        qstrcpy(ship2.shipName, "Sea Voyager");
        ship2.crewSize = 30;

        ship2Label.setText(QString::number(ship2.shipId) + " | " + QString::number(ship2.shipLength) + " | " +
                           ship2.shipType + " | " + (ship2.isDocked ? "true" : "false") + " | " +
                           QString(ship2.shipName) + " | " + QString::number(ship2.crewSize));

        Ship ship3;
        ship3.shipId = 3;
        ship3.shipLength = 85.6;
        ship3.shipType = 'C';
        ship3.isDocked = true;
        qstrcpy(ship3.shipName, "Atlantis");
        ship3.crewSize = 45;

        ship3Label.setText(QString::number(ship3.shipId) + " | " + QString::number(ship3.shipLength) + " | " +
                           ship3.shipType + " | " + (ship3.isDocked ? "true" : "false") + " | " +
                           QString(ship3.shipName) + " | " + QString::number(ship3.crewSize));

        Ship ship4;
        Ship *ship4Ptr = &ship4;
        ship4Ptr->shipId = 4;
        ship4Ptr->shipLength = 80.3;
        ship4Ptr->shipType = 'A';
        ship4Ptr->isDocked = true;
        qstrcpy(ship4Ptr->shipName, "Oceanic");
        ship4Ptr->crewSize = 70;

        ship4Label.setText(QString::number(ship4Ptr->shipId) + " | " + QString::number(ship4Ptr->shipLength) + " | " +
                           ship4Ptr->shipType + " | " + (ship4Ptr->isDocked ? "true" : "false") + " | " +
                           QString(ship4Ptr->shipName) + " | " + QString::number(ship4Ptr->crewSize));

        Ship ship5;
        Ship &ship5Ref = ship5;
        ship5Ref.shipId = 5;
        ship5Ref.shipLength = 120.8;
        ship5Ref.shipType = 'D';
        ship5Ref.isDocked = false;
        qstrcpy(ship5Ref.shipName, "Starlight");
        ship5Ref.crewSize = 55;

        ship5Label.setText(QString::number(ship5Ref.shipId) + " | " + QString::number(ship5Ref.shipLength) + " | " +
                           ship5Ref.shipType + " | " + (ship5Ref.isDocked ? "true" : "false") + " | " +
                           QString(ship5Ref.shipName) + " | " + QString::number(ship5Ref.crewSize));
    });

    window.show();

    return app.exec();
}
