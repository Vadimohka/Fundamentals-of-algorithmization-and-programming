#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_currentDate = getCurrentDate();

    this->getDatesFromFile();
    this->fillTable();

    ui->label->setText(getCurrentDate()->Output());
    ui->label_8->setVisible(false);
    ui->label_10->setText(QString::number(this->getCurrentDate()->DaysTillYourBirthday(Date(1,1,1))));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_currentDate;
}


Date* MainWindow::getCurrentDate()
{    
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;

    Date* CurrentDate = new Date(day, month, year);
    return CurrentDate;
}


void MainWindow::getDatesFromFile()
{
    m_datesFromFile.clear();

    std::ifstream datesInputFile(m_filePath);

    if (datesInputFile.is_open())
    {
        std::string line;
        while (std::getline(datesInputFile, line))
            m_datesFromFile.push_back(Date(line));

        datesInputFile.close();
    }
}


void MainWindow::fillTable()
{
    this->clearTable();

    for (int i = 0; i < m_datesFromFile.size(); ++i)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0,
                                 new QTableWidgetItem(m_datesFromFile[i].Output()));

        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1,
                                 new QTableWidgetItem(m_datesFromFile[i].NextDay().Output()));

        if (ui->tableWidget->rowCount() != 1)
        {
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 2, 2,
                                     new QTableWidgetItem(QString::number(m_datesFromFile[i-1].Duration(m_datesFromFile[i]))));
        }

        if (m_datesFromFile[i].PreviousDate().Year() < 1)
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3,
                                     new QTableWidgetItem("Год до нашей эры..."));
        else
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3,
                                 new QTableWidgetItem(m_datesFromFile[i].PreviousDate().Output()));
    }
}

void MainWindow::clearTable()
{
    for (int i = ui->tableWidget->rowCount() - 1; i >= 0; --i)
        ui->tableWidget->removeRow(i);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    Date birthdayDate(arg1, ui->spinBox_2->value(), ui->spinBox_3->value());
    this->setDaysTillBirthday(birthdayDate);
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    Date birthdayDate(ui->spinBox->value(), arg1, ui->spinBox_3->value());
    this->setDaysTillBirthday(birthdayDate);
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    Date birthdayDate(ui->spinBox->value(), ui->spinBox_2->value(), arg1);
    this->setDaysTillBirthday(birthdayDate);
}


void MainWindow::setDaysTillBirthday(Date birthdayDate)
{
    ui->label_10->setText(QString::number(this->getCurrentDate()->DaysTillYourBirthday(birthdayDate)));
    ui->label_8->setVisible(false);
    ui->label_7->setVisible(true);

    if (ui->spinBox->value() > birthdayDate.daysInMonth(ui->spinBox_2->value()))
    {
        ui->label_7->setVisible(false);
        ui->label_8->setVisible(true);
        ui->label_10->setText("Incorrect date");
    }
}


void MainWindow::on_pushButton_clicked()
{
    std::ofstream datesInputFile(m_filePath, std::ios::app);

    if (datesInputFile.is_open())
    {
        Date newDate(ui->spinBox_4->value(), ui->spinBox_5->value(), ui->spinBox_6->value());

        if (ui->spinBox_4->value() > newDate.daysInMonth(ui->spinBox_5->value()))
            QMessageBox::critical(this, "Ошибка", "Такой даты не существует.");
        else
        {
            datesInputFile << newDate.Day() << '.' << newDate.Month() << '.' << newDate.Year() << '\n';
        }
        datesInputFile.close();

        getDatesFromFile();
        fillTable();
    }
    else
        QMessageBox::critical(this, "Ошибка", "Файл не открыт.");
}


void MainWindow::on_pushButton_2_clicked()
{
    Date newDate(ui->spinBox_7->value(), ui->spinBox_8->value(), ui->spinBox_9->value());

    if (ui->spinBox_7->value() > newDate.daysInMonth(ui->spinBox_8->value()))
        QMessageBox::critical(this, "Ошибка", "Такой даты не существует.");
    else
    {
        int selectedRowItem = ui->tableWidget->currentRow();
        int selectedColumnItem = ui->tableWidget->currentColumn();

        if (selectedRowItem && selectedColumnItem == 0)
        {
            ui->tableWidget->setItem(selectedRowItem, 0,
                                     new QTableWidgetItem(newDate.Output()));
        }
        else
            QMessageBox::critical(this, "Ошибка", "Дата не выбрана/это поле нельзя изменить.");
    }

    std::ofstream datesInputFile(m_filePath);

    if (datesInputFile.is_open())
    {
        for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
            datesInputFile << (ui->tableWidget->item(i, 0)->text()).toStdString() << '\n';
    }

    datesInputFile.close();

    getDatesFromFile();
    fillTable();
}



void MainWindow::on_pushButton_3_clicked()
{
    std::string newFilePath = (QFileDialog::getOpenFileName(nullptr, "Открыть файл", "", "Текстовые файлы (*.txt);;Все файлы (*.*)")).toStdString();

    if (!newFilePath.empty())
        m_filePath = newFilePath;

    this->getDatesFromFile();
    this->fillTable();
}

