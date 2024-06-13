#include "mainwindow.h"

MainWindow::MainWindow()
{
    auto *mainVL = new QVBoxLayout;
    auto *buttonGL = new QGridLayout;
    auto *addInfoVLayout = new QVBoxLayout;
    auto *yesNoLayout = new QHBoxLayout;
    auto *yesNoCandidateLayout = new QHBoxLayout;
    auto *ageLayout = new QHBoxLayout;
    auto *HL = new QHBoxLayout;
    auto *addcompanyViewVLayout = new QVBoxLayout;

    arrayCompany = (companyClass **) calloc(1, sizeof(companyClass *));
    arrayCandidate = (candidateClass **) calloc(1, sizeof(candidateClass *));

    buttonGL->addWidget(openFileCompanyBtn, 0, 0);
    connect(openFileCompanyBtn, SIGNAL(clicked(bool)), SLOT(openFileCompany()));

    buttonGL->addWidget(openFileCompanyBtn1, 0, 1);
    connect(openFileCompanyBtn1, SIGNAL(clicked(bool)), SLOT(openFileCandidate()));

    buttonGL->addWidget(saveToFileCompanyBtn, 0, 2);
    connect(saveToFileCompanyBtn, SIGNAL(clicked(bool)), SLOT(saveToFileCompany()));

    buttonGL->addWidget(closeBtn, 1, 0);
    connect(closeBtn, SIGNAL(clicked(bool)), SLOT(onBtn_close_clicked()));

    buttonGL->addWidget(addBtn, 1, 1);
    connect(addBtn, SIGNAL(clicked(bool)), SLOT(addToArrayCompany()));

    buttonGL->addWidget(addBtn1, 1, 2);
    connect(addBtn1, SIGNAL(clicked(bool)), SLOT(addToArrayCandidate()));

    buttonGL->addWidget(sortBtn, 2, 0);
    connect(sortBtn, SIGNAL(clicked(bool)), SLOT(sortCandidatesByName()));

    buttonGL->addWidget(getListOfPossibleVacanciesBtn, 2, 1);
    connect(getListOfPossibleVacanciesBtn, SIGNAL(clicked(bool)), SLOT(getListOfPossibleVacancies()));

    buttonGL->addWidget(getListOfShortageVacanciesBtn, 2, 2);
    connect(getListOfShortageVacanciesBtn, SIGNAL(clicked(bool)), SLOT(getListOfUnmatchedCompanies()));

    addInfoVLayout->addWidget(addCompanyNameLbl, 1);
    addInfoVLayout->addWidget(addCompanyNameEdit, 1);

    addInfoVLayout->addWidget(addNameOfSpecialtyLbl, 1);
    addInfoVLayout->addWidget(addNameOfSpecialtyEdit, 1);

    addInfoVLayout->addWidget(addPositionNameLbl, 1);
    addInfoVLayout->addWidget(addPositionNameEdit, 1);

    addInfoVLayout->addWidget(addSalaryLbl, 1);
    addInfoVLayout->addWidget(addSalaryEdit, 1);

    addInfoVLayout->addWidget(addVacationDaysLbl, 1);
    addInfoVLayout->addWidget(addVacationDaysEdit, 1);

    addInfoVLayout->addWidget(addHigherEducationLbl, 1);
    QButtonGroup* higherEducationGroup = new QButtonGroup(this);
    higherEducationGroup->setExclusive(true);
    yesNoLayout->addWidget(addYesLbl,1);
    higherEducationGroup->addButton(addYesBox);
    yesNoLayout->addWidget(addYesBox,3);
    higherEducationGroup->addButton(addNoBox);
    yesNoLayout->addWidget(addNoLbl,1);
    yesNoLayout->addWidget(addNoBox,3);
    addInfoVLayout->addLayout(yesNoLayout,1);

    addInfoVLayout->addWidget(addAgeLbl,1);
    ageLayout->addWidget(addFromAgeLbl);
    ageLayout->addWidget(addFromAgeEdit);
    ageLayout->addWidget(addToAgeLbl);
    ageLayout->addWidget(addToAgeEdit);
    addInfoVLayout->addLayout(ageLayout,1);
    ///////////////////////////////////////////////////////////////
    addInfoVLayout->addWidget(addCandidateNameLbl, 1);
    addInfoVLayout->addWidget(addCandidateNameEdit, 1);

    addInfoVLayout->addWidget(addcalendarBirthDateLbl, 1);
    addInfoVLayout->addWidget(addcalendarBirthDateEdit, 1);

    addInfoVLayout->addWidget(addSpecialityLbl, 1);
    addInfoVLayout->addWidget(addSpecialityEdit, 1);

    addInfoVLayout->addWidget(addHigherEducationCandidateLbl, 1);

    QButtonGroup* higherEducationCandidateGroup = new QButtonGroup(this);
    higherEducationCandidateGroup->setExclusive(true);

    QButtonGroup* yesNoCandidateGroup = new QButtonGroup(this);
    yesNoCandidateGroup->setExclusive(true);

    yesNoCandidateLayout->addWidget(addYesCandidateLbl, 1);
    higherEducationCandidateGroup->addButton(addYesCandidateBox);
    yesNoCandidateGroup->addButton(addYesCandidateBox);
    yesNoCandidateLayout->addWidget(addYesCandidateBox, 3);
    yesNoCandidateLayout->addWidget(addNoCandidateLbl, 1);
    higherEducationCandidateGroup->addButton(addNoCandidateBox);
    yesNoCandidateGroup->addButton(addNoCandidateBox);
    yesNoCandidateLayout->addWidget(addNoCandidateBox, 3);

    addInfoVLayout->addLayout(yesNoCandidateLayout, 1);

    addInfoVLayout->addWidget(addDesiredPositionLbl, 1);
    addInfoVLayout->addWidget(addDesiredPositionEdit, 1);

    addInfoVLayout->addWidget(addMinSalaryLbl, 1);
    addInfoVLayout->addWidget(addMinSalaryEdit, 1);

    addcalendarBirthDateEdit->setDisplayFormat("dd MMM yyyy");
    addcalendarBirthDateEdit->setDate(QDate::currentDate());
    addcalendarBirthDateEdit->setCalendarPopup(true); // включает выпадающий календарь
    addcalendarBirthDateEdit->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);

    companyView->setReadOnly(true);
    answerView->setReadOnly(true);

    HL->addLayout(addInfoVLayout, 1);
    addcompanyViewVLayout->addWidget(companyView, 1);
    addcompanyViewVLayout->addWidget(candidateView, 1);
    QWidget *addcompanyViewWidget = new QWidget();
    addcompanyViewWidget->setLayout(addcompanyViewVLayout);
    HL->addWidget(addcompanyViewWidget, 2);
    HL->addWidget(answerView, 2);

    mainVL->addLayout(HL);
    mainVL->addLayout(buttonGL);

    setLayout(mainVL);
}

