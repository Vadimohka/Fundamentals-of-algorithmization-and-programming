#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Birthday->setText("Birthday: 00.00.0000");

    //Birthday menu
    BirthDayWidget = new QWidget();
    EditBirthDay = new QLineEdit("Set new date");
    QVBoxLayout* birthdayLayout = new QVBoxLayout(BirthDayWidget);
    QPushButton* confirmBirthday = new QPushButton("Confirm");

    BirthDayWidget->setFixedSize(300, 150);
    BirthDayWidget->setWindowTitle("Change birthday");

    birthdayLayout->addWidget(EditBirthDay);
    birthdayLayout->addWidget(confirmBirthday);
    EditBirthDay->setInputMask("00.00.0000");

    connect(confirmBirthday, &QPushButton::clicked, this, &MainWindow::on_ConfirmBirthday_clicked);


    //Change menu
    ChangeWidget = new QWidget();
    EditDate = new QLineEdit("Set new date");
    EditNumber = new QLineEdit("Enter number");
    QVBoxLayout *changelayout = new QVBoxLayout(ChangeWidget);
    QPushButton *confirmChange = new QPushButton("Confirm");

    ChangeWidget->setFixedSize(300, 150);
    ChangeWidget->setWindowTitle("Change Date");

    changelayout->addWidget(EditNumber);
    changelayout->addWidget(EditDate);
    changelayout->addWidget(confirmChange);

    EditDate->setInputMask("00.00.0000");
    EditNumber->setInputMask("00");
    connect(confirmChange, &QPushButton::clicked, this, &MainWindow::on_ConfirmDate_ckicked);


    //Add Menu
    AddWidget = new QWidget();
    EditAdd = new QLineEdit("Set new date");
    QVBoxLayout* AddLayout = new QVBoxLayout(AddWidget);
    QPushButton* confirmAdd = new QPushButton("Confirm");

    AddWidget->setFixedSize(300, 150);
    AddWidget->setWindowTitle("Add new date");

    AddLayout->addWidget(EditAdd);
    AddLayout->addWidget(confirmAdd);
    EditAdd->setInputMask("00.00.0000");

    connect(confirmAdd, &QPushButton::clicked, this, &MainWindow::on_ConfirmAdd_ckicked);


    //Table
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);

    ui->tableWidget->setFixedWidth(1030);

    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setRowCount(1);

    for(int i = 0; i < ui->tableWidget->columnCount(); ++i){
        ui->tableWidget->setColumnWidth(i, 128);
    }
    ui->tableWidget->setRowHeight(0, 40);

    ui->tableWidget->setItem(0,0, new QTableWidgetItem("Date"));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem("Deffrence with\nnext day"));
    ui->tableWidget->setItem(0,2, new QTableWidgetItem("Next day"));
    ui->tableWidget->setItem(0,3, new QTableWidgetItem("Prev day"));
    ui->tableWidget->setItem(0,4, new QTableWidgetItem("Days till\nbirthday"));
    ui->tableWidget->setItem(0,5, new QTableWidgetItem("Is leap"));
    ui->tableWidget->setItem(0,6, new QTableWidgetItem("Week number"));
    ui->tableWidget->setItem(0,7, new QTableWidgetItem("days from\ntoday"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayFiles()
{
    ui->tableWidget->setRowCount(number_of_files + 1);
    for(int i = 1; i <= number_of_files; ++i){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dates.at(i - 1).Print()));
    }
}

bool MainWindow::CheckString(QString line)
{
    QString num_1 = "00";
    QString num_2 = "00";
    QString num_3 = "0000";

    try {
        if(line.size() != 10){
            throw "Incorrect size";
            return false;
        }
        if(line.at(2) != '.' || line.at(5) != '.'){
            throw "Invalid structure";
        }
        if(!line.at(0).isDigit() || !line.at(1).isDigit() || !line.at(3).isDigit() || !line.at(4).isDigit() || !line.at(6).isDigit() || !line.at(7).isDigit() || !line.at(9).isDigit() || !line.at(9).isDigit()){
            throw "Only digits can be used";
        }

        num_1[0] = line[0];
        num_1[1] = line[1];

        num_2[0] = line[3];
        num_2[1] = line[4];

        num_3[0] = line[6];
        num_3[1] = line[7];
        num_3[2] = line[8];
        num_3[3] = line[9];

        if((num_1.toInt() > 31 || num_1.toInt() < 0) || (num_2.toInt() > 12 or num_2.toInt() < 0) || (num_3.toInt() < 0)){
            throw "Invalid data";
        }
    }
    catch (const char* error_message) {
        qCritical() << error_message;
        return false;
    }

    return true;
}

