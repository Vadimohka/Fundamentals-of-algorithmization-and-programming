#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>

using namespace std;

mainwindow::mainwindow(): ui(new Ui::mainwindow), scene (new QGraphicsScene(this)) {

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->openButton, SIGNAL(clicked()), this, SLOT(openfile_clicked()));
    connect(ui->saveFileButton, SIGNAL(clicked()), this, SLOT(savefile_clicked()));
    connect(ui->matchButton, SIGNAL(clicked(bool)), this, SLOT(match_clicked()));
    connect(ui->emptyVacancyButton, SIGNAL(clicked(bool)), this, SLOT(emptyvacancy_clicked()));
    connect(ui->emptyCandidateButton, SIGNAL(clicked()), this, SLOT(emptycandidate_clicked()));
    connect(ui->sortButton, SIGNAL(clicked()), this, SLOT(sort_clicked()));

    connect(ui->addcomboBox, SIGNAL(activated(int)), this, SLOT(add_clicked(int)));
    connect(ui->changecomboBox, SIGNAL(activated(int)), this, SLOT(change_clicked(int)));
    connect(ui->deletecomboBox, SIGNAL(activated(int)), this, SLOT(delete_clicked(int)));

    connect(ui->editFirmCloseButton, SIGNAL(clicked()), this, SLOT(close_firm_clicked()));
    connect(ui->editFirmAddButton, SIGNAL(clicked()), this, SLOT(add_firm_clicked()));
    connect(ui->editFirmChangeButton, SIGNAL(clicked(bool)), this, SLOT(change_firm_clicked()));
    connect(ui->firmComboBox, SIGNAL(activated(int)), this, SLOT(show_firm_clicked(int)));
    connect(ui->editFirmDeleteButton, SIGNAL(clicked()), this, SLOT(delete_firm_clicked()));

    connect(ui->editCandidateCloseButton, SIGNAL(clicked()), this, SLOT(close_candidate_clicked()));
    connect(ui->editCandidateAddButton, SIGNAL(clicked()), this, SLOT(add_candidate_clicked()));
    connect(ui->editCandidateChangeButton, SIGNAL(clicked()), this, SLOT(change_candidate_clicked()));
    connect(ui->editCandidateDeleteButton, SIGNAL(clicked()), this, SLOT(delete_candidate_clicked()));
    connect(ui->candidateComboBox, SIGNAL(activated(int)), this, SLOT(show_candidate_clicked(int)));

    ui->firmWidget->hide();
    ui->candidateWidget->hide();

    ui->saveFileButton->setEnabled(false);
    ui->matchButton->setEnabled(false);
    ui->emptyCandidateButton->setEnabled(false);
    ui->emptyVacancyButton->setEnabled(false);
    ui->sortButton->setEnabled(false);
    ui->addcomboBox->setEnabled(false);
    ui->changecomboBox->setEnabled(false);
    ui->deletecomboBox->setEnabled(false);

}

