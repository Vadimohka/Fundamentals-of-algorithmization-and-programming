#ifndef T1WIN_H
#define T1WIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class T1Win;
}
QT_END_NAMESPACE

class T1Win : public QMainWindow
{
    Q_OBJECT

public:
    explicit T1Win(QWidget *parent = nullptr);
    ~T1Win() override;

private slots:
    void on_button_convert_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::T1Win *ui;

    void ToBinary(QString, QString&);
    void SixDigiysAfterPoint(QString, QString&, short);
};
#endif // T1WIN_H
