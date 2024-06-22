#ifndef ADD_TYPE_WINDOW_H
#define ADD_TYPE_WINDOW_H

#include <QDialog>

#include <QString>
#include <QVariant>

namespace Ui {
class Add_type_window;
}

class Add_type_window : public QDialog
{
    Q_OBJECT

signals:
    void OpenMainWindow(QVariant);
public:
    explicit Add_type_window(QWidget *parent = nullptr);
    ~Add_type_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add_type_window *ui;
};

#endif // ADD_TYPE_WINDOW_H
