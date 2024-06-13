#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
constexpr int MAX_ARRAY_SIZE = 100;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void addElement();
    void sortArray();
    void searchIndex();

private:
    void updateTableModel();
    void interpolateSort(int left, int right);
    int binpow(int digit, int powder, int mod);

    QLabel *titleLabel;
    QLabel *inputLabel;
    QLineEdit *inputLineEdit;
    QPushButton *addButton;
    QPushButton *sortButton;
    QPushButton *searchButton;
    QTableView *tableView;
    QStandardItemModel *model;
    int arr[MAX_ARRAY_SIZE];
    int n;
};
#endif // MAINWINDOW_H
