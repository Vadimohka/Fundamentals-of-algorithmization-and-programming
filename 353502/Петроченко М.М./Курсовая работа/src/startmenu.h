//
// Created by acryoz on 4/30/24.
//

#ifndef COURSEWORK_SRC_STARTMENU_H_
#define COURSEWORK_SRC_STARTMENU_H_

#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

namespace Ui {
class StartMenu;
}

QT_END_NAMESPACE

class StartMenu : public QWidget {
    Q_OBJECT

   public:
    explicit StartMenu(QWidget* parent = nullptr);
    ~StartMenu() override;
   private slots:
    void onBotClick();
    void onPlayerClick();
   signals:
    void botChosen(bool, uint8_t);

   private:
    QRadioButton* black;
    QRadioButton* white;
    QPushButton* bot_button;
    QPushButton* player_button;
    QVBoxLayout* vbox;
    bool bot = false;
    Ui::StartMenu* ui;
};


#endif  //COURSEWORK_SRC_STARTMENU_H_
