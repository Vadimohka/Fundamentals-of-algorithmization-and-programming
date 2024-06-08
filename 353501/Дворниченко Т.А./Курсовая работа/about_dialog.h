#ifndef ABOUT_DIALOG_H
#define ABOUT_DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPixmap>
#include <QSpacerItem>

namespace Ui {
class About_Dialog;
}

class About_Dialog : public QDialog
{

    Q_OBJECT

public:
    explicit About_Dialog(QWidget *parent = 0);
    ~About_Dialog();

private:
    Ui::About_Dialog *ui;
    QVBoxLayout * mainVBox;

    QLabel * schoolInfo, * classInfo, * groupMember1, * logoLbl, * spacerLabel;

    QPixmap * logo, * spacerBar;

};

#endif // ABOUT_DIALOG_H
