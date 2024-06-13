#include "mainwindow.h"
#include "ui_mainwindow.h"

int COUNTDATES = 0;
int COLUMNCOUNT;
int ROWCOUNT;
bool DATECORRECT;
QMap <int, int> monthMap;


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    StyleSheet();

    for (int i = 1; i <= 12; ++i) {
        if (i == 2) {
            monthMap[i] = 28;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11) {
            monthMap[i] = 30;
        }
        else {
            monthMap[i] = 31;
        }
    }

    COLUMNCOUNT = ui->tableTime->columnCount();
    ROWCOUNT = ui->tableTime->rowCount();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::StyleSheet() {
    this->setStyleSheet("background-color: #1E213D;");
    ui->lineBirthday->setStyleSheet("QLineEdit {border-style: outset;"
                                    "border-width: 1px;"
                                    "border-color: #5D76CB;"
                                    "background: #0047AB;"
                                    "}");
    ui->groupBox->setStyleSheet("QGroupBox { text-color: #1E213D;"
                                "border-style: outset;"
                                "border-width: 5px;"
                                "border-color: #5D76CB;"
                                "}");
    ui->ButtonNextDay->setStyleSheet("QPushButton { "
                                     "background-color: #1E213D;"
                                     "border-style: outset;"
                                     "border-width: 2px;"
                                     "border-radius: 10px;"
                                     "border-color: #5D76CB;"
                                     "font: bold 14px;"
                                     "min-width: 10em;"
                                     "padding: 6px; "
                                     "}");
    ui->ButtonPreviousDay->setStyleSheet("QPushButton { "
                                         "background-color: #1E213D;"
                                         "border-style: outset;"
                                         "border-width: 2px;"
                                         "border-radius: 10px;"
                                         "border-color: #5D76CB;"
                                         "font: bold 14px;"
                                         "min-width: 10em;"
                                         "padding: 6px; "
                                         "}");
    ui->ButtonBirthDaySearch->setStyleSheet("QPushButton { "
                                            "background-color: #1E213D;"
                                            "border-style: outset;"
                                            "border-width: 2px;"
                                            "border-radius: 10px;"
                                            "border-color: #5D76CB;"
                                            "font: bold 14px;"
                                            "min-width: 10em;"
                                            "padding: 6px; "
                                            "}");
    ui->ButtonDuration->setStyleSheet("QPushButton { "
                                      "background-color: #1E213D;"
                                      "border-style: outset;"
                                      "border-width: 2px;"
                                      "border-radius: 10px;"
                                      "border-color: #5D76CB;"
                                      "font: bold 14px;"
                                      "min-width: 10em;"
                                      "padding: 6px; "
                                      "}");
    ui->ButtonWeek->setStyleSheet("QPushButton { "
                                      "background-color: #1E213D;"
                                      "border-style: outset;"
                                      "border-width: 2px;"
                                      "border-radius: 10px;"
                                      "border-color: #5D76CB;"
                                      "font: bold 14px;"
                                      "min-width: 10em;"
                                      "padding: 6px; "
                                      "}");
    ui->ButtonLeapYear->setStyleSheet("QPushButton { "
                                      "background-color: #1E213D;"
                                      "border-style: outset;"
                                      "border-width: 2px;"
                                      "border-radius: 10px;"
                                      "border-color: #5D76CB;"
                                      "font: bold 14px;"
                                      "min-width: 10em;"
                                      "padding: 6px; "
                                      "}");
    ui->loadDateButton->setStyleSheet("QPushButton { "
                                      "background-color: #1E213D;"
                                      "border-style: outset;"
                                      "border-width: 2px;"
                                      "border-radius: 10px;"
                                      "border-color: #5D76CB;"
                                      "font: bold 14px;"
                                      "min-width: 10em;"
                                      "padding: 6px; "
                                      "}");
    ui->tableTime->setStyleSheet("QTableWidget {"
                                 "background-color: #0047AB;"
                                 "border-style: outset;"
                                 "border-width: 5px;"
                                 "border-color: #5D76CB;"
                                 "}"
                                 "QScrollBar:vertical {"
                                 "border-style: outset;"
                                 "border-width: 1px;"
                                 "border-color: #5D76CB;"
                                 "}");
   // ui->tableTime->setRowCount(1);
    ui->tableTime->setColumnCount(3);
    ui->tableTime->setColumnWidth(0, 294);
    ui->tableTime->setColumnWidth(1, 294);
    ui->tableTime->setColumnWidth(2, 294);
    ui->tableTime->setHorizontalHeaderLabels(QStringList() << tr("Исходная дата") << tr("Следующий день")
                                                           << tr("Разница со следующим элементом"));
    ui->tableTime->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


Date MainWindow::InputValidationDate(QString dateChecked) {
    int size = dateChecked.size();
    if (size != 10) {
        DATECORRECT = false;
        return Date("", false, 0, 0, 0);
    }
    for (int i = 0; i < size; ++i) {
        if ((i == 2 || i == 5) && dateChecked.at(i) != '.') {
            DATECORRECT = false;
            return Date("", false, 0, 0, 0);
        }
        else if (!(dateChecked.at(i) >= '0' && dateChecked.at(i) <= '9') && i != 2 && i != 5) {
            DATECORRECT = false;
            return Date("", false, 0, 0, 0);
        }
    }
    int day = dateChecked.mid(0, 2).toInt();
    int month = dateChecked.mid(3, 2).toInt();
    int year = dateChecked.mid(6, 4).toInt();
    bool leapYear = false;
    if (month < 1 || month > 12) {
        DATECORRECT = false;
        return Date("", false, 0, 0, 0);
    }
    if (year < 0 || year > 9999) {
        DATECORRECT = false;
        return Date("", false, 0, 0, 0);
    }
    if (year % 4 == 0 && year % 100 != 0) {
        leapYear = true;
    }
    if (leapYear) {
        if (month == 2 && (day < 1 || day > 29)) {
            DATECORRECT = false;
            return Date("", false, 0, 0, 0);
        }
    }
    else {
        if (month == 2 && (day < 1 || day > 28)) {
            DATECORRECT = false;
            return Date("", false, 0, 0, 0);
        }
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) {
        DATECORRECT = false;
        return Date("", false, 0, 0, 0);
    }
    else if(day < 1 || day > 31) {
        DATECORRECT = false;
        return Date("", false, 0, 0, 0);
    }
    DATECORRECT = true;
    return Date(dateChecked, leapYear, day, month, year);
}


void MainWindow::InputValidation(QString checkedText) {
    QString templateChecked = "";
    int size = checkedText.size();
    int sizeDate = 0;
    bool TEMPLATECORRECT = true;
    for (int i = 0; i < size; ++i) {
        if (checkedText.at(i) == ' ' || checkedText.at(i) == '\n') {
            sizeDate = templateChecked.size();
            if (sizeDate != 10) {
                templateChecked = "";
                continue;
            }
            for (int i = 0; i < sizeDate; ++i) {
                if ((i == 2 || i == 5) && templateChecked.at(i) != '.') {
                    TEMPLATECORRECT = false;
                    break;
                }
                else if (!(templateChecked.at(i) >= '0' && templateChecked.at(i) <= '9') && i != 2 && i != 5) {
                    TEMPLATECORRECT = false;
                    break;
                }
            }
            if (TEMPLATECORRECT) {
                DateValidation(templateChecked);
            }
            templateChecked = "";
            TEMPLATECORRECT = true;
        }
        else {
            templateChecked += checkedText.at(i);
        }
    }
}


void MainWindow::DateValidation(QString dateChecked) {
    int day = dateChecked.mid(0, 2).toInt();
    int month = dateChecked.mid(3, 2).toInt();
    int year = dateChecked.mid(6, 4).toInt();
    bool leapYear = false;
    if (month < 1 || month > 12) {
        return;
    }
    if (year < 0 || year > 9999) {
        return;
    }
    if (year % 4 == 0 && year % 100 != 0) {
        leapYear = true;
    }
    if (leapYear) {
        if (month == 2 && (day < 1 || day > 29)) {
            return;
        }
    }
    else {
        if (month == 2 && (day < 1 || day > 28)) {
            return;
        }
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) {
        return;
    }
    else if(day < 1 || day > 31) {
        return;
    }
    date = new Date(dateChecked, leapYear, day, month, year);
    dates.append(date);
    InputData(date);
    COUNTDATES++;
}


void MainWindow::InputData(Date *InputDate) {
    QString Input = InputDate->DateOutput();
    QTableWidgetItem *ItemDate = new QTableWidgetItem(Input);
    QTableWidgetItem *ItemDateNext = new QTableWidgetItem(InputDate->NextDate());
    QTableWidgetItem *ItemDateDuration;
    ui->tableTime->setRowCount(COUNTDATES + 1);
    ui->tableTime->setItem(COUNTDATES, 0, ItemDate);
    ui->tableTime->setItem(COUNTDATES, 1, ItemDateNext);
    if (COUNTDATES >= 1) {
        ItemDateDuration = new QTableWidgetItem(QString::number(InputDate->Duration(*dates[COUNTDATES - 1])));
        ui->tableTime->setItem(COUNTDATES - 1, 2, ItemDateDuration);
        ItemDateDuration = new QTableWidgetItem("-");
        ui->tableTime->setItem(COUNTDATES, 2, ItemDateDuration);
    }
}

void MainWindow::CheckedTable() {
    if (ui->tableTime->rowCount() == 0) {
        QMessageBox::information(this,"Обратите внмание","В данном текстовом файле нет корректных дынных");
    }
}

void MainWindow::on_loadDateButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открытие файла", "/home/lklls1/Документы/", tr("TXT Files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл";
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    InputValidation(text);
    CheckedTable();
    file.close();

}


