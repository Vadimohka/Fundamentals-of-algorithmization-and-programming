#include "citybuttons.h"
#include <QFile>
#include <QTextStream>
#include <QResizeEvent>
#include <cmath>

CityButtons::CityButtons(QWidget *parent)
    : QWidget(parent)
{
}

void CityButtons::createButtonsAndWidgets(const QString &fileName, QWidget *parent) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    int ind=0;
    while (!in.atEnd()) {
        int x, y, r;
        QString text;
        in >> x >> y >> r;
        x -= 3;
        y -= 3;
        in.skipWhiteSpace();
        text = in.readLine();
        xCord.push_back(x);
        yCord.push_back(y);
        widthButton.push_back(2*r);
        heightButton.push_back(2*r);
        nameCities.push_back(text);
        hashMap.insert(text, ind++);
    }
    file.close();

    createInfoWidgets();
    createButtons(parent);
    //connect(buttons[63], &QPushButton::clicked, &infoWidgets[0], &CityInfoWidget::showInfo);
}

void CityButtons::setWindowSize(QSize size)
{
    windowSize = size;
}

void CityButtons::handleResizeEvent(const QSize &newSize)
{
    double wRatio = (double)newSize.width() / windowSize.width(), hRatio = (double)newSize.height() / windowSize.height();

    for (int i = 0; i < xCord.size(); ++i)
    {;
        buttons[i]->move(xCord[i]*wRatio, yCord[i]*hRatio);
        buttons[i]->setEllipseSize(widthButton[i]*wRatio, heightButton[i]*hRatio);
    }

}

void CityButtons::showInfoWidget(int ind)
{
    infoWidgets[ind].showInfo();
}

void CityButtons::createInfoWidgets()
{
    for (auto name:nameCities)
    {
        QString pathDir=dirP + name;
        QDir dir(pathDir);
        QStringList filters;
        filters << "*";
        QFileInfoList fileList = dir.entryInfoList(filters, QDir::Files);
        QStringList fileNameList;
        foreach (QFileInfo fileInfo, fileList) {
            fileNameList.append(dirP + name + "/" + fileInfo.fileName());
        }
        infoWidgets.push_back(CityInfoWidget(dirT + name + ".txt", fileNameList, nullptr));
    }
}

void CityButtons::createButtons(QWidget *parent)
{
    for (int i=0; i<nameCities.size(); i++)
    {
        buttons.push_back(new CircularButton("", widthButton[i], heightButton[i], parent));
        connect(buttons[i], &QPushButton::clicked, &infoWidgets[i], &CityInfoWidget::showInfo);
        buttons[i]->move(xCord[i], yCord[i]);
        buttons[i]->show();
    }
}

QVector<CityInfoWidget>* CityButtons::getWidgets()
{
    return &infoWidgets;
}

QHash<QString, int>* CityButtons::getHashMap()
{
    return &hashMap;
}
