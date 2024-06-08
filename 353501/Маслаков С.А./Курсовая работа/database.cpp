#include "database.h"
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlQuery>

Database::Database() : db(QSqlDatabase::addDatabase("QSQLITE"))
{
    db.setDatabaseName("/Users/sagot/Documents/Snake-game/usersdb.db");
    if (!db.open()) {
        qDebug() << "Failed to connect to the database";
    }
}

void Database::addToTable(const QString& username, int score)
{
    QSqlQuery query;
    query.prepare("INSERT INTO LeaderBoard (Username, Score) VALUES (:username, :score)");
    query.bindValue(":username", username);
    query.bindValue(":score", score);

    if (!query.exec()) {
        qDebug() << "Failed to add record:" << query.lastError().text();
    }
}