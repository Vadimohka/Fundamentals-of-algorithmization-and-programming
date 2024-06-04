#include "messengerwindow.h"
#include "loginwindow.h"

#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MessengerWindow w;
    LoginWindow l;

    QObject::connect(&l, &LoginWindow::userLoggedIn, &w, &MessengerWindow::setupUser);
    QObject::connect(&l, &LoginWindow::openWindow, &w, &MessengerWindow::show);

    l.show();
    return a.exec();
}
