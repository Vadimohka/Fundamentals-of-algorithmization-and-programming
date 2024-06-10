#ifndef CUSTOMTEXTEDIT_H
#define CUSTOMTEXTEDIT_H

#include <QTextEdit>
#include <QKeyEvent>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include "Plant.h"

class CustomTextEdit : public QTextEdit
{
    int n = 0;
    QString action = "nothing";
public:
    CustomTextEdit(QWidget* parent);
    void getTextFromFile(QString filePath);
    void saveArrayToFile(int n);
    void setAction(QString newAction);
    void setN(int a);
    void loadFloatArrayFromFile();
    void loadTextFromBinaryFile(QString filePath);
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // CUSTOMTEXTEDIT_H
