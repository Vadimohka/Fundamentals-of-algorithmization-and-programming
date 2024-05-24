#include <QApplication>

#include "Headers/Widget.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Widget *firstWindow = new Widget;

#ifdef DEBUG
    firstWindow->showFullScreen();
#else
    firstWindow->show();
#endif
    return QApplication::exec();
}
