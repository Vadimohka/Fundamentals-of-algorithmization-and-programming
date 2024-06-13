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

private slots:
    void on_pushButton_clicked();

private:
    QString procOut(QString &);
    QString fracToBinary(QString, long long);
    QString multiply2(const QString&);
    bool isnull(QString);
    QString sum(const QString&, const QString&);
    QString div2(QString);
    QString intToBinary(QString);
    QString doubleToBinary(QString);
    bool proc = false;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
