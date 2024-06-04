#include "arraytable.h"
#include "ui_arraytable.h"

int *ArrayTable::array() const {
    return _array;
}

void ArrayTable::setArray(int *newArray, int newArrSize) {
    _array = newArray;
    slotResizeArray(newArrSize);
}

int ArrayTable::arrSize() const {
    return _arrSize;
}

void ArrayTable::setReadOnly(bool status) {
    _isReadOnly = status;

    ui->indexSpinBox->setReadOnly(_isReadOnly);
    ui->valueSpinBox->setReadOnly(_isReadOnly);
    ui->sizeSpinBox->setReadOnly(_isReadOnly);
    ui->randPushButton->setEnabled(!_isReadOnly);
}

bool ArrayTable::readOnle() const {
    return _isReadOnly;
}

ArrayTable::ArrayTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ArrayTable)
{
    ui->setupUi(this);

    connect(ui->sizeSpinBox, SIGNAL(valueChanged(int)), SLOT(slotResizeArray(int)));
    connect(ui->valueSpinBox, SIGNAL(valueChanged(int)), SLOT(slotChangeElement(int)));
    connect(ui->randPushButton, SIGNAL(clicked(bool)), SLOT(slotRandomiseValues()));

    ui->valueSpinBox->setMinimum(INT_MIN);
    ui->valueSpinBox->setMaximum(INT_MAX);
    ui->sizeSpinBox->setMinimum(1);
    ui->sizeSpinBox->setMaximum(MAX_SIZE);
    slotResizeArray(1);
    _array[0] = 0;
    showArray();
}

ArrayTable::~ArrayTable() {
    delete ui;
    delete[] _array;
}

void ArrayTable::resizeEvent(QResizeEvent *event)
{
    showArray();
    QWidget::resizeEvent(event);
}

void ArrayTable::showArray() {
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width());
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(_arrSize);
    for (int i = 0; i < _arrSize; ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(_array[i]));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->tableWidget->setItem(0, i, item);
    }
}

void ArrayTable::slotResizeArray(int newSize) {
    if (newSize > _capacity) {
        int* newArr = new int[newSize];
        for (int i = 0; i < _arrSize; ++i) {
            newArr[i] = _array[i];
        }
        for (int i = _arrSize; i < newSize; ++i) {
            newArr[i] = 0;
        }
        delete[] _array;
        _array = newArr;
        _capacity = newSize;
    }
    if (newSize < _capacity) {
        for (int i = newSize; i < _arrSize; ++i) {
            _array[i] = 0;
        }
    }
    _arrSize = newSize;

    ui->indexSpinBox->setMaximum(_arrSize - 1);
    emit arrayChanged();
    showArray();
}

void ArrayTable::slotChangeElement(int newValue) {
    int index = ui->indexSpinBox->value();
    _array[index] = newValue;

    QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(newValue));
    ui->tableWidget->setItem(index, 0, newItem);

    emit arrayChanged();
}

void ArrayTable::slotRandomiseValues() {
    sorted = false;
    for (int i = 0; i < _arrSize; ++i)
    {
        _array[i] = QRandomGenerator::global()->bounded(_arrSize * 2);
    }
    emit arrayChanged();
    showArray();
}
