#include "mainmenu.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/icon"));
    MainWindow mainWin;
    mainWin.setSize();
    mainWin.show();
    return a.exec();
}
