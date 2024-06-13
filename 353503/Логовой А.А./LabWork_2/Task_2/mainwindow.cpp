#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    player(),
    info_display(new QTextEdit(this)),
    button1(new QPushButton(this)),
    button2(new QPushButton(this)),
    button3(new QPushButton(this)),
    button4(new QPushButton(this)),
    button5(new QPushButton(this)),
    button6(new QPushButton(this)),
    button7(new QPushButton(this)),
    name_line(new QLineEdit(this)),
    club_line(new QLineEdit(this)),
    positition_line(new QLineEdit(this)),
    goals_line(new QLineEdit(this)),
    penalty_line(new QLineEdit(this)),
    intValidator(new QIntValidator(this))

{
    setWindowTitle("Sports.ru");
    resize(850,800);

    fileName = "";

    table = new QTableWidget(0, 1, this);
    headers << "Fotballer Name";
    table->setHorizontalHeaderLabels(headers);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->resize(300,800);
    table->horizontalHeader()->setStretchLastSection(true);

    info_display->setGeometry(300,0,300,800);
    info_display->setReadOnly(true);

    connect(table, &QTableWidget::cellDoubleClicked, this, &MainWindow::displayInformation);

    name_line->setGeometry(650,50,150,30);
    name_line->setPlaceholderText("Name");

    club_line->setGeometry(650,100,150,30);
    club_line->setPlaceholderText("Club");

    positition_line->setGeometry(650,150,150,30);
    positition_line->setPlaceholderText("Position");

    goals_line->setGeometry(650,200,150,30);
    goals_line->setValidator(intValidator);
    goals_line->setPlaceholderText("Goals");

    penalty_line->setGeometry(650,250,150,30);
    penalty_line->setValidator(intValidator);
    penalty_line->setPlaceholderText("Penalty points");


    button1->setGeometry(650,300,150,30);
    button1->setText("Save information");
    connect(button1, &QPushButton::clicked, this, &MainWindow::saveInformation);

    button2->setGeometry(650,350,150,30);
    button2->setText("Open file");
    connect(button2, &QPushButton::clicked, this, &MainWindow::openFile);

    button3->setGeometry(650,400,150,30);
    button3->setText("Create file");
    connect(button3, &QPushButton::clicked, this, &MainWindow::createFile);

    button4->setGeometry(650,450,150,30);
    button4->setText("Close file");
    connect(button4, &QPushButton::clicked, this, &MainWindow::closeFile);

    button5->setGeometry(650,500,150,30);
    button5->setText("Best Scorers");
    connect(button5, &QPushButton::clicked, this, &MainWindow::showTopScorers);

    button6->setGeometry(650,550,150,30);
    button6->setText("More Penalty Points");
    connect(button6, &QPushButton::clicked, this, &MainWindow::showTopPenalties);

    button7->setGeometry(650,600,150,30);
    button7->setText("Top 10 Players");
    connect(button7, &QPushButton::clicked, this, &MainWindow::showBestPlayers);

}

MainWindow::~MainWindow() {}

void MainWindow::displayInformation(short row, short column){
    Q_UNUSED(column);
    Footballer *players = player.at(row);
    info_display->setText(players->toString());
}

void MainWindow::saveInformation(){

    if(fileName != "" && checkInput()){

        Footballer *newPlayer = new Footballer(name_line->text(),
                                             club_line->text(),
                                             positition_line->text(),
                                             goals_line->text().toShort(),
                                             penalty_line->text().toShort());

        player.push_back(newPlayer);

        short row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(newPlayer->getName()));
        writeToFile(newPlayer);
        QMessageBox::about(nullptr, "Success" , "You add new fotballer");
    }
    else{
        if(checkInput())
            QMessageBox::critical(nullptr, "Erorr", "Next time enter all data");
        else
            QMessageBox::critical(nullptr, "Erorr", "No open file");
    }
    name_line->clear();
    club_line->clear();
    positition_line->clear();
    goals_line->clear();
    penalty_line->clear();
}

