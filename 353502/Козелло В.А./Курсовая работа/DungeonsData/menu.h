#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu() override;

private:
    Ui::Menu *ui;

signals:
    void Close();
    void Continue();
    void NewGame();

private slots:
    void on_pushButton_close_clicked();
    void on_pushButton_continue_clicked();
    void on_pushButton_3_clicked();
};

#endif // MENU_H
