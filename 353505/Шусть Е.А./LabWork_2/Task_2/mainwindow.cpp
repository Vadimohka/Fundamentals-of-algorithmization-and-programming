#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Task2");
    ui->tableWidget->setHorizontalHeaderLabels({"Тип","Изготовитель","Модель","Параметры","Цена","Наличие"});

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addToFile(const QString&fileName,const Components &item)
{
    QFile file(fileName);
    if(file.open(QIODevice::Append | QIODevice::Text)){
        QTextStream out(&file);
        out<<item.type<<'\n';
        out<<item.firm<<'\n';
        out<<item.model<<'\n';
        out<<item.parameters<<'\n';
        out<<item.price<<" "<<item.curr<<'\n';
        out<<item.available<<'\n';
        out<<'\n';
    }
    file.close();
}

void MainWindow::updateInFile(const QString&fileName,const QVector<Components> &components)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (int i = 0; i < components.size(); i++) {
            out << components[i].type << '\n';
            out << components[i].firm << '\n';
            out << components[i].model << '\n';
            out << components[i].parameters << '\n';
            out << components[i].price << " " << components[i].curr << '\n';
            out << components[i].available << '\n';
            out << '\n';
        }
        file.close();
    }
}

void MainWindow::deleteFromFile(const QString &fileName, int itemNum)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream in(&file);
        QStringList lines = in.readAll().split('\n');
        int startLine = itemNum * 7;
        lines.removeAt(startLine);
        lines.removeAt(startLine);
        lines.removeAt(startLine);
        lines.removeAt(startLine);
        lines.removeAt(startLine);
        lines.removeAt(startLine);
        lines.removeAt(startLine);

        file.resize(0);
        QTextStream out(&file);
        out<<lines.join('\n');
        file.close();
    }
}

void MainWindow::findGroups(QList<Components> &components, double minPrice, double maxPrice, QList<Components> &currentGroup, int currentIndex, QList<QList<Components> > &groups)
{
    if (currentIndex >= components.size()) {
        double totalPrice = 0;
        for (const Components& c : currentGroup) {
            totalPrice += c.price;
        }
        if (totalPrice >= minPrice && totalPrice <= maxPrice) {
            groups.append(currentGroup);
        }
        return;
    }

    findGroups(components, minPrice, maxPrice, currentGroup, currentIndex + 1, groups);

    currentGroup.append(components[currentIndex]);
    findGroups(components, minPrice, maxPrice, currentGroup, currentIndex + 1, groups);

}

void MainWindow::on_open_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, "Open File", path, "Text Files (*.txt)");
    if(!fileName.isEmpty()){
        ui->tableWidget->clearContents();

        this->components = Components::readComponents(fileName);
        ui->tableWidget->setRowCount(components.size());

        for(int i=0;i<ui->tableWidget->rowCount();i++){
            Components c = components[i];
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(c.type));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(c.firm));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(c.model));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(c.parameters));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(c.price)+" "+c.curr));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(c.available));

        }
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

}


void MainWindow::on_add_clicked()
{
    if(fileName.isEmpty()){
        QMessageBox::warning(this,"Ошибка","Файл не открыт.");
        return;
    }

    AddItemDialog addItemDialog(this);
    if(addItemDialog.exec() == QDialog::Accepted){

        Components newItem;
        newItem.type = addItemDialog.getType();
        newItem.firm = addItemDialog.getManufacturer();
        if(newItem.type.isEmpty()){
            QMessageBox::warning(this,"Ошибка","Не указан тип.");
            return;
        }
        newItem.model = addItemDialog.getModel();
        newItem.parameters = addItemDialog.getParameters();
        bool ok=1;
        double price = addItemDialog.getPrice();
        if (!ok || price <= 0) {
            QMessageBox::warning(this, "Ошибка", "Некорректная цена");
            return;
        }
        newItem.price =price;
        newItem.curr = addItemDialog.getCurrency();
        newItem.available = addItemDialog.getAvailability();

        this->components.push_back(newItem);

        ui->tableWidget->setRowCount(components.size());
        int row = ui->tableWidget->rowCount() - 1;
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(newItem.type));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(newItem.firm));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(newItem.model));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(newItem.parameters));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(newItem.price) + " " + newItem.curr));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(newItem.available));

        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


        addToFile(fileName,newItem);
    }
}

