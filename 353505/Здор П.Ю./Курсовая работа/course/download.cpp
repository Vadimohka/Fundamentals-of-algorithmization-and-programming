#include "download.h"

void Download::Hide(QVector <QPushButton*> b,QVector<QCheckBox*>a){
    for(int i=0;i<28;++i)
    {
        a[i]->setChecked(false);
    }
    for(int i=0;i<6;++i)
    {
        b[i]->setVisible(false);
    }

    QMessageBox::information(nullptr,"Загрузка","Вы выбрали режим обычной загрузки. Выберете программу,которую хотите установить");
    for(int i=0;i<28;++i)
    {
        a[i]->setVisible(true);
        a[i]->setEnabled(true);



    }
      b[5]->setVisible(true);
    b[5]->setText("Установить");

}
std::string Download::process(int i)
{
    int k=0;
    Encryption rsa;
    std::string ss1;
    QFile file ("../../decrypt_for_download.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        if(k==i)
        {
            ss1= rsa.RSA(line.toStdWString());
            break;
        }
        k++;
    }
    return ss1;
}
void Download::downloading(std::string arg)
{
    QProcess process;
    QString program = "powershell.exe";
    QStringList arguments;
    arguments  << "-Command" << "Start-Process powershell -Verb runAs -ArgumentList '" << QString::fromStdString(arg)+"'";  ;

    process.start(program, arguments);

}
