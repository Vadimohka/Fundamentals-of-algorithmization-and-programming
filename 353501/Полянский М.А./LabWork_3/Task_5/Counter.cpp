#include "Counter.h"

int Counter::Folders = 0;
int Counter::Files = 0;

void Counter::CounterAll(QString path){
    QDir directory(path);
    QFileInfoList fileInfoList = directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for(const auto &fileInfo : fileInfoList){
        if(fileInfo.isSymLink() || fileInfo.isSymbolicLink()){
            continue;
        }
        if(fileInfo.isFile()) {
            Files++;
        } else {
            Folders++;
            CounterAll(fileInfo.filePath());
        }
    }
}

void Counter::Reset(){
    Folders = 0;
    Files = 0;
}

int Counter::GetFolders(){
    return Folders;
}

int Counter::GetFiles(){
    return Files;
}
