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
    void startHanoi();

private:
    void hanoi(int n, int source, int auxiliary, int destination, QString& moves);

    QString moves;
    QSpinBox *numDiscsSpinBox;
    QPushButton *startButton;
    QTextEdit *movesTextEdit;
};

#endif // MAINWINDOW_H
