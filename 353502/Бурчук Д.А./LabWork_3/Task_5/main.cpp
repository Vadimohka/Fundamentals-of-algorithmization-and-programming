#include <QApplication>
#include <QFileDialog>
#include <QDebug>

#include "FileCounter.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QString path = QFileDialog::getExistingDirectory(nullptr, "Open Files", "../Files",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QDir dir;
    dir.setPath(path);
    dir.setFilter( QDir::AllEntries | QDir::NoDotAndDotDot );
    qDebug() << dir.count();
    qDebug() << "Number of files = " << FileCounter::countFiles(path).first <<"Number of dir = " <<  FileCounter::countFiles(path).second;
    return 0;
}
