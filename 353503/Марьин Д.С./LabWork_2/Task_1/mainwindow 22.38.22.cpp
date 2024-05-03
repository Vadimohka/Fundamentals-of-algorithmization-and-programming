#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("\"Danil Mariyn\"Lab_2_1");
    ui->lineEdit->setInputMask("00.00.0000;_");
    ui->line_addDate->setInputMask("00.00.0000;_");
    ui->line_deleteRow->setInputMask("000");
    ui->lineToEdit->setInputMask("00;");
    ui->lineEdit_2->setInputMask("00.00.0000;_");
    ui->checkBox_File_sellect->setEnabled(false);
    setTodayDate();
    table = new Table();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    pathToFile = QFileDialog::getOpenFileName(this,tr("Open File"),"/Documents");
    if (pathToFile.isEmpty())
    {
        QMessageBox::warning(this, "Error!!!", "No one file selected.");
        WasOpen = false;
        return;
    }

    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    QString str;
    while (!fileStream.atEnd())
    {
        str = fileStream.readLine();
        QDate date = QDate::fromString(str,"dd.MM.yyyy");
        if (!date.isValid())
        {
            QMessageBox::warning(this, "Error", "Error to read information from file / Wrong Format of Date.");
            WasOpen = false;
            file.close();
            return;
        }
    }
    file.close();
    ui->checkBox_File_sellect->setCheckState(Qt::Checked);
    putDataFromFileToTable();
}

void MainWindow::putDataFromFileToTable()
{
    if (pathToFile.isEmpty())
        return;
    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);
    QString s;
    do {
        fileStream >> s;
        if (!s.isEmpty())
        {
            QDate date = QDate::fromString(s, "dd.MM.yyyy");
            if (!date.isNull())
            {
                tableDate.push_back(new Date(date));
            }
        }
    } while (!fileStream.atEnd());
    ui->checkBox_File_sellect->setChecked(true);
    table->setTableInfo(tableDate);
    ui->gridLayout_5->addWidget(table);
    table->show();
    WasTableCreated = true;
    file.close();
}

void MainWindow::setTodayDate()
{
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    Date current(timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    ui->lbl_todayDate->setText(current.toString());
}

void MainWindow::on_btn_select_clicked()
{
    openFile();
    qDebug() << pathToFile;
}

void MainWindow::on_lineEdit_returnPressed()
{
    birthdaydate = ui->lineEdit->text();
    QDate d = QDate::fromString(birthdaydate, "dd.MM.yyyy");
    if(!d.isNull())
    {
        Date date(d);
        ui->lblBirthday->setNum(date.DaysTillYourBithday(date));
    }
    else
    {
        ui->lineEdit->clear();
        QMessageBox::information(this,"Incorrect Input!!!","Please enter correct input!");
    }
}

void MainWindow::on_line_addDate_returnPressed()
{
    QString str = ui->line_addDate->text();
    QDate d = QDate::fromString(str, "dd.MM.yyyy");
    if(!d.isNull() && WasTableCreated)
    {
        Date date(d);
        table->addRow(&date);
        file.open(QIODevice::ReadWrite);
        QTextStream fileStream(&file);
        fileStream.seek((table->rowCount()) * 10 * sizeof(char));
        fileStream <<"\n"<< date.toString();
        file.close();
    }
    else
    {
        ui->line_addDate->clear();
        QMessageBox::information(this,"Incorrect Input!!!","Please enter correct input!");
    }
}

void MainWindow::on_line_deleteRow_returnPressed()
{
    int n = ui->line_deleteRow->text().toInt();
    if(n > table->rowCount() || !WasTableCreated)
    {
        ui->line_deleteRow->clear();
        QMessageBox::information(this,"Incorrect Input!!!","Please enter correct input!");
    }
    else
    {
        table->remove_Row(n);
        table->DelRow(&file,n);
    }
}


void MainWindow::on_lineToEdit_returnPressed()
{
    int n = ui->lineToEdit->text().toInt();
    if(n > table->rowCount() || !WasTableCreated)
    {
        ui->lineToEdit->clear();
        QMessageBox::information(this,"Incorrect Input!!!","Please enter correct input!");
    }
    else
    {
        QDate d = QDate::fromString(EditDate, "dd.MM.yyyy");
        if(!d.isNull())
        {
            Date date(d);
            table->EditRow(date,n);
            file.open(QIODevice::ReadWrite);
            QTextStream fileStream(&file);
            fileStream.seek((n-1) * 11 * sizeof(char));
            fileStream << date.toString() << "\n";
            file.close();
        }
        else
        {
            QMessageBox::information(this,"Incorrect Input!!!","Please enter correct input!");
        }
    }

}

void MainWindow::on_lineEdit_2_returnPressed()
{
    EditDate = ui->lineEdit_2->text();
    QDate d = QDate::fromString(EditDate, "dd.MM.yyyy");
    if(d.isNull() && !WasTableCreated)
    {
        ui->line_addDate->clear();
        EditDate.clear();
        QMessageBox::information(this,"Incorrect Input!!!","Please enter correct input!");
    }
}

