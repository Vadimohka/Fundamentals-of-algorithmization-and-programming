#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include "Vector.h"
#include "Pair.h"

void displayMatrix(const Vector<int>& vec, QTableWidget* table) {
    table->setRowCount(vec.size());
    table->setColumnCount(1);

    for (size_t i = 0; i < vec.size(); ++i) {
        QTableWidgetItem* item = new QTableWidgetItem(QString::number(vec.at(i)));
        table->setItem(i, 0, item);
    }
}

void displayMatrix(const Vector<Pair<int, double>>& vec, QTableWidget* table) {
    table->setRowCount(vec.size());
    table->setColumnCount(2);

    for (size_t i = 0; i < vec.size(); ++i) {
        QTableWidgetItem* item1 = new QTableWidgetItem(QString::number(vec.at(i).first));
        QTableWidgetItem* item2 = new QTableWidgetItem(QString::number(vec.at(i).second));
        table->setItem(i, 0, item1);
        table->setItem(i, 1, item2);
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Vector Pair Example");

    QVBoxLayout* layout = new QVBoxLayout();

    // Создание вектора, содержащего пары векторов
    Vector<Pair<Vector<int>, Vector<Pair<int, double>>>> vectorOfPairs;
    Vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    Vector<Pair<int, double>> vec2;
    vec2.push_back(Pair<int, double>(4, 4.1));
    vec2.push_back(Pair<int, double>(5, 5.1));
    vec2.push_back(Pair<int, double>(6, 6.1));

    vectorOfPairs.push_back(Pair<Vector<int>, Vector<Pair<int, double>>>(vec1, vec2));

    QLabel* label1 = new QLabel("Matrix 1 (vector<int>):");
    layout->addWidget(label1);

    QTableWidget* table1 = new QTableWidget();
    displayMatrix(vectorOfPairs.at(0).first, table1);
    layout->addWidget(table1);

    QLabel* label2 = new QLabel("Matrix 2 (vector<pair<int, double>>):");
    layout->addWidget(label2);

    QTableWidget* table2 = new QTableWidget();
    displayMatrix(vectorOfPairs.at(0).second, table2);
    layout->addWidget(table2);

    window.setLayout(layout);
    window.show();

    return app.exec();
}
