#ifndef DELETE_ELEMENT_WINDOW_H
#define DELETE_ELEMENT_WINDOW_H

#include <QDialog>
#include <QIntValidator>
#include <QMessageBox>


namespace Ui {
class Delete_element_window;
}

class Delete_element_window : public QDialog
{
    Q_OBJECT

signals:
    void OpenMainWindow(int key);

public:
    explicit Delete_element_window(QWidget *parent = nullptr);
    ~Delete_element_window();

private slots:
    void on_Cancel_button_clicked();


    void on_Delete_button_clicked();

private:
    Ui::Delete_element_window *ui;
};

#endif // DELETE_ELEMENT_WINDOW_H
