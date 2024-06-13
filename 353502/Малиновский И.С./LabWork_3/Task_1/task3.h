#ifndef TASK3_H
#define TASK3_H

#include <QObject>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>

class Task3 : public QObject
{
    Q_OBJECT
public:
    Task3(QObject *parent = nullptr);
    int reverse(int x, int &step);

    void startDialog();

private:
    QLabel labelX, labelResult;
    QLineEdit lineX, lineResult;
    QPushButton setupInfo;
    QDialog dialog;

    void calcResult();
};

#endif // TASK3_H