void mainwindow::openfile_clicked() {
    if(open)
        return;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Text files (*.txt)"));
    fileRem = fileName;
    if(fileName.size() == 0)
    {
        QMessageBox message;
        message.setText("Can't open file");
        message.exec();
        return;
    }
    file.setFileName(fileName);
    file.open(QIODevice::ReadWrite);
    QTextStream fileLine(&file);

    QString s;
    while(!fileLine.atEnd()) {
        s = fileLine.readLine();
        if (s == "firm") {
            fff:;
            auto x = Firm();
            try {
                s = fileLine.readLine();
                x.setNameOfFirm(s);
            }
            catch (...) {
                CantOpen();
                return;
            }
            try {
                s = fileLine.readLine();
                x.setVacancy(s);
            }
            catch (...) {
                CantOpen();
                return;
            }
            try {
                s = fileLine.readLine();
                double k = s.toDouble();
                x.setSalary(k);
            }
            catch (...) {
                CantOpen();
                return;
            }
            try {
                s = fileLine.readLine();
                int k = s.toInt();
                x.setVacation(k);
            }
            catch (...) {
                CantOpen();
                return;
            }
            try {
                s = fileLine.readLine();
                bool t = s.toInt();
                x.setEducation(t);
            }
            catch (...) {
                CantOpen();
                return;
            }
            try {
                s = fileLine.readLine();
                int t = s.toInt();
                x.setMinAge(t);
            }
            catch (...) {
                CantOpen();
                return;
            }
            try {
                s = fileLine.readLine();
                int t = s.toInt();
                x.setMaxAge(t);
            }
            catch (...) {
                CantOpen();
                return;
            }
            try {
                s = fileLine.readLine();
                int t = s.toInt();
                x.setExperience(t);
            }
            catch (...) {
                CantOpen();
                return;
            }
            firms.push_back(x);
            continue;
        }
        if (s == "candidate") {
            ccc:;
            auto x = Candidate();
            try {
                s = fileLine.readLine();
                x.setName(s);
            }
            catch (...) {
                CantOpen();
                return;
            }
            try {
                s = fileLine.readLine();
                QDate d = QDate::fromString(s, "dd.MM.yyyy");
                x.setDate(d);
            }
            catch (...) {
                CantOpen();
                return;
            }
            try {
                s = fileLine.readLine();
                bool t = s.toInt();
                x.setEducation(t);
            }
            catch (...) {
                CantOpen();
                return;
            }
            try {
                s = fileLine.readLine();
                x.setVacancy(s);
            }
            catch (...) {
                CantOpen();
                return;
            }
            try {
                s = fileLine.readLine();
                double t = s.toDouble();
                x.setMinValue(t);
            }
            catch (...) {
                CantOpen();
                return;
            }
            int num_of_work;
            try {
                s = fileLine.readLine();
                int t = s.toInt();
                num_of_work = t;
            }
            catch (...) {
                CantOpen();
                return;
            }
            QVector<tuple<QString, QDate, QDate> > v;
            if (num_of_work >= 0) {
                for (int i = 0; i < num_of_work; i++) {
                    QString work;
                    QDate start, finish;
                    if(s == "candidate")
                        goto ccc;
                    if(s == "firm")
                        goto fff;
                    try {
                        s = fileLine.readLine();
                        work = s;
                    }
                    catch (...) {
                        CantOpen();
                        return;
                    }
                    try {
                        s = fileLine.readLine();
                        QDate a = QDate::fromString(s, "dd.MM.yyyy");
                        start = a;
                    }
                    catch (...) {
                        CantOpen();
                        return;
                    }
                    try {
                        s = fileLine.readLine();
                        QDate b = QDate::fromString(s, "dd.MM.yyyy");
                        finish = b;
                    }
                    catch (...) {
                        CantOpen();
                        return;
                    }
                    try {
                        v.push_back(make_tuple(work, start, finish));
                    }
                    catch (...) {
                        CantOpen();
                        return;
                    }
                }
            } else {
                CantOpen();
                return;
            }
            x.setExperience(v);
            candidates.push_back(x);
            continue;
        }
        QMessageBox message;
        message.setText("Incorrect data in file");
        message.exec();
        firms.clear();
        candidates.clear();
        return;
    }
    open = true;
    file.close();
    ShowLists();
    ui->openButton->setEnabled(false);
    ui->saveFileButton->setEnabled(true);
    ui->matchButton->setEnabled(true);
    ui->emptyCandidateButton->setEnabled(true);
    ui->emptyVacancyButton->setEnabled(true);
    ui->sortButton->setEnabled(true);
    ui->addcomboBox->setEnabled(true);
    ui->editFirmCloseButton->setEnabled(true);
    ui->editFirmAddButton->setEnabled(true);
    ui->changecomboBox->setEnabled(true);
    ui->deletecomboBox->setEnabled(true);
}

void mainwindow::CantOpen() {
    QMessageBox message;
    message.setText("Incorrect data in file");
    ShowLists();
    message.exec();
    firms.clear();
    candidates.clear();
}

