#include "widget.h"
#include "./ui_widget.h"
#include <QTimer>
#include <QRandomGenerator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->spinBox->setRange(2, 900);
    ui->verticalSlider->setRange(5, 200);
    ui->pushButton->setDisabled(1);
    ui->verticalSlider->setValue(100);
    ui->spinBox_2->setRange(-2000, 2000);
    ui->pushButton_3->setDisabled(1);
    ui->pushButton_4->setEnabled(0);
    ui->label_4->setText("Delay: " + QString::number(delay)+"ms");
    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        swaps = 0;
        comparisions = 0;
        arrayAccesses = 0;
        ui->pushButton->setDisabled(1);
        ui->pushButton_2->setDisabled(1);
        ui->comboBox->setDisabled(1);
        ui->spinBox->setDisabled(1);
        switch (ui->comboBox->currentIndex()) {
        case 0:
            heapSort(nums);
            break;
        case 1:
            QSort(nums, 0, nums.size()-1);
            break;
        case 2:
            mergeSort(nums, 0, nums.size()-1);
            break;
        case 3: InterpolationSort(nums);
        default:
            break;
        }

        firstSwitchedElement = 0;
        secondSwitchedElement = 0;
        lowPos = -1;
        midPos = -1;
        topPos = -1;
        QWidget::repaint();
        ui->comboBox->setDisabled(0);
        ui->pushButton_2->setDisabled(0);
        ui->spinBox->setDisabled(0);
        ui->pushButton_3->setDisabled(0);
    });

    connect(ui->verticalSlider, &QAbstractSlider::valueChanged, this,[this](){
        delay = ui->verticalSlider->value();
        ui->label_4->setText("Delay: " + QString::number(delay)+"ms");
    });

    connect(ui->pushButton_2, &QPushButton::clicked, this,[this](){
        size = ui->spinBox->value();
        ui->pushButton_3->setDisabled(1);
        ui->pushButton_4->setEnabled(0);
        nums.clear();
        for(int i =0; i<size; ++i){
            int a = QRandomGenerator::global()->bounded(1, size+1);
            while (std::find(nums.begin(),nums.end(), a) != nums.end()) {
                a = QRandomGenerator::global()->bounded(1, size+1);
            }
            nums.push_back(a);
        }
        QWidget::repaint();
        ui->pushButton->setDisabled(0);

    });

    connect(ui->pushButton_3, &QPushButton::clicked, this, [this](){
        ui->label_5->setText(QString::number(binarySearch(nums, ui->spinBox_2->value())));
        if(ui->label_5->text().toInt() != -1){
            ui->pushButton_4->setEnabled(1);
        }
    });

    connect(ui->spinBox_2, &QSpinBox::valueChanged, this, [this](){
        ui->pushButton_4->setEnabled(0);
    });

    connect(ui->pushButton_4, &QPushButton::clicked, this, [this](){
        ui->label_6->setText(QString::number(binPow(ui->label_5->text().toInt(),nums.size(), ui->spinBox_2->value())));
    });
}

Widget::~Widget()
{
    delete ui;

}

