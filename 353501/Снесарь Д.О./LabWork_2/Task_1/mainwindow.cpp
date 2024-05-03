#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableInfo->insertRow(0);
    ui->spinBoxChange->setMinimum(0);
    ui->spinBoxDelete->setMinimum(0);
    ui->spinBoxChange->setMaximum(0);
    ui->spinBoxDelete->setMaximum(0);
    QRegExp pattern("\\b(0[1-9]|[12][0-9]|3[01])\\.(0[1-9]|1[0-2])\\.\\d{4}\\b");
    QRegExpValidator *validator = new QRegExpValidator(pattern, this);
    ui->lineEdit->setValidator(validator);
}

MainWindow::~MainWindow()
{

    delete ui;
}

bool MainWindow::checkDate(QString str)
{

    QRegularExpression rx("\\b(0[1-9]|[12][0-9]|3[01])\\.(0[1-9]|1[0-2])\\.\\d{4}\\b");

    if (str.length() < 10 || str[2] != '.' || str[5] != '.')
        return false;

    QRegularExpressionMatch match = rx.match(str);
    if (!match.hasMatch())
        return false;

    QString day = str.mid(0, 2);
    QString month = str.mid(3, 2);
    QString year = str.mid(6, 4);

    int iday = day.toInt();
    int imonth = month.toInt();
    int iyear = year.toInt();

    Date date(str);
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    daysInMonth[1] = date.daysInYear(iyear) == 366 ? 29 : 28;

    if (iday > daysInMonth[imonth - 1])
        return false;

    return true;


}

void MainWindow::fileToTable()
{
    if (Path.isEmpty())
        return;


    File.setFileName(Path);
    File.open(QIODevice::ReadWrite);
    QTextStream fileStream(&File);
    QString strF;
    do {
        fileStream >> strF;
        if (!strF.isEmpty()) {
            int row = ui->tableInfo->rowCount();
            ui->tableInfo->insertRow(row);
            Date inputDate(strF);
            QTableWidgetItem* itm0 = new QTableWidgetItem(inputDate.getDateStr());
            QTableWidgetItem* itm1 = new QTableWidgetItem(inputDate.nextDay().getDateStr());

            QTableWidgetItem* previousItem = ui->tableInfo->item((row - 2), 0);
            if(previousItem != nullptr)
            {
                QString Text = previousItem->text();
                Date temp(Text);
                qDebug()<<temp.getDateStr();
                QTableWidgetItem* itm2 = new QTableWidgetItem(QString::number(inputDate.difference(temp)));
                ui->tableInfo->setItem(row - 1, 2, itm2);

            }
            ui->spinBoxChange->setMaximum(row);
            ui->spinBoxDelete->setMaximum(row);
            ui->tableInfo->setItem(row - 1, 0, itm0);
            ui->tableInfo->setItem(row - 1, 1, itm1);
            ui->tableInfo->update();
        }
    } while (!fileStream.atEnd());
    File.close();
}

void MainWindow::changeFile(int row, QString date)
{
    File.open(QIODevice::ReadWrite);
    QTextStream fileStream(&File);
    fileStream.seek((row - 1)* 11 * sizeof(char));
    fileStream << date << "\n";
    File.close();
}

void MainWindow::deleteFile(int row)
{
    File.open(QIODevice::ReadWrite);
    QStringList lines;
    QTextStream in(&File);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        lines.append(line);
    }

    File.resize(0);

    QTextStream out(&File);

    for (int i = 0; i < lines.size(); ++i)
    {
        if (i + 1 != (row))
        {
            out << lines.at(i) << Qt::endl;
        }
    }
    File.close();
}