void MainWindow::onBtn_close_clicked()
{
    QMessageBox::StandardButton reply;
    if (file.fileName() != "") {
        reply = QMessageBox::question(this, "Save", "Save items to file?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            saveToFileCompany();
            close();
        } else if (reply == QMessageBox::No) {
            close();
        }

    } else {
        close();
    }
}

void MainWindow::openFileCompany()
{
    pathToFile = QFileDialog::getOpenFileName(this, "Open .txt", projectDirectory + "/..", tr("Text File (*.txt)"));
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Error", "Not file selected");
        return;
    }
    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file); // для чтения и записи данных из файла file

    while (!fileStream.atEnd()) {
        QString s1, s2, s3, s4, s5, s6, s7, s8;

        s1 = fileStream.readLine();
        s2 = fileStream.readLine();
        s3 = fileStream.readLine();
        s4 = fileStream.readLine();
        s5 = fileStream.readLine();
        s6 = fileStream.readLine();
        s7 = fileStream.readLine();
        s8 = fileStream.readLine();

        if (s1.isEmpty() || s2.isEmpty() || s3.isEmpty() || s4.isEmpty() || s5.isEmpty() || s6.isEmpty() ||
            s7.isEmpty() || s8.isEmpty())
        {
            QMessageBox::warning(this, "Error", "Wrong file");
            return;
        }
    }
    file.close();
    loadFromFileCompany();
}

void MainWindow::openFileCandidate()
{
    pathToFile1 = QFileDialog::getOpenFileName(this, "Open .txt", projectDirectory+ "/.." , tr("Text File (*.txt)"));
    if (pathToFile1.isEmpty()) {
        QMessageBox::warning(this, "Error", "Not file selected");
        return;
    }
    file1.setFileName(pathToFile1);
    file1.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file1);

    while (!fileStream.atEnd()) {
        QString s1, s2, s3, s4, s5, s6;

        s1 = fileStream.readLine();
        s2 = fileStream.readLine();
        s3 = fileStream.readLine();
        s4 = fileStream.readLine();
        s5 = fileStream.readLine();
        s6 = fileStream.readLine();

        if (s1.isEmpty() || QDate::fromString(s2, "d.M.yyyy").isNull() ||
            s3.isEmpty() || s4.isEmpty() || s5.isEmpty() || s6.isEmpty())
        {
            QMessageBox::warning(this, "Error", "Wrong file");
            return;
        }
    }
    file1.close();
    loadFromFileCandidate();
}

