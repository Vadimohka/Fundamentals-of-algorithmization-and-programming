#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTextEdit;
class QSpinBox;
class QPushButton;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void restartClicked();
    void enterClicked();

private:
    void createUI();
    void printArr(const QVector<long long> &arr, const QString &pref, QString &out);
    unsigned long long bin_mul(unsigned long long a, unsigned long long n, unsigned long long m);
    unsigned long long binpow(unsigned long long a, unsigned long long n, unsigned long long m);
    long long binSearch(const QVector<long long> &a, long long find);
    void divide(QVector<long long> &A, QVector<long long> &divideSize, int &end);
    void interpolationSort(QVector<long long> &arr, QString &text);

    Ui::MainWindow *ui;

    QVector<long long> arr;
    int enterI;
    int n;
    int find;
    int mod;

    QTextEdit *textEdit;
    QSpinBox *spinBox;
    QPushButton *restartButton;
    QPushButton *enterButton;
    QLabel *label_n;
    QLabel *label_mod;
    QLabel *label_ans;
    QLabel *messageLabel;
};

#endif // MAINWINDOW_H