void MainWindow::on_ButtonNextDay_clicked() {
    QModelIndexList indexes = ui->tableTime->selectionModel()->selection().indexes();
    if (indexes.count() == 0) {
        QMessageBox::warning(this,"Внимание", "Выделите дату в строке");
    }
    for (int i = 0; i < indexes.count(); ++i) {
        QModelIndex index = indexes.at(i);
        QMessageBox::information(this,"Следующий день","Дата следующего дня - " + dates[index.row()]->NextDate());
    }
}


void MainWindow::on_ButtonPreviousDay_clicked() {
    QModelIndexList indexes = ui->tableTime->selectionModel()->selection().indexes();
    if (indexes.count() == 0) {
        QMessageBox::warning(this,"Внимание", "Выделите дату в строке");
    }
    for (int i = 0; i < indexes.count(); ++i)
    {
        QModelIndex index = indexes.at(i);
        QMessageBox::information(this,"Следующий день","Дата предыдущего дня - " + dates[index.row()]->PreviousDate());
    }
}


void MainWindow::on_ButtonDuration_clicked() {
    QDateTime date = QDateTime::currentDateTime();
    QString dateSecondSTR = date.toString("dd.MM.yyyy");
    Date dateSecond = InputValidationDate(dateSecondSTR);
    QModelIndexList indexes = ui->tableTime->selectionModel()->selection().indexes();
    if (indexes.count() == 0) {
        QMessageBox::warning(this,"Внимание", "Выделите дату в строке");
    }
    for (int i = 0; i < indexes.count(); ++i)
    {
        QModelIndex index = indexes.at(i);
        QMessageBox::information(this,"Промежуток","Промежуток между днями(в днях) - " + QString::number(dates[index.row()]->Duration(dateSecond)));
    }
}


