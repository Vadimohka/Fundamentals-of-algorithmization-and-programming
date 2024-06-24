#ifndef MIDVECTOR_H
#define MIDVECTOR_H

#include <QDialog>

namespace Ui {
class MidVector;
}

class MidVector : public QDialog
{
    Q_OBJECT

public:
    explicit MidVector(QWidget *parent = nullptr);
    ~MidVector();

private:
    Ui::MidVector *ui;
    QVector < long long > OriginalVector;
    QVector < long long > MidVectorr;

public:

    void MakeMidVector( QString str );
    void MakeVector( QString str );
    void MakeTable();

};

#endif // MIDVECTOR_H
