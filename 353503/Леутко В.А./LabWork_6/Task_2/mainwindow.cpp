#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textEdit_output->setReadOnly(true);

    QButtonGroup* abcdGroup = new QButtonGroup(this);
    abcdGroup->addButton(ui->checkBox_A, 0);
    abcdGroup->addButton(ui->checkBox_B, 1);
    abcdGroup->addButton(ui->checkBox_C, 2);
    abcdGroup->addButton(ui->checkBox_D, 3);
    abcdGroup->setExclusive(true);

    QButtonGroup* yesNoGroup = new QButtonGroup(this);
    yesNoGroup->addButton(ui->checkBox_yes, 0);
    yesNoGroup->addButton(ui->checkBox_no, 1);
    yesNoGroup->setExclusive(true);

    connect(ui->textEdit_input, &QTextEdit::textChanged, this, &MainWindow::updateOutputText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputBtn_clicked()
{
    switch (ui->comboBox->currentIndex()) {
    case 0: {
        if (ui->textEdit_input->toPlainText() != ""){
            recordTextToFile();
        }
        break;
    }
    case 1: {
        recordArrayToFile();
        break;
    }
    case 2: {
        appendStructToFile();
        break;
    }
    case 3: {
        appendStructToFileBin();
        break;
    }
    case 4: {
        appendTextToFile();
        break;
    }
    }
}

void MainWindow::on_outputBtn_clicked()
{
    switch (ui->comboBox->currentIndex()) {
    case 0: {
        readTextFromFile();
        break;
    }
    case 1: {
        readArrayFromFile();
        break;
    }
    case 2: {
        readStructFromFile();
        break;
    }
    case 3: {
        readStructFromFileBin();
        break;
    }
    case 4: {
        readTextFromFile();
        break;
    }
    }
}

QString MainWindow::printInfo(const AutoRepairShop &shop)
{
    QString info = QString("%1|%2|%3|%4|%5")
                       .arg(QString::number(shop.age))
                       .arg(QString::number(shop.repairBill))
                       .arg(shop.isCertificated ? "yes" : "no")
                       .arg(shop.category == '\0' ? "N/A" : QString(shop.category))
                       .arg(QString::fromLocal8Bit(shop.autoName.data(), shop.autoName.size() - 1));

    for (int i = 0; i < MAX_BREAKDOWNS; ++i)
    {
        info += QString("|%1").arg(QString::number(shop.breakdowns[i]));
    }

    return info;
}

void MainWindow::recordTextToFile()
{
    QString text = ui->textEdit_input->toPlainText();
    if (!text.isEmpty())
    {
        QString projectDir = QFileInfo(__FILE__).absolutePath();
        QString filePath = QFileDialog::getSaveFileName(this, "Save File", projectDir, "Text Files (*.txt)");
        if (!filePath.isEmpty())
        {
            currentFilePath = filePath;
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream out(&file);
                for (const auto& c : text)
                {
                    out << c;
                }
                file.close();
                QMessageBox::information(this, "Success", "Text has been saved to " + filePath + ".");
            }
            else
            {
                QMessageBox::critical(this, "Error", "Failed to open file for recording.");
            }
        }
    }
}

void MainWindow::appendTextToFile()
{
    QString text = ui->textEdit_input->toPlainText();
    if (!text.isEmpty())
    {
        QString projectDir = QFileInfo(__FILE__).absolutePath();
        QString filePath = QFileDialog::getSaveFileName(this, "Save File", projectDir, "Text Files (*.txt)");
        if (!filePath.isEmpty())
        {
            currentFilePath = filePath;
            QFile file(filePath);
            if (file.open(QIODevice::Append | QIODevice::Text))
            {
                QTextStream out(&file);
                out << "\n" << text;
                file.close();
                QMessageBox::information(this, "Success", "Text has been appended to " + filePath + ".");
            }
            else
            {
                QMessageBox::critical(this, "Error", "Failed to open file for writing.");
            }
        }
    }
}

void MainWindow::readTextFromFile()
{
    QString projectDir = QFileInfo(__FILE__).absolutePath();
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", projectDir, "Text Files (*.txt)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString text = in.readAll();
            file.close();
            ui->textEdit_output->setPlainText(text);
        } else {
            QMessageBox::critical(this, "Error", "Failed to open file for reading.");
        }
    }
}

