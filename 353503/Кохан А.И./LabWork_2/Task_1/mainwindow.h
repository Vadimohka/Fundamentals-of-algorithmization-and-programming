#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QEvent>
#include <QFile>
#include <QMainWindow>
#include <QTextStream>
#include <QTimer>
#include <QVector>

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
    void extracted(QStringList &lineWords);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_activated(int index);
    void calendarSlot();
    void tableSlot();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    void changeEvent(QEvent *e) override;
    QTimer *timer;
    Ui::MainWindow *ui;
    Date date;
    QFile* txtFile;
    QVector<Date> txtDates;
};
#endif // MAINWINDOW_H
