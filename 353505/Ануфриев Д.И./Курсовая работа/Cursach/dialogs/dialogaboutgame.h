#ifndef DIALOGABOUTGAME_H
#define DIALOGABOUTGAME_H

#include <QDialog>

namespace Ui {
class DialogAboutGame;
}

class DialogAboutGame : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAboutGame(QWidget *parent = nullptr);
    ~DialogAboutGame();

private:
    Ui::DialogAboutGame *ui;
};

#endif // DIALOGABOUTGAME_H
