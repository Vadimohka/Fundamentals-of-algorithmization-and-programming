#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ConstMainWindow.h"
#include "ConstNumber.h"

#include <QDate>
#include <QtAlgorithms>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer)
    , addCompany(new AddCompany)
    , addPerson(new AddPerson)
{
    ui->setupUi(this);
    ui->tableCompany->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablePerson->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablePerson->setCurrentCell(NO_VALUE_SELECTED_ON_THE_TABLE, NO_VALUE_SELECTED_ON_THE_TABLE);

    addCompanySlot();
    addPersonSlot();

    connect(timer, &QTimer::timeout, this, &MainWindow::companySlot);
    connect(timer, &QTimer::timeout, this, &MainWindow::personSlot);
    connect(addCompany, &AddCompany::addSignal, this, &MainWindow::addCompanySlot);
    connect(addPerson, &AddPerson::addSignal, this, &MainWindow::addPersonSlot);
    timer->start(SPEED_TIMER);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::companySlot()
{
    if(ui->tableCompany->currentRow() != NO_VALUE_SELECTED_ON_THE_TABLE && ui->tableCompany->currentColumn() != NO_VALUE_SELECTED_ON_THE_TABLE) {

        if(ui->tableCompany->item(ui->tableCompany->currentRow(), ui->tableCompany->currentColumn())->text() !=
            companies[ui->tableCompany->currentRow()][ui->tableCompany->currentColumn()]){

            companies[ui->tableCompany->currentRow()][ui->tableCompany->currentColumn()] =
                ui->tableCompany->item(ui->tableCompany->currentRow(), ui->tableCompany->currentColumn())->text();

            if(ui->tableCompany->currentColumn() == SALARY_SELECTED_ON_THE_COMPANY_TABLE && (!ui->tableCompany->item(ui->tableCompany->currentRow(),
                ui->tableCompany->currentColumn())->text().toDouble() || ui->tableCompany->item(ui->tableCompany->currentRow(),
                ui->tableCompany->currentColumn())->text().toDouble() < 0)){

                companies[ui->tableCompany->currentRow()][ui->tableCompany->currentColumn()] = "0";

                if(ui->tableCompany->item(ui->tableCompany->currentRow(),
                    ui->tableCompany->currentColumn())->text() == "Нет информации"){
                    companies[ui->tableCompany->currentRow()][ui->tableCompany->currentColumn()] = "Нет информации";
                }
            }

            else if(ui->tableCompany->currentColumn() == HOLIDAY_SELECTED_ON_THE_COMPANY_TABLE && (!ui->tableCompany->item(ui->tableCompany->currentRow(),
                    ui->tableCompany->currentColumn())->text().toInt() || ui->tableCompany->item(ui->tableCompany->currentRow(),
                    ui->tableCompany->currentColumn())->text().toInt() < 0)){
                companies[ui->tableCompany->currentRow()][ui->tableCompany->currentColumn()] = "0";

                if(ui->tableCompany->item(ui->tableCompany->currentRow(),
                    ui->tableCompany->currentColumn())->text() == "Нет информации"){
                    companies[ui->tableCompany->currentRow()][ui->tableCompany->currentColumn()] = "Нет информации";
                }
            }

            else if((ui->tableCompany->currentColumn() == MIN_AGE_SELECTED_ON_THE_COMPANY_TABLE ||
                     ui->tableCompany->currentColumn() == MAX_AGE_SELECTED_ON_THE_COMPANY_TABLE)
                    && (!ui->tableCompany->item(ui->tableCompany->currentRow(),
                    ui->tableCompany->currentColumn())->text().toInt() || ui->tableCompany->item(ui->tableCompany->currentRow(),
                    ui->tableCompany->currentColumn())->text().toInt() < 0)){
                companies[ui->tableCompany->currentRow()][ui->tableCompany->currentColumn()] = "0";
            }

            addCompany->getTxt()->open(QIODevice::Append | QIODevice::Text | QIODevice::Truncate);
            QTextStream out(addCompany->getTxt());

            for (int row = 0; row < companies.size(); ++row) {
                for (int column = 0; column < companies[0].size(); ++column) {
                    ui->tableCompany->item(row, column)->setText(companies[row][column]);
                    out << companies[row][column] + "\n";

                    if(column == companies[0].size() - 1) {
                        out << "\n";
                    }
                }
            }

            addCompany->getTxt()->close();
        }

    }
}

void MainWindow::personSlot()
{

    if(ui->tablePerson->currentRow() != NO_VALUE_SELECTED_ON_THE_TABLE && ui->tablePerson->currentColumn() != NO_VALUE_SELECTED_ON_THE_TABLE) {

        if(ui->tablePerson->item(ui->tablePerson->currentRow(), ui->tablePerson->currentColumn())->text() !=
            people[ui->tablePerson->currentRow()][ui->tablePerson->currentColumn()]){

            QString lastValue = people[ui->tablePerson->currentRow()][ui->tablePerson->currentColumn()];

            people[ui->tablePerson->currentRow()][ui->tablePerson->currentColumn()] =
               ui->tablePerson->item(ui->tablePerson->currentRow(), ui->tablePerson->currentColumn())->text();

            if(ui->tablePerson->currentColumn() == DATE_SELECTED_ON_THE_PERSON_TABLE){

                QString value = people[ui->tablePerson->currentRow()][ui->tablePerson->currentColumn()];

                if(value.size() != SIZE_DATE)
                {
                    value = lastValue;
                }

                else if(value.at(NUMBER_FIRST_DOT_IN_DATE) != '.' ||
                        value.at(NUMBER_SECOND_DOT_IN_DATE) != '.' ||
                        !(value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() > 0) ||
                        !(value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() <= countMonth) ||
                        !(value.left(SIZE_STRING_DAY).toInt() > 0) ||
                        !(value.mid(FIRST_NUMBER_YEAR_IN_DATE, SIZE_STRING_YEAR).toInt() > 0))
                {
                    value = lastValue;
                }


                else if((value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberApril ||
                         value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberJune ||
                         value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberSeptember ||
                         value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberNovember) &&
                         value.left(SIZE_STRING_DAY).toInt() > MAX_DAY30)
                {
                    value = lastValue;
                }

                else if((value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberJanuary ||
                         value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberMarch ||
                         value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberMay ||
                         value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberJuly ||
                         value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberAugust ||
                         value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberOctober ||
                         value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberDecember) &&
                         value.left(SIZE_STRING_DAY).toInt() > MAX_DAY31)
                {
                    value = lastValue;
                }

                else if(value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberFebruary &&
                        value.mid(FIRST_NUMBER_YEAR_IN_DATE, SIZE_STRING_YEAR).toInt() % 4 == 0 &&
                        value.left(SIZE_STRING_DAY).toInt() > MAX_DAY29)
                {
                    value = lastValue;
                }

                else if(value.mid(FIRST_NUMBER_MONTH_IN_DATE, SIZE_STRING_MONTH).toInt() == numberFebruary &&
                        value.mid(FIRST_NUMBER_YEAR_IN_DATE, SIZE_STRING_YEAR).toInt() % 4 != 0 &&
                        value.left(SIZE_STRING_DAY).toInt() > MAX_DAY28)
                {
                    value = lastValue;
                }

                people[ui->tablePerson->currentRow()][ui->tablePerson->currentColumn()] = value;
            }

            else if(ui->tablePerson->currentColumn() == SALARY_SELECTED_ON_THE_PERSON_TABLE && (!ui->tablePerson->item(ui->tablePerson->currentRow(),
                    ui->tablePerson->currentColumn())->text().toDouble() ||
                    ui->tablePerson->item(ui->tablePerson->currentRow(),
                    ui->tablePerson->currentColumn())->text().toDouble() < 0))
            {
                people[ui->tablePerson->currentRow()][ui->tablePerson->currentColumn()] = "0";

                if(ui->tablePerson->item(ui->tablePerson->currentRow(),
                    ui->tablePerson->currentColumn())->text() == "Не указано")
                {
                        people[ui->tablePerson->currentRow()][ui->tablePerson->currentColumn()] = "Не указано";
                }
            }

            addPerson->getTxt()->open(QIODevice::Append | QIODevice::Text | QIODevice::Truncate);
            QTextStream out(addPerson->getTxt());

            for (int row = 0; row < people.size(); ++row) {
                for (int column = 0; column < people[0].size(); ++column) {
                    ui->tablePerson->item(row, column)->setText(people[row][column]);
                    out << people[row][column] + "\n";

                    if( column == people[0].size() - 1)
                    {
                        out << "\n";
                    }
                }
            }

            addPerson->getTxt()->close();
        }

        else{
            for (int i = 0; i < companies.size(); ++i)
            {
                ui->tableCompany->setRowHidden(i, false);
            }

            for (int i = 0; i < companies.size(); ++i) {
                if(ui->tableCompany->item(i, SPECIALITY_SELECTED_ON_THE_COMPANY_TABLE)->text() != "Не обязательно")
                {
                    if(ui->tableCompany->item(i, SPECIALITY_SELECTED_ON_THE_COMPANY_TABLE)->text() !=
                       ui->tablePerson->item(ui->tablePerson->currentRow(), SPECIALITY_SELECTED_ON_THE_PERSON_TABLE)->text())
                    {
                        ui->tableCompany->setRowHidden(i, true);
                    }
                }

                if(ui->tablePerson->item(ui->tablePerson->currentRow(), SALARY_SELECTED_ON_THE_PERSON_TABLE)
                             ->text() != "Не указано") {
                    if(ui->tableCompany->item(i, SALARY_SELECTED_ON_THE_COMPANY_TABLE)->text().toInt() <
                        ui->tablePerson->item(ui->tablePerson->currentRow(), SALARY_SELECTED_ON_THE_PERSON_TABLE)->text().toInt())
                    {
                        ui->tableCompany->setRowHidden(i, true);
                    }
                }

                if(QDate::currentDate().year() - ui->tableCompany->item(i, MIN_AGE_SELECTED_ON_THE_COMPANY_TABLE)->text().toInt() <
                   QDate::fromString(ui->tablePerson->item(ui->tablePerson->currentRow(), DATE_SELECTED_ON_THE_PERSON_TABLE)->text(),"dd.MM.yyyy").year())
                {
                    ui->tableCompany->setRowHidden(i, true);
                }

                else if(QDate::currentDate().year() - ui->tableCompany->item(i, MIN_AGE_SELECTED_ON_THE_COMPANY_TABLE)->text().toInt() ==
                        QDate::fromString(ui->tablePerson->item(ui->tablePerson->currentRow(), DATE_SELECTED_ON_THE_PERSON_TABLE)->text(),"dd.MM.yyyy").year())
                {
                    if(QDate::currentDate().dayOfYear() <
                       QDate::fromString(ui->tablePerson->item(ui->tablePerson->currentRow(), DATE_SELECTED_ON_THE_PERSON_TABLE)->text(),"dd.MM.yyyy").dayOfYear())
                    {
                        ui->tableCompany->setRowHidden(i, true);
                    }
                }

                if(QDate::currentDate().year() - ui->tableCompany->item(i, MAX_AGE_SELECTED_ON_THE_COMPANY_TABLE)->text().toInt() >
                   QDate::fromString(ui->tablePerson->item(ui->tablePerson->currentRow(), DATE_SELECTED_ON_THE_PERSON_TABLE)->text(),"dd.MM.yyyy").year())
                {
                    ui->tableCompany->setRowHidden(i, true);
                }

                else if(QDate::currentDate().year() - ui->tableCompany->item(i, MAX_AGE_SELECTED_ON_THE_COMPANY_TABLE)->text().toInt() ==
                        QDate::fromString(ui->tablePerson->item(ui->tablePerson->currentRow(), DATE_SELECTED_ON_THE_PERSON_TABLE)->text(),"dd.MM.yyyy").year())
                {
                    if(QDate::currentDate().dayOfYear() <
                       QDate::fromString(ui->tablePerson->item(ui->tablePerson->currentRow(), DATE_SELECTED_ON_THE_PERSON_TABLE)->text(),"dd.MM.yyyy").dayOfYear())
                    {
                        ui->tableCompany->setRowHidden(i, true);
                    }
                }

                if(ui->tableCompany->item(i, EDUCATION_SELECTED_ON_THE_COMPANY_TABLE)->text() == "Обязательное")
                {
                    if(ui->tablePerson->item(ui->tablePerson->currentRow(), EDUCATION_SELECTED_ON_THE_PERSON_TABLE)->text() != "Имеется")
                    {
                        ui->tableCompany->setRowHidden(i, true);
                    }
                }
                    if(ui->tablePerson->item(ui->tablePerson->currentRow(), POST_SELECTED_ON_THE_PERSON_TABLE)->text() !=
                       ui->tableCompany->item(i, POST_SELECTED_ON_THE_COMPANY_TABLE)->text())
                    {
                        ui->tableCompany->setRowHidden(i, true);
                    }
            }
        }
    }
}

void MainWindow::addCompanySlot()
{
    companyFromFile();
}

void MainWindow::addPersonSlot()
{
    personFromFile();
}

void MainWindow::on_actionAddCompany_triggered()
{
    addCompany->show();
}


void MainWindow::on_actionAddPerson_triggered()
{
    addPerson->show();
}

void MainWindow::companyFromFile()
{
    addCompany->getTxt()->open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream inCompany(addCompany->getTxt());
    QStringList lineWords;

    while(!inCompany.atEnd()) {
        lineWords += inCompany.readLine();
    }

    addCompany->getTxt()->close();

    companies.resize((lineWords.size() - (lineWords.size() / ui->tableCompany->columnCount() + 1))  / ui->tableCompany->columnCount() + 1,
                     QVector<QString>(ui->tableCompany->columnCount()));

    for (int i = 0, j = 0, k = 0; i < lineWords.size(); ++i, ++k)
    {
        if(lineWords.at(i).isEmpty())
        {
            --k;
            continue;
        }

        companies[j][k] = lineWords.at(i);
        if(k == ui->tableCompany->columnCount() - 1)
        {
            k -= ui->tableCompany->columnCount();
            ++j;
        }
    }

    ui->tableCompany->setRowCount(companies.size());

    for (int row = 0; row < companies.size(); ++row)
    {
        for(int column = 0; column < ui->tableCompany->columnCount(); ++column)
        {
            auto *newItem = new QTableWidgetItem(companies[row][column]);
            ui->tableCompany->setItem(row, column, newItem);
        }
    }
}

void MainWindow::personFromFile()
{
    addPerson->getTxt()->open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream inPeople(addPerson->getTxt());
    QStringList lineWords;

    while(!inPeople.atEnd())
    {
        lineWords += inPeople.readLine();
    }

    addPerson->getTxt()->close();

    people.resize((lineWords.size() - (lineWords.size() / ui->tablePerson->columnCount() + 1))
                   / ui->tablePerson->columnCount() + 1, QVector<QString>(ui->tablePerson->columnCount()));

    for (int i = 0, j = 0, k = 0; i < lineWords.size(); ++i, ++k)
    {
        if(lineWords.at(i).isEmpty())
        {
            --k;
            continue;
        }

        people[j][k] = lineWords.at(i);
        if(k == ui->tablePerson->columnCount() - 1)
        {
            k -= ui->tablePerson->columnCount();
            ++j;
        }
    }

    ui->tablePerson->setRowCount(people.size());

    for (int row = 0; row < people.size(); ++row)
    {
        for(int column = 0; column < ui->tablePerson->columnCount(); ++column)
        {
            auto *newItem = new QTableWidgetItem(people[row][column]);
            ui->tablePerson->setItem(row, column, newItem);
        }
    }
}


void MainWindow::on_actionDeleteCompany_triggered()
{
    if(ui->tableCompany->currentRow() != -1)
    {
        companies.erase(companies.begin() + ui->tableCompany->currentRow());
        ui->tableCompany->setRowCount(companies.size());

        addCompany->getTxt()->open(QIODevice::Append | QIODevice::Text | QIODevice::Truncate);
        QTextStream out(addCompany->getTxt());

        for (auto & companie : companies)
        {
            for (int column = 0; column < companies[0].size(); ++column)
            {
                out << companie[column] + "\n";

                if( column == companies[0].size() - 1)
                {
                    out << "\n";
                }
            }
        }

        addCompany->getTxt()->close();
        companyFromFile();
    }
}


void MainWindow::on_actionDeletePerson_triggered()
{
    if(ui->tablePerson->currentRow() != NO_VALUE_SELECTED_ON_THE_TABLE)
    {
        people.erase(people.begin() + ui->tablePerson->currentRow());
        ui->tablePerson->setRowCount(people.size());

        addPerson->getTxt()->open(QIODevice::Append | QIODevice::Text | QIODevice::Truncate);
        QTextStream out(addPerson->getTxt());

        for (auto & row : people) {
            for (int column = 0; column < people[0].size(); ++column)
            {
                out << row[column] + "\n";

                if( column == people[0].size() - 1)
                {
                    out << "\n";
                }
            }
        }

        addPerson->getTxt()->close();
        personFromFile();
    }
}


void MainWindow::on_actionReset_triggered()
{
    ui->tablePerson->setCurrentCell(NO_VALUE_SELECTED_ON_THE_TABLE, NO_VALUE_SELECTED_ON_THE_TABLE);
    ui->tableCompany->setCurrentCell(NO_VALUE_SELECTED_ON_THE_TABLE, NO_VALUE_SELECTED_ON_THE_TABLE);

    for (int i = 0; i < companies.size(); ++i)
    {
        ui->tableCompany->setRowHidden(i, false);
    }

    for (int i = 0; i < people.size(); ++i)
    {
        ui->tablePerson->setRowHidden(i, false);
    }
}


void MainWindow::on_actionSortPerson_triggered()
{   
    addPerson->getTxt()->open(QIODevice::Append | QIODevice::Text | QIODevice::Truncate);
    QTextStream out(addPerson->getTxt());

    std::sort(people.begin(), people.end(), compare);

    for (int i = 0; i < people.size(); ++i) {
        for (int j = 0; j < people[0].size(); ++j) {
            ui->tablePerson->item(i, j)->setText(people[i][j]);
            out << people[i][j] + "\n";

            if( j == people[0].size() - 1){
                out << "\n";
            }
        }
    }

    addPerson->getTxt()->close();
}

bool MainWindow::compare(const QVector<QString>& a, const QVector<QString>& b) {
    return a[0] < b[0];
}

void MainWindow::on_actionSortCompany_triggered()
{
    addCompany->getTxt()->open(QIODevice::Append | QIODevice::Text | QIODevice::Truncate);
    QTextStream out(addCompany->getTxt());

    std::sort(companies.begin(), companies.end(), compare);

    for (int i = 0; i < companies.size(); ++i) {
        for (int j = 0; j < companies[0].size(); ++j)
        {
            ui->tableCompany->item(i, j)->setText(companies[i][j]);
            out << companies[i][j] + "\n";

            if( j == companies[0].size() - 1){
                out << "\n";
            }
        }
    }

    addCompany->getTxt()->close();
}


void MainWindow::on_actionDefCompany_triggered()
{
    ui->tablePerson->setCurrentCell(NO_VALUE_SELECTED_ON_THE_TABLE, NO_VALUE_SELECTED_ON_THE_TABLE);
    ui->tableCompany->setCurrentCell(NO_VALUE_SELECTED_ON_THE_TABLE, NO_VALUE_SELECTED_ON_THE_TABLE);

    for (int i = 0; i < companies.size(); ++i)
    {
        ui->tableCompany->setRowHidden(i, false);
    }

    for (int i = 0; i < companies.size(); ++i)
    {
        for (int j = 0; j < people.size(); ++j)
        {
            if(ui->tableCompany->item(i, SPECIALITY_SELECTED_ON_THE_COMPANY_TABLE)->text() ==
               ui->tablePerson->item(j, SPECIALITY_SELECTED_ON_THE_PERSON_TABLE)->text() ||
               ui->tableCompany->item(i, SPECIALITY_SELECTED_ON_THE_COMPANY_TABLE)->text() == "Не обязательно")
            {
                if(ui->tableCompany->item(i, SALARY_SELECTED_ON_THE_COMPANY_TABLE)->text().toInt() >=
                   ui->tablePerson->item(j, SALARY_SELECTED_ON_THE_PERSON_TABLE)->text().toInt() ||
                   ui->tablePerson->item(j, SALARY_SELECTED_ON_THE_PERSON_TABLE)->text() != "Не указано")
                {
                    if(ui->tablePerson->item(j, POST_SELECTED_ON_THE_PERSON_TABLE)->text() ==
                       ui->tableCompany->item(i, POST_SELECTED_ON_THE_COMPANY_TABLE)->text())
                    {
                        if((ui->tableCompany->item(i, EDUCATION_SELECTED_ON_THE_COMPANY_TABLE)->text() == "Обязательное" &&
                             ui->tablePerson->item(j, EDUCATION_SELECTED_ON_THE_PERSON_TABLE)->text() == "Имеется") ||
                            ui->tableCompany->item(i, EDUCATION_SELECTED_ON_THE_COMPANY_TABLE)->text() == "Не обязательное" ||
                            ui->tableCompany->item(i, EDUCATION_SELECTED_ON_THE_COMPANY_TABLE)->text() == "Нет информации")
                        {
                            ui->tableCompany->setRowHidden(i, true);
                        }
                    }
                }
            }
        }
    }
}
