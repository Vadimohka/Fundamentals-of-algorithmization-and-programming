#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setWordWrap(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->verticalHeader()->setVisible(false);

    isTableFilled = false;
    isBDshow = false;
    isBDshow = false;
    isNextDayShow = false;
    isPreviousDayShow = false;
    isLeapShow = false;
    isDateShow = false;
    isDurationShow = false;
    isWeekNumberShow = false;

    isTheFirstOpeningFile = true;

    QStringList headers;

    headers << "Дата" << "Следующий\nдень" << "Предыдущий\nдень" <<
        "Кол-во дней до\nвашего след.\nдня рождения" << "Количество дней\nмежду этой\nи след. датами" <<
        "Год високосный?" << "Номер недели\nв году";

    ui->tableWidget->setHorizontalHeaderLabels(headers);
    QHeaderView *header = ui->tableWidget->horizontalHeader();

    header->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setColumnWidth(0,23);
    ui->tableWidget->setColumnWidth(0,23);
    ui->tableWidget->setColumnWidth(0,23);
    ui->tableWidget->setColumnWidth(0,23);
    ui->tableWidget->setColumnWidth(0,23);
    ui->tableWidget->setColumnWidth(0,23);

    ui->addNewDateButton->setEnabled(false);
    ui->outputNextDayButton->setEnabled(false);
    ui->outputPreviousDayButton->setEnabled(false);
    ui->outputDaysTillBDButton->setEnabled(false);
    ui->outputDurationToNextButton->setEnabled(false);
    ui->outputDatesButton->setEnabled(false);
    ui->outputLeapDatesButton->setEnabled(false);
    ui->outputWeekNumbersButton->setEnabled(false);
    ui->outputFullFilebutton->setEnabled(false);
    ui->clearTableButton->setEnabled(false);
    ui->closeFileButton->setEnabled(false);

    ui->addNewDateButton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->outputNextDayButton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->outputPreviousDayButton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->outputDaysTillBDButton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->outputDurationToNextButton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->outputDatesButton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->outputLeapDatesButton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->outputWeekNumbersButton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->outputFullFilebutton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->clearTableButton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->closeFileButton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");
    ui->openFilebutton->setStyleSheet("QPushButton:disabled { color: gray; background-color: lightgray; }");

    ui->tableWidget->setStyleSheet("QTableWidget:disabled { background-color: #DCDCDC; }");

    birthday = Date((QString)"13.01.2006");

    datesFromFile.clear();

    path = "";

    QTimer* updating = new QTimer();

    connect(updating, &QTimer::timeout, [=](){
        if(!ui->outputNextDayButton->isEnabled()
           && !ui->outputPreviousDayButton->isEnabled()
           && !ui->outputDaysTillBDButton->isEnabled()
           && !ui->outputDurationToNextButton->isEnabled()
           && !ui->outputDatesButton->isEnabled()
           && !ui->outputLeapDatesButton->isEnabled()
            && !ui->outputWeekNumbersButton->isEnabled()
            && ui->outputFullFilebutton->isEnabled())
        {
            ui->outputFullFilebutton->setEnabled(false);
            isTableFilled = true;
        }

        if(!isTableFilled) ui->tableWidget->setEnabled(false);
        else ui->tableWidget->setEnabled(true);
    });

    updating->start(10);

    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, &QTableWidget::customContextMenuRequested, this, &MainWindow::showContextMenuWithEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_outputFullFilebutton_clicked()
{
    if(!datesFromFile.isEmpty())
    {
        ui->tableWidget->setRowCount(datesFromFile.size());

        for(int i = 0; i < datesFromFile.size(); i++)
        {   
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(datesFromFile[i].ToString()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(datesFromFile[i].NextDay().ToString()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(datesFromFile[i].PreviousDay().ToString()));

            if(datesFromFile[i].DaysTillYourBirthday(birthday) == -1)
            {
                ui->tableWidget->setItem(i, 3, new QTableWidgetItem("Не родился"));
            }
            else
            {
                ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(datesFromFile[i].DaysTillYourBirthday(birthday))));
            }

            int index = (i < datesFromFile.size() - 1) ? i + 1: 0;
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(datesFromFile[i].Duration(datesFromFile[index]))));

            if(datesFromFile[i].isLeap()) ui->tableWidget->setItem(i, 5, new QTableWidgetItem("Да"));
            else ui->tableWidget->setItem(i, 5, new QTableWidgetItem("Нет"));

            ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(datesFromFile[i].WeekNumber())));
        }

        ui->outputNextDayButton->setEnabled(false);
        ui->outputPreviousDayButton->setEnabled(false);
        ui->outputDaysTillBDButton->setEnabled(false);
        ui->outputDurationToNextButton->setEnabled(false);
        ui->outputDatesButton->setEnabled(false);
        ui->outputLeapDatesButton->setEnabled(false);
        ui->outputWeekNumbersButton->setEnabled(false);

        ui->addNewDateButton->setEnabled(true);

        ui->outputFullFilebutton->setEnabled(false);
        ui->clearTableButton->setEnabled(true);
        ui->closeFileButton->setEnabled(true);

        isTableFilled = true;

        isBDshow = true;
        isNextDayShow = true;
        isPreviousDayShow = true;
        isLeapShow = true;
        isDateShow = true;
        isDurationShow = true;
        isWeekNumberShow = true;
    }
    else QMessageBox::warning(this, "Ошибка", "Данных нет. Вероятно, вы не открыли файл.");
}


