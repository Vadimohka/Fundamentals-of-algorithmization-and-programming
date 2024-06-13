#include "itemmodel.h"

ItemModel::ItemModel() : QStandardItemModel()
{
    for(int i = 0; i < NumberOfRows; i++)
    {
        for(int j = 0; j < NumberOfColumns; j++)
        {
            //QString cellText = QString("Data %1-%2").arg(i + 1).arg(j + 1);
            //QString cellText = QString("%1%2").arg(i + 1).arg(j + 1);
            Item* cell = new Item();
            //QBrush brush(Qt::white);
            //cell->setBackground(brush);
            this->setItem(i, j, cell);
        }
    }
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        this->setHeaderData(i, Qt::Horizontal, QString(char(i + 65)));
    }
}

void ItemModel::saveTableInFile(QWidget* widget)
{
    QString filePath = QFileDialog::getSaveFileName(widget, "Сохранить таблицу", "", "CSV файл (*.csv)");
    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }

    QTextStream out(&file);

    // Сохранение заголовков столбцов
    for (int column = 0; column < this->columnCount(); ++column) {
        if(column == this->columnCount() - 1)
        {
            QString headerText = this->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
            out << headerText;
            continue;
        }
        QString headerText = this->headerData(column, Qt::Horizontal, Qt::DisplayRole).toString();
        out << headerText << ",";
    }
    out << "\n";

    out << NumberOfColumns << "," << NumberOfRows << "\n";

    // Сохранение данных ячеек
    for (int row = 0; row < this->rowCount(); ++row) {
        for (int column = 0; column < this->columnCount(); ++column) {
            QModelIndex cellIndex = this->index(row, column);
            QStandardItem* item = this->itemFromIndex(cellIndex);
            QVariant textColorValue = this->data(cellIndex, Qt::ForegroundRole);
            QColor textColor = textColorValue.value<QColor>();
            QString cellText = item->text();
            QFont font = item->font();
            if(item->background().color() == QColor(0, 0, 0))
            {
                QBrush brush(Qt::white);
                item->setBackground(brush);
            }

            QColor backgroundColor = item->background().color();
            qDebug() << item->background().color();
            item->setBackground(item->background().color());
            qDebug() << backgroundColor;

            out << row << ","
                << column << ","
                << cellText << ","
                << font.family() << ","
                << font.pointSize() << ","
                << font.bold() << ","
                << font.italic() << ","
                << textColor.red() << ","
                << textColor.blue() << ","
                << textColor.green() << ","
                << backgroundColor.red()<< ","
                << backgroundColor.green()<< ","
                << backgroundColor.blue();

            out << "\n";
        }
    }
    //NumberOfColumns = this->columnCount();
    //NumberOfRows = this->rowCount();
    file.close();
    qDebug() << "Таблица сохранена в файл:" << filePath;
}

void ItemModel::loadTableFromFile(QWidget* widget)
{
    QString filePath = QFileDialog::getOpenFileName(widget, "Загрузить таблицу", "", "CSV файл (*.csv)");
    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading:" << file.errorString();
        return;
    }

    QTextStream in(&file);

    // Очистка существующей модели данных
    this->clear();

    // Загрузка заголовков столбцов
    QString headerLine = in.readLine();

    QStringList headers = headerLine.split(",");
    this->setHorizontalHeaderLabels(headers);
    qDebug() << "model rows: " << this->NumberOfRows;
    qDebug() << "model columns: " << this->NumberOfColumns;

    QString count = in.readLine();

    QStringList counts = count.split(",");

    this->NumberOfColumns = counts.at(0).toInt();
    this->NumberOfRows = counts.at(1).toInt();

    // Загрузка данных ячеек
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList data = line.split(",");
        QString cellText = data.at(2);

        QString fontFamily = data.at(3);

        int fontSize = data.at(4).toInt();

        bool isBold = data.at(5).toInt();

        bool isItalic = data.at(6).toInt();

        int redText = data.at(7).toInt();

        int greenText = data.at(9).toInt();

        int blueText = data.at(8).toInt();

        int red = data.at(10).toInt();

        int green = data.at(11).toInt();

        int blue = data.at(12).toInt();


        Item* item = new Item(cellText);
        QFont font(fontFamily, fontSize);

        font.setBold(isBold);
        font.setItalic(isItalic);
        item->setData(QColor(redText, greenText, blueText), Qt::ForegroundRole);
        item->setFont(font);
        item->setBackground(QColor(red, green, blue));
        this->setItem(data.at(0).toInt(), data.at(1).toInt(), item);
    }
    file.close();
    qDebug() << "Таблица загружена из файла:" << filePath;
}

