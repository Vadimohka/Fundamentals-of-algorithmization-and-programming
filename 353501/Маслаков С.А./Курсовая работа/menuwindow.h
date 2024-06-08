
#ifndef SNAKE_GAME_MENUWINDOW_H
#define SNAKE_GAME_MENUWINDOW_H
#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class MenuWindow; }
QT_END_NAMESPACE
class MainWindow;
class LeaderBoardWindow;
class MenuWindow : public QWidget {
Q_OBJECT

public:
    explicit MenuWindow(int col,QString name,QWidget *parent = nullptr);
    ~MenuWindow() override;
private:
    QString imagePath = "/Users/sagot/Documents/Snake-game/images/snakeUnit1Head.png";
    int colorIndex = 1;
    QString name;
    Ui::MenuWindow *ui;
    MainWindow* mainwindow;
    LeaderBoardWindow* leaderBoardWindow;
private slots:
    void openMainWindow();
    void showSkinFrame();
    void getSkinColor();
    void changedColorOnCombobox(int);
    void openLeaderBoardWindow();
};


#endif //SNAKE_GAME_MENUWINDOW_H
