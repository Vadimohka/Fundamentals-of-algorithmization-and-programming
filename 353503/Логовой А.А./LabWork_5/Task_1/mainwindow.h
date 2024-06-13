#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<keyboard.h>
#include<QString>
#include<QPainter>
#include<langauges.h>
#include<QFile>
#include<QFileDialog>
#include<typingstatistic.h>

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
signals:
    void textFromFile(QString text);

private slots:
    void on_comboBox_activated(int index);

    void on_file_clicked();

    void on_pushButton_clicked();

private:

    QString text12;

    KeyBoard* key;

    QString current_template;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