void MainWindow::loadFromFileCompany()
{
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    QString companyName;
    QString nameOfSpecialty;
    QString positionName;
    QString salary;
    QString vacationDays;
    QString higherEducation;
    int fromAge;
    int toAge;

    QString allCompany;
    do {
        stream >> companyName;
        if (!companyName.isEmpty()) {
            arrayCompany = (companyClass **) realloc(arrayCompany, (nmbOfItems + 1) * sizeof(companyClass *));
            arrayCompany[nmbOfItems] = new companyClass;
            arrayCompany[nmbOfItems]->setCompanyName(companyName);
            stream >> nameOfSpecialty;
            arrayCompany[nmbOfItems]->setNameOfSpecialty(nameOfSpecialty);
            stream >> positionName;
            arrayCompany[nmbOfItems]->setPositionName(positionName);
            stream >> salary;
            arrayCompany[nmbOfItems]->setSalary(salary);
            stream >> vacationDays;
            arrayCompany[nmbOfItems]->setVacationDays(vacationDays);
            stream >> higherEducation;
            arrayCompany[nmbOfItems]->setHigherEducation(higherEducation);
            stream >> fromAge;
            arrayCompany[nmbOfItems]->setFromAge(fromAge);
            stream >> toAge;
            arrayCompany[nmbOfItems]->setToAge(toAge);
            if (allCompany.indexOf(arrayCompany[nmbOfItems]->getAllCompanyInfo()) < 0) {
                allCompany += arrayCompany[nmbOfItems]->getAllCompanyInfo();
                nmbOfItems++;
            }
        }
    } while (!companyName.isEmpty());
    companyView->setPlainText(allCompany);
    answerView->clear();
    file.close();
}

void MainWindow::loadFromFileCandidate()
{
    file1.open(QIODevice::ReadWrite);
    QTextStream stream(&file1);

    QString candidateName;
    QString calendarBirthDate;
    QString speciality;
    QString higherEducationCandidate;
    QString desiredPosition;
    QString minSalary;

    QString allCandidate;
    do {
        stream >> candidateName;
        if (!candidateName.isEmpty()) {
            arrayCandidate = (candidateClass **) realloc(arrayCandidate, (nmbOfItems1 + 1) * sizeof(candidateClass *));
            arrayCandidate[nmbOfItems1] = new candidateClass;
            arrayCandidate[nmbOfItems1]->setCandidateName(candidateName);
            stream >> calendarBirthDate;
            arrayCandidate[nmbOfItems1]->setCalendarBirthDate(QDate::fromString(calendarBirthDate, "d.M.yyyy"));
            stream >> speciality;
            arrayCandidate[nmbOfItems1]->setSpeciality(speciality);
            stream >> higherEducationCandidate;
            arrayCandidate[nmbOfItems1]->setHigherEducationCandidate(higherEducationCandidate);
            stream >> desiredPosition;
            arrayCandidate[nmbOfItems1]->setDesiredPosition(desiredPosition);
            stream >> minSalary;
            arrayCandidate[nmbOfItems1]->setMinSalary(minSalary);
            if (allCandidate.indexOf(arrayCandidate[nmbOfItems1]->getAllCandidateInfo()) < 0) {
                allCandidate += arrayCandidate[nmbOfItems1]->getAllCandidateInfo();
                nmbOfItems1++;
            }
        }
    } while (!candidateName.isEmpty());
    candidateView->setPlainText(allCandidate);
    answerView->clear();
    file1.close();
}

void MainWindow::saveToFileCompany()
{
    file.open(QIODevice::ReadWrite);
    file.resize(0);
    QTextStream stream(&file);
    for (int i = 0; i < nmbOfItems; i++) {
        stream << arrayCompany[i]->getCompanyName() << "\n";
        stream << arrayCompany[i]->getNameOfSpecialty() << "\n";
        stream << arrayCompany[i]->getPositionName() << "\n";
        stream << arrayCompany[i]->getSalary() << "\n";
        stream << arrayCompany[i]->getVacationDays() << "\n";
        stream << arrayCompany[i]->getHigherEducation() << "\n";
        stream << arrayCompany[i]->getFromAge() << "\n";
        stream << arrayCompany[i]->getToAge() << "\n";
    }
    file.close();
    QMessageBox::information(this, "Saved", "Saved!");
}

