#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_data = new int[m_size];
    arrayForTime = new int[m_size];

    for (int i = 0; i < m_size; ++i) {
        m_data[i] = rand() % 340;
        arrayForTime[i] = m_data[i];
    }

    isSorted = false;
    isNumberGood = false;

    ui->label_4->setWordWrap(true);

    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::getNumber);
    connect(ui->lineEdit, &QLineEdit::cursorPositionChanged, this, &MainWindow::lineChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    painter.drawRect(219, 40, 800, 500);
    painter.setBrush(Qt::red);

    if (m_size != 0) {
        int w = 800 / m_size;
        for(int i = 0; i < m_size; ++i) {
            //painter.drawRect(20 + i * w, 370, w, -m_data[i]);
            painter.drawRect(219 + i * w, 540, w, -m_data[i]);
        }
    }
}

//Task 1

void MainWindow::merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Создаем временные массивы
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = m_data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = m_data[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            m_data[k] = L[i];
            i++;
        }
        else
        {
            m_data[k] = R[j];
            j++;
        }

        delay(50);
        update();

        k++;
    }

    while (i < n1)
    {
        m_data[k] = L[i];
        i++;
        k++;

        delay(50);
        update();
    }

    while (j < n2)
    {
        m_data[k] = R[j];
        j++;
        k++;

        delay(50);
        update();
    }
}

void MainWindow::mergeSort(int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);

        merge(l, m, r);
    }
}

void MainWindow::mergeSortTime(int l, int r)
{

    if (l < r)
    {
        int m = l + (r - l) / 2;


        mergeSortTime(l, m);
        mergeSortTime(m + 1, r);

        mergeTime(l, m, r);
    }
}

void MainWindow::mergeTime(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = m_data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arrayForTime[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arrayForTime[k] = L[i];
            i++;
        }
        else
        {
            arrayForTime[k] = R[j];
            j++;
        }

        delay(50);
        update();

        k++;
    }

    while (i < n1)
    {
        arrayForTime[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arrayForTime[k] = R[j];
        j++;
        k++;
    }
}

void MainWindow::heapify(int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < n && m_data[left] > m_data[largest])
        largest = left;

    if (right < n && m_data[right] > m_data[largest])
        largest = right;

    if (largest != i) {
        std::swap(m_data[i], m_data[largest]);

        delay(0.5);
        update();

        heapify(n, largest);
    }
}

void MainWindow::heapSort(int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(m_data[0], m_data[i]);
        delay(0.5);
        update();
        heapify(i, 0);
    }
}

void MainWindow::heapSortTime(int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyTime(n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arrayForTime[0], arrayForTime[i]);
        heapifyTime(i, 0);
    }
}

void MainWindow::heapifyTime(int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < n && arrayForTime[left] > arrayForTime[largest])
        largest = left;

    if (right < n && arrayForTime[right] > arrayForTime[largest])
        largest = right;

    if (largest != i) {
        std::swap(arrayForTime[i], arrayForTime[largest]);

        heapifyTime(n, largest);
    }
}

int MainWindow::partition(int low, int high)
{
    int pivot = m_data[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (m_data[j] < pivot) {
            i++;
            std::swap(m_data[i], m_data[j]);

            delay(0.5);
            update();
        }
    }
    std::swap(m_data[i + 1], m_data[high]);

    delay(0.5);
    update();

    return (i + 1);
}

