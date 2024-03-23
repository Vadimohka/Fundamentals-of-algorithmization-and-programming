#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include <QVBoxLayout>
#include <QMessageBox>
#include <product.h>

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
    void on_pushButton_add_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_load_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_sort_clicked();

    void on_pushButton_sortGroup_clicked();

    void on_pushButton_searchCount_clicked();

    void on_pushButton_return_clicked();

private:
    Ui::MainWindow *ui;
    QFile file;
    QVector<Product> products;
    void SetItems(int, bool);
    void ReadFromFile();
    void WriteToFile();
};
#endif // MAINWINDOW_H
