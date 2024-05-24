#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->topScorersTable->hide();
    ui->table->show();
    ui->hidetopscorrers->hide();
    ui->hidetoppenalty->hide();
    ui->topPenaltyTable->hide();
    ui->WorstscorersTable->hide();
    ui->hideworstscorers->hide();
    ui->frame->show();
    ui->EDITMENU->hide();
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->topPenaltyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->topPenaltyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->WorstscorersTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openfilebut_clicked()
{
    pathToFile = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::homePath(), tr("TXT файл (*.txt)"));
    file.setFileName(pathToFile);
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }

    QTextStream fileStream(&file);
    FromFiletoVector();
}

void MainWindow::FromFiletoVector(){
    file.setFileName(pathToFile);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "Error", "Failed to open the file.");
        return;
    }

    QTextStream in(&file);
    players.clear();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList playerData = line.split(',');

        if (playerData.size() == 5)
        {
            Player player;
            player.name = playerData[0];
            player.club = playerData[1];
            player.role = playerData[2];
            player.get_goals(playerData[3]);
            player.get_penalty(playerData[4]);

            players.append(player);
        }
    }
    file.close();
    ui->table->setRowCount(players.size());
    for (int i = 0; i < players.size(); ++i) {
        QTableWidgetItem* itm0 = new QTableWidgetItem(players[i].name);
        ui->table->setItem(i, 0, itm0);

        QTableWidgetItem* itm1 = new QTableWidgetItem(players[i].club);
        ui->table->setItem(i, 1, itm1);

        QTableWidgetItem* itm2 = new QTableWidgetItem(players[i].role);
        ui->table->setItem(i, 2, itm2);

        QTableWidgetItem* itm3 = new QTableWidgetItem(players[i].print_goals());
        ui->table->setItem(i, 3, itm3);

        QTableWidgetItem* itm4 = new QTableWidgetItem(players[i].print_penalty());
        ui->table->setItem(i, 4, itm4);
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->table->hide();
    ui->topScorersTable->show();
    QVector<Player> topScorers = players;
    std::sort(topScorers.begin(), topScorers.end(), [](const Player& a, const Player& b) {
        if (a.goals_num != b.goals_num) {
            return a.goals_num > b.goals_num; // Сортировка по убыванию количества голов
        } else {
            return a.penalty_num < b.penalty_num; // Сортировка по возрастанию штрафных очков
        }
    });
    int count = qMin(10, topScorers.size());

    ui->topScorersTable->setRowCount(count);
    for (int i = 0; i < count; ++i) {
        QTableWidgetItem* itm0 = new QTableWidgetItem(topScorers[i].name);
        ui->topScorersTable->setItem(i, 0, itm0);

        QTableWidgetItem* itm1 = new QTableWidgetItem(topScorers[i].club);
        ui->topScorersTable->setItem(i, 1, itm1);

        QTableWidgetItem* itm2 = new QTableWidgetItem(topScorers[i].role);
        ui->topScorersTable->setItem(i, 2, itm2);

        QTableWidgetItem* itm3 = new QTableWidgetItem(topScorers[i].print_goals());
        ui->topScorersTable->setItem(i, 3, itm3);

        QTableWidgetItem* itm4 = new QTableWidgetItem(topScorers[i].print_penalty());
        ui->topScorersTable->setItem(i, 4, itm4);
    }
    ui->hidetopscorrers->show();
}


void MainWindow::on_hidetopscorrers_clicked()
{
    ui->topScorersTable->hide();
    ui->table->show();
    ui->hidetopscorrers->hide();
}