void MainWindow::recordArrayToFile()
{
    int size = QInputDialog::getInt(this, "Write array", "Enter array size:");
    if (size <= 0) {
        return;
    }

    std::vector<int> array(size);
    for (int i = 0; i < size; i++) {
        bool ok;
        int element = QInputDialog::getInt(this, "Write array", QString("Enter element %1:").arg(i + 1), 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), 1, &ok);
        if (!ok) {
            return;
        }
        array[i] = element;
    }

    QString projectDir = QFileInfo(__FILE__).absolutePath();
    QString filePath = QFileDialog::getSaveFileName(this, "Save Array", projectDir, "Array Files (*.txt)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            QString arrayText;
            for (int i = 0; i < size; i++) {
                out << array[i];
                arrayText += QString::number(array[i]);
                if (i < size - 1) {
                    out << ":";
                    arrayText += ":";
                }
            }
            file.close();
            ui->textEdit_input->setText(arrayText);
            QMessageBox::information(this, "Success", "Array has been saved to " + filePath + ".");
        } else {
            QMessageBox::critical(this, "Error", "Failed to open file for writing.");
        }
    }
}

void MainWindow::readArrayFromFile()
{
    QString projectDir = QFileInfo(__FILE__).absolutePath();
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", projectDir, "Text Files (*.txt)");

    std::vector<int> array;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;
        while (!in.atEnd()) {
            line = in.readLine();
            QStringList elements = line.split(":");
            for (const QString& element : elements) {
                bool ok;
                int value = element.toInt(&ok);
                if (ok) {
                    array.push_back(value);
                }
            }
        }
        file.close();

        QString arrayText;
        for (int i = 0; i < array.size(); i++) {
            arrayText += QString::number(array[i]) + " ";
        }
        ui->textEdit_output->setPlainText(arrayText.trimmed());
        QMessageBox::information(this, "Array from File", "Array elements:\n" + arrayText);
    } else {
        QMessageBox::critical(this, "Error", "Failed to open file for reading.");
    }
}

void MainWindow::appendStructToFile()
{
    QString projectDir = QFileInfo(__FILE__).absolutePath();
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", projectDir, "Text Files (*.txt)");

    AutoRepairShop shop4;

    shop4.age = ui->spinBox_age->value();
    shop4.repairBill = ui->spinBox_repairBill->value();

    if (ui->checkBox_yes->isChecked()) {
        shop4.isCertificated = true;
        ui->checkBox_no->setChecked(false);
    } else if (ui->checkBox_no->isChecked()) {
        shop4.isCertificated = false;
        ui->checkBox_yes->setChecked(false);
    }

    if (ui->checkBox_A->isChecked()) {
        shop4.category = 'A';
        ui->checkBox_B->setChecked(false);
        ui->checkBox_C->setChecked(false);
        ui->checkBox_D->setChecked(false);
    } else if (ui->checkBox_B->isChecked()) {
        shop4.category = 'B';
        ui->checkBox_A->setChecked(false);
        ui->checkBox_C->setChecked(false);
        ui->checkBox_D->setChecked(false);
    } else if (ui->checkBox_C->isChecked()) {
        shop4.category = 'C';
        ui->checkBox_A->setChecked(false);
        ui->checkBox_B->setChecked(false);
        ui->checkBox_D->setChecked(false);
    } else if (ui->checkBox_D->isChecked()) {
        shop4.category = 'D';
        ui->checkBox_A->setChecked(false);
        ui->checkBox_B->setChecked(false);
        ui->checkBox_C->setChecked(false);
    } else {
        shop4.category = '\0'; // Нет выбранной категории
    }

    QString autoNameQString = ui->lineEdit->text();
    strncpy(shop4.autoName.data(), autoNameQString.toLocal8Bit().constData(), shop4.autoName.size() - 1);
    shop4.autoName[shop4.autoName.size() - 1] = '\0';

    for (int i = 0; i < MAX_BREAKDOWNS; i++) {
        shop4.breakdowns[i] = ui->spinBox_breakdowns->value();
    }

    QString info = printInfo(shop4);

    QFile file(filePath);
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << info << "\n";
        file.close();
        QMessageBox::information(this, "Success", "Structure has been saved to " + filePath + ".");
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to open file for reading.");
    }
}

