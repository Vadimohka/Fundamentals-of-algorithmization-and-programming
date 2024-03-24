#include "mainwindow.h"
#include "move_rec.h"
#include <QApplication>
#include <QtMultimedia>


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWindow w;

    QMediaPlaylist *list = new QMediaPlaylist();
    list->addMedia(QUrl::fromLocalFile("/home/skibidi-dop/Downloads/ost-soldaty--zdravstvuy-nebo-v-oblakah.mp3"));
    list->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *player = new QMediaPlayer;
    player->setPlaylist(list);
    player->play();

    w.show();
    return app.exec();
}
