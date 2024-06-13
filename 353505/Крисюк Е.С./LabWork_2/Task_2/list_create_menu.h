#ifndef LIST_CREATE_MENU_H
#define LIST_CREATE_MENU_H

#include <QDialog>
#include <QFile>
#include <QIntValidator>
#include <QDir>

namespace Ui {
class List_create_menu;
}

class List_create_menu : public QDialog
{
    Q_OBJECT

public:
    explicit List_create_menu(QWidget *parent = nullptr);
    ~List_create_menu();

signals:
    void Send_path(const QString& file_path);

private slots:
    void on_Cancel_button_clicked();

    void on_Dish_count_textChanged(const QString &arg1);

    void on_Add_dish_button_clicked();

    void on_Order_number_line_textChanged(const QString &arg1);

    void on_Table_number_line_textChanged(const QString &arg1);

    void on_Add_order_button_clicked();

public slots:
    void Reseive_path(const QString& File_path);

private:
    Ui::List_create_menu *ui;
    bool first = false, second = false, third = false;
};

#endif // LIST_CREATE_MENU_H
