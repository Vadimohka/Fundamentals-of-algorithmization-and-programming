#include "../Headers/Widget.h"

#define DEBUG

Widget::Widget(QWidget *parent) : QWidget(parent) {
    service = new DateService(/*3,5,1900*/);

    closeButton = new QPushButton("Close", this);
    closeButton->setGeometry(1820, 10, 90, 30);
    connect(closeButton, SIGNAL(clicked(bool)), SLOT(close()));

    fileButton = new QPushButton("Open file", this);
    fileButton->setGeometry(1820, 50, 90, 30);
    DateService::connect(fileButton, SIGNAL(clicked(bool)), service, SLOT(setPath()));
    connect(fileButton, SIGNAL(clicked(bool)), SLOT(showTable()));

    addToFileButton = new QPushButton("Add to file", this);
    addToFileButton->setGeometry(1820, 90, 90, 30);
    connect(addToFileButton, SIGNAL(clicked()), SLOT(addToFile()));

    birthDayButton = new QPushButton("Set birthday", this);
    birthDayButton->setGeometry(1820, 130, 90, 30);
    connect(birthDayButton, SIGNAL(clicked()), SLOT(addBirthDay()));

    redactButton = new QPushButton("Redact", this);
    redactButton->setGeometry(1820, 170, 55, 30);
    connect(redactButton, SIGNAL(clicked(bool)), SLOT(redactFile()));
    redactScrollBar = new QSpinBox(this);
    redactScrollBar->setGeometry(1880, 170, 30, 30);
    redactScrollBar->setMinimum(0);
    redactScrollBar->setMaximum(0);
    redactScrollBar->hide();

    timer = new QTimer;
    timer->start(1);

    //connect(timer, SIGNAL(timeout()),SLOT(showTable()));

    dayLineEdit = new QLineEdit(this);
    dayLineEdit->setGeometry(1820, 210, 90, 30);
    monthLineEdit = new QLineEdit(this);
    monthLineEdit->setGeometry(1820, 250, 90, 30);
    yearLineEdit = new QLineEdit(this);
    yearLineEdit->setGeometry(1820, 290, 90, 30);

    dateTable = new QTableWidget(this);
    dateTable->setGeometry(10, 10, 1800, 1060);
    dateTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    dateTable->setColumnCount(6);
    dateTable->setRowCount(0);
    dateTable->setColumnWidth(0, 300);
    dateTable->setColumnWidth(1, 300);
    dateTable->setColumnWidth(2, 300);
    dateTable->setColumnWidth(3, 300);
    dateTable->setColumnWidth(4, 300);
    dateTable->setColumnWidth(5, 300);
    dateTable->setHorizontalHeaderLabels(
            QStringList() << "previous" << "this" << "next" << "days from today" << "number of days"
                          << "number of week");
    showTable();
}

void Widget::addToFile() {
    uint day = dayLineEdit->text().toInt();
    uint month = monthLineEdit->text().toInt();
    uint year = yearLineEdit->text().toInt();
    Date inputDate = Date(day, month, year);
    if (inputDate.year() != 0) {
        service->addToFile(inputDate);
        showTable();
    } else {
        dayLineEdit->setText("Error");
        monthLineEdit->setText("Error");
        yearLineEdit->setText("Error");
        QTimer::singleShot(600, this, SLOT(setSpaces()));
    }
}

