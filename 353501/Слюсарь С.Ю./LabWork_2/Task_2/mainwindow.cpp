#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    on_ButtonReset_clicked();

    //Input Masks
    ui->LineCost->setInputMask("0000000");
    ui->LineGasoline->setInputMask("00");
    ui->LineComfort->setInputMask("00");
    ui->LineReliability->setInputMask("00");

    //Add Menu
    AddWidget = new QWidget();
    AddMark = new QLineEdit("");
    AddModel = new QLineEdit("");
    AddPrice = new QLineEdit("");
    AddCountry = new QLineEdit("");
    AddEngine = new QLineEdit("");
    AddGasoline = new QLineEdit("");
    AddReliability = new QLineEdit("");
    AddComfort = new QLineEdit("");

    QVBoxLayout* AddLayout = new QVBoxLayout(AddWidget);
    QPushButton* confirmAdd = new QPushButton("Confirm");
    QLabel* PriceLabel = new QLabel("Enter Price:");
    QLabel* GasolineLabel = new QLabel("Enter Gasoline spend:");
    QLabel* ReliabilityLabel = new QLabel("Enter Reliability:");
    QLabel* ComfortLabel = new QLabel("Enter Comfort:");
    QLabel* MarkLabel = new QLabel("Enter Mark:");
    QLabel* ModelLabel = new QLabel("Enter Model:");
    QLabel* CountryLabel = new QLabel("Enter Country:");
    QLabel* EngineLabel = new QLabel("Enter Engine:");

    AddWidget->setFixedSize(1500, 800);
    AddWidget->setWindowTitle("Add new car");

    AddLayout->addWidget(MarkLabel);
    AddLayout->addWidget(AddMark);

    AddLayout->addWidget(ModelLabel);
    AddLayout->addWidget(AddModel);

    AddLayout->addWidget(PriceLabel);
    AddLayout->addWidget(AddPrice);

    AddLayout->addWidget(CountryLabel);
    AddLayout->addWidget(AddCountry);

    AddLayout->addWidget(EngineLabel);
    AddLayout->addWidget(AddEngine);

    AddLayout->addWidget(GasolineLabel);
    AddLayout->addWidget(AddGasoline);

    AddLayout->addWidget(ReliabilityLabel);
    AddLayout->addWidget(AddReliability);

    AddLayout->addWidget(ComfortLabel);
    AddLayout->addWidget(AddComfort);

    AddLayout->addWidget(confirmAdd);

    AddPrice->setInputMask("0000000");
    AddGasoline->setInputMask("00");
    AddReliability->setInputMask("00");
    AddComfort->setInputMask("00");

    connect(confirmAdd, &QPushButton::clicked, this, &MainWindow::on_comfirmAdd_clicked);

    //Delete Menu
    DeleteWidget = new QWidget();
    DeleteNumber = new QLineEdit("");

    QLabel* DeleteLabel = new QLabel("Enter number you want to delete:");
    QVBoxLayout* DeleteLayout = new QVBoxLayout(DeleteWidget);
    QPushButton* confirmDelete = new QPushButton("Confirm");

    DeleteWidget->setFixedSize(300, 100);
    DeleteWidget->setWindowTitle("Delete some car");

    DeleteLayout->addWidget(DeleteLabel);
    DeleteLayout->addWidget(DeleteNumber);
    DeleteLayout->addWidget(confirmDelete);

    DeleteNumber->setInputMask("000");

    connect(confirmDelete, &QPushButton::clicked, this, &MainWindow::on_confirmDelete_clicked);

    //table
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);

    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setRowCount(1);

    ui->tableWidget->setColumnWidth(0, 25);
    for(int i = 1; i < 9; ++i){
        ui->tableWidget->setColumnWidth(i, 100);
    }

    ui->tableWidget->setItem(0,0, new QTableWidgetItem("№"));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem("Mark:"));
    ui->tableWidget->setItem(0,2, new QTableWidgetItem("Model"));
    ui->tableWidget->setItem(0,3, new QTableWidgetItem("Price:"));
    ui->tableWidget->setItem(0,4, new QTableWidgetItem("Country:"));
    ui->tableWidget->setItem(0,5, new QTableWidgetItem("Engine:"));
    ui->tableWidget->setItem(0,6, new QTableWidgetItem("Gasoline spend:"));
    ui->tableWidget->setItem(0,7, new QTableWidgetItem("Reliability:"));
    ui->tableWidget->setItem(0,8, new QTableWidgetItem("Comfort:"));

    ExtractData();
    DisplayData();

    UpdateComboBox();
}


MainWindow::~MainWindow()
{
    delete ui;
}