void MainWindow::on_ButtonBirthDaySearch_clicked() {
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy");
    Date dateToday = InputValidationDate(formattedTime);
    Date dateBirthday = InputValidationDate(ui->lineBirthday->text());
    if (!DATECORRECT) {
        QMessageBox::warning(this,"Внимание", "Введите корректные данные:\n"
                                               "Первые 2 цифры означают день от 01 до 31 дня в зависимости от месяца,\n"
                                               "(Внимание 29 февраля можно ввести, когда год является високосным(кратен 4))\n"
                                               "далее необходимо ввести точку,\n"
                                               "после необходимо ввести 2 цифры месяца от 01 до 12,\n"
                                               "далее нужно ввести точку,\n"
                                               "после ввести 4 цифры года от 0000 да 9999");
        return;
    }
    QMessageBox::information(this,"День рождения","До вашего дня рождения(в днях) - " + QString::number(dateToday.DaysTillYourBirthday(dateBirthday)));
}


void MainWindow::on_ButtonLeapYear_clicked() {
    QModelIndexList indexes = ui->tableTime->selectionModel()->selection().indexes();
    if (indexes.count() == 0) {
        QMessageBox::warning(this,"Внимание", "Выделите дату в строке");
    }
    for (int i = 0; i < indexes.count(); ++i)
    {
        QModelIndex index = indexes.at(i);
        if (dates[index.row()]->IsLeapYear()) {
            QMessageBox::information(this,"Високосный год","Этот год високосный");
        }
        else {
            QMessageBox::information(this,"Високосный год","Этот год не високосный");
        }
    }
}


void MainWindow::on_ButtonWeek_clicked() {
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy");
    Date dateToday = InputValidationDate(formattedTime);
    QMessageBox::information(this,"Номер недели","Номер текущей недели - " + QString::number(dateToday.WeekNumber()));
}


void MainWindow::on_ButtonAddDate_clicked()
{
    QString Input = ui->lineAddTable->text() + " ";
    int CountDateOld = COUNTDATES;

    InputValidation(Input);
    if (CountDateOld == COUNTDATES) {
        QMessageBox::warning(this,"Внимание", "Введите корректные данные:\n"
                                               "Первые 2 цифры означают день от 01 до 31 дня в зависимости от месяца,\n"
                                               "(Внимание 29 февраля можно ввести, когда год является високосным(кратен 4))\n"
                                               "далее необходимо ввести точку,\n"
                                               "после необходимо ввести 2 цифры месяца от 01 до 12,\n"
                                               "далее нужно ввести точку,\n"
                                               "после ввести 4 цифры года от 0000 да 9999");
    }
}

