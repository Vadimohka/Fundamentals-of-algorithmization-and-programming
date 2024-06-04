#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::heapify(int arr[], int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элеме4нт больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }

}

void MainWindow::heapSort(int arr[], int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

void MainWindow::printArray(int arr[], int n)
{
    QString result;
    for (int i=0; i<n; ++i){
        result += QString::number(arr[i]) + " ";
    }

        ui->printArray->setText(result);

}

void MainWindow::qsortRecursive(int *mas, int size)
{
        int i = 0;
        int j = size - 1;

        //Центральный элемент массива
        int mid = mas[size / 2];

        //Делим массив
        do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
        } while (i <= j);


        //Рекурсивные вызовы, если осталось, что сортировать
        if(j > 0) {
        //"Левый кусок"
        qsortRecursive(mas, j + 1);
        }
        if (i < size) {
        //"Првый кусок"
        qsortRecursive(&mas[i], size - i);
        }
}

void MainWindow::merge(int array[], const int left, const int mid, const int right)
{
        int const subArrayOne = mid - left + 1;
        int const subArrayTwo = right - mid;

        // Create temp arrays
        auto *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];

        // Copy data to temp arrays leftArray[] and rightArray[]
        for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

        auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;

        // Merge the temp arrays back into array[left..right]
        while (indexOfSubArrayOne < subArrayOne
               && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
        }

        // Copy the remaining elements of
        // left[], if there are any
        while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        }

        // Copy the remaining elements of
        // right[], if there are any
        while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        }
        delete[] leftArray;
        delete[] rightArray;
}

void MainWindow::mergeSort(int array[], const int begin, const int end)
{
        if (begin >= end)
        return;

        int mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
}

void MainWindow::binsearch()
{
        QString text = ui->textEdit->toPlainText();
        QStringList stringList = text.split(" ");
        int size = stringList.size();

        int* arr = new int[size]; // Создаем динамический массив

        for (int i = 0; i < size; ++i) {
        arr[i] = stringList[i].toInt(); // Преобразуем каждую подстроку в число
        }

        qsortRecursive(arr, size);

    int key = ui->textbin->toPlainText().toInt();
        bool flag = false;
        int l = 0; // левая граница
        int r = 9; // правая граница
        int mid;

        while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (arr[mid] == key) flag = true; //проверяем ключ со серединным элементом
        if (arr[mid] > key) r = mid - 1; // проверяем, какую часть нужно отбросить
        else l = mid + 1;
        }

        if (flag) ui->linebin->setText("Индекс элемента " + QString::number(key) + " в массиве равен: " + QString::number(mid));

        else ui->linebin->setText( "-1");
}

/*QTime t;
 t.start();
 some_lengthy_task();
 qDebug("Time elapsed: %d ms", t.elapsed());*/

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    QStringList stringList = text.split(" ");
    int size = stringList.size();

    int* arr = new int[size]; // Создаем динамический массив

    for (int i = 0; i < size; ++i) {
        arr[i] = stringList[i].toInt(); // Преобразуем каждую подстроку в число
    }

    int* arr2 = new int[size];
    for (int i = 0; i < size; i++) {
        arr2[i] = arr[i];
    }

    int* arr3 = new int[size];
    for (int i = 0; i < size; i++) {
        arr3[i] = arr[i];
    }

    redirection1(arr, size);
    redirection2(arr2, size);
    redirection3(arr2, size);

    /*void myFunction(int (&arr)[10]) {
        // Теперь arr - это копия переданного массива
        // Вы можете изменять arr внутри функции
for(0...size-1)
cout<<arr[i]<<" ";
    }*/
    delete[] arr;
}

void MainWindow::redirection1(int arr[], int size)
{
    QElapsedTimer heap;
    heap.start();
    heapSort(arr, size);
    QString heapTimeString = QString::number(heap.nsecsElapsed()) + " ns"; // Преобразуем время в строку
    printArray(arr, size);

    // Устанавливаем строку в виджет
    ui->heapSort->setText(heapTimeString);
}

void MainWindow::redirection2(int arr[], int size)
{
    QString result;
    for (int i=0; i<size; ++i){
        result += QString::number(arr[i]) + " ";
    }

    ui->lineEdit->setText(result);

    QElapsedTimer quick;
    quick.start();
    qsortRecursive(arr, size);
    QString quickTimeString = QString::number(quick.nsecsElapsed()) + " ns"; // Преобразуем время в строку

    // Устанавливаем строку в виджет
    ui->quickSort->setText(quickTimeString);
}

void MainWindow::redirection3(int arr[], int size)
{
    QElapsedTimer merge;
    merge.start();
    mergeSort(arr, 0, size - 1);
    QString mergeTimeString = QString::number(merge.nsecsElapsed()) + " ns"; // Преобразуем время в строк
    // Устанавливаем строку в виджет
    ui->mergeSort->setText(mergeTimeString);
}


void MainWindow::on_buttonbin_clicked()
{
    binsearch();
}

