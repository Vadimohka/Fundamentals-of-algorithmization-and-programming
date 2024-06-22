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
    void enterClicked();
    void restartClicked();

private:
    void createUI();

    Ui::MainWindow *ui;

    QVector<long long> arr;
    int enterI;
    int n;

    QTextEdit *textEdit;
    QSpinBox *spinBox;
    QPushButton *restartButton;
    QPushButton *enterButton;
    QLabel *label_n;
    QLabel *messageLabel;
};

#endif // MAINWINDOW_H
