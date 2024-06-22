#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->comboBox_change->clear();
    ui->comboBox_del->clear();
    ui->comboBox_2->clear();
    ui->comboBox_change->clear();
    ui->textEdit->clear();
    sFilePath = QFileDialog::getOpenFileName(this, "Выбрать файл", "/home/senya/qt/Lab_2", "Text Files(*.txt)");
    QFile fileDates(sFilePath);
    QString line;
    if (fileDates.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&fileDates);
        vac = new Vacancy();
        cand = new Candidate();
        int cntV = 0;
        int cntC = 0;
        ui -> textEdit -> clear();

        if(sFilePath == "/home/senya/qt/Lab_2/candidate.txt"){
            vecCand.clear();
            openCand = true;
            isCandOnScreen = true;
            while (!stream.atEnd()){
                line = stream.readLine();
                ui -> textEdit -> append(line);
                if(line == "-"){
                    //    qDebug() << cand->candidateName;
                    vecCand.push_back(cand);
                    cntC = 0;
                    cand = new Candidate();
                    continue;
                }
                else{
                    switch(cntC)
                    {
                    case 0:
                        cand->candidateName = line;
                        ui->comboBox_del->addItem(line);
                        ui->comboBox_2->addItem(line);
                        ui->comboBox_change->addItem(line);
                        break;
                    case 1:
                        cand->candBirthday = QDate::fromString(line, "dd.MM.yyyy");
                        cand->makeAge();
                        break;
                    case 2:
                        cand->candSpeciality = line;
                        break;
                    case 3:
                        cand->candHigherEduc = (line == "Да" ? 1 : 0);
                        break;
                    case 4:
                        cand->candPost = line;
                        break;
                    case 5:
                        cand->candMinSalary = line.toDouble();
                        break;
                    default:
                    }
                }
                cntC++;
            }
            // qDebug() << (vecCand.back())->candidateName;
            vecCand.push_back(cand);
        }
        else if(sFilePath == "/home/senya/qt/Lab_2/firm.txt"){
            vecVacancy.clear();
            isCandOnScreen = false;
            while (!stream.atEnd()){
                line = stream.readLine();
                ui -> textEdit -> append(line);

                if(line == "-"){
                    vecVacancy.push_back(vac);
                    cntV = 0;
                    vac = new Vacancy();
                    continue;
                }
                switch(cntV){
                case 0:
                    vac->firmName = line;
                    break;
                case 1:
                    vac->speciality = line;
                    break;
                case 2:
                    vac->postName = line;
                    break;
                case 3:
                    vac->salary = line.toDouble();
                case 4:
                    vac->vacationDuration = line.toInt();
                    break;
                case 5:
                    vac->higherEducation = (line == "Да" ? 1 : 0);
                    break;
                case 6:
                    vac->minAge = line.toInt();
                    break;
                case 7:
                    vac -> maxAge = line.toInt();
                    break;
                default:
                    break;
                }
                cntV++;
            }
            vecVacancy.push_back(vac);
        }
    }
}

void MainWindow::on_comboBox_del_activated(int index)
{
    ui->comboBox_change->clear();
    openCand = true;
    vecCand.erase(vecCand.begin() + index);
    ui->comboBox_del->removeItem(index);
    ui->comboBox_2->removeItem(index);
    ui->comboBox_change->removeItem(index);
    ui->textEdit->clear();
    for(Candidate* cand: vecCand)
    {
        //qDebug() << cand->candidateName;
        ui->textEdit->append(cand->candidateName);
        ui->textEdit->append(cand->candBirthday.toString("dd.MM.yyyy"));
        ui->textEdit->append(cand->candSpeciality);
        ui->textEdit->append(cand->candHigherEduc == 1 ? "ДА" : "НЕТ");
        ui->textEdit->append(cand->candPost);
        ui->textEdit->append(QString::number(cand->candMinSalary));
        if(cand != vecCand.back())
            ui->textEdit->append("-");
    }
}


