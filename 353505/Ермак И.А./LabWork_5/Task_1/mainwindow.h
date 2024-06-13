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

public:    MainWindow(QWidget *parent = nullptr);
public:    ~MainWindow();
public:    QVector<QVector<QString>> getBelarusianKeyboard();
public:    QVector<QVector<QString>> getGermanKeyboard();
public:    QVector<QVector<QString>> getFrenchKeyboard();
public:    QVector<QVector<QString>> getEnglishKeyboard();
public:    QVector<QVector<QString>> getChinesseKeyboard();
public:    QVector<QVector<QString>> getArabicKeyboard();
public:    QVector<QVector<QString>> getHebrewKeyboard();
public:    void setSettings();
public:    void setNewKeyboard();
public:    void setNewBoard();
public:    void setPopularWords();
public:    void generateText();
public:    void highlightCharacter(int index, const QColor &color);
public:    void changeColorOfText(const QColor &color);
public:    void checkIsCorrectSymbol(QString ch);
public:    void keyPressEvent(QKeyEvent *event);
public:    void keyReleaseEvent(QKeyEvent *event);
public:    void SetStyleSheet();
private slots:    void startTimer();
private slots:    void stopTimer();
private slots:    void updateLCD();
private slots:    void changeKeyboard(int index);
private slots:    void on_openFile_clicked();
private slots:    void on_checkBox_stateChanged(int arg1);

private:    Ui::MainWindow *ui;
private:    QTimer *timer;
private:    QString string = "";
private:    QString oldStr = "";
private:    qint64 startTime = 0;
private:    bool timerOn = false;
private:    bool onCaps = false;
private:    bool onShift = false;
private:    bool onSpace = false;
private:    short indexOfLanguage = 0;
private:    int indexOfText = -1;
private:    int countAllSymbol = -1;
private:    int countCorrectSymbol = -1;
private:    QVector<QVector<QString>> popularWords;
private:    QVector<QVector<QString>> currKeyboard;

};
#endif // MAINWINDOW_H
