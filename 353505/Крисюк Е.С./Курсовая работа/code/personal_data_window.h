#ifndef PERSONAL_DATA_WINDOW_H
#define PERSONAL_DATA_WINDOW_H

#include <QDialog>
#include <QRegularExpression>
#include <QString>
#include <QMessageBox>
#include <QCalendarWidget>

#include "bank_meneger.h"
#include "allusersfile.h"

namespace Ui {
class Personal_data_window;
}

class Personal_data_window : public QDialog
{
    Q_OBJECT

signals:
    void OpenMainWindow();
    void OpenRegWindow();

public slots:

public:
    explicit Personal_data_window(long long, QWidget *parent = nullptr);
    ~Personal_data_window();

private slots:
    void on_name_line_textChanged(const QString &arg1);

    void on_surname_line_textChanged(const QString &arg1);

    void on_middle_name_line_textChanged(const QString &arg1);

    void on_Cancel_button_clicked();

    void on_Continue_button_clicked();

    void on_Email_line_textChanged(const QString &arg1);

    void on_Return_to_prev_window_button_clicked();

private:
    Ui::Personal_data_window *ui;
    bool Is_dont_have_numbers(QString);
    bool Is_all_lines_not_empty();

    long long index_in_bank;

    bool Check_Email();
};

#endif // PERSONAL_DATA_WINDOW_H