// Extract / Display
void MainWindow::ExtractData()
{
    QFile file(path);
    if(!file.exists()){
        qCritical() << "File not found";
        return;
    }
    if(!file.open(QIODeviceBase::ReadOnly)){
        qCritical() << file.errorString();
        return;
    }

    QTextStream out(&file);

    while(!out.atEnd()){
        int readline = 0;
        Car temp;
        for(int i = 0; i < 8; ++i){
            QString line = out.readLine();
            if(line.isEmpty()){
                return;
            }
            switch (i) {
            case 0:
                temp.setMark(line);
                break;
            case 1:
                temp.setModel(line);
                break;
            case 2:
                for(int k = 0; k < line.size(); ++k){
                    if(!line.at(k).isDigit()){
                        qCritical() << "Price must be number";
                        return;
                    }
                }
                temp.setPrice(line.toInt());
                break;
            case 3:
                temp.setCountry(line);
                break;
            case 4:
                temp.setEngineType(line);
                break;
            case 5:
                for(int k = 0; k < line.size(); ++k){
                    if(!line.at(k).isDigit()){
                        qCritical() << "Spend must be number";
                        return;
                    }
                }
                temp.setGasolineSpend(line.toInt());
                break;
            case 6:
                for(int k = 0; k < line.size(); ++k){
                    if(!line.at(k).isDigit()){
                        qCritical() << "Spend must be number";
                        return;
                    }
                }
                temp.setReliability(line.toInt());
                break;
            case 7:
                for(int k = 0; k < line.size(); ++k){
                    if(!line.at(k).isDigit()){
                        return;
                    }
                }
                temp.setComfortability(line.toInt());
                break;
            default:
                break;
            }
        }
        Cars.append(temp);
        total_cars++;
    }

    file.close();
}

void MainWindow::DisplayData()
{
    ui->tableWidget->setRowCount(total_cars + 1);
    QString Pr, Gas, Rel, Comf, Num;
    for(int i = 1; i < ui->tableWidget->rowCount(); ++i){
        Pr.setNum(Cars.at(i - 1).getPrice());
        Gas.setNum(Cars.at(i - 1).getGasolineSpend());
        Rel.setNum(Cars.at(i - 1).getReliability());
        Comf.setNum(Cars.at(i - 1).getComfortability());
        Num.setNum(i);

        ui->tableWidget->setItem(i,0, new QTableWidgetItem(Num));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(Cars.at(i - 1).getMark()));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(Cars.at(i - 1).getModel()));
        ui->tableWidget->setItem(i,3, new QTableWidgetItem(Pr));
        ui->tableWidget->setItem(i,4, new QTableWidgetItem(Cars.at(i - 1).getCountry()));
        ui->tableWidget->setItem(i,5, new QTableWidgetItem(Cars.at(i - 1).getEngineType()));
        ui->tableWidget->setItem(i,6, new QTableWidgetItem(Gas));
        ui->tableWidget->setItem(i,7, new QTableWidgetItem(Rel));
        ui->tableWidget->setItem(i,8, new QTableWidgetItem(Comf));
    }
}


// Update comboBoxes(Engine and Marks)
void MainWindow::UpdateComboBox()
{
    //Engine
    for(int i = 0; i < total_cars; ++i){
        bool Isadd = true;
        QString engine = Cars.at(i).getEngineType();

        for(int j = 0; j < CurrEngines.size(); ++j){
            if(engine == CurrEngines.at(j)){
                Isadd = false;
            }
        }

        if(Isadd){
            CurrEngines.append(engine);
            ui->BoxEngine->addItem(engine);
        }
    }

    //Marks
    for(int i = 0; i < total_cars; ++i){
        bool Isadd = true;
        QString mark = Cars.at(i).getMark();

        for(int j = 0; j < CurrMarks.size(); ++j){
            if(mark == CurrMarks.at(j)){
                Isadd = false;
            }
        }

        if(Isadd){
            CurrMarks.append(mark);
            ui->BoxMarks->addItem(mark);
        }
    }
}


// Add
void MainWindow::on_ButtonAdd_clicked()
{
    AddWidget->hide();
    AddWidget->show();
}

