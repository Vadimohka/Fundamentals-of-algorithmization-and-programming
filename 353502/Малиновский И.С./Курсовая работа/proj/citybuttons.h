#ifndef CITYBUTTONS_H
#define CITYBUTTONS_H

#include <QWidget>
#include <QVector>
#include <QSize>
#include <QDebug>
#include <QDir>

#include "circularbutton.h"
#include "cityinfowidget.h"

const QString dirP = "/home/ilyamzy/proj/courseWork/Pictures/";
const QString dirT = "/home/ilyamzy/proj/courseWork/Texts/";

class CityButtons : public QWidget {
    Q_OBJECT

public:
    CityButtons(QWidget *parent = nullptr);

    void createButtonsAndWidgets(const QString &fileName, QWidget *parent = nullptr);
    void setWindowSize(QSize size);
    void handleResizeEvent(const QSize &newSize);
    void showInfoWidget(int ind);
    QVector<CityInfoWidget>* getWidgets();
    QHash<QString, int>* getHashMap();

private:
    QVector<double> xCord, yCord, widthButton, heightButton;
    QVector<CircularButton*> buttons;
    QVector<QString> nameCities;
    QVector<CityInfoWidget> infoWidgets;
    QHash<QString, int> hashMap;
    QSize windowSize;

    void createButtons(QWidget *parent);
    void createInfoWidgets();
};

#endif // CITYBUTTONS_H