void Widget::showTable() {
    service->readFile();
    dateTable->setRowCount(service->_date.size() + 2);
    if (service->_date.size() != 0) {
        redactScrollBar->setMinimum(3);
        redactScrollBar->setMaximum(dateTable->rowCount());
    }
    redactScrollBar->show();
    QString isLeap = service->todayDate().isLeap() ? "leap" : "not leap";
    QTableWidgetItem *temp = new QTableWidgetItem(QString(ZERO_D_T +
                                                          QString::number(service->todayDate().day()) + '.' +
                                                          ZERO_M_T +
                                                          QString::number(service->todayDate().month()) + '.' +
                                                          ZERO_Y_T +
                                                          QString::number(service->todayDate().year()) + ' ' + isLeap));
    temp->setBackgroundColor(Qt::green);
    dateTable->setItem(0, 1, temp);
    Date previousDate = service->todayDate().previousDay();
    isLeap = previousDate.isLeap() ? "leap" : "not leap";
    if (previousDate.year() > 0) {
        temp = new QTableWidgetItem(QString(ZERO_D_P +
                                            QString::number(previousDate.day()) + '.' +
                                            ZERO_M_P +
                                            QString::number(previousDate.month()) +
                                            ZERO_Y_P +
                                            '.' + QString::number(previousDate.year()) + ' ' + isLeap));
    } else {
        temp = new QTableWidgetItem("no such date");
    }
    temp->setBackgroundColor(Qt::green);
    dateTable->setItem(0, 0, temp);
    Date nextDate = service->todayDate().nextDay();
    isLeap = nextDate.isLeap() ? "leap" : "not leap";
    if (nextDate.year() != 0) {
        temp = new QTableWidgetItem(QString(ZERO_D_N +
                                            QString::number(nextDate.day()) + '.' +
                                            ZERO_M_N +
                                            QString::number(nextDate.month()) + '.' +
                                            ZERO_Y_N +
                                            QString::number(nextDate.year()) + ' ' + isLeap));
    } else {
        temp = new QTableWidgetItem("no such date");
    }
    temp->setBackgroundColor(Qt::green);
    dateTable->setItem(0, 2, temp);
    temp = new QTableWidgetItem(QString::number(service->todayDate().difference(Date())));
    temp->setBackgroundColor(Qt::green);
    dateTable->setItem(0, 3, temp);
    int dayOfWeekNumber = service->todayDate().dayOfWeek();
    QString dayOfWeekString;
    switch (dayOfWeekNumber) {
        case 0:
        case 7:
            dayOfWeekString = "sunday";
            break;
        case 1:
            dayOfWeekString = "monday";
            break;
        case 2:
            dayOfWeekString = "tuesday";
            break;
        case 3:
            dayOfWeekString = "wednesday";
            break;
        case 4:
            dayOfWeekString = "thursday";
            break;
        case 5:
            dayOfWeekString = "friday";
            break;
        case 6:
            dayOfWeekString = "saturday";
            break;
        default:
            dayOfWeekString = "";
            break;
    }
    temp = new QTableWidgetItem(dayOfWeekString);
    temp->setBackgroundColor(Qt::green);
    dateTable->setItem(0, 4, temp);
    temp = new QTableWidgetItem(QString::number(service->todayDate().numberOfWeek()));
    temp->setBackgroundColor(Qt::green);
    dateTable->setItem(0, 5, temp);

    qDebug() << 3;
    // BirthDay
    if (service->birthDayDate().year() != 0) {
        qDebug() << 5;
        isLeap = service->birthDayDate().isLeap() ? "leap" : "not leap";
        temp = new QTableWidgetItem(QString(ZERO_D_B +
                                            QString::number(service->birthDayDate().day()) + '.' +
                                            ZERO_M_B +
                                            QString::number(service->birthDayDate().month()) + '.' +
                                            ZERO_Y_B +
                                            QString::number(service->birthDayDate().year()) + ' ' + isLeap));
        qDebug() << 6;
        temp->setBackgroundColor(Qt::red);
        dateTable->setItem(1, 1, temp);
        qDebug() << "i";
        previousDate = service->birthDayDate().previousBirthDay();
        qDebug() << "p";
        isLeap = previousDate.isLeap() ? "leap" : "not leap";
        qDebug() << 7;
        if (previousDate.year() > 0) {
            temp = new QTableWidgetItem(QString(ZERO_D_P +
                                                QString::number(previousDate.day()) + '.' +
                                                ZERO_M_P +
                                                QString::number(previousDate.month()) + '.' +
                                                ZERO_Y_P +
                                                QString::number(previousDate.year()) + ' ' + isLeap));
        } else {
            temp = new QTableWidgetItem("no such date");
        }


        temp->setBackgroundColor(Qt::red);
        dateTable->setItem(1, 0, temp);
        nextDate = service->birthDayDate().nextBirthDay();
        isLeap = nextDate.isLeap() ? "leap" : "not leap";
        if (nextDate.year() != 0) {
            qDebug() << 10.1;
            temp = new QTableWidgetItem(QString(ZERO_D_N +
                                                QString::number(nextDate.day()) + '.' +
                                                ZERO_M_N +
                                                QString::number(nextDate.month()) + '.' +
                                                ZERO_Y_N +
                                                QString::number(nextDate.year()) + ' ' + isLeap));
        } else {
            qDebug() << 10.2;
            temp = new QTableWidgetItem("no such date");
        }
        temp->setBackgroundColor(Qt::red);
        dateTable->setItem(1, 2, temp);
        temp = new QTableWidgetItem(QString::number(service->birthDayDate().difference(Date())));
        temp->setBackgroundColor(Qt::red);
        dateTable->setItem(1, 3, temp);
        int dayOfWeekNumber = service->birthDayDate().dayOfWeek();
        QString dayOfWeekString;
        switch (dayOfWeekNumber) {
            case 0:
            case 7:
                dayOfWeekString = "sunday";
                break;
            case 1:
                dayOfWeekString = "monday";
                break;
            case 2:
                dayOfWeekString = "tuesday";
                break;
            case 3:
                dayOfWeekString = "wednesday";
                break;
            case 4:
                dayOfWeekString = "thursday";
                break;
            case 5:
                dayOfWeekString = "friday";
                break;
            case 6:
                dayOfWeekString = "saturday";
                break;
            default:
                dayOfWeekString = "";
                break;
        }
        temp = new QTableWidgetItem(dayOfWeekString);
        temp->setBackgroundColor(Qt::red);
        dateTable->setItem(1, 4, temp);
        temp = new QTableWidgetItem(QString::number(service->birthDayDate().numberOfWeek()));
        temp->setBackgroundColor(Qt::red);
        dateTable->setItem(1, 5, temp);
    } else {
        for (int i = 0; i < 6; i++) {
            temp = new QTableWidgetItem;
            temp->setBackgroundColor(Qt::red);
            dateTable->setItem(1, i, temp);
        }
    }
    for (int ID = 0; ID < service->_date.size(); ID++) {
        qDebug() << ID;
        isLeap = service->_date[ID].isLeap() ? "leap" : "not leap";
        temp = new QTableWidgetItem(QString(ZERO_D_ID +
                                            QString::number(service->_date[ID].day()) + '.' +
                                            ZERO_M_ID +
                                            QString::number(service->_date[ID].month()) + '.' +
                                            ZERO_Y_ID +
                                            QString::number(service->_date[ID].year()) + ' ' + isLeap));
        dateTable->setItem(ID + 2, 1, temp);
        previousDate = service->_date[ID].previousDay();
        isLeap = previousDate.isLeap() ? "leap" : "not leap";
        if (previousDate.year() > 0) {
            temp = new QTableWidgetItem(QString(ZERO_D_P +
                                                QString::number(previousDate.day()) + '.' +
                                                ZERO_M_P +
                                                QString::number(previousDate.month()) + '.' +
                                                ZERO_Y_P +
                                                QString::number(previousDate.year()) + ' ' + isLeap));
        } else {
            temp = new QTableWidgetItem("no such date");
        }
        dateTable->setItem(ID + 2, 0, temp);
        nextDate = service->_date[ID].nextDay();
        isLeap = nextDate.isLeap() ? "leap" : "not leap";
        if (nextDate.year() < 10000) {
            temp = new QTableWidgetItem(QString(ZERO_D_N +
                                                QString::number(nextDate.day()) + '.' +
                                                ZERO_M_N +
                                                QString::number(nextDate.month()) + '.' +
                                                ZERO_Y_N +
                                                QString::number(nextDate.year()) + ' ' + isLeap));
        } else {
            temp = new QTableWidgetItem("no such date");
        }
        dateTable->setItem(ID + 2, 2, temp);
        if (ID != 0) {
            temp = new QTableWidgetItem(QString::number(service->_date[ID].difference(service->_date[ID - 1])));
            dateTable->setItem(ID + 1, 3, temp);
        }
        temp = new QTableWidgetItem(QString::number(service->_date[ID].difference(Date())));
        dateTable->setItem(ID + 2, 3, temp);
        int dayOfWeekNumber = service->_date[ID].dayOfWeek();
        QString dayOfWeekString;
        switch (dayOfWeekNumber) {
            case 0:
            case 7:
                dayOfWeekString = "sunday";
                break;
            case 1:
                dayOfWeekString = "monday";
                break;
            case 2:
                dayOfWeekString = "tuesday";
                break;
            case 3:
                dayOfWeekString = "wednesday";
                break;
            case 4:
                dayOfWeekString = "thursday";
                break;
            case 5:
                dayOfWeekString = "friday";
                break;
            case 6:
                dayOfWeekString = "saturday";
                break;
            default:
                dayOfWeekString = "";
                break;
        }
        temp = new QTableWidgetItem(dayOfWeekString);
        dateTable->setItem(ID + 2, 4, temp);
        temp = new QTableWidgetItem(QString::number(service->_date[ID].numberOfWeek()));
        dateTable->setItem(ID + 2, 5, temp);
    }
}

