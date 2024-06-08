
#include "leaderboardwindow.h"
#include "ui_LeaderBoardWindow.h"
#include "mainwindow.h"
#include <QTableWidgetItem>
#include <QSqlRecord>
#include <QSqlError>
LeaderBoardWindow::LeaderBoardWindow(int col,QString n,QWidget *parent) :
        QWidget(parent), ui(new Ui::LeaderBoardWindow) {
    name = n;
    colorIndex = col;
    ui->setupUi(this);
    QSqlTableModel* model = new QSqlTableModel(this, database.db);
    model->setTable("LeaderBoard");
    model->select();
    model->sort(1,Qt::DescendingOrder);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 250);
    ui->tableView->setColumnWidth(1, 130);
    //ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->backToMenuBut,&QPushButton::clicked,this,&LeaderBoardWindow::backToMenu);
}
void LeaderBoardWindow::backToMenu() {
    menuWindow = new MenuWindow(colorIndex,name);
    this->close();
    menuWindow->show();
}

/*void LeaderBoardWindow::addToTable() {
    db.transaction();
    QSqlRecord record = model->record();
    record.setValue("Username","hyina");
    record.setValue("Score",1212);

    qDebug( )<< record << model->insertRecord(-1,record);
    qDebug() << model->lastError();
    model->submitAll(); // Подтверждаем изменения в базе данных
}*/
LeaderBoardWindow::~LeaderBoardWindow() {
    delete ui;
}
