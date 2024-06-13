#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QButtonGroup>
#include <QDoubleValidator>
#include <QFile>
#include <QPushButton>
#include <QMainWindow>
#include <QValidator>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include "sport_team.h"

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
    void Menu();

    void on_plainTextEdit_textChanged();

    void on_arraySizeLineEdit_editingFinished();

    void on_arrayElementLineEdit_editingFinished();

    void on_ratingPosLineEdit_editingFinished();

    void on_winPercentageLineEdit_editingFinished();

    void on_divisionLineEdit_editingFinished();

    void on_nameAbbreviationLineEdit_editingFinished();

    void on_playerNumberLineEdit_editingFinished();

    void on_passedToChampionsLeagueLineEdit_editingFinished();

    void on_winPercentageLineEdit_inputRejected();

    void on_winPercentageLineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    ushort spaceNumber;
    ushort playersNumber;

    void EnterWritePrintText();
    void WriteTextToFileAndPrint();
    void PrintText();

    void EnterWritePrintArray();
    void WriteArrayToFileAndPrint();
    void PrintArray();

    void EnterWritePrintSportTeamInfo();
    void WriteSportTeamInfoToFileAndPrint();
    void PrintSportTeamInfo();

    void WriteSportTeamInfoToBinFileAndPrint();
    void PrintBinSportTeamInfo();

    void EnterWritePrintSentence();
    void WriteSentenceToFileAndPrint();
    void PrintSentence();
};
#endif // MAINWINDOW_H
