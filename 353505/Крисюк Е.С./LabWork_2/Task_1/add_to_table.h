#ifndef ADD_TO_TABLE_H
#define ADD_TO_TABLE_H

#include <QDialog>

namespace Ui {
class Add_to_Table;
}

class Add_to_Table : public QDialog
{
    Q_OBJECT

public:
    explicit Add_to_Table(QWidget *parent = nullptr);
    ~Add_to_Table();

signals:
    void Send_new_day(QString);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Add_to_Table *ui;
};

#endif // ADD_TO_TABLE_H
