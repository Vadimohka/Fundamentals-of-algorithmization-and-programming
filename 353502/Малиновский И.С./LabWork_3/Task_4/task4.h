#ifndef TASK4_H
#define TASK4_H

#include <QObject>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <QScrollArea>

const int RESH_DIALOG_WIDTH = 400;
const int RESH_DIALOG_HIGHT = 800;
const int QLABEL_HIGHT = 24;

class Task4 : public QObject
{
    Q_OBJECT
public:
    Task4(QObject *parent = nullptr);

    void resh(int n, int start, int finish);

    void startDialog();
private:
    QDialog reshDialog, dialog;
    QLabel labelNumber;
    QLineEdit lineNumber;
    QPushButton setupInfo;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *scrollLayout, *reshLayout;

    QVector <QLabel *> labels;

    void startReshDialog();
};

#endif // TASK4_H
