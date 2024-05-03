#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(nCol);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "тип"
                                                             << "наименование"
                                                             << "автор"
                                                             << "стоимость"
                                                             << "примечание");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

bool MainWindow::comp1(disk x, disk y) {
    const QString x1 = x.type,x2 = x.name ,y1 = y.type ,y2 = y.name;
    if (x1==y1) {
        return x2<y2;
    }
    return x1<y1;
}

bool MainWindow::comp2(disk x, disk y) {
    const QString x1 = x.type,x2 = x.author ,y1 = y.type ,y2 = y.author;
    if (x1==y1) {
        return x2<y2;
    }
    return x1<y1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileEdit() {
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    file.close();
    for (auto &i: arr) {
        writeString(i.type+" ");
        writeString(i.name+" ");
        writeString(i.author+" ");
        writeString(QString::number(i.cost)+" ");
        writeString(i.prim+"\n");
    }
    writeString("-1# ");
}

void MainWindow::writeString(QString str)
{
    QFile file(path);
    file.open(QIODevice::Append);
    for (auto &j: str) {
        c[0] = j.unicode()-zero.unicode()+'0';
        file.write(c,1);
    }
    file.close();
}

void MainWindow::on_open_clicked()
{
    path = QFileDialog::getOpenFileName(nullptr, "Выберите .txt файл", QDir::homePath(), "Текстовые файлы (*.txt)");
    QFile file(path);
    if(!file.exists()){
        return;
    }

    if(!file.open(QIODevice::ReadOnly)){
        return;
    }

    for (int i=0;i<nRow;i++) {
        ui->tableWidget->removeRow(0);
    }
    arr.clear();

    nRow = 0;
    int i=0;

    QString inp;
    flag=true;
    count=0;
    while (flag) {
        for (int j = 0; j < nCol; j++) {
            count++;
            curr[j]="";
            inp = file.read(1);
            while (inp!=" " && inp!="\n") {
                curr[j]+=inp;
                inp = file.read(1);
            }
            if (curr[j]=="-1#") {
                flag = false;
                break;
            }
        }
        if (!flag) {
            break;
        }
        ui->tableWidget->insertRow(i);
        currDisk = disk(curr[0], curr[1], curr[2], curr[3].toInt(), curr[4]);
        arr.push_back(currDisk);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(currDisk.type));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(currDisk.name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(currDisk.author));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(currDisk.cost)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(currDisk.prim));
        i++;
    }
    nRow=i;
    file.close();
}

void MainWindow::on_add_clicked()
{
    currDisk = disk("", "", "", 0, "");
    arr.push_back(currDisk);
    ui->tableWidget->insertRow(nRow);
    nRow++;
    fileEdit();
}

void MainWindow::on_delete_2_clicked()
{
    if (ui->tableWidget->currentRow()!=-1) {
        auto it = arr.begin();
        it+=ui->tableWidget->currentRow();
        arr.erase(it);
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
        nRow--;
        fileEdit();
    }
}


void MainWindow::on_sortName_clicked()
{
    std::sort(arr.begin(),arr.end(),comp1);
    for (int i=0;i<arr.size();i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(arr[i].type));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(arr[i].name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(arr[i].author));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(arr[i].cost)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(arr[i].prim));
    }
    fileEdit();
}


void MainWindow::on_sortAuthor_clicked()
{
    std::sort(arr.begin(),arr.end(),comp2);
    for (int i=0;i<arr.size();i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(arr[i].type));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(arr[i].name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(arr[i].author));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(arr[i].cost)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(arr[i].prim));
    }
    fileEdit();
}


void MainWindow::on_findAuthor_clicked()
{
    ui->lineEdit_2->setText("Введите автора диска(запрещены пробелы и русские буквы)");
    ui->lineEdit->setEnabled(true);
    ui->buttonBox->setEnabled(true);
    typeAct = 1;
}


void MainWindow::on_findType_clicked()
{
    ui->lineEdit_2->setText("Введите тип диска(запрещены пробелы и русские буквы)");
    ui->lineEdit->setEnabled(true);
    ui->buttonBox->setEnabled(true);
    typeAct = 2;
}


void MainWindow::on_findName_clicked()
{
    ui->lineEdit_2->setText("Введите имя диска(запрещены пробелы и русские буквы)");
    ui->lineEdit->setEnabled(true);
    ui->buttonBox->setEnabled(true);
    typeAct = 3;
}

