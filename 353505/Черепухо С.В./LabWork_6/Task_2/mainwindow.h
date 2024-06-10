#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <FileInputOutput.h>

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
    ~MainWindow();

private:
    void keyPressEvent(QKeyEvent *event) override;

private slots:

    void on_inputButton_clicked();

    void on_outputButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_clearButton_clicked();

    void on_addButtonBin_clicked();

    void on_pushButton_Add_clicked();

    void on_lineEdit_Add_textChanged(const QString &arg1);

    void on_lineEdit_2_Add_textChanged(const QString &arg1);

    void on_lineEdit_3_Add_textChanged(const QString &arg1);

    void on_lineEdit_4_Add_textChanged(const QString &arg1);

    void on_lineEdit_Add_2_textChanged(const QString &arg1);

    void on_lineEdit_2_Add_2_textChanged(const QString &arg1);

    void on_lineEdit_3_Add_2_textChanged(const QString &arg1);

    void on_lineEdit_4_Add_2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Plant plant;
    Notebook notebook;
    QVector<float> array;
};
#endif // MAINWINDOW_H
