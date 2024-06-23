#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include<QDialog>
#include<QLineEdit>
#include<QComboBox>
#include <QFormLayout>
#include <QPushButton>

class AddItemDialog:public QDialog
{
    Q_OBJECT

public:
    explicit AddItemDialog(QWidget *parent = nullptr);

    QString getType() const;
    QString getManufacturer() const;
    QString getModel() const;
    QString getParameters() const;
    double getPrice() const;
    QString getCurrency() const;
    QString getAvailability() const;

    void setType(const QString& s);
    void setMan(const QString& s);
    void setModel(const QString& s);
    void setParameters(const QString& s);
    void setPrice(double s);
    void setCurr(int idx);
    void setAvailable(int idx);


private:
    QLineEdit *typeLineEdit;
    QLineEdit *manufacturerLineEdit;
    QLineEdit *modelLineEdit;
    QLineEdit *parametersLineEdit;
    QLineEdit *priceLineEdit;
    QComboBox *currBox;
    QComboBox *availabilityBox;
    QFormLayout *form;
};

#endif // ADDITEMDIALOG_H
