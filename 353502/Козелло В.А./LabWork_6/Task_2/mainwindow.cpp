#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "watches.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->form->hide();
    ui->output->setText("Введите абзац текста, после чего нажмите клавишу \"Enter\"");
    ui->serialLetter->setMaxLength(1);
    ui->name->setMaxLength(29);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeParagraph()
{
    QString str = ui->inputLine->text();
    ui->inputLine->clear();

    std::ofstream out;
    out.open("../KozelloLab20.txt");
    if (out.is_open()) {
        out << str.toStdString();
    }
    out.close();
    readParagraph();
}

void MainWindow::readParagraph()
{
    std::string line;
    std::ifstream in("../KozelloLab20.txt");
    if (in.is_open()) {
        std::getline(in, line);
        ui->output->setText(QString(line.c_str()));
    }
    in.close();
}

void MainWindow::writeArray()
{
    QString str = ui->inputLine->text();
    QString res;
    if (checkArray()) {
        ui->inputLine->clear();
        QStringList parts = str.split(' ');
        for (int i = 1; i <= parts[0].toInt(); i++) {
            res.append(parts[i] + '}');
        }
        res.chop(1);
        std::ofstream out;
        out.open("../KozelloLab20_0.txt");
        if (out.is_open()) {
            out << res.toStdString();
        }
        out.close();
        readArray();

    } else {
        QMessageBox::critical(this, "", "ошибка ввода!");
    }
}

void MainWindow::readArray()
{
    std::string line;
    std::ifstream in("../KozelloLab20_0.txt");
    ui->output->clear();
    if (in.is_open()) {
        QVector<double> array;
        char ch = 0;
        std::string numStr;
        while (in >> ch) {
            if (ch == '}') {
                if (!numStr.empty()) {
                    array.push_back(QString(numStr.c_str()).toDouble());
                    numStr.clear();
                }
            } else {
                numStr += ch;
            }
        }
        array.push_back(QString(numStr.c_str()).toDouble());
        QString str;
        for (const double num : array) {
            str.append(QString::number(num) + ' ');
        }
        ui->output->setText(str);
    }
    in.close();
}

bool MainWindow::checkArray()
{
    QString str = ui->inputLine->text();
    QStringList parts = str.split(' ');
    bool isNumber = false;
    if (!parts[0].toInt(&isNumber)) {
        return false;
    }
    int size = parts[0].toInt();
    parts.removeAt(0);
    if (size != parts.size()) {
        return false;
    }

    for (const QString &part : parts) {
        part.toDouble(&isNumber);
        if (!isNumber) {
            return false;
        }
    }

    return true;
}

void MainWindow::writeStruct(Watches watches)
{
    std::ofstream out("../KozelloLab20_1.txt", std::ios::app);
    if (out.is_open()) {
        out << watches.hours << std::endl;
        out << watches.minutes << std::endl;
        out << watches.seconds << std::endl;
        out << QString(watches.name).toStdString() << std::endl;
        out << watches.serialLetter << std::endl;
        out << watches.serialNumber << std::endl;
        out << watches.waterResistance << std::endl;
        out << watches.detailsNumbers[0] << std::endl;
        out << watches.detailsNumbers[1] << std::endl;
        out << watches.detailsNumbers[2] << std::endl;
        out << watches.detailsNumbers[3] << std::endl;
        out << watches.detailsNumbers[4] << std::endl;
    }
    out.close();
    readStructs();
}

void MainWindow::readStructs()
{
    std::string line;
    std::ifstream in("../KozelloLab20_1.txt");
    ui->output->clear();
    Watches temp;
    if (in.is_open()) {
        int k = 0;
        while (std::getline(in, line)) {
            k++;
            ui->output->append("Поле " + QString::number(k) + ": " + QString(line.c_str()));
            if (k % 12 == 0) {
                ui->output->append("");
                k = 0;
            }
        }
    }
    in.close();
}

