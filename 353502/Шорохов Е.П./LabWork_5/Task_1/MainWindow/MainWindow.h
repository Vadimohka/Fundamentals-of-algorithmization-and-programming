//
// Created by shosh on 5/22/24.
//

#ifndef LABWORK_5_MAINWINDOW_H
#define LABWORK_5_MAINWINDOW_H

#include "QApplication"
#include "QEvent"
#include "QMainWindow"
#include "QTimer"
#include "QKeyEvent"
#include "QLabel"
#include "QGridLayout"
#include "QVector"
#include "QPushButton"
#include "QTextEdit"
#include "QComboBox"
#include "QVBoxLayout"
#include "QFileDialog"
#include "QSizePolicy"
#include "QHBoxLayout"
#include "QDebug"

class MainWindow : public QMainWindow {
    Q_OBJECT
    QComboBox *LanguagesSelector = new QComboBox;
    QPushButton *ChooseTxt = new QPushButton;
    QGridLayout *MainLayout = new QGridLayout;
    QWidget *CentralWidget = new QWidget;
    QTextEdit *ShownTypeScreen = new QTextEdit;
    QTextEdit *MainTypeScreen = new QTextEdit;
    QVector<QPushButton*> keyboardButtons;
    QTimer *GuiRefresh = new QTimer;
    QLabel *TimeElapsed = new QLabel;
    int correct_symbols = 0;
    int all_symbols = 0;
    double words_per_minute = 0;
    QLabel *AccuracyLabel = new QLabel;
    bool is_uppercase = false;
public:
    MainWindow();
    void keyReleaseEvent(QKeyEvent *event) override;
    void setKeyboardToEnglish();
    void setKeyboardToEnglishUppercase();
    void setKeyboardToBelarusian();
    void setKeyboardToFrench();
    void setKeyboardToArabic();
    void setKeyboardToHebrew();
};


#endif //LABWORK_5_MAINWINDOW_H
