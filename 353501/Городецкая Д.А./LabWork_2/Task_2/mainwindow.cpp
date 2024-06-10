#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tablewindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTableWidget>
#include "heightrange.h"
#include "weightrange.h"
#include "agerange.h"
#include "man.h"
#include "women.h"
#include <QList>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openButton = new QPushButton("Open File", this);
    connect(openButton, &QPushButton::clicked, this, &MainWindow::openFile);

    QPushButton *openTableButton = new QPushButton("Open Table", this);
    connect(openTableButton, &QPushButton::clicked, this, &MainWindow::openTableWindow);

    QPushButton *addButton = new QPushButton("Add Person", this);
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addField);
    QPushButton *deleteButton = new QPushButton("Delete Person", this);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::deleteField);
    // Добавляем кнопку в вертикальный слой
    ui->verticalLayout->addWidget(openTableButton);

    // Add the openButton to the layout
    ui->verticalLayout->addWidget(openButton);

    // Initialize the tableWidget
    ui->tableWidget->setColumnCount(11);
    ui->tableWidget->setHorizontalHeaderLabels({"Gender", "Serial Number", "Name", "Age", "Height", "Weight", "Habits", "Hobbies", "Age Range", "Height Range", "Weight Range"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::readParametersFromFile(const QString& filePath, QList<Women>& womenList, QList<Man>& menList)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    int serialNumber = 1;  // Initial serial number
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList params = line.split(',');

        if (params.size() < 13)
            continue;

        QString gender = params[0].trimmed();
        QString name = params[1].trimmed();
        int age = params[2].toInt();
        int height = params[3].toInt();
        int weight = params[4].toInt();
        QString habits = params[5].trimmed();
        QString hobbies = params[6].trimmed();
        int minAge = params[7].toInt();
        int maxAge = params[8].toInt();
        int minHeight = params[9].toInt();
        int maxHeight = params[10].toInt();
        int minWeight = params[11].toInt();
        int maxWeight = params[12].toInt();

        if (gender.compare("Women", Qt::CaseInsensitive) == 0) {
            womenList.append(Women(serialNumber, name, age, height, weight, habits, hobbies, {minAge, maxAge}, {minHeight, maxHeight}, {minWeight, maxWeight}));
        } else if (gender.compare("Men", Qt::CaseInsensitive) == 0) {
            menList.append(Man(serialNumber, name, age, height, weight, habits, hobbies, {minAge, maxAge}, {minHeight, maxHeight}, {minWeight, maxWeight}));
        }

        serialNumber++;
    }

    file.close();
    return true;
}

void MainWindow::fillRow(QTableWidget* tableWidget, int row, const Women& woman, const QString& gender)
{
    tableWidget->setItem(row, 0, new QTableWidgetItem(gender));
    tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(woman.serialNumber)));
    tableWidget->setItem(row, 2, new QTableWidgetItem(woman.name));
    tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(woman.age)));
    tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(woman.height)));
    tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(woman.weight)));
    tableWidget->setItem(row, 6, new QTableWidgetItem(woman.habits));
    tableWidget->setItem(row, 7, new QTableWidgetItem(woman.hobbies));
    tableWidget->setItem(row, 8, new QTableWidgetItem(QString("%1-%2").arg(woman.ageRange.minAge).arg(woman.ageRange.maxAge)));
    tableWidget->setItem(row, 9, new QTableWidgetItem(QString("%1-%2").arg(woman.heightRange.minHeight).arg(woman.heightRange.maxHeight)));
    tableWidget->setItem(row, 10, new QTableWidgetItem(QString("%1-%2").arg(woman.weightRange.minWeight).arg(woman.weightRange.maxWeight)));
}


void MainWindow::fillRow(QTableWidget* tableWidget, int row, const Man& man, const QString& gender)
{
    tableWidget->setItem(row, 0, new QTableWidgetItem(gender));
    tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(man.serialNumber)));
    tableWidget->setItem(row, 2, new QTableWidgetItem(man.name));
    tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(man.age)));
    tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(man.height)));
    tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(man.weight)));
    tableWidget->setItem(row, 6, new QTableWidgetItem(man.habits));
    tableWidget->setItem(row, 7, new QTableWidgetItem(man.hobbies));
    tableWidget->setItem(row, 8, new QTableWidgetItem(QString("%1-%2").arg(man.ageRange.minAge).arg(man.ageRange.maxAge)));
    tableWidget->setItem(row, 9, new QTableWidgetItem(QString("%1-%2").arg(man.heightRange.minHeight).arg(man.heightRange.maxHeight)));
    tableWidget->setItem(row, 10, new QTableWidgetItem(QString("%1-%2").arg(man.weightRange.minWeight).arg(man.weightRange.maxWeight)));
}

