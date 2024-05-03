#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H

#include <QDialog>

namespace Ui {
class errorMessage;
}

class errorMessage : public QDialog
{
    Q_OBJECT

public:
    explicit errorMessage(QWidget *parent = nullptr);
    ~errorMessage();

private:
    Ui::errorMessage *ui;
};

#endif // ERRORMESSAGE_H
