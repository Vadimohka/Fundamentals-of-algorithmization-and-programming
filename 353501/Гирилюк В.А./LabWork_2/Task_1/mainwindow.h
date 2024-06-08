#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QTableWidget>
#include <QStyledItemDelegate>


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

private slots:

    void on_actionOpen_file_triggered();

    void on_birthday_editingFinished();

    void lockColumns();

    void fillTableField();

    void on_isLeapButton_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_nextDayButton_clicked();

    void on_previousDayButton_clicked();

    void on_weekNumberButton_clicked();

    void on_tillBirthdayButton_clicked();

    void on_durationButton_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    bool event(QEvent *e);

private:
    Ui::MainWindow *ui;
    QVector<Date> date;
    Date selectedDate;
    Date bufferDate;
    QTableWidgetItem *bufferItem;
    Date *today = nullptr;
    Date *birthday = nullptr;
    QFile *File = nullptr;

    QString filePath = "/home/vlad/Qt/projects/2 sem/Lab_Work2/";
};
#endif // MAINWINDOW_H
