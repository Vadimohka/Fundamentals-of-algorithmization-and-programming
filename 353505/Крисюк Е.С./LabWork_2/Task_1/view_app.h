#ifndef VIEW_APP_H
#define VIEW_APP_H

#include <QDialog>
#include <QList>
#include "date.h"

namespace Ui {
class View_App;
}

class View_App : public QDialog
{
    Q_OBJECT

public:
    explicit View_App(QWidget *parent = nullptr);
    ~View_App();

public slots:
    void App_open(QList <Date>, QString, int );

private slots:
    void on_User_input_date_line_userDateChanged(const QDate &date);

private:
    Ui::View_App *ui;
    QList <Date> Date_list;
};

#endif // VIEW_APP_H
