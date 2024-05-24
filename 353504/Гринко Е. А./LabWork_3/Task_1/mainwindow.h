#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDoubleValidator>
#include <QMainWindow>

const int MAX_DEC = 16;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_eval_clicked();

private:
    Ui::MainWindow *ui;
    QDoubleValidator validator;

    QString toBin1(qint64, QString);
    QString toBin2(double, QString, int);
};
#endif // MAINWINDOW_H
