#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_Add_clicked()
{
    ui->tableWidget->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    if (!ui->lineEdit_type->text().isEmpty() && !ui->lineEdit_company->text().isEmpty() && !ui->lineEdit_model->text().isEmpty() && !ui->lineEdit_param->text().isEmpty()){
        details.push_back(Detail(ui->lineEdit_type->text(), ui->lineEdit_company->text(), ui->lineEdit_model->text(), ui->lineEdit_param->text(), ui->doubleSpinBox_coast->value(), ui->checkBox_ava->isChecked()));
        QMessageBox::information(0, tr(""), tr("Успешно"), QMessageBox::Ok|QMessageBox::NoButton);
        arrayToTable(details);
    } else {
        QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных "),QMessageBox::Ok|QMessageBox::NoButton);
    }
}

void MainWindow::on_pushButton_open_clicked()
{
    bool cont = true, ok = true;
    int k = 0;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);
    QTextStream in(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    if (in.atEnd()){
        ui->tableWidget->setRowCount(0);
        QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }
    cont = true;
    QString mainLine, t, c, m, p;
    double coa;
    bool aval;
    details.clear();
    while (!in.atEnd() && cont && ok)
    {
        mainLine = in.readLine();
        auto a = mainLine.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        ui->tableWidget->setRowCount(0);
        for (auto line : a) {
            switch (k) {
            case 0:
                t = line;
                break;
            case 1:
                c = line;
                break;
            case 2:
                m = line;
                break;
            case 3:
                p = line;
                break;
            case 4:
                coa = line.toDouble(&ok);
                if (coa < 0)
                    ok = false;
                break;
            case 5:
                if (line == "1" || line == "True"  || line == "true"  || line == "TRUE"  || line == "T" || line == "t")
                    aval = true; else
                    if (line == "0" || line == "False" || line == "false" || line == "FALSE" || line == "F" || line == "f")
                        aval = true;
                    else
                        cont = false;
                break;
            }
            ++k;
            if (k == 6){
                details.push_back(Detail(t, c, m, p, coa, aval));
                k = 0;
            }
        }
    }
    if (!cont || k != 0 || !ok){
        details.clear();
        QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
    }

    file.close();
    arrayToTable(details);
}

void MainWindow::on_pushButton_save_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Сохранение"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        return;
    }

    QTextStream out(&file);

    for (auto i : details) {
        out << i.GetType() << ' ' << i.GetName() << ' ' << i.GetAuthor() << ' ' << i.GetRemark() << ' ' << i.GetCoast() << ' ' << i.isAvaliable() << '\n';
    }
    file.close();
}

void MainWindow::arrayToTable(QVector<Detail> arr){
    ui->tableWidget->setRowCount(0);
    short j, k  = 0;
    for (auto i : arr) {
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
        QTableWidgetItem *item = new QTableWidgetItem("");
        ui->tableWidget->setVerticalHeaderItem(k, item);
        j = 0;
        QTableWidgetItem *pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(QString::number(k + 1));
        ++j;

        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.GetType());

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.GetName());

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.GetAuthor());

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.GetRemark());

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(QString::number(i.GetCoast()));

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.isAvaliable() ? "Yes" : "No");
        ++k;
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::arrayToTableSort(QVector<Detail> arr){
    short j, k = num * arr.size();
    for (auto i : arr) {
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(num + 1));
        ui->tableWidget->setVerticalHeaderItem(k, item);
        j = 0;
        QTableWidgetItem *pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(QString::number(k - num * arr.size() + 1));
        ++j;

        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.GetType());

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.GetName());

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.GetAuthor());

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.GetRemark());

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(QString::number(i.GetCoast()));

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.isAvaliable() ? "Yes" : "No");
        ++k;
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ++num;
}

void MainWindow::on_pushButton_showAll_clicked()
{
    arrayToTable(details);
}


void MainWindow::on_pushButton_search_clicked()
{
    QVector <Detail> fi;
    QString compare = ui->lineEdit_search->text();
   if (ui->radioButton_company->isChecked()) {
        for (auto i : details) {
            if (i.GetName() == compare)
                fi.push_back(i);
        }
    } else if (ui->radioButton_model->isChecked()){
        for (auto i : details) {
            if (i.GetAuthor() == compare)
                fi.push_back(i);
        }
    }
    arrayToTable(fi);
}
void MainWindow::on_pushButton_sort_clicked()
{
    auto sortStrings = details;
    for (int i = 0; i < sortStrings.size() - 1; ++i) {
        for (int j = 0; j < sortStrings.size() - 1; ++j) {
            if (sortStrings[j].GetType() < sortStrings[j + 1].GetType()){
                sortStrings.swapItemsAt(j, j+1);
            }
        }
    }

    QVector<Detail> temp;
    QVector<QVector<Detail>> aa;
    if (!sortStrings.empty()) temp.push_back(sortStrings[0]);
    for (int i = 1; i < sortStrings.size(); ++i) {
        if (sortStrings[i - 1].GetType() != sortStrings[i].GetType()){
            aa.push_back(temp);
            temp.clear();
        }
        temp.push_back(sortStrings[i]);
    }
    aa.push_back(temp);

    num = 0;
    ui->tableWidget->setRowCount(0);

    for (auto& k : aa) {
        for (int i = 0; i < k.size() - 1; ++i) {
            for (int j = 0; j < k.size() - 1; ++j) {
                if (k[j].GetAuthor() > k[j + 1].GetAuthor()){  // Изменили знак с < на >
                        std::swap(k[j], k[j+1]);
                }
            }
        }
        arrayToTableSort(k);
    }
}
