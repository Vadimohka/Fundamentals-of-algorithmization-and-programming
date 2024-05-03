#include "TTLoader.h"
#include "Common.h"
#include <exception>
#include <qfiledialog.h>
#include <stdexcept>

const QString TTLoader::defFnames[6] = {"chi", "bel", "ara", "heb", "ger", "fra"};
const QString TTLoader::prefix = "/trainings/";

QString TTLoader::loadDefault(Locale loc) {
    QDir d = QDir::current();
    d.cdUp();
    QString path = d.absolutePath() + prefix;
  switch (loc) {
  case Locale::Belarussian:
    path +=  defFnames[BEL];
    break;
  case Locale::Arabic:
    path += defFnames[ARA];
    break;
  case Locale::French:
    path +=  defFnames[FRA];
    break;
  case Locale::Hebrew:
    path += defFnames[HEB];
    break;
  case Locale::German:
    path +=  defFnames[GER];
    break;
    case Locale::Chinese:
    path += defFnames[CHI];
    break;
default:
    throw new std::invalid_argument("Wrong enum value");
  }


QFile f(path);

  if(!f.open(QFile::ReadOnly)){
    throw std::runtime_error("The default training file is not found. Reinstall the program.");
  } else {
    return f.readAll();
  }
}


QString TTLoader::loadCustom(QString fname){
    QFile f(fname);
    f.open(QFile::ReadOnly);
    return f.readAll();
}
