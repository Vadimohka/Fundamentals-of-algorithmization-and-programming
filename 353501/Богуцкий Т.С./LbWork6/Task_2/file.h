#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <QStringList>
#include <QFile>
#include <QTextBrowser>
#include <QTextStream>
#include <fstream>
#include <QMessageBox>
#include <QCoreApplication>
#include <QInputDialog>
#include <sportik.h>
#include <dialog.h>

class FileWorker
{
public:
    FileWorker(QTextBrowser*);

    QString inputText;

    const QStringList files = {"BogutskiLab6.txt", "BogutskiLab6_0.txt",
                               "BogutskiLab6_1.txt", "BogutskiLab6_2.bin", "BogutskiLab6_3.txt"};
    void CreateNonExistingFiles();

    void SaveTextToFile(const QString&);
    void LoadTextFromFile(const QString&);

    void SaveArrayToFile(const QString&);
    void LoadArrayFromFile(const QString&);

    void SaveStructToFile(const QString&);
    void LoadStructsFromFile(const QString&);

    void SaveStructToBinaryFile(const QString&);
    void LoadStructsFromBinaryFile(const QString&);

    void SaveSentenceToFile(const QString&);
    void LoadSentencesFromFile(const QString&);
private:
    Sportik a;
    StructInputDialog* structDialog;

    QTextBrowser* output;
    QTextStream outputStream;
    QString outputText;
};

#endif // FILEWORKER_H
