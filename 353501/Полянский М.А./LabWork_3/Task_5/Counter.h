#include <QString>
#include <QDir>

class Counter 
{
public:
    static void CounterAll(QString path);
    static void Reset();
    static int GetFolders();
    static int GetFiles();
    static void IncreaseFolder();
    static void IncreaseFiles();
private:
    static int Folders;
    static int Files;

};