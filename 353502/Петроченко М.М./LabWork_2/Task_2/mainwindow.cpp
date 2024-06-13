//
// Created by acryoz on 7.3.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto fileName = QFileDialog::getOpenFileName(this, tr("Open txt"), "/home", tr("Text Files (*.txt)"));
    this->selected_index = 0;
    this->file = new QFile(fileName);
    if (!file->open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug() << "Not open";
    }

    //data
    this->parties = readFile(this->file);

    //labels
    this->name_label = new QLabel("Full name");
    this->age_label = new QLabel("Age");
    this->party_label = new QLabel("Party");
    this->region_label = new QLabel("Region number");
    this->occupation_label = new QLabel("Occupation");
    this->income_label = new QLabel("Income");

    //lines
    this->name_line = new QLineEdit;
    this->age_line = new QLineEdit;
    this->party_line = new QLineEdit;
    this->region_line = new QLineEdit;
    this->occupation_line = new QLineEdit;
    this->income_line = new QLineEdit;

    //buttons
    this->form_button = new QPushButton("Form bulletin");
    QObject::connect(this->form_button, SIGNAL(clicked()), this, SLOT(formBulletin()));
    this->find_button = new QPushButton("Find");
    QObject::connect(this->find_button, SIGNAL(clicked()), this, SLOT(findCandidates()));
    this->sort_button = new QPushButton("Sort");
    QObject::connect(this->sort_button, SIGNAL(clicked()), this, SLOT(sort()));
    this->show_button = new QPushButton("Show all");
    QObject::connect(this->show_button, SIGNAL(clicked()), this, SLOT(showall()));
    this->add_button = new QPushButton("Add");
    QObject::connect(this->add_button, SIGNAL(clicked()), this, SLOT(add()));
    this->del_button = new QPushButton("Delete");
    QObject::connect(this->del_button, SIGNAL(clicked()), this, SLOT(del()));
    this->edit_button = new QPushButton("Edit");
    QObject::connect(this->edit_button, SIGNAL(clicked()), this, SLOT(edit()));
    this->save_button = new QPushButton("Save");
    QObject::connect(this->save_button, SIGNAL(clicked()), this, SLOT(save()));
    this->select_button = new QPushButton("Select");
    QObject::connect(this->select_button, SIGNAL(clicked()), this, SLOT(select()));

    //textEdit
    this->textEdit = new QPlainTextEdit;
    this->textEdit->setReadOnly(true);

    //layouts
    this->input_grid = new QGridLayout;
    this->input_grid->addWidget(this->name_label, 0, 0);
    this->input_grid->addWidget(this->name_line, 0, 1);
    this->input_grid->addWidget(this->age_label, 1, 0);
    this->input_grid->addWidget(this->age_line, 1,1);
    this->input_grid->addWidget(this->party_label, 2, 0);
    this->input_grid->addWidget(this->party_line, 2, 1);
    this->input_grid->addWidget(this->occupation_label, 3, 0);
    this->input_grid->addWidget(this->occupation_line, 3, 1);
    this->input_grid->addWidget(this->income_label, 4, 0);
    this->input_grid->addWidget(this->income_line, 4, 1);
    this->input_grid->addWidget(this->region_label, 5, 0);
    this->input_grid->addWidget(this->region_line, 5, 1);
    this->input_grid->addWidget(this->select_button);

    this->hbox = new QHBoxLayout;
    this->hbox->addLayout(this->input_grid);
    this->hbox->addWidget(this->textEdit);

    this->buttons_grid = new QGridLayout;
    this->buttons_grid->addWidget(this->form_button, 0, 0);
    this->buttons_grid->addWidget(this->find_button, 0, 1);
    this->buttons_grid->addWidget(this->sort_button, 1, 0);
    this->buttons_grid->addWidget(this->show_button, 1, 1);
    this->buttons_grid->addWidget(this->add_button, 2, 0);
    this->buttons_grid->addWidget(this->del_button, 2, 1);
    this->buttons_grid->addWidget(this->edit_button, 3, 0);
    this->buttons_grid->addWidget(this->save_button, 3, 1);

    this->vbox = new QVBoxLayout;
    this->vbox->addLayout(this->hbox);
    this->vbox->addLayout(this->buttons_grid);

    this->setLayout(this->vbox);
}

void MainWindow::formBulletin() {
    QString bul;
    QTextStream out(&bul);
    QList<QString> names = this->parties->keys();
    for(const QString& name: names){
        Party p = (*this->parties)[name];
        out << "Party: " << p.name() << '\n';
        out << "Number of candidates: " << p.candidates()->size() << '\n';
        out << "Average age: " << p.averageAge() << '\n';
        out << "Average income: " << p.averageIncome() << '\n';
        out << "Most common occupation: " << p.mostCommonProfession() << '\n';
        out << "-----------------------------------------------\n";
    }
    this->textEdit->setPlainText(bul);
}


void MainWindow::findCandidates() {
    if(!this->party_line->text().isEmpty()){
        QString name = this->party_line->text().toLower();
        if(this->parties->contains(name)){
            Party p = (*this->parties)[name];
            QString bul;
            QTextStream out(&bul);
            out << "Party: " << p.name() << '\n';
            for(const Candidate& can : *p.candidates()){
                out << "Candidate: " << can.name() << '\n';
                out << "Age: " << can.age() << '\n';
                out << "Region: " << can.region() << '\n';
                out << "Occupation: " << can.occupation() << '\n';
                out << "Income: " << can.income() << '\n';
                out << "-----------------------------------------------\n";
            }
            this->textEdit->setPlainText(bul);
            this->clearLines();
        }
        else{
            this->textEdit->setPlainText("No such party");
        }
    }
    else{
        this->textEdit->setPlainText("No party name provided");
    }
}


