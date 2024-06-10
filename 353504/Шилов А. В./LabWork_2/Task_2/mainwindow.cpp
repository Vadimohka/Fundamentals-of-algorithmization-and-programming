#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setVisibleAddCandidateMenu(false);
    this->setEditModeCandidates(false, false);

    this->setVisibleAddFirmMenu(false);
    this->setEditModeFirms(false, false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::GetCandidatesFromFile()
{
    m_candidates.clear();

    QFile file(m_candidatesFilePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        while (!stream.atEnd())
        {
            QString line = stream.readLine();
            m_candidates.push_back(Candidate(line));
        }

        file.close();
    }
}


void MainWindow::GetFirmsFromFile()
{
    m_firms.clear();

    QFile file(m_firmsFilePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        while (!stream.atEnd())
        {
            QString line = stream.readLine();
            m_firms.push_back(Firm(line));
        }

        file.close();
    }
}


QString MainWindow::getTextToSave(int flag)
{
    QString text = " ";
    if (flag == 1)
        for (int i = 0; i < m_candidates.count(); ++i)
            text += m_candidates[i].GetStr() + '\n';
    if (flag == 2)
        for (int i = 0; i < m_firms.count(); ++i)
            text += m_firms[i].GetStr() + '\n';

    return text;
}


void MainWindow::SaveFile(int flag)
{
    QString filePath = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "Text Files (*.txt)");

    if (!filePath.isEmpty())
    {
        QFile file(filePath);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream << this->getTextToSave(flag);

            file.close();
            if (flag == 1)
                m_candidatesFilePath = filePath;
            if (flag == 2)
                m_firmsFilePath = filePath;
        }
    }
}


void MainWindow::OpenFile(int flag)
{
    QString newFilePath = (QFileDialog::getOpenFileName(nullptr, "Открыть файл", "", "Текстовые файлы (*.txt);;Все файлы (*.*)"));

    if (!newFilePath.isEmpty())
    {
        if (flag == 1)
        {
            m_candidatesFilePath = newFilePath;
            this->GetCandidatesFromFile();
            this->fillFieldsCandidates();
        }
        if (flag == 2)
        {
            m_firmsFilePath = newFilePath;
            this->GetFirmsFromFile();
            this->fillFieldsFirms();
        }
    }
}


Candidate MainWindow::getNewCandidate()
{
    QString fullName = ui->lineEdit_3->text();
    QString birthdayDate = ui->dateEdit->text();
    QString speciality = ui->lineEdit->text();
    QString havingHigherEducation;
    if (ui->checkBox->isChecked())
        havingHigherEducation = QString::fromStdString("+");
    else
        havingHigherEducation = QString::fromStdString("-");
    QString careerObjective = ui->lineEdit_2->text();
    QString salary = ui->spinBox->text();

    if (fullName.indexOf(',') != -1 || speciality.indexOf(',') != -1 || careerObjective.indexOf(',') != -1)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Специальный знак , запрещен");
        this->on_comboBox_currentIndexChanged(-1);
    }

    return Candidate(fullName, birthdayDate, speciality, salary, havingHigherEducation, careerObjective);
}


Firm MainWindow::getNewFirm()
{
    QString firmName = ui->lineEdit_4->text();
    QString speciality = ui->lineEdit_5->text();
    QString job = ui->lineEdit_6->text();
    QString salary = ui->spinBox_2->text();
    QString vacationDays = ui->spinBox_3->text();
    QString higherEducation;
    if (ui->checkBox_2->isChecked())
        higherEducation = QString::fromStdString("+");
    else
        higherEducation = QString::fromStdString("-");
    QString minAge = ui->spinBox_4->text();
    QString maxAge = ui->spinBox_5->text();

    if (firmName.indexOf(',') != -1 || speciality.indexOf(',') != -1 || job.indexOf(',') != -1)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Специальный знак , запрещен");
        this->on_comboBox_currentIndexChanged(-1);
    }

    return Firm(firmName, speciality, job, salary, vacationDays, higherEducation, minAge, maxAge);
}


void MainWindow::setVisibleAddCandidateMenu(bool flag)
{
    ui->lineEdit_3->setVisible(flag);
    ui->label_9->setVisible(flag);
    ui->pushButton_5->setVisible(flag);
    ui->pushButton_6->setVisible(flag);
    ui->comboBox->setVisible(!flag);
}


void MainWindow::setVisibleAddFirmMenu(bool flag)
{
    ui->lineEdit_4->setVisible(flag);
    ui->label_18->setVisible(flag);
    ui->pushButton_16->setVisible(flag);
    ui->pushButton_18->setVisible(flag);
    ui->comboBox_2->setVisible(!flag);
}


