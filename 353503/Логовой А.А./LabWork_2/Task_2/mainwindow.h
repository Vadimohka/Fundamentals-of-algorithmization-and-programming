#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <footballer.h>
#include <QMainWindow>
#include <QLineEdit>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QTableWidget>
#include <QGridLayout>
#include <QStringList>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QValidator>
#include <QRegularExpressionValidator>
#include <QTextEdit>
#include <QHeaderView>
#include <InsertionSort.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QVector <Footballer* > player;

    QTableWidget* table;

    QTextEdit* info_display;

    QStringList headers;

    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QPushButton* button4;
    QPushButton* button5;
    QPushButton* button6;
    QPushButton* button7;

    QLineEdit* name_line;
    QLineEdit* club_line;
    QLineEdit* positition_line;
    QLineEdit* goals_line;
    QLineEdit* penalty_line;

    QString fileName;

    QIntValidator* intValidator;

    void displayInformation(short row, short column);

    void saveInformation();

    void openFile();

    void createFile();

    void closeFile();

    void writeToFile(Footballer* player);

    void sortFootballer(bool (*compare)(Footballer*, Footballer*));

    void showTopScorers();

    void showTopPenalties();

    void showBestPlayers();

    void updateTable();

    bool checkInput();


};
#endif // MAINWINDOW_H
