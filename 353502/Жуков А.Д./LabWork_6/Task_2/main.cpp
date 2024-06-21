#include "mainwindow.h"
#include <QTextCodec>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    w.show();
    return a.exec();
}