void MainWindow::on_OpenFile_clicked()
{
    ExtractFile();
}

void MainWindow::ExtractFile()
{
    path = QFileDialog::getOpenFileName(nullptr, "Выберите .txt файл", QDir::homePath(), "Текстовые файлы (*.txt)");
    QFile file(path);

    if(!file.exists()){
        qCritical() << "File not found";
        return;
    }
    if(!file.open(QIODeviceBase::ReadWrite)){
        qCritical() << file.errorString();
        return;    
    }

    //12.00.2122
    QString num_1 = "00";
    QString num_2 = "00";
    QString num_3 = "0000";
    QTextStream stream(&file);

    while(!stream.atEnd()){
        QString line = stream.readLine();
        try {
            if(line.size() != 10){
                throw "Incorrect size";
            }
            if(line.at(2) != '.' || line.at(5) != '.'){
                throw "Invalid structure";
            }
            if(!line.at(0).isDigit() || !line.at(1).isDigit() || !line.at(3).isDigit() || !line.at(4).isDigit() || !line.at(6).isDigit() || !line.at(7).isDigit() || !line.at(9).isDigit() || !line.at(9).isDigit()){
                throw "Only digits can be used";
            }

            num_1[0] = line[0];
            num_1[1] = line[1];

            num_2[0] = line[3];
            num_2[1] = line[4];

            num_3[0] = line[6];
            num_3[1] = line[7];
            num_3[2] = line[8];
            num_3[3] = line[9];

            if((num_1.toInt() > 31 || num_1.toInt() < 0) || (num_2.toInt() > 12 or num_2.toInt() < 0) || (num_3.toInt() < 0)){
                throw "Invalid data";
            }
        }
        catch (const char* error_message) {
            qCritical() << error_message;
            return;
        }
        Date temp = Date(num_1.toShort(), num_2.toShort(), num_3.toInt());

        dates.push_back(temp);
        number_of_files++;
        DisplayFiles();
    }
    file.close();  
}


// Birthday
void MainWindow::on_EnterBirthday_clicked()
{
    BirthDayWidget->hide();
    BirthDayWidget->show();
}

void MainWindow::on_ConfirmBirthday_clicked()
{
    Date temp = Date(0,0,0);

    if(!CheckString(EditBirthDay->text())){
        return;
        //qCritical() << "Error";
    }
    temp = temp.StringToDate(EditBirthDay->text());

    Birthday = temp;
    ui->Birthday->setText("Birthday: " + Birthday.Print());
    BirthDayWidget->hide();
    EditBirthDay->setText("enter");
    on_TillBirthday_clicked();
}

void MainWindow::on_TillBirthday_clicked()
{
    if(number_of_files < 1){
        qCritical() << "No Dates";
        return;
    }
    QString t;
    for(int i = 0; i < number_of_files - 1; ++i){
        ui->tableWidget->setItem(i + 1, 4, new QTableWidgetItem(t.setNum(qAbs(dates[i].DaysTillYourBirthday(Birthday)))));
    }
    ui->tableWidget->setItem(number_of_files, 4, new QTableWidgetItem(t.setNum(qAbs(dates[number_of_files - 1].DaysTillYourBirthday(Birthday)))));
}


// Change
void MainWindow::on_ChangeDate_clicked()
{
    ChangeWidget->hide();
    ChangeWidget->show();
}

void MainWindow::on_ConfirmDate_ckicked()
{
    if(number_of_files == 0){
        qCritical() << "Open file First";
        return;
    }

    if(!CheckString(EditDate->text())){
        return;
        //qCritical() << "Error";
    }

    QFile file(path);
    if(!file.exists()){
        qCritical() << "No where to add";
        return;
    }
    if(!file.open(QIODeviceBase::ReadWrite)){
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);

    Date temp = Date(0,0,0);
    QString num = EditNumber->text();
    int number = 0;
    // check of the changed number
    try{
        if(num.size() == 0){
            throw "Cant be empty";
        }
    }
    catch(const char* error_message){
        qCritical() << error_message;
        return;
    }
    if(num.size() == 2){
        if(num.at(0) == '0'){
            QString t = num;
            num.resize(1);
            num = t.at(1);
        }
    }
    if(num.toInt() > 0 && num.toInt() - 1 < number_of_files){
        number = num.toInt();
    }
    else{
        return;
    }

    temp = temp.StringToDate(EditDate->text());

    dates[number - 1] = temp.StringToDate(EditDate->text());
    ui->tableWidget->item(number, 0)->setText(temp.Print());

    on_DisplayAll_clicked();

    for(int i = 0; i < number - 1; ++i){
        stream.readLine();
    }
    qint64 position = stream.pos();
    stream.seek(position);
    stream << temp.Print();

    ChangeWidget->hide();
    EditDate->setText("edit");
    EditNumber->setText("__");

    file.close();
}


