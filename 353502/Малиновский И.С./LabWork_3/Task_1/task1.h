#ifndef TASK1_H
#define TASK1_H

#include <QObject>
#include <QLabel>
#include <QVBoxLayout>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class Task1 : public QObject
{
    Q_OBJECT
public:
    Task1(QObject *parent = nullptr);

    QString conversion(int x);

    void startDialog();

private:
    QLabel labelNumber, labelResult;
    QLineEdit lineNumber, lineResult;
    QPushButton setupInfo;
    QDialog dialog;

    void calcResult();
};

#endif // TASK1_H
