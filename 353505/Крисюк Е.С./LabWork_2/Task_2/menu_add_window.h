#ifndef MENU_ADD_WINDOW_H
#define MENU_ADD_WINDOW_H

#include <QDialog>
#include <QIntValidator>
#include <QFile>
#include <QFileDialog>


namespace Ui {
class Menu_add_window;
}

class Menu_add_window : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_add_window(QWidget *parent = nullptr);
    ~Menu_add_window();
    QString File_path;


signals:

    void Send_message(const QString& File_path);


private slots:

    void on_Cancel_button_clicked();

    void on_Add_button_clicked();

    void on_Dish_name_line_textChanged(const QString &arg1);

    void on_Description_line_textChanged();

    void on_Prise_line_textChanged(const QString &arg1);



    void on_Save_button_clicked();

private:
    Ui::Menu_add_window *ui;
    bool first = false, second = false, third = false, fourth = false;
};

#endif // MENU_ADD_WINDOW_H
