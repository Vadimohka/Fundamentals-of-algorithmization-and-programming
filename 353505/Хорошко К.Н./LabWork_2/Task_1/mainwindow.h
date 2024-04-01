#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QFile>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QRadioButton>
#include <QTimer>
#include <QPushButton>
#include <QMessageBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void parce(QTextStream& stream,  QVector<Date>& dat);
    void myTable(QTableWidget& tableWidget, QVector<Date>& dat, int x0, int x1);
    QMetaObject::Connection connection;
    void fileMod(int position);
    bool radio = true;
    void fileadd();


private:
    Ui::MainWindow *ui;
    QVector<Date> dat;
    QTableWidget tableWidget;
    int n;
    QTimer *timer;

    QPushButton *previousButton;
    QPushButton *leapButton;
    QPushButton *weekButton;
    QPushButton *bithdayButton;
    QPushButton *durationButton;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *openButton;
    QLineEdit dateEdit1;
    QLineEdit dateEdit2;
    Date bithday;
    Date usrdate;
    QLabel dr;
    QLabel usrDay;

private:
    void resizeEvent(QResizeEvent *event);
    bool isDate(QString text, Date &date, QLineEdit& dateEdit);


private slots:
    void resizeTimer();
    void chang_slot(QTableWidgetItem *item);

    void previousCliced();
    void leapClick();
    void weekClick();
    void bithClick();
    void durationclick();
    void addClick();
    void deleteClick();
    void openClick();

};
#endif // MAINWINDOW_H
