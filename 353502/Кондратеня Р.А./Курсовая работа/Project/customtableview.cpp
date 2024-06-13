#include "customtableview.h"

CustomTableView::CustomTableView(QWidget *parent) : QTableView(parent)
{

}

ItemModel* CustomTableView::getModel()
{
    return qobject_cast<ItemModel*>(this->model());
}

void CustomTableView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        selectedCell = indexAt(event->pos());
        if (selectedCell.isValid()) {
            // Определена действия для правой кнопки мыши
            QMenu menu(this);
            QAction* summOfCells = menu.addAction("Sum");
            QAction* multiplicationOfCells = menu.addAction("Multiplication");
            QAction* averageOfCells = menu.addAction("Average");
            QAction* getRandomValue = menu.addAction("Random");
            QAction* selectedItem = menu.exec(event->globalPos());
            if (selectedItem == summOfCells) {
                QMessageBox::information(this, "ContextMenu", "Выберите диапазон ячеек.");

                action = "sum";
                qDebug() << "sum";
            }
            if (selectedItem == multiplicationOfCells) {
                QMessageBox::information(this, "ContextMenu", "Выберите диапазон ячеек.");

                action = "mult";
                qDebug() << "mult";
            }
            if (selectedItem == averageOfCells) {
                QMessageBox::information(this, "ContextMenu", "Выберите диапазон ячеек.");

                action = "avg";
                qDebug() << "sum";
            }
            if (selectedItem == getRandomValue) {
                QMessageBox::information(this, "ContextMenu", "Выберите диапазон ячеек.");
                action = "rand";
                qDebug() << "rand";
            }
        }
    }
    QTableView::mousePressEvent(event);
}

void CustomTableView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return) {
        if(action == "sum")
        {
            selectedIndexes = this->selectionModel()->selectedIndexes();
            if(!isValues(selectedIndexes))
            {
                QMessageBox::information(nullptr, "Ошибка", "Проверьте корректность выделенных данных");
                setAction("nothing");
                return;
            }
            this->getModel()->getSumOfCells(selectedIndexes, selectedCell);
            setAction("nothing");
        }
        if(action == "mult")
        {
            selectedIndexes = this->selectionModel()->selectedIndexes();
            if(!isValues(selectedIndexes))
            {
                QMessageBox::information(nullptr, "Ошибка", "Проверьте корректность выделенных данных");
                setAction("nothing");
                return;
            }
            this->getModel()->getMultOfCells(selectedIndexes, selectedCell);
            setAction("nothing");
        }
        if(action == "avg")
        {
            selectedIndexes = this->selectionModel()->selectedIndexes();
            if(!isValues(selectedIndexes))
            {
                QMessageBox::information(nullptr, "Ошибка", "Проверьте корректность выделенных данных");
                setAction("nothing");
                return;
            }
            this->getModel()->getAverageOfCells(selectedIndexes, selectedCell);
            setAction("nothing");
        }
        if(action == "rand")
        {
            selectedIndexes = this->selectionModel()->selectedIndexes();
            this->getModel()->getRandomValue(selectedIndexes);
            setAction("nothing");
        }
        if(action == "BarDiagram")
        {
            selectedIndexes = this->selectionModel()->selectedIndexes();
            buildLineDiagram(selectedIndexes);
            setAction("nothing");
        }
        if(action == "Graphic")
        {
            selectedIndexes = this->selectionModel()->selectedIndexes();
            buildGraphic(selectedIndexes);
            setAction("nothing");
        }
        if(action == "PieDiagram")
        {
            selectedIndexes = this->selectionModel()->selectedIndexes();
            buildPieDiagram(selectedIndexes);
            setAction("nothing");
        }
        if(action == "AscendingGnomeSort")
        {
            selectedIndexes = this->selectionModel()->selectedIndexes();
            sortSelectedRange();
            setAction("nothing");
        }
        if(action == "DescendingGnomeSort")
        {
            selectedIndexes = this->selectionModel()->selectedIndexes();
            sortSelectedRange();
            setAction("nothing");
        }
        if(action == "AscendingCombSort")
        {
            selectedIndexes = this->selectionModel()->selectedIndexes();
            sortSelectedRange();
            setAction("nothing");
        }
        if(action == "DescendingCombSort")
        {
            selectedIndexes = this->selectionModel()->selectedIndexes();
            sortSelectedRange();
            setAction("nothing");
        }
    } else {
        QTableView::keyPressEvent(event);
    }
}

