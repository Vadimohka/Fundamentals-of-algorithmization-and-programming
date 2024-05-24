#ifndef TILE_H
#define TILE_H

#include <QPushButton>
#include <QLabel>
#include <QRandomGenerator>

class Tile : public QPushButton
{
public:
    Tile(QWidget *parent = nullptr);
    void set_image(const QPixmap &image);
    void set_number(short number);
    void set_index(short index);
    short get_number();
    short get_index();
private:
    short _number;
    short _ind;
};

#endif // TILE_H