void MainWindow::on_openFilebutton_clicked()
{
    datesFromFile.clear();

    path = QFileDialog::getOpenFileName(this, "Выбрать файл", "/home/deviyan/QTprojects/LabWork2", "Текстовый файл (*.txt)");

    file.setFileName(path);
    file.open(QIODevice::ReadWrite | QIODevice::Text);

    QTextStream in(&file);

    if(file.isOpen())
    {
        QString date;

        while(!in.atEnd())
        {
            in >> date;
            if(date != "") datesFromFile.push_back(Date(date));
        }


        ui->addNewDateButton->setEnabled(true);
        ui->outputNextDayButton->setEnabled(true);
        ui->outputPreviousDayButton->setEnabled(true);
        ui->outputDaysTillBDButton->setEnabled(true);
        ui->outputDurationToNextButton->setEnabled(true);
        ui->outputDatesButton->setEnabled(true);
        ui->outputLeapDatesButton->setEnabled(true);
        ui->outputWeekNumbersButton->setEnabled(true);
        ui->addNewDateButton->setEnabled(true);
        ui->outputFullFilebutton->setEnabled(true);
        ui->closeFileButton->setEnabled(true);
        ui->openFilebutton->setEnabled(false);
    }

    ui->statusbar->showMessage("Файл был открыт!", 5000);

    isTheFirstOpeningFile = true;
}

void MainWindow::on_outputLeapDatesButton_clicked()
{
    if(!datesFromFile.isEmpty())
    {
        ui->tableWidget->setRowCount(datesFromFile.size());

        for(int i = 0; i < datesFromFile.size(); i++)
        {
            if(datesFromFile[i].isLeap()) ui->tableWidget->setItem(i, 5, new QTableWidgetItem("Да"));
            else ui->tableWidget->setItem(i, 5, new QTableWidgetItem("Нет"));
        }

        ui->outputLeapDatesButton->setEnabled(false);

        ui->clearTableButton->setEnabled(true);

        isTableFilled = true;
        isLeapShow = true;
    }

    else QMessageBox::warning(this, "Ошибка", "Данных нет. Вероятно, вы не открыли файл.");
}

void MainWindow::on_outputDatesButton_clicked()
{
    if(!datesFromFile.isEmpty())
    {
        ui->tableWidget->setRowCount(datesFromFile.size());

        for(int i = 0; i < datesFromFile.size(); i++)
        {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem((datesFromFile[i].ToString())));
        }

        ui->outputDatesButton->setEnabled(false);

        ui->clearTableButton->setEnabled(true);

        isTableFilled = true;
        isDateShow = true;
    }

    else QMessageBox::warning(this, "Ошибка", "Данных нет. Вероятно, вы не открыли файл.");
}

void MainWindow::on_outputNextDayButton_clicked()
{
    if(!datesFromFile.isEmpty())
    {
        ui->tableWidget->setRowCount(datesFromFile.size());

        for(int i = 0; i < datesFromFile.size(); i++)
        {
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem((datesFromFile[i].NextDay().ToString())));
        }

        ui->outputNextDayButton->setEnabled(false);

        ui->clearTableButton->setEnabled(true);

        isTableFilled = true;
        isNextDayShow = true;
    }

    else QMessageBox::warning(this, "Ошибка", "Данных нет. Вероятно, вы не открыли файл.");
}

void MainWindow::on_outputPreviousDayButton_clicked()
{
    if(!datesFromFile.isEmpty())
    {
        ui->tableWidget->setRowCount(datesFromFile.size());

        for(int i = 0; i < datesFromFile.size(); i++)
        {
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem((datesFromFile[i].PreviousDay().ToString())));
        }

        ui->outputPreviousDayButton->setEnabled(false);

        ui->clearTableButton->setEnabled(true);

        isTableFilled = true;
        isPreviousDayShow = true;
    }

    else QMessageBox::warning(this, "Ошибка", "Данных нет. Вероятно, вы не открыли файл.");
}

