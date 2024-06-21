#include <QApplication>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>
#include "pair.h"

void populateTable(QTableWidget* table, const std::vector<int>& data) {
    table->setRowCount(data.size());
    table->setColumnCount(1);
    for (size_t i = 0; i < data.size(); ++i) {
        table->setItem(i, 0, new QTableWidgetItem(QString::number(data[i])));
    }
}

void populateTable(QTableWidget* table, const std::vector<Pair<int, double>>& data) {
    table->setRowCount(data.size());
    table->setColumnCount(2);
    for (size_t i = 0; i < data.size(); ++i) {
        table->setItem(i, 0, new QTableWidgetItem(QString::number(data[i].first)));
        table->setItem(i, 1, new QTableWidgetItem(QString::number(data[i].second)));
    }
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    std::vector<Pair<std::vector<int>, std::vector<Pair<int, double>>>> container;

    // Пример заполнения данными
    std::vector<int> intVector = {1, 2, 3, 4, 5};
    std::vector<Pair<int, double>> pairVector = {{1, 1.1}, {2, 2.2}, {3, 3.3}, {4, 4.4}, {5, 5.5}};
    Pair<std::vector<int>, std::vector<Pair<int, double>>> myPair(intVector, pairVector);
    container.push_back(myPair);

    QWidget window;
    QVBoxLayout* layout = new QVBoxLayout;

    QTableWidget* intTable = new QTableWidget;
    QTableWidget* pairTable = new QTableWidget;

    layout->addWidget(intTable);
    layout->addWidget(pairTable);

    window.setLayout(layout);
    window.setWindowTitle("Matrix Display");

    if (!container.empty()) {
        populateTable(intTable, container[0].first);
        populateTable(pairTable, container[0].second);
    }

    window.show();
    return app.exec();
}