void mainwindow::ShowLists() {
    ui->candidateplainTextEdit->clear();
    for(const auto& x : candidates)
    {
        ui->candidateplainTextEdit->appendPlainText(x.getName());
        ui->candidateplainTextEdit->appendPlainText(x.getDate().toString("dd.MM.yyyy"));
        int t = x.isEducation();
        ui->candidateplainTextEdit->appendPlainText("higher education: " + QString::fromStdString(to_string(t)));
        ui->candidateplainTextEdit->appendPlainText(x.getVacancy());
        ui->candidateplainTextEdit->appendPlainText(QString::fromStdString(to_string(x.getMinValue())));
        for(auto y : x.getExperience())
        {
            ui->candidateplainTextEdit->appendPlainText(get<0>(y) + " " + get<1>(y).toString("dd.MM.yyyy") + " - " + get<2>(y).toString("dd.MM.yyyy"));
        }
    }
    ui->firmplainTextEdit->clear();
    for(const auto& x : firms)
    {
        ui->firmplainTextEdit->appendPlainText(x.getNameOfFirm());
        ui->firmplainTextEdit->appendPlainText(x.getVacancy());
        ui->firmplainTextEdit->appendPlainText("salary: " + QString::fromStdString(to_string(x.getSalary())));
        ui->firmplainTextEdit->appendPlainText("vacation: " + QString::fromStdString(to_string(x.getVacation())));
        ui->firmplainTextEdit->appendPlainText("higher education: " + QString::fromStdString(to_string(x.isEducation())));
        ui->firmplainTextEdit->appendPlainText("min age: " + QString::fromStdString(to_string(x.getMinAge())));
        ui->firmplainTextEdit->appendPlainText("max age: " + QString::fromStdString(to_string(x.getMaxAge())));
        ui->firmplainTextEdit->appendPlainText("experience: " + QString::fromStdString(to_string(x.getExperience())));
    }
}

void mainwindow::savefile_clicked() {
    if(!open)
        return;
    file.setFileName(fileRem);
    file.open(QIODevice::ReadWrite);
    QTextStream fileLine(&file);
    for(const auto& x : firms)
    {
        fileLine << "firm\n";
        fileLine << x.getNameOfFirm() << "\n";
        fileLine << x.getVacancy() << "\n";
        fileLine << x.getSalary() << "\n";
        fileLine << x.getVacation() << "\n";
        fileLine << x.isEducation() << "\n";
        fileLine << x.getMinAge() << "\n";
        fileLine << x.getMaxAge() << "\n";
        fileLine << x.getExperience() << "\n";
    }
    for(const auto& x : candidates)
    {
        fileLine << "candidate\n";
        fileLine << x.getName() << "\n";
        fileLine << x.getDate().toString("dd.MM.yyyy") << "\n";
        fileLine << x.isEducation() << "\n";
        fileLine << x.getVacancy() << "\n";
        fileLine << x.getMinValue() << "\n";
        fileLine << x.getExperience().size() << "\n";
        for(auto y : x.getExperience())
        {
            fileLine << std::get<0>(y) << "\n";
            fileLine << std::get<1>(y).toString("dd.MM.yyyy") << "\n";
            fileLine << std::get<2>(y).toString("dd.MM.yyyy") << "\n";
        }
    }
}

void mainwindow::match_clicked() {
    QVector<Firm> f;
    QVector<QVector<Candidate>> c;
    for(const auto& x : firms)
    {
        QVector<Candidate> has;
        for(const auto& y : candidates)
        {
            if(Firm::Match(x, y))
            {
                has.push_back(y);
            }
        }
        f.push_back(x);
        c.push_back(has);
    }
    ShowResult(f, c);
}

void mainwindow::ShowResult(QVector<Firm> f, QVector<QVector<Candidate>> c) {
    ui->resultplainTextEdit->show();
    ui->resultplainTextEdit->clear();
    for(int i = 0; i < f.size(); i ++)
    {
        ui->resultplainTextEdit->appendPlainText(f[i].getNameOfFirm() + ":");
        if(c[i].empty())
        {
            ui->resultplainTextEdit->appendPlainText("no candidates");
        }
        else
        {
            for(const auto& y : c[i])
            {
                ui->resultplainTextEdit->appendPlainText(y.getName());
            }
        }
        ui->resultplainTextEdit->appendPlainText("\n");
    }

}

void mainwindow::emptyvacancy_clicked() {
    QVector<Firm> f;
    for(const auto& x : firms)
    {
        bool q = false;
        for(const auto& y : candidates)
        {
            if(Firm::Match(x, y))
            {
                q = true;
                break;
            }
        }
        if(!q)
        {
            f.push_back(x);
        }
    }
    ShowResult(f);

}

