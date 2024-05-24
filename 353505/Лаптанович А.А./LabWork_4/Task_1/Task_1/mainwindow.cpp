#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printArr(QVector<long long> arr, QString pref, QString & out){
    out += pref;
    for (auto &i : arr)
        out += QString::number(i) + " ";
    out += "\n";
}

void MainWindow::heapify(QVector<long long>& arr, long long n, long long i, long long & count) {
    long long largest = i;
    long long l = 2 * i + 1;
    long long r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        ++count;
        heapify(arr, n, largest, count);
    }
}

long long MainWindow::heapSort(QVector<long long> & arr, QString & text) {
    long long count = 0;
    long long step = 1;
    long long n = arr.size();

    for (long long i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, count);
    printArr(arr, "heap sort, шаг" + QString::number(step++) + ": ", text);
    for (long long i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        ++count;
        heapify(arr, i, 0, count);
        printArr(arr, "heap sort, шаг" + QString::number(step++) + ": ", text);
    }
    return count;
}

long long MainWindow::partition(QVector<long long>& arr, long long start, long long end, long long & countSt) {
    long long pivot = arr[start];

    long long count = 0;
    for (long long i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    long long pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);
    ++countSt;
    long long i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
            ++countSt;
        }
    }
    return i + 1;
}

long long MainWindow::quickSort(QVector<long long> & arr, long long low, long long high, QString & text)
{
    long long count = 0;
    static long long step = 1;
    if (low == 0 && high == arr.size() - 1) step = 1;
    long long mid;
    long long f=low, l=high;
    mid=arr[(f+l) / 2];
    while (f<l) {
        while (arr[f]<mid) f++;
        while (arr[l]>mid) l--;
        if (f<l)
        {
            ++count;
            std::swap(arr[f], arr[l]);
            printArr(arr, "quick sort, шаг" + QString::number(step++) + ": ", text);
            f++;
            l--;
        } else if (f == l){
            f++;
            l--;
        }
    };
    if (low<l) count += quickSort(arr, low, l,text);
    if (f<high) count += quickSort(arr, f, high, text);
    return count;
}

long long MainWindow::merge(QVector<long long>& arr, long long l, long long m, long long r) {
    long long n1 = m - l + 1;
    long long n2 = r - m;

    QVector<long long> L(n1), R(n2);

    for (long long i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (long long j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    long long i = 0, j = 0, k = l;
    long long count = 0;
    while (i < n1 && j < n2) {
        ++count;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count;
}

long long MainWindow::mergeSort(QVector<long long> & arr, long long l, long long r, QString & text) {
    long long count = 0;
    static long long step = 1;
    if (l == 0 && r == arr.size() - 1) step = 1;
    if (l < r) {
        long long m = l + (r - l) / 2;

        count += mergeSort(arr, l, m, text);
        printArr(arr, "merge sort, шаг" + QString::number(step++) + ": ", text);
        count += mergeSort(arr, m + 1, r, text);
        printArr(arr, "merge sort, шаг " + QString::number(step++) + ": ", text);
        count += merge(arr, l, m, r);
    }
    return count;
}

long long MainWindow::binSearch(QVector<long long> & a, long long find) {
    long long l = 0, r = a.size() - 1;

    while (r > l) {
        long long m = (l + r) / 2;

        if (a[m] < find) {
            l = m + 1;
        } else if (a[m] > find) {
            r = m - 1;
        } else {
            return m;
        }
    }
    \
    if (a[l] == find) {
        return l;
    } else {
        return -2;
    }
}

void MainWindow::on_pushButton_enter_clicked()
{
    if (ui->Message->text() == "Введите n:"){
        n = ui->spinBox->value();
        arr.resize(n);
        ui->spinBox->setMinimum(-2147483647);
        ui->spinBox->setMaximum(1000);
        ui->Message->setText("Введите элемент № " + QString::number(enterI + 1) + ":");
        ui->label_n->setText("n: " + QString::number(n));

    } else if (ui->Message->text() == "Введите элемент для поиска"){
        find = ui->spinBox->value();
        //ui->Message->setText("Input Ended");
        ui->spinBox->setEnabled(false);
        ui->pushButton_enter->setEnabled(false);
        ui->label_ans->setText("Ответ: " + QString::number(binSearch(arr, find) + 1));
    }
    else{
        arr[enterI] = ui->spinBox->value();

        if (enterI == 0){
            ui->textEdit->setVisible(true);
            ui->textEdit->setText("Массив:        " + QString::number(arr[0]));
        }
        else
            ui->textEdit->setText(ui->textEdit->toPlainText() + " " + QString::number(arr[enterI]));
        ++enterI;
        if (enterI != n)
            ui->Message->setText("Введите элемент № " + QString::number(enterI + 1) + ":");
        else{
            ui->Message->setText("Введите элемент для поиска");
            auto arr1 = arr,
                 arr2 = arr,
                 arr3 = arr;
            QString text1, text2, text3;
            ui->label_speed->setText("Heap  sort количество шагов: " + QString::number(heapSort(arr1, text1)) + "\n" +
                                     "Quick sort количество шагов: " + QString::number(quickSort(arr2, 0, arr2.size() - 1, text2)) + "\n" +
                                     "Merge sort количество шагов: " + QString::number(mergeSort(arr3, 0, arr3.size() - 1, text3)));
            arr = arr1;
            ui->textEdit->setText(ui->textEdit->toPlainText() + "\n" + text1 + "\n" + text2 + "\n" + text3 + "\n");
            QString add = "Отсортированный массив: ";
            for (auto &i : arr) {
                add += QString::number(i) + " ";
            }
            ui->textEdit->setText(ui->textEdit->toPlainText() + add);

        }
    }
}


void MainWindow::on_pushButton_restart_clicked()
{
    ui->spinBox->setEnabled(true);
    ui->pushButton_enter->setEnabled(true);
    ui->spinBox->setMinimum(1);
    arr.clear();
    enterI = 0;
    n = 0;
    ui->textEdit->setText("");
    ui->textEdit->setReadOnly(true);
    ui->label_n->setText("");
    ui->label_speed->setText("");
    ui->label_ans->setText("");
    ui->Message->setText("Введите n:");
}
