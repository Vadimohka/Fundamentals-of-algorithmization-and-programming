#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    QPalette m_pal;
    m_pal.setColor(QPalette::Active,QPalette::Window,QColor("#283655"));
    m_pal.setColor(QPalette::Active,QPalette::WindowText,QColor("#D0E1F9"));
    m_pal.setColor(QPalette::Active,QPalette::Base,QColor("#1E1F26"));
    m_pal.setColor(QPalette::Active,QPalette::Text,QColor("#D0E1F9"));
    m_pal.setColor(QPalette::Active,QPalette::Button,QColor("#4D648D"));
    m_pal.setColor(QPalette::Active,QPalette::ButtonText,QColor("#283655"));
    w.setPalette(m_pal);
    w.show();
    return a.exec();
}
