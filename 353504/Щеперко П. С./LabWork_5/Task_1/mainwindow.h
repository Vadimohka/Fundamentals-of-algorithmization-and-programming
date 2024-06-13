#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "keys.h"
#include "validator.h"

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
    VirtualKeyboard* _keyboard;
    InputAnalizer* _analizer;
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
};
#endif // MAINWINDOW_H