void MainWindow::saveToFileCandidate()
{
    file1.open(QIODevice::ReadWrite);
    file1.resize(0);
    QTextStream stream(&file1);
    for (int i = 0; i < nmbOfItems1; i++) {
        stream << arrayCandidate[i]->getCandidateName() << "\n";
        stream << arrayCandidate[i]->getCalendarBirthDate().toString("dd.MM.yyyy") << "\n";
        stream << arrayCandidate[i]->getSpeciality() << "\n";
        stream << arrayCandidate[i]->getHigherEducationCandidate() << "\n";
        stream << arrayCandidate[i]->getDesiredPosition() << "\n";
        stream << arrayCandidate[i]->getMinSalary() << "\n";
    }
    file1.close();
    QMessageBox::information(this, "Saved", "Saved!");
}

void MainWindow::addToArrayCompany()
{
    QString companyName = addCompanyNameEdit->text();
    QString nameOfSpecialty = addNameOfSpecialtyEdit->text();
    QString positionName = addPositionNameEdit->text();
    QString salary = addSalaryEdit->text();
    QString vacationDays = addVacationDaysEdit->text();
    int fromAge = addFromAgeEdit->text().toInt();
    int toAge = addToAgeEdit->text().toInt();

    if (companyName.isEmpty() || nameOfSpecialty.isEmpty() || positionName.isEmpty() || salary.isEmpty() ||
        vacationDays.isEmpty() || fromAge == 0 || toAge == 0)
    {
        QMessageBox::warning(this, "Add something", "You skip some fields");
    } else {
        arrayCompany = (companyClass **) realloc(arrayCompany, (nmbOfItems + 1) * sizeof(companyClass *));
        arrayCompany[nmbOfItems] = new companyClass;
        arrayCompany[nmbOfItems]->setCompanyName(companyName);
        arrayCompany[nmbOfItems]->setNameOfSpecialty(nameOfSpecialty);
        arrayCompany[nmbOfItems]->setPositionName(positionName);
        arrayCompany[nmbOfItems]->setSalary(salary);
        arrayCompany[nmbOfItems]->setVacationDays(vacationDays);
        QString higherEducationValue = addYesBox->isChecked() ? "yes" : "no";
        arrayCompany[nmbOfItems]->setHigherEducation(higherEducationValue);
        arrayCompany[nmbOfItems]->setFromAge(fromAge);
        arrayCompany[nmbOfItems]->setToAge(toAge);
        if (companyView->toPlainText().indexOf(arrayCompany[nmbOfItems]->getAllCompanyInfo()) < 0) {
            nmbOfItems++;
        } else {
            QMessageBox::warning(this, "Error", "Founded the same item");
        }
    }
    QString allCompany;
    for (int i = 0; i < nmbOfItems; i++) allCompany += arrayCompany[i]->getAllCompanyInfo();
    companyView->setPlainText(allCompany);
    answerView->clear();
    file.close();
}

void MainWindow::addToArrayCandidate()
{
    QString candidateName = addCandidateNameEdit->text();
    QDate calendarBirthDate = addcalendarBirthDateEdit->date();
    QString speciality = addSpecialityEdit->text();
    QString desiredPosition = addDesiredPositionEdit->text();
    QString minSalary = addMinSalaryEdit->text();

    if (candidateName.isEmpty() ||calendarBirthDate.isNull() || speciality.isEmpty() ||
        desiredPosition.isEmpty() || minSalary.isEmpty())
    {
        QMessageBox::warning(this, "Add something", "You skip some fields");
    } else {
        arrayCandidate = (candidateClass **) realloc(arrayCandidate, (nmbOfItems1 + 1) * sizeof(candidateClass *));
        arrayCandidate[nmbOfItems1] = new candidateClass;
        arrayCandidate[nmbOfItems1]->setCandidateName(candidateName);
        arrayCandidate[nmbOfItems1]->setCalendarBirthDate(calendarBirthDate);
        arrayCandidate[nmbOfItems1]->setSpeciality(speciality);
        QString higherEducationCandidateValue = addYesCandidateBox->isChecked() ? "yes" : "no";
        arrayCandidate[nmbOfItems1]->setHigherEducationCandidate(higherEducationCandidateValue);
        arrayCandidate[nmbOfItems1]->setDesiredPosition(desiredPosition);
        arrayCandidate[nmbOfItems1]->setMinSalary(minSalary);
        if (candidateView->toPlainText().indexOf(arrayCandidate[nmbOfItems1]->getAllCandidateInfo()) < 0) {
            nmbOfItems1++;
        } else {
            QMessageBox::warning(this, "Error", "Founded the same item");
        }
    }
    QString allCandidate;
    for (int i = 0; i < nmbOfItems1; i++) allCandidate += arrayCandidate[i]->getAllCandidateInfo();
    candidateView->setPlainText(allCandidate);
    answerView->clear();
    file1.close();
}

