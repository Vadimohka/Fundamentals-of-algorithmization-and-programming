#ifndef PLAYERMENU_HPP
#define PLAYERMENU_HPP

// qt
#include <QDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QColorDialog>
#include <QPushButton>

// connected four
#include "common.hpp"

namespace Ui {
class PlayerMenu;
}

class PlayerMenu : public QDialog
{
    Q_OBJECT
protected:
    QPixmap player1Pixmap_;
    QPixmap player2Pixmap_;
    QColor player1Color_;
    QColor player2Color_;

public:
    explicit PlayerMenu(QString player1Name, QString player2Name, QColor player1Color, QColor player2Color, QWidget *parent = nullptr);
    QColor getPlayer1Color();
    QColor getPlayer2Color();
    QString getPlayer1Name();
    QString getPlayer2Name();
    ~PlayerMenu();

private slots:
    void on_player2Color_clicked();

    void on_player1Color_clicked();

    void on_textChanged();

private:
    Ui::PlayerMenu *ui;
};

#endif // PLAYERMENU_HPP
