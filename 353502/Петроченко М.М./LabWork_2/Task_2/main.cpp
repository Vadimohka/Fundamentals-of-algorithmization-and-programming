#include <QApplication>
#include <QPushButton>
#include "../headers/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow main_window(nullptr);
    main_window.show();
    return QApplication::exec();
}
