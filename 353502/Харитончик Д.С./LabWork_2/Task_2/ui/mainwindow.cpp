#include "mainwindow.h"
#include "../fileStream/fileStream.h"
#include <QFileDialog>
#include <QInputDialog>
#include <algorithm>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
        : QWidget(parent), applicants(), originalApplicants(), comboBox(new QComboBox), textEdit(new QTextEdit) {

    QPushButton *loadButton = new QPushButton("Load");
    QPushButton *saveButton = new QPushButton("Save");
    QPushButton *sortButton = new QPushButton("Sort by Specialty");
    QPushButton *searchButton = new QPushButton("Search by Name");
    QPushButton *backButton = new QPushButton("Back");
    QPushButton *closeButton = new QPushButton("Close App");

    // Load data from file
    QObject::connect(loadButton, &QPushButton::clicked, this, &MainWindow::loadFromFile);

    // Save data to file
    QObject::connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveToFile);

    // Sort applicants by specialty
    QObject::connect(sortButton, &QPushButton::clicked, this, &MainWindow::sortBySpecialty);

    // Search applicant by name
    QObject::connect(searchButton, &QPushButton::clicked, this, &MainWindow::searchByName);

    // Show original data
    QObject::connect(backButton, &QPushButton::clicked, this, &MainWindow::showOriginalData);

    QObject::connect(closeButton, &QPushButton::clicked, this, &MainWindow::closeApp);

    // UI
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(comboBox);
    layout->addWidget(textEdit);
    layout->addWidget(loadButton);
    layout->addWidget(saveButton);
    layout->addWidget(sortButton);
    layout->addWidget(searchButton);
    layout->addWidget(backButton);
    layout->addWidget(closeButton);
    setLayout(layout);
}

void MainWindow::loadFromFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        originalApplicants.clear();
        if (FileStream::LoadFromFile(fileName, originalApplicants)) {
            applicants = originalApplicants;
            QString allData;
            for (const auto &applicant : applicants) {
                allData += applicant.getAllInfo();
            }
            textEdit->setText(allData);
            QMessageBox::information(this, "Success", "Data loaded successfully.");
        } else {
            textEdit->setText("Failed to load data.");
            QMessageBox::warning(this, "Error", "Failed to load data.");
        }
    }
}


void MainWindow::saveToFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        if (FileStream::SaveToFile(fileName, applicants)) {
            textEdit->setText("Data saved successfully.");
        } else {
            textEdit->setText("Failed to save data.");
        }
    }
}

void MainWindow::sortBySpecialty() {
    std::sort(applicants.begin(), applicants.end(), [](const Applicant &a, const Applicant &b) {
        if (a.getSpecialty() == b.getSpecialty()) {
            return a.getTotalScore() < b.getTotalScore();
        }
        return a.getSpecialty() < b.getSpecialty();
    });

    QString sortedData;
    for (const auto &applicant : applicants) {
        sortedData += applicant.getAllInfo();
    }

    textEdit->setText(sortedData);
}

void MainWindow::searchByName() {
    QString searchName = QInputDialog::getText(this, "Search", "Enter full name:");
    QString searchData;
    for (const auto &applicant : applicants) {
        if (applicant.getFullName().contains(searchName, Qt::CaseInsensitive)) {
            searchData += applicant.getAllInfo();
        }
    }

    if (searchData.isEmpty()) {
        textEdit->setText("Applicant not found.");
    } else {
        textEdit->setText(searchData);
    }
}

void MainWindow::showOriginalData() {
    applicants = originalApplicants;
    QString allData;
    for (const auto &applicant : applicants) {
        allData += applicant.getAllInfo();
    }
    textEdit->setText(allData);
}

void MainWindow::closeApp() {
    close();
}