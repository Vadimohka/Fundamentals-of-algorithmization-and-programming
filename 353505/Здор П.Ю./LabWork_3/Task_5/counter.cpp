#include "counter.h"

void counter::count(QString path,int &count1,int &count2) {
    QDir dir=(path);
    if(!dir.exists()) return;
    else {
        QStringList pth=dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        for(int i=0;i<dir.count();++i){
            count1++;
        }
        for(const QString& subdirectory: pth){
            count(path+"/"+subdirectory,count1,count2);
        }
        QStringList files=dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
        for(int i=0;i<files.count();++i){
        count2+=files[i].length();
        }
    }

}