void MainWindow::writeBinStruct(Watches watches)
{
    std::ofstream out("../KozelloLab20_2.bin", std::ios::binary | std::ios::app);
    if (out.is_open()) {
        out.write(reinterpret_cast<char *>(&watches), sizeof watches);
        int len = strlen(watches.name);
        out.write(reinterpret_cast<char *>(&len), sizeof(len));
        out.write(watches.name, len);
    }
    out.close();
    readBinStructs();
}

void MainWindow::readBinStructs()
{
    std::ifstream in("../KozelloLab20_2.bin", std::ios::binary);
    if (in.is_open()) {
        Watches temp;
        ui->output->clear();
        while (in.read(reinterpret_cast<char *>(&temp), sizeof(temp))) {
            int strLength;
            in.read(reinterpret_cast<char *>(&strLength), sizeof(strLength));
            temp.name = new char[strLength + 1];
            in.read(temp.name, strLength);
            temp.name[strLength] = '\0';
            ui->output->append(temp.toString());
            ui->output->append("");
        }
    }
    in.close();
}

void MainWindow::writeSentence()
{
    QString str = ui->inputLine->text();
    ui->inputLine->clear();

    std::ofstream out("../KozelloLab20_3.txt", std::ios::app);
    if (out.is_open()) {
        out << str.toStdString() << ' ';
    }
    out.close();
    readSentence();
}

void MainWindow::readSentence()
{
    std::string line;

    std::ifstream in("../KozelloLab20_3.txt");
    if (in.is_open()) {
        while (std::getline(in, line)) {
            ui->output->setText(QString(line.c_str()));
        }
    }
    in.close();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->form->hide();
        ui->inputLine->show();
        ui->output->setText("Введите абзац текста, после чего нажмите клавишу \"Enter\"");
        break;
    case 1:
        ui->form->hide();
        ui->inputLine->show();
        ui->output->setText("Введите сперва размер массива, а затем через пробел значения типа "
                            "double, после чего нажмите клавишу \"Enter\"");
        break;
    case 2:
        ui->form->show();
        ui->inputLine->hide();
        ui->output->setText("Заполните форму и нажмите кнопку \"Записать\"");
        break;
    case 3:
        ui->form->show();
        ui->inputLine->hide();
        ui->output->setText("Заполните форму и нажмите кнопку \"Записать\"");
        break;
    case 4:
        ui->form->hide();
        ui->inputLine->show();
        ui->output->setText("Введите предложение, после чего нажмите клавишу \"Enter\"");
        break;
    }
}

void MainWindow::on_inputLine_returnPressed()
{
    if (ui->comboBox->currentIndex() == 0) {
        writeParagraph();
    } else if (ui->comboBox->currentIndex() == 1) {
        writeArray();
    } else {
        writeSentence();
    }
}

void MainWindow::on_submit_clicked()
{
    if (isEnglish(ui->name->text()) && isEnglish(ui->serialLetter->text())) {
        Watches temp;
        temp.hours = ui->hours->value();
        temp.minutes = ui->minutes->value();
        temp.seconds = ui->seconds->value();

        temp.name = (char *) ui->name->text().toStdString().c_str();
        temp.serialLetter = *ui->serialLetter->text().toStdString().c_str();

        temp.serialNumber = ui->serialNumber->value();
        temp.waterResistance = ui->waterResistance->currentIndex();
        temp.detailsNumbers[0] = ui->detail_1->value();
        temp.detailsNumbers[1] = ui->detail_2->value();
        temp.detailsNumbers[2] = ui->detail_3->value();
        temp.detailsNumbers[3] = ui->detail_4->value();
        temp.detailsNumbers[4] = ui->detail_5->value();

        if (ui->comboBox->currentIndex() == 2) {
            writeStruct(temp);
        } else {
            writeBinStruct(temp);
        }

    } else {
        QMessageBox::critical(
            this, "", "Неверно введены данные, строки могут содержать только английские символы");
    }
}
