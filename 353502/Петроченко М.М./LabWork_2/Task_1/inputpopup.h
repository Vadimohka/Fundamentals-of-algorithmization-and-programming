//
// Created by acryoz on 5.3.24.
//

#ifndef UNTITLED5_INPUTPOPUP_H
#define UNTITLED5_INPUTPOPUP_H

#include <QWidget>
#include <QPushButton>
#include <QValidator>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include "Date.h"


QT_BEGIN_NAMESPACE
namespace Ui { class InputPopup; }
QT_END_NAMESPACE

class InputPopup : public QWidget {
Q_OBJECT

public:
    explicit InputPopup(QWidget *parent = nullptr);

    Date getDate();
    ~InputPopup() override;

public slots:
    void onAccept();
signals:
    void valid(Date);
private:
    QLabel* day_label;
    QLabel* month_label;
    QLabel* year_label;
    QLineEdit* day_line;
    QLineEdit* month_line;
    QLineEdit* year_line;
    QPushButton* accept;
    QIntValidator* validator;
    QGridLayout* grid;
    QVBoxLayout* vbox;
    QLabel* errorLabel;
    Date date;
    Ui::InputPopup *ui;
};


#endif //UNTITLED5_INPUTPOPUP_H
