#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    FileInputOutput::clear(pathToBinStruct);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        && ui->doubleSpinBox->hasFocus()) {
        ui->inputEdit->setText(ui->inputEdit->toPlainText()
                               + QString::number(ui->doubleSpinBox->value()) + ">");
        array.push_back(ui->doubleSpinBox->value());
    }
}

void MainWindow::on_inputButton_clicked()
{
    if (ui->inputEdit->toPlainText() != "") {
        switch (ui->comboBox->currentIndex()) {
        case 0: {
            FileInputOutput::writeToFile(pathToSimpleParagraph, ui->inputEdit->toPlainText());
            break;
        }
        case 1: {
            if (!array.empty()) {
                FileInputOutput::writeArrayToFile(pathToArray, array);
            }
            break;
        }
        case 2: {
            FileInputOutput::writeStructToTxtFile(pathToTxtStruct, notebook);
            break;
        }
        case 3: {
            FileInputOutput::writeStructToBinFile(pathToBinStruct, notebook);
            break;
        }
        case 4: {
            FileInputOutput::appendSentenceToFile(pathToListSentences, ui->inputEdit->toPlainText());
            break;
        }
        }
    }
}

void MainWindow::on_outputButton_clicked()
{
    switch (ui->comboBox->currentIndex()) {
    case 0: {
        ui->outputEdit->setText(FileInputOutput::readFromFile(pathToSimpleParagraph));
        break;
    }
    case 1: {
        ui->outputEdit->setText(FileInputOutput::readArrayFromFile(pathToArray));
        break;
    }
    case 2: {
        ui->outputEdit->clear();
        for (int i = 0; i < FileInputOutput::readStructFromTxtFile(pathToTxtStruct).size(); ++i) {
            ui->outputEdit->setText(
                ui->outputEdit->toPlainText()
                + FileInputOutput::readStructFromTxtFile(pathToTxtStruct)[i].tooString() + "\n");
        }
        break;
    }
    case 3: {
        ui->outputEdit->clear();
        for (int i = 0; i < FileInputOutput::readStructFromBinFile(pathToBinStruct).size(); ++i) {
            ui->outputEdit->setText(
                ui->outputEdit->toPlainText()
                + FileInputOutput::readStructFromBinFile(pathToBinStruct)[i].tooString() + "\n");
        }
        break;
    }
    case 4: {
        ui->outputEdit->setText(FileInputOutput::readFromFile(pathToListSentences));
        break;
    }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    if (index == 0 || index == 4) {
        ui->inputEdit->setReadOnly(false);
    } else {
        ui->inputEdit->setReadOnly(true);
    }
    ui->inputEdit->clear();
    ui->outputEdit->clear();
}

void MainWindow::on_clearButton_clicked()
{
    ui->inputEdit->clear();
    if (ui->comboBox->currentIndex() == 1) {
        array.clear();
    }
}

void MainWindow::on_addButtonBin_clicked() // Add_notebook_bin
{
    if(ui->lineEdit_Add_2->text() == "" || ui->lineEdit_2_Add_2->text() == "" || ui->lineEdit_3_Add_2->text() == "" || ui->lineEdit_4_Add_2->text() == "" || ui->lineEdit_3_Add_2->text().size() < 10 || ui->lineEdit_4_Add_2->text().size() < 9)
    {
        ui->label_13_Add_2->setText("Неверно заданы характеристики");
        return;
    }
    else
        ui->label_13_Add_2->setText("");

    notebook = notebook.toSelf(QString::number(ui->spinBox_Add_2->value()) + " | " +
                               ui->lineEdit_Add_2->text() + " | " +
                               ui->lineEdit_2_Add_2->text() + " | " +
                               QString::number(ui->CheckBox_Add_2->isChecked()) + " | " +
                               ui->lineEdit_3_Add_2->text() + " | " +
                               ui->lineEdit_4_Add_2->text());

    ui->inputEdit->setText(notebook.tooString());
}

void MainWindow::on_pushButton_Add_clicked() // Add_notebook
{
    if(ui->lineEdit_Add->text() == "" || ui->lineEdit_2_Add->text() == "" || ui->lineEdit_3_Add->text() == "" || ui->lineEdit_4_Add->text() == "" || ui->lineEdit_3_Add->text().size() < 10 || ui->lineEdit_4_Add->text().size() < 9)
    {
        ui->label_13_Add->setText("Неверно заданы характеристики");
        return;
    }
    else
        ui->label_13_Add->setText("");

    notebook = notebook.toSelf(QString::number(ui->spinBox_Add->value()) + " | " +
                                ui->lineEdit_Add->text() + " | " +
                                ui->lineEdit_2_Add->text() + " | " +
                                QString::number(ui->CheckBox_Add->isChecked()) + " | " +
                                ui->lineEdit_3_Add->text() + " | " +
                                ui->lineEdit_4_Add->text());

    ui->inputEdit->setText(notebook.tooString());
}

void MainWindow::on_lineEdit_Add_textChanged(const QString &arg1)
{
    int count = 0;
    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] == '.')
            count++;

        if(((arg1[i] < '0' || arg1[i] > '9') && arg1[i] != '.') || count > 1 || arg1.size() > 10)
        {
            QString txt = ui->lineEdit_Add->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit_Add->setText(txt);
            return;
        }
    }
}