void MainWindow::on_edit_clicked()
{
    currCol = ui->tableWidget->currentColumn();
    currRow = ui->tableWidget->currentRow();
    ui->lineEdit->setEnabled(true);
    ui->buttonBox->setEnabled(true);
    switch(currCol) {
    case 0:
        ui->lineEdit_2->setText("Введите новый тип(запрещены пробелы и русские буквы)");
        break;
    case 1:
        ui->lineEdit_2->setText("Введите новое название(запрещены пробелы и русские буквы)");
        break;
    case 2:
        ui->lineEdit_2->setText("Введите нового автора(запрещены пробелы и русские буквы)");
        break;
    case 3:
        ui->lineEdit_2->setText("Введите новую цену(запрещены пробелы и русские буквы)");
        break;
    case 4:
        ui->lineEdit_2->setText("Введите новое примечание(запрещены пробелы и русские буквы)");
        break;
    default:
        break;
    }
    typeAct = 4;
}

void MainWindow::on_buttonBox_accepted()
{
    if (typeAct==1) {
        currauthor = ui->lineEdit->text();
        for (int i=0;i<nRow;i++) {
            ui->tableWidget->removeRow(0);
        }
        nRow = 0;
        for (auto &i: arr) {
            if (i.author==currauthor) {
                ui->tableWidget->insertRow(nRow);
                ui->tableWidget->setItem(nRow, 0, new QTableWidgetItem(i.type));
                ui->tableWidget->setItem(nRow, 1, new QTableWidgetItem(i.name));
                ui->tableWidget->setItem(nRow, 2, new QTableWidgetItem(i.author));
                ui->tableWidget->setItem(nRow, 3, new QTableWidgetItem(QString::number(i.cost)));
                ui->tableWidget->setItem(nRow, 4, new QTableWidgetItem(i.prim));
                nRow++;
            }
        }
    }
    if (typeAct==2) {
        currtype = ui->lineEdit->text();
        for (int i=0;i<nRow;i++) {
            ui->tableWidget->removeRow(0);
        }
        nRow = 0;
        for (auto &i: arr) {
            if (i.type==currtype) {
                ui->tableWidget->insertRow(nRow);
                ui->tableWidget->setItem(nRow, 0, new QTableWidgetItem(i.type));
                ui->tableWidget->setItem(nRow, 1, new QTableWidgetItem(i.name));
                ui->tableWidget->setItem(nRow, 2, new QTableWidgetItem(i.author));
                ui->tableWidget->setItem(nRow, 3, new QTableWidgetItem(QString::number(i.cost)));
                ui->tableWidget->setItem(nRow, 4, new QTableWidgetItem(i.prim));
                nRow++;
            }
        }
    }
    if (typeAct==3) {
        currname = ui->lineEdit->text();
        for (int i=0;i<nRow;i++) {
            ui->tableWidget->removeRow(0);
        }
        nRow = 0;
        for (auto &i: arr) {
            if (i.name==currname) {
                ui->tableWidget->insertRow(nRow);
                ui->tableWidget->setItem(nRow, 0, new QTableWidgetItem(i.type));
                ui->tableWidget->setItem(nRow, 1, new QTableWidgetItem(i.name));
                ui->tableWidget->setItem(nRow, 2, new QTableWidgetItem(i.author));
                ui->tableWidget->setItem(nRow, 3, new QTableWidgetItem(QString::number(i.cost)));
                ui->tableWidget->setItem(nRow, 4, new QTableWidgetItem(i.prim));
                nRow++;
            }
        }
    }
    if (typeAct==4) {
        qDebug() << currCol << currRow;
        switch(currCol) {
        case 0:
            arr[currRow].type = ui->lineEdit->text();
            ui->tableWidget->setItem(currRow, currCol, new QTableWidgetItem(arr[currRow].type));
            break;
        case 1:
            arr[currRow].name = ui->lineEdit->text();
            ui->tableWidget->setItem(currRow, currCol, new QTableWidgetItem(arr[currRow].name));
            break;
        case 2:
            arr[currRow].author = ui->lineEdit->text();
            ui->tableWidget->setItem(currRow, currCol, new QTableWidgetItem(arr[currRow].author));
            break;
        case 3:
            currcost = ui->lineEdit->text().toInt(&ok, dec);
            if (ok) {
                arr[currRow].cost = currcost;
                ui->tableWidget->setItem(currRow, currCol, new QTableWidgetItem(QString::number(currcost)));
            } else {
                form.show();
            }
            break;
        case 4:
            arr[currRow].prim = ui->lineEdit->text();
            ui->tableWidget->setItem(currRow, currCol, new QTableWidgetItem(arr[currRow].prim));
            break;
        default:
            break;
        }
        fileEdit();
    }
    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->buttonBox->setEnabled(false);
    typeAct = 0;
}


void MainWindow::on_buttonBox_rejected()
{
    ui->lineEdit->setText("");
}

void MainWindow::on_showAll_clicked()
{
    for (int i=0;i<nRow;i++) {
        ui->tableWidget->removeRow(0);
    }
    for (int i=0;i<arr.size();i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(arr[i].type));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(arr[i].name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(arr[i].author));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(arr[i].cost)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(arr[i].prim));
    }
    nRow = arr.size();
}
