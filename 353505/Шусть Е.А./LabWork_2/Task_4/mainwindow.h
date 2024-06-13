#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void calculate();

private:
    QLineEdit* leftOperandLineEdit;
    QComboBox* operationComboBox;
    QLineEdit* rightOperandLineEdit;
    QPushButton* calculateButton;
    QLabel* resultLabel;

    void setupUI();
};

#endif // MAINWINDOW_H
