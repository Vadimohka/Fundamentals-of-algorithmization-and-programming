#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), comboBox(&addTicketDialog)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    int posX = (screenGeometry.width() - this->width()) / 2;
    int posY = (screenGeometry.height() - this->height()) / 2;
    this->move(posX, posY);

    ui->setupUi(this);

    addTicketDialog.setFixedSize(ADD_TICKET_DIALOG_WIDTH, ADD_TICKET_DIALOG_HEIGHT);
    addTicketDialog.setWindowTitle("Выберите врача");
    deleteDoctorDialog.setFixedSize(ADD_TICKET_DIALOG_WIDTH, ADD_TICKET_DIALOG_HEIGHT);
    deleteDoctorDialog.setWindowTitle("Выберите врача");
    comboBox.setFixedSize(DOCTOR_INFO_WIDTH, DOCTOR_INFO_HEIGHT);
    addTicketButton.setText("Записаться");
    deleteDoctorButton.setText("Удалить расписание врача");

    ticketLayout = new QVBoxLayout(&addTicketDialog);
    deleteLayout = new QVBoxLayout(&deleteDoctorDialog);

    QVBoxLayout layout(&showCalendar);
    layout.addWidget(&calendar);
    dateSelected.setText("Выберите дату");
    QObject::connect(&dateSelected, &QPushButton::clicked,  this, &MainWindow::dateSelect);
    layout.addWidget(&dateSelected);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addDoctorButton_clicked()
{
    Doctor doctor;
    doctor.addDoctor();

    if (doctor.name.getName() == "") return;
    doctors.push_back(doctor);

    std::sort(doctors.begin(), doctors.end(), [](const Doctor &a, const Doctor &b) {
        return a.name.getSurname()+a.name.getName()+a.name.getPatronymic() < b.name.getSurname()+b.name.getName()+b.name.getPatronymic();
    });
    for (auto &doctor:doctors) qDebug() << doctor.getInfo();
}

void MainWindow::on_addTicketButton_clicked()
{

    comboBox.clear();
    for (auto &doctor : doctors)
    {
        comboBox.addItem(doctor.getInfo());
    }

    ticketLayout->addWidget(&comboBox);
    QObject::connect(&addTicketButton, &QPushButton::clicked, this, &MainWindow::doctorSelected);
    ticketLayout->addWidget(&addTicketButton);

    addTicketDialog.exec();
}

void MainWindow::doctorSelected()
{
    qDebug() << "OK";
    if (comboBox.currentIndex() == -1)
    {
        QMessageBox::warning(nullptr, "Ошибка", "К сожалению невозможно записать ни к одному из врачей...");
        return;
    }

    addTicketDialog.close();
    doctors[comboBox.currentIndex()].selectDate();
}


void MainWindow::on_deleteDoctorButton_clicked()
{

    comboBox.clear();
    for (auto &doctor : doctors)
    {
        comboBox.addItem(doctor.getInfo());
    }

    deleteLayout->addWidget(&comboBox);
    QObject::connect(&deleteDoctorButton, &QPushButton::clicked, this, &MainWindow::doctorDeleteSelected);
    deleteLayout->addWidget(&deleteDoctorButton);

    deleteDoctorDialog.exec();
}

void MainWindow::doctorDeleteSelected()
{
    if (comboBox.currentIndex() == -1)
    {
        QMessageBox::warning(nullptr, "Ошибка", "Выберите врача");
        return;
    }

    deleteDoctorDialog.close();
    doctors.erase(doctors.begin() + comboBox.currentIndex());
}



void MainWindow::on_dateQueue_clicked()
{
    calendar.show();
    QVBoxLayout layout(&showCalendar);
    showCalendar.exec();
}

void MainWindow::dateSelect()
{
    QDate date(2024, 4, 16);
    showCalendar.close();
    QVBoxLayout layout(&showQueueNumber);
    for (auto &doctor:doctors)
    {
        QString str = doctor.getInfo()+"\nКоличество приёмов в данный день: "+QString::number(doctor.getQueueNumber(date));
        QLabel label(str);
        layout.addWidget(&label);
    }
    showQueueNumber.exec();
}

