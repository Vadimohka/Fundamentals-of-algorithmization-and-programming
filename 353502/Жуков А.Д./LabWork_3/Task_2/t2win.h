#ifndef T2WIN_H
#define T2WIN_H

#include <QWidget>

namespace Ui {
class T2Win;
}

class T2Win : public QWidget
{
    Q_OBJECT

public:
    explicit T2Win(QWidget *parent = nullptr);
    ~T2Win() override;

private slots:
    void on_pushButton_clicked();

private:
    Ui::T2Win *ui;

    int64_t A(int64_t m, int64_t n);
    int64_t power(int64_t, int64_t);
};

#endif // T2WIN_H
