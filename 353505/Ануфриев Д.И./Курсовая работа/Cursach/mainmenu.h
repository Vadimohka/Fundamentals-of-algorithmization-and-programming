#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    void myShow();

private slots:
    void on_playButton_clicked();

    void on_aboutButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::MainMenu *ui;

signals:
    void play();
};

#endif // MAINMENU_H
