#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include "date.h"
#include "vector"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:

    void on_calculateButton_clicked();

    void on_openFileButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *_ui;
    std::vector<Date> _dates;
    QString _filePath;

    int _currentIndex{0};

    void addDateFromFile();

    void addDateToFile();

    void removeLastDateFromFile();

    auto readDatesFromFile(const std::string &filename) -> std::vector<Date>;
};

#endif // MAINWINDOW_H
