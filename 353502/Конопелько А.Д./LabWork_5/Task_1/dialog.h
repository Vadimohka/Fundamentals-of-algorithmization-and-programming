#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
signals:
    void signalStart(int ind);

private slots:
    void on_comboBox_2_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    int indLang = 0;


};

#endif // DIALOG_H