//Add
void MainWindow::on_AddDate_clicked()
{
    AddWidget->hide();
    AddWidget->show();
}

void MainWindow::on_ConfirmAdd_ckicked()
{
    if(number_of_files == 0){
        qCritical() << "Open file First";
        return;
    }

    if(!CheckString(EditAdd->text())){
        return;
        //qCritical() << "Error";
    }

    QFile file(path);
    if(!file.exists()){
        qCritical() << "No where to add";
        return;
    }
    if(!file.open(QIODeviceBase::ReadWrite | QIODeviceBase::Append)){
        qCritical() << file.errorString();
        return;
    }
    QTextStream stream(&file);

    Date temp = Date(0,0,0);
    temp = temp.StringToDate(EditAdd->text());

    stream << temp.Print() << "\n";

    number_of_files++;
    dates.append(temp);

    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    ui->tableWidget->setItem(number_of_files, 0, new QTableWidgetItem(temp.Print()));

    ui->tableWidget->update();

    on_DisplayAll_clicked();

    file.flush();
    file.close();

    AddWidget->hide();
    EditAdd->setText("Edit");
}


//Funcs
void MainWindow::on_NextDay_clicked()
{
    //3 column
    Date temp = Date(0,0,0);

    for(int i = 0; i < number_of_files; ++i){
        temp = dates.at(i);
        temp = temp.NextDay();
        QString date = temp.Print();
        ui->tableWidget->setItem(i + 1, 2, new QTableWidgetItem(date));
    }
}


void MainWindow::on_PreviousDay_clicked()
{
    Date temp = Date(0,0,0);

    for(int i = 0; i < number_of_files; ++i){
        temp = dates.at(i);
        temp = temp.PreviousDay();
        QString date = temp.Print();
        ui->tableWidget->setItem(i + 1, 3, new QTableWidgetItem(date));
    }
}


void MainWindow::on_Deffrence_clicked()
{
    if(number_of_files < 2){
        qCritical() << "Impossible to calculate";
        return;
    }
    QString t;
    for(int i = 0; i < number_of_files - 1; ++i){
        ui->tableWidget->setItem(i + 1, 1, new QTableWidgetItem(t.setNum(qAbs(dates[i].Duration(dates[i + 1])))));
    }
    ui->tableWidget->setItem(number_of_files, 1, new QTableWidgetItem(t.setNum(qAbs(dates[number_of_files - 1].Duration(dates[0])))));
}

void MainWindow::on_IsLeap_clicked()
{
    for(int i = 0; i < number_of_files; ++i){
        if(dates[i].IsLeap()){
            ui->tableWidget->setItem(i + 1, 5, new QTableWidgetItem("Yes"));
        }
        else{
            ui->tableWidget->setItem(i + 1, 5, new QTableWidgetItem("No"));
        }
    }
}

void MainWindow::on_DaysFromToday_clicked()
{
    if(number_of_files < 1){
        qCritical() << "No Dates";
        return;
    }

    QDate today;
    today = today.currentDate();

    Date temp = Date(today.day(), today.month(), today.year());
    QString t;
    for(int i = 0; i < number_of_files; ++i){
        ui->tableWidget->setItem(i + 1, 7, new QTableWidgetItem(t.setNum(qAbs(dates[i].Duration(temp)))));
    }
}


void MainWindow::on_WeekNumber_clicked()
{
    QString t;
    for(int i = 0; i < number_of_files; ++i){
        ui->tableWidget->setItem(i + 1, 6, new QTableWidgetItem(t.setNum(dates[i].WeekNumber())));
    }
}

void MainWindow::on_DisplayAll_clicked()
{
    on_Deffrence_clicked();
    on_NextDay_clicked();
    on_PreviousDay_clicked();
    on_TillBirthday_clicked();
    on_IsLeap_clicked();
    on_WeekNumber_clicked();
    on_DaysFromToday_clicked();
}

