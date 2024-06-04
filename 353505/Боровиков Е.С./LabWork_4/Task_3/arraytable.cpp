#include "arraytable.h"
#include "ui_arraytable.h"

#include <QPushButton>

void ArrayTable::setVector(const QVector<float> &newVector) {
    _data = newVector;
    showVect();
}

int ArrayTable::vectSize() const {

    return _data.size();
}

void ArrayTable::setReadOnly(bool status) {
    _isReadOnly = status;

    ui->indexSpinBox->setReadOnly(_isReadOnly);
    ui->valueSpinBox->setReadOnly(_isReadOnly);
    ui->sizeSpinBox->setReadOnly(_isReadOnly);
    ui->randPushButton->setEnabled(!_isReadOnly);
}

bool ArrayTable::readOnly() const {
    return _isReadOnly;
}

void ArrayTable::setTableOnly(bool status) {
    _isTableOnly = status;

    if (_isTableOnly) {
        ui->indexSpinBox->hide();
        ui->valueSpinBox->hide();
        ui->sizeSpinBox->hide();
        ui->randPushButton->hide();
        ui->sizeLabel->hide();
        ui->valueLabel->hide();
        ui->indexLabel->hide();
    } else {
        ui->indexSpinBox->show();
        ui->valueSpinBox->show();
        ui->sizeSpinBox->show();
        ui->randPushButton->show();
        ui->sizeLabel->show();
        ui->valueLabel->show();
        ui->indexLabel->show();
    }
}

bool ArrayTable::tableOnly() const {
    return _isTableOnly;
}

ArrayTable::ArrayTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ArrayTable)
{
    ui->setupUi(this);

    connect(ui->sizeSpinBox, SIGNAL(valueChanged(int)), SLOT(slotResizeArray(int)));
    connect(ui->valueSpinBox, SIGNAL(valueChanged(double)), SLOT(slotChangeElement(double)));
    connect(ui->randPushButton, SIGNAL(clicked(bool)), SLOT(slotRandomiseValues()));

    ui->valueSpinBox->setMinimum(INT_MIN);
    ui->valueSpinBox->setMaximum(INT_MAX);
    ui->sizeSpinBox->setMinimum(1);
    ui->sizeSpinBox->setMaximum(MAX_SIZE);
    _data.resize(1);
    _data[0] = 0;
    showVect();
}

ArrayTable::~ArrayTable() {
    delete ui;
}

QVector<float> ArrayTable::vector() const {
    return _data;
}

void ArrayTable::resizeEvent(QResizeEvent *event)
{
    showVect();
    QWidget::resizeEvent(event);
}

void ArrayTable::showVect() {
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width());
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(_data.size());
    for (int i = 0; i < _data.size(); ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(_data.at(i)));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->tableWidget->setItem(0, i, item);
    }
}

void ArrayTable::slotResizeArray(int newSize) {
    _data.resize(newSize);

    ui->indexSpinBox->setMaximum(_data.size() - 1);
    emit vectorChanged();
    showVect();
}

void ArrayTable::slotChangeElement(double newValue) {
    int index = ui->indexSpinBox->value();
    _data[index] = newValue;

    QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(newValue));
    ui->tableWidget->setItem(index, 0, newItem);

    emit vectorChanged();
}

void ArrayTable::slotRandomiseValues() {
    for (float &i : _data) {
        i = QRandomGenerator::global()->bounded(_data.size() * 2) +
            QRandomGenerator::global()->bounded(RAND_PRECISION) / static_cast<float>(RAND_PRECISION);
    }
    emit vectorChanged();
    showVect();
}