void mainwindow::ShowResult(const QVector<Firm>& f) {
    ui->resultplainTextEdit->show();
    ui->resultplainTextEdit->clear();
    for(const auto& x : f)
    {
        ui->resultplainTextEdit->appendPlainText(x.getNameOfFirm() + ". vacancy: " + x.getVacancy());
    }
}

void mainwindow::emptycandidate_clicked() {

    QVector<Candidate> f;
    for(const auto& x : candidates)
    {
        bool q = false;
        for(const auto& y : firms)
        {
            if(Firm::Match(y, x))
            {
                q = true;
                break;
            }
        }
        if(!q)
            f.push_back(x);
    }
    ShowResult(f);
}

void mainwindow::ShowResult(const QVector<Candidate>& f) {
    ui->resultplainTextEdit->show();
    ui->resultplainTextEdit->clear();
    for(const auto& x : f)
    {
        ui->resultplainTextEdit->appendPlainText(x.getName() + " - " + x.getVacancy());
    }
}

static bool comp(Firm a, Firm b)
{
    return a.getSalary() > b.getSalary();
}

static bool comp2(Candidate a, Candidate b)
{
    return a.getName() > b.getName();
}

void mainwindow::sort_clicked() {

    sort(firms.begin(), firms.end(), comp);
    sort(candidates.begin(), candidates.end(), comp2);
    ShowLists();
}

void mainwindow::ErrorLine(const QString& s) {
    QMessageBox message;
    message.setText("Incorrect data in line " + s);
    message.exec();
}

void mainwindow::add_clicked(int type) {
    if(!open)
        return;

    if(type == 0)
    {   ui->editFirmAddButton->setEnabled(true);

        ui->editFirmChangeButton->setEnabled(false);
        ui->editFirmDeleteButton->setEnabled(false);
        ui->firmComboBox->setEnabled(false);
        ui->editFirmName->setEnabled(true);
        ui->editFirmVacancy->setEnabled(true);
        ui->editFirmSalary->setEnabled(true);
        ui->editFirmVacation->setEnabled(true);
        ui->editFirmEducation->setEnabled(true);
        ui->editFirmMinAge->setEnabled(true);
        ui->editFirmMaxAge->setEnabled(true);
        ui->editFirmExperience->setEnabled(true);
        ui->firmWidget->show();
    }
    else
    {
        ui->editCandidateAddButton->setEnabled(true);
        ui->editCandidateName->setEnabled(true);
        ui->editCandidateVacancy->setEnabled(true);
        ui->editCandidateMinValue->setEnabled(true);
        ui->editCandidateDate->setEnabled(true);
        ui->editCandidateEducation->setEnabled(true);
        ui->editCandidateWorkNumber->setEnabled(true);
        ui->editCandidateJobs->setEnabled(true);
        ui->candidateWidget->show();

    }

}

void mainwindow::change_clicked(int type) {
    if(!open)
        return;

    if(type == 0)
    {
        ui->editFirmAddButton->setEnabled(false);
        ui->editFirmChangeButton->setEnabled(true);
        ui->editFirmDeleteButton->setEnabled(false);
        ui->firmComboBox->setEnabled(true);

        for(const auto& x : firms)
        {
            ui->firmComboBox->addItem(x.getNameOfFirm());
        }
        if(firms.empty())
        {
            ui->editFirmChangeButton->setEnabled(false);
        }

        ui->editFirmName->setEnabled(true);
        ui->editFirmVacancy->setEnabled(true);
        ui->editFirmSalary->setEnabled(true);
        ui->editFirmVacation->setEnabled(true);
        ui->editFirmEducation->setEnabled(true);
        ui->editFirmMinAge->setEnabled(true);
        ui->editFirmMaxAge->setEnabled(true);
        ui->editFirmExperience->setEnabled(true);

        ui->firmWidget->show();
        if(!firms.empty())
            show_firm_clicked(0), posForChange = 0;
    }
    else
    {
        ui->editCandidateChangeButton->setEnabled(true);
        ui->candidateComboBox->setEnabled(true);
        for(auto x : candidates)
        {
            ui->candidateComboBox->addItem(x.getName());
        }
        if(candidates.empty())
            ui->editFirmChangeButton->setEnabled(false);

        ui->editCandidateName->setEnabled(true);
        ui->editCandidateVacancy->setEnabled(true);
        ui->editCandidateMinValue->setEnabled(true);
        ui->editCandidateDate->setEnabled(true);
        ui->editCandidateEducation->setEnabled(true);
        ui->editCandidateWorkNumber->setEnabled(true);
        ui->editCandidateJobs->setEnabled(true);
        ui->candidateWidget->show();

        ui->candidateWidget->show();
        if(!candidates.empty())
        {
            show_candidate_clicked(0);
            posForChange = 0;
        }

    }

}