void MainWindow::on_biggestpenalty_clicked()
{
    ui->table->hide();
    ui->topPenaltyTable->show();
    QVector<Player> topPenalty = players;
    std::sort(topPenalty.begin(), topPenalty.end(), [](const Player& a, const Player& b) {
        if (a.penalty_num != b.penalty_num) {
            return a.penalty_num > b.penalty_num; // Сортировка по убыванию количества голов
        } else {
            return a.goals_num > b.goals_num; // Сортировка по возрастанию штрафных очков
        }
    });
    int count = qMin(10, topPenalty.size());

    ui->topPenaltyTable->setRowCount(count);
    for (int i = 0; i < count; ++i) {
        QTableWidgetItem* itm0 = new QTableWidgetItem(topPenalty[i].name);
        ui->topPenaltyTable->setItem(i, 0, itm0);

        QTableWidgetItem* itm1 = new QTableWidgetItem(topPenalty[i].club);
        ui->topPenaltyTable->setItem(i, 1, itm1);

        QTableWidgetItem* itm2 = new QTableWidgetItem(topPenalty[i].role);
        ui->topPenaltyTable->setItem(i, 2, itm2);

        QTableWidgetItem* itm3 = new QTableWidgetItem(topPenalty[i].print_goals());
        ui->topPenaltyTable->setItem(i, 3, itm3);

        QTableWidgetItem* itm4 = new QTableWidgetItem(topPenalty[i].print_penalty());
        ui->topPenaltyTable->setItem(i, 4, itm4);
    }
    ui->hidetoppenalty->show();
}


void MainWindow::on_hidetoppenalty_clicked()
{
    ui->topPenaltyTable->hide();
    ui->table->show();
    ui->hidetoppenalty->hide();
}



void MainWindow::on_worstscorersbut_clicked()
{
    ui->table->hide();
    ui->WorstscorersTable->show();
    QVector<Player> worstScorers = players;
    std::sort(worstScorers.begin(), worstScorers.end(), [](const Player& a, const Player& b) {
        if (a.goals_num != b.goals_num) {
            return a.goals_num < b.goals_num; // Сортировка по убыванию количества голов
        } else {
            return a.penalty_num > b.penalty_num; // Сортировка по возрастанию штрафных очков
        }
    });
    int count = qMin(10, worstScorers.size());

    ui->WorstscorersTable->setRowCount(count);
    for (int i = 0; i < count; ++i) {
        QTableWidgetItem* itm0 = new QTableWidgetItem(worstScorers[i].name);
        ui->WorstscorersTable->setItem(i, 0, itm0);

        QTableWidgetItem* itm1 = new QTableWidgetItem(worstScorers[i].club);
        ui->WorstscorersTable->setItem(i, 1, itm1);

        QTableWidgetItem* itm2 = new QTableWidgetItem(worstScorers[i].role);
        ui->WorstscorersTable->setItem(i, 2, itm2);

        QTableWidgetItem* itm3 = new QTableWidgetItem(worstScorers[i].print_goals());
        ui->WorstscorersTable->setItem(i, 3, itm3);

        QTableWidgetItem* itm4 = new QTableWidgetItem(worstScorers[i].print_penalty());
        ui->WorstscorersTable->setItem(i, 4, itm4);
    }
    ui->hideworstscorers->show();
}


void MainWindow::on_hideworstscorers_clicked()
{
    ui->WorstscorersTable->hide();
    ui->table->show();
    ui->hideworstscorers->hide();
}

void MainWindow::on_addbut_clicked()
{
    ui->frame->hide();
    ui->EDITMENU->show();
    ui->confirmbut->show();
    ui->confirmbut_2->hide();
}


void MainWindow::on_confirmbut_clicked()
{
        QString name = ui->nameline->text();
        QString club = ui->clubline->text();
        QString role = ui->roleline->text();
        int goals = ui->goalsline->text().toInt();
        int penaltyPoints = ui->penaltyline->text().toInt();
        if(goals < 0 || penaltyPoints < 0){
            QMessageBox::critical(this, "Error", "Failed.");
            return;
        }
        Player newPlayer(name, goals, penaltyPoints, club, role);

        players.push_back(newPlayer);

        int row = ui->table->rowCount();
        ui->table->insertRow(row);

        QTableWidgetItem* itm0 = new QTableWidgetItem(name);
        ui->table->setItem(row, 0, itm0);

        QTableWidgetItem* itm1 = new QTableWidgetItem(club);
        ui->table->setItem(row, 1, itm1);

        QTableWidgetItem* itm2 = new QTableWidgetItem(role);
        ui->table->setItem(row, 2, itm2);

        QTableWidgetItem* itm3 = new QTableWidgetItem(QString::number(goals));
        ui->table->setItem(row, 3, itm3);

        QTableWidgetItem* itm4 = new QTableWidgetItem(QString::number(penaltyPoints));
        ui->table->setItem(row, 4, itm4);
        if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << name << "," << club << "," << role << ","
                   << goals << "," << penaltyPoints << "\n";
            file.close();
        }

        ui->nameline->clear();
        ui->clubline->clear();
        ui->roleline->clear();
        ui->goalsline->clear();
        ui->penaltyline->clear();
        ui->EDITMENU->hide();
        ui->frame->show();
}


