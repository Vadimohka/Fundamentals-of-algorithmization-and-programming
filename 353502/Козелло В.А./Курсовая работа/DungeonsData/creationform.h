#ifndef CREATIONFORM_H
#define CREATIONFORM_H

#include <QRandomGenerator>
#include <QWidget>
#include "world.h"
#include <armor.h>
#include <item.h>
#include <player.h>
#include <weapon.h>

namespace Ui {
class CreationForm;
}

class CreationForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreationForm(World *world, QWidget *parent = nullptr);
    ~CreationForm() override;

private slots:
    void on_createButton_clicked();

private:
    Ui::CreationForm *ui;
    World *world;
    Player *player = new Player;

signals:
    void Completed(Player *);
};

#endif // CREATIONFORM_H