void mainwindow::delete_clicked(int type) {
    if(!open)
        return;

    if(type == 0)
    {
        ui->editFirmAddButton->setEnabled(false);
        ui->editFirmChangeButton->setEnabled(false);
        ui->editFirmDeleteButton->setEnabled(true);
        ui->firmComboBox->setEnabled(true);

        for(const auto& x : firms)
        {
            ui->firmComboBox->addItem(x.getNameOfFirm());
        }

        if(firms.empty())
            ui->firmComboBox->setEnabled(false);

        ui->editFirmName->setEnabled(false);
        ui->editFirmVacancy->setEnabled(false);
        ui->editFirmSalary->setEnabled(false);
        ui->editFirmVacation->setEnabled(false);
        ui->editFirmEducation->setEnabled(false);
        ui->editFirmMinAge->setEnabled(false);
        ui->editFirmMaxAge->setEnabled(false);
        ui->editFirmExperience->setEnabled(false);

        ui->firmWidget->show();
        if(!firms.empty())
            show_firm_clicked(0), posForChange = 0;
    }
    else
    {
        ui->editCandidateDeleteButton->setEnabled(true);
        ui->candidateComboBox->setEnabled(true);

        for(const auto& x : candidates)
        {
            ui->candidateComboBox->addItem(x.getName());
        }

        if(candidates.empty())
            ui->editCandidateDeleteButton->setEnabled(false);

        ui->candidateWidget->show();
        if(!candidates.empty())
        {
            show_candidate_clicked(0);
            posForChange = 0;
        }
    }
}

void mainwindow::close_firm_clicked() {
    ui->firmComboBox->clear();
    ui->editFirmName->clear();
    ui->editFirmVacancy->clear();
    ui->editFirmSalary->clear();
    ui->editFirmVacation->clear();
    ui->editFirmEducation->clear();
    ui->editFirmMinAge->clear();
    ui->editFirmMaxAge->clear();
    ui->editFirmExperience->clear();
    ui->editFirmAddButton->setEnabled(false);
    ui->editFirmChangeButton->setEnabled(false);
    ui->editFirmDeleteButton->setEnabled(false);
    ui->firmComboBox->setEnabled(false);
    ui->firmWidget->hide();
}

void mainwindow::close_candidate_clicked() {

    ui->editCandidateAddButton->setEnabled(false);
    ui->editCandidateChangeButton->setEnabled(false);
    ui->editCandidateDeleteButton->setEnabled(false);
    ui->candidateComboBox->clear();
    ui->candidateComboBox->setEnabled(false);
    ui->editCandidateName->clear();
    ui->editCandidateName->setEnabled(false);
    ui->editCandidateDate->clear();
    ui->editCandidateDate->setEnabled(false);
    ui->editCandidateVacancy->clear();
    ui->editCandidateVacancy->setEnabled(false);
    ui->editCandidateMinValue->clear();
    ui->editCandidateMinValue->setEnabled(false);
    ui->editCandidateEducation->clear();
    ui->editCandidateEducation->setEnabled(false);
    ui->editCandidateWorkNumber->clear();
    ui->editCandidateWorkNumber->setEnabled(false);
    ui->editCandidateJobs->clear();
    ui->editCandidateJobs->setEnabled(false);
    ui->candidateWidget->hide();
}

void mainwindow::show_firm_clicked(int i)
{
    posForChange = i;
    auto t = firms[i];
    ui->editFirmName->setPlainText(t.getNameOfFirm());
    ui->editFirmVacancy->setPlainText(t.getVacancy());
    ui->editFirmSalary->setPlainText(QString::number(t.getSalary()));
    ui->editFirmVacation->setPlainText(QString::number(t.getVacation()));
    ui->editFirmEducation->setPlainText(QString::number(t.isEducation()));
    ui->editFirmMinAge->setPlainText(QString::number(t.getMinAge()));
    ui->editFirmMaxAge->setPlainText(QString::number(t.getMaxAge()));
    ui->editFirmExperience->setPlainText(QString::number(t.getExperience()));
}