void MainWindow::openFile(){

    fileName = QFileDialog::getOpenFileName(nullptr, "blaugranas/oaip/laba2", "", "text files(*.txt);;All files(*)");

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error", "Not open the file");
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');

        if(parts.size() == 5) {
            QString name = parts[0].trimmed();
            QString club = parts[1].trimmed();
            QString position = parts[2].trimmed();
            short goals = parts[3].trimmed().toShort();
            short penaltyPoints = parts[4].trimmed().toShort();

            Footballer *newPlayer = new Footballer(name, club, position, goals, penaltyPoints);
            player.push_back(newPlayer);

            short row = table->rowCount();
            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(newPlayer->getName()));
        }
    }

    file.close();
    QMessageBox::about(nullptr, "Success" , "File was successfully opened and data was loaded");
}

void MainWindow::createFile(){

    fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"), file.errorString());
            return;
        }
        QTextStream out(&file);
        QMessageBox::about(nullptr, "Operation", "File was sucsesfully create");
    }
}

void MainWindow::closeFile() {

    if (fileName != "") {
        fileName = "";
        table->clear();
        table->setRowCount(0);
        player.clear();
        table->setHorizontalHeaderLabels(headers);
        info_display->clear();
        QMessageBox::information(this, "Opearation", "File was sucsesfully close");
    }
    else
        QMessageBox::critical(this, "Erorr" , "No open file");

}

void MainWindow::writeToFile(Footballer *player){
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << player->getName() << "," <<
                player->getClub() << "," << player->getPosition() << "," <<
                player->getGoals() << "," << player->getPenaltyPoints()  <<"\n";
            file.close();
        }
    }
}

bool MainWindow::checkInput(){

    if(name_line->text().isEmpty() || club_line->text().isEmpty()
        || goals_line->text().isEmpty() || positition_line->text().isEmpty()
        || penalty_line->text().isEmpty())
        return false;
    else{
        return true;
    }
}

void MainWindow::sortFootballer(bool (*compare)(Footballer*, Footballer*)){

    for(short i{}; i<player.size(); ++i){
        short j = i;
        while(j > 0 && compare(player[j-1],player[j])){
            std::swap(player[j-1],player[j]);
            j--;
        }
    }
}

void MainWindow::showTopScorers() {

    if(fileName !=""){

    sortFootballer(isMoreGoals);

    QMessageBox msgBox;
    msgBox.setWindowTitle("Top Scorrers");

    QString message;

    for (short i {}; i < player.size(); ++i) {
        message +=  QString::number(i + 1) + ") Name: " + player[i]->getName() + '\n' +
                    "Goals: " +  QString::number(player[i]->getGoals())  + '\n';
    }

    msgBox.setText(message);
    msgBox.exec();
    updateTable();

    }
    else
        QMessageBox::critical(nullptr, "Error" , "No Open file");
}

void MainWindow::showTopPenalties(){

    if(fileName !=""){

        sortFootballer(isMorePenalty);

        QMessageBox msgBox;
        msgBox.setWindowTitle("Top Penalties PLayers");

        QString message;

        short last_player = player.size() > 10 ? 10:player.size();

        for (short i {}; i < last_player; ++i) {
            message +=  QString::number(i + 1) + ") Name: " + player[i]->getName() + '\n' +
                       "Penalty points: " +  QString::number(player[i]->getPenaltyPoints())  + '\n';
        }

        msgBox.setText(message);
        msgBox.exec();

        updateTable();
    }
    else
        QMessageBox::critical(nullptr, "Error" , "No Open file");
}

void MainWindow::showBestPlayers(){

    if(fileName !=""){

        sortFootballer(isMorePoints);

        QMessageBox msgBox;
        msgBox.setWindowTitle("Top 10 PLayers");

        QString message;

        short last_player = player.size() > 10 ? 10:player.size();

        for (short i {}; i < last_player; ++i) {
            message +=  QString::number(i + 1) + ") Name: " + player[i]->getName() + '\n' +
                       "Goals: " + QString::number(player[i]->getGoals()) + '\n' +
                       "Penalty points: " +  QString::number(player[i]->getPenaltyPoints())  + '\n';
        }

        msgBox.setText(message);
        msgBox.exec();

        updateTable();
    }
    else
        QMessageBox::critical(nullptr, "Error" , "No Open file");
}

void MainWindow::updateTable() {
    table->clear();
    table->setRowCount(0);

    for (short i = 0; i < player.size(); ++i) {
        short row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(player[i]->getName()));
    }
}



