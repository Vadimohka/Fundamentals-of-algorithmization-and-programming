#include <QApplication>
#include <t2win.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T2Win w;
    w.show();
    return a.exec();
}
