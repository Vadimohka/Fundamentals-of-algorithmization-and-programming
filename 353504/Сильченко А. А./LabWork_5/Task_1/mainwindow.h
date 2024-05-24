#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "keyboard.h"
#include "input.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QTextCharFormat>
#include <QFont>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    Keyboard* _keyboard;
    Input* _analizer;
    Language _languge = Bel;
    QString _text;
    int _charCntr;
    QTextCharFormat _redF;
    QTextCharFormat _greenF;
    QTextCharFormat _blackF;
    std::array<QString, 6> _presets;
    bool _isReadOnly = false;

    void presets();

public:
    int bimage=0;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    bool isReadOnly() const;
    void setReadOnly(bool newStatus);

public slots:
    void slotChangeLang(int newLangIndex);
    void slotStartCheck();
    void slotFinishCheck();
    void slotUpdateInfo();
    void slotOpenFile();
    void slotColorText(QChar newChar);
    void slotInsertPreset();
    void on_pushAlarm_clicked();
};
#endif // MAINWINDOW_H
