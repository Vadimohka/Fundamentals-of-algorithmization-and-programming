#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QRegularExpression>
#include <QMessageBox>

class dialog : public QDialog
{
    Q_OBJECT
public:
    dialog(QWidget *parent);
    QString getFio();
    int getMath();
    int getPhys();
    int getRus();
    int getAtestat();
    void begin(QString fio, int matText, int physText, int rusText, int atText);

private:
    QLabel *labelSurname;
    QLabel *labelName;
    QLabel *labelFather;
    QLabel *labelMat;
    QLabel *labelPhys;
    QLabel *labelRus;
    QLabel *labelAtestat;

    QLineEdit *surname;
    QLineEdit *name;
    QLineEdit *father;
    QLineEdit *mat;
    QLineEdit *phys;
    QLineEdit *rus;
    QLineEdit *atestat;

    QGridLayout *layout;

    QPushButton *okButton;
    QPushButton *cancelButton;

    QString fio;
    int Mat;
    int Phys;
    int Rus;
    int Atestat;

private slots:
    void enableOkButton();
    void disableOkButton();
    void myAccept();
};



#endif // DIALOG_H
