#include <QFile>
#include <QFileDialog>
#include <QString>
#include "Common.h"

using namespace Common;

class TTLoader{
private:
    static const QString defFnames[6];
    static const QString prefix;

  public:  
    static QString loadDefault(Locale loc);
    static QString loadCustom(QString fname);
};