#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    if (  (!QFile(":/MediaFiles/high.mp3").exists())
        ||(!QFile(":/MediaFiles/high.mp3").exists()))
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Медиафайлы для метронома не найдены!");
        msgBox.exec();
        return 1;
    }
    return a.exec();
}
