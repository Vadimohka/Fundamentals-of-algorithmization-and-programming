#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ConstMainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    ui->addButton->setIcon(QIcon(":/img/img/1709460043374.png"));
    ui->deleteButton->setIcon(QIcon(":/img/img/1709473169011.png"));

    ui->addButton->setIconSize(QSize(SIZE_ICON_IN_BUTTON, SIZE_ICON_IN_BUTTON));
    ui->deleteButton->setIconSize(QSize(SIZE_ICON_IN_BUTTON, SIZE_ICON_IN_BUTTON));

    txtFile = new QFile("/home/artem_kokhan/QT/OAIP(QT - 2 sem)/LabWork_2/Task_1/Dates.txt");
    txtFile->open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(txtFile);
    QStringList lineWords;

    while(!in.atEnd()) {
        lineWords += in.readLine();
    }

    txtFile->close();

    for (const auto & lineWord : lineWords) {
            Date tempDate;
            tempDate = tempDate.fromString(lineWord);

            txtDates.append(tempDate);
    }

    ui->tableWidget->setRowCount(txtDates.size());

    for(int row = 0; row < txtDates.size(); ++row) {
        auto *newItem = new QTableWidgetItem(QString(lineWords.at(row)).arg(row));
        ui->tableWidget->setItem(row, 0, newItem);
    }

    ui->tableWidget->setColumnWidth(0, SIZE_TABLE_WIDGET_WIDTH);

    ui->comboBox->addItem("Cегодняшяя дата");
    ui->comboBox->addItem("Завтрашняя дата");
    ui->comboBox->addItem("Вчерашняя дата");
    ui->comboBox->addItem("Является ли високосным год на календаре");
    ui->comboBox->addItem("Номер недели в году");
    ui->comboBox->addItem("Номер дня в году");
    ui->comboBox->addItem("Дней между датой на календаре и сегодняшеней датой");
    ui->comboBox->addItem("Следующий день даты из таблицы");
    ui->comboBox->addItem("Разница между датой на календаре и датой из таблицы");
    ui->comboBox->addItem("Разница между выбрнаной датой из таблицы и следующей датой из таблицы");
    ui->label->setAlignment(Qt::AlignCenter);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::calendarSlot);
    connect(timer, &QTimer::timeout, this, &MainWindow::calendarSlot);
    timer->start(SPEED_TIMER);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    switch (index) {
    case NOWDAY_METHOD:
        {
        ui->label->setText(date.toString());
        break;
        }
    case NEXT_DAY_METHOD:
    {
        ui->label->setText(date.nextDay().toString());
        break;
    }
    case PREVIOUS_DAY_METHOD:
    {
        ui->label->setText(date.previousDay().toString());
        break;
    }
    case WEEK_NUMBER_METHOD:
    {
        ui->label->setText(QString::number(date.weekNumber()) + " неделя");
        break;
    }
    case DAY_NUMBER_OF_YEAR_METHOD:
    {
        ui->label->setText(QString::number(date.dayNumber()) + "дн");
        break;
    }
    default:{}
    }
}

void MainWindow::calendarSlot() {
    if(ui->comboBox->currentIndex() == DURATION_METHOD) {
        Date tempDate;

        tempDate.setDay(ui->calendarWidget->selectedDate().day());
        tempDate.setMonth(ui->calendarWidget->selectedDate().month());
        tempDate.setYear(ui->calendarWidget->selectedDate().year());

        ui->label->setText(QString::number(date.Duration(tempDate)) + "дн");
    }

    else if(ui->comboBox->currentIndex() == LEAP_DAY_METHOD) {
        Date tempDate;

        tempDate.setYear(ui->calendarWidget->yearShown());

        (tempDate.isLeap())? ui->label->setText("Является високосным"): ui->label->setText("Не является високосным");
    }

    else if(ui->comboBox->currentIndex() == NEXT_DAY_FROM_THE_TABLE && ui->tableWidget->currentRow()!= NO_VALUE_SELECTED_ON_THE_COMBOBOX) {
        ui->label->setText(txtDates.at(ui->tableWidget->currentRow()).nextDay().toString());
    }

    else if(ui->comboBox->currentIndex() == DURATION_BETWEEN_DATE_ON_CALENDAR_AND_TABLE &&
             ui->tableWidget->currentRow()!= NO_VALUE_SELECTED_ON_THE_COMBOBOX) {
        Date tempDate;

        tempDate.setDay(ui->calendarWidget->selectedDate().day());
        tempDate.setMonth(ui->calendarWidget->selectedDate().month());
        tempDate.setYear(ui->calendarWidget->selectedDate().year());
        ui->label->setText(QString::number(txtDates.at(ui->tableWidget->currentRow()).Duration(tempDate))
                           + "дн");
    }

    else if(ui->comboBox->currentIndex() == DURATION_BETWEEN_DATE_ON_TABLE_AND_NEXT_DATE_TABLE &&
             ui->tableWidget->currentRow()!= NO_VALUE_SELECTED_ON_THE_COMBOBOX) {

        if(ui->tableWidget->currentRow() != txtDates.size() - 1){
            ui->label->setText(QString::number(txtDates.at(ui->tableWidget->currentRow()).Duration(
                               txtDates.at(ui->tableWidget->currentRow() + 1))) + "дн");
        }

        else {
            ui->label->setText(QString::number(txtDates.at(ui->tableWidget->currentRow()).Duration(
                                txtDates.at(0))) + "дн");
        }
    }
}

