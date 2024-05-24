#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <date.h>
#include <QFileDialog>
#include <fstream>
#include <QTableWidgetItem>
#include <QString>
#include <QMessageBox>
#include <dialoginputdate.h>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include "dialogupdatetable.h"

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
    void on_outputFullFilebutton_clicked();

    void on_openFilebutton_clicked();

    void on_outputLeapDatesButton_clicked();

    void on_outputDatesButton_clicked();

    void on_outputNextDayButton_clicked();

    void on_outputPreviousDayButton_clicked();

    void on_outputDaysTillBDButton_clicked();

    void on_outputWeekNumbersButton_clicked();

    void on_outputDurationToNextButton_clicked();

    void on_closeFileButton_clicked();

    void on_clearTableButton_clicked();

    void on_addNewDateButton_clicked();

    void on_inputBDdutton_clicked();

    void showContextMenuWithEdit(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    QVector <Date> datesFromFile;
    Date birthday;
    QString path;
    bool isTableFilled;
    bool isBDshow, isNextDayShow, isPreviousDayShow, isLeapShow, isDateShow, isDurationShow, isWeekNumberShow;
    bool isTheFirstOpeningFile;

    QFile file;
};
#endif // MAINWINDOW_H