void Widget::addBirthDay() {
    uint day = dayLineEdit->text().toInt();
    uint month = monthLineEdit->text().toInt();
    qDebug() << month;
    uint year = yearLineEdit->text().toInt();
    Date inputDate = Date(day, month, year);
    if (inputDate.year() != 0) {
        service->setBirthDay(inputDate);
        qDebug() << 1;
        showTable();
        qDebug() << 1;
    } else {
        dayLineEdit->setText("Error");
        monthLineEdit->setText("Error");
        yearLineEdit->setText("Error");
        QTimer::singleShot(600, this, SLOT(setSpaces()));
    }
}

void Widget::redactFile() {
    uint day = dayLineEdit->text().toInt();
    uint month = monthLineEdit->text().toInt();
    uint year = yearLineEdit->text().toInt();
    Date inputDate = Date(day, month, year);
    if (inputDate.year() != 0) {
        service->redactFile(inputDate, redactScrollBar->value());
        showTable();
    } else {
        dayLineEdit->setText("Error");
        monthLineEdit->setText("Error");
        yearLineEdit->setText("Error");
        QTimer::singleShot(600, this, SLOT(setSpaces()));
    }
}

void Widget::setSpaces() {
    dayLineEdit->setText("");
    monthLineEdit->setText("");
    yearLineEdit->setText("");
}

