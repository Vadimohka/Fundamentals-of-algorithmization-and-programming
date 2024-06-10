#include "widget.h"

#include <QApplication>
#include <QFileDialog>
#include <QDebug>

#include "NumberOfFiles.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

