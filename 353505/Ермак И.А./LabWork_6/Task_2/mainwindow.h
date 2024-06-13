#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>
#include <QIODevice>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void enterParagraph();
    void readParagraph();
    void saveArray();
    void readArray();
    void saveStructToText();
    void readStructFromText();
    void saveStructToBinary();
    void readStructFromBinary();
    void saveSentence();
    void readSentences();
    void exitApplication();

private:
    Ui::MainWindow *ui;
    struct Movie {
        int id;
        double rating;
        char genre;
        bool isAvailable;
        static const int TITLE_SIZE = 100;
        static const int NUM_ARRAY_SIZE = 10;
        char title[TITLE_SIZE];
        static int ratings[NUM_ARRAY_SIZE];
    };
};

#endif // MAINWINDOW_H
