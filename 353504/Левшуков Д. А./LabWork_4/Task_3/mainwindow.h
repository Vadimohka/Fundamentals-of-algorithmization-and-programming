#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

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
    void ShowError();
    void HiddenError();
    bool check_element(std::string s);
    bool read(std::string s);
    void UpdateInfo();
    void cmp(long long a,long long b, long long c);
private slots:
    void on_plainTextEdit_textChanged();

private:
    Ui::MainWindow *ui;
    std::vector<long long>v,b;
};
#endif // MAINWINDOW_H