void MainWindow::quickSort(int low, int high)
{
    if (low < high) {
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void MainWindow::quickSortTime(int low, int high)
{
    if (low < high) {
        int pi = partitionTime(low, high);

        quickSortTime(low, pi - 1);
        quickSortTime(pi + 1, high);
    }
}

int MainWindow::partitionTime(int low, int high)
{
    int pivot = arrayForTime[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arrayForTime[j] < pivot) {
            i++;
            std::swap(arrayForTime[i], arrayForTime[j]);
        }
    }
    std::swap(arrayForTime[i + 1], arrayForTime[high]);
    return (i + 1);
}

void MainWindow::on_pushButton_clicked()
{
    if(!isSorted)
    {
        ui->pushButton->setDisabled(true);
        ui->lineEdit->setDisabled(true);

        int time;

        if(ui->comboBox->currentIndex() == 0)
        {
            isSorted = true;

            timer.start();
            mergeSortTime(0, m_size - 1);
            time = timer.nsecsElapsed();
            ui->label_6->setText(QString::number(time / 1000000000.0, 'f', 9));

            mergeSort(0, m_size - 1);
        }
        else if(ui->comboBox->currentIndex() == 1)
        {
            isSorted = true;

            timer.start();
            quickSortTime(0, m_size - 1);
            time = timer.nsecsElapsed();
            ui->label_6->setText(QString::number(time / 1000000000.0, 'f', 9));

            quickSort(0, m_size - 1);
        }
        else if(ui->comboBox->currentIndex() == 2)
        {
            isSorted = true;

            timer.start();
            heapSortTime(m_size);
            time = timer.nsecsElapsed();
            ui->label_6->setText(QString::number(time / 1000000000.0, 'f', 9));

            heapSort(m_size);
        }
        else if(ui->comboBox->currentIndex() == 3)
        {
            isSorted = true;

            timer.start();
            interpolationSortTime();
            time = timer.nsecsElapsed();
            ui->label_6->setText(QString::number(time / 1000000000.0, 'f', 9));

            interpolationSort();
        }

        ui->pushButton->setEnabled(true);
        ui->lineEdit->setEnabled(true);
    }
}

void MainWindow::delay(int time)
{
    QEventLoop loop;
    QTimer::singleShot(time, &loop, &QEventLoop::quit);
    loop.exec();
}

void MainWindow::getNumber()
{
    bool ok;
    numberForBinarySearch = ui->lineEdit->text().toInt(&ok);
    if(!ok)
    {
        isNumberGood = false;
        QMessageBox::warning(this, "Ошибка", "Введенное значение не является числом");
    }
    else
    {
        isNumberGood = true;
        ui->lineEdit->setReadOnly(true);
    }
    setIndexOfNumber();
    ui->label_7->setText("Индекс числа в степени " + QString::number(m_size) + " по модулю " + ui->lineEdit->text() + ":");
    indexInBinpow();
}

void MainWindow::lineChanged()
{
    ui->lineEdit->setReadOnly(false);
}

int MainWindow::binarySearch()
{
    int left = 0;
    int right = m_size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (m_data[mid] == numberForBinarySearch)
            return mid;
        if (m_data[mid] < numberForBinarySearch)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void MainWindow::setIndexOfNumber()
{
    if(!isSorted && !isNumberGood)
    {
        QMessageBox::warning(this, "Ошибка", "Массив должен быть отсортирован");
        return ;
    }

    indexOfNumber = binarySearch();
    ui->label_3->setText(QString::number(indexOfNumber));
}

//Task 2

void MainWindow::interpolationSort()
{
    if (!isSorted) return;

    std::vector<int> divideSize;
    int end = m_size;
    divideSize.push_back(end);

    while (!divideSize.empty() && isSorted) {
        int size = divideSize.back();
        divideSize.pop_back();
        int start = end - size;
        int min = m_data[start];
        int max = m_data[start];

        for (int i = start + 1; i < end && isSorted; i++) {
            if (m_data[i] < min) {
                min = m_data[i];
            }
            else if (m_data[i] > max) {
                max = m_data[i];
            }
        }

        if (min == max) {
            end -= size;
        }
        else {
            int p = 0;
            std::vector<std::vector<int>> bucket(size);
            for (int i = start; i < end && isSorted; i++) {
                p = static_cast<int>(((m_data[i] - min) / static_cast<double>(max - min)) * (size - 1));
                bucket[p].push_back(m_data[i]);
            }

            for (int i = 0; i < size && isSorted; i++) {
                if (!bucket[i].empty()) {
                    for (int j = 0; j < bucket[i].size() && isSorted; j++) {
                        m_data[start++] = bucket[i][j];

                        delay(50);  // Задержка в 50 миллисекунд
                        printArray();
                        update();
                    }
                    divideSize.push_back(bucket[i].size());
                }
            }
        }
    }
}


void MainWindow::printArray()
{
    QString arrayStr;
    for (int i = 0; i < m_size; ++i) {
        arrayStr += QString::number(m_data[i]);
        if (i != m_size - 1) {
            arrayStr += ", ";
        }
    }
    ui->label_4->setText("Элементы массива: ["+arrayStr+"]");
}

void MainWindow::interpolationSortTime()
{
    if (!isSorted) return;

    std::vector<int> divideSize;
    int end = m_size;
    divideSize.push_back(end);

    while (!divideSize.empty() && isSorted) {
        int size = divideSize.back();
        divideSize.pop_back();
        int start = end - size;
        int min = arrayForTime[start];
        int max = arrayForTime[start];

        for (int i = start + 1; i < end && isSorted; i++) {
            if (arrayForTime[i] < min) {
                min = arrayForTime[i];
            }
            else if (arrayForTime[i] > max) {
                max = arrayForTime[i];
            }
        }

        if (min == max) {
            end -= size;
        }
        else {
            int p = 0;
            std::vector<std::vector<int>> bucket(size);
            for (int i = start; i < end && isSorted; i++) {
                p = static_cast<int>(((arrayForTime[i] - min) / static_cast<double>(max - min)) * (size - 1));
                bucket[p].push_back(arrayForTime[i]);
            }

            for (int i = 0; i < size && isSorted; i++) {
                if (!bucket[i].empty()) {
                    for (int j = 0; j < bucket[i].size() && isSorted; j++) {
                        arrayForTime[start++] = bucket[i][j];

                    }
                    divideSize.push_back(bucket[i].size());
                }
            }
        }
    }
}

int MainWindow::binpow(int digit, int powder, int mod)
{
    digit %= mod;
    int result = 1;
    while (powder > 0) {
        if (powder & 1)
            result = (result * digit) % mod;
        digit = (digit * digit) % mod;
        powder >>= 1;
    }
    return result;
}

void MainWindow::indexInBinpow()
{
    ui->label_8->setText(QString::number(binpow(indexOfNumber, m_size, numberForBinarySearch)));
}

