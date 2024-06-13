#include "sheetwidget.h"
#include <cmath>

SheetWidget::SheetWidget()
{
    this->setWindowTitle("Table View Widget");
    table = new CustomTableView(this);
    model = new ItemModel();
    table->setModel(model);
    CustomTableView* tableView = table;
    ItemModel* newModel = model;
    QFontDialog* fontDialog = new QFontDialog(this);
    window = new FilterWindow();
    connect(window, &FilterWindow::filterSignal, this, &SheetWidget::filterTableSignal);
    connect(this, &SheetWidget::filterTableSignal, table, &CustomTableView::filterTable);

    QPushButton* fontColorButton = new QPushButton("Изменить цвет текста");
    QObject::connect(fontColorButton, &QPushButton::clicked, [this, tableView](){
       this->setFontColorOfCells(tableView);
    });

    QPushButton* filterButton = new QPushButton("Отфильтровать выбранный диапазон");
    QObject::connect(filterButton, &QPushButton::clicked, [this](){
        window->show();
    });

    QPushButton *sortButton = new QPushButton("Отсортировать выделенное", this);
    QObject::connect(sortButton, &QPushButton::clicked, table, &CustomTableView::sortSelectedRange);

    QMenu* sortMenu = new QMenu(this);

    QAction* sortNumbersFromLowToHigh = new QAction("Сортировать числовые значения по возрастанию");
    QAction* sortNumbersFromHighToLow = new QAction("Сортировать числовые значения по убыванию");
    QAction* sortStringsFromLowToHigh = new QAction("Сортировать строчные значения от А до Я");
    QAction* sortStringsFromHighToLow = new QAction("Сортировать строчные значения от Я до А");

    sortMenu->addAction(sortNumbersFromLowToHigh);
    sortMenu->addAction(sortNumbersFromHighToLow);
    sortMenu->addAction(sortStringsFromLowToHigh);
    sortMenu->addAction(sortStringsFromHighToLow);

    sortButton->setMenu(sortMenu);

    QObject::connect(sortNumbersFromLowToHigh, &QAction::triggered, [this]{
        setTableViewAction("AscendingGnomeSort");
    });

    QObject::connect(sortNumbersFromHighToLow, &QAction::triggered, [this]{
        setTableViewAction("DescendingGnomeSort");
    });

    QObject::connect(sortStringsFromLowToHigh, &QAction::triggered, [this]{
        setTableViewAction("AscendingCombSort");
    });

    QObject::connect(sortStringsFromHighToLow, &QAction::triggered, [this]{
        setTableViewAction("DescendingCombSort");
    });

    QPushButton* setFont = new QPushButton("Установить шрифт ячеек");
    QObject::connect(setFont, &QPushButton::clicked, [this, fontDialog, tableView, newModel](){
        this->setFont(fontDialog, tableView, newModel);
    });

    QPushButton* setColorOfCell = new QPushButton("Изменить цвет ячеек", this);
    QObject::connect(setColorOfCell, &QPushButton::clicked, [this, tableView]() {
        setColorOfCells(tableView);
    });

    QPushButton *addRowButton = new QPushButton("Добавить строку", this);
    QObject::connect(addRowButton, &QPushButton::clicked, [this]() {
        model->addRow();
    });

    QPushButton *deleteRowButton = new QPushButton("Удалить строку", this);
    QObject::connect(deleteRowButton, &QPushButton::clicked, [this](){
        model->deleteRow();
    });

    QPushButton *deleteColumnButton = new QPushButton("Удалить столбец", this);
    QObject::connect(deleteColumnButton, &QPushButton::clicked, [this](){
        model->deleteColumn();
    });

    QPushButton *addColumnButton = new QPushButton("Добавить столбец", this);
    QObject::connect(addColumnButton, &QPushButton::clicked, [this]() {
        model->addColumn();

    });

    QPushButton *saveButton = new QPushButton("Сохранить", this);
    QObject::connect(saveButton, &QPushButton::clicked, [this]() {
        model->saveTableInFile(this);
    });



    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout* hLayout = new QHBoxLayout(this);
    QHBoxLayout* hhLayout = new QHBoxLayout(this);

    QPushButton* setDiagramButton = new QPushButton("Построить диаграмму или график");
    QMenu* menu = new QMenu(this);

    QAction* pieDiagram = new QAction("Построить круговую диаграму");
    QAction* lineDiagram = new QAction("Построить столбчатую диаграму");
    QAction* graphic = new QAction("Построить график");

    menu->addAction(pieDiagram);
    menu->addAction(lineDiagram);
    menu->addAction(graphic);
    setDiagramButton->setMenu(menu);

    QObject::connect(lineDiagram, &QAction::triggered, [this](){
        setTableViewAction("BarDiagram");
    });

    QObject::connect(graphic, &QAction::triggered, [this](){
        setTableViewAction("Graphic");
    });

    QObject::connect(pieDiagram, &QAction::triggered, [this](){
        setTableViewAction("PieDiagram");
    });

    layout->addLayout(hhLayout);
    hhLayout->addWidget(setDiagramButton);
    hhLayout->addWidget(setColorOfCell);
    hhLayout->addWidget(fontColorButton);
    hhLayout->addWidget(setFont);
    hhLayout->addWidget(sortButton);
    hhLayout->addWidget(filterButton);

    QVBoxLayout* vlayout = new QVBoxLayout;
    QVBoxLayout* vlayout1 = new QVBoxLayout;

    layout->addWidget(tableView);
    layout->addLayout(hLayout);
    hLayout->addLayout(vlayout);
    hLayout->addLayout(vlayout1);
    vlayout->addWidget(addRowButton);
    vlayout->addWidget(deleteRowButton);
    vlayout1->addWidget(addColumnButton);
    vlayout1->addWidget(deleteColumnButton);
    hLayout->addWidget(saveButton);

    this->showMaximized();
}



