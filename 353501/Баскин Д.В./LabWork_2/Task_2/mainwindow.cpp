#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file.setFileName("temp.txt");
    ReadFromFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetItems(int row, bool fromUi)
{
    if (fromUi)
    {
        products[row].SetGroup(ui->lineEdit_group->text().trimmed());
        products[row].SetCode(ui->lineEdit_code->text().trimmed());
        products[row].SetName(ui->lineEdit_name->text().trimmed());
        products[row].SetModel(ui->lineEdit_model->text().trimmed());
        products[row].SetCost(ui->doubleSpinBox_cost->value());
        products[row].SetCount(ui->spinBox_count->value());

        /*ui->lineEdit_group->clear();
        ui->lineEdit_code->clear();
        ui->lineEdit_name->clear();
        ui->lineEdit_model->clear();
        ui->doubleSpinBox_cost->clear();
        ui->spinBox_count->clear();*/
    }

    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(products[row].GetGroup()));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(products[row].GetCode()));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(products[row].GetName()));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(products[row].GetModel()));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(products[row].GetCost())));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(products[row].GetCount())));
}

void MainWindow::ReadFromFile()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    products.clear();

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, tr("Error"), tr("Unable to read data"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    QTextStream stream(&file);
    int i = 0;
    stream.seek(0);
    while (!stream.atEnd())
    {
        QString Group = stream.readLine(), Code = stream.readLine(), Name = stream.readLine(), Model = stream.readLine();
        bool check;
        double Cost = stream.readLine().toDouble(&check);
        int Count = stream.readLine().toInt(&check);

        if (!check || Group.isEmpty() || Code.isEmpty() || Name.isEmpty() || Model.isEmpty())
        {
            QMessageBox::critical(0,tr("Error"),tr("File contained corrupted data or empty string, importing interrupted"),QMessageBox::Ok|QMessageBox::NoButton);
            file.close();
            return;
        }

        ui->tableWidget->insertRow(i);
        Product product(Group, Code, Name, Model, Cost, Count);
        products.push_back(product);
        SetItems(i, false);
        ++i;
    }

    file.close();
    ui->tableWidget->update();
}

