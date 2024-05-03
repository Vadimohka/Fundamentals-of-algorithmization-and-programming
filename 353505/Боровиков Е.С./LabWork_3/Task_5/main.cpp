#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FolderBrowser *folderBrowser = new FolderBrowser;
    folderBrowser->showFullScreen();
    return a.exec();
}
