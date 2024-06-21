#ifndef TASK1WINDOW_H
#define TASK1WINDOW_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QDesktopServices>

#include <QException>
#include <date.h>

namespace Ui {
class Task1Window;
}

class Task1Window : public QWidget
{
    Q_OBJECT

public:
    explicit Task1Window(QWidget *parent = nullptr);
    ~Task1Window() override;

private slots:

    void on_addToTable_clicked();

    void on_deleteLine_clicked();

    void on_editLine_clicked();

    void on_openFileDirectory_clicked();

    void on_weekNumber_clicked();

    void on_DaysTillBirthday_clicked();

private:
    Ui::Task1Window *ui;

    void showData();
    void updateFile();

    Date *date;
    QMessageBox *msgbx;
    QList<Date> dateList;
};

#endif // TASK1WINDOW_H
