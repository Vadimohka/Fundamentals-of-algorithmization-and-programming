#ifndef CANVA_H
#define CANVA_H

#include <QDialog>
#include <paintscene.h>

namespace Ui {
class Canva;
}

class Canva : public QDialog
{
    Q_OBJECT

public:
    explicit Canva(QWidget *parent = nullptr);
    ~Canva();

private:
    Ui::Canva *ui;
    paintScene *scene;

};

#endif // CANVA_H
