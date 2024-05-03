#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QRegularExpression>

#include "manual.h"
#include "scheduletemplate.h"

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
    ~MainWindow() override;

    void ShowInTable(ScheduleTemplate tmp, int row);
    void ReadFromFile(const QString &filepath);
    void FillRowComboBox();

private slots:
    void on_open_manual_button_clicked();
    void AddToFile();
    void ChooseFile();
    void Search();
    void ResetSearch();
    void CalculateFuelConsumption();
    void Edit();
    void Delete();
    void FillTypesOfAirplane();

private:
    Ui::MainWindow *ui;
    Manual *manual{nullptr};
    QVector<ScheduleTemplate> schedLines;
    QRegularExpression regex;
    QString filename{""};
    double TotalFuelConsumption{0};
};
#endif // MAINWINDOW_H
