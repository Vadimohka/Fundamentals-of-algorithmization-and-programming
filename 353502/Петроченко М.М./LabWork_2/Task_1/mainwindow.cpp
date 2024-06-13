//
// Created by acryoz on 27.2.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"

const uint LINEWIDTH = 200;
const uint LABELWIDTH = 75;
const uint MAXYEAR = 9999;

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    auto fileName = QFileDialog::getOpenFileName(this, tr("Open txt"), "/home", tr("Text Files (*.txt)"));

    this->file = new QFile(fileName);
    if (!file->open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug() << "Not open";
    }

    this->save_button = new QPushButton("Save");

    QObject::connect(this->save_button, SIGNAL(clicked()), this, SLOT(save()));

    this->errorLabel = new QLabel("Invalid input");
    this->errorLabel->setStyleSheet("QLabel { color : red; }");

    this->day_label = new QLabel("Day:");
    this->day_label->setMaximumWidth(LABELWIDTH);
    this->month_label = new QLabel("Month:");
    this->month_label->setMaximumWidth(LABELWIDTH);
    this->year_label = new QLabel("Year:");
    this->year_label->setMaximumWidth(LABELWIDTH);

    this->validator = new QIntValidator(0, MAXYEAR);

    this->day_line = new QLineEdit();
    this->day_line->setValidator(this->validator);
    this->day_line->setMaximumWidth(LINEWIDTH);

    this->month_line = new QLineEdit();
    this->month_line->setValidator(this->validator);
    this->month_line->setMaximumWidth(LINEWIDTH);

    this->year_line = new QLineEdit();
    this->year_line->setValidator(this->validator);
    this->year_line->setMaximumWidth(LINEWIDTH);

    this->arbitrary_vbox = new QVBoxLayout;

    this->grid2 = new QGridLayout;
    this->grid2->addWidget(day_label, 0, 0);
    this->grid2->addWidget(day_line, 0, 1);
    this->grid2->addWidget(month_label, 1, 0);
    this->grid2->addWidget(month_line, 1, 1);
    this->grid2->addWidget(year_label, 2, 0);
    this->grid2->addWidget(year_line, 2, 1);

    this->arbitrary_vbox->addLayout(this->grid2);
    this->arbitrary_vbox->addWidget(this->errorLabel);
    this->errorLabel->hide();
    this->arbitrary_vbox->addWidget(this->save_button);

    this->values = readDates(this->file);

    for(int i = 0; i < this->values->size(); ++i){
        if ((*this->values)[i].isValid()) {
            this->values->remove(i);
        }
    }

    this->model = new QTableViewModel();
    this->model->populate(this->values);
    this->model->setBday(Date(LINEWIDTH, LINEWIDTH, LINEWIDTH));

    this->tableView = new QTableView(this);
    this->tableView->showGrid();
    this->tableView->setMinimumSize(this->size());
    this->tableView->setModel(this->model);
    this->tableView->resizeColumnsToContents();

    this->add_button = new QPushButton("Add record");
    QObject::connect(add_button, SIGNAL(clicked()), this, SLOT(onAddPush()));

    this->delete_button = new QPushButton("Delete record");
    QObject::connect(delete_button, SIGNAL(clicked()), this, SLOT(onDelPush()));

    this->redact_button = new QPushButton("Redact record");
    QObject::connect(redact_button, SIGNAL(clicked()), this, SLOT(onRedactPush()));

    this->bday_button = new QPushButton("Set birthday");
    QObject::connect(bday_button, SIGNAL(clicked()), this, SLOT(onBdayPush()));

    this->grid = new QGridLayout;
    this->grid->addWidget(this->add_button, 0, 0);
    this->grid->addWidget(this->redact_button, 0, 1);
    this->grid->addWidget(this->delete_button, 1, 0);
    this->grid->addWidget(this->bday_button, 1, 1);

    this->vbox = new QVBoxLayout;
    this->vbox->addWidget(this->tableView);
    this->vbox->addLayout(this->grid);

    this->hbox = new QHBoxLayout;
    this->hbox->addLayout(this->vbox);
    this->hbox->addLayout(this->arbitrary_vbox);

    this->setLayout(this->hbox);
}


void MainWindow::onAddPush() {
    Date date = Date(this->day_line->text().toInt(), this->month_line->text().toInt(), this->year_line->text().toInt());
    if(date.isValid()){
        this->errorLabel->hide();
        this->model->append(date);
    } else {
        this->day_line->clear();
        this->month_line->clear();
        this->year_line->clear();
        this->errorLabel->show();
    }
}


void MainWindow::onDelPush() {
    QVector<int> selected = this->selectedRows();
    if(selected.empty()){
        return;
    }
    int j = selected[0];
    for(int i = 0; i < selected.size(); ++i){
        qDebug() << selected[i];
        this->model->del(j);
    }
}


void MainWindow::onRedactPush(){
    QVector<int> selected = this->selectedRows();
    if(selected.empty()){
        return;
    }
    Date dt = Date(this->day_line->text().toInt(), this->month_line->text().toInt(), this->year_line->text().toInt());
    int j = selected[0];
    if(dt.isValid()){
        this->errorLabel->hide();
        this->model->redact(dt, j);
    }
    else{
        this->day_line->clear();
        this->month_line->clear();
        this->year_line->clear();
        this->errorLabel->show();
    }
}


void MainWindow::onBdayPush() {
    Date dt = Date(this->day_line->text().toInt(), this->month_line->text().toInt(), this->year_line->text().toInt());
    if(dt.isValid()){
        this->errorLabel->hide();
        this->model->setBday(dt);
    }
    else{
        this->day_line->clear();
        this->month_line->clear();
        this->year_line->clear();
        this->errorLabel->show();
    }
}

QVector<int> MainWindow::selectedRows() {
    QModelIndexList selection = this->tableView->selectionModel()->selectedRows();
    QVector<int> rs;
    for(int i = 0; i < selection.size(); ++i){
        rs.push_back(selection.at(i).row());
    }
    return rs;
}


void MainWindow::getDatePopup(const Date& dt) {
    this->pdate = dt;
    this->date_inputed = true;
}


void MainWindow::save() {
    writeDates(this->file, this->values);
}


MainWindow::~MainWindow() {
    delete ui;
}
