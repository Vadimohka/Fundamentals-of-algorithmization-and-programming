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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void GenerateArray(std::vector<int>& arr);
    void PrintArray(const std::vector<int>& arr);
    void PrintArray_(const std::vector<int>& arr);
    void FillMedian(const std::vector<int>& arr);

private slots:
    void on_SizeButton_clicked();

private:
    Ui::MainWindow *ui;

    QString Output = "";
    QString Result = "";
    int size = 0;
    std::vector<int> array;
    std::vector<int> mediana;
};
#endif // MAINWINDOW_H