void MainWindow::on_pushButton_clicked()
{
    int row = ui->tableInfo->rowCount();
    ui->tableInfo->insertRow(row);
    QString input = ui->lineEdit->text();
    Date inputDate(input);
    QTableWidgetItem* itm0 = new QTableWidgetItem(inputDate.getDateStr());
    QTableWidgetItem* itm1 = new QTableWidgetItem(inputDate.nextDay().getDateStr());

    QTableWidgetItem* previousItem = ui->tableInfo->item((row - 2), 0);
    if(previousItem != nullptr)
    {
        QString Text = previousItem->text();
        Date temp(Text);
        // qDebug()<<dd.getDateStr();
        QTableWidgetItem* itm2 = new QTableWidgetItem(QString::number(inputDate.difference(temp)));
        ui->tableInfo->setItem(row - 1, 2, itm2);

    }
    ui->spinBoxChange->setMaximum(row);
    ui->spinBoxDelete->setMaximum(row);
    ui->tableInfo->setItem(row - 1, 0, itm0);
    ui->tableInfo->setItem(row - 1, 1, itm1);

    File.open(QIODevice::ReadWrite);
    QTextStream fileStream(&File);
    fileStream.seek((row - 1) * 11 * sizeof(char));
    fileStream << input << "\n";
    File.close();

}


void MainWindow::on_tableInfo_cellEntered(int row, int column)
{

}


void MainWindow::on_tableInfo_cellChanged(int row, int column)
{
   /* if(column == 0)
    {
        QTableWidgetItem *item = ui->tableInfo->item(row, column);
        QString cellText = item->text();
        Date ddd(cellText);

        QTableWidgetItem* itm = new QTableWidgetItem(ddd.nextDay().getDateStr());
        ui->tableInfo->setItem(row, column + 1, itm);


        QTableWidgetItem* nextItem = ui->tableInfo->item((row - 1) , column);
        if (nextItem != nullptr) {
            QString Text = nextItem->text();
            Date dd(Text);
            qDebug()<<dd.getDateStr();
            QTableWidgetItem* newItem1 = new QTableWidgetItem(QString::number(ddd.difference(dd)));
            ui->tableInfo->setItem(row, column + 2, newItem1);
        }
    }*/
}


void MainWindow::on_pushButton_2_clicked()
{

    for(int i = 0; i < ui->tableInfo->rowCount() - 1; i++)
    {
        QTableWidgetItem* curDateItem = ui->tableInfo->item(i , 0);
        QString text = curDateItem->text();
        Date curDate(text);
        QTableWidgetItem* previousDay = new QTableWidgetItem(curDate.previousDay().getDateStr());
        ui->tableInfo->setItem(i , 3, previousDay);

    }
}


void MainWindow::on_IsLeapButton_clicked()
{
    for(int i = 0; i < ui->tableInfo->rowCount() - 1; i++)
    {
        QTableWidgetItem* curDateItem = ui->tableInfo->item(i , 0);
        QString text = curDateItem->text();
        Date curDate(text);
        if(curDate.isLeap())
        {
            QTableWidgetItem* isLeap = new QTableWidgetItem("Is leap");
            ui->tableInfo->setItem(i , 3, isLeap);
        }
        else
        {
            QTableWidgetItem* isLeap = new QTableWidgetItem("Not leap");
            ui->tableInfo->setItem(i , 3, isLeap);
        }
    }
}


void MainWindow::on_BirthdayButton_clicked()
{
    QString input = ui->lineEdit->text();
    Date birthday(input);
    for(int i = 0; i < ui->tableInfo->rowCount() - 1; i++)
    {
        QTableWidgetItem* curDateItem = ui->tableInfo->item(i , 0);
        QString text = curDateItem->text();
        Date curDate(text);
        QTableWidgetItem* daysTillBirthday = new QTableWidgetItem(QString::number(curDate.daysTillYourBirthday(birthday)));
        ui->tableInfo->setItem(i , 3, daysTillBirthday);
    }
}


void MainWindow::on_pushButton_5_clicked()
{

}