void CustomTableView::buildLineDiagram(QModelIndexList selectedIndexes)
{
    ItemModel* model = getModel();
    QChart* chart = new QChart();
    QChartView* chartView = new QChartView(chart);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    QValueAxis *axisY = new QValueAxis();
    axisX->setTitleText("Категории");
    axisY->setTitleText("Значения");
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    QBarSet* barSet;
    QBarSeries* barSeries = new QBarSeries();

    QModelIndex firstIndex = selectedIndexes.first();
    QModelIndex lastIndex = selectedIndexes.last();

    int firstRow = firstIndex.row();
    int firstColumn = firstIndex.column();
    int lastRow = lastIndex.row();
    int lastColumn = lastIndex.column();

    if(!checkCorrectInputForLineDiagram(selectedIndexes))
        return;

    for(int col = firstColumn; col <= lastColumn; ++col)
    {
        QModelIndex index = model->index(firstRow, col);
        QString name = model->data(index).toString();
        barSet = new QBarSet(name);
        for( int row = firstRow + 1; row <= lastRow; ++row)
        {
            QModelIndex index1 = model->index(row, col);
            QVariant data = model->data(index1);
            double value = data.toDouble();
            *barSet << value;
        }
        barSeries->append(barSet);
    }
//    for(int i = firstRow + 1; i <= lastRow; ++i)
//    {
//        QModelIndex index = model->index(i, firstColumn);
//        QString data = model->data(index).toString();
//        axisX->append(data);
//    }
    chart->addSeries(barSeries);
    barSeries->attachAxis(axisX);
    barSeries->attachAxis(axisY);

    QLegend *legend = chart->legend();
    legend->setVisible(true);
    legend->setAlignment(Qt::AlignBottom);

    // Создание виджета для отображения диаграммы
    chartView->setRenderHint(QPainter::Antialiasing);

    // Создание главного окна и размещение виджета диаграммы в нем
    QMainWindow* window = new QMainWindow;
    window->setCentralWidget(chartView);
    window->resize(400, 300);
    window->show();
}

void CustomTableView::buildGraphic(QModelIndexList selectedIndexes)
{
    ItemModel* model = getModel();
    QChart* chart = new QChart();
    QChartView* chartView = new QChartView(chart);

    QLineSeries* series;

    QModelIndex firstIndex = selectedIndexes.first();
    QModelIndex lastIndex = selectedIndexes.last();

    if(!checkCorrectInputForGraphic(selectedIndexes))
        return;

    int firstRow = firstIndex.row();
    int firstColumn = firstIndex.column();
    int lastRow = lastIndex.row();
    int lastColumn = lastIndex.column();

    for(int col = firstColumn + 1; col <= lastColumn; ++col)
    {
        series = new QLineSeries;
        QModelIndex index = model->index(firstRow, col);
        QString name = model->data(index).toString();
        series->setName(name);
        for(int row = firstRow + 1; row <= lastRow; ++row)
        {
            QModelIndex x_index = model->index(row, firstColumn);
            QModelIndex y_index = model->index(row, col);

            QVariant x_data = model->data(x_index);
            QVariant y_data = model->data(y_index);

            double x_value = x_data.toDouble();
            double y_value = y_data.toDouble();
            series->append(x_value, y_value);
        }
        chart->addSeries(series);
    }
    chart->createDefaultAxes();

    QMainWindow* window = new QMainWindow;
    window->setCentralWidget(chartView);
    window->resize(400, 300);
    window->show();
}