void SheetWidget::setFont(QFontDialog *fontDialog, CustomTableView *tableView, ItemModel *newModel)
{
    if(fontDialog->exec() == QDialog::Accepted)
    {
        QFont selectedFont = fontDialog->selectedFont();
        QItemSelectionModel* selectionModel = tableView->selectionModel();
        QModelIndexList selectedIndexes = selectionModel->selectedIndexes();
        for (int i = 0; i < selectedIndexes.count(); ++i) {
            QModelIndex index = selectedIndexes.at(i);
            QStandardItem* item = newModel->itemFromIndex(index);
            item->setFont(selectedFont);
            newModel->setItem(index.row(), index.column(), item);
            tableView->setModel(newModel);
        }
    }
}

void SheetWidget::setColorOfCells(CustomTableView *tableView)
{
    QColorDialog colorDialog;
    colorDialog.exec();

    // Получите выбранный цвет из QColorDialog
    QColor color = colorDialog.selectedColor();

    if (color.isValid()) {
        QItemSelectionModel* selectionModel = tableView->selectionModel();
        QModelIndexList selectedIndexes = selectionModel->selectedIndexes();
        for (int i = 0; i < selectedIndexes.count(); ++i) {
            QModelIndex index = selectedIndexes.at(i);
            QStandardItem* item = model->itemFromIndex(index);
            item->setBackground(color);
            model->setItem(index.row(), index.column(), item);
            tableView->setModel(model);
        }
    }
}

void SheetWidget::setFontColorOfCells(CustomTableView *tableView)
{
    QColorDialog colorDialog;
    colorDialog.exec();

    // Получите выбранный цвет из QColorDialog
    QColor color = colorDialog.selectedColor();

    QPalette palette;

    palette.setColor(QPalette::WindowText, color);

    if (color.isValid()) {
        QItemSelectionModel* selectionModel = tableView->selectionModel();
        QModelIndexList selectedIndexes = selectionModel->selectedIndexes();
        for (int i = 0; i < selectedIndexes.count(); ++i) {
            QModelIndex index = selectedIndexes.at(i);
            QStandardItem* item = model->itemFromIndex(index);
            item->setData(color, Qt::ForegroundRole);
            model->setItem(index.row(), index.column(), item);
            tableView->setModel(model);
        }
    }
}

void SheetWidget::setFiltration(double minValue, double maxValue)
{
    table->filterTable(minValue, maxValue);
}

ItemModel* SheetWidget::getModel()
{
    return model;
}


void SheetWidget::setTableViewAction(QString action)
{
    table->setAction(action);
}


