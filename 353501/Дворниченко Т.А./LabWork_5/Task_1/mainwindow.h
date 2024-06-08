#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QFile>
#include <QDebug>
#include<QDateTime>
#include <QFileDialog>
#include <QTimer>

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
    QVector<QPushButton*> getButtons();
    void setNewKeyBoard();
    QVector<QVector<QString>> getGermanKeyboard();
    QVector<QVector<QString>> getFranchKeyboard();
    QVector<QVector<QString>> getArabicKeyboard();
    QVector<QVector<QString>> getEnglishKeyboard();
    QVector<QVector<QString>> getBelarussianKeyboard();
    QVector<QVector<QString>> getHerbewKeyboard();
    QVector<QVector<QString>> getChinaseKeyboard();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void changeColorAtIndex(int index, const QString& color);
    void checkIsCorrectSymbol(QString ch);
    void setupPopularWords();
    void generateText();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_bnt_start_clicked();

    void on_bnt_end_clicked();
    void startTimer();
    void stopTimer();
    void updateLCD();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    qint64 startTime;
    bool currCaps = false;
    bool currShift = false;
    int indexOfLanguage = 0;
    int currIndOfText = -1;
    int cntAllStmbol = -1;
    int cntCorrectSymbol = -1;
    QString currString = "";
    QString oldStr = "";
    bool isActiveTrain = false;
    QVector<QVector<QString>> currKeyboard;
    QVector<QVector<QString>> popularWords;
};
#endif // MAINWINDOW_H
