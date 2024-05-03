#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include "ui_mainwindow.h"
#include <QVector>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QRandomGenerator>

class TextManager : public QObject
{
    Q_OBJECT
public:
    TextManager(QVector<QString>*, QVector<QString>*, Ui::MainWindow*);

    void Generate();
    void LoadTest();
    void AddTextToNext();
    void SetDictionary(int);
private:
    QVector<QString> *dictionary;
    QVector<QString> *trainingText;
    Ui::MainWindow *ui;
};

#endif // TEXTMANAGER_H
