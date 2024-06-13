#ifndef TASK2_H
#define TASK2_H

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QObject>
#include <QMessageBox>

class Task2 : public QObject
{
    Q_OBJECT
public:
    Task2(QObject *parent = nullptr);
    int ackerman(int m, int n);

    void startDialog();

private:
    QLineEdit lineN, lineM, lineResult;
    QLabel labelN, labelM, labelResult;
    QPushButton setupInfo;
    QDialog dialog;

    void calcResult();
};

#endif // TASK2_H