void MainWindow::setEditModeCandidates(bool flag, bool flag2)
{
    ui->lineEdit_3->setVisible(flag);
    ui->lineEdit_3->setText(ui->comboBox->currentText());
    ui->comboBox->setVisible(!flag);
    ui->lineEdit->setReadOnly(!flag);
    ui->dateEdit->setReadOnly(!flag);
    ui->checkBox->setEnabled(flag);
    ui->lineEdit_2->setReadOnly(!flag);
    ui->spinBox->setReadOnly(!flag);
    ui->pushButton_8->setVisible(flag2);
    ui->pushButton_9->setVisible(flag2);
}


void MainWindow::setEditModeFirms(bool flag, bool flag2)
{
    ui->lineEdit_4->setVisible(flag);
    ui->lineEdit_4->setText(ui->comboBox_2->currentText());
    ui->comboBox_2->setVisible(!flag);
    ui->lineEdit_5->setReadOnly(!flag);
    ui->checkBox_2->setEnabled(flag);
    ui->lineEdit_6->setReadOnly(!flag);
    ui->spinBox_2->setReadOnly(!flag);
    ui->spinBox_3->setReadOnly(!flag);
    ui->spinBox_4->setReadOnly(!flag);
    ui->spinBox_5->setReadOnly(!flag);
    ui->pushButton_17->setVisible(flag2);
    ui->pushButton_15->setVisible(flag2);
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    if (index == -1)
    {
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->checkBox_2->setChecked(false);
        ui->spinBox_2->setValue(0);
        ui->spinBox_3->setValue(0);
        ui->spinBox_4->setValue(0);
        ui->spinBox_5->setValue(0);
        return;
    }

    if (m_firms[index].HavingHigherEducation() == QString::fromStdString("+"))
        ui->checkBox_2->setChecked(true);
    else
        ui->checkBox_2->setChecked(false);

    ui->lineEdit_5->setText(m_firms[index].NameOfSpeciality());
    ui->lineEdit_6->setText(m_firms[index].JobTitle());
    ui->spinBox_2->setValue(m_firms[index].Salary().toInt());
    ui->spinBox_3->setValue(m_firms[index].NumberOfVacationDays().toInt());
    ui->spinBox_4->setValue(m_firms[index].MinAge().toInt());
    ui->spinBox_5->setValue(m_firms[index].MaxAge().toInt());
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == -1)
    {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        //ui->dateEdit->clear();
        ui->checkBox->setChecked(false);
        ui->spinBox->setValue(0);
        return;
    }

    ui->lineEdit->setText(m_candidates[index].Speciality());

    ui->dateEdit->setDate(m_candidates[index].BirthdayDate());

    if (m_candidates[index].HavingHigherEducation() == QString::fromStdString("+"))
        ui->checkBox->setChecked(true);
    else
        ui->checkBox->setChecked(false);

    ui->lineEdit_2->setText(m_candidates[index].CareerObjective());

    ui->spinBox->setValue(m_candidates[index].MinimumSalary().toInt());
}


void MainWindow::fillFieldsCandidates()
{
    ui->comboBox->clear();
    for (int i = 0; i < m_candidates.count(); ++i)
        ui->comboBox->addItem(m_candidates[i].FullName());
}

void MainWindow::fillFieldsFirms()
{
    ui->comboBox_2->clear();
    for (int i = 0; i < m_firms.count(); ++i)
        ui->comboBox_2->addItem(m_firms[i].FirmName());
}


void MainWindow::on_pushButton_clicked()
{
    this->OpenFile(1);
}


void MainWindow::on_pushButton_2_clicked()
{
    this->SaveFile(1);
}


void MainWindow::on_pushButton_3_clicked()
{
    this->setVisibleAddCandidateMenu(true);
    this->setEditModeCandidates(true, false);
}