void MainWindow::on_change_clicked()
{
    if(fileName.isEmpty()){
        QMessageBox::warning(this,"Ошибка","Файл не открыт.");
        return;
    }

    int rowCount = ui->tableWidget->rowCount();
    QStringList itemNum;
    for(int i=0;i<rowCount;i++){
        itemNum.append(QString::number(i+1));
    }

    bool ok;
    QString selectedNum = QInputDialog::getItem(this,"Выберите номер комплектующего","Номер",itemNum,0,false,&ok);
    if(!ok){
        return;
    }
    int selectedRow = selectedNum.toInt() - 1;
    if (selectedRow < 0 || selectedRow >= rowCount) {
        return;
    }

    AddItemDialog editItem(this);
    editItem.setWindowTitle("Изменение комплектующих");
    QString type = ui->tableWidget->item(selectedRow,0)->text();
    QString manufacturer = ui->tableWidget->item(selectedRow, 1)->text();
    QString model = ui->tableWidget->item(selectedRow, 2)->text();
    QString parameters = ui->tableWidget->item(selectedRow, 3)->text();
    QString priceStr = ui->tableWidget->item(selectedRow, 4)->text();
    QString currency = priceStr.right(4);

    int index = 0;
    if (currency == " USD") {
        index = 0;
    } else if (currency == " EUR") {
        index = 1;
    } else if (currency == "руб.") {
        index = 2;
    }
    double price = priceStr.left(priceStr.length()-4).toDouble();
    QString availability = ui->tableWidget->item(selectedRow,5)->text();
    int index1 = 0;
    if (availability == "В наличии") {
        index1 = 0;
    } else if (availability == "Нет в наличии") {
        index1 = 1;
    }
    editItem.setType(type);
    editItem.setMan(manufacturer);
    editItem.setModel(model);
    editItem.setParameters(parameters);
    editItem.setPrice(price);
    editItem.setCurr(index);
    editItem.setAvailable(index1);

    int result = editItem.exec();
    if (result == QDialog::Accepted) {

        QString updatedType = editItem.getType();
        QString updatedManufacturer = editItem.getManufacturer();
        QString updatedModel = editItem.getModel();
        QString updatedParameters = editItem.getParameters();
        double updatedPrice = editItem.getPrice();
        QString updatedCurrency = editItem.getCurrency();
        QString updatedAvailability = editItem.getAvailability();

        if (updatedType.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Нельзя изменить тип комплектующего на пустое значение.");
            return;
        }

        if (updatedPrice <= 0) {
            QMessageBox::warning(this, "Ошибка", "Некорректная цена");
            return;
        }

        ui->tableWidget->item(selectedRow, 0)->setText(updatedType);

        ui->tableWidget->item(selectedRow, 1)->setText(updatedManufacturer);
        ui->tableWidget->item(selectedRow, 2)->setText(updatedModel);
        ui->tableWidget->item(selectedRow, 3)->setText(updatedParameters);
        QString updatedPriceStr = QString::number(updatedPrice) + " " +updatedCurrency;
        ui->tableWidget->item(selectedRow, 4)->setText(updatedPriceStr);
        ui->tableWidget->item(selectedRow, 5)->setText(updatedAvailability);

        components[selectedRow].type = updatedType;
        components[selectedRow].firm = updatedManufacturer;
        components[selectedRow].model = updatedModel;
        components[selectedRow].parameters = updatedParameters;
        components[selectedRow].price = updatedPrice;
        components[selectedRow].curr = updatedCurrency;
        components[selectedRow].available = updatedAvailability;

        updateInFile(fileName,components);
    }
}