void MainWindow::on_comfirmAdd_clicked()
{
    QFile file(path);
    if(!file.exists()){
        qCritical() << "No where to add";
        return;
    }
    if(!file.open(QIODeviceBase::ReadWrite | QIODeviceBase::Append)){
        qCritical() << file.errorString();
        return;
    };

    try {
        if(AddComfort->text().isEmpty() || AddCountry->text().isEmpty() || AddEngine->text().isEmpty() || AddGasoline->text().isEmpty() ||
            AddMark->text().isEmpty() || AddModel->text().isEmpty() || AddPrice->text().isEmpty() || AddReliability->text().isEmpty()){
            throw "can't be empty";
        }
    } catch (const char* error_message) {
        qCritical() << error_message;
        return;
    }

    QTextStream in(&file);

    //Add to file
    Car temp;
    temp.setMark(AddMark->text());
    temp.setModel(AddModel->text());
    temp.setPrice(AddPrice->text().toInt());
    temp.setCountry(AddCountry->text());
    temp.setEngineType(AddEngine->text());
    temp.setGasolineSpend(AddEngine->text().toInt());
    temp.setReliability(AddReliability->text().toInt());
    temp.setComfortability(AddComfort->text().toInt());

    Cars.append(temp);
    total_cars++;

    in << temp.getMark() << "\n";
    in << temp.getModel() << "\n";
    in << temp.getPrice() << "\n";
    in << temp.getCountry() << "\n";
    in << temp.getEngineType() << "\n";
    in << temp.getGasolineSpend() << "\n";
    in << temp.getReliability() << "\n";
    in << temp.getComfortability() << "\n";

    AddWidget->hide();


    //Add to table
    ui->tableWidget->setRowCount(total_cars + 1);

    QString Pr, Gas, Rel, Comf, Num;

    Pr.setNum(temp.getPrice());
    Gas.setNum(temp.getGasolineSpend());
    Rel.setNum(temp.getReliability());
    Comf.setNum(temp.getComfortability());
    Num.setNum(total_cars);

    ui->tableWidget->setItem(total_cars,0, new QTableWidgetItem(Num));
    ui->tableWidget->setItem(total_cars,1, new QTableWidgetItem(temp.getMark()));
    ui->tableWidget->setItem(total_cars,2, new QTableWidgetItem(temp.getModel()));
    ui->tableWidget->setItem(total_cars,3, new QTableWidgetItem(Pr));
    ui->tableWidget->setItem(total_cars,4, new QTableWidgetItem(temp.getCountry()));
    ui->tableWidget->setItem(total_cars,5, new QTableWidgetItem(temp.getEngineType()));
    ui->tableWidget->setItem(total_cars,6, new QTableWidgetItem(Gas));
    ui->tableWidget->setItem(total_cars,7, new QTableWidgetItem(Rel));
    ui->tableWidget->setItem(total_cars,8, new QTableWidgetItem(Comf));

    AddMark->setText("");
    AddModel->setText("");
    AddPrice->setText("");
    AddCountry->setText("");
    AddEngine->setText("");
    AddGasoline->setText("");
    AddReliability->setText("");
    AddComfort->setText("");

    UpdateComboBox();

    file.flush();
    file.close();
}


// Delete
void MainWindow::on_ButtonDelete_clicked()
{
    DeleteWidget->hide();
    DeleteWidget->show();
}

void MainWindow::on_confirmDelete_clicked()
{
    int number_to_delete = DeleteNumber->text().toInt();
    if(number_to_delete > ui->tableWidget->rowCount()){
        qCritical() << "There is no such number";
        return;
    }
    if(DeleteNumber->text().isEmpty()){
        qCritical() << "Enter something";
        return;
    }

    QString engine_to_delete = Cars.at(number_to_delete - 1).getEngineType();
    QString mark_to_delete = Cars.at(number_to_delete - 1).getMark();
    bool IsdeleteMark = true;
    bool IsdeleteEngine = true;

    // Delete from table
    QVector<Car> New_vector;
    for(int i = 0; i < number_to_delete - 1; ++i){
        New_vector.append(Cars.at(i));
    }
    for(int i = number_to_delete; i < total_cars; i++){
        New_vector.append(Cars.at(i));
    }
    total_cars--;
    Cars = New_vector;
    DisplayData();

    for(int i = 0; i < total_cars; i++){
        if(engine_to_delete == Cars.at(i).getEngineType()){
            IsdeleteEngine = false;
            break;
        }
    }
    for(int i = 0; i < total_cars; i++){
        if(mark_to_delete == Cars.at(i).getMark()){
            IsdeleteMark = false;
            break;
        }
    }
    if(IsdeleteEngine){
        ui->BoxEngine->removeItem(ui->BoxEngine->findText(engine_to_delete));
    }
    if(IsdeleteMark){
        ui->BoxMarks->removeItem(ui->BoxMarks->findText(mark_to_delete));
    }


    // Delete from file

    QFile file(path);
    if(!file.exists()){
        qCritical() << "No where to add";
        return;
    }
    if(!file.open(QIODeviceBase::ReadWrite | QIODeviceBase::Text)){
        qCritical() << file.errorString();
        return;
    };
    file.resize(0);

    QTextStream in(&file);
    for(int i = 0; i < Cars.size(); ++i){
        in << Cars.at(i).getMark() << "\n" << Cars.at(i).getModel() << "\n" << Cars.at(i).getPrice() << "\n" <<
            Cars.at(i).getCountry() << "\n" << Cars.at(i).getEngineType() << "\n" << Cars.at(i).getGasolineSpend() << "\n" <<
            Cars.at(i).getReliability() << "\n" << Cars.at(i).getComfortability() << "\n";
    }

    file.flush();
    file.close();

    DeleteWidget->hide();
    DeleteNumber->setText("");
}


