#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTimer>
#include <QTextStream>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QString>
#include <QTextDocument>

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

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    void startTraining();

    void endTraining();

    void changeColorAtIndex(int index, const QString& color);

    bool checkIsCorrectSymbol(QString ch);

    void setNewKeyBoard();

    QVector<QVector<QString>> getGermanKeyboard();

    QVector<QVector<QString>> getFranchKeyboard();

    QVector<QVector<QString>> getArabicKeyboard();

    QVector<QVector<QString>> getEnglishKeyboard();

    QVector<QVector<QString>> getBelarussianKeyboard();

    QVector<QVector<QString>> getHerbewKeyboard();

    QVector<QVector<QString>> getchineseKeyboard();


private slots:

    void on_comboBox_activated(int index);

private:
    QString TrainingText;

    Ui::MainWindow *ui;

    QTimer *timer;

    double startTime;

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
