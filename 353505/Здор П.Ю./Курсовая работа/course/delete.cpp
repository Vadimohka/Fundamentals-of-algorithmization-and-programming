#include "delete.h"


void Delete::Hide(QVector <QPushButton*> b,QVector<QCheckBox*>a){
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
    QMessageBox::information(nullptr,"Удаление","Вы выбрали режим удаления. Выберете программу,которую хотите удалить");
    for(int i=0;i<28;++i)
    {   if(tmp[i]=='1'){
        a[i]->setVisible(true);
        a[i]->setEnabled(true);
        }


    }
    b[5]->setVisible(true);
    b[5]->setText("Удалить");

}
std::string Delete::process(int i)
{
    int k=0;
    Encryption vig;
    std::string ss1;
    QFile file ("../../decrypt_uninstall.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(k==i){
        ss1=line.toStdString();
        vig.Vigener_cypher(ss1);
        break;
        }
        k++;
    }
    return ss1;
}
