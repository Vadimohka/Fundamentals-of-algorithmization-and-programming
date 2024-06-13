#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIntValidator>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;


private slots:
    void on_Input_line_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    int* array;
    int array_length;

    void Array_input(int);
    void Array_to_table(int);
    void interpolationSort();

    int count_of_rows;
};
#endif // MAINWINDOW_H
