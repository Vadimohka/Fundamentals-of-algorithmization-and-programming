#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <QDialog>

namespace Ui {
class MyVector;
}

class MyVector : public QDialog
{
    Q_OBJECT

public:
    explicit MyVector(QWidget *parent = nullptr);
    ~MyVector();

private:
    Ui::MyVector *ui;
    QVector <long long> OriginalVector;
    QVector <long long> MyVectorr;

public:
    void MakeMyVector( QString str );
    void MakeVector( QString str );
    void MakeTable();

};

#endif // MYVECTOR_H
