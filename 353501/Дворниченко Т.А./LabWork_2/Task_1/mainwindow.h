#pragma once

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include <QTableWidgetItem>
#include "date.h"
#include <vector>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Date* myDate;
    std::vector <Date> myDatesVector;
    QString path;
    int index;
public:
    MainWindow();
private slots:
    void openFile();
    void setBirthdayDate();
    void on_addDate_clicked();
    void setDurations();
    void handleTableRowClicked(QTableWidgetItem* item);
    void editDate();
    void editFile(int index, QString edit);
    void on_savefile_clicked();

protected:
    Ui::MainWindow *ui;
};
