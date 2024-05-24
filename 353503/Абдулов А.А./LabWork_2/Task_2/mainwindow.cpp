#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filePath = "/home/alexandr/laba2_2/Store.txt";
    amount = 0;
    ReadProducts();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::FillName(){
    ui->comboBox->blockSignals(true);
    ui->comboBox->clear();

    // Заполнение QComboBox именами продуктов
    for (int i = 0; i < amount; i++) {
        ui->comboBox->addItem(productsfromfile[i].GetName());
    }

    ui->comboBox->blockSignals(false);
}

void MainWindow::ReadProducts(){
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Не удалось открыть файл");
        return;
    }

    amount = 0;
    while(!file.atEnd()){
        file.readLine();
        ++amount;
    }
    file.seek(0);

    productsfromfile = new Product[amount];
    for (int i = 0; i < amount; ++i){
        productsfromfile[i] = Product(file.readLine());
    }

    FillName();
    file.close();
}

Product MainWindow::FillProductLine(){
    QDialog dialog(this);
    QFormLayout form(&dialog);

    // Добавление полей для ввода
    QLineEdit *groupInput = new QLineEdit(&dialog);
    QLineEdit *codeInput = new QLineEdit(&dialog);
    QLineEdit *nameInput = new QLineEdit(&dialog);
    QLineEdit *modelInput = new QLineEdit(&dialog);
    QLineEdit *costInput = new QLineEdit(&dialog);
    QLineEdit *countInput = new QLineEdit(&dialog);
    form.addRow("Group", groupInput);
    form.addRow("Code", codeInput);
    form.addRow("Name", nameInput);
    form.addRow("Model", modelInput);
    form.addRow("Cost", costInput);
    form.addRow("Count", countInput);

    // Добавление кнопок Ок и Отмена
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Отображение диалогового окна
    if (dialog.exec() == QDialog::Accepted) {
        QString group = groupInput->text();
        QString code = codeInput->text();
        QString name = nameInput->text();
        QString model = modelInput->text();
        double cost = costInput->text().toDouble();
        int count = countInput->text().toInt();

        Product newproduct(group, code, name, model, cost, count);
        return newproduct;
    }
}

void MainWindow::on_AddButton_clicked(){
    QFile file(filePath);
    Product prod = FillProductLine();

    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
        QTextStream out(&file);
        out << prod.ToString() << "\n";
        file.close();
        qDebug() << "Запись успешно добавлена в файл:" << filePath;
    } else{
        QMessageBox::critical(this, "Error", "Ошибка");
        return;
    }

    ReadProducts();
}

void MainWindow::RewriteFile(int rowIndex, const QString &newproduct){
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

    if(rowIndex >= 0 && rowIndex < lines.size()){
        lines[rowIndex] = newproduct;
    } else {
        QMessageBox::warning(this, "Warning", "Индекс строки вне диапазона");
        return;
    }

    QTextStream out(&file);
    for(const QString &line : lines){
        out << line << "\n";
    }
    file.close();
}

void MainWindow::on_ChangeButton_clicked(){
    QDialog dialog(this);
    QFormLayout form(&dialog);

    QLineEdit *indexInput = new QLineEdit(&dialog);
    form.addRow("Number", indexInput);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted) {
        int index = indexInput->text().toInt();

        Product newproduct = FillProductLine();
        RewriteFile(index, newproduct.ToString());
    }
}

void MainWindow::on_DeleteButton_clicked(){
    QDialog dialog(this);
    QFormLayout form(&dialog);

    QLineEdit *indexInput = new QLineEdit(&dialog);
    form.addRow("Number", indexInput);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted) {
        int index = indexInput->text().toInt();

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

        if(index >= 0 && index < lines.size()){
            lines.removeAt(index);
        } else {
            QMessageBox::warning(this, "Warning", "Индекс строки вне диапазона");
            return;
        }

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Не удалось открыть файл");
            return;
        }
        QTextStream out(&file);
        for(const QString &line : lines){
            out << line << "\n";
        }
        file.close();
        amount--;
    }
}

void MainWindow::on_SeeButton_clicked(){
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Не удалось открыть файл");
        return;
    }
    QTextStream in(&file);
    ui->textBrowser->clear();
    while (!in.atEnd()) {
        ui->textBrowser->append(in.readLine());
    }
    file.close();
}

void MainWindow::on_comboBox_currentIndexChanged(int index){
    if (index != -1) { // проверка, что выбран действительный элемент
        QString name = ui->comboBox->itemText(index);
        for (int i = 0; i < amount; i++) {
            Product product = productsfromfile[i];
            if (product.GetName() == name) {
                ui->groupLabel->setText(product.GetGroup());
                ui->codeLabel->setText(product.GetCode());
                ui->modelLabel->setText(product.GetModel());
                ui->costLabel->setText(QString::number(product.GetCost()));
                ui->countLabel->setText(QString::number(product.GetCount()));
                break;
            }
        }
    }
}

void MainWindow::on_OpenButton_clicked(){
    QString newpath = QFileDialog::getOpenFileName(nullptr, "Выберите .txt файл", QDir::homePath());

    if (newpath.isEmpty())
        return;

    QFile file(newpath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Не удалось открыть файл");
        return;
    }
    filePath = newpath;
    file.close();

    ReadProducts();
}

