#include <QSqlDatabase>
#include <QSqlTableModel>
#pragma once
class Database
{
public:
    QSqlDatabase db;

    Database();
    void addToTable(const QString& username, int score);
};

