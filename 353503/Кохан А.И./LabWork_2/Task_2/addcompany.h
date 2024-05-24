#ifndef ADDCOMPANY_H
#define ADDCOMPANY_H

#include <QWidget>
#include <QFile>

namespace Ui {
class AddCompany;
}

class AddCompany : public QWidget
{
    Q_OBJECT

public:
    explicit AddCompany(QWidget *parent = nullptr);
    ~AddCompany();
    QFile* getTxt();

signals:
    void addSignal();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddCompany *ui;
    QFile* txtCompanies;

    bool checkCorrect();
};

#endif // ADDCOMPANY_H
