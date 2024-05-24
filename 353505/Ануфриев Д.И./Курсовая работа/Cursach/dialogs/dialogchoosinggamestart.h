#ifndef DIALOGCHOOSINGGAMESTART_H
#define DIALOGCHOOSINGGAMESTART_H

#include <QMainWindow>

namespace Ui {
class DialogChoosingGameStart;
}

class DialogChoosingGameStart : public QMainWindow
{
    Q_OBJECT

public:
    explicit DialogChoosingGameStart(QWidget *parent = nullptr);
    ~DialogChoosingGameStart();

private slots:
    void on_continueButton_clicked();

    void on_newGameButton_clicked();

private:
    Ui::DialogChoosingGameStart *ui;

signals:
    void continueGame();
    void restartGame();
};

#endif // DIALOGCHOOSINGGAMESTART_H
