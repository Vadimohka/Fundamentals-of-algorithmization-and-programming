#include "doctor.h"

void Doctor::initialization()
{
    QObject::connect(&doctorDates, &CustomCalendarWidget::dateSelected, &dateDialog, &QDialog::accept);

    dateDialog.setWindowTitle("Выбор даты");

    addDialog.setFixedSize(DialogWidth, DialogHeight);
    addDialog.setWindowTitle("Заполните данные");

    nameLine.setPlaceholderText("Введите имя врача");
    surnameLine.setPlaceholderText("Введите фамилию врача");
    patronymicLine.setPlaceholderText("Введите отчество врача");
    specializationLine.setPlaceholderText("Введите специализацию врача");
    cabinetNumberLine.setPlaceholderText("Введите номер кабинета врача");
    for (int i=0; i<7; i++)
    {
        startTimeLines[i].setPlaceholderText("Введите время начала рабочего дня");
        endTimeLines[i].setPlaceholderText("Введите время конца рабочего дня");
    }

    nameLabel.setText("Имя врача:");
    surnameLabel.setText("Фамилия врача:");
    patronymicLabel.setText("Отчество врача:");
    specializationLabel.setText("Специализация врача:");
    cabinetNumberLabel.setText("Номер кабинета врача:");
    startTimeLabels[0].setText("Начало рабочего дня в понедельник:");
    startTimeLabels[1].setText("Начало рабочего дня во вторник:");
    startTimeLabels[2].setText("Начало рабочего дня в среду:");
    startTimeLabels[3].setText("Начало рабочего дня в четверг:");
    startTimeLabels[4].setText("Начало рабочего дня в пятницу:");
    startTimeLabels[5].setText("Начало рабочего дня в субботу:");
    startTimeLabels[6].setText("Начало рабочего дня в восскесенье:");
    endTimeLabels[0].setText("Конец рабочего дня в понедельник:");
    endTimeLabels[1].setText("Конец рабочего дня во вторник:");
    endTimeLabels[2].setText("Конец рабочего дня в среду:");
    endTimeLabels[3].setText("Конец рабочего дня в четверг:");
    endTimeLabels[4].setText("Конец рабочего дня в пятницу:");
    endTimeLabels[5].setText("Конец рабочего дня в субботу:");
    endTimeLabels[6].setText("Конец рабочего дня в восскесенье:");
    workSheduleLabel.setText("График работы врача:");

    QVBoxLayout *layout = new QVBoxLayout(&addDialog);

    layout->addWidget(&nameLabel);
    layout->addWidget(&nameLine);
    layout->addWidget(&surnameLabel);
    layout->addWidget(&surnameLine);
    layout->addWidget(&patronymicLabel);
    layout->addWidget(&patronymicLine);
    layout->addWidget(&specializationLabel);
    layout->addWidget(&specializationLine);
    layout->addWidget(&cabinetNumberLabel);
    layout->addWidget(&cabinetNumberLine);
    layout->addWidget(&workSheduleLabel, 0, Qt::AlignCenter);
    for (int i=0; i<NumberDays; i++)
    {
        QHBoxLayout *horizontalBox1 = new QHBoxLayout;
        horizontalBox1->addWidget(&startTimeLabels[i]);
        horizontalBox1->addWidget(&endTimeLabels[i]);
        layout->addLayout(horizontalBox1);

        QHBoxLayout *horizontalBox2 = new QHBoxLayout;
        horizontalBox2->addWidget(&startTimeLines[i]);
        horizontalBox2->addWidget(&endTimeLines[i]);
        layout->addLayout(horizontalBox2);
    }
    saveAddButton.setText("Добавить данные врача");
    QObject::connect(&saveAddButton, &QPushButton::clicked, this, &Doctor::checkAddDoctor);
    layout->addWidget(&saveAddButton);
}

Doctor::Doctor(QObject *parent)
{
    Q_UNUSED(parent);
    initialization();
}

Doctor::Doctor(QString specialization, QString name, QString surname, QString patronymic, int cabinetNumber, QTime* startTime, QTime* endTime, QObject *parent): specialization(specialization), name(name, surname, patronymic), cabinetNumber(cabinetNumber)
{
    Q_UNUSED(parent);
    initialization();
    for (int i=0; i<NumberDays; i++)
    {
        this->startTime[i]=startTime[i];
        this->endTime[i]=endTime[i];
        this->queueNumber[i] = qMax(0, startTime[i].secsTo(endTime[i]) / AddSecs);
        if (!this->queueNumber[i]) doctorDates.addBanDayOfWeek(i + 1);
    }
}

Doctor::Doctor(const Doctor &other) : QObject(other.parent()), name(other.name)
{
    specialization = other.specialization;
    cabinetNumber = other.cabinetNumber;
    doctorDates = other.doctorDates;
    dataQueue = other.dataQueue;

    for (int i = 0; i < NumberDays; i++) {
        startTime[i] = other.startTime[i];
        endTime[i] = other.endTime[i];
    }
    for (int i = 0; i < NumberDays; ++i) {
        queueNumber[i] = other.queueNumber[i];
        startTimeLines[i].setText(other.startTimeLines[i].text());
        endTimeLines[i].setText(other.endTimeLines[i].text());

    }
}

