#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <vector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sortArray();

private:
    QVBoxLayout *verticalLayout;
    QTextEdit *inputTextEdit;
    QPushButton *sortButton;
    QTextEdit * outputTextEdit;

    void interpolationSort(std::vector<int> &arr);
    int binpow(int a, int b, int m);
};
