#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPlainTextEdit>
#include <cstdlib>
#include <ctime>

#include "customhashtable.h"

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
    void on_generateButton_clicked();
    void on_removeNegativeKeysButton_clicked();

private:
    Ui::MainWindow *ui;
    CustomHashTable hashtable;
    QPlainTextEdit *plainTextEdit; // Добавляем указатель на QPlainTextEdit
    QPushButton *generateButton; // Добавляем указатель на QPushButton
    QPushButton *removeNegativeKeysButton; // Добавляем указатель на QPushButton
    void updatePlainTextEdit();
};

#endif // MAINWINDOW_H