Doctor& Doctor::operator=(const Doctor &other) {
    if (this != &other)
    {
        name = other.name;
        specialization = other.specialization;
        cabinetNumber = other.cabinetNumber;
        doctorDates = other.doctorDates;
        dataQueue = other.dataQueue;

        for (int i = 0; i < NumberDays; ++i) {
            startTime[i] = other.startTime[i];
            endTime[i] = other.endTime[i];
        }

        for (int i = 0; i < NumberDays; ++i) {
            queueNumber[i] = other.queueNumber[i];
            startTimeLines[i].setText(other.startTimeLines[i].text());
            endTimeLines[i].setText(other.endTimeLines[i].text());

        }

        dateDialog.setWindowTitle(other.dateDialog.windowTitle());
        addDialog.setWindowTitle(other.addDialog.windowTitle());

        nameLine.setText(other.nameLine.text());
        surnameLine.setText(other.surnameLine.text());
        patronymicLine.setText(other.patronymicLine.text());
        specializationLine.setText(other.specializationLine.text());
        cabinetNumberLine.setText(other.cabinetNumberLine.text());

        nameLabel.setText(other.nameLabel.text());
        surnameLabel.setText(other.surnameLabel.text());
        patronymicLabel.setText(other.patronymicLabel.text());
        specializationLabel.setText(other.specializationLabel.text());
        cabinetNumberLabel.setText(other.cabinetNumberLabel.text());

        saveAddButton.setText(other.saveAddButton.text());
    }
    return *this;
}


QString Doctor::getSpecialization() const
{
    return specialization;
}

QTime Doctor::getStartTime(int ind) const
{
    return startTime[ind - 1];
}

QTime Doctor::getEndTime(int ind) const
{
    return endTime[ind - 1];
}

QString Doctor::getInfo() const
{
    return "ФИО: " + name.getSurname() + ' ' + name.getName() + ' ' +name.getPatronymic() + "\nСпециализация: " + specialization;
}

void Doctor::selectDate()
{
    QVBoxLayout layout(&dateDialog);

    QPushButton *selectDate = new QPushButton("Выбрать дату");

    layout.addWidget(&doctorDates);
    layout.addWidget(selectDate);

    QObject::connect(selectDate, &QPushButton::clicked, this, &Doctor::addTicket);
    dateDialog.exec();
}

void Doctor::addTicket()
{
    qDebug();
    QDate selectedDate = doctorDates.selectedDate();

    dateDialog.close();
    QTime time = this->startTime[selectedDate.dayOfWeek() - 1].addSecs(AddSecs * dataQueue[selectedDate].size());
    Ticket ticket(selectedDate, time, dataQueue[selectedDate].size()+1, cabinetNumber, name.getName(), name.getSurname(), name.getPatronymic(), "", "", "");

    ticket.startFoarm();
    dataQueue[selectedDate].push_back(ticket);
    if (dataQueue[selectedDate].size() == queueNumber[selectedDate.dayOfWeek() - 1])
    {
        doctorDates.addBanDate(selectedDate);
    }
}

void Doctor::addDoctor()
{
    addDialog.exec();
}

void Doctor::checkAddDoctor()
{
    if (nameLine.text() == "")
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введите имя врача");
        return;
    }
    if (surnameLine.text() == "")
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введите фамилию врача");
        return;
    }
    if (patronymicLine.text() == "")
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введите отчество врача");
        return;
    }
    if (specializationLine.text() == "")
    {
        QMessageBox::warning(nullptr, "Ошибка", "Введите специализацию врача");
        return;
    }
    QString cabNum = cabinetNumberLine.text();
    bool isNumber = true;
    int number = cabNum.toInt(&isNumber);
    if (!isNumber || number <= 0)
    {
        QMessageBox::warning(nullptr, "Ошибка", "Номер кабинета введён некорректно");
        return;
    }
    for (int i=0; i<NumberDays; i++)
    {
        QTime start = QTime::fromString(startTimeLines[i].text(), "hh:mm");
        QTime end = QTime::fromString(endTimeLines[i].text(), "hh:mm");
        if (!start.isValid() || !end.isValid() || start.secsTo(end) < 0)
        {
            QMessageBox::warning(nullptr, "Ошибка", "График работы для " + DAYS_OF_WEEK[i] + " введён неправильно");
            return;
        }
    }
    name.setName(nameLine.text());
    name.setSurname(surnameLine.text());
    name.setPatronymic(patronymicLine.text());
    specialization = specializationLine.text();
    cabinetNumber = cabinetNumberLine.text().toInt();
    for (int i=0; i<NumberDays; i++)
    {
        QTime start = QTime::fromString(startTimeLines[i].text(), "hh:mm");
        QTime end = QTime::fromString(endTimeLines[i].text(), "hh:mm");
        startTime[i] = start;
        endTime[i] = end;
        qDebug() << start << " " << end << bool(start == end);
        if (start == end)
        {
            queueNumber[i] = 0;
        }
        else
        {
            queueNumber[i] = startTime[i].secsTo(endTime[i]) / AddSecs;
        }
        if (queueNumber[i] == 0)
        {
            doctorDates.addBanDayOfWeek(i + 1);
        }
    }
    addDialog.close();
}

 int Doctor::getQueueNumber(const QDate &date)
 {
     return dataQueue[date].size();
 }
