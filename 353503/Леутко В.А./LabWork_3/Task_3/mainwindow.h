#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void reverseButtonClicked();
private:
    QLabel *numberLabel;
    QLineEdit *numberLineEdit;
    QPushButton *reverseButton;
    QLabel *reversedLabel;
    QLabel *reversedValueLabel;
};
#endif // MAINWINDOW_H
