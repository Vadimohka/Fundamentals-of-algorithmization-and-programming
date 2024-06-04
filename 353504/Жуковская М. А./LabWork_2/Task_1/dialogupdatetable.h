#ifndef DIALOGUPDATETABLE_H
#define DIALOGUPDATETABLE_H

#include <QDialog>

namespace Ui {
class DialogUpdateTable;
}

class DialogUpdateTable : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUpdateTable(QWidget *parent = nullptr);
    ~DialogUpdateTable();

private:
    Ui::DialogUpdateTable *ui;
};

#endif // DIALOGUPDATETABLE_H
