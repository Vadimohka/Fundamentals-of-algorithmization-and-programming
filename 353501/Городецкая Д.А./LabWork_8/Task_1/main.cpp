#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPalette palette = a.palette();
    // Установка цвета фона на розовый
    palette.setColor(QPalette::Window, QColorConstants::Svg::greenyellow);

    // Установка цвета текста на синий
    palette.setColor(QPalette::WindowText, QColorConstants::Svg::black);

    // Установка обновленной палитры приложения
    a.setPalette(palette);
    w.show();
    return a.exec();
}
