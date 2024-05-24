#ifndef LVLUPFORM_H
#define LVLUPFORM_H

#include <QWidget>

namespace Ui {
class LvlUpForm;
}

class LvlUpForm : public QWidget
{
    Q_OBJECT

public:
    explicit LvlUpForm(QWidget *parent = nullptr);
    ~LvlUpForm();

private:
    Ui::LvlUpForm *ui;
signals:
    void Choose(int);
private slots:
    void on_selectButton_clicked();
};

#endif // LVLUPFORM_H
