#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sortHeapButton_clicked();
    void on_sortQuickButton_clicked();
    void on_sortMergeButton_clicked();
    void on_sortInterpolationButton_clicked(); // Новый слот для интерполяционной сортировки
    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<int> array;
    void updateArrayDisplay();
    void measureSortTime(void (*sortFunc)(QVector<int>&));

    QLineEdit *arrayInput;
    QLabel *arrayDisplay;
    QPushButton *sortHeapButton;
    QPushButton *sortQuickButton;
    QPushButton *sortMergeButton;
    QPushButton *sortInterpolationButton; // Новая кнопка для интерполяционной сортировки
    QPushButton *searchButton;
};

#endif // MAINWINDOW_H
