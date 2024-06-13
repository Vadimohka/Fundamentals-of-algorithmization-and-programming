#include <QApplication>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QWidget>

struct HandWatch
{
    int HandWatchId;
    double HandWatchQuality;
    char HandWatchType;
    bool isWork;
    static const int maxNameLength = 20;
    char HandWatchName[maxNameLength];
    static const int maxSerialNumber = 100;
    int serialNumber;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("HandWatch Information");

    QLineEdit idLineEdit;
    QLineEdit qualityLineEdit;
    QLineEdit typeLineEdit;
    QLineEdit workLineEdit;
    QLineEdit nameLineEdit;
    QLineEdit serialNumberLineEdit;

    QPushButton submitButton("Submit");

    QFormLayout formLayout;
    formLayout.addRow("ID:", &idLineEdit);
    formLayout.addRow("Quality(%):", &qualityLineEdit);
    formLayout.addRow("Type(M-Mechanical, E-Electrical):", &typeLineEdit);
    formLayout.addRow("Work (1 for yes, 0 for no):", &workLineEdit);
    formLayout.addRow("Name:", &nameLineEdit);
    formLayout.addRow("Serial Number:", &serialNumberLineEdit);
    formLayout.addRow(&submitButton);

    window.setLayout(&formLayout);

    QObject::connect(&submitButton, &QPushButton::clicked, [&]() {
        QString a;

        //NewHandWatch
        HandWatch newHandWatch;
        newHandWatch.HandWatchId = idLineEdit.text().toInt();
        newHandWatch.HandWatchQuality = qualityLineEdit.text().toDouble();
        newHandWatch.HandWatchType = typeLineEdit.text().isEmpty()
                                         ? '\0'
                                         : typeLineEdit.text().at(0).toLatin1();
        newHandWatch.isWork = workLineEdit.text().toInt();
        qstrcpy(newHandWatch.HandWatchName, nameLineEdit.text().toUtf8().constData());
        newHandWatch.serialNumber = serialNumberLineEdit.text().toInt();

        a.append(QString::number(newHandWatch.HandWatchId) + " | "
                 + QString::number(newHandWatch.HandWatchQuality) + " | "
                 + newHandWatch.HandWatchType + " | " + (newHandWatch.isWork ? "true" : "false")
                 + " | " + QString(newHandWatch.HandWatchName) + " | "
                 + QString::number(newHandWatch.serialNumber) + '\n');

        //HandWatch2
        HandWatch HandWatch2;
        HandWatch2.HandWatchId = 2;
        HandWatch2.HandWatchQuality = 97;
        HandWatch2.HandWatchType = 'M';
        HandWatch2.isWork = false;
        qstrcpy(HandWatch2.HandWatchName, "Casio");
        HandWatch2.serialNumber = 30;

        a.append(QString::number(HandWatch2.HandWatchId) + " | "
                 + QString::number(HandWatch2.HandWatchQuality) + " | " + HandWatch2.HandWatchType
                 + " | " + (HandWatch2.isWork ? "true" : "false") + " | "
                 + QString(HandWatch2.HandWatchName) + " | "
                 + QString::number(HandWatch2.serialNumber) + '\n');

        //HandWatch3
        HandWatch HandWatch3;
        HandWatch3.HandWatchId = 3;
        HandWatch3.HandWatchQuality = 99.7;
        HandWatch3.HandWatchType = 'M';
        HandWatch3.isWork = true;
        qstrcpy(HandWatch3.HandWatchName, "Rolex");
        HandWatch3.serialNumber = 45;

        a.append(QString::number(HandWatch3.HandWatchId) + " | "
                 + QString::number(HandWatch3.HandWatchQuality) + " | " + HandWatch3.HandWatchType
                 + " | " + (HandWatch3.isWork ? "true" : "false") + " | "
                 + QString(HandWatch3.HandWatchName) + " | "
                 + QString::number(HandWatch3.serialNumber) + '\n');

        //HandWatch4
        HandWatch HandWatch4;
        HandWatch *HandWatch4Ptr = &HandWatch4;
        HandWatch4Ptr->HandWatchId = 4;
        HandWatch4Ptr->HandWatchQuality = 60.3;
        HandWatch4Ptr->HandWatchType = 'M';
        HandWatch4Ptr->isWork = false;
        qstrcpy(HandWatch4Ptr->HandWatchName, "Luch");
        HandWatch4Ptr->serialNumber = 70;

        a.append(QString::number(HandWatch4Ptr->HandWatchId) + " | "
                 + QString::number(HandWatch4Ptr->HandWatchQuality) + " | "
                 + HandWatch4Ptr->HandWatchType + " | " + (HandWatch4Ptr->isWork ? "true" : "false")
                 + " | " + QString(HandWatch4Ptr->HandWatchName) + " | "
                 + QString::number(HandWatch4Ptr->serialNumber) + '\n');

        //HandWatch5
        HandWatch HandWatch5;
        HandWatch &HandWatch5Ref = HandWatch5;
        HandWatch5Ref.HandWatchId = 5;
        HandWatch5Ref.HandWatchQuality = 85.8;
        HandWatch5Ref.HandWatchType = 'E';
        HandWatch5Ref.isWork = true;
        qstrcpy(HandWatch5Ref.HandWatchName, "Apple Watch");
        HandWatch5Ref.serialNumber = 55;

        a.append(QString::number(HandWatch5Ref.HandWatchId) + " | "
                 + QString::number(HandWatch5Ref.HandWatchQuality) + " | "
                 + HandWatch5Ref.HandWatchType + " | " + (HandWatch5Ref.isWork ? "true" : "false")
                 + " | " + QString(HandWatch5Ref.HandWatchName) + " | "
                 + QString::number(HandWatch5Ref.serialNumber) + '\n');
        QMessageBox::about(&window, "My HandWatches", a);
    });

    window.show();

    return app.exec();
}
