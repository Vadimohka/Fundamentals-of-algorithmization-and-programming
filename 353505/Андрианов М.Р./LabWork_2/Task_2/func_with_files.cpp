#include "func_with_files.h"

QString func_with_files::openfile(){
    QString filep=QFileDialog::getOpenFileName(nullptr,"Open file","","Text files (*.txt)");
    return filep;
}
QString func_with_files::readFromFile(QString c,int sch){
    QFile file=(c);
    file.open(QIODevice::ReadWrite);
    QTextStream l(&file);
    for(int i=0;i<sch;++i){
        l.readLine();
    }
    return l.readLine();
}
bool func_with_files::check(QString c,int sch){
    QFile file=(c);
    file.open(QIODevice::ReadWrite);
    QTextStream l(&file);
    for(int i=0;i<sch;++i){
        l.readLine();
    }
    if(l.atEnd()) return false;
    else return true;
}
bool func_with_files::check_str(QString s){
    sch1=1;
    fl=0;
    if(s.length()==10){
        while(sch1<11){
            if((s[sch1-1]<'0' || s[sch1-1]>'9') && sch1-1!=2 && sch1-1!=5){
                fl=1;
            }
            if((sch1-1==2 ||  sch1-1== 5) && s[sch1-1]!='.'){
                fl=1;
            }
            sch1++;
        }
        if(!fl){
            year=s[6].digitValue()*1000+s[7].digitValue()*100+s[8].digitValue()*10+s[9].digitValue();
            if(s[0].digitValue()*10+s[1].digitValue()>0 && s[0].digitValue()*10+s[1].digitValue()<32 && s[3].digitValue()*10+s[4].digitValue()<13 && s[3].digitValue()*10+s[4].digitValue()>0){
                if(year>0 && year<10000){

                    if(s[3].digitValue()*10+s[4].digitValue()==4 || s[3].digitValue()*10+s[4].digitValue()==6 || s[3].digitValue()*10+s[4].digitValue()==9 || s[3].digitValue()*10+s[4].digitValue()==11){
                        if(s[0].digitValue()*10+s[1].digitValue()<=30){
                            return true;
                        }
                        else return false;
                    }
                    else if(s[3].digitValue()*10+s[4].digitValue()==2 && year%400==0 || (year%4==0 && year%100!=0)  ){
                        if(s[0].digitValue()*10+s[1].digitValue()<=29) return true;
                        else return false;
                    }
                    else if(s[3].digitValue()*10+s[4].digitValue()==2){
                        if(s[0].digitValue()*10+s[1].digitValue()<=28) return true;
                        else return false;
                    }
                    else return true;


                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false ;
}
void func_with_files::writeIntoFile(QString c,QString k){
    QFile file=(c);
    file.open(QIODevice::ReadWrite);
    QTextStream l(&file);
    while(!l.atEnd()){
        l.readLine();
    }
    file.seek(l.pos());

    l << k << Qt::endl;
}
