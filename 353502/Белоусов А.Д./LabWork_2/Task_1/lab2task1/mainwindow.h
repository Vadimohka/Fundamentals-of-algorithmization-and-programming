#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <vector>
#include "date.h"
#include "fileservice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void UpdateTextBox();
    void UpdateBirthdayDateBox();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_textEdit_textChanged();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Date> dates;
    Date birthdayDate;
    FileService fileService;
};
#endif // MAINWINDOW_H
