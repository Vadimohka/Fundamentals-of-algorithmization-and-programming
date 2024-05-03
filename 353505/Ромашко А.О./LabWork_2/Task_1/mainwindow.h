#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QVector>
#include <QTableWidget>
#include <QTextStream>
#include <QTimer>
#include <QLineEdit>
#include <QSpinBox>

#include "date.h"

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
    QFile file;
    void dateArray(QString str);

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_cellActivated(int row, int column);

    void on_pushButton_2_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEditBD_textChanged(const QString &arg1);

    void on_labelBD_linkActivated(const QString &link);

    void on_pushButton_3_clicked();

    void on_label_Now_linkActivated(const QString &link);

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton__clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    void addElements(QString arg1);
private:
    bool fopen = false;
    int datenum;
    int arrsize;
    int indexSB;
    QString filepath;
    QString editstr;
    Ui::MainWindow *ui;
    QVector <QString> date;
    QVector <Date> dateclass;
    Date *d;
    Date *BD;
    Date *Fedit;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_1;
};
#endif // MAINWINDOW_H
