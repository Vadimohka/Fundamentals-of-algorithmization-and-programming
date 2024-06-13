#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QTimer>
#include <QComboBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *timeLabel;
    QLabel *accuracyLabel;
    QLineEdit *inputField;
    QTimer *timer;
    QComboBox *languageComboBox;

private slots:
    void updateTimeAndAccuracy();
    void addKeyToInputField();
    void changeLanguage(int index);
};

#endif // MAINWINDOW_H
