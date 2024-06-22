#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include "binaryheaparray.h"
#include "binaryheaplist.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onInsertButtonClicked();
    void onExtractMaxButtonClicked();
    void onGetMaxButtonClicked();
    void onComboBoxChanged(const QString &text);

private:
    QComboBox *classSelector;
    QLineEdit *valueInput;
    QPushButton *insertButton;
    QPushButton *extractMaxButton;
    QPushButton *getMaxButton;
    QTextEdit *output;

    BinaryHeapArray heapArray;
    BinaryHeapList heapList;
    bool useArray;

    void updateOutput();
};

#endif // MAINWINDOW_H
