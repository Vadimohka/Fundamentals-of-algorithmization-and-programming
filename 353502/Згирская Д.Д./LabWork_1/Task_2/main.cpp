#include "filefunctions.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileFunctions w;
    w.show();
    return a.exec();
}
