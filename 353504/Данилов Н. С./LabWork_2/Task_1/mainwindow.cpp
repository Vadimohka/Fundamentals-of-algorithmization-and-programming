
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    std::time_t currentTime = std::time(nullptr);
    BDay.SetDay(std::localtime(&currentTime)->tm_mday);
    BDay.SetMonth(std::localtime(&currentTime)->tm_mon + 1);
    BDay.SetYear(std::localtime(&currentTime)->tm_year + 1900);

    Duration.SetDay(std::localtime(&currentTime)->tm_mday);
    Duration.SetMonth(std::localtime(&currentTime)->tm_mon + 1);
    Duration.SetYear(std::localtime(&currentTime)->tm_year + 1900);

    ui->setupUi(this);

    ui->spinBox_day->setValue(std::localtime(&currentTime)->tm_mday);
    ui->spinBox_month->setValue(std::localtime(&currentTime)->tm_mon + 1);
    ui->spinBox_year->setValue(std::localtime(&currentTime)->tm_year + 1900);

    ui->label_BDate->setText(QString("Birh Date: " + QString::number(BDay.GetDay()) + "." + QString::number(BDay.GetMonth()) + "." + QString::number(BDay.GetYear())));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBox_month_editingFinished()
{
    switch (ui->spinBox_month->value()) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        ui->spinBox_day->setMaximum(31);
        break;
    case 4: case 6: case 9: case 11:
        ui->spinBox_day->setMaximum(30);
        if (ui->spinBox_day->value() == 31)
            ui->spinBox_day->setValue(30);
        break;
    case 2:
        if (Date(1, 1, ui->spinBox_year->value()).IsLeap()){
            ui->spinBox_day->setMaximum(29);
            if (ui->spinBox_day->value() > 29)
                ui->spinBox_day->setValue(29);
        } else {
            ui->spinBox_day->setMaximum(28);
            if (ui->spinBox_day->value() > 28)
                ui->spinBox_day->setValue(28);
        }
        break;
    }
}


void MainWindow::on_spinBox_month_valueChanged(int arg1)
{
    if (arg1 == 2 || arg1 == 4 || arg1 == 5 || arg1 == 6 || arg1 == 7 || arg1 == 8 || arg1 == 9 || arg1 == 10 || arg1 == 11 || arg1 == 12)
        ui->spinBox_month->editingFinished();
}


void MainWindow::on_pushButton_setBDay_clicked()
{
    BDay.SetDay(ui->spinBox_day->value());
    BDay.SetMonth(ui->spinBox_month->value());
    BDay.SetYear(ui->spinBox_year->value());
    ui->label_BDate->setText(QString("Birh Date: " + QString::number(ui->spinBox_day->value()) + "." + QString::number(ui->spinBox_month->value()) + "." + QString::number(ui->spinBox_year->value())));
    arrayToTable(dates);
}


void MainWindow::on_pushButton_setDur_clicked()
{
    Duration.SetDay(ui->spinBox_day->value());
    Duration.SetMonth(ui->spinBox_month->value());
    Duration.SetYear(ui->spinBox_year->value());
    ui->label_Dur->setText(QString("Date for duration:: " + QString::number(ui->spinBox_day->value()) + "." + QString::number(ui->spinBox_month->value()) + "." + QString::number(ui->spinBox_year->value())));
    arrayToTable(dates);
}


void MainWindow::on_pushButton_open_clicked()
{
    bool cont;
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
    short d, m, y, max;
    cont = true;
    QString mainLine;
    while (!in.atEnd() && cont)
    {
        cont = false;
        dates.clear();
        mainLine = in.readLine();
        auto a = mainLine.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        ui->tableWidget->setRowCount(0);
        for (auto line : a) {
            if (line.length() == 10 && line[2] == '.' && line[5] == '.' && line[0].isDigit() && line[1].isDigit() && line[3].isDigit() && line[4].isDigit() && line[6].isDigit() && line[7].isDigit() && line[8].isDigit() && line[9].isDigit()){
                d = (line.left(2)).toShort();
                m = (line.mid(3, 2)).toShort();
                y = (line.right(4)).toShort();
                if (y >= 1582 && y <= 3000){
                    if (m >= 1 && m <= 12){
                        switch (m) {
                        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                            max = 31;
                            break;
                        case 4: case 6: case 9: case 11:
                            max = 30;
                            break;
                        case 2:
                            if (Date(1, 1, ui->spinBox_year->value()).IsLeap()){
                                max = 29;
                            } else {
                                max = 28;
                            }
                            break;
                        }
                        if (d >= 1 && d <= max){
                            dates.push_back(Date(d, m, y));
                            cont = true;
                        }
                    }
                }
            }
        }
    }
    if (!cont){
        dates.clear();
        QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
    }

    file.close();
    arrayToTable(dates);
}

void MainWindow::arrayToTable(QVector<Date> arr){
    if (dates.empty()){
        ui->spinBox_change->setEnabled(false);
    } else {
        ui->spinBox_change->setEnabled(true);
        ui->spinBox_change->setMaximum(dates.size());
    }
    ui->tableWidget->setRowCount(arr.size());
    short j, k  = 0;
    for (auto i : arr) {
        j = 0;
        QTableWidgetItem *pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.ToQString());

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.NextDay().ToQString());

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.PreviousDay().ToQString());

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(i.IsLeap() ? "Yes" : "No");

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(QString::number(i.WeekNumber()));

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(QString::number(i.Duration(Duration)));

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        pCell->setText(QString::number(i.DaysTillYourBithday(BDay)));

        ++j;
        pCell = ui->tableWidget->item(k, j);
        if(!pCell)
        {
            pCell = new QTableWidgetItem;
            ui->tableWidget->setItem(k, j, pCell);
        }
        if (k != arr.size() - 1){
            pCell->setText(QString::number(i.Duration(Date(arr[k + 1].GetDay(), arr[k + 1].GetMonth(), arr[k + 1].GetYear()))));
        } else {
            pCell->setText("-");
        }
        ++k;
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_pushButton_AddDay_clicked()
{
    dates.push_back(Date(ui->spinBox_day->value(), ui->spinBox_month->value(), ui->spinBox_year->value()));
    arrayToTable(dates);
}

void MainWindow::on_pushButton_ChangeDay_clicked()
{
    if (ui->spinBox_change->isEnabled()){
        dates[ui->spinBox_change->value() - 1].SetDay(ui->spinBox_day->value());
        dates[ui->spinBox_change->value() - 1].SetMonth(ui->spinBox_month->value());
        dates[ui->spinBox_change->value() - 1].SetYear(ui->spinBox_year->value());
    }
    arrayToTable(dates);
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

    for (auto i : dates) {
        out << i.ToQString() << ' ';
    }
    file.close();
}


void MainWindow::on_spinBox_year_editingFinished()
{
    switch (ui->spinBox_month->value()) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        ui->spinBox_day->setMaximum(31);
        break;
    case 4: case 6: case 9: case 11:
        ui->spinBox_day->setMaximum(30);
        if (ui->spinBox_day->value() == 31)
            ui->spinBox_day->setValue(30);
        break;
    case 2:
        if (Date(1, 1, ui->spinBox_year->value()).IsLeap()){
            ui->spinBox_day->setMaximum(29);
            if (ui->spinBox_day->value() > 29)
                ui->spinBox_day->setValue(29);
        } else {
            ui->spinBox_day->setMaximum(28);
            if (ui->spinBox_day->value() > 28)
                ui->spinBox_day->setValue(28);
        }
        break;
    }
}