void MainWindow::on_outputDaysTillBDButton_clicked()
{
    if(!datesFromFile.isEmpty())
    {
        ui->tableWidget->setRowCount(datesFromFile.size());

        for(int i = 0; i < datesFromFile.size(); i++)
        {
            if(datesFromFile[i].DaysTillYourBirthday(birthday) == -1)
            {
                ui->tableWidget->setItem(i, 3, new QTableWidgetItem("Не родился"));
            }
            else
            {
                ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(datesFromFile[i].DaysTillYourBirthday(birthday))));
            }
        }

        ui->outputDaysTillBDButton->setEnabled(false);

        ui->clearTableButton->setEnabled(true);

        isTableFilled = true;
        isBDshow = true;
    }

    else QMessageBox::warning(this, "Ошибка", "Данных нет. Вероятно, вы не открыли файл.");
}

void MainWindow::on_outputWeekNumbersButton_clicked()
{
    if(!datesFromFile.isEmpty())
    {
        ui->tableWidget->setRowCount(datesFromFile.size());

        for(int i = 0; i < datesFromFile.size(); i++)
        {
            ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(datesFromFile[i].WeekNumber())));
        }

        ui->outputWeekNumbersButton->setEnabled(false);

        ui->clearTableButton->setEnabled(true);

        isTableFilled = true;
        isWeekNumberShow = true;
    }

    else QMessageBox::warning(this, "Ошибка", "Данных нет. Вероятно, вы не открыли файл.");
}

void MainWindow::on_outputDurationToNextButton_clicked()
{
    if(!datesFromFile.isEmpty())
    {
        ui->tableWidget->setRowCount(datesFromFile.size());

        for(int i = 0; i < datesFromFile.size(); i++)
        {
            int index = (i < datesFromFile.size() - 1) ? i + 1: 0;
            ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(datesFromFile[i].Duration(datesFromFile[index]))));
        }

        ui->outputDurationToNextButton->setEnabled(false);

        ui->clearTableButton->setEnabled(true);

        isTableFilled = true;
        isDurationShow = true;
    }

    else QMessageBox::warning(this, "Ошибка", "Данных нет. Вероятно, вы не открыли файл.");
}

void MainWindow::on_closeFileButton_clicked()
{
    file.close();
    datesFromFile.clear();

    ui->addNewDateButton->setEnabled(false);
    ui->outputNextDayButton->setEnabled(false);
    ui->outputPreviousDayButton->setEnabled(false);
    ui->outputDaysTillBDButton->setEnabled(false);
    ui->outputDurationToNextButton->setEnabled(false);
    ui->outputDatesButton->setEnabled(false);
    ui->outputLeapDatesButton->setEnabled(false);
    ui->outputWeekNumbersButton->setEnabled(false);
    ui->addNewDateButton->setEnabled(false);
    ui->outputFullFilebutton->setEnabled(false);



    ui->closeFileButton->setEnabled(false);

    ui->openFilebutton->setEnabled(true);
}

void MainWindow::on_clearTableButton_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    if(file.isOpen())
    {
        ui->addNewDateButton->setEnabled(true);
        ui->outputNextDayButton->setEnabled(true);
        ui->outputPreviousDayButton->setEnabled(true);
        ui->outputDaysTillBDButton->setEnabled(true);
        ui->outputDurationToNextButton->setEnabled(true);
        ui->outputDatesButton->setEnabled(true);
        ui->outputLeapDatesButton->setEnabled(true);
        ui->outputWeekNumbersButton->setEnabled(true);
        ui->addNewDateButton->setEnabled(true);
        ui->outputFullFilebutton->setEnabled(true);



        ui->closeFileButton->setEnabled(true); 
    }

    isTableFilled = false;
    isBDshow = false;
    isNextDayShow = false;
    isPreviousDayShow = false;
    isLeapShow = false;
    isDateShow = false;
    isDurationShow = false;
    isWeekNumberShow = false;


    ui->clearTableButton->setEnabled(false);

}

