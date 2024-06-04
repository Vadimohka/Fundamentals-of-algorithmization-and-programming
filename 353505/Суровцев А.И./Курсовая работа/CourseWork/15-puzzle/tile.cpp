#include "tile.h"

Tile::Tile(QWidget *parent)
    : QPushButton(parent) {
    int green = QRandomGenerator::global()->bounded(150, 256);
    int red = QRandomGenerator::global()->bounded(200, 256);
    int blue = 0;
    QString colorStyle = QString("background-color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue);
    setStyleSheet(QString("QPushButton {%1}").arg(colorStyle));
}

void Tile::set_image(const QPixmap &image)
{
    QSize buttonSize = size();
    QPixmap scaledImage = image.scaled(buttonSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setIcon(QIcon(scaledImage));
    setIconSize(buttonSize);
    setText("");
    QString colorStyle = "background-color: #eb86dd;";
    setStyleSheet(QString("QPushButton {%1}").arg(colorStyle));
}

void Tile::set_number(short number)
{
    _number = number;
    setText(QString::number(_number));
    QFont font = this->font();
    font.setBold(true);
    font.setPointSize(16);
    setFont(font);
}

void Tile::set_index(short index)
{
    _ind = index;
}

short Tile::get_number()
{
    return _number;
}

short Tile::get_index()
{
    return _ind;
}
