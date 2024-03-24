#include "mainwindow.h"
#include "student.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <algorithm>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <qaction.h>
#include <qdebug.h>
#include <qlist.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qtableview.h>
#include <qtablewidget.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->addButton, &QPushButton::pressed, this, &MainWindow::handleAdd);
  connect(ui->tableWidget, &QTableWidget::itemClicked, this, &MainWindow::handleItemClicked);
  connect(ui->editButton, &QPushButton::pressed, this, &MainWindow::handleEdit);
  connect(ui->deleteButton, &QPushButton::pressed, this,&MainWindow::handleDelete);

  connect(ui->sortByNameButton, &QPushButton::pressed, this, &MainWindow::sortByName);
  connect(ui->sortByAvgButton, &QPushButton::pressed, this, &MainWindow::sortByAvg);
  connect(ui->resetSortButton, &QPushButton::pressed, this, &MainWindow::resetSort);
  connect(ui->showBestButton, &QPushButton::pressed, this, &MainWindow::showBest);
  connect(ui->searchButton, &QPushButton::pressed, this, &MainWindow::search);

  connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
  connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
}

void MainWindow::handleAdd() {
  if (!checkFields()) {
    QMessageBox::critical(nullptr, "Ошибка","Введите все поля");
    return;
  }

  int marks[] = {ui->logicSpinBox->value(),   ui->OAIPSpinBox->value(),
                 ui->historySpinBox->value(), ui->MASpinBox->value(),
                 ui->AGiLASpinBox->value(),   ui->MLSpinBox->value()};
  
  Student student{ui->lastNameEdit->text(),
                  ui->firstNameEdit->text(),
                  ui->middleNameEdit->text(),
                  ui->specialtyEdit->text(),
                  ui->groupEdit->text(),
                  ui->formComboBox->currentText(),
                  marks};

  studentList.append(student);
  populateTable(studentList);
}

void MainWindow::handleEdit() {
  if (!checkFields()) {
    QMessageBox::critical(nullptr, "Ошибка", "Введите все поля");
    return;
  }

  studentList[index].setLastName(ui->lastNameEdit->text());
  studentList[index].setFirstName(ui->firstNameEdit->text());
  studentList[index].setMiddleName(ui->middleNameEdit->text());
  studentList[index].setGroup(ui->groupEdit->text());
  studentList[index].setSpecialty(ui->specialtyEdit->text());
  studentList[index].setForm(ui->formComboBox->currentText());

  studentList[index].setMark(Student::Logic, ui->logicSpinBox->value());
  studentList[index].setMark(Student::OAIP, ui->OAIPSpinBox->value());
  studentList[index].setMark(Student::History, ui->historySpinBox->value());
  studentList[index].setMark(Student::MA, ui->MASpinBox->value());
  studentList[index].setMark(Student::AGiLA, ui->AGiLASpinBox->value());
  studentList[index].setMark(Student::ML, ui->MLSpinBox->value());
  
  populateTable(studentList);
}

void MainWindow::handleDelete() {
  if (index >= studentList.size() || index < 0)
    return;

  studentList.removeAt(index);
  populateTable(studentList);
}

void MainWindow::handleItemClicked(QTableWidgetItem *item) {

  index = item->row();

  if (index >= studentList.size() || index < 0)
    return;

  ui->headerLabel->setText("Студент №" + QString::number(index));
  Student student = studentList[index];

  ui->lastNameEdit->setText(student.lastName());
  ui->firstNameEdit->setText(student.firstName());
  ui->middleNameEdit->setText(student.middleName());
  ui->specialtyEdit->setText(student.specialty());
  ui->groupEdit->setText(student.group());

  ui->logicSpinBox->setValue(student.mark(Student::Logic));
  ui->OAIPSpinBox->setValue(student.mark(Student::OAIP));
  ui->historySpinBox->setValue(student.mark(Student::History));
  ui->MASpinBox->setValue(student.mark(Student::MA));
  ui->AGiLASpinBox->setValue(student.mark(Student::AGiLA));
  ui->MLSpinBox->setValue(student.mark(Student::ML));
}

void MainWindow::populateTable(const QList<Student> &list) {
  int size = list.size();
  ui->tableWidget->setRowCount(size);
  ui->tableWidget->setColumnCount(5);
  ui->tableWidget->setHorizontalHeaderLabels(
      {"ФИО", "Группа", "Специальность", "Форма обучения", "Средний балл"});
  
  for (int i = 0; i < size; i++) {
    Student student = list[i];
    
    QTableWidgetItem *nameItem = new QTableWidgetItem(student.lastName() + "\n" + student.firstName() + "\n" + student.middleName());
    QTableWidgetItem *groupItem = new QTableWidgetItem(student.group());
    QTableWidgetItem *specialtyItem = new QTableWidgetItem(student.specialty());
    QTableWidgetItem *formItem = new QTableWidgetItem(student.form());
    QTableWidgetItem *AvgItem = new QTableWidgetItem(QString::number(student.averageMark()));

    ui->tableWidget->setItem(i, 0, nameItem);
    ui->tableWidget->setItem(i, 1, groupItem);
    ui->tableWidget->setItem(i, 2, specialtyItem);
    ui->tableWidget->setItem(i, 3, formItem);
    ui->tableWidget->setItem(i, 4, AvgItem);

    nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
    groupItem->setFlags(groupItem->flags() & ~Qt::ItemIsEditable);
    specialtyItem->setFlags(specialtyItem->flags() & ~Qt::ItemIsEditable);
    formItem->setFlags(formItem->flags() & ~Qt::ItemIsEditable);
    AvgItem->setFlags(AvgItem->flags() & ~Qt::ItemIsEditable);

    ui->tableWidget->resizeRowToContents(i);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode( 4, QHeaderView::Stretch);
    
  }
}