void MainWindow::on_pushButton_add_clicked()
{
    openCand = true;
    if(!isCandOnScreen){
        ui->textEdit->clear();
        vecCand.clear();
        ui->comboBox_2->clear();
        ui->comboBox_del->clear();
        ui->comboBox_change->clear();
    }
    isCandOnScreen = true;
    if(vecCand.isEmpty())
        ui->textEdit->clear();
    QString data = ui->textEdit_new->toPlainText();
    QStringList strList = data.split(QRegExp("[\n]"),QString::SkipEmptyParts);

    if(strList.size() != 6){
        QMessageBox::information(this, tr("Gosling Guy"), tr("Поля неправильно заполнены"));
        return;
    }
    cand = new Candidate;
    if(ui->comboBox_del->findText(strList[0]) != -1){
        QMessageBox::information(this, tr("Oooops"), tr("Вы уже в списке"));
        return;
    }

    if(!QDate::fromString(strList[1], "dd.MM.yyyy").isValid()){
        QMessageBox::information(this, tr("Gosling guy"), tr("Неправильная дата"));
        return;
    }
    bool okDbl;
    double dblSalary = strList[5].toDouble(&okDbl);
    if(!okDbl || dblSalary < 0){
        QMessageBox::information(this, tr("Gosling guy"), tr("Неправильный оклад"));
        return;
    }
    if(!ui->textEdit->document()->isEmpty())
        ui->textEdit->append("-");
    cand->candBirthday = QDate::fromString(strList[1], "dd.MM.yyyy");
    if(cand->candBirthday > QDate::currentDate()){
        cand->candBirthday = QDate::currentDate();
    }
    for(int i = 0; i < 6; i++){
        if(i == 3){
            bool ch = ((strList[3] == "ДА" || strList[3] == "Да" || strList[3] == "дa") ? 1 : 0);
            ui->textEdit->append(ch == 1 ? "ДА" : "НЕТ");
            continue;
        }
        if(i == 5){
            ui->textEdit->append(QString::number(dblSalary));
            continue;
        }
        if(i == 1){
            ui->textEdit->append(cand->candBirthday.toString("dd.MM.yyyy"));
            continue;
        }
        ui->textEdit->append(strList[i]);
    }

    cand->candidateName = strList[0];

    cand->candSpeciality = strList[2];
    cand->candHigherEduc = ((strList[3] == "ДА" || strList[3] == "Да" || strList[3] == "дa") ? 1 : 0);
    cand->candPost = strList[4];
    cand->candMinSalary = dblSalary;

    ui->comboBox_del->addItem(strList[0]);
    ui->comboBox_2->addItem(strList[0]);
    ui->comboBox_change->addItem(strList[0]);
    vecCand.push_back(cand);
}

void MainWindow::on_comboBox_2_activated(int index)
{
    ui->comboBox_change->clear();
    isCandOnScreen = false;
    ui->textEdit->clear();
    if(vecVacancy.isEmpty()){
        QMessageBox::information(this, tr("Sorry"), tr("Сначала стоит \nпросмотреть файл"));
        return;
    }
    int age = vecCand[index]->candAge;
    QString spec = vecCand[index]->candSpeciality;
    bool highEduc = vecCand[index]->candHigherEduc;
    QString post = vecCand[index]->candPost;
    double minSalary = vecCand[index]->candMinSalary;
    for(Vacancy* vac : vecVacancy){
        //   qDebug() << vac->firmName;
        //   qDebug() << vac->higherEducation << " sw " << !highEduc;
        if(vac->higherEducation && !highEduc){
            continue;
        }
        if(vac->maxAge <= age && vac->minAge >= age){
            continue;
        }
        if(vac->postName != post){
            continue;
        }
        if(vac->speciality != spec){
            continue;
        }
        if(vac->salary < minSalary)
        {
            continue;
        }
        ui->textEdit->append(vac->firmName);
        ui->textEdit->append(vac->speciality);
        ui->textEdit->append(vac->postName);
        ui->textEdit->append(QString::number(vac->salary));
        ui->textEdit->append(QString::number(vac->vacationDuration));
        ui->textEdit->append(vac->higherEducation == 1 ? "ДА" : "НЕТ");
        ui->textEdit->append(QString::number(vac->minAge));
        ui->textEdit->append(QString::number(vac->maxAge));
        ui->textEdit->append("-");
    }
    if(!ui->textEdit->document()->isEmpty()){
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.select(QTextCursor::LineUnderCursor);
        cursor.removeSelectedText();
        cursor.deletePreviousChar();
    }
}

void MainWindow::on_pushButton_save_clicked()
{
    if(!isCandOnScreen){
        QMessageBox::information(this, tr("Sorry"), tr("Откройте список \nс кандидатами"));
        return;
    }
    QString fileName = "/home/senya/qt/Lab_2/candidate.txt";
    QFile outfile;
    outfile.setFileName(fileName);
    outfile.open(QFile::WriteOnly|QFile::Truncate | QIODevice::Append | QIODevice::Text);
    QTextStream out(&outfile);
    out << ui->textEdit->toPlainText();
}

void MainWindow::on_pushButton_def_clicked()
{
    ui->comboBox_change->clear();
    isCandOnScreen = false;
    if(vecVacancy.isEmpty() || !openCand){
        QMessageBox::information(this, tr("Sorry"), tr("Сначала стоит \nпросмотреть файл"));
        return;
    }
    ui->textEdit->clear();
    for(Vacancy* vac: vecVacancy){
        bool isFound = false;
        for(Candidate* cand: vecCand){
            if(cand->candPost == vac->postName){
                isFound = true;
            }
        }
        if(!isFound){
            ui->textEdit->append(vac->firmName);
            ui->textEdit->append(vac->speciality);
            ui->textEdit->append(vac->postName);
            ui->textEdit->append(QString::number(vac->salary));
            ui->textEdit->append(QString::number(vac->vacationDuration));
            ui->textEdit->append(vac->higherEducation == 1 ? "ДА" : "НЕТ");
            ui->textEdit->append(QString::number(vac->minAge));
            ui->textEdit->append(QString::number(vac->maxAge));
            ui->textEdit->append("-");
        }
    }
    if(!ui->textEdit->document()->isEmpty()){
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.select(QTextCursor::LineUnderCursor);
        cursor.removeSelectedText();
        cursor.deletePreviousChar();
    }
}

