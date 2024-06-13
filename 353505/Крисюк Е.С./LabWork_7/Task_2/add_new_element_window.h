#ifndef ADD_NEW_ELEMENT_WINDOW_H
#define ADD_NEW_ELEMENT_WINDOW_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QIntValidator>


namespace Ui {
class Add_new_element_window;
}

class Add_new_element_window : public QDialog
{
    Q_OBJECT

signals:
    void OpenMainWindow(QString &, int &);
public:
    explicit Add_new_element_window(QWidget *parent = nullptr);
    ~Add_new_element_window();

private slots:


    void on_Cancel_button_clicked();

    void on_Add_button_clicked();

private:
    Ui::Add_new_element_window *ui;

    bool Check_if_not_empty();
};

#endif // ADD_NEW_ELEMENT_WINDOW_H
