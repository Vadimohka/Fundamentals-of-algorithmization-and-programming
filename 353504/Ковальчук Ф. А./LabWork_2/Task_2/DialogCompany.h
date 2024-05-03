#ifndef DIALOGCOMPANY_H
#define DIALOGCOMPANY_H


#include <QDialog>

#include "Condidate.h"
#include "Companies.h"
#include "JobOpenings.h"


namespace Ui {
class DialogCompany;
}

class DialogCompany : public QDialog
{
    Q_OBJECT

public:
    friend class MainWindow;
    explicit DialogCompany(QWidget *parent = nullptr);
    ~DialogCompany();

private slots:

    void on_ButtonAddCompanyName_clicked();

    void closeEvent(QCloseEvent* event);

private:
    Ui::DialogCompany *ui;

    //MainWindow* m_pMainWindow;
};

#endif // DIALOGCOMPANY_H
