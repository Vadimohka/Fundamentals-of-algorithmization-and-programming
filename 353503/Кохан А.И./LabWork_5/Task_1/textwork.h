#ifndef TEXTWORK_H
#define TEXTWORK_H

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QString>
#include <QTextStream>
#include <QVector>
#include "ui_mainwindow.h"

class TextWork : public QObject
{
    Q_OBJECT
public:
    TextWork(QVector<QString> *, QVector<QString> *, Ui::MainWindow *);

    void GenerateText();
    void AddTextToProgressLine();
    void SetDictionary(int);

private:
    QVector<QString> *dictionary;
    QVector<QString> *tranningText;
    Ui::MainWindow *ui;
};

#endif // TEXTWORK_H
