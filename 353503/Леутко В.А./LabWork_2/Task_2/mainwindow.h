#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "companyclass.h"
#include "candidateclass.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

    QString projectDirectory;
private:
    QString pathToFile;
    QString pathToFile1;
    QFile file;
    QFile file1;

    companyClass **arrayCompany;
    int nmbOfItems = 0;
    candidateClass **arrayCandidate;
    int nmbOfItems1 = 0;

    QPushButton *openFileCompanyBtn = new QPushButton("Open...");
    QPushButton *openFileCompanyBtn1 = new QPushButton("Open...");
    QPushButton *closeBtn = new QPushButton("Close");
    QPushButton *addBtn = new QPushButton("Add");
    QPushButton *addBtn1 = new QPushButton("Add");
    QPushButton *editBtn = new QPushButton("Edit/Delete");
    QPushButton *sortBtn = new QPushButton("Sort");
    QPushButton *saveToFileCompanyBtn = new QPushButton("Save");
    QPushButton *saveToFileCompanyBtn1 = new QPushButton("Save");
    QPushButton *getListOfPossibleVacanciesBtn = new QPushButton("Get List Of Possible Vacancies");
    QPushButton *getListOfShortageVacanciesBtn = new QPushButton("Get List Of Shortage Vacancies");
    QPushButton *getListOfCompaniesWithoutCandidatesBtn = new QPushButton("Get List Of Companies Without Candidates");

    QPlainTextEdit *companyView = new QPlainTextEdit;
    QPlainTextEdit *candidateView = new QPlainTextEdit;
    QPlainTextEdit *answerView = new QPlainTextEdit;

    ///////////////////////////////////////////////////////////////
    QLabel *addCompanyNameLbl = new QLabel("Company Name");
    QLineEdit *addCompanyNameEdit = new QLineEdit;

    QLabel *addNameOfSpecialtyLbl = new QLabel("NameOfSpecialty");
    QLineEdit *addNameOfSpecialtyEdit = new QLineEdit;

    QLabel *addPositionNameLbl = new QLabel("Position Name");
    QLineEdit *addPositionNameEdit = new QLineEdit;

    QLabel *addSalaryLbl = new QLabel("Salary");
    QLineEdit *addSalaryEdit = new QLineEdit;

    QLabel *addVacationDaysLbl = new QLabel("Number Of Vacation Days");
    QLineEdit *addVacationDaysEdit = new QLineEdit;

    QLabel *addHigherEducationLbl = new QLabel("Availability Of Higher Education");
    QLabel *addYesLbl = new QLabel("    yes");
    QLabel *addNoLbl = new QLabel("    no");
    QCheckBox *addYesBox = new QCheckBox;
    QCheckBox *addNoBox = new QCheckBox;

    QLabel *addAgeLbl = new QLabel("Age");
    QLabel *addFromAgeLbl = new QLabel("from");
    QLabel *addToAgeLbl = new QLabel("to");
    QLineEdit *addFromAgeEdit = new QLineEdit;
    QLineEdit *addToAgeEdit = new QLineEdit;
    ///////////////////////////////////////////////////////////////
    QLabel *addCandidateNameLbl = new QLabel("Candidate Name");
    QLineEdit *addCandidateNameEdit = new QLineEdit;

    QLabel *addcalendarBirthDateLbl = new QLabel("Birth Date");
    QDateEdit *addcalendarBirthDateEdit = new QDateEdit;

    QLabel *addSpecialityLbl = new QLabel("Speciality");
    QLineEdit *addSpecialityEdit = new QLineEdit;

    QLabel *addHigherEducationCandidateLbl = new QLabel("Availability Of Higher Education");
    QLabel *addYesCandidateLbl = new QLabel("    yes");
    QLabel *addNoCandidateLbl = new QLabel("    no");
    QCheckBox *addYesCandidateBox = new QCheckBox;
    QCheckBox *addNoCandidateBox = new QCheckBox;

    QLabel *addDesiredPositionLbl = new QLabel("Desired Position");
    QLineEdit *addDesiredPositionEdit = new QLineEdit;

    QLabel *addMinSalaryLbl = new QLabel("Minimum Salary");
    QLineEdit *addMinSalaryEdit = new QLineEdit;

protected slots:
    void onBtn_close_clicked();
    void openFileCompany();
    void openFileCandidate();
    void loadFromFileCompany();
    void loadFromFileCandidate();
    void saveToFileCompany();
    void saveToFileCandidate();
    void addToArrayCompany();
    void addToArrayCandidate();
    void getListOfPossibleVacancies();
    void getListOfUnmatchedCompanies();
    void sortCandidatesByName();
    void qsortByName(int b, int e);
};
#endif // MAINWINDOW_H