bool MainWindow::checkFields() {
  if (ui->firstNameEdit->text().isEmpty() ||
      ui->lastNameEdit->text().isEmpty() ||
      ui->middleNameEdit->text().isEmpty() ||
      ui->specialtyEdit->text().isEmpty())
    return false;
  else
    return true;
}

void MainWindow::sortByName() {
  sortedList = studentList;

  auto nameComparator = [](const Student &a, const Student &b) {
    QString fullNameA = a.lastName() + a.firstName() + a.middleName();
    QString fullNameB = b.lastName() + b.firstName() + b.middleName();
    return fullNameA.compare(fullNameB, Qt::CaseInsensitive) < 0;
  };

  std::sort(sortedList.begin(), sortedList.end(), nameComparator);
  populateTable(sortedList);
}

void MainWindow::sortByAvg() {
  sortedList.clear();
  if (ui->sortFormComboBox->currentIndex() == 0) {
    sortedList = studentList;
  } else if (ui->sortFormComboBox->currentIndex() == 1) {
    for (auto &student : studentList) {
      if (student.form() == "Бюджет")
        sortedList.append(student);
    }
  } else if (ui->sortFormComboBox->currentIndex() == 2) {
    for (auto &student : studentList) {
      if (student.form() == "Платно")
        sortedList.append(student);
    }
  }

  auto avgComparator = [](const Student &a, const Student &b) {
    return a.averageMark() > b.averageMark();
  };

  std::sort(sortedList.begin(), sortedList.end(), avgComparator);
  populateTable(sortedList);
}

void MainWindow::showBest() {
  sortedList.clear();
  bool best;
  for ( auto &student : studentList) {
    if (student.isBest() && student.form() == "Платно")
      sortedList.append(student);
  }
  populateTable(sortedList);
}

void MainWindow::resetSort() {
  ui->searchLastNameEdit->clear();
  ui->searchFirstNameEdit->clear();
  ui->searchMiddleNameEdit->clear();
  ui->searchGroupEdit->clear();
  ui->searchFormComboBox->setCurrentIndex(0);

  populateTable(studentList);
}

void MainWindow::search() {
  searchList.clear();

  QString lastName = ui->searchLastNameEdit->text();
  QString firstName = ui->searchFirstNameEdit->text();
  QString middleName = ui->searchMiddleNameEdit->text();
  QString group = ui->searchGroupEdit->text();
  QString form = ui->searchFormComboBox->currentText();
  if (ui->searchFormComboBox->currentIndex() == 0) form = "";

  for (auto &student : studentList) {
    if (!student.lastName().contains(lastName)) continue;
    if (!student.firstName().contains(firstName)) continue;
    if (!student.middleName().contains(middleName)) continue;
    if (!student.group().contains(group)) continue;
    if (!student.form().contains(form)) continue;
    searchList.append(student);
  }

  populateTable(searchList);
}

void MainWindow::saveFile() {
  QString filePath = QFileDialog::getSaveFileName(this, "Save Table Data", "",
                                                  "Text Files (*.txt)");

  if (!filePath.isEmpty()) {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QTextStream out(&file);

      for (auto &student : studentList) {
        out << student.lastName() << " ";
        out << student.firstName() << " ";
        out << student.middleName() << "\t";
        out << student.group() << "\t";
        out << student.specialty() << "\t";
        out << student.form() << "\t";
        for (int i = 0; i < Student::SUBJECT_COUNT; i++) {
          out << student.mark(i) << " ";
        }
        out << "\n";
      }

      file.close();
    } else {
      // File couldn't be opened for writing
    }
  } else {
    // No file selected
  }
}

void MainWindow::openFile() {
  QString filePath = QFileDialog::getOpenFileName(this, "Open Text File", "",
                                                  "Text Files (*.txt)");

  if (!filePath.isEmpty()) {
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QTextStream in(&file);
      studentList.clear();

      while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(QRegularExpression("\\s+"));
        if (fields.size() != 12) {
          QMessageBox::critical(nullptr, "Error", "File data is incorrect");
          return;
        }

        int marks[Student::SUBJECT_COUNT];
        
        if (fields.size() >= Student::SUBJECT_COUNT + 6) {
          for (int i = 0; i < Student::SUBJECT_COUNT; ++i) {
            bool ok;
            int mark = fields[i + 6].toInt(&ok);
            if (ok)
              marks[i] = mark;
            else {
              QMessageBox::critical(nullptr, "Error", "File data is incorrect");
              return;
            }
        }

        Student student{fields[0], fields[1], fields[2], fields[4], fields[3], fields[5], marks};
        studentList.append(student);
        }
      }

      file.close();
    } else {
      // File couldn't be opened for reading
    }
  } else {
    // No file selected
  }
  populateTable(studentList);
}