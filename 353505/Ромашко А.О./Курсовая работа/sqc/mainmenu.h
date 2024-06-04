#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_pushButton_Exit_clicked();

    void on_pushButton_Play_clicked();
public slots:
    void openMainMenu();
signals:
    void MainMenutoSaveMenuSignal();
private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
