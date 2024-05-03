#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <person.h>

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


private:
    Ui::MainWindow *ui;
    QString pathToFile;
    bool firstAdd=true;
    QFile file;
     QVector<int>m_inds;
    QVector<int>w_inds;
     QVector<int>inds;
    QVector<Person>men;
    QVector<Person>women;
    QVector<std::pair<Person, Person>> pairs;
public slots:
    void putDataFromFileToTable();
    void addPerson(QString s, bool add);
    void loadTable(Person, bool);
    void checkF();
    void checkS();
    void addToFile();
    void setLimit(int);
      void setLimit2(int);
    void openAndCheck();
      void removeBlock();
    void deleteFromTable(int);
      void changeBlock(QString);
    void sortTables();

      void fillMatches();

    void createPairs(bool);
};
#endif // MAINWINDOW_H