int Widget::binarySearch(QVector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        lowPos = left;
        midPos = mid;
        topPos = right;
        QEventLoop loop;
        QTimer::singleShot(500, &loop, &QEventLoop::quit);
        loop.exec();
        QWidget::repaint();
        if (arr[mid] == target) {
            lowPos = mid;
            topPos = mid;
            QWidget::repaint();
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    lowPos = -1;
    midPos = -1;
    topPos = -1;
    QWidget::repaint();
    return -1;
}

void Widget::heapify(QVector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;

    if (right < n && arr[right] > arr[largest]) largest = right;
    comparisions+=4;
    arrayAccesses+=4;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        arrayAccesses+=2;
        swaps++;
        sortAnimation(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void Widget::heapSort(QVector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        arrayAccesses+=2;
        swaps++;
        sortAnimation(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void Widget::merge(QVector<int> &arr, int low, int mid, int high)
{
    int left = mid - low + 1;
    int right = high - mid;

    QVector<int> leftArray(left), rightArray(right);

    for (int i = 0; i < left; i++){
        leftArray[i] = arr[low + i];
        arrayAccesses++;
    }
    for (int j = 0; j < right; j++){
        rightArray[j] = arr[mid + 1 + j];
        arrayAccesses++;
    }
    int i = 0;
    int j = 0;
    int k = low;

    while (i < left && j < right) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            arrayAccesses++;
            sortAnimation(arr[k], 0);
            i++;
        } else {
            arr[k] = rightArray[j];
            arrayAccesses++;
            sortAnimation(arr[k], 0);
            j++;
        }
        comparisions++;
        k++;
    }
    while (i < left) {
        arr[k] = leftArray[i];
        arrayAccesses++;
        sortAnimation(arr[k], 0);
        i++;
        k++;
    }

    while (j < right) {
        arr[k] = rightArray[j];
        arrayAccesses++;
        sortAnimation(arr[k], 0);
        j++;
        k++;
    }
}

void Widget::mergeSort(QVector<int>& nums, int low, int high)
{
    if (high > low)
    {
        mergeSort(nums, low, low + ((high - low) / 2));
        mergeSort(nums, low + ((high - low) / 2) + 1, high);
        merge(nums, low, low + ((high - low) / 2), high);
    }
}

void Widget::QSort(QVector<int> &arr, int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot){
            comparisions++;
            arrayAccesses++;
            i++;
        }
        while (arr[j] > pivot){
            comparisions++;
            arrayAccesses++;
            j--;
        }
        if (i <= j) {
            std::swap(arr[i],arr[j]);
            arrayAccesses+=2;
            swaps++;
            sortAnimation(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        QSort(arr, left, j);
    if (i < right)
        QSort(arr, i, right);
}

void Widget::InterpolationSort(QVector<int> &arr)
{
    int start = 0;
    int size = arr.size();
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }
    if (min != max) {
        QVector<QVector<int>> bucket(size);
        int interpolation = 0;
        for (int i = 0; i < size; i++) {
            interpolation = (int)(((double)(arr[i] - min) / (max - min)) * (size - 1));
            bucket[interpolation].push_back(arr[i]);
        }
        for (int i = 0; i < size; i++) {
            if (bucket[i].size() > 1) {
                InterpolationSort(bucket[i]);
            }
            for (size_t j = 0; j < bucket[i].size(); j++) {
                sortAnimation(arr[start], bucket[i][j]);
                arr[start++] = bucket[i][j];
            }
        }
    }
}

int Widget::binPow(int num, int powder, int mod){
    int a = num;
    while(a>=mod){
        a%=mod;
    }
    while(powder!=1){
        a*=num;
        powder--;
        while(a>=mod){
            a%=mod;
        }
    }
    return a;
}

void Widget::sortAnimation(int a, int b){
    firstSwitchedElement = a;
    secondSwitchedElement = b;
    ui->label->setText("Comparisions: " + QString::number(comparisions));
    ui->label_2->setText("Array Accesses: " + QString::number(arrayAccesses));
    ui->label_3->setText("Swaps: " + QString::number(swaps));
    QWidget::repaint();
    QEventLoop loop;
    QTimer::singleShot(delay, &loop, &QEventLoop::quit);
    loop.exec();
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(0,100, 2000, 2000);
    painter.setBrush(QBrush(Qt::white));

    for(int i = 0; i<nums.size(); ++i){
        if(nums[i]==firstSwitchedElement||nums[i]==secondSwitchedElement||(i >= lowPos&& i <=topPos)){
            painter.setBrush(QBrush(Qt::green));
        }
        if(i==midPos){
            painter.setBrush(QBrush(Qt::red));
        }
        painter.drawRect(QRect(i*(1800/size),1000, (1800/size), -(900/size)*nums[i]));
        painter.setBrush(QBrush(Qt::white));
    }
}