void MainWindow::on_editbut_clicked()
{
    ui->frame->hide();
    ui->EDITMENU->show();
    ui->confirmbut->hide();
    ui->confirmbut_2->show();
    selectedRow = ui->table->currentRow();
    if (selectedRow < 0 || selectedRow >= ui->table->rowCount()){
        QMessageBox::critical(this, "Error", "Failed.");
        ui->frame->show();
        ui->EDITMENU->hide();
        ui->confirmbut->hide();
        ui->confirmbut_2->hide();
        return;
    }
    QTableWidgetItem* nameItem = ui->table->item(selectedRow, 0);
    QTableWidgetItem* clubItem = ui->table->item(selectedRow, 1);
    QTableWidgetItem* roleItem = ui->table->item(selectedRow, 2);
    QTableWidgetItem* goalsItem = ui->table->item(selectedRow, 3);
    QTableWidgetItem* penaltyPointsItem = ui->table->item(selectedRow, 4);

    if (!nameItem || !clubItem || !roleItem || !goalsItem || !penaltyPointsItem){
        QMessageBox::critical(this, "Error", "Failed.");
        ui->frame->show();
        ui->EDITMENU->hide();
        ui->confirmbut->hide();
        ui->confirmbut_2->hide();
        return;
    }

    QString currentName = nameItem->text();
    QString currentClub = clubItem->text();
    QString currentRole = roleItem->text();
    QString currentGoals = goalsItem->text();
    QString currentPenaltyPoints = penaltyPointsItem->text();
    ui->nameline->setText(currentName);
    ui->clubline->setText(currentClub);
    ui->roleline->setText(currentRole);
    ui->goalsline->setText(currentGoals);
    ui->penaltyline->setText(currentPenaltyPoints);
}

void MainWindow::on_confirmbut_2_clicked()
{
    QString newName = ui->nameline->text();
    QString newClub = ui->clubline->text();
    QString newRole = ui->roleline->text();
    int newGoals = ui->goalsline->text().toInt();
    int newPenaltyPoints = ui->penaltyline->text().toInt();

    // Обновление значений в массиве players
    Player& player = players[selectedRow];
    player.name = newName;
    player.club = newClub;
    player.role = newRole;
    player.goals_num = newGoals;
    player.penalty_num = newPenaltyPoints;

    // Обновление значений в QTableWidgetItem
    QTableWidgetItem* itm0 = new QTableWidgetItem(newName);
    ui->table->setItem(selectedRow, 0, itm0);

    QTableWidgetItem* itm1 = new QTableWidgetItem(newClub);
    ui->table->setItem(selectedRow, 1, itm1);

    QTableWidgetItem* itm2 = new QTableWidgetItem(newRole);
    ui->table->setItem(selectedRow, 2, itm2);

    QTableWidgetItem* itm3 = new QTableWidgetItem(QString::number(newGoals));
    ui->table->setItem(selectedRow, 3, itm3);

    QTableWidgetItem* itm4 = new QTableWidgetItem(QString::number(newPenaltyPoints));
    ui->table->setItem(selectedRow, 4, itm4);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        for (const Player& player : players) {
            stream << player.name << "," << player.club << "," << player.role << ","
                   << player.goals_num << "," << player.penalty_num << "\n";
        }
        file.close();
    }
    ui->nameline->clear();
    ui->clubline->clear();
    ui->roleline->clear();
    ui->goalsline->clear();
    ui->penaltyline->clear();
    ui->EDITMENU->hide();
    ui->frame->show();
    ui->confirmbut_2->hide();
}