void MainWindow::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open File");
    if (!filePath.isEmpty()) {
        womenList.clear();
        menList.clear();

        if (readParametersFromFile(filePath, womenList, menList)) {
            // Clear the table
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);

            int row = 0;
            for (const Women& woman : womenList) {
                ui->tableWidget->insertRow(row);
                fillRow(ui->tableWidget, row, woman, "Women");
                row++;
            }

            for (const Man& man : menList) {
                ui->tableWidget->insertRow(row);
                fillRow(ui->tableWidget, row, man, "Men");
                row++;
            }

            QMessageBox::information(this, "File Opened", "File opened successfully.");
        } else {
            QMessageBox::warning(this, "Error", "Failed to open file.");
        }
    }
}

void MainWindow::openTableWindow()
{

    // Найдите совместимые пары
    QList<QPair<Women, Man>> matchingPairs = findMatchingPairs(womenList, menList);

    // Создайте объект QTableWidget
    QTableWidget* tableWidget = new QTableWidget(this);

    // Устанавливаем количество столбцов для таблицы
    tableWidget->setColumnCount(2);

    // Устанавливаем заголовки для таблицы
    tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Парень"));
    tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Девушка"));

    // Заполняем таблицу данными из списка пар
    tableWidget->setRowCount(matchingPairs.size());
    for (int row = 0; row < matchingPairs.size(); ++row) {
        const QPair<Women, Man>& pair = matchingPairs.at(row);
        QTableWidgetItem* boyItem = new QTableWidgetItem(pair.second.name); // Получаем имя парня
        QTableWidgetItem* girlItem = new QTableWidgetItem(pair.first.name); // Получаем имя девушки
        tableWidget->setItem(row, 0, boyItem); // Устанавливаем имя парня в первый столбец
        tableWidget->setItem(row, 1, girlItem); // Устанавливаем имя девушки во второй столбец
    }

    // Устанавливаем свойства таблицы
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // Создаем окно таблицы и передаем список совместимых пар
    TableWindow* tableWindow = new TableWindow(tableWidget, this);
    tableWindow->show();
}

bool MainWindow::meetPartnerRequirements(const Man& man, const Women& woman)
{
    if (man.age < woman.ageRange.minAge || man.age > woman.ageRange.maxAge) {
        return false;
    }

    if (man.height < woman.heightRange.minHeight || man.height > woman.heightRange.maxHeight) {
        return false;
    }

    if (man.weight < woman.weightRange.minWeight || man.weight > woman.weightRange.maxWeight) {
        return false;
    }

    return true;
}

bool MainWindow::meetPartnerRequirements(const Women& woman, const Man& man)
{
    if (woman.age < man.ageRange.minAge || woman.age > man.ageRange.maxAge) {
        return false;
    }

    if (woman.height < man.heightRange.minHeight || woman.height > man.heightRange.maxHeight) {
        return false;
    }

    if (woman.weight < man.weightRange.minWeight || woman.weight > man.weightRange.maxWeight) {
        return false;
    }

    return true;
}



QList<QPair<Women, Man>> MainWindow::findMatchingPairs(const QList<Women>& womenList, const QList<Man>& menList)
{

    QList<Women> remainingWomen = womenList;
    QList<Man> remainingMen = menList;

    QList<QPair<Women, Man>> matchingPairs;
    for(int i = 0; i < remainingMen.count(); i++) {
        Man men = remainingMen[i];
        int found_women = -1;
        for(int j = 0; j < remainingWomen.count(); j++) {
            if(!meetPartnerRequirements(men, remainingWomen[i])) continue;
            if(!meetPartnerRequirements(remainingWomen[i], men)) continue;
            found_women = j;
            break;
        }
        if(found_women == -1) continue;
        matchingPairs.push_back({remainingWomen[i], remainingMen[i]});
        remainingMen.removeAt(i);
        remainingWomen.removeAt(found_women);
        i--;
    }


    return matchingPairs;

}
void MainWindow::addField()
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rowCount + 1);

    int columnCount = ui->tableWidget->columnCount();
    for (int column = 0; column < columnCount; ++column)
    {
        QTableWidgetItem* item = new QTableWidgetItem();
        ui->tableWidget->setItem(rowCount, column, item);
    }
}

void MainWindow::deleteField()
{
    int selectedRow = ui->tableWidget->currentRow();
    if (selectedRow != -1)
    {
        ui->tableWidget->removeRow(selectedRow);
    }
}
void MainWindow::on_addButton_clicked()
{
    addField();
}
void MainWindow::on_deleteButton_clicked()
{
    deleteField();
}
