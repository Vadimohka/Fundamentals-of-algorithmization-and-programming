#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onEvaluateButtonClicked();

private:
    QLineEdit *inputLineEdit1;
    QLineEdit *inputLineEdit2;
    QPushButton *evaluateButton;
    QLabel *resultLabel;
};

#endif // MAINWINDOW_H
