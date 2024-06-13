#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    qint64 sign;

private slots:
    void lineEdit_userTextChanged(const QString &text);
    QString ToBinary(double number);
    QString integerToBinary(qint64 num);
    QString fractionalToBinary(float num, qint64 precision);
private:
    bool isNegative;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