void MainWindow::readStructFromFile()
{
    QString projectDir = QFileInfo(__FILE__).absolutePath();
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", projectDir, "Text Files (*.txt)");

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        ui->textEdit_output->clear();
        while (!in.atEnd())
        {
            AutoRepairShop shop;
            QString line = in.readLine();
            QStringList fields = line.split("|");
            if (fields.size() == 15)
            {
                shop.age = fields[0].toInt();
                shop.repairBill = fields[1].toInt();
                shop.isCertificated = fields[2] == "true";
                shop.category = fields[3][0].toLatin1();
                strncpy(shop.autoName.data(), fields[4].toLocal8Bit().constData(), shop.autoName.size() - 1);
                shop.autoName[shop.autoName.size() - 1] = '\0';
                for (int i = 0; i < MAX_BREAKDOWNS; i++)
                {
                    shop.breakdowns[i] = fields[5 + i].toInt();
                }
                QString info = printInfo(shop);
                ui->textEdit_output->append(info);
            }
            else
            {
                ui->textEdit_output->append("Invalid line: " + line);
            }
        }
        file.close();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to open file for reading.");
    }
}

void MainWindow::appendStructToFileBin()
{
    QString filePath = "LeutkoLab20_2.bin";

    AutoRepairShop shop;

    shop.age = ui->spinBox_age->value();
    shop.repairBill = ui->spinBox_repairBill->value();

    if (ui->checkBox_yes->isChecked()) {
        shop.isCertificated = true;
        ui->checkBox_no->setChecked(false);
    } else if (ui->checkBox_no->isChecked()) {
        shop.isCertificated = false;
        ui->checkBox_yes->setChecked(false);
    }

    if (ui->checkBox_A->isChecked()) {
        shop.category = 'A';
        ui->checkBox_B->setChecked(false);
        ui->checkBox_C->setChecked(false);
        ui->checkBox_D->setChecked(false);
    } else if (ui->checkBox_B->isChecked()) {
        shop.category = 'B';
        ui->checkBox_A->setChecked(false);
        ui->checkBox_C->setChecked(false);
        ui->checkBox_D->setChecked(false);
    } else if (ui->checkBox_C->isChecked()) {
        shop.category = 'C';
        ui->checkBox_A->setChecked(false);
        ui->checkBox_B->setChecked(false);
        ui->checkBox_D->setChecked(false);
    } else if (ui->checkBox_D->isChecked()) {
        shop.category = 'D';
        ui->checkBox_A->setChecked(false);
        ui->checkBox_B->setChecked(false);
        ui->checkBox_C->setChecked(false);
    } else {
        shop.category = '\0'; // No category selected
    }

    QString autoNameQString = ui->lineEdit->text();
    strncpy(shop.autoName.data(), autoNameQString.toLocal8Bit().constData(), shop.autoName.size() - 1);
    shop.autoName[shop.autoName.size() - 1] = '\0';

    for (int i = 0; i < MAX_BREAKDOWNS; i++) {
        shop.breakdowns[i] = ui->spinBox_breakdowns->value();
    }

    QFile file(filePath);
    if (file.open(QFile::Append))
    {
        file.write((char*)&shop, sizeof(AutoRepairShop));
        file.close();
        QMessageBox::information(this, "Success", "Structure has been saved to " + filePath + ".");
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to open file for writing.");
    }
}

void MainWindow::readStructFromFileBin()
{
    QString filePath = "LeutkoLab20_2.bin";

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        ui->textEdit_output->clear();
        AutoRepairShop shop;
        while (file.read((char*)&shop, sizeof(AutoRepairShop)) == sizeof(AutoRepairShop))
        {
            QString info = QString("%1 ; %2 ; %3 ; %4 ; %5 ; %6 ; %7 ; %8 ; %9 ; %10 ; %11 ; %12 ; %13 ; %14 ; %15")
                               .arg(shop.age)
                               .arg(shop.repairBill)
                               .arg(shop.isCertificated ? "true" : "false")
                               .arg(shop.category)
                               .arg(QString::fromStdString(shop.autoName.data()))
                               .arg(shop.breakdowns[0])
                               .arg(shop.breakdowns[1])
                               .arg(shop.breakdowns[2])
                               .arg(shop.breakdowns[3])
                               .arg(shop.breakdowns[4])
                               .arg(shop.breakdowns[5])
                               .arg(shop.breakdowns[6])
                               .arg(shop.breakdowns[7])
                               .arg(shop.breakdowns[8])
                               .arg(shop.breakdowns[9]);
            ui->textEdit_output->append(info);
        }
        file.close();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to open file for reading.");
    }
}

void MainWindow::updateOutputText()
{
    if (currentFilePath == ui->textEdit_input->toPlainText()) {
        ui->textEdit_output->setPlainText(ui->textEdit_input->toPlainText());
    }
}