void MainWindow::on_SortButton_clicked(){
    QMessageBox message;
    message.setText("Sort: ");

    QAbstractButton* button1 = message.addButton("Sort in group", QMessageBox::NoRole);
    QAbstractButton* button2 = message.addButton("Cost < number", QMessageBox::NoRole);
    QAbstractButton* button3 = message.addButton("Find", QMessageBox::NoRole);

    message.exec();

    ui->textBrowser->clear();

    if(message.clickedButton() == button1){
        QMessageBox messageSort;
        messageSort.setText("Sort: ");

        QAbstractButton* button6 = messageSort.addButton("Code", QMessageBox::NoRole);
        QAbstractButton* button7 = messageSort.addButton("Name", QMessageBox::NoRole);
        QAbstractButton* button8 = messageSort.addButton("Cost", QMessageBox::NoRole);

        messageSort.exec();

        if(messageSort.clickedButton() == button6){
            for (int i = 0; i < amount - 1; i++) {
                for (int j = 0; j < amount - i - 1; j++) {
                    if (productsfromfile[j].GetCode() > productsfromfile[j + 1].GetCode()) {
                        std::swap(productsfromfile[j], productsfromfile[j + 1]);
                    }
                }
            }
        } else if(messageSort.clickedButton() == button7){
            for (int i = 0; i < amount - 1; i++) {
                for (int j = 0; j < amount - i - 1; j++) {
                    if (productsfromfile[j].GetName() > productsfromfile[j + 1].GetName()) {
                        std::swap(productsfromfile[j], productsfromfile[j + 1]);
                    }
                }
            }
        } else if(messageSort.clickedButton() == button8){
            for (int i = 0; i < amount - 1; i++) {
                for (int j = 0; j < amount - i - 1; j++) {
                    if (productsfromfile[j].GetCost() > productsfromfile[j + 1].GetCost()) {
                        std::swap(productsfromfile[j], productsfromfile[j + 1]);
                    }
                }
            }
        }

        for (int i = 0; i < amount - 1; i++) {
            for (int j = 0; j < amount - i - 1; j++) {
                if (productsfromfile[j].GetGroup() > productsfromfile[j + 1].GetGroup()) {
                    std::swap(productsfromfile[j], productsfromfile[j + 1]);
                } else if (productsfromfile[j].GetGroup() == productsfromfile[j + 1].GetGroup()) {
                    if (messageSort.clickedButton() == button6 && productsfromfile[j].GetCode() > productsfromfile[j + 1].GetCode()) {
                        std::swap(productsfromfile[j], productsfromfile[j + 1]);
                    } else if (messageSort.clickedButton() == button7 && productsfromfile[j].GetName() > productsfromfile[j + 1].GetName()) {
                        std::swap(productsfromfile[j], productsfromfile[j + 1]);
                    } else if (productsfromfile[j].GetCost() > productsfromfile[j + 1].GetCost()) {
                        std::swap(productsfromfile[j], productsfromfile[j + 1]);
                    }
                }
            }
        }


        for (int i = 0; i < amount; i++) {
            ui->textBrowser->append(productsfromfile[i].ToString());
        }

    } else if(message.clickedButton() == button2){
        QDialog dialog(this);
        QFormLayout form(&dialog);

        QLineEdit *indexInput = new QLineEdit(&dialog);
        form.addRow("Number", indexInput);

        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
        form.addRow(&buttonBox);
        QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
        QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

        if (dialog.exec() == QDialog::Accepted) {
            int cost = indexInput->text().toInt();
            for (int i = 0; i < amount; i++) {
                if (productsfromfile[i].GetCost() < cost) {
                    ui->textBrowser->append(productsfromfile[i].ToString());
                }
            }

        }
    } else if(message.clickedButton() == button3){
        QMessageBox messageFind;
        messageFind.setText("Find: ");

        QAbstractButton* button4 = messageFind.addButton("Name", QMessageBox::NoRole);
        QAbstractButton* button5 = messageFind.addButton("Model", QMessageBox::NoRole);

        messageFind.exec();

        QDialog dialog(this);
        QFormLayout form(&dialog);

        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
        form.addRow(&buttonBox);
        QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
        QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

        if(messageFind.clickedButton() == button4){
            QLineEdit *indexInput = new QLineEdit(&dialog);
            form.addRow("Name", indexInput);

            if (dialog.exec() == QDialog::Accepted) {
                QString name = indexInput->text();
                for (int i = 0; i < amount; i++) {
                    if (productsfromfile[i].GetName() == name) {
                        ui->textBrowser->append(productsfromfile[i].ToString());
                    }
                }
            }
        } else if(messageFind.clickedButton() == button5){
            QLineEdit *indexInput = new QLineEdit(&dialog);
            form.addRow("Name", indexInput);

            if (dialog.exec() == QDialog::Accepted) {
                QString model = indexInput->text();
                for (int i = 0; i < amount; i++) {
                    if (productsfromfile[i].GetModel() == model) {
                        ui->textBrowser->append(productsfromfile[i].ToString());
                    }
                }
            }
        }
    }
}
