#ifndef ADD_ELEMENT_WINDOW_H
#define ADD_ELEMENT_WINDOW_H

#include <QDialog>

#include <QString>
#include <QMessageBox>
#include <QIntValidator>


namespace Ui {
class Add_element_window;
}

class Add_element_window : public QDialog
{
    Q_OBJECT


signals:
    void OpenMainWindow(QString);

public:
    explicit Add_element_window(QWidget *parent = nullptr);
    ~Add_element_window();

private slots:


    void on_Cancel_button_clicked();

    void on_Add_button_clicked();

private:
    Ui::Add_element_window *ui;
};

#endif // ADD_ELEMENT_WINDOW_H
