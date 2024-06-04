#ifndef REGISTRATION_WINDOW_H
#define REGISTRATION_WINDOW_H

#include <QDialog>
#include <QByteArray>
#include <QDir>
#include <QRegularExpression>

#include "allusersfile.h"
#include "user.h"
#include "bank_meneger.h"
#include "personal_data_window.h"
#include "sha256.h"


namespace Ui {
class Registration_window;
}

class Registration_window : public QDialog
{
    Q_OBJECT

signals:
    void OpenMainWindow();
    void OpenPersonalDataWindow();
public:
    explicit Registration_window(QWidget *parent = nullptr);
    ~Registration_window();

private slots:
    void OpenWindow();

    void on_Cancel_button_clicked();

    void on_View_PassWord_button_toggled(bool checked);

    void on_Continue_button_clicked();

    void on_Login_line_textChanged(const QString &arg1);

    void on_Password_line_textChanged(const QString &arg1);

    void on_Repeat_password_line_textChanged(const QString &arg1);

    void Open();

private:
    Ui::Registration_window *ui;
    Personal_data_window* personal_data_window;

    bool Is_all_lines_not_empty();

};

#endif // REGISTRATION_WINDOW_H
