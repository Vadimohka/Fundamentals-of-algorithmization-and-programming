#ifndef FILES_H
#define FILES_H

#include <QCoreApplication>
#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <QStringList>
#include <QTextBrowser>
#include <QTextStream>
#include <fstream>

class Files
{
public:
    QString inputText;

    const QStringList files = {"GruganovLab6.txt",
                               "GruganovLab6_0.txt",
                               "GruganovLab6_1.txt",
                               "GruganovLab6_2.bin",
                               "GruganovLab6_3.txt"};

    void CreateNonExistingFiles();

    void SaveTextToFile(const QString &);
    void LoadTextFromFile(const QString &);

    void SaveArrayToFile(const QString &);
    void LoadArrayFromFile(const QString &);

    void SaveStructToFile(const QString &);
    void LoadStructsFromFile(const QString &);

    void SaveStructToBinaryFile(const QString &);
    void LoadStructsFromBinaryFile(const QString &);

    void SaveSentenceToFile(const QString &);
    void LoadSentencesFromFile(const QString &);

    Files(QTextBrowser *browser);

private:
    QString path = "/home/kostyanych2005/Qt/Labs/Lab 6/build-Task_2-Desktop-Debug";
    QTextBrowser *output;
    QTextStream outputStream;
    QString outputText;
};

#endif // FILES_H
