//
// Created by acryoz on 5/4/24.
//

#ifndef COURSEWORK_LIB_ENDMENU_H_
#define COURSEWORK_LIB_ENDMENU_H_

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
class EndMenu;
}

QT_END_NAMESPACE

class EndMenu : public QWidget {
    Q_OBJECT

   public:
    explicit EndMenu(QWidget* parent = nullptr);
    ~EndMenu() override;
    void set(uint8_t winner);
   public slots:
    void onEnd();
    void onRematch();
   signals:
    void end();
    void restart();

   private:
    QLabel* label;
    QPushButton* ok_button;
    QPushButton* close_button;
    QVBoxLayout* vbox;
    QHBoxLayout* hbox;

    Ui::EndMenu* ui;
};


#endif  //COURSEWORK_LIB_ENDMENU_H_
