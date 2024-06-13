#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "keyboard.h"
#include "trainer.h"

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
    Trainer* _trainer;
    Language _languge = Ger;
    QString _text;
    int _charCntr;
    QTextCharFormat _redF;
    QTextCharFormat _greenF;
    QTextCharFormat _blackF;
    std::array<QString, 6> _presets;
    bool _isReadOnly = false;

    void presets();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    bool isReadOnly() const;
    void setReadOnly(bool newStatus);

public slots:
    void ChangeLang(int newLangIndex);
    void StartCheck();
    void FinishCheck();
    void UpdateInfo();
    void OpenFile();
    void ColorText(QChar newChar);
    void InsertPreset();
};
#endif // MAINWINDOW_H