void CustomTableView::buildPieDiagram(QModelIndexList selectedIndexes)
{
    ItemModel* model = getModel();
    QChart* chart = new QChart();
    QChartView* chartView = new QChartView(chart);

    QPieSeries* series = new QPieSeries;

    QModelIndex firstIndex = selectedIndexes.first();
    QModelIndex lastIndex = selectedIndexes.last();

    if(!checkCorrectInputForPieDiagram(selectedIndexes))
    {
        return;
    }

    int firstRow = firstIndex.row();
    int firstColumn = firstIndex.column();
    int lastRow = lastIndex.row();
    int lastColumn = lastIndex.column();

    for(int col = firstColumn; col <= lastColumn; ++col)
    {
        QModelIndex name_index = model->index(firstRow, col);
        QModelIndex value_index = model->index(lastRow, col);

        QVariant name_data = model->data(name_index);
        QVariant value_data = model->data(value_index);

        QString name_value = name_data.toString();
        double value = value_data.toDouble();

        series->append(name_value, value);
    }

    chart->addSeries(series);

    QMainWindow* window = new QMainWindow;
    window->setCentralWidget(chartView);
    window->resize(400, 300);
    window->show();
}

void CustomTableView::setAction(QString action)
{
    this->action = action;
}

void CustomTableView::sortSelectedRange() {
    QItemSelectionModel *selectionModel = this->selectionModel();
    if (!selectionModel->hasSelection()) {
        return;
    }

    QModelIndexList selectedIndexes = selectionModel->selectedIndexes();
    if (selectedIndexes.isEmpty()) {
        return;
    }

    // Получаем верхнюю и нижнюю границы выделения
    int minRow = selectedIndexes.first().row();
    int maxRow = selectedIndexes.last().row();

    // Получаем столбец, по которому будем сортировать (первый выделенный столбец)
    int sortColumn = selectedIndexes.first().column();

    for(int i = 0; i < this->getModel()->NumberOfRows; i++)
    {
        for(int j = 0; j < this->getModel()->NumberOfColumns; j++)
        {

        }
    }


    // Собираем строки в пределах выделения
    QList<QList<QString>> selectedRowsData;
    for (int row = minRow; row <= maxRow; ++row) {
        QList<QString> rowData;
        for (int col = 0; col < this->getModel()->columnCount(); ++col) {
            rowData.append(this->getModel()->item(row, col)->text());
        }
        selectedRowsData.append(rowData);
    }

    if(action == "AscendingGnomeSort")
    {
        selectedRowsData = this->getModel()->ascendingGnomeSort(selectedRowsData, sortColumn);
    }
    if(action == "DescendingGnomeSort")
    {
        selectedRowsData = this->getModel()->descendingGnomeSort(selectedRowsData, sortColumn);
    }
    if(action == "AscendingCombSort")
    {
        selectedRowsData = this->getModel()->ascendingCombSort(selectedRowsData, sortColumn);
    }
    if(action == "DescendingCombSort")
    {
        selectedRowsData = this->getModel()->descendingCombSort(selectedRowsData, sortColumn);
    }
    qDebug() << selectedRowsData;
    for (int row = minRow; row <= maxRow; ++row) {
        for (int col = 0; col < this->getModel()->columnCount(); ++col) {
            //qDebug() << new Item(selectedRowsData[row])
            this->getModel()->setItem(row, col, new Item(selectedRowsData[row - minRow][col]));
        }
    }
}

void CustomTableView::filterTable(double minValue, double maxValue)
{

    QItemSelectionModel *selectionModel = this->selectionModel();
    if (!selectionModel->hasSelection()) {
        return;
    }

    QModelIndexList selectedIndexes = selectionModel->selectedIndexes();
    if (selectedIndexes.isEmpty()) {
        return;
    }

    for(auto index:selectedIndexes)
    {
        if(getModel()->data(index).toDouble() < minValue || getModel()->data(index).toDouble() > maxValue)
            getModel()->setData(index, "");
    }
}

