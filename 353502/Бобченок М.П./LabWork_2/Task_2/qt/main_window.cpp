//
// Created by u on 10.04.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"

#include <iostream>


void main_window::save()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save a file", "../saves");
    if (file_name.isEmpty())
        return;

    if (file_name.mid(file_name.size() - 4, 4) != ".txt")
        file_name += ".txt";

    std::ofstream fout(file_name.toStdString());

    for (auto &u: students)
    {
        std::cout << u.getFio().toStdString() << " " << u.getSpeciality().toStdString() << " " << u.getGroup().toStdString() << " " << u.getGrade(0) << " "
        << u.getGrade(1) << " " << u.getGrade(2) << "\n";
        fout << u.getFio().toStdString() << " " << u.getSpeciality().toStdString() << " "
             << u.getGroup().toStdString() << " " << u.getGrade(0) << " " << u.getGrade(1) << " " << u.getGrade(2) << "\n";
    }


    fout.close();
}

void main_window::load()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Load a file", "../saves");
    if (file_name.isEmpty())
        return;

    if (file_name.mid(file_name.size() - 4, 4) != ".txt")
        file_name += ".txt";

    std::ifstream fin(file_name.toStdString());

    while (!fin.eof())
    {
        std::string fio, speciality, group;
        float g1, g2, g3;
        fin >> fio >> speciality >> group >> g1 >> g2 >> g3;
        if (fio.empty() || speciality.empty() || group.empty())
            return;
        students.emplace_back(QString::fromStdString(fio), QString::fromStdString(speciality), QString::fromStdString(group), g1, g2, g3);
    }

    fin.close();
}

void main_window::add()
{
    QString fio, speciality, group;
    fio = ui->fio->text();
    speciality = ui->speciality->text();
    group = ui->group->text();

    if (fio.isEmpty())
        fio = "null";
    if (speciality.isEmpty())
        speciality = "null";
    if (group.isEmpty())
        group = "null";

    students.emplace_back(fio, speciality, group, ui->math->text().toFloat(), ui->programming->text().toFloat(), ui->philosophi->text().toFloat());
}

void main_window::change()
{
    students[ui->numOfStudent->value()] = student(ui->fio->text(), ui->speciality->text(), ui->group->text(), ui->math->text().toFloat(), ui->programming->text().toFloat(), ui->philosophi->text().toFloat());
}


void main_window::findStudent()
{
    if (studentFio.size() == 0)
        studentFio = ui->fio->text();
    else
        studentFio = "";
}

void main_window::showBadStudent()
{
    showBadStudents ^= 1;
}

void main_window::sortByGrade()
{
    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 1; j < students.size(); j++)
            if ((students[j].getGrade(0) + students[j].getGrade(1) + students[j].getGrade(2)) / 3 >
                (students[j - 1].getGrade(0) + students[j - 1].getGrade(1) + students[j - 1].getGrade(2)) / 3)
                std::swap(students[j], students[j - 1]);
    }
}

void main_window::sortByGroup()
{
    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 1; j < students.size(); j++)
            if (students[j - 1].getGroup() > students[j].getGroup())
                std::swap(students[j], students[j - 1]);
    }

    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 1; j < students.size(); j++)
            if (students[j].getGroup() == students[j - 1].getGroup() &&
                (students[j].getGrade(0) + students[j].getGrade(1) + students[j].getGrade(2)) / 3 >
                (students[j - 1].getGrade(0) + students[j - 1].getGrade(1) + students[j - 1].getGrade(2)) / 3)
                std::swap(students[j], students[j - 1]);
    }
}

void main_window::updateTable()
{
    ui->tableWidget->setRowCount((int)students.size());
    ui->numOfStudent->setMaximum(std::max(0, (int)students.size() - 1));

    int i = 0;
    for (int k = 0; k < students.size(); k++)
    {
        if (studentFio.size() != 0 && students[k].getFio() != studentFio)
            continue;

        if (!showBadStudents &&
                (students[k].getGrade(0) < 4 ||
                students[k].getGrade(1) < 4 ||
                students[k].getGrade(2) < 4))
            continue;

        auto *fio = new QTableWidgetItem();
        fio->setText(students[k].getFio());
        ui->tableWidget->setItem(i, 0, fio);

        auto *speciality = new QTableWidgetItem();
        speciality->setText(students[k].getSpeciality());
        ui->tableWidget->setItem(i, 1, speciality);

        auto *group = new QTableWidgetItem();
        group->setText(students[k].getGroup());
        ui->tableWidget->setItem(i, 2, group);

        float average = 0;
        for (int j = 0; j < 3; j++)
        {
            auto *grade = new QTableWidgetItem();
            grade->setText(QString::number(students[k].getGrade(j)));
            ui->tableWidget->setItem(i, 4 + j, grade);
            average += students[k].getGrade(j);
        }

        auto *av = new QTableWidgetItem();
        av->setText(QString::number(average / 3));
        ui->tableWidget->setItem(i, 3, av);
        i++;
    }

    ui->tableWidget->setRowCount(i);
}

main_window::main_window(QWidget *parent) : QWidget(parent), ui(new Ui::main_window)
{
    ui->setupUi(this);

    auto *timer = new QTimer(this);
    timer->setInterval(1);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTable()));
    timer->start();

    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(add()));
    connect(ui->changeButton, SIGNAL(clicked(bool)), this, SLOT(change()));
    connect(ui->findStudent, SIGNAL(clicked(bool)), this, SLOT(findStudent()));
    connect(ui->showBadStudent, SIGNAL(clicked(bool)), this, SLOT(showBadStudent()));
    connect(ui->saveButton, SIGNAL(clicked(bool)), this, SLOT(save()));
    connect(ui->loadButton, SIGNAL(clicked(bool)), this, SLOT(load()));
    connect(ui->gradeSortButton, SIGNAL(clicked(bool)), this, SLOT(sortByGrade()));
    connect(ui->groupSortButton, SIGNAL(clicked(bool)), this, SLOT(sortByGroup()));
}

main_window::~main_window()
{
    delete ui;
}