void MainWindow::on_fileCheck_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Выберите файл",path,"Текстовые файлы (*.txt)");
    if(fileName.isEmpty()){
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл.");
        return;
    }
    QTextStream in(&file);
    QString fileContent = in.readAll();

    file.close();

    view_Dialog viewDialog(this);
    viewDialog.setWindowTitle("Просмотр файла");
    viewDialog.setText(fileContent);
    viewDialog.resize(400,400);
    viewDialog.exec();
}


void MainWindow::on_delete_2_clicked()
{
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл не открыт.");
        return;
    }
    int rowCount = ui->tableWidget->rowCount();
    QStringList itemNum;
    for (int i = 0; i < rowCount; i++) {
        itemNum.append(QString::number(i + 1));
    }

    bool ok;
    QString selectedNum = QInputDialog::getItem(this, "Выберите номер комплектующего", "Номер", itemNum, 0, false, &ok);
    if (!ok) {
        return;
    }
    int selectedRow = selectedNum.toInt() - 1;
    if (selectedRow < 0 || selectedRow >= rowCount) {
        return;
    }

    deleteFromFile(fileName, selectedRow);

    ui->tableWidget->removeRow(selectedRow);
    components.removeAt(selectedRow);

}


void MainWindow::on_search1_clicked() {
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл не открыт.");
        return;
    }

    RangeDialog rangeDialog(this);
    if (rangeDialog.exec() == QDialog::Accepted) {
        double minPrice = rangeDialog.getMinVal();
        double maxPrice = rangeDialog.getMaxVal();
        QString currency = rangeDialog.getCurr();

        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        QList<Components> validComponents;
        for (const Components& c : components) {
            if (c.curr == currency && c.price >= minPrice && c.price <= maxPrice) {
                validComponents.append(c);
            }
        }

        QList<Components> currentGroup;
        QList<QList<Components>> groups;
        findGroups(validComponents, minPrice, maxPrice, currentGroup, 0, groups);

        int groupNumber = 1;
        for (const QList<Components>& group : groups) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem("Группа " + QString::number(groupNumber)));

            int row = ui->tableWidget->rowCount();
            for (const Components& c : group) {
                ui->tableWidget->insertRow(row);
                ui->tableWidget->setItem(row, 0, new QTableWidgetItem(c.type));
                ui->tableWidget->setItem(row, 1, new QTableWidgetItem(c.firm));
                ui->tableWidget->setItem(row, 2, new QTableWidgetItem(c.model));
                ui->tableWidget->setItem(row, 3, new QTableWidgetItem(c.parameters));
                ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(c.price) + " " + c.curr));
                ui->tableWidget->setItem(row, 5, new QTableWidgetItem(c.available));
                row++;
            }

            groupNumber++;
        }

        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}



void MainWindow::on_search_2_clicked()
{
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл не открыт.");
        return;
    }

    SearchDialog searchDialog(this);
    if (searchDialog.exec() == QDialog::Accepted) {
        QString type = searchDialog.getType();
        QString manufacturer = searchDialog.getManufacturer();
        QString model = searchDialog.getModel();

        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);

        QList<Components> matchedComponents;
        for (const Components& c : components) {
            if ((type.isEmpty() || c.type == type) &&
                (manufacturer.isEmpty() || c.firm == manufacturer) &&
                (model.isEmpty() || c.model == model)) {
                matchedComponents.append(c);
            }
        }

        ui->tableWidget->setRowCount(matchedComponents.size());

        for (int i = 0; i < matchedComponents.size(); i++) {
            const Components& c = matchedComponents[i];

            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(c.type));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(c.firm));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(c.model));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(c.parameters));
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(c.price) + " " + c.curr));
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem(c.available));
        }

        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}


void MainWindow::on_sort_clicked()
{
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл не открыт.");
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    std::sort(components.begin(), components.end(), [](const Components& a, const Components& b) {
        if (a.type == b.type) {
            return a.price > b.price;
        }
        return a.type < b.type;
    });

    ui->tableWidget->setRowCount(components.size());

    for (int i = 0; i < components.size(); i++) {
        const Components& c = components[i];

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(c.type));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(c.firm));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(c.model));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(c.parameters));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(c.price) + " " + c.curr));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(c.available));
    }

    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
