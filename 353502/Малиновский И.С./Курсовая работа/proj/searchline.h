#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCompleter>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMap>
#include "cityinfowidget.h"

class SearchLine : public QLineEdit {
public:
    SearchLine();
    void findNames();
    void setInfoWidgets(QVector<CityInfoWidget>* infoWidgets);

private:
    QVector<QString> names;
    QVector<CityInfoWidget> *infoWidgets;
    QMap<QString, int> indNames;
    QCompleter *completer;
    QStringListModel *model;
    bool isEqual(const QString pref, const QString str);

    void sort();
};
