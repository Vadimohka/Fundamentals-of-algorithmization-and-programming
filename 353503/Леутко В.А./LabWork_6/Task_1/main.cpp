#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    QPalette m_pal;
    m_pal.setColor(QPalette::Active,QPalette::Window,QColor(62, 66, 68));
    w.setPalette(m_pal);
    w.show();
    return a.exec();
}
