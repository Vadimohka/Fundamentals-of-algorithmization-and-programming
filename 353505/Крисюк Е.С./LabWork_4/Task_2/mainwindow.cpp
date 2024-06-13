#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIntValidator* val = new QIntValidator(0,99);
    ui -> Input_line -> setValidator(val);

    array = new int[0];

    count_of_rows = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Array_input(int current_array_length){

    for(int i = 0; i < current_array_length; ++i){
        array[i] = QRandomGenerator::global() -> bounded(0,100);
    }
}

void MainWindow::on_Input_line_textChanged(const QString &text)
{
    count_of_rows = 0;
    if(text != ""){
        delete[] array;
        array_length = text.toInt();

        array = new int[array_length];
        Array_input(array_length);

        ui -> Table -> setRowCount(count_of_rows + 1);
        ui -> Table -> setColumnCount(array_length);

        Array_to_table(array_length);

        interpolationSort();
    }
    else{
        ui -> Output_line -> setText("");
        ui -> Table -> clear();
    }
}

void interpolationSort(std::vector<int>& arr, int start, int size) {
    int minValue = arr[start];
    int maxValue = arr[start];

    for (int i = start + 1; i < start + size; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
        else if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    if (minValue != maxValue) {
        std::vector<std::vector<int>> bucket(size, std::vector<int>(size, 0));

        int interpolation;
        for (int i = 0; i < size; i++) {
            interpolation = static_cast<int>(std::floor(((arr[start + i] - minValue) / (maxValue - minValue)) * (size - 1)));
            bucket[interpolation][i] = arr[start + i];
        }

        int currentStart = start;
        for (int i = 0; i < size; i++) {
            if (bucket[i][0] != 0) {
                interpolationSort(arr, currentStart, size);
                currentStart += size;
            }
            for (int j = 0; j < size; j++) {
                if (bucket[i][j] != 0) {
                    arr[start++] = bucket[i][j];
                }
            }
        }
    }
}

void MainWindow::Array_to_table(int current_array_length){
    for(int i = 0; i < current_array_length; ++i){
        ui -> Table -> setItem(count_of_rows, i, new QTableWidgetItem(QString::number(array[i])));
    }
}