void MainWindow::on_addNewDateButton_clicked()
{
    if(!datesFromFile.isEmpty())
    {
        DialogInputDate* dialog = new DialogInputDate();

        connect(dialog, &DialogInputDate::accepted, [this, dialog](){

            if(file.isOpen())
            {
                Date newDate = dialog->getDate();

                file.open(QIODevice::ReadWrite | QIODevice::Append);

                file.seek(file.size() - 1);

                char lastChar;
                file.getChar(&lastChar);
                if(lastChar < '0' || lastChar > '9')
                {
                    file.seek(file.size() - 1);
                }
                else file.seek(file.size());

                // if(isTheFirstOpeningFile)
                // {
                //     file.seek(file.size() - 1);
                //     isTheFirstOpeningFile = false;
                // }
                // else file.seek(file.size());

                QTextStream out(&file);

                datesFromFile.push_back(newDate);

                out << " " << QString(newDate.ToString());


                DialogUpdateTable* dialogUpdate = new DialogUpdateTable();

                connect(dialogUpdate, &DialogInputDate::accepted, [=](){

                    if(isDateShow) MainWindow::on_outputDatesButton_clicked();
                    if(isNextDayShow) MainWindow::on_outputNextDayButton_clicked();
                    if(isPreviousDayShow) MainWindow::on_outputPreviousDayButton_clicked();
                    if(isDurationShow) MainWindow::on_outputDurationToNextButton_clicked();
                    if(isBDshow) MainWindow::on_outputDaysTillBDButton_clicked();
                    if(isWeekNumberShow) MainWindow::on_outputWeekNumbersButton_clicked();
                    if(isLeapShow) MainWindow::on_outputLeapDatesButton_clicked();

                });

                dialogUpdate->exec();

                delete dialogUpdate;
                dialogUpdate = nullptr;

                if(!isDateShow) ui->outputDatesButton->setEnabled(true);
                if(!isNextDayShow) ui->outputNextDayButton->setEnabled(true);
                if(!isPreviousDayShow) ui->outputPreviousDayButton->setEnabled(true);
                if(!isDurationShow) ui->outputDurationToNextButton->setEnabled(true);
                if(!isBDshow) ui->outputDaysTillBDButton->setEnabled(true);
                if(!isWeekNumberShow) ui->outputWeekNumbersButton->setEnabled(true);
                if(!isLeapShow) ui->outputLeapDatesButton->setEnabled(true);

                if(!isDateShow || !isNextDayShow || !isPreviousDayShow || !isDurationShow || !isBDshow || !isWeekNumberShow || !isLeapShow)

                ui->outputFullFilebutton->setEnabled(true);
                ui->closeFileButton->setEnabled(true);
            }

        });

        dialog->exec();

        delete dialog;
        dialog = nullptr;
    }

    else QMessageBox::warning(this, "Ошибка", "Данных нет. Вероятно, вы не открыли файл.");
}


void MainWindow::on_inputBDdutton_clicked()
{
    DialogInputDate* dialog = new DialogInputDate();

    connect(dialog, &DialogInputDate::accepted, [this, dialog](){

        Date newDate = dialog->getDate();

        birthday = newDate;

        if(isBDshow)
        {
            MainWindow::on_outputDaysTillBDButton_clicked();
        }

    });

    dialog->setDate(birthday);
    dialog->exec();

    delete dialog;
    dialog = nullptr;
}

void MainWindow::showContextMenuWithEdit(const QPoint &pos){


        QModelIndex index = ui->tableWidget->indexAt(pos);

        if(index.column() == 0 && isDateShow)
        {
            ui->tableWidget->itemFromIndex(index)->setSelected(true);

            QMenu contextMenu;
            QAction *edit = contextMenu.addAction("Изменить дату");

            QAction *selectedAction = contextMenu.exec(QCursor::pos());
            if (selectedAction == edit) {

                DialogInputDate* dialog = new DialogInputDate();

                connect(dialog, &DialogInputDate::accepted, [=](){

                    Date newDate = dialog->getDate();

                    ui->tableWidget->setItem(index.row(), index.column(), new QTableWidgetItem(QString(newDate.ToString())));

                    datesFromFile[index.row()] = newDate;

                    if(isDateShow) MainWindow::on_outputDatesButton_clicked();
                    if(isNextDayShow) MainWindow::on_outputNextDayButton_clicked();
                    if(isPreviousDayShow) MainWindow::on_outputPreviousDayButton_clicked();
                    if(isDurationShow) MainWindow::on_outputDurationToNextButton_clicked();
                    if(isBDshow) MainWindow::on_outputDaysTillBDButton_clicked();
                    if(isWeekNumberShow) MainWindow::on_outputWeekNumbersButton_clicked();
                    if(isLeapShow) MainWindow::on_outputLeapDatesButton_clicked();

                    file.seek(index.row() * 11);

                    QTextStream out(&file);

                    out << newDate.ToString();



                });

                dialog->setDate(Date((ui->tableWidget->item(index.row(), index.column()))->text()));
                dialog->exec();

                delete dialog;
                dialog = nullptr;
            }

            ui->tableWidget->itemFromIndex(index)->setSelected(false);
        }
    }
