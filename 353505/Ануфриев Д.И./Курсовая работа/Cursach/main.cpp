#include "dialogs/dialogchoosinggamestart.h"
#include "mainmenu.h"
#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainMenu menu;
    DialogChoosingGameStart chooseOfGameStart;

    QMediaPlayer *player = new QMediaPlayer();
    QAudioOutput *output = new QAudioOutput();


    player->setAudioOutput(output);
    output->setVolume(0.5);


    QScreen *screen =QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height1 = screenGeometry.height();
    int width1 = screenGeometry.width();

    // w.resize(width1 / 2.0, height1 / 2.0);
    // menu.resize(width1 / 2.0, height1 / 2.0);
    // chooseOfGameStart.resize(width1 / 2.0 ,height1 / 2.0);

    w.resize(width1, height1);
    menu.resize(width1, height1);
    chooseOfGameStart.resize(width1, height1);

    menu.show();

    QObject::connect(&menu, &MainMenu::play, [&w, &menu, &chooseOfGameStart, &player](){

        QFile file("../../files/save.txt");
        if (file.size() != 0)
        {
            chooseOfGameStart.showNormal();
            QObject::connect(&chooseOfGameStart, &DialogChoosingGameStart::continueGame, [&player, &w, &chooseOfGameStart](){
                player->setSource(QUrl::fromLocalFile("../../media/continueGame.mp3"));
                player->play();

                w.loadGameFromFile();
                w.show();

                QTimer::singleShot(500, &chooseOfGameStart, &DialogChoosingGameStart::hide);

            });

            QObject::connect(&chooseOfGameStart, &DialogChoosingGameStart::restartGame, [&player, &w, &chooseOfGameStart](){
                player->setSource(QUrl::fromLocalFile("../../media/newGame.mp3"));
                player->play();

                w.startNewGame();
                w.showNormal();

                QTimer::singleShot(500, &chooseOfGameStart, &DialogChoosingGameStart::hide);
            });
        }
        else
        {
            w.startNewGame();
            w.showNormal();
        }
        file.close();

        QTimer::singleShot(500, &menu, &MainMenu::hide);
    });

    QObject::connect(&w, &MainWindow::exit, [&w, &menu](){
        menu.showNormal();
        QTimer::singleShot(500, &w, &MainWindow::hide);

    });

    return a.exec();
}
