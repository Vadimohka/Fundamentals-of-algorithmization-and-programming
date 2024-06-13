#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    titleLabel(new QLabel("Interpolation Sort", this)),
    inputLabel(new QLabel("Enter a number:", this)),
    inputLineEdit(new QLineEdit(this)),
    addButton(new QPushButton("Add", this)),
    sortButton(new QPushButton("Sort", this)),
    searchButton(new QPushButton("Search", this)),
    tableView(new QTableView(this)),
    model(new QStandardItemModel(this)),
    n(0)
{
    setFixedSize(500,400);
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *gridLayout = new QGridLayout(centralWidget);

    gridLayout->addWidget(titleLabel, 0, 0, 1, 2);
    gridLayout->addWidget(inputLabel, 1, 0);
    gridLayout->addWidget(inputLineEdit, 1, 1);
    gridLayout->addWidget(addButton, 2, 0, 1, 2);
    gridLayout->addWidget(sortButton, 3, 0, 1, 2);
    gridLayout->addWidget(searchButton, 4, 0, 1, 2);
    gridLayout->addWidget(tableView, 5, 0, 1, 2);

    setCentralWidget(centralWidget);

    tableView->setModel(model);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addElement);
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::sortArray);
    connect(searchButton, &QPushButton::clicked, this, &MainWindow::searchIndex);
}


MainWindow::~MainWindow() {}

void MainWindow::addElement()
{
    int value = inputLineEdit->text().toInt();

    if (n >= MAX_ARRAY_SIZE) {
        QMessageBox::warning(this, "Array Full", "Maximum array size reached!");
        return;
    }

    arr[n] = value;
    n++;

    inputLineEdit->clear();

    updateTableModel();
}

void MainWindow::sortArray()
{
    if (n <= 1) {
        QMessageBox::warning(this, "Array Empty", "Insufficient elements to sort!");
        return;
    }

    interpolateSort(0, n - 1);

    updateTableModel();
}

void MainWindow::searchIndex()
{
    int value = inputLineEdit->text().toInt();

    if (n <= 1) {
        QMessageBox::warning(this, "Array Empty", "Insufficient elements to search!");
        return;
    }

    int index = -1;

    int left = 0;
    int right = n - 1;

    while (left <= right && value >= arr[left] && value <= arr[right]) {
        int pos = left + ((value - arr[left]) * (right - left) / (arr[right] - arr[left]));

        if (arr[pos] == value) {
            index = pos;
            break;
        }

        if (arr[pos] < value)
            left = pos + 1;
        else
            right = pos - 1;
    }

    if (index != -1) {
        int mod = n;
        int poweredIndex = binpow(index, n, mod);
        QMessageBox::information(this, "Search Result", QString("Value found at index %1, powered index: %2").arg(index).arg(poweredIndex));
    } else {
        QMessageBox::information(this, "Search Result", "Value not found");
    }
}

void MainWindow::updateTableModel()
{
    model->clear();
    model->setRowCount(n);
    model->setColumnCount(1);

    for (int i = 0; i < n; ++i) {
        QModelIndex index = model->index(i, 0);
        model->setData(index, arr[i]);
    }
}

void MainWindow::interpolateSort(int left, int right)
{
    if (left >= right)
        return;

    int value = arr[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (i <= right && arr[i] < value)
            i++;

        while (j > left && arr[j] >= value)
            j--;

        if (i < j)
            std::swap(arr[i], arr[j]);
    }

    std::swap(arr[left], arr[j]);

    interpolateSort(left, j - 1);
    interpolateSort(j + 1, right);
}

int MainWindow::binpow(int digit, int powder, int mod)
{
    int result = 1;

    while (powder > 0) {
        if (powder & 1)
            result = (result * digit) % mod;

        digit = (digit * digit) % mod;
        powder >>= 1;
    }

    return result;
}
