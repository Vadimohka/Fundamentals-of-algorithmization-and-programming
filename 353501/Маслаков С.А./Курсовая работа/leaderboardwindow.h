

#ifndef SNAKE_GAME_LEADERBOARDWINDOW_H
#define SNAKE_GAME_LEADERBOARDWINDOW_H
#include "database.h"
#include <QWidget>
#include "menuwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LeaderBoardWindow; }
QT_END_NAMESPACE
class MainWindow;
class LeaderBoardWindow : public QWidget {
Q_OBJECT

public:
    explicit LeaderBoardWindow(int col,QString n,QWidget *parent = nullptr);

    ~LeaderBoardWindow() override;

private:
    QString name;
    int colorIndex;
    QSqlDatabase db;
    Ui::LeaderBoardWindow *ui;
    QSqlTableModel* model;
    MainWindow* mainwindow;
    MenuWindow* menuWindow;
    Database database;
    //void addToTable();
private slots:
    void backToMenu();
};


#endif //SNAKE_GAME_LEADERBOARDWINDOW_H
