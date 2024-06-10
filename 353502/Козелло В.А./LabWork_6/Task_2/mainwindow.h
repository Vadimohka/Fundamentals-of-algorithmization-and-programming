#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include "watches.h"
#include <fstream>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void writeParagraph();
    void readParagraph();

    void writeArray();
    void readArray();
    bool checkArray();

    void writeStruct(Watches);
    void readStructs();

    void writeBinStruct(Watches watches);
    void readBinStructs();

    void writeSentence();
    void readSentence();

    bool isEnglish(const QString &str)
    {
        QRegExp rx("[a-zA-Z]+");
        return str.contains(rx);
    }

private slots:
    void on_inputLine_returnPressed();
    void on_submit_clicked();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
