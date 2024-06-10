#pragma once
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include "../applicants/applicant.h"

class MainWindow : public QWidget {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void loadFromFile();
    void saveToFile();
    void sortBySpecialty();
    void searchByName();
    void showOriginalData();
    void closeApp();

private:
    QList<Applicant> applicants;
    QList<Applicant> originalApplicants;
    QComboBox *comboBox;
    QTextEdit *textEdit;
};
