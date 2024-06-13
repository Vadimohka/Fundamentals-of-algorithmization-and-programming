#include <QApplication>
#include "QMainWindow"
#include <QPushButton>
#include <QLocale>
#include "MainWindow/MainWindow.h"
#include "map"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QFile stylesFile("/home/shosh/CourseProject/Course project/Styles/styles.qss");
    stylesFile.open(QIODevice::ReadWrite);
    QString style(stylesFile.readAll());
    a.setStyleSheet(style);
    MainWindow *Main = new MainWindow;
    return QApplication::exec();
}
