#ifndef T3WIN_H
#define T3WIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class T3Win;
}
QT_END_NAMESPACE

class T3Win : public QMainWindow
{
    Q_OBJECT

public:
    explicit T3Win(QWidget *parent = nullptr);
    ~T3Win() override;

private slots:
    void on_resultButton_clicked();

private:
    Ui::T3Win *ui;

    int64_t reverseNum(int64_t);
    void countC(int64_t);
    int64_t l1 = 10, l2 = 10;
};
#endif // T3WIN_H
