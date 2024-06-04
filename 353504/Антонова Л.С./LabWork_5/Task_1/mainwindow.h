#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QFileDialog>

#include <QKeyEvent>
#include <QRandomGenerator>

#include <QTextDocument>
#include <QTextCursor>

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

    QVector<QVector<QString>> getBelarusianKeyboard();
    QVector<QVector<QString>> getGermanKeyboard();
    QVector<QVector<QString>> getFrenchKeyboard();
    QVector<QVector<QString>> getEnglishKeyboard();
    QVector<QVector<QString>> getChinesseKeyboard();
    QVector<QVector<QString>> getArabicKeyboard();
    QVector<QVector<QString>> getHebrewKeyboard();

    void setNewKeyboard();
    void setNewBoard();
    void setupPopularWords();
    void generateText();

    // void highlightCharacter(int index, const QColor &color);
    void changeColorOfText(const QColor &color);
    void checkIsCorrectSymbol(QString ch);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void startTimer();
    void stopTimer();
    void updateLCD();
    void changeKeyboard(int index);

    void on_openFile_clicked();
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    QTimer *timer;
    qint64 startTime;
    bool isTimerActiv = false;

    short indexOfLanguage = 0;
    QVector<QVector<QString>> currKeyboard;

    bool currCaps = false;
    bool currShift = false;
    bool currSpace = false;

    QString currString = "";

    int currIndOfText = -1;
    int cntAllSmb = -1;
    int cntCorrectSymbol = -1;

    QString oldStr = "";
    QVector<QVector<QString>> popularWords;
};
#endif // MAINWINDOW_H
