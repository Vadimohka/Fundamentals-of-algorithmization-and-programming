
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QSpacerItem>
#include <QDebug>
#include <QLabel>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include "student.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    students = new Student*[100];
    saveNameButton = new QPushButton("Add student",this);
    sortButton = new QPushButton("Sort", this);
    exellentButton = new QPushButton("Show exellent st.", this);
    searchButton = new QPushButton("Search", this);
    name = new QLineEdit(this);
    marks = new QLineEdit(this);
    search = new QLineEdit(this);
    output = new QTextEdit(this);
    group = new QComboBox(this);
    form = new QComboBox(this);
    speciality = new QComboBox(this);

    QLabel *nameLab = new QLabel("Name:",this);
    QLabel *marksLab = new QLabel("Marks", this);
    QLabel *groupLab = new QLabel("Group:", this);
    QLabel *formLab = new QLabel("Form of education:", this);
    QLabel *specialityLab = new QLabel("Speciality:", this);

    group->addItem("1");
    group->addItem("2");
    group->addItem("3");
    group->addItem("4");
    group->addItem("5");
    form->addItem("budget");
    form->addItem("paid");
    speciality->addItem("sp1");
    speciality->addItem("sp2");
    speciality->addItem("sp3");

    output->setReadOnly(1);
    output->setFixedSize(600, 600);

    ui->gridLayout->addWidget(nameLab, 0, 0);
    ui->gridLayout->addWidget(name, 1, 0);
    ui->gridLayout->addWidget(marksLab, 2, 0);
    ui->gridLayout->addWidget(marks, 3, 0);
    ui->gridLayout->addWidget(groupLab, 4, 0);
    ui->gridLayout->addWidget(group, 5, 0);
    ui->gridLayout->addWidget(formLab, 6, 0);
    ui->gridLayout->addWidget(form, 7, 0);
    ui->gridLayout->addWidget(specialityLab, 8, 0);
    ui->gridLayout->addWidget(speciality, 9, 0);
    ui->gridLayout->addWidget(saveNameButton, 11, 0);
    ui->gridLayout->addWidget(output, 0, 1, 10, 5);
    ui->gridLayout->addWidget(exellentButton, 11, 2);
    ui->gridLayout->addWidget(sortButton, 11, 1);
    ui->gridLayout->addWidget(search, 11, 3, 1, 2);
    ui->gridLayout->addWidget(searchButton, 11, 5);


    connect(saveNameButton, SIGNAL(clicked()), this,  SLOT(saveStudent()));
    connect(sortButton, SIGNAL(clicked()), this,  SLOT(sort()));
    connect(exellentButton, SIGNAL(clicked()), this, SLOT(showExcellentStudents()));
    connect(searchButton, SIGNAL(clicked()), this,  SLOT(searchStudents()));

    loadFromFile(file);
}

MainWindow::~MainWindow()
{
    delete[] students;
    delete ui;
}

void MainWindow::saveStudent(){
    if (name->text() != "" && marks->text() != "") {
        students[number] = new Student(name->text(), marks->text(), group->currentText(), form->currentText(), speciality->currentText());
        name->setText("");
        marks->setText("");

        output->append(QString("name: %1, group: %2, form: %3, speciality: %4, average mark: %5")
                           .arg(students[number]->getName()).arg(students[number]->getGroup()).arg(students[number]->getForm())
                           .arg(students[number]->getSpeciality()).arg(students[number]->getAverageMark()));
        number++;
        saveToFile(file);
    }
}

void MainWindow::sort()
{
    int n = number;
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (students[i]->getAverageMark() < students[i + 1]->getAverageMark()) {
                std::swap(students[i], students[i + 1]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);

    output->clear();
    for (int i = 0; i < number; ++i) {
        output->append(QString("name: %1, group: %2, form: %3, speciality: %4, average mark: %5")
                           .arg(students[i]->getName()).arg(students[i]->getGroup()).arg(students[i]->getForm())
                           .arg(students[i]->getSpeciality()).arg(students[i]->getAverageMark()));
    }
}

void MainWindow::showExcellentStudents()
{
    output->clear();
    output->append("Excellent Students with Paid Education:\n");

    for (int i = 0; i < number; ++i) {
        if (students[i]->getForm() == "paid") {
            QString markString = students[i]->getMarks();
            QStringList markList = markString.split(" ");
            bool hasExcellentGrade = false;
            foreach (QString mark, markList) {
                int value = mark.toInt();
                if (value == 9 || value == 10) {
                    hasExcellentGrade = true;
                    break;
                }
            }
            if (hasExcellentGrade) {
                output->append(QString("Name: %1, Group: %2, Form: %3, Speciality: %4, Average Mark: %5")
                                   .arg(students[i]->getName()).arg(students[i]->getGroup()).arg(students[i]->getForm())
                                   .arg(students[i]->getSpeciality()).arg(students[i]->getAverageMark()));
            }
        }
    }
}

void MainWindow::searchStudents()
{
    QString searchText = search->text();
    search->clear();
    output->clear();
    for (int i = 0; i < number; ++i)
    {
        if (students[i]->getName() == searchText || students[i]->getGroup() == searchText || students[i]->getForm() == searchText)
        {
            output->append(QString("Name: %1, Group: %2, Form: %3, Speciality: %4, Average Mark: %5")
                               .arg(students[i]->getName()).arg(students[i]->getGroup()).arg(students[i]->getForm())
                               .arg(students[i]->getSpeciality()).arg(students[i]->getAverageMark()));
        }
    }
}

void MainWindow::saveToFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << filename;
        return;
    }

    QTextStream out(&file);
    for (int i = 0; i < number; ++i) {
        out << students[i]->getName() << ","
            << students[i]->getMarks() << ","
            << students[i]->getGroup() << ","
            << students[i]->getForm() << ","
            << students[i]->getSpeciality() << "\n";
    }

    file.close();
}

void MainWindow::loadFromFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading:" << filename;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() == 5) {
            students[number] = new Student(fields[0], fields[1], fields[2], fields[3], fields[4]);
            output->append(QString("name: %1, group: %2, form: %3, speciality: %4, average mark: %5")
                               .arg(students[number]->getName()).arg(students[number]->getGroup()).arg(students[number]->getForm())
                               .arg(students[number]->getSpeciality()).arg(students[number]->getAverageMark()));
            number++;
        }
    }
    file.close();
}
