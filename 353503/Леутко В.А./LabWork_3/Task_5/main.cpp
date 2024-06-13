#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    QPalette m_pal;
    m_pal.setColor(QPalette::Active,QPalette::Window,QColor::fromRgb(230, 230, 230));
    //m_pal.setColor(QPalette::Active,QPalette::Base,QColor::fromRgb(242, 242, 242));
    m_pal.setColor(QPalette::Active,QPalette::Button,QColor::fromRgb(204, 204, 255));
    m_pal.setColor(QPalette::Active,QPalette::ButtonText,QColor::fromRgb(0, 0, 0));
    //m_pal.setColor(QPalette::Active,QPalette::WindowText,QColor::fromRgb(0, 0, 0));
    w.setPalette(m_pal);
    w.show();
    return a.exec();
}
