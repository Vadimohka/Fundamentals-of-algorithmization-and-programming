#ifndef SAVEMENU_H
#define SAVEMENU_H

#include <QWidget>

namespace Ui {
class SaveMenu;
}

class SaveMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SaveMenu(QWidget *parent = nullptr);
    ~SaveMenu();

public slots:
    void openSlot();
signals:
    void SaveMenuExitSignal();
    void SaveMenuExitTGLSoSignal();
private slots:
    void on_pushButton_Back_clicked();
    void on_pushButton_NewGame_clicked();
    void on_pushButton_OpenGame_clicked();

private:
    Ui::SaveMenu *ui;
};

#endif // SAVEMENU_H
