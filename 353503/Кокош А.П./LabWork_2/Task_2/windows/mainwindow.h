#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtWidgets>
#include "../MyClass/myclass.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    //File
    QFile myFile;

    //PathToFile
    QString pathToFile;

    MyClass **players;

    int numOfPlayers = 0;

    QPushButton *openFileButton = new QPushButton("Open");
    QPushButton *closeButton = new QPushButton("Close");
    QPushButton *addButton = new QPushButton("Add");
    QPushButton *editButton = new QPushButton("Edit/Delete");
    QPushButton *sortButton = new QPushButton("Sort");
    QPushButton *saveToFileButton = new QPushButton("Save");
};
#endif // MAINWINDOW_H