void MainWindow::sort() {
    QList<QString> names = this->parties->keys();
    for(const QString& name: names){
        Party* p = &(*this->parties)[name];
        std::sort(p->candidates()->begin(), p->candidates()->end());
    }
}


void MainWindow::showall() {
    QString bul;
    QTextStream out(&bul);
    QList<QString> names = this->parties->keys();
    for(const QString& name: names){
        Party p = (*this->parties)[name];
        for(const Candidate& can: *p.candidates()){
            out << can.print();
        }
    }
    this->textEdit->setPlainText(bul);
}


void MainWindow::add() {
    if(!this->name_line->text().isEmpty() && !this->party_line->text().isEmpty()
        && !this->income_line->text().isEmpty() && !this->region_line->text().isEmpty()
        && !this->occupation_line->text().isEmpty() && !this->age_line->text().isEmpty()){
        if(!this->parties->contains(this->party_line->text().toLower())){
            (*this->parties).insert(this->party_line->text().toLower(), Party(this->party_line->text().toLower()));
        }
        (*this->parties)[this->party_line->text().toLower()]
                .add(Candidate(this->name_line->text(),
                               this->region_line->text().toInt(),
                               this->party_line->text().toLower(),
                               this->occupation_line->text().toLower(),
                               this->income_line->text().toInt(),
                               this->age_line->text().toInt()));
        this->clearLines();
    }
    else{
        this->textEdit->setPlainText("Not all fields are filled");
    }
}


void MainWindow::del() {
    int deleted = 0;
    if(!this->name_line->text().isEmpty() && !this->party_line->text().isEmpty()
       && !this->income_line->text().isEmpty() && !this->region_line->text().isEmpty()
       && !this->occupation_line->text().isEmpty() && !this->age_line->text().isEmpty()){
        if(!this->parties->contains(this->party_line->text().toLower())){
            this->textEdit->setPlainText("No such party");
            return;
        }
        Party p = (*this->parties)[this->party_line->text().toLower()];
        for(int i = 0; i < p.candidates()->size(); ++i) {
            Candidate can = (*p.candidates())[i];
            if (can.name() == this->name_line->text() &&
                can.income() == this->income_line->text().toInt() &&
                can.region() == this->region_line->text().toInt() &&
                can.occupation() == this->occupation_line->text().toLower() &&
                can.age() == this->age_line->text().toInt()) {
                (*this->parties)[this->party_line->text().toLower()].candidates()->remove(i);
                deleted += 1;
            }
        }
        if(deleted == 0){
            this->textEdit->setPlainText("No such candidate");
        }
        else{
            this->clearLines();
        }
    }
    else{
        this->textEdit->setPlainText("Not all fields are filled");
    }
}

void MainWindow::select() {
    bool is_selected = false;
    if(!this->name_line->text().isEmpty() && !this->party_line->text().isEmpty()
       && !this->income_line->text().isEmpty() && !this->region_line->text().isEmpty()
       && !this->occupation_line->text().isEmpty() && !this->age_line->text().isEmpty()){
        if(!this->parties->contains(this->party_line->text().toLower())){
            this->textEdit->setPlainText("No such party");
            return;
        }
        Party p = (*this->parties)[this->party_line->text().toLower()];
        for(int i = 0; i < p.candidates()->size(); ++i) {
            Candidate can = (*p.candidates())[i];
            if (can.name() == this->name_line->text() &&
                can.income() == this->income_line->text().toInt() &&
                can.region() == this->region_line->text().toInt() &&
                can.occupation() == this->occupation_line->text().toLower() &&
                can.age() == this->age_line->text().toInt()) {
                is_selected = true;
                this->selected_party = this->party_line->text().toLower();
                this->selected_index = i;
                this->selected = true;
                break;
            }
        }
        if(!is_selected){
            this->textEdit->setPlainText("No such candidate");
        }
        else{
            this->textEdit->setPlainText("Selected a candidate");
            this->clearLines();
        }
    }
    else{
        this->textEdit->setPlainText("Not all fields are filled");
    }

}


void MainWindow::edit() {
    if(this->selected){
        if(!this->name_line->text().isEmpty() && !this->party_line->text().isEmpty()
           && !this->income_line->text().isEmpty() && !this->region_line->text().isEmpty()
           && !this->occupation_line->text().isEmpty() && !this->age_line->text().isEmpty()) {
            if(this->selected_party == this->party_line->text().toLower()){
                (*this->parties)[this->selected_party].edit(this->selected_index, Candidate(this->name_line->text(),
                                                                                            this->region_line->text().toInt(),
                                                                                            this->selected_party,
                                                                                            this->occupation_line->text().toLower(),
                                                                                            this->income_line->text().toInt(),
                                                                                            this->age_line->text().toInt()));
            }
            else{
                this->textEdit->setPlainText("Cannot change party");
                this->party_line->clear();
            }
        }
        else{
            this->textEdit->setPlainText("Not all fields are filled");
        }

    }
    else{
        this->textEdit->setPlainText("No candidate selected");
    }
}


void MainWindow::clearLines() {
    this->name_line->clear();
    this->party_line->clear();
    this->income_line->clear();
    this->age_line->clear();
    this->occupation_line->clear();
    this->region_line->clear();
}


int MainWindow::count(){
    int c = 0;
    QList<QString> names = this->parties->keys();
    for(const QString& name: names){
        Party p = (*this->parties)[name];
        c += p.candidates()->size();
    }
    return c;
}

void MainWindow::save() {
    writeFile(this->file, this->parties);
}

MainWindow::~MainWindow() {
    delete ui;
}
