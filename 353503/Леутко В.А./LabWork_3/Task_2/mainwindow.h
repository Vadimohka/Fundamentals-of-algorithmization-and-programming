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
    void calculateClicked();

private:
    QLabel *mLabel;
    QLineEdit *mLineEdit;
    QLabel *nLabel;
    QLineEdit *nLineEdit;
    QPushButton *calculateButton;
    QLabel *resultLabel;
    QLabel *resultValueLabel;
};
#endif // MAINWINDOW_H
