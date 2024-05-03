#ifndef URA_H
#define URA_H

#include <QDialog>

namespace Ui {
class Ura;
}

class Ura : public QDialog
{
    Q_OBJECT

public:
    explicit Ura(QWidget *parent = nullptr);
    ~Ura();

private:
    Ui::Ura *ui;

public:

    void setPathLable( QString Path );

};

#endif // URA_H
