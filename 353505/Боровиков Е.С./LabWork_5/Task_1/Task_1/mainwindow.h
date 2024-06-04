#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include <QFile>
#include <QFileDialog>
#include <QPushButton>
#include <QMessageBox>
#include <QComboBox>
#include <QRadioButton>
#include <QTime>
#include <QRandomGenerator>
#include <QVector>
#include <QMap>
#include <QGraphicsDropShadowEffect>
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

    QRadioButton* TypeOfTextRadioButton;
    QPushButton* OpenTextButton;
    QComboBox* LanguageComboBox;

    bool isTested = false;
    bool isCaps = false;
    int lengthOfText;
    int RandomOffset;
    int IndexOfAlpha;
    int NumberOfErrors;
    int NumberOfAlphas;
    QString language;
    QString Text;
    QString CopyText;
    QString FileText;
    QStringList Alphas;
    QStringList ChineTranclitAlphas;
    QStringList LowerAlphas;
    QStringList CapsAlphas;
    QStringList ShiftAlphas;
    QString ChineInputString;
    QStringList Caps_ShiftAlphas;

    QVector <QPushButton*> VectorOfButtons;
    QMap <int, int> ButtonsMap;
    QMap <QString, QString> ChinaMap;
    QTime start;
    QTimer* timer;

    void StartTest();
    void EndTest();
    void GenerateText();
    void BelarusianTextGenerate();
    void GermanTextGenerate();
    void FrenchTextGenerate();
    void ChineseTextGenerate();
    void ArabianTextGenerate();
    void HebrewTextGenerate();
    void lengthGenerate();
    int spaceIntervalGenerate();
    QString appendRandomAlpha();
    void ButtonsInisialisation();
    void MapInizialisation(QString FileName);
    void ChangeAlphas(int ind);

private slots:
    void on_OpenTextButton_clicked();
    void on_GenerateTextRadioButton_clicked();
    void on_OpenTextRadioButton_clicked();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *event);

    void on_StartPushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
