#include "download_nv.h"


void Download_nv::Hide(QVector <QPushButton*>b,QVector<QCheckBox*>a,std::vector<double> st_info){
    for(int i=0;i<28;++i)
    {
        a[i]->setChecked(false);
    }
    for(int i=0;i<6;++i)
    {
        b[i]->setVisible(false);
    }
    QFile file("../../logs.txt");
    QTextStream out(&file);
    QString tmp;
    file.open(QIODevice::ReadOnly);
    while(!out.atEnd())
    {
        tmp = out.readLine();
    }
    file.close();
    QMessageBox::information(nullptr,"Загрузка","Вы выбрали режим загрузки 2.0. Выберете программу,которую хотите установить");
    QStorageInfo storageInfo("/");
    qint64 bytes = storageInfo.bytesAvailable();
    double mbytes = bytes / (1024.0 * 1024.0);
    if(mbytes<5000 && mbytes>100)
    {
        QMessageBox::information(nullptr,"Внимание","На вашем диске осталось меньше 5 гб. Вам будут предложены только определенные приложения");
        std::vector <double> tmp=st_info;
        std::sort(tmp.begin(),tmp.end());
        for(size_t i=0;i<tmp.size();++i)
        {
            for(size_t j=0;j<st_info.size();++j)
            {
                if(mbytes>1000){
                if(tmp[i]==st_info[j])
                    {
                    a[j]->setVisible(true);
                    a[j]->setEnabled(true);
                    mbytes-=st_info[i];

                }
                }
            }
        }
    }
    else if (mbytes>5000){
    for(int i=0;i<28;++i)
    {

        a[i]->setVisible(true);
        a[i]->setEnabled(true);



    }
      b[5]->setVisible(true);
    b[5]->setText("Установить");
    }
    else {
        QMessageBox::information(nullptr,"Внимание","На вашем диске слишком мало места!");
    }


}
std::string Download_nv::process(int i)
{
    int k=0;
    Encryption rc4;
    std::string ss1;
    QFile file ("../../decrypt_downloadv2.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(k==i)
        {
            ss1= rc4.RC4(line.toStdWString());
            break;
        }
        k++;
    }
    return ss1;
}