void MainWindow::tableSlot()
{
    if(ui->tableWidget->currentRow() != NO_VALUE_SELECTED_ON_THE_COMBOBOX) {
        Date tempDate, firstDate;

        tempDate = tempDate.fromString(ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text());

        ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->setText(tempDate.toString());

        if(tempDate.toString() != txtDates.at(ui->tableWidget->currentRow()).toString()) {
            txtDates[ui->tableWidget->currentRow()].setDay(tempDate.getDay());
            txtDates[ui->tableWidget->currentRow()].setMonth(tempDate.getMonth());
            txtDates[ui->tableWidget->currentRow()].setYear(tempDate.getYear());

            txtFile->open(QIODevice::ReadWrite);
            QTextStream stream(txtFile);

            for(short currentLine = 0; !stream.atEnd(); ++currentLine) {
                short position = stream.pos();
                stream.readLine();
                qDebug() << ui->tableWidget->currentRow();
                if (currentLine == ui->tableWidget->currentRow()) {
                    txtFile->seek(position);
                    stream << tempDate.toString();
                    break;
                }
            }

            txtFile->close();
        }
    }
}


void MainWindow::on_addButton_clicked()
{
    Date tempDate;
    txtFile->open(QIODevice::Append | QIODevice::Text);
    QTextStream out(txtFile);

    tempDate.setDay(ui->calendarWidget->selectedDate().day());
    tempDate.setMonth(ui->calendarWidget->monthShown());
    tempDate.setYear(ui->calendarWidget->yearShown());

    txtDates.append(tempDate);

    out << tempDate.toString() + "\n";

    txtFile->close();

    ui->tableWidget->setRowCount(txtDates.size());
    auto *newItem = new QTableWidgetItem(tempDate.toString());
    ui->tableWidget->setItem(txtDates.size() - 1, 0, newItem);
}

void MainWindow::on_deleteButton_clicked()
{
        txtFile->open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream out(txtFile);

        QString str;
        txtDates.clear();

        while(!out.atEnd()) {
            QString line = out.readLine();
            if(!line.contains("00.00.0000")) { // Условие для удаления строки
                str.append(line + "\n");
            txtDates.append(Date::fromString(line));
            }
        }
        txtFile->resize(0); // Очистка файла
        out << str; // Запись измененного содержимого обратно в файл
        txtFile->close();

        for(int row = 0; row < txtDates.size(); ++row) {
            auto *newItem = new QTableWidgetItem(txtDates.at(row).toString());
            ui->tableWidget->setItem(row, 0, newItem);
        }

        ui->tableWidget->setRowCount(txtDates.size());
}

void MainWindow::changeEvent(QEvent *e)
{
    if (e->type() == QEvent::ActivationChange && this->isActiveWindow()) {
        txtFile->open(QIODevice::ReadOnly | QIODevice::Text);
        ui->tableWidget->setRowCount(0);
        QTextStream in(txtFile);
        QStringList lineWords;

        while (!in.atEnd()) {
            lineWords += in.readLine();
        }

        txtFile->close();

        txtDates.resize(0);
        for (const auto &lineWord : lineWords) {
            Date tempDate;
            tempDate = tempDate.fromString(lineWord);

            txtDates.append(tempDate);
        }

        ui->tableWidget->setRowCount(txtDates.size());

        for (int row = 0; row < txtDates.size(); ++row) {
            auto *newItem = new QTableWidgetItem(QString(lineWords.at(row)).arg(row));
            ui->tableWidget->setItem(row, 0, newItem);
        }
    }
}
