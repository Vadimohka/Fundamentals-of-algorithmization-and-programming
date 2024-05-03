#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "ui_mainwindow.h"
#include "abiturient.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void updateTable();
    void doComparison();

private slots:
    void onAddAbiturient();
    void onDeleteAbiturient();
    void onUpdateAbiturient();
    void onSortByScore();
    void onSearchAbiturient();
    void openFile();
    void saveFile();

private:
    Ui::MainWindow *ui;

private:
    void displayAbiturients();

    QVector<Abiturient> m_abiturients;
    // Здесь могут быть другие приватные члены класса, например, указатели на визуальные компоненты
};

#endif // MAINWINDOW_H
