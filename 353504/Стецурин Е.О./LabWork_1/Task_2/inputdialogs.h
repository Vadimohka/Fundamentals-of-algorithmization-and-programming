#ifndef INPUTDIALOGS_H
#define INPUTDIALOGS_H

#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr);

    int getX();
    int getY();

private:
    QSpinBox *xInput, *yInput;
};

class InputDialogkrds : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialogkrds(QWidget *parent = nullptr);

    int getX();
    int getY();

private:
    QLineEdit *xInput, *yInput;
};

class InputDialogzv : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialogzv(QWidget *parent = nullptr);

    int getX();
    int getY();
    int getRadio();

private:
    QSpinBox *xInput, *yInput;
    QRadioButton *radioButton5,*radioButton6,*radioButton8;
};

class InputDialogrb : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialogrb(QWidget *parent = nullptr);

    int getX();
    int getY();

private:
    QSpinBox *xInput, *yInput;
};

class InputDialogkv : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialogkv(QWidget *parent = nullptr);

    int getX();

private:
    QSpinBox *xInput;
};


#endif // INPUTDIALOGS_H
