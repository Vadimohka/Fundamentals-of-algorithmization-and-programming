#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "decimaltobinary.h"

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
    void onBinaryResult(const QString& binary);
    void performConversion();

private:
    Ui::MainWindow *ui;
    DecimalToBinary *converter;
};

#endif // MAINWINDOW_H
