#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QHeaderView* header = ui->flightsTable->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    ui->flightsTable->setMinimumWidth(350);

    QString styleSheet = "QTableView::item:selected { outline: 2px solid yellow; }";
    ui->comboBox->addItem(QString("All"));
    ui->flightsTable->setStyleSheet(styleSheet);


    QHeaderView* header1 = ui->planesTable->horizontalHeader();
    header1->setSectionResizeMode(QHeaderView::Stretch);
    ui->planesTable->setMinimumWidth(350);
    QString styleSheet1 = "QTableView::item:selected { outline: 2px solid yellow; }";
    ui->planesTable->setStyleSheet(styleSheet1);

    addPlanes();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    DialogAdd addWindow(flVec, planeVec);
    addWindow.exec();
    actualTable();
}


void MainWindow::on_editButton_clicked()
{
    QItemSelectionModel *selectionModel = ui->flightsTable->selectionModel();
    QModelIndexList selectedRows = selectionModel->selectedRows();

    foreach(const QModelIndex& index, selectedRows) {
        int row = index.row();
        DialogEdit editWindow(flVec, planeVec, row);
        editWindow.exec();
        actualTable();
    }

}


void MainWindow::on_deleteButton_clicked()
{
    QItemSelectionModel *selectionModel = ui->flightsTable->selectionModel();
    QModelIndexList selectedRows = selectionModel->selectedRows();

    foreach(const QModelIndex& index, selectedRows) {
        int row = index.row();
        flVec.erase(flVec.begin() + row);
        actualTable();
    }
}


void MainWindow::on_showButton_clicked()
{
    currentShow();
}

void MainWindow::on_openFileButton_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, "Open .txt", tr("Text File (*.txt)"));
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "Error", "Not file selected");
        return;
    }

    file.setFileName(filePath);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);

    while (!fileStream.atEnd()) {
        QString s1, s2, s3, s4, s5, s6;

        s1 = fileStream.readLine();
        s2 = fileStream.readLine();
        s3 = fileStream.readLine();
        s4 = fileStream.readLine();
        s5 = fileStream.readLine();
        s6 = fileStream.readLine();

     /*   qDebug() << s1 << '\n' << s2 << '\n' <<s3 << '\n' <<s4 << '\n' <<s5 << '\n' <<s6;
qDebug() << "\n\n\n\n";*/

       if (!s1.toInt() || s2.isEmpty() || !s3.toDouble() || s4.isEmpty() ||
            !QDate::fromString(s5, "hh:mm:ss").isNull()
            || !QDate::fromString(s6, "hh:mm:ss").isNull()) {
            QMessageBox::warning(this, "Error", "Wrong file");
            return;
        }

    }

    file.close();
    fromFile();
}


void MainWindow::on_saveFileButton_clicked()
{
    toFile();
}

void MainWindow::actualTable()
{

    ui->comboBox->setCurrentIndex(0);
    ui->flightsTable->setRowCount(0);
    ui->comboBox->clear();
    ui->comboBox->addItem(QString("All"));
    for(int i = 0; i < flVec.size(); i++)
    {
        int row = ui->flightsTable->rowCount();
        ui->flightsTable->insertRow(row);
        QTextEdit *textEdit = new QTextEdit();
        textEdit->setReadOnly(true);
        textEdit->setFixedHeight(150);
        textEdit->setPlainText(flVec[i].getFullInfo());
        ui->flightsTable->setCellWidget(i, 0, textEdit);
        ui->flightsTable->setRowHeight(i, 150);
        if(ui->comboBox->findText(flVec[i].getDestination()) == -1)
            ui->comboBox->addItem(flVec[i].getDestination());
    }
}

void MainWindow::fromFile()
{
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    QString flightNumber;
    QString destination;
    QString distance;
    QString type;
    QString arriveTime;
    QString departureTime;

    do {
        stream >> flightNumber;
        if (!flightNumber.isEmpty()) {

            stream >> destination;
            stream >> distance;
            stream >> type;
            stream >> arriveTime;
            stream >> departureTime;
            flVec.push_back(Flight(flightNumber.toInt(), destination, distance.toDouble(), type, QDateTime::fromString(arriveTime, "hh:mm:ss"), QDateTime::fromString(departureTime,"hh:mm:ss")));

        }
    } while (!flightNumber.isEmpty());


    file.close();
    actualTable();
}

