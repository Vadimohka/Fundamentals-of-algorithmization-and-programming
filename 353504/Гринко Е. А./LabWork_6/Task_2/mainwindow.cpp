#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::inputText(QString fileName) {
    QString text = ui->textEdit->toPlainText();

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        for (const QChar &c : text) {
            stream << c;
        }
        file.close();
        QMessageBox::information(this, "Success", "Text successfully written to the file.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to open the file for writing.");
    }
}

void MainWindow::outputText(QString fileName) {
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString text;
        QChar c;
        while (!stream.atEnd()) {
            stream >> c;
            text.append(c);
        }
        file.close();
        QMessageBox::information(this, "Text from the file", text);
    } else {
        QMessageBox::critical(this, "Error", "Failed to open the file for reading.");
    }
}

void MainWindow::saveArrayToFile(QString fileName) {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        for (int i = 0; i < _vec.size(); ++i) {
            stream << _vec.at(i);
            if (i + 1 < _vec.size()) {
                stream << "^";
            }
        }
        file.close();
        QMessageBox::information(this, "Success", "Array successfully written to the file.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to open the file for writing.");
    }
}

void MainWindow::writeCityToTextFile(const QString &fileName) {
    QFile file(fileName);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << ui->populationBox->value() << "|" << ui->areaDBox->value() << "|" <<
               static_cast<char>(ui->categoryBox->value()) << "|"
               << ui->checkBox->isChecked() << "|" << ui->nameLine->text() << "|" <<
               ui->aBox->value() << " " << ui->bBox->value() << " " << ui->cBox->value();
        stream << "\n";
        file.close();
        QMessageBox::information(this, "Success", "Struct successfully written to the file.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Failed to open the file for writing.");
    }
}

void MainWindow::writeCityToBinaryFile(const QString &fileName) {
    City city;
    city.population = ui->populationBox->value();
    city.area = ui->areaDBox->value();
    city.category = ui->categoryBox->value();
    city.isCapital = ui->checkBox->isChecked();
    strcpy(city.name, ui->nameLine->text().toStdString().c_str());
    city.features[0] = ui->aBox->value();
    city.features[1] = ui->bBox->value();
    city.features[2] = ui->cBox->value();

    QFile file(fileName);
    if (file.open(QIODevice::Append)) {
        QDataStream stream(&file);
        stream.writeRawData(reinterpret_cast<const char*>(&city), sizeof(City));
        file.close();
        QMessageBox::information(this, "Success", "Struct successfully written to the binary file.");
    } else {
        QMessageBox::critical(nullptr, "Error", "Failed to open the file for writing.");
    }
}

void MainWindow::showCitiesFromBinaryFile(const QString &fileName) {
    QVector<City> cities;
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream stream(&file);
        while (!stream.atEnd()) {
            City city;
            stream.readRawData(reinterpret_cast<char*>(&city), sizeof(City));
            cities.append(city);
        }
        file.close();

        QString message;
        for (const City &city : cities) {
            message += QString("Population: %1, Area: %2, Category: %3, Capital: %4, Name: %5, Features: ")
                           .arg(city.population)
                           .arg(city.area)
                           .arg(city.category)
                           .arg(city.isCapital ? "Yes" : "No")
                           .arg(city.name);

            for (int i = 0; i < City::numFeatures; ++i) {
                message += QString::number(city.features[i]);
                if (i < City::numFeatures - 1) {
                    message += " ";
                }
            }
            message += "\n";
        }

        QMessageBox::information(this, "Cities from Binary File", message);
    } else {
        QMessageBox::critical(nullptr, "Error", "Failed to open the file for reading.");
    }
}

void MainWindow::appendSentenceToFile(const QString &fileName) {
    QString sentence = ui->lineEdit->text();
    QFile file(fileName);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << sentence << "\n";
        file.close();
        QMessageBox::information(this, "Success", "Sentence successfully appended to the file.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to open the file for writing.");
    }
}

void MainWindow::readSentencesFromFile(const QString &fileName) {
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString sentences;
        while (!stream.atEnd()) {
            QString sentence = stream.readLine();
            sentences += sentence + "\n";
        }
        file.close();
        QMessageBox::information(this, "Sentences from File", sentences);
    } else {
        QMessageBox::critical(this, "Error", "Failed to open the file for reading.");
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _vec.resize(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sizeBox_valueChanged(int arg1)
{
    _vec.resize(arg1);
    ui->posBox->setMaximum(arg1 - 1);
}


void MainWindow::on_valueBox_valueChanged(int arg1)
{
    _vec[ui->posBox->value()] = arg1;
}


void MainWindow::on_posBox_valueChanged(int arg1)
{
    ui->valueBox->setValue(_vec.at(arg1));
}

void MainWindow::on_parargraphBtn_clicked()
{
    inputText("DergunLab20.txt");
    outputText("DergunLab20.txt");
}

void MainWindow::on_arrayBtn_clicked()
{
    saveArrayToFile("DergunLab20_0.txt");
    outputText("DergunLab20_0.txt");
}

void MainWindow::on_appendBtn_clicked()
{
    writeCityToTextFile("DergunLab20_1.txt");
    outputText("DergunLab20_1.txt");
}

void MainWindow::on_structBtn_clicked()
{
    writeCityToBinaryFile("DergunLab20_2.txt");
    showCitiesFromBinaryFile("DergunLab20_2.txt");
}

void MainWindow::on_sentenceBtn_clicked()
{
    appendSentenceToFile("DergunLab20_3.txt");
    readSentencesFromFile("DergunLab20_3.txt");
}

void MainWindow::on_finishBtn_clicked()
{
    close();
}
