#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <QProcess>
namespace Ui {
class GameOverWindow;
}

class GameOverWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverWindow(QWidget *parent = 0);
    ~GameOverWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::GameOverWindow *ui;

};

#endif // GAMEOVER_H