void MainWindow::WriteToFile()
{
    file.reset();
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(nullptr, tr("Error"), tr("Unable to write data"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    QTextStream out(&file);
    for (int i = 0; i < products.size(); ++i)
    {
        out << products[i].GetGroup() << '\n' << products[i].GetCode() << '\n'
            << products[i].GetName() << '\n' << products[i].GetModel() << '\n'
            << products[i].GetCost() << '\n' << products[i].GetCount() << '\n';
    }
    file.close();
}

void MainWindow::on_pushButton_add_clicked()
{
    ReadFromFile();
    if (ui->lineEdit_group->text().trimmed().isEmpty() || ui->lineEdit_code->text().trimmed().isEmpty() ||
            ui->lineEdit_name->text().trimmed().isEmpty() || ui->lineEdit_model->text().trimmed().isEmpty())
    {
        QMessageBox::critical(nullptr, tr("Error"), tr("Every field must be filled!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    products.push_back(*new Product);
    SetItems(row, true);
    WriteToFile();
}

void MainWindow::on_pushButton_change_clicked()
{
    ReadFromFile();
    if (ui->lineEdit_group->text().trimmed().isEmpty() || ui->lineEdit_code->text().trimmed().isEmpty() ||
            ui->lineEdit_name->text().trimmed().isEmpty() || ui->lineEdit_model->text().trimmed().isEmpty())
    {
        QMessageBox::critical(nullptr, tr("Error"), tr("Every field must be filled!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    if (ui->tableWidget->selectedItems().count() == 0)
        return;

    int row = ui->tableWidget->selectedItems().first()->row();
    SetItems(row, true);
    WriteToFile();
}

void MainWindow::on_pushButton_delete_clicked()
{
    ReadFromFile();
    int row = ui->tableWidget->selectedItems().first()->row();
    ui->tableWidget->removeRow(row);
    products.removeAt(row);
    WriteToFile();
}

void MainWindow::on_pushButton_save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Text file"), "", tr("Text Files (*.txt)"));
    if (fileName.isEmpty())
    {
        return;
    }

    file.copy(fileName + ".txt");
    file.close();
}

void MainWindow::on_pushButton_load_clicked()
{
    ReadFromFile();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text file"), "", tr("Text Files (*.txt)"));
    if (fileName.isEmpty())
    {
        return;
    }

    QFile openedFile(fileName);
    if (QFileInfo(file).absoluteFilePath() == QFileInfo(openedFile).absoluteFilePath())
    {
        QMessageBox::warning(0,tr("Warning"),tr("Cannot import from working file"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }

    if (!openedFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(nullptr, tr("Error"), tr("Unable to read data"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    if (!file.open((QIODevice::WriteOnly | QIODevice::Append)))
    {
        QMessageBox::critical(nullptr, tr("Error"), tr("Unable to write data"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    QTextStream from(&openedFile);
    QTextStream in(&file);
    while (!from.atEnd())
    {
        QString Group = from.readLine();
        QString Code = from.readLine();
        QString Name = from.readLine();
        QString Model = from.readLine();
        QString Cost = from.readLine();
        QString Count = from.readLine();

        bool check;
        Cost.toDouble(&check);
        Count.toInt(&check);

        if (!check || Group.isEmpty() || Code.isEmpty() || Name.isEmpty() || Model.isEmpty())
        {
            QMessageBox::critical(0,tr("Error"),tr("Invalid data format, importing interrupted"),QMessageBox::Ok|QMessageBox::NoButton);
            file.close();
            openedFile.close();
            if (openedFile.fileName() != "temp.txt")
            {
                ReadFromFile();
            }
            else
            {
                file.resize(0);
            }
            return;
        }
        in << Group << '\n' << Code << '\n' << Name << '\n' << Model << '\n' << Cost << '\n'<< Count << '\n';
    }

    file.close();
    openedFile.close();
}

void MainWindow::on_pushButton_search_clicked()
{
    for (int i = 0; i < products.size(); ++i)
    {
        if (ui->lineEdit_nameSearch->text().trimmed().isEmpty() && ui->lineEdit_modelSort->text().trimmed().isEmpty())
        {
            QMessageBox::information(0,tr("Info"),tr("Fill in at least one field!"),QMessageBox::Ok|QMessageBox::NoButton);
            return;
        }
        if ((products[i].GetName().contains(ui->lineEdit_nameSearch->text().trimmed()) && products[i].GetModel().contains(ui->lineEdit_modelSort->text().trimmed())) ||
            (products[i].GetName().contains(ui->lineEdit_nameSearch->text().trimmed()) && ui->lineEdit_modelSort->text().isEmpty()) ||
            (ui->lineEdit_nameSearch->text().isEmpty() && products[i].GetModel().contains(ui->lineEdit_modelSort->text().trimmed())))
        {
            ui->tableWidget->showRow(i);
        }
        else
        {
            ui->tableWidget->hideRow(i);
        }
    }
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_searchCount_clicked()
{
    for (int i = 0; i < products.size(); ++i)
    {
        if (products[i].GetCount() < ui->spinBox_countSearch->value())
        {
            ui->tableWidget->showRow(i);
        }
        else
        {
            ui->tableWidget->hideRow(i);
        }
    }
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_sort_clicked()
{
    int option = ui->comboBox_sortOption->currentIndex();

    if (products.size() > 1)
    {
        switch (option) {
        case 0:
            std::sort(products.begin(), products.end(), [](const Product& left, const Product& right){
                return left.GetGroup() < right.GetGroup();
            });
            break;
        case 1:
            std::sort(products.begin(), products.end(), [](const Product& left, const Product& right){
                return left.GetCode() < right.GetCode();
            });
            break;
        case 2:
            std::sort(products.begin(), products.end(), [](const Product& left, const Product& right){
                return left.GetName() < right.GetName();
            });
            break;
        case 3:
            std::sort(products.begin(), products.end(), [](const Product& left, const Product& right){
                return left.GetModel() < right.GetModel();
            });
            break;
        case 4:
            std::sort(products.begin(), products.end(), [](const Product& left, const Product& right){
                return left.GetCost() > right.GetCost();
            });
            break;
        case 5:
            std::sort(products.begin(), products.end(), [](const Product& left, const Product& right){
                return left.GetCount() > right.GetCount();
            });
            break;
        default:
            break;
        }

        WriteToFile();
        ReadFromFile();
    }
}

void MainWindow::on_pushButton_sortGroup_clicked()
{
    int option = ui->comboBox_sortGroupOption->currentIndex();

    QVector<Product> group;
    for (int i = 0; i < products.size(); ++i)
    {
        if (products[i].GetGroup() == ui->lineEdit_groupSort->text().trimmed())
        {
            group.push_back(products[i]);
        }
    }

    if (group.size() > 1)
    {
        switch (option) {
        case 0:
            std::sort(group.begin(), group.end(), [](const Product& left, const Product& right){
                return left.GetCode() > right.GetCode();
            });
            break;
        case 1:
            std::sort(group.begin(), group.end(), [](const Product& left, const Product& right){
                return left.GetName() > right.GetName();
            });
            break;
        case 2:
            std::sort(group.begin(), group.end(), [](const Product& left, const Product& right){
                return left.GetCost() > right.GetCost();
            });
            break;
        default:
            break;
        }
    }

    int n = 0;
    if (products.size()) {
        for (int i = 0; i < products.size(); ++i)
        {
            if(products[i].GetGroup() == ui->lineEdit_groupSort->text().trimmed())
            {
                products[i] = group[n];
                ++n;
            }
        }
        if (n != 0)
        {
            WriteToFile();
            ReadFromFile();
        }
        else
        {
            QMessageBox::information(0,tr("Search info"),tr("No products with such group found!"),QMessageBox::Ok|QMessageBox::NoButton);
        }
    }
    else
    {
        QMessageBox::information(0,tr("Search info"),tr("No products!"),QMessageBox::Ok|QMessageBox::NoButton);

    }
}

void MainWindow::on_pushButton_return_clicked()
{
    ReadFromFile();
    ui->stackedWidget->setCurrentIndex(0);
}

