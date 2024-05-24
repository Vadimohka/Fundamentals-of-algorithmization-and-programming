#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

int MainWindow::binsearch(int *arr, int n, int x)
{
    int l = 0, r = n - 1;
    qDebug() << arr[l] << arr[r] << x;
    if (arr[l] > x || arr[r] < x) {
        return -2;
    }
    if (arr[l] == x) {
        return l;
    }
    int m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (arr[m] >= x) {
            r = m;
        } else {
            l = m;
        }
    }
    if (arr[r] == x) {
        return r;
    }
    return -2;
}

void MainWindow::heapify(int *arr, int n, int i)
{
    int j = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[j]) {
        j = l;
    }
    if (r < n && arr[r] > arr[j]) {
        j = r;
    }
    if (i != j) {
        swap(arr[i], arr[j]);
        heapify(arr, n, j);
    }
}

void MainWindow::HeapSort(int n, int *arr)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void MainWindow::Merge(int *arr, int l, int r)
{
    //cout << "! " << l << " " << r << endl;
    int m = (l + r) / 2;
    int *larr = new int[m - l + 1];
    for (int j = l; j <= m; j++) {
        larr[j - l] = arr[j];
        //cout << j - l << " " << j << " " << arr[j] << endl;
    }
    /*for (int j = 0; j < m - l + 1; j++) {
        cout << larr[j] << " ";
    }
    cout << endl;*/
    int *rarr = new int[r - m];
    for (int j = m + 1; j <= r; j++) {
        rarr[j - m - 1] = arr[j];
    }
    /*for (int j = 0; j < r - m; j++) {
        cout << rarr[j] << " ";
    }
    cout << endl;*/
    int j1 = 0, j2 = 0;
    for (int j = l; j <= r; j++) {
        //cout << l << " " << r << endl;
        //cout << larr[j1] << " ! " << rarr[j2] << endl;
        if (j1 >= m - l + 1) {
            arr[j] = rarr[j2];
            j2++;
            continue;
        }
        if (j2 >= r - m) {
            arr[j] = larr[j1];
            j1++;
            continue;
        }
        //cout << j1 << " " << m - l + 1 << " " << j2 << " " << r - m << " " << larr[j1] << " " << rarr[j2] << endl;
        if (larr[j1] <= rarr[j2]) {
            arr[j] = larr[j1];
            j1++;
        } else {
            arr[j] = rarr[j2];
            j2++;
        }
    }
}

void MainWindow::MergeSort(int *arr, int l, int r)
{
    if (l < r) {
        MergeSort(arr, l, (l + r) / 2);
        MergeSort(arr, (l + r) / 2 + 1, r);
        Merge(arr, l, r);
    }
}

int MainWindow::partition(int *arr, int l, int r)
{
    int x = arr[(l + r) / 2];
    int j1 = l, j2 = r;
    while (j1 < j2) {
        while (arr[j1] < x) {
            j1++;
        }
        while (arr[j2] > x) {
            j2--;
        }
        if (j1 >= j2) {
            break;
        }
        swap(arr[j1++], arr[j2--]);
    }
    return j2;
}

void MainWindow::QuickSort(int *arr, int l, int r)
{
    if (l < r) {
        int q = partition(arr, l, r);
        QuickSort(arr, l, q);
        QuickSort(arr, q + 1, r);
    }
}

void MainWindow::divide(int *arr, vector<int> &divideSize, int end)
{
    int size = divideSize.back();
    divideSize.pop_back();
    int start = end - size;
    int min = arr[start];
    int max = arr[start];
    for (int i = start + 1; i < end; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }
    if (min == max) {
        end -= size;
    } else {
        vector<vector<int> > bucket(size);
        for (int i = start; i < end; i++) {
            int p = floor(((arr[i] - min) / double(max - min)) * (size - 1));
            bucket[p].push_back(arr[i]);
        }
        for (int i = 0; i < size; i++) {
            if (!bucket[i].empty()) {
                for (int j = 0; j < bucket[i].size(); j++) {
                    arr[start++] = bucket[i][j];
                }
                divideSize.push_back(bucket[i].size());
            }
        }
    }
}

void MainWindow::interpolationSort(int *arr, int n)
{
    vector<int> divideSize;
    divideSize.push_back(n);
    while (!divideSize.empty()) {
        divide(arr, divideSize, n);
    }
}

int MainWindow::binpow(int a, int p, int mod)
{
    if (p == 1) {
        return a % mod;
    }
    int ans = binpow(a, p / 2, mod);
    ans = (ans * ans) % mod;
    if (p % 2 == 1) {
        ans = (ans * a) % mod;
    }
    return ans % mod;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /**/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //cin >> n;
    bool ok = true;
    n = ui->lineEdit->text().toInt(&ok);
    if (!ok) {
        ui->textBrowser->clear();
        ui->textBrowser->append("Error, try again");
        ui->lineEdit_2->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
    } else {
        a = new int[n];
        for (i = 0; i < n; i++) {
            //cin >> a[i];
            a[i] = rand() % (10 * n);
        }
        b = new int[n];
        for (i = 0; i < n; i++) {
            b[i] = a[i];
        }
        clock_t beg = clock();
        HeapSort(n, b);
        clock_t en = clock();
        qDebug() << "Heap sort: " << double(en - beg) / CLOCKS_PER_SEC;
        beg = clock();
        QuickSort(b, 0, n - 1);
        en = clock();
        qDebug() << "Quick sort: " << double(en - beg) / CLOCKS_PER_SEC;
        for (i = 0; i < n; i++) {
            //cout << b[i] << " ";
            b[i] = a[i];
        }
        beg = clock();
        /*for (i = 0; i < n; i++) {
        cout << b[i] << " ";
    }*/
        //cout << endl;
        MergeSort(b, 0, n - 1);
        en = clock();
        qDebug() << "Merge sort: " << double(en - beg) / CLOCKS_PER_SEC;
        for (i = 0; i < n; i++) {
            //cout << b[i] << " ";
            b[i] = a[i];
        }
        beg = clock();
        interpolationSort(b, n);
        en = clock();
        qDebug() << "Interpolation sort: " << double(en - beg) / CLOCKS_PER_SEC;
        qDebug() << "Printing...";
        //cout << (chrono::duration_cast<std::chrono::milliseconds>(en - beg)).count() << endl;
        ui->textBrowser->clearHistory();
        ui->textBrowser->append("Изначальный массив:");
        for (i = 0; i < n; i++) {
            ui->textBrowser->append(QString::number(a[i]));
            //cout << b[i] << " ";
        }
        ui->textBrowser->append("");
        ui->textBrowser->append("Отсортированный массив:");
        for (i = 0; i < n; i++) {
            ui->textBrowser->append(QString::number(b[i]));
            //cout << b[i] << " ";
            b[i] = a[i];
        }
        ui->lineEdit_2->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->textBrowser->append("");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    bool ok = true;
    x = ui->lineEdit_2->text().toInt(&ok);
    if (!ok) {
        ui->textBrowser->append("Error, try again");
    } else {
        qDebug() << n;
        for (i = 0; i < n; i++) {
            qDebug() << b[i];
        }
        ui->textBrowser->append(QString::number(binsearch(b, n, x) + 1));
    }
}
