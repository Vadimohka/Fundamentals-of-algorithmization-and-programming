#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString projDir;
    bool fromFile = false;
    QDate currData;

    void hideAll();
    void showAll();


private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    Date date;
    QString pathToFile;
    QFile file;
    bool first = true;


public slots:
    void resPrev();
    void resLeap();
    void resDiff();

    void addButton();
    void deleteButton();
    void changeButton();

    void setDiff(int);
    void setNext(int);

    void openFile();
    void putDataFromFileToTable();

    void addToFile(QString);

    void addFromFile();
    void deleteFromFile(int);
    void changeFromFile(int);
};
#endif // MAINWINDOW_H
