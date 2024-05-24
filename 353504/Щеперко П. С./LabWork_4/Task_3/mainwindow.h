#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QStringList>

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
    void PrintMedianVector();

private slots:
    void on_lineEdit_textEdited(const QString &arg1);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<short> medianVector;
};
#endif // MAINWINDOW_H
