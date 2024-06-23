#ifndef RANGEDIALOG_H
#define RANGEDIALOG_H
#include<QtWidgets>

class RangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RangeDialog(QWidget *parent = nullptr);

    double getMinVal() const;
    double getMaxVal() const;
    QString getCurr();
private:
    QLineEdit *minLineEdit;
    QLineEdit *maxLineEdit;
    QComboBox *currBox;


};

#endif // RANGEDIALOG_H