void MainWindow::on_DurationButton_clicked()
{
    QString input = ui->lineEdit->text();
    Date inputDate(input);
    for(int i = 0; i < ui->tableInfo->rowCount() - 1; i++)
    {
        QTableWidgetItem* curDateItem = ui->tableInfo->item(i , 0);
        QString text = curDateItem->text();
        Date curDate(text);
        QTableWidgetItem* difference = new QTableWidgetItem(QString::number(curDate.difference(inputDate)));
        ui->tableInfo->setItem(i , 3, difference);
    }
}


void MainWindow::on_nowButton_clicked()
{
    Date now(std::time(nullptr));
    ui->lineEdit->setText(now.getDateStr());
}


void MainWindow::on_spinBoxChange_textChanged(const QString &arg1)
{

}


void MainWindow::on_ChangeDateButton_clicked()
{
    int row;
    row = ui->spinBoxChange->value();
    QString input = ui->lineEdit->text();
    Date inputDate(input);
    QTableWidgetItem* itm0 = new QTableWidgetItem(inputDate.getDateStr());
    QTableWidgetItem* itm1 = new QTableWidgetItem(inputDate.nextDay().getDateStr());
    ui->tableInfo->setItem(row - 1, 0, itm0);
    ui->tableInfo->setItem(row - 1, 1, itm1);

    QTableWidgetItem* previousItem = ui->tableInfo->item((row - 2), 0);
    if(previousItem != nullptr)
    {
        QString Text = previousItem->text();
        Date temp(Text);
        QTableWidgetItem* itm2 = new QTableWidgetItem(QString::number(inputDate.difference(temp)));
        ui->tableInfo->setItem(row - 1, 2, itm2);
    }

    QTableWidgetItem* nextItem = ui->tableInfo->item(row , 0);
    if(nextItem!= nullptr)
    {
        qDebug()<<row;
        QString Text = nextItem->text();
        Date temp(Text);
        QTableWidgetItem* itm3 = new QTableWidgetItem(QString::number(inputDate.difference(temp)));
        ui->tableInfo->setItem(row , 2, itm3);
    }
    changeFile(row, input);
}


void MainWindow::on_DurationButton_3_clicked()
{

}


void MainWindow::on_lineEdit_textChanged(const QString &date)
{

}


void MainWindow::on_lineEdit_editingFinished()
{

}


void MainWindow::on_DeleteDateButton_clicked()
{
    int row;
    row = ui->spinBoxDelete->value();
    ui->tableInfo->removeRow(row - 1);
    int numrow = ui->tableInfo->rowCount();
    ui->spinBoxChange->setMaximum(numrow - 1);
    ui->spinBoxDelete->setMaximum(numrow - 1);



    QTableWidgetItem* previousItem = ui->tableInfo->item((row - 2), 0);
    QTableWidgetItem* nextItem = ui->tableInfo->item(row - 1 , 0);

    if(previousItem != nullptr && nextItem!= nullptr)
    {

        Date next(nextItem->text());
        Date previous(previousItem->text());
        qDebug()<<nextItem->text()<<"    " <<previousItem->text();
        QTableWidgetItem* nexti = new QTableWidgetItem(QString::number(next.difference(previous)));
        ui->tableInfo->setItem(row - 1, 2, nexti);
    }

    if(previousItem == nullptr)
    {
        QTableWidgetItem* nexti = new QTableWidgetItem("");
        ui->tableInfo->setItem(row - 1, 2, nexti);
    }

    deleteFile(row);


}


void MainWindow::on_openFileButton_clicked()
{
    Path = QFileDialog::getOpenFileName(this, tr("Открытие"), "//", tr("Текстовые документы (*.txt)"));
    /*if (Path.isEmpty()) {
        return;
    }*/
    File.setFileName(Path);
    File.open(QIODevice::ReadWrite);

    ui->tableInfo->setRowCount(1);

    QTextStream fileStream(&File);
    QString strF;
    while (!fileStream.atEnd()) {
        strF = fileStream.readLine();
        if (!checkDate(strF))
        {
            QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
            return;
        }
    }


    File.close();

    fileToTable();
}


