#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QWidget>
#include <QFile>

namespace Ui {
class AddPerson;
}

class AddPerson : public QWidget
{
    Q_OBJECT

public:
    explicit AddPerson(QWidget *parent = nullptr);
    ~AddPerson();
    QFile* getTxt();

private slots:
    void on_buttonBox_accepted();

signals:
    void addSignal();

private:
    Ui::AddPerson *ui;
    QFile* txtPeople;
    bool checkCorrect();
};

#endif // ADDPERSON_H
