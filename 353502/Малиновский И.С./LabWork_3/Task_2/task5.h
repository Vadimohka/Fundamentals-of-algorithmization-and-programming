#ifndef TASK5_H
#define TASK5_H

#include <QDialog>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QObject>
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>
#include <QDebug>

class Task5 : public QObject
{
    Q_OBJECT
public:
    Task5(QObject *parent = nullptr);

    void startDialog();

private:
    QDialog dialog;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *scrollLayout;

    QString pathFile;
    QVector <QLabel *> labels;

    int countFoldersAndFiles(const QString& path, int& numFolders, int& numFiles);
    bool isDir(QString path);
};

#endif // TASK5_H
