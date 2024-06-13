#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLineEdit>
#include <QRegularExpression>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Input_line_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString program_result;

    int index_of_letter;
    bool Is_have_letters(QString &);
    void GetMedianVector(QString &);

    void Long_sum(QString &, QString &, int, QString &);
    void Long_divide(QString &);

    void Get_max_length(QString &, const int);

    QString Get_max_number (QString &, QString &);
    QString Get_min_number (QString &, QString &);

    QString Get_mid_number(QString &, QString &, QString &);
};
#endif // MAINWINDOW_H