void mainwindow::show_candidate_clicked(int i) {
    posForChange = i;
    auto t = candidates[i];
    ui->editCandidateName->setPlainText(t.getName());
    ui->editCandidateVacancy->setPlainText(t.getVacancy());
    ui->editCandidateMinValue->setPlainText(QString::number(t.getMinValue()));
    ui->editCandidateDate->setDate(t.getDate());
    ui->editCandidateEducation->setPlainText(QString::number(t.isEducation()));
    ui->editCandidateWorkNumber->setPlainText(QString::number(t.getExperience().size()));
    ui->editCandidateJobs->clear();
    for(auto x : t.getExperience())
    {
        auto x0 = std::get<0>(x);
        ui->editCandidateJobs->append(x0);
        auto x1 = std::get<1>(x).toString("dd.MM.yyyy");
        ui->editCandidateJobs->append(x1);
        x1 = std::get<2>(x).toString("dd.MM.yyyy");
        ui->editCandidateJobs->append(x1);
    }
}

void mainwindow::add_firm_clicked() {
    auto x = Firm();
    try
    {
        if(ui->editFirmName->toPlainText().size() == 0)
            throw "Empty line";
        x.setNameOfFirm(ui->editFirmName->toPlainText());
    }
    catch(...)
    {
        ErrorLine("name of firm");
        return;
    }
    try
    {
        if(ui->editFirmVacancy->toPlainText().size() == 0)
            throw "Empty line";
        x.setVacancy(ui->editFirmVacancy->toPlainText());
    }
    catch(...)
    {
        ErrorLine("vacancy");
        return;
    }
    try
    {
        if(ui->editFirmSalary->toPlainText().size() == 0)
            throw "Empty line";
        x.setSalary(ui->editFirmSalary->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("salary");
        return;
    }
    try
    {
        if(ui->editFirmVacation->toPlainText().size() == 0)
            throw "Empty line";
        x.setVacation((ui->editFirmVacation->toPlainText()).toInt());
    }
    catch(...)
    {
        ErrorLine("vacation");
        return;
    }
    try
    {
        if(ui->editFirmEducation->toPlainText().size() == 0)
            throw "Empty line";
        x.setEducation(ui->editFirmName->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("requiring education");
        return;
    }
    try
    {
        if(ui->editFirmMinAge->toPlainText().size() == 0)
            throw "Empty line";
        x.setMinAge(ui->editFirmMinAge->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("minimal age");
        return;
    }
    try
    {
        if(ui->editFirmMaxAge->toPlainText().size() == 0)
            throw "Empty line";
        x.setMaxAge(ui->editFirmMaxAge->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("maximal age");
        return;
    }
    try
    {
        if(ui->editFirmExperience->toPlainText().size() == 0)
            throw "Empty line";
        x.setExperience(ui->editFirmExperience->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("experience");
        return;
    }

    try{
        firms.push_back(x);
    }
    catch(...)
    {
        QMessageBox message;
        message.setText("Incorrect data in form");
        message.exec();
        return;
    }
    ShowLists();
}

void mainwindow::add_candidate_clicked() {
    auto x = Candidate();
    try
    {
        if(ui->editCandidateName->toPlainText().size() == 0)
            throw "Empty line";
        x.setName(ui->editCandidateName->toPlainText());
    }
    catch(...)
    {
        ErrorLine("name");
        return;
    }
    try
    {
        if(ui->editCandidateVacancy->toPlainText().size() == 0)
            throw "Empty line";
        x.setVacancy(ui->editCandidateVacancy->toPlainText());
    }
    catch(...)
    {
        ErrorLine("vacancy");
        return;
    }
    try
    {
        if(ui->editCandidateMinValue->toPlainText().size() == 0)
            throw "Empty line";
        x.setMinValue(ui->editCandidateMinValue->toPlainText().toDouble());
    }
    catch(...)
    {
        ErrorLine("minimal salary");
        return;
    }
    try
    {
        x.setDate(ui->editCandidateDate->date());
    }
    catch(...)
    {
        ErrorLine("date of birthday");
        return;
    }
    try
    {
        if(ui->editCandidateEducation->toPlainText().size() == 0)
            throw "Empty line";
        x.setEducation(ui->editCandidateEducation->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("education");
        return;
    }
    int numberOfJobs = 0;
    try
    {
        if(ui->editCandidateWorkNumber->toPlainText().size() == 0)
            throw "Empty line";
        numberOfJobs = ui->editCandidateWorkNumber->toPlainText().toInt();
    }
    catch(...)
    {
        ErrorLine("number of previous jobs");
        return;
    }
    auto t = ui->editCandidateJobs->toPlainText();
    QVector<QString> has;
    QString cur;
    bool f = false;
    for(int i = 0; i < t.size(); i ++)
    {
        if(t[i] == '\n')
        {
            has.push_back(cur);
            cur.clear();
            f = false;
        }
        else
        {
            cur += t[i];
            f = true;
        }
    }
    if(f)
        has.push_back(cur);
    if(has.size() % 3 != 0 || has.size() / 3 != numberOfJobs) {
        ErrorLine("jobs");
        return;
    }
    QVector<std::tuple<QString, QDate, QDate> > add;
    for(int i = 0; i < has.size(); i += 3)
    {
        QString s1;
        QDate s2, s3;
        try {
            s1 = has[i];
        }
        catch (...) {
            ErrorLine("date");
            return;
        }
        try {
            s2 = QDate::fromString(has[i + 1], "dd.MM.yyyy");
        }
        catch (...)
        {
            ErrorLine("date");
            return;
        }
        try {
            s3 = QDate::fromString(has[i + 2], "dd.MM.yyyy");
        }
        catch (...)
        {
            ErrorLine("date");
            return;
        }
        try{
            add.push_back(make_tuple(s1, s2, s3));
        }
        catch (...)
        {
            ErrorLine("date");
            return;
        }
    }
    try{
        x.setExperience(add);
    }
    catch (...)
    {
        ErrorLine("date");
        return;
    }
    try
    {
        candidates.push_back(x);
    }
    catch (...)
    {
        QMessageBox message;
        message.setText("Incorrect data in form");
        message.exec();
        return;
    }
    ShowLists();
}

void mainwindow::change_firm_clicked() {
    auto x = Firm();
    try
    {
        if(ui->editFirmName->toPlainText().size() == 0)
            throw "Empty line";
        x.setNameOfFirm(ui->editFirmName->toPlainText());
    }
    catch(...)
    {
        ErrorLine("name of firm");
        return;
    }
    try
    {
        if(ui->editFirmVacancy->toPlainText().size() == 0)
            throw "Empty line";
        x.setVacancy(ui->editFirmVacancy->toPlainText());
    }
    catch(...)
    {
        ErrorLine("vacancy");
        return;
    }
    try
    {
        if(ui->editFirmSalary->toPlainText().size() == 0)
            throw "Empty line";
        x.setSalary(ui->editFirmSalary->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("salary");
        return;
    }
    try
    {
        if(ui->editFirmVacation->toPlainText().size() == 0)
            throw "Empty line";
        x.setVacation(ui->editFirmVacation->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("vacation");
        return;
    }
    try
    {
        if(ui->editFirmEducation->toPlainText().size() == 0)
            throw "Empty line";
        x.setEducation(ui->editFirmName->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("requiring education");
        return;
    }
    try
    {
        if(ui->editFirmMinAge->toPlainText().size() == 0)
            throw "Empty line";
        x.setMinAge(ui->editFirmMinAge->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("minimal age");
        return;
    }
    try
    {
        if(ui->editFirmMaxAge->toPlainText().size() == 0)
            throw "Empty line";
        x.setMaxAge(ui->editFirmMaxAge->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("maximal age");
        return;
    }
    try
    {
        if(ui->editFirmExperience->toPlainText().size() == 0)
            throw "Empty line";
        x.setExperience(ui->editFirmExperience->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("experience");
        return;
    }

    try{
        firms[posForChange] = x;
    }
    catch(...)
    {
        QMessageBox message;
        message.setText("Incorrect data in form");
        message.exec();
        return;
    }
    ShowLists();
}

void mainwindow::change_candidate_clicked() {
    auto x = Candidate();
    try
    {
        if(ui->editCandidateName->toPlainText().size() == 0)
            throw "Empty line";
        x.setName(ui->editCandidateName->toPlainText());
    }
    catch(...)
    {
        ErrorLine("name");
        return;
    }
    try
    {
        if(ui->editCandidateVacancy->toPlainText().size() == 0)
            throw "Empty line";
        x.setVacancy(ui->editCandidateVacancy->toPlainText());
    }
    catch(...)
    {
        ErrorLine("vacancy");
        return;
    }
    try
    {
        if(ui->editCandidateMinValue->toPlainText().size() == 0)
            throw "Empty line";
        x.setMinValue(ui->editCandidateMinValue->toPlainText().toDouble());
    }
    catch(...)
    {
        ErrorLine("minimal salary");
        return;
    }
    try
    {
        x.setDate(ui->editCandidateDate->date());
    }
    catch(...)
    {
        ErrorLine("date of birthday");
        return;
    }
    try
    {
        if(ui->editCandidateEducation->toPlainText().size() == 0)
            throw "Empty line";
        x.setEducation(ui->editCandidateEducation->toPlainText().toInt());
    }
    catch(...)
    {
        ErrorLine("education");
        return;
    }
    int numberOfJobs = 0;
    try
    {
        if(ui->editCandidateWorkNumber->toPlainText().size() == 0)
            throw "Empty line";
        numberOfJobs = ui->editCandidateWorkNumber->toPlainText().toInt();
    }
    catch(...)
    {
        ErrorLine("number of previous jobs");
        return;
    }
    auto t = ui->editCandidateJobs->toPlainText();
    QVector<QString> has;
    QString cur;
    bool f = false;
    for(int i = 0; i < t.size(); i ++)
    {
        if(t[i] == '\n')
        {
            has.push_back(cur);
            cur.clear();
            f = false;
        }
        else
        {
            cur += t[i];
            f = true;
        }
    }
    if(f)
        has.push_back(cur);
    if(has.size() % 3 != 0 || has.size() / 3 != numberOfJobs) {
        ErrorLine("jobs");
        return;
    }
    QVector<std::tuple<QString, QDate, QDate> > add;
    for(int i = 0; i < has.size(); i += 3)
    {
        QString s1;
        QDate s2, s3;
        try {
            s1 = has[i];
        }
        catch (...) {
            ErrorLine("date");
            return;
        }
        try {
            s2 = QDate::fromString(has[i + 1], "dd.MM.yyyy");
        }
        catch (...)
        {
            ErrorLine("date");
            return;
        }
        try {
            s3 = QDate::fromString(has[i + 2], "dd.MM.yyyy");
        }
        catch (...)
        {
            ErrorLine("date");
            return;
        }
        try{
            add.push_back(make_tuple(s1, s2, s3));
        }
        catch (...)
        {
            ErrorLine("date");
            return;
        }
    }
    try{
        x.setExperience(add);
    }
    catch (...)
    {
        ErrorLine("date");
        return;
    }
    try
    {
        candidates[posForChange] = x;
    }
    catch (...)
    {
        QMessageBox message;
        message.setText("Incorrect data in form");
        message.exec();
        return;
    }
    ShowLists();
}

void mainwindow::delete_firm_clicked() {
    if(firms.empty())
    {
        return;
    }
    firms.erase(firms.begin() + posForChange);
    ui->firmComboBox->removeItem(posForChange);
    ShowLists();
    posForChange --;
    if(posForChange < 0)
        posForChange += firms.size();
    if(firms.empty())
    {
        ui->firmComboBox->setEnabled(false);
    }
    else
    {
        show_firm_clicked(posForChange);
    }
}

void mainwindow::delete_candidate_clicked() {
    if(candidates.empty())
    {
        return ;
    }
    candidates.erase(candidates.begin() + posForChange);
    ui->candidateComboBox->removeItem(posForChange);
    ShowLists();
    posForChange --;
    if(posForChange < 0)
    {
        posForChange += candidates.size();
    }
    if(candidates.empty())
    {
        ui->candidateComboBox->setEnabled(false);
    }
    else
    {
        show_candidate_clicked(posForChange);
    }
}