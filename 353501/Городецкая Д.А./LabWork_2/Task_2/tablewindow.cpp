

#include "tablewindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "mainwindow.h"

TableWindow::TableWindow(QTableWidget* tableWidget, QWidget* parent)
    : QMainWindow(parent), tableWidget(tableWidget)
{

    setCentralWidget(tableWidget);
}

void TableWindow::populateTable()
{
    // Устанавливаем количество строк для таблицы
    int rowCount = qMin(womenList.size(), menList.size());
    tableWidget->setRowCount(rowCount);

    // Заполняем таблицу данными из списков womenList и menList
    for (int row = 0; row < rowCount; ++row) {
        const Women& woman = womenList.at(row);
        const Man& man = menList.at(row);

        QTableWidgetItem* boyItem = new QTableWidgetItem(man.name); // Получаем имя парня
        QTableWidgetItem* girlItem = new QTableWidgetItem(woman.name); // Получаем имя девушки

        tableWidget->setItem(row, 0, boyItem); // Устанавливаем имя парня в первый столбец
        tableWidget->setItem(row, 1, girlItem); // Устанавливаем имя девушки во второй столбец
    }
}

TableWindow::~TableWindow()
{
    // Освобождаем память, выделенную для tableWidget
    delete tableWidget;
}
