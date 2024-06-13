#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QFile stylesFile(QDir::current().filePath("resources/styles.qss"));
    stylesFile.open(QIODevice::ReadOnly);
    QString style(stylesFile.readAll());
    a.setStyleSheet(style);
    w.show();
    return a.exec();
}