// Sort

// Boxes
void MainWindow::on_BoxMarks_activated(int index)
{
    Pr_mark = ui->BoxMarks->currentText();
}
void MainWindow::on_BoxEngine_activated(int index)
{
    Pr_engine = ui->BoxEngine->currentText();
}

// Lines
void MainWindow::on_ApplyCost_clicked()
{
    Pr_price = ui->LineCost->text().toInt();
}
void MainWindow::on_ApplyGas_clicked()
{
    Pr_gas = ui->LineGasoline->text().toInt();
}
void MainWindow::on_ApplyReliability_clicked()
{
    Pr_rel = ui->LineReliability->text().toInt();
}
void MainWindow::on_ApplyComfort_clicked()
{
    Pr_comf = ui->LineComfort->text().toInt();
}

void MainWindow::on_ButtonSearch_clicked()
{
    ui->ButtonAdd->blockSignals(true);
    ui->ButtonDelete->blockSignals(true);
    Search();
}


void MainWindow::Search()
{
    QVector<Car> searched_cars;
    int curr_numb = 0;

    for(int i = 0; i < total_cars; ++i){

        int price_range = Cars.at(i).getPrice() * 0.1;
        int gas_range = Cars.at(i).getGasolineSpend() * 0.1;
        int rel_range = Cars.at(i).getReliability() * 0.1;
        int comf_range = Cars.at(i).getComfortability() * 0.1;

        if(Pr_mark != "None"){
            if(Cars.at(i).getMark() != Pr_mark){
                continue;
            }
        }
        if(Pr_engine != "None"){
            if(Cars.at(i).getEngineType() != Pr_engine){
                continue;
            }
        }

        if(Pr_price != 0){
            if((Pr_price <= Cars.at(i).getPrice() - price_range) || (Pr_price >= Cars.at(i).getPrice() + price_range)){
                continue;
            }
        }
        if(Pr_gas != 0){
            if((Pr_gas <= Cars.at(i).getGasolineSpend() - gas_range) || (Pr_gas >= Cars.at(i).getGasolineSpend() + gas_range)){
                continue;
            }
        }
        if(Pr_rel != 0){
            if((Pr_rel <= Cars.at(i).getReliability() - rel_range) || (Pr_rel >= Cars.at(i).getReliability() + rel_range)){
                continue;
            }
        }
        if(Pr_comf != 0){
            if((Pr_comf <= Cars.at(i).getComfortability() - comf_range) || (Pr_comf >= Cars.at(i).getComfortability() + comf_range)){
                continue;
            }
        }
        searched_cars.append(Cars.at(i));
        curr_numb++;
    }

    ui->tableWidget->setRowCount(curr_numb + 1);
    QString Pr, Gas, Rel, Comf, Num;
    for(int i = 1; i < ui->tableWidget->rowCount(); ++i){
        Pr.setNum(searched_cars.at(i - 1).getPrice());
        Gas.setNum(searched_cars.at(i - 1).getGasolineSpend());
        Rel.setNum(searched_cars.at(i - 1).getReliability());
        Comf.setNum(searched_cars.at(i - 1).getComfortability());
        Num.setNum(i);

        ui->tableWidget->setItem(i,0, new QTableWidgetItem(Num));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(searched_cars.at(i - 1).getMark()));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(searched_cars.at(i - 1).getModel()));
        ui->tableWidget->setItem(i,3, new QTableWidgetItem(Pr));
        ui->tableWidget->setItem(i,4, new QTableWidgetItem(searched_cars.at(i - 1).getCountry()));
        ui->tableWidget->setItem(i,5, new QTableWidgetItem(searched_cars.at(i - 1).getEngineType()));
        ui->tableWidget->setItem(i,6, new QTableWidgetItem(Gas));
        ui->tableWidget->setItem(i,7, new QTableWidgetItem(Rel));
        ui->tableWidget->setItem(i,8, new QTableWidgetItem(Comf));
    }

}

void MainWindow::on_ButtonReset_clicked()
{
    Pr_mark = "None";
    Pr_engine = "None";
    Pr_price = 0;
    Pr_gas = 0;
    Pr_rel = 0;
    Pr_comf = 0;

    DisplayData();
    ui->BoxMarks->setCurrentIndex(0);
    ui->BoxEngine->setCurrentIndex(0);
    ui->LineCost->setText("");
    ui->LineGasoline->setText("");
    ui->LineReliability->setText("");
    ui->LineComfort->setText("");

    ui->ButtonAdd->blockSignals(false);
    ui->ButtonDelete->blockSignals(false);
}