void MainWindow::on_lineEdit_2_Add_textChanged(const QString &arg1)
{
    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] < 'A' || arg1[i] > 'Z' || arg1.size() > 1)
        {
            QString txt = ui->lineEdit_2_Add->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit_2_Add->setText(txt);
            return;
        }
    }
}


void MainWindow::on_lineEdit_3_Add_textChanged(const QString &arg1)
{
    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] < '0' || arg1[i] > '9' || arg1.size() > 10)
        {
            QString txt = ui->lineEdit_3_Add->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit_3_Add->setText(txt);
            return;
        }
    }
}


void MainWindow::on_lineEdit_4_Add_textChanged(const QString &arg1)
{
    for(int i = 0; i < arg1.size(); i++)
    {
        if(((arg1[i] < 'A' || arg1[i] > 'Z') && (arg1[i] < 'a' || arg1[i] > 'z')) || arg1.size() > 9)
        {
            QString txt = ui->lineEdit_4_Add->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit_4_Add->setText(txt);
            return;
        }
    }
}


void MainWindow::on_lineEdit_Add_2_textChanged(const QString &arg1)
{
    int count = 0;
    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] == '.')
            count++;

        if(((arg1[i] < '0' || arg1[i] > '9') && arg1[i] != '.') || count > 1 || arg1.size() > 10)
        {
            QString txt = ui->lineEdit_Add_2->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit_Add_2->setText(txt);
            return;
        }
    }
}


void MainWindow::on_lineEdit_2_Add_2_textChanged(const QString &arg1)
{
    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] < 'A' || arg1[i] > 'Z' || arg1.size() > 1)
        {
            QString txt = ui->lineEdit_2_Add_2->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit_2_Add_2->setText(txt);
            return;
        }
    }
}


void MainWindow::on_lineEdit_3_Add_2_textChanged(const QString &arg1)
{
    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] < '0' || arg1[i] > '9' || arg1.size() > 10)
        {
            QString txt = ui->lineEdit_3_Add_2->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit_3_Add_2->setText(txt);
            return;
        }
    }
}


void MainWindow::on_lineEdit_4_Add_2_textChanged(const QString &arg1)
{
    for(int i = 0; i < arg1.size(); i++)
    {
        if(((arg1[i] < 'A' || arg1[i] > 'Z') && (arg1[i] < 'a' || arg1[i] > 'z')) || arg1.size() > 9)
        {
            QString txt = ui->lineEdit_4_Add_2->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit_4_Add_2->setText(txt);
            return;
        }
    }
}