void MainWindow::toFile()
{
    file.open(QIODevice::ReadWrite);
    file.resize(0);
    QTextStream stream(&file);
    for (int i = 0; i < flVec.size(); i++) {
        stream << flVec[i].getInfo();
        stream << "\n";
    }
    file.close();
    QMessageBox::information(this, "Save", "Saved!");
}

void MainWindow::currentShow()
{
    QString searchStr= ui->comboBox->currentText();
    if(searchStr != "All"){
        ui->flightsTable->setRowCount(0);
        for(int i = 0; i < flVec.size() ; i++){
            if(flVec[i].getDestination() == searchStr){
                int row = ui->flightsTable->rowCount();
                ui->flightsTable->insertRow(row);
                QTextEdit *textEdit = new QTextEdit();
                textEdit->setReadOnly(true);
                textEdit->setFixedHeight(150);
                textEdit->setPlainText(flVec[i].getFullInfo());
                ui->flightsTable->setCellWidget(row, 0, textEdit);
                ui->flightsTable->setRowHeight(row, 150);
            }
        }
    }
    else if(searchStr == "All"){
        ui->flightsTable->setRowCount(0);
        for(int i = 0; i < flVec.size(); i++){
            int row = ui->flightsTable->rowCount();
            ui->flightsTable->insertRow(row);
            QTextEdit *textEdit = new QTextEdit();
            textEdit->setReadOnly(true);
            textEdit->setFixedHeight(150);
            textEdit->setPlainText(flVec[i].getFullInfo());
            ui->flightsTable->setCellWidget(i, 0, textEdit);
            ui->flightsTable->setRowHeight(i, 150);
        }
    }
}


void MainWindow::on_flightsTable_itemSelectionChanged()
{

}


void MainWindow::on_pushButton_4_clicked()
{

}


void MainWindow::on_sortDistanceButton_clicked()
{
    std::sort(flVec.begin(), flVec.end(), [](const Flight& a, const Flight& b) {
        return a.getDistance() < b.getDistance();
    });
    currentShow();
}


void MainWindow::on_sortDepartureButton_clicked()
{
    std::sort(flVec.begin(), flVec.end(), [](const Flight& a, const Flight& b) {
        return a.getDepartureTime() < b.getDepartureTime();
    });
    currentShow();
}

double MainWindow::calculate()
{
    double res = 0;
    for(int i = 0; i < flVec.size(); i++)
    {
        for(int j = 0; j < planeVec.size(); j++)
        {
            if(flVec[i].getType() == planeVec[j].getTypeString()){
                res += flVec[i].getDistance() * planeVec[j].getFuelCons();
                break;
            }
        }
    }
    return res;
}

void MainWindow::addPlanes()
{
    //////////////
    planesFilePath = "/home/user/OAIP/Labs/Lab2/L2T2/planes.txt"; //???? add path ??????
    QFile planesFile(planesFilePath);
    if (!planesFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "err p f Do correct path";
    }

    QTextStream stream(&planesFile);
    QString type;
    QString year;
    QString fuel;
    do {
        stream >> type;
        if (!type.isEmpty()) {
            stream >> year;
            stream >> fuel;
            planeVec.push_back(Plane(type, year.toInt(), fuel.toInt()));
        }
    } while (!type.isEmpty());
    planesFile.close();
    ///////////
    for(int i = 0; i < planeVec.size(); i++){
        ui->planesTable->setRowCount(0);
        for(int i = 0; i < planeVec.size(); i++)
        {
            int row = ui->planesTable->rowCount();
            ui->planesTable->insertRow(row);
            QTextEdit *textEdit = new QTextEdit();
            textEdit->setReadOnly(true);
            textEdit->setFixedHeight(100);
            textEdit->setPlainText(planeVec[i].getFullInfo());
            ui->planesTable->setCellWidget(i, 0, textEdit);
            ui->planesTable->setRowHeight(i, 100);
        }
    }
}


void MainWindow::on_calcButton_clicked()
{
    ui->label->setText(QString::number(calculate(), 'f', 2));
}

