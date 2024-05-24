#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include "chordtransposer.h"
#include "ticker.h"
#include "timer.h"
#include "tuner.h"

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
    void on_fromChordTransposerToMetronomeButton_clicked();

    void on_fromChordTransposerToTunerButton_clicked();

    void on_fromMetronomeToChordTransposerButton_clicked();

    void on_fromMetronomeToTunerButton_clicked();

    void on_fromTunerToChordTransposerButton_clicked();

    void on_fromTunerToMetronomeButton_clicked();

    void on_sortChordsButton_clicked();

    void on_transposeButton_clicked();

    void on_guitarTypeComboBox_currentIndexChanged(int index);

    void on_playButton_clicked();

    void on_guitar6String1RadioButton_clicked();

    void on_guitar6String2RadioButton_clicked();

    void on_guitar6String3RadioButton_clicked();

    void on_guitar6String4RadioButton_clicked();

    void on_guitar6String5RadioButton_clicked();

    void on_guitar6String6RadioButton_clicked();

    void on_guitar7String1RadioButton_clicked();

    void on_guitar7String2RadioButton_clicked();

    void on_guitar7String3RadioButton_clicked();

    void on_guitar7String4RadioButton_clicked();

    void on_guitar7String5RadioButton_clicked();

    void on_guitar7String6RadioButton_clicked();

    void on_guitar7String7RadioButton_clicked();

    void on_ukuleleString1RadioButton_clicked();

    void on_ukuleleString2RadioButton_clicked();

    void on_ukuleleString3RadioButton_clicked();

    void on_ukuleleString4RadioButton_2_clicked();

    void on_bass4String1RadioButton_clicked();

    void on_bass4String2RadioButton_clicked();

    void on_bass4String3RadioButton_clicked();

    void on_bass4String4RadioButton_clicked();

    void on_bass5String1RadioButton_clicked();

    void on_bass5String2RadioButton_clicked();

    void on_bass5String3RadioButton_clicked();

    void on_bass5String4RadioButton_clicked();

    void on_bass5String5RadioButton_clicked();

    void on_searchButton_clicked();

private:
    void closeEvent(QCloseEvent* event) override;
    QString xorEncrypt(QString str);
    void saveSettings();
    void getSettings();
    void setMetronomeConnection();
    void setChordTransposerConnection();
    void setTunerConnection();
    Ui::MainWindow *ui;
    ChordTransposer* transposer;
    Tuner* tuner;
    Ticker* ticker;
    Timer* timer;
    QFile _file;
    QString _key = "КРАКОЗЯБРА";
    QString _settingsStr;
    int stringNumber = 1;
    QStringList chords;
    bool _isGetSettings = true;
};
#endif // MAINWINDOW_H