void MainWindow::on_pushButton_4_clicked()
{
    if (m_candidates.isEmpty() || !ui->comboBox->isVisible())
        QMessageBox::critical(nullptr, "Ошибка", "Элемент не выбран");
    else
    {
        m_candidates.remove(ui->comboBox->currentIndex());
        this->fillFieldsCandidates();
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    m_candidates.append(this->getNewCandidate());

    this->setVisibleAddCandidateMenu(false);
    this->setEditModeCandidates(false, false);
    this->fillFieldsCandidates();
}


void MainWindow::on_pushButton_6_clicked()
{
    this->setVisibleAddCandidateMenu(false);
    this->setEditModeCandidates(false, false);
    if (m_candidates.length() != 0)
        this->on_comboBox_currentIndexChanged(0);
}


void MainWindow::on_pushButton_7_clicked()
{
    if (m_candidates.isEmpty() || !ui->comboBox->isVisible() || ui->comboBox->currentIndex() == -1)
        QMessageBox::critical(nullptr, "Ошибка", "Элемент не выбран");
    else
        this->setEditModeCandidates(true, true);
}


void MainWindow::on_pushButton_8_clicked()
{
    this->setEditModeCandidates(false, false);
    if (m_candidates.length() != 0)
        this->on_comboBox_currentIndexChanged(0);
}


void MainWindow::on_pushButton_9_clicked()
{
    m_candidates[ui->comboBox->currentIndex()] = this->getNewCandidate();
    this->fillFieldsCandidates();
    this->setEditModeCandidates(false, false);
}

void MainWindow::on_pushButton_10_clicked()
{
    this->OpenFile(2);
}



void MainWindow::on_pushButton_11_clicked()
{
    this->SaveFile(2);
}


void MainWindow::on_pushButton_13_clicked()
{
    this->setVisibleAddFirmMenu(true);
    this->setEditModeFirms(true, false);
}


void MainWindow::on_pushButton_14_clicked()
{
    if (m_firms.isEmpty() || !ui->comboBox_2->isVisible())
        QMessageBox::critical(nullptr, "Ошибка", "Элемент не выбран");
    else
    {
        m_firms.remove(ui->comboBox_2->currentIndex());
        this->fillFieldsFirms();
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    if (m_firms.isEmpty() || !ui->comboBox_2->isVisible() || ui->comboBox_2->currentIndex() == -1)
        QMessageBox::critical(nullptr, "Ошибка", "Элемент не выбран");
    else
        this->setEditModeFirms(true, true);
}


void MainWindow::on_pushButton_16_clicked()
{
    m_firms.append(this->getNewFirm());

    this->setVisibleAddFirmMenu(false);
    this->setEditModeFirms(false, false);
    this->fillFieldsFirms();
}


void MainWindow::on_pushButton_18_clicked()
{
    this->setVisibleAddFirmMenu(false);
    this->setEditModeFirms(false, false);
    if (m_firms.length() != 0)
        this->on_comboBox_2_currentIndexChanged(0);
}


void MainWindow::on_pushButton_15_clicked()
{
    m_firms[ui->comboBox_2->currentIndex()] = this->getNewFirm();
    this->fillFieldsFirms();
    this->setEditModeFirms(false, false);
}


void MainWindow::on_pushButton_17_clicked()
{
    this->setEditModeFirms(false, false);
    if (m_firms.length() != 0)
        this->on_comboBox_2_currentIndexChanged(0);
}


void MainWindow::on_pushButton_19_clicked()
{
    QString text = "";

    for(int i = 0; i < m_firms.count(); ++i)
        if (isCandidateAvailable(m_firms[i], m_candidates[ui->comboBox->currentIndex()]))
            text += m_firms[i].FirmName() + '\n';

    ui->textEdit->setText(text);
    if (text.isEmpty())
        ui->textEdit->setText("Фирмы не найдены.");
}


bool MainWindow::isCandidateAvailable(Firm firm, Candidate candidate)
{
    if (firm.NameOfSpeciality().toLower() != candidate.Speciality().toLower() ||
        (firm.JobTitle().toLower() != candidate.CareerObjective().toLower() && candidate.CareerObjective() != QString::fromStdString("-")) ||
        firm.Salary().toInt() < candidate.MinimumSalary().toInt() ||
        (firm.HavingHigherEducation() == "+" && candidate.HavingHigherEducation() == "-") ||
        candidate.BirthdayDate().daysTo(QDate::currentDate()) < firm.MinAge().toInt()*365 ||
        candidate.BirthdayDate().daysTo(QDate::currentDate()) > firm.MaxAge().toInt()*365 )
        return false;
    return true;
}


void MainWindow::on_pushButton_20_clicked()
{
    QString text = "";
    QVector<QString> specialities;
    QVector<QString> notSpecialities;
    QVector<QString> endText;
    bool flag = false;

    for (int i = 0; i < m_firms.count(); ++i)
    {
        for (int j = 0; j < m_candidates.count(); ++j)
            if (isCandidateAvailable(m_firms[i], m_candidates[j]))
            {
                flag = true;
                specialities.push_back(m_firms[i].NameOfSpeciality());
                break;
            }
        if (!flag)
            notSpecialities.push_back(m_firms[i].NameOfSpeciality());
        flag = false;
    }

    for (int i = 0; i < notSpecialities.count(); ++i)
        if (specialities.indexOf(notSpecialities[i]) == -1 && endText.indexOf(notSpecialities[i]) == -1)
            endText.push_back(notSpecialities[i]);

    for (int i = 0; i < endText.count(); ++i)
        text += endText[i] + '\n';

    ui->textEdit_2->setText(text);
    if (text.isEmpty())
        ui->textEdit_2->setText("Отсутствуют.");
}


void MainWindow::on_pushButton_21_clicked()
{
    QString text = "";
    bool flag = false;

    for (int i = 0; i < m_firms.count(); ++i)
    {
        for (int j = 0; j < m_candidates.count(); ++j)
            if (isCandidateAvailable(m_firms[i], m_candidates[j]))
            {
                flag = true;
                break;
            }
        if (!flag)
            text += m_firms[i].FirmName() + '\n';
        flag = false;
    }

    ui->textEdit_3->setText(text);
    if (text.isEmpty())
        ui->textEdit_3->setText("Отсутствуют.");
}

