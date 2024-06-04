#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->arrayElements->setWordWrap(true);

    updateData(m_size);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateData(int newSize) {
    if(m_data != nullptr)
    {
        delete[] m_data;
        delete[] m_colors;
    }
    m_size = newSize;
    m_data = new int[m_size];
    m_colors = new QColor[m_size];
    tempData = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = rand() % 700;
        m_colors[i] = QColor(rand() % 256, rand() % 256, rand() % 256);
        tempData[i] = m_data[i];
    }

    printArray();
}

void MainWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    painter.drawRect(20, 20, 1200, 700);

    if (m_size != 0) {
        int w = 1200 / m_size;
        for(int i = 0; i < m_size; ++i) {
            painter.setBrush(m_colors[i]);
            painter.drawRect(20 + i * w, 720, w, -m_data[i]);
        }
    }
}

void MainWindow::heapSort()
{
    // Построение кучи (перегруппировка массива)
    for (int i = m_size / 2 - 1; i >= 0 && isSorting; i--)
        heapify(m_size, i);

    // Один за другим извлекаем элемент из кучи
    for (int i = m_size - 1; i >= 0 && isSorting; i--) {
        // Перемещаем текущий корень в конец
        std::swap(m_data[0], m_data[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(i, 0);
        delay(50);  // Задержка в 50 миллисекунд
        printArray();
        update();
    }
}

void MainWindow::heapSortTimer()
{
    // Построение кучи (перегруппировка массива)
    for (int i = m_size / 2 - 1; i >= 0 && isSorting; i--)
        heapifyTimer(m_size, i);

    // Один за другим извлекаем элемент из кучи
    for (int i = m_size - 1; i >= 0 && isSorting; i--) {
        // Перемещаем текущий корень в конец
        std::swap(tempData[0], tempData[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapifyTimer(i, 0);
    }
}

void MainWindow::heapify(int n, int i)
{
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // левый = 2*i + 1
    int right = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (left < n && m_data[left] > m_data[largest])
        largest = left;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (right < n && m_data[right] > m_data[largest])
        largest = right;

    // Если самый большой элемент не корень
    if (largest != i) {
        std::swap(m_data[i], m_data[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(n, largest);
    }
}

void MainWindow::heapifyTimer(int n, int i)
{
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // левый = 2*i + 1
    int right = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (left < n && tempData[left] > tempData[largest])
        largest = left;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (right < n && tempData[right] > tempData[largest])
        largest = right;

    // Если самый большой элемент не корень
    if (largest != i) {
        std::swap(tempData[i], tempData[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(n, largest);
    }
}

void MainWindow::quickSort(int low, int high)
{

    if (low >= high && isSorting)
        return;
        /* pi - индекс опорного элемента */
    int p = partition(low, high);

        // Рекурсивно сортируем элементы до и после опорного
    quickSort(low, p - 1);
    quickSort(p + 1, high);

}

void MainWindow::quickSortTimer(int low, int high)
{
    if (low >= high && isSorting)
        return;
    /* pi - индекс опорного элемента */
    int p = partitionTimer(low, high);

    // Рекурсивно сортируем элементы до и после опорного
    quickSortTimer(low, p - 1);
    quickSortTimer(p + 1, high);
}

int MainWindow::partition(int start, int end)
{
    // Опорный элемент (принимаем за опорный последний элемент)
    int pivot = m_data[start];
    //int i = (low - 1); // Индекс меньшего элемента
    int count = 0;

    for (int i = start + 1; i <= end && isSorting; i++) {
        if (m_data[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = start + count;
    std::swap(m_data[pivotIndex], m_data[start]);
    delay(50);
    printArray();
    update();

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex && isSorting) {

        while (m_data[i] <= pivot) {
            i++;
        }

        while (m_data[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex && isSorting) {
            std::swap(m_data[i++], m_data[j--]);
            delay(50);
            printArray();
            update();
        }
    }

    return pivotIndex;
}

int MainWindow::partitionTimer(int start, int end)
{
    int pivot = tempData[start];
    //int i = (low - 1); // Индекс меньшего элемента
    int count = 0;

    for (int i = start + 1; i <= end && isSorting; i++) {
        if (tempData[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = start + count;
    std::swap(tempData[pivotIndex], tempData[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex && isSorting) {

        while (tempData[i] <= pivot) {
            i++;
        }

        while (tempData[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex && isSorting) {
            std::swap(tempData[i++], tempData[j--]);
        }
    }

    return pivotIndex;
}

void MainWindow::mergeSort(int left, int right)
{
    if (left < right && isSorting)
    {
        int mid = left + (right - left) / 2;

        // Сортируем первую и вторую половины
        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }
}

void MainWindow::mergeSortTimer(int left, int right)
{
    if (left < right && isSorting)
    {
        int mid = left + (right - left) / 2;

        // Сортируем первую и вторую половины
        mergeSortTimer(left, mid);
        mergeSortTimer(mid + 1, right);

        mergeTimer(left, mid, right);
    }
}

void MainWindow::merge(int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создаем временные массивы
    int L[n1], R[n2];

    // Копируем данные во временные массивы L[] и R[]
    for (i = 0; i < n1; i++)
        L[i] = m_data[left + i];
    for (j = 0; j < n2; j++)
        R[j] = m_data[mid + 1 + j];

    // Сливаем временные массивы обратно в m_data[left..right]
    i = 0; // Индекс первого подмассива
    j = 0; // Индекс второго подмассива
    k = left; // Индекс сливаемого подмассива
    while (i < n1 && j < n2 && isSorting)
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
        delay(50);  // Задержка в 50 миллисекунд
        printArray();
        update();
        k++;
    }

    // Копируем оставшиеся элементы L[], если есть
    while (i < n1 && isSorting)
    {
        m_data[k] = L[i];
        i++;
        k++;
        delay(50);  // Задержка в 50 миллисекунд
        printArray();
        update();
    }

    // Копируем оставшиеся элементы R[], если есть
    while (j < n2 && isSorting)
    {
        m_data[k] = R[j];
        j++;
        k++;
        delay(50);  // Задержка в 50 миллисекунд
        printArray();
        update();
    }
}

void MainWindow::mergeTimer(int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создаем временные массивы
    int L[n1], R[n2];

    // Копируем данные во временные массивы L[] и R[]
    for (i = 0; i < n1; i++)
        L[i] = tempData[left + i];
    for (j = 0; j < n2; j++)
        R[j] = tempData[mid + 1 + j];

    // Сливаем временные массивы обратно в tempData[left..right]
    i = 0; // Индекс первого подмассива
    j = 0; // Индекс второго подмассива
    k = left; // Индекс сливаемого подмассива
    while (i < n1 && j < n2 && isSorting)
    {
        if (L[i] <= R[j])
        {
            tempData[k] = L[i];
            i++;
        }
        else
        {
            tempData[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы L[], если есть
    while (i < n1 && isSorting)
    {
        tempData[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы R[], если есть
    while (j < n2 && isSorting)
    {
        tempData[k] = R[j];
        j++;
        k++;
    }
}

void MainWindow::interpolationSort()
{
    if (!isSorting) return;

    std::vector<int> divideSize;
    int end = m_size;
    divideSize.push_back(end);

    while (!divideSize.empty() && isSorting) {
        int size = divideSize.back();
        divideSize.pop_back();
        int start = end - size;
        int min = m_data[start];
        int max = m_data[start];

        for (int i = start + 1; i < end && isSorting; i++) {
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
            for (int i = start; i < end && isSorting; i++) {
                p = static_cast<int>(((m_data[i] - min) / static_cast<double>(max - min)) * (size - 1));
                bucket[p].push_back(m_data[i]);
            }

            for (int i = 0; i < size && isSorting; i++) {
                if (!bucket[i].empty()) {
                    for (int j = 0; j < bucket[i].size() && isSorting; j++) {
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

void MainWindow::interpolationSortTimer()
{
    if (!isSorting) return;

    std::vector<int> divideSize;
    int end = m_size;
    divideSize.push_back(end);

    while (!divideSize.empty() && isSorting) {
        int size = divideSize.back();
        divideSize.pop_back();
        int start = end - size;
        int min = tempData[start];
        int max = tempData[start];

        for (int i = start + 1; i < end && isSorting; i++) {
            if (tempData[i] < min) {
                min = tempData[i];
            }
            else if (tempData[i] > max) {
                max = tempData[i];
            }
        }

        if (min == max) {
            end -= size;
        }
        else {
            int p = 0;
            std::vector<std::vector<int>> bucket(size);
            for (int i = start; i < end && isSorting; i++) {
                p = static_cast<int>(((tempData[i] - min) / static_cast<double>(max - min)) * (size - 1));
                bucket[p].push_back(tempData[i]);
            }

            for (int i = 0; i < size && isSorting; i++) {
                if (!bucket[i].empty()) {
                    for (int j = 0; j < bucket[i].size() && isSorting; j++) {
                        tempData[start++] = bucket[i][j];
                    }
                    divideSize.push_back(bucket[i].size());
                }
            }
        }
    }
}




void MainWindow::delay(int millisecondsToWait)
{
    QEventLoop loop;
    QTimer::singleShot(millisecondsToWait, &loop, &QEventLoop::quit);
    loop.exec();
}

void MainWindow::on_pushButton_clicked() // запустить сортировку
{
    if (isSorted()) {
        QMessageBox::critical(0, "The array is sorted", "The array is already sorted!\n");
        return;
    }

    int elapsedTime;
    isSorting = true;
    ui->comboBox->setEnabled(false);
    ui->pushButton_2->setEnabled(true);

    if (ui->comboBox->currentIndex() == 0) {
        timer.start();
        heapSortTimer();
        elapsedTime = timer.nsecsElapsed();
        ui->time->setText("Speed: "+QString::number(elapsedTime / 1000000000.0, 'f', 9)+" sec");

        heapSort();
    } else if (ui->comboBox->currentIndex() == 1) {
        timer.start();
        quickSortTimer(0, m_size - 1);
        elapsedTime = timer.nsecsElapsed();
        ui->time->setText("Speed: "+QString::number(elapsedTime / 1000000000.0, 'f', 9)+" sec");

        quickSort(0, m_size - 1);
    } else if (ui->comboBox->currentIndex() == 2) {
        timer.start();
        mergeSortTimer(0, m_size - 1);
        elapsedTime = timer.nsecsElapsed();
        ui->time->setText("Speed: "+QString::number(elapsedTime / 1000000000.0, 'f', 9)+" sec");

        mergeSort(0, m_size - 1);
    } else {
        timer.start();
        interpolationSortTimer();
        elapsedTime = timer.nsecsElapsed();
        ui->time->setText("Speed: "+QString::number(elapsedTime / 1000000000.0, 'f', 9)+" sec");

        interpolationSort();
    }
    ui->comboBox->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void MainWindow::on_pushButton_2_clicked() // остановить сортировку
{
    isSorting = false;
    ui->comboBox->setEnabled(true);
}


void MainWindow::on_pushButton_3_clicked() // задать случайные значения
{
    isSorting = false;
    int size = ui->spinBox->value();
    updateData(size);
    update();
}

void MainWindow::printArray() {
    QString arrayStr;
    for (int i = 0; i < m_size; ++i) {
        arrayStr += QString::number(m_data[i]);
        if (i != m_size - 1) {
            arrayStr += ", ";
        }
    }

    ui->arrayElements->setText("Array elements: ["+arrayStr+"]");
}


int MainWindow::binsearch(int digit)
{

    int left = 0;
    int right = m_size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Проверяем, является ли digit средним элементом
        if (m_data[mid] == digit)
            return mid;
        // Если digit больше, игнорируем левую половину
        if (m_data[mid] < digit)
            left = mid + 1;
        // Если digit меньше, игнорируем правую половину
        else
            right = mid - 1;
    }

    // Если мы здесь, то элемент не присутствует
    return -1;
}

bool MainWindow::isSorted()
{
    for (int i = 0; i < m_size - 1; i++) {
        if (m_data[i] > m_data[i + 1]) {
            return false;  // Если предыдущий элемент больше следующего, массив не отсортирован
        }
    }
    return true;  // Если мы прошли весь массив и не нашли ни одного элемента, который больше следующего, массив отсортирован
}


void MainWindow::on_pushButton_4_clicked()
{
    if (isSorted()) {
        int el = ui->spinBox_2->value();
        index = binsearch(el);
        ui->index->setText("Index: "+QString::number(index));
    } else {
        QMessageBox::critical(0, "Ошибка", "Массив не отсортирован!\nБинарный поиск проводиться только в отсортированном массиве!");
    }
}

int MainWindow::binpow(int digit, int powder, int mod) {
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


void MainWindow::on_pushButton_5_clicked()
{
    int mod = ui->spinBox_3->value();
    ui->bpow->setText("The result: "+QString::number(binpow(index, m_size, mod)));
}

