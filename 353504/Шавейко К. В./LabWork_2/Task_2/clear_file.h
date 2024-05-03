#ifndef CLEAR_FILE_H
#define CLEAR_FILE_H

#include <QDialog>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private:
    Ui::Dialog1 *ui;
};

#endif // CLEAR_FILE_H
