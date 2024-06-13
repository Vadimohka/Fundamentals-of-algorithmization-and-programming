#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QShortcut>
#include <QMap>
#include <QPushButton>
#include <QTimer>
#include <QFile>
#include <QFileDialog>
#include <QStringList>
#include <QTime>
//#include <QX11Info>
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

    std::map<QChar, QPushButton*>but;

    void fillButMap();

    QVector<QStringList>HoleText;

    QStringList textForTyping;

    QString currentWord;

    QChar lastClickedLetter = QChar(255);

    QString lastStyleSheet;

    void readFromFile(QString filename);

    const QString filename = "/home/lidskae/Lab5_Klava/English_Texts/text.txt";

    int currentWordInd = 0;

    void goToNextWord();

    void goToNextLine();

    void fillTextEdit(int line = 0, int i = 0);

    int currentLine = 0;

    bool typingIsCorrect = true;

    void setTypingIsCorrect(bool);

    void buttonClicked(QChar);

    bool shift = false;

    void goBack();

    QStringList avaliableLanguages{"English",
                                 "Русский"};

    int wordCount = 0;

    int sec;

    QTimer timer;
private slots:

    void setCurrentWordFromEdit();

    void setShiftModiferState();

    void on_openFile_clicked();

    void changeLanguage();

    void calcSpeed();

    void slotTimeout();
};
#endif // MAINWINDOW_H
