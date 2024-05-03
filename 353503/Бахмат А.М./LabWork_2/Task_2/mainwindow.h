#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QtWidgets>
#include <QPair>
#include "human.h"
#include <QFont>

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

private slots:
    void on_openFile_clicked();

    void on_addButton_clicked();

    void addHuman();

    void on_editButton_clicked();

    void editHuman();

    void on_sortButton_clicked();

    void on_findButton_clicked();

    void match();

private:
    QWidget* window1 = new QWidget();
    QWidget* window2 = new QWidget();
    QWidget* windowMatches = new QWidget();
    QRadioButton* femaleRadioBitton1 = new QRadioButton();
    QRadioButton* maleRadioBitton1 = new QRadioButton();
    QLineEdit* idLine1 = new QLineEdit();
    QLineEdit* nameLine1 = new QLineEdit();
    QLineEdit* ageLine1 = new QLineEdit();
    QLineEdit* heightLine1 = new QLineEdit();
    QLineEdit* weightLine1 = new QLineEdit();
    QLineEdit* habitsLine1 = new QLineEdit();
    QLineEdit* hobbyLine1 = new QLineEdit();
    QLineEdit* minAgeLine1 = new QLineEdit();
    QLineEdit* maxAgeLine1 = new QLineEdit();
    QLineEdit* minHeightLine1 = new QLineEdit();
    QLineEdit* maxHeightLine1 = new QLineEdit();
    QLineEdit* minWeightLine1 = new QLineEdit();
    QLineEdit* maxWeightLine1 = new QLineEdit();
    QPushButton* button1 = new QPushButton("Ok");
    QLineEdit* idLine2 = new QLineEdit();
    QLineEdit* nameLine2 = new QLineEdit();
    QLineEdit* ageLine2 = new QLineEdit();
    QLineEdit* heightLine2 = new QLineEdit();
    QLineEdit* weightLine2 = new QLineEdit();
    QLineEdit* habitsLine2 = new QLineEdit();
    QLineEdit* hobbyLine2 = new QLineEdit();
    QLineEdit* minAgeLine2 = new QLineEdit();
    QLineEdit* maxAgeLine2 = new QLineEdit();
    QLineEdit* minHeightLine2 = new QLineEdit();
    QLineEdit* maxHeightLine2 = new QLineEdit();
    QLineEdit* minWeightLine2 = new QLineEdit();
    QLineEdit* maxWeightLine2 = new QLineEdit();
    QPushButton* button2 = new QPushButton("Ok");
    QTableWidget* tableMatches = new QTableWidget;
    QStringList _headerStr;
    QLabel* labelMatches = new QLabel;
    QSpinBox* spinBoxMatches = new QSpinBox;
    QPushButton* buttonMatches = new QPushButton;
    Ui::MainWindow *ui;
    QString _filePath;
    QFile _file;
    QVBoxLayout* layout1 = new QVBoxLayout;
    QVBoxLayout* layout2 = new QVBoxLayout;
    QVBoxLayout* layoutMatches = new QVBoxLayout;
    int _index;
    bool _isMale;
    char _gender;
    QVector<Human> males, females;
    void readTextFile();
    QString checkAndGetGender(QString);
    void addToVector(QString);
    void editVector(QString, int);
    void updateTable();
    void updateTableMatches();
    QVector<Human> matches;
    QVector<int> candidatsNumber;
    QFont font;
    QFont systemFont;
    QString checkAddAndGetQString();
    QString checkAddAndGetQString2();
};
#endif // MAINWINDOW_H
