#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    w.move(1000,100);
    QPalette m_pal;
    m_pal.setColor(QPalette::Active,QPalette::Window, QColor(40,40,40));

    m_pal.setColor(QPalette::Active, QPalette::Base, QColor(40,40,40));
    m_pal.setColor(QPalette::Active,QPalette::Button, QColor("#FFA500"));
    m_pal.setColor(QPalette::Active,QPalette::ButtonText, QColor(255, 255, 255));
    w.setPalette(m_pal);
    w.show();
    return a.exec();
}