void ItemModel::getSumOfCells(QModelIndexList selectedIndexes, QModelIndex selectedCell)
{
    QList<double> values;
    for (const QModelIndex& index : selectedIndexes) {
        bool ok;
        double value = this->itemData(index).value(0).toDouble(&ok);
        if (ok) {
            values.append(value);
        }
    }

    double result = Function::sumFunction(values);
    this->setData(selectedCell, result);
}

void ItemModel::getMultOfCells(QModelIndexList selectedIndexes, QModelIndex selectedCell)
{
    QList<double> values;
    for (const QModelIndex& index : selectedIndexes) {
        bool ok;
        double value = this->itemData(index).value(0).toDouble(&ok);
        if (ok) {
            values.append(value);
        }
    }

    double result = Function::multFunction(values);
    this->setData(selectedCell, result);
}

void ItemModel::getAverageOfCells(QModelIndexList selectedIndexes, QModelIndex selectedCell)
{
    QList<double> values;
    for (const QModelIndex& index : selectedIndexes) {
        bool ok;
        double value = this->itemData(index).value(0).toDouble(&ok);
        if (ok) {
            values.append(value);
        }
    }

    double result = Function::averageFunction(values);
    this->setData(selectedCell, result);
}

QList<QList<QString>> ItemModel::ascendingGnomeSort(QList<QList<QString>> range, int sortingColumn)
{
    int n = range.size();
    int pos = 0;

    while (pos < n) {
        if (pos == 0 || range[pos][sortingColumn].toInt() >= range[pos - 1][sortingColumn].toInt()) {
            pos++;
        } else {
            std::swap(range[pos], range[pos - 1]);
            pos--;
        }
    }
    qDebug() << range;
    return range;
}

QList<QList<QString>> ItemModel::descendingGnomeSort(QList<QList<QString>> range, int sortingColumn)
{
    int n = range.size();
    int pos = 0;

    while (pos < n) {
        if (pos == 0 || range[pos][sortingColumn].toInt() <= range[pos - 1][sortingColumn].toInt()) {
            pos++;
        } else {
            std::swap(range[pos], range[pos - 1]);
            pos--;
        }
    }
    return range;
}

QList<QList<QString>> ItemModel::ascendingCombSort(QList<QList<QString>> range, int sortingColumn)
{
    int n = range.size();
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        swapped = false;
        for (int i = 0; i < n - gap; ++i) {
            if (range[i][sortingColumn] > range[i + gap][sortingColumn]) {
                std::swap(range[i], range[i + gap]);
                swapped = true;
            }
        }
    }
    return range;
}

QList<QList<QString>> ItemModel::descendingCombSort(QList<QList<QString>> range, int sortingColumn)
{
    int n = range.size();
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        swapped = false;
        for (int i = 0; i < n - gap; ++i) {
            if (range[i][sortingColumn] < range[i + gap][sortingColumn]) {
                std::swap(range[i], range[i + gap]);
                swapped = true;
            }
        }
    }
    return range;
}

void ItemModel::getRandomValue(QModelIndexList selectedIndexes)
{
    QVector<long long> values = Function::randomFunction(selectedIndexes.size());
    int i = 0;
    for(auto index : selectedIndexes)
    {
        long long result = values[i];
        i++;
        this->setData(index, result);
    }
}

void ItemModel::addColumn()
{
    if(NumberOfColumns >= 26)
    {
        this->insertColumn(NumberOfColumns);
        this->setHeaderData(NumberOfColumns, Qt::Horizontal, QString(char(NumberOfColumns / 26 + 64)) + QString(char(NumberOfColumns % 26 + 65)));
    }
    else
    {
        this->insertColumn(NumberOfColumns);
        this->setHeaderData(NumberOfColumns, Qt::Horizontal, QString(char(NumberOfColumns + 65)));
    }
    for(int i = 0; i < NumberOfRows; ++i)
    {
        Item* cell = new Item("");
        QBrush brush(Qt::white);
        cell->setBackground(brush);
        this->setItem(i, NumberOfColumns, cell);

    }
    NumberOfColumns++;
}

void ItemModel::addRow()
{
    this->insertRow(NumberOfRows);
    this->setVerticalHeaderItem(NumberOfRows, new QStandardItem(QString("%1").arg(NumberOfRows + 1)));
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        Item* cell = new Item("");
        QBrush brush(Qt::white);
        cell->setBackground(brush);
        this->setItem(NumberOfRows, i, cell);
    }
    NumberOfRows++;
}

void ItemModel::deleteRow()
{
    if(NumberOfRows > 0)
    {
        this->removeRow(--NumberOfRows);
    }

}

void ItemModel::deleteColumn()
{
    if(NumberOfColumns > 0)
    {
        this->removeColumn(--NumberOfColumns);
    }

}