void MainWindow::on_pushButton_noCand_clicked()
{
    ui->comboBox_change->clear();
    ui->textEdit->clear();
    if(vecVacancy.isEmpty() || !openCand){
        QMessageBox::information(this, tr("Sorry"), tr("Сначала стоит \nпросмотреть файл"));
        return;
    }
    isCandOnScreen = false;
    QSet<QString> setFirmWithCand, setAnsFirm;
    for(Candidate* cand: vecCand){
        for(Vacancy* vac : vecVacancy){
            if(vac->postName == cand->candPost){
                setFirmWithCand.insert(vac->firmName);
                break;
            }
        }
    }
    for(Vacancy* vac : vecVacancy){
        if(setFirmWithCand.find(vac->firmName) == setFirmWithCand.end()){
            setAnsFirm.insert(vac->firmName);
        }
    }
    for(auto it = setAnsFirm.begin(); it != setAnsFirm.end(); it++){
        ui->textEdit->append(*it + "\n-");
    }
    if(!ui->textEdit->document()->isEmpty()){
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.select(QTextCursor::LineUnderCursor);
        cursor.removeSelectedText();
        cursor.deletePreviousChar();
    }
}


void MainWindow::on_comboBox_change_activated(int index)
{
    ui->textEdit_change->clear();
    Candidate* cand = vecCand[index];
    indChange = index;
    openCand = true;
    if(!isCandOnScreen){
        QMessageBox::information(this, tr("Sorry"), tr("На экране нет кандидатов"));
        return;
    }
    ui->textEdit_change->append(cand->candidateName);
    ui->textEdit_change->append(cand->candBirthday.toString("dd.MM.yyyy"));
    ui->textEdit_change->append(cand->candSpeciality);
    ui->textEdit_change->append(cand->candHigherEduc == 1 ? "ДА" : "НЕТ");
    ui->textEdit_change->append(cand->candPost);
    ui->textEdit_change->append(QString::number(cand->candMinSalary));
}


void MainWindow::on_pushButton_clicked()
{
    if(!isCandOnScreen){
        QMessageBox::information(this, tr("Sorry"), tr("На экране нет кандидатов"));
        return;
    }
    vecCand.erase(vecCand.begin() + indChange);
    if(indChange == -1)
        return;
    QString data = ui->textEdit_change->toPlainText();
    QStringList strList = data.split(QRegExp("[\n]"),QString::SkipEmptyParts);

    if(strList.size() != 6){
        QMessageBox::information(this, tr("Gosling Guy"), tr("Поля неправильно заполнены"));
        return;
    }
    cand = new Candidate;
    for(int i = 0; i < vecCand.size(); i++){
        if(strList[0] == vecCand[i]->candidateName && i != indChange){
            QMessageBox::information(this, tr("Oooops"), tr("Вы уже в списке"));
            return;
        }
    }
    if(!QDate::fromString(strList[1], "dd.MM.yyyy").isValid()){
        QMessageBox::information(this, tr("Gosling guy"), tr("Неправильная дата"));
        return;
    }
    bool okDbl;
    double dblSalary = strList[5].toDouble(&okDbl);
    if(!okDbl || dblSalary < 0){
        QMessageBox::information(this, tr("Gosling guy"), tr("Неправильная зарплата"));
        return;
    }
    cand->candBirthday = QDate::fromString(strList[1], "dd.MM.yyyy");
    if(cand->candBirthday > QDate::currentDate()){
        cand->candBirthday = QDate::currentDate();
    }

    cand->candidateName = strList[0];
    cand->candSpeciality = strList[2];
    cand->candHigherEduc = ((strList[3] == "ДА" || strList[3] == "Да" || strList[3] == "дa") ? 1 : 0);
    cand->candPost = strList[4];
    cand->candMinSalary = dblSalary;

    vecCand[indChange] = cand;

    ui->textEdit->clear();
    ui->comboBox_2->clear();
    ui->comboBox_change->clear();
    ui->comboBox_del->clear();
    for(Candidate* cand: vecCand)
    {
        //qDebug() << cand->candidateName;
        ui->comboBox_del->addItem(cand->candidateName);
        ui->comboBox_2->addItem(cand->candidateName);
        ui->comboBox_change->addItem(cand->candidateName);
        ui->textEdit->append(cand->candidateName);
        ui->textEdit->append(cand->candBirthday.toString("dd.MM.yyyy"));
        ui->textEdit->append(cand->candSpeciality);
        ui->textEdit->append(cand->candHigherEduc == 1 ? "ДА" : "НЕТ");
        ui->textEdit->append(cand->candPost);
        ui->textEdit->append(QString::number(cand->candMinSalary));
        if(cand != vecCand.back())
            ui->textEdit->append("-");
    }
    ui->textEdit_change->clear();
    indChange = -1;
}

