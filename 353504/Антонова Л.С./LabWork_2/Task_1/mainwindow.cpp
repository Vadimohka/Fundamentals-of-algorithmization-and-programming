#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    filePath = "/home/vediz/LabsOAiP/Lab2/task1/Date";
    ui->DateTable->setRowCount(1);
    ui->DateTable->setColumnCount(9);

    // Заполнение шапки
    ui->DateTable->setItem(0, 0, new QTableWidgetItem("Number"));
    ui->DateTable->setItem(0, 1, new QTableWidgetItem("Date"));
    ui->DateTable->setItem(0, 2, new QTableWidgetItem("Days for\ntoday"));
    ui->DateTable->setItem(0, 3, new QTableWidgetItem("Year\nisLeap"));
    ui->DateTable->setItem(0, 4, new QTableWidgetItem("NextDay"));
    ui->DateTable->setItem(0, 5, new QTableWidgetItem("PreviousDay"));
    ui->DateTable->setItem(0, 6, new QTableWidgetItem("TillBithday"));
    ui->DateTable->setItem(0, 7, new QTableWidgetItem("Week\nNumber"));
    ui->DateTable->setItem(0, 8, new QTableWidgetItem("From\ndate"));

    ui->DateTable->verticalHeader()->setVisible(false);
    ui->DateTable->horizontalHeader()->setVisible(false);

    // Установка размеров ячеек
    ui->DateTable->setColumnWidth(0, 70);
    ui->DateTable->setColumnWidth(1, 90);
    ui->DateTable->setColumnWidth(2, 75);
    ui->DateTable->setColumnWidth(3, 70);
    ui->DateTable->setColumnWidth(4, 90);
    ui->DateTable->setColumnWidth(5, 100);
    ui->DateTable->setColumnWidth(6, 90);
    ui->DateTable->setColumnWidth(7, 80);
    ui->DateTable->setColumnWidth(8, 80);
    ui->DateTable->setRowHeight(0, 50);

    // Ограничение на веделение только одной строки таблицы
    ui->DateTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->DateTable->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->label->setText("Bithday: " + bithday.ToString());

    amount = 0;

    ReadDates();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FillTable(){
    ui->DateTable->setRowCount(amount + 1);
    for(int i = 1; i <= amount; ++i){
        Date datei = datesfromfile[i - 1];
        ui->DateTable->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        ui->DateTable->setItem(i, 1, new QTableWidgetItem(datei.ToString()));
        ui->DateTable->setItem(i, 2, new QTableWidgetItem(QString::number(datei.Duration(today))));
        ui->DateTable->setItem(i, 3, new QTableWidgetItem(datei.isLeap() ? "Yes" : "No"));
        ui->DateTable->setItem(i, 4, new QTableWidgetItem(datei.NextDay().ToString()));
        ui->DateTable->setItem(i, 5, new QTableWidgetItem(datei.PreviousDay().ToString()));
        ui->DateTable->setItem(i, 6, new QTableWidgetItem(QString::number(datei.DaysTillYourBiryhday(bithday))));
        ui->DateTable->setItem(i, 7, new QTableWidgetItem(QString::number(datei.WeekNumber())));
    }

    for (int i = 1; i < amount; ++i)    {
        Date currdate = datesfromfile[i-1];
        Date nextdate = datesfromfile[i];
        ui->DateTable->setItem(i, 8, new QTableWidgetItem(QString::number(
                                          currdate.Duration(nextdate))));
    }
}

void MainWindow::ReadDates(){
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Обработка ошибки
        qDebug() << "Не удалось открыть файл";
        QMessageBox::critical(this, "Error", "Не удалось открыть файл");
        return;
    }

    amount = 0;

    while(!file.atEnd()){
        file.readLine();
        ++amount;
    }
    file.seek(0);

    // Заполнение массива датами из файла
    datesfromfile = new Date[amount];
    for (int i = 0; i < amount; ++i){
        datesfromfile[i] = Date(file.readLine());

        if (!datesfromfile[i].isValid()){
            qDebug() << "Некорректный формат даты";
            QMessageBox::critical(this, "Error", "Некорректный формат даты");
            return;
        }
    }

    FillTable();
    file.close();
}

Date MainWindow::FillDateLine(){
    QDialog dialog(this);
    QFormLayout form(&dialog);

    // Добавление полей для ввода
    QLineEdit *dayInput = new QLineEdit(&dialog);
    QLineEdit *monthInput = new QLineEdit(&dialog);
    QLineEdit *yearInput = new QLineEdit(&dialog);
    form.addRow("Day", dayInput);
    form.addRow("Month", monthInput);
    form.addRow("Year", yearInput);

    // Добавление кнопок Ок и Отмена
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Отображение диалогового окна
    if (dialog.exec() == QDialog::Accepted) {
        int day = dayInput->text().toInt();
        int month = monthInput->text().toInt();
        int year = yearInput->text().toInt();

        Date newdate(day, month, year);
        if (!newdate.isValid()){
            qDebug() << "Некорректный формат даты";
            QMessageBox::critical(this, "Error", "Некорректный формат даты");
        } else{
            return newdate;
        }
    }
}

void MainWindow::on_BithdayButton_clicked(){
    bithday = FillDateLine();
    ui->label->setText("Bithday: " + bithday.ToString());
    ReadDates();
}

void MainWindow::on_AddDateButton_clicked(){
    QFile file(filePath);
    Date date = FillDateLine();

    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
        QTextStream out(&file);
        out << date.ToString() << "\n";
        file.close();
        qDebug() << "Запись успешно добавлена в файл:" << filePath;
    } else{
        qDebug() << "Ошибка";
        QMessageBox::critical(this, "Error", "Ошибка");
        return;
    }

    ReadDates();
}

void MainWindow::RewriteFile(int rowIndex, const QString &newdate){
    // Читаем все строки из файла в список
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Не удалось открыть файл");
        return;
    }
    QTextStream in(&file);
    QStringList lines;
    while (!in.atEnd()) {
        lines.append(in.readLine());
    }
    file.close();

    // Заменяем нужную строку
    if(rowIndex >= 0 && rowIndex < lines.size()){
        lines[rowIndex] = newdate;
    } else {
        QMessageBox::warning(this, "Warning", "Индекс строки вне диапазона");
        return;
    }

    // Записываем все строки обратно в файл
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Не удалось открыть файл");
        return;
    }
    QTextStream out(&file);
    for(const QString &line : lines){
        out << line << "\n";
    }
    file.close();
}

void MainWindow::on_ChangeDateButton_clicked(){
    QModelIndexList selected = ui->DateTable->selectionModel()->selectedRows();

    if(selected.isEmpty()){
        // Если ни одна строка не выбрана, выводим предупреждение
        QMessageBox::warning(this, "Warning", "Не выбрана ни одна строка");
    } else {
        // Иначе, обрабатываем выбранную строку
        QModelIndex index = selected.first();

        RewriteFile(index.row() - 1, FillDateLine().ToString());
        ReadDates();
    }
}

void MainWindow::on_OpenFileButton_clicked(){
    // Диалог выбора файла
    QString newpath = QFileDialog::getOpenFileName(nullptr, "Выберите .txt файл", QDir::homePath());

    if (newpath.isEmpty())
        return; // Если пользователь нажал Отмена

    QFile file(newpath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Не удалось открыть файл");
        return;
    }
    filePath = newpath;
    file.close();

    ReadDates();
}
