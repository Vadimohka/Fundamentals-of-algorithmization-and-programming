#include "ticket.h"

void Ticket::initialize()
{
    dialog.setWindowTitle("Заполните форму");

    nameLine = new QLineEdit;
    surnameLine = new QLineEdit;
    patronymicLine = new QLineEdit;

    nameLine->setPlaceholderText("Введите ваше имя");
    surnameLine->setPlaceholderText("Введите вашу фамилию");
    patronymicLine->setPlaceholderText("Введите ваше отчество");

    dateText = new QTextEdit;
    timeText = new QTextEdit;
    cabinetNumberText = new QTextEdit;
    queueNumberText = new QTextEdit;

    dateText->setFixedSize(Width, Height);
    timeText->setFixedSize(Width, Height);
    cabinetNumberText->setFixedSize(Width, Height);
    queueNumberText->setFixedSize(Width, Height);

    dateText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    timeText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    cabinetNumberText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    queueNumberText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    dateText->setReadOnly(true);
    timeText->setReadOnly(true);
    cabinetNumberText->setReadOnly(true);
    queueNumberText->setReadOnly(true);

    dateText->setText(date.toString("dd.MM.yyyy"));

    timeText->setText(time.toString("hh:mm"));
    cabinetNumberText->setText(QString::number(cabinetNumber));
    queueNumberText->setText(QString::number(queueNumber));

    nameLabel = new QLabel("Ваше имя:");
    surnameLabel = new QLabel("Ваша Фамилия:");
    patronymicLabel = new QLabel("Ваше отчество:");
    dateLabel = new QLabel("Дата приёма:");
    timeLabel = new QLabel("Время приёма:");
    cabinetNumberLabel = new QLabel("Кабинет врача:");
    queueNumberLabel = new QLabel("Номер очереди:");

    saveTicketButton = new QPushButton("Записаться на приём");

    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->addWidget(nameLabel);
    layout->addWidget(nameLine);
    layout->addWidget(surnameLabel);
    layout->addWidget(surnameLine);
    layout->addWidget(patronymicLabel);
    layout->addWidget(patronymicLine);
    layout->addWidget(dateLabel);
    layout->addWidget(dateText);
    layout->addWidget(timeLabel);
    layout->addWidget(timeText);
    layout->addWidget(cabinetNumberLabel);
    layout->addWidget(cabinetNumberText);
    layout->addWidget(queueNumberLabel);
    layout->addWidget(queueNumberText);
    layout->addWidget(saveTicketButton);

    QObject::connect(saveTicketButton, &QPushButton::clicked, this, &Ticket::authorization);

}

Ticket::Ticket(QObject *parent)
{
    initialize();
}

Ticket::Ticket(QDate date, QTime time, int queueNumber, int cabinetNumber, QString doctorName, QString doctorSurname, QString doctorPatronymic, QString patientName, QString patientSurname, QString patientPatronymic, QObject *parent):
    date(date), time(time), queueNumber(queueNumber), cabinetNumber(cabinetNumber), doctorName(doctorName, doctorSurname, doctorPatronymic), patientName(patientName, patientSurname, patientPatronymic) {
    initialize();
};

Ticket::Ticket(const Ticket &other) :
    date(other.date),
    time(other.time),
    queueNumber(other.queueNumber),
    cabinetNumber(other.cabinetNumber),
    doctorName(other.doctorName),
    patientName(other.patientName)
{}

Ticket& Ticket::operator=(const Ticket &other)
{
    if (this != &other) {
        date = other.date;
        time = other.time;
        queueNumber = other.queueNumber;
        cabinetNumber = other.cabinetNumber;
        doctorName = other.doctorName;
        patientName = other.patientName;
    }
    return *this;
}


QDate Ticket::getDate()
{
    return date;
}

QTime Ticket::getTime()
{
    return time;
}

int Ticket::getQueueNumber()
{
    return queueNumber;
}

int Ticket::getCabinetNumber()
{
    return cabinetNumber;
}

void Ticket::startFoarm()
{
    dialog.exec();
}

void Ticket::authorization()
{
    if (nameLine->text() == "")
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введите ваше имя");
        return;
    }
    if (surnameLine->text() == "")
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введите вашу фамилию");
        return;
    }
    if (patronymicLine->text() == "")
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введите ваше отчество");
        return;
    }
    patientName.setName(nameLine->text());
    patientName.setSurname(surnameLine->text());
    patientName.setPatronymic(patronymicLine->text());
    dialog.close();
}
