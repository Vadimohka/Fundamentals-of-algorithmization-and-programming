#include "ClasMenu.h"

ClasMenu::ClasMenu() = default;

ClasMenu::ClasMenu(QString nas, QString opis, int price) {
    ClasMenu::nas = nas;
    ClasMenu::opis = opis;
    ClasMenu::price = price;
}