void MainWindow::getListOfPossibleVacancies()
{
    QString all = "Possible Vacancies:\n\n";
    QDate currentDate = QDate::currentDate();
    bool foundMatchingVacancies = false;
    for (int i = 0; i < nmbOfItems; i++) {
        for (int j = 0; j < nmbOfItems1; j++) {
            if (arrayCompany[i]->getNameOfSpecialty() == arrayCandidate[j]->getSpeciality() &&
                arrayCompany[i]->getPositionName() == arrayCandidate[j]->getDesiredPosition() &&
                arrayCompany[i]->getHigherEducation() == arrayCandidate[j]->getHigherEducationCandidate() &&
                arrayCompany[i]->getSalary() >= arrayCandidate[j]->getMinSalary() &&
                currentDate.year() - arrayCandidate[j]->getCalendarBirthDate().year() >= arrayCompany[i]->getFromAge() &&
                currentDate.year() - arrayCandidate[j]->getCalendarBirthDate().year() <= arrayCompany[i]->getToAge()) {
                all += "Company: " + arrayCompany[i]->getCompanyName()
                       + "\nCandidate: " + arrayCandidate[j]->getCandidateName()
                       + "\n\n";
                foundMatchingVacancies = true;
            }
        }
    }

    if (!foundMatchingVacancies) {
        all += "No matching vacancies found.";
        QMessageBox::information(this, "Vacancy Search", "No matching vacancies found.");
    }
    answerView->setPlainText(all);
}

void MainWindow::getListOfUnmatchedCompanies()
{
    QString unmatchedCompanies = "Companies with no matching candidates:\n\n";
    QDate currentDate = QDate::currentDate();
    bool foundMatchingVacancies = false;

    for (int i = 0; i < nmbOfItems; i++) {
        bool hasMatchingCandidate = false; // Флаг, указывающий, найден ли совпадающий кандидат для текущей компании

        for (int j = 0; j < nmbOfItems1; j++) {
            if (arrayCompany[i]->getNameOfSpecialty() == arrayCandidate[j]->getSpeciality() &&
                arrayCompany[i]->getPositionName() == arrayCandidate[j]->getDesiredPosition() &&
                arrayCompany[i]->getHigherEducation() == arrayCandidate[j]->getHigherEducationCandidate() &&
                arrayCompany[i]->getSalary() >= arrayCandidate[j]->getMinSalary() &&
                currentDate.year() - arrayCandidate[j]->getCalendarBirthDate().year() >= arrayCompany[i]->getFromAge() &&
                currentDate.year() - arrayCandidate[j]->getCalendarBirthDate().year() <= arrayCompany[i]->getToAge()) {
                hasMatchingCandidate = true; // Установка флага, если найден совпадающий кандидат
                break; // Прерывание цикла, если найден совпадающий кандидат
            }
        }

        if (!hasMatchingCandidate) {
            unmatchedCompanies += arrayCompany[i]->getCompanyName() + "\n";
            foundMatchingVacancies = true;
        }
    }

    if (!foundMatchingVacancies) {
        unmatchedCompanies += "All companies have matching candidates.";
        QMessageBox::information(this, "Unmatched Companies", "All companies have matching candidates.");
    }

    answerView->setPlainText(unmatchedCompanies);
}

void MainWindow::sortCandidatesByName()
{
    qsortByName(0, nmbOfItems1 - 1);
    QString all;
    for (int i = 0; i < nmbOfItems1; i++) {
        all += arrayCandidate[i]->getAllCandidateInfo();
    }
    candidateView->setPlainText(all);
    answerView->clear();
}

void MainWindow::qsortByName(int b, int e)
{
    int l = b, r = e;
    candidateClass* mid = arrayCandidate[(l + r) / 2];
    while (l <= r) {
        while (arrayCandidate[l]->getCandidateName() < mid->getCandidateName())
            l++;
        while (arrayCandidate[r]->getCandidateName() > mid->getCandidateName())
            r--;
        if (l <= r)
            qSwap(arrayCandidate[l++], arrayCandidate[r--]);
    }
    if (b < r)
        qsortByName(b, r);
    if (e > l)
        qsortByName(l, e);
}
