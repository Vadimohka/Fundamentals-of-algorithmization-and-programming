
#include "update.h"
std::string Update::process()
{
    Encryption hill;
    std::string ss1;
    QFile file ("../../decrypt_upgrade.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        std::string ss1=line.toStdString();
        hill.Hill_cipher(ss1);
    }
    return ss1;
}