bool CustomTableView::checkCorrectInputForPieDiagram(QModelIndexList selectedIndexes)
{
    QModelIndex firstIndex = selectedIndexes.first();
    QModelIndex lastIndex = selectedIndexes.last();

    int firstRow = firstIndex.row();
    int firstColumn = firstIndex.column();
    int lastRow = lastIndex.row();
    int lastColumn = lastIndex.column();

    if(!checkCorrectnessOfValues(firstRow + 1, lastRow, firstColumn, lastColumn))
    {
        QMessageBox::information(this, "Ошибка", "Проверьте корректность выделенных данных");
        return false;
    }

    if(!checkCorrectnessOfDiapason(selectedIndexes))
    {
        QMessageBox::information(this, "Ошибка", "выделите прямоугольный диапазон");
        return false;
    }

    if(lastRow - firstRow != 1)
    {
        QMessageBox::information(this, "Ошибка", "выделите только 2 строки");
        return false;
    }
    return true;
}

bool CustomTableView::checkCorrectnessOfDiapason(QModelIndexList selectedIndexes)
{
    int minRow = INT_MAX;
    int maxRow = INT_MIN;
    int minColumn = INT_MAX;
    int maxColumn = INT_MIN;

    for (const QModelIndex& index : selectedIndexes) {
        minRow = qMin(minRow, index.row());
        maxRow = qMax(maxRow, index.row());
        minColumn = qMin(minColumn, index.column());
        maxColumn = qMax(maxColumn, index.column());
    }

    bool isRectangular = (maxRow - minRow + 1) * (maxColumn - minColumn + 1) == selectedIndexes.size();
    return isRectangular;
}

bool CustomTableView::checkCorrectnessOfValues(int firstRow, int lastRow, int firstColumn, int lastColumn)
{
    ItemModel* model = getModel();

    bool ok;

    for(int i = firstColumn; i <= lastColumn; ++i)
    {
        for(int j = firstRow; j <= lastRow; ++j)
        {
            QModelIndex index = model->index(j, i);
            QVariant data = model->data(index);
            data.toDouble(&ok);
            if(!ok)
                return false;
        }
    }
    return true;
}

bool CustomTableView::checkCorrectInputForGraphic(QModelIndexList selectedIndexes)
{
    QModelIndex firstIndex = selectedIndexes.first();
    QModelIndex lastIndex = selectedIndexes.last();

    int firstRow = firstIndex.row();
    int firstColumn = firstIndex.column();
    int lastRow = lastIndex.row();
    int lastColumn = lastIndex.column();

    if(!checkCorrectnessOfDiapason(selectedIndexes))
    {
        QMessageBox::information(this, "Ошибка", "Выделите прямоугольный диапазон");
        return false;
    }
    if(!checkCorrectnessOfValues(firstRow + 1, lastRow, firstColumn, lastColumn))
    {
        QMessageBox::information(this, "Ошибка", "Проверьте корректность выделенных данных");
        return false;
    }
    return true;
}

bool CustomTableView::checkCorrectInputForLineDiagram(QModelIndexList selectedIndexes)
{
    QModelIndex firstIndex = selectedIndexes.first();
    QModelIndex lastIndex = selectedIndexes.last();

    int firstRow = firstIndex.row();
    int firstColumn = firstIndex.column();
    int lastRow = lastIndex.row();
    int lastColumn = lastIndex.column();

    if(!checkCorrectnessOfDiapason(selectedIndexes))
    {
        QMessageBox::information(this, "Ошибка", "Выделите прямоугольный диапазон");
        return false;
    }
    if(!checkCorrectnessOfValues(firstRow + 1, lastRow, firstColumn, lastColumn))
    {
        QMessageBox::information(this, "Ошибка", "Проверьте корректность выделенных данных");
        return false;
    }
    return true;
}

bool CustomTableView::isValues(QModelIndexList selectedIndexes)
{
    int firstColumn = selectedIndexes.first().column();
    int lastColumn = selectedIndexes.last().column();
    int firstRow = selectedIndexes.first().row();
    int lastRow = selectedIndexes.last().row();
    bool ok;
    for(int column = firstColumn; column <= lastColumn; column++)
    {
        for(int row = firstRow; row <= lastRow; ++row)
        {
            QModelIndex index = getModel()->index(row, column);
            QVariant data = getModel()->data(index);
            data.toDouble(&ok);
            if(!ok)
                return false;
        }
    }
    return true;
}
