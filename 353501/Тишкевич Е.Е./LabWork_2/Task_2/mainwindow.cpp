#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "person.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->isM->setChecked(true);


     connect(ui->openB, &QPushButton::pressed, this, &MainWindow::openAndCheck);
    connect(ui->isM, &QCheckBox::pressed, this, &MainWindow::checkF);
     connect(ui->isW, &QCheckBox::pressed, this, &MainWindow::checkS);
    connect(ui->addB, &QPushButton::pressed, this, &MainWindow::addToFile);
     connect(ui->lAge, &QSpinBox::valueChanged, this, &MainWindow::setLimit);
    connect(ui->rAge, &QSpinBox::valueChanged, this, &MainWindow::setLimit2);
      connect(ui->deleteB, &QPushButton::pressed, this, &MainWindow::removeBlock);
    connect(ui->sortB, &QPushButton::pressed, this, &MainWindow::sortTables);
    connect(ui->candidateB, &QPushButton::pressed, this, &MainWindow::fillMatches);
    connect(ui->allB, &QPushButton::pressed, this, &MainWindow::fillMatches);





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openAndCheck() {
    inds.clear();
    pathToFile = QFileDialog::getOpenFileName(this, tr("Choose file"), {}, tr("*.txt"));
    if (pathToFile.isEmpty()) {
        QMessageBox::warning(this, "Error", "No file selected.");
        return;
    }

    file.setFileName(pathToFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл");
        return;
    }

    QTextStream in(&file);
    int lineNumber = 0;
    int blockNumber = 0;
    int nullCount = 0;
    bool lastLineWasEmpty=false;
    do {
        QString line = in.readLine();
        lineNumber++;
        if (line.isEmpty())
        {
            blockNumber = 0;
            nullCount++;
            lastLineWasEmpty=true;
            if (nullCount>1)
            {
                QMessageBox::critical(nullptr, "Ошибка", "Ошибка в строке " + QString::number(lineNumber) + ": использовано 2 или более пробельные строки подряд");
                return;
            }
            continue;
        }
        else {nullCount=0; lastLineWasEmpty=false;}

        blockNumber++;
        switch (blockNumber) {
        case 1: {
            bool ok;
            line.toInt(&ok);
            if (!ok) {
                QMessageBox::critical(nullptr, "Ошибка", "Ошибка в строке " + QString::number(lineNumber) + ": ожидалось число");
                return;
            }
            inds.push_back(line.toInt());
            if (inds.count(line.toInt())>1)
            {
                inds.pop_back();
                QMessageBox::critical(nullptr, "Ошибка", "Ошибка в строке " + QString::number(lineNumber) + ": порядковый номер должен быть уникален");
                return;
            }
            break;
        }
        case 2: {
            if (line != "М" && line != "Ж") {
                QMessageBox::critical(nullptr, "Ошибка", "Ошибка в строке " + QString::number(lineNumber) + ": ожидалась буква 'М' или 'Ж'");
                return;
            }
            break;
        }
        case 3: {
            // имя может быть любым, проверка не требуется
            break;
        }
        case 4:
        case 5:
        case 6: {
            bool ok;
            line.toInt(&ok);
            if (!ok) {
                QMessageBox::critical(nullptr, "Ошибка", "Ошибка в строке " + QString::number(lineNumber) + ": ожидалось число");
                return;
            }
            break;
        }
        case 7:
        case 8:
        case 9: {
            QStringList numbers = line.split(" ");
            if (numbers.size() != 2) {
                QMessageBox::critical(nullptr, "Ошибка", "Ошибка в строке " + QString::number(lineNumber) + ": ожидалось два числа, разделенных пробелом");
                return;
            }
            bool ok1, ok2;
            int num1 = numbers[0].toInt(&ok1);
            int num2 = numbers[1].toInt(&ok2);
            if (!ok1 || !ok2 || num1 < 0 || num1 > num2) {
                QMessageBox::critical(nullptr, "Ошибка", "Ошибка в строке " + QString::number(lineNumber) + ": ожидались два числа, где первое меньше или равно второму и неотрицательно");
                return;
            }
            break;
        }
        default: {
            QMessageBox::critical(nullptr, "Ошибка", "Ошибка в строке " + QString::number(lineNumber) + ": ожидалась пустая строка");
            return;
        }
        }
    }while (!in.atEnd());

    /* if (!lastLineWasEmpty) {
        QMessageBox::critical(nullptr, "Ошибка", "Ошибка: в конце файла ожидалась пустая строка");
        return;
    }*/

    putDataFromFileToTable();
}

void MainWindow::putDataFromFileToTable() {
    if (pathToFile.isEmpty()) return;
    qDebug()<<"successfull";

    ui->men->setRowCount(0);
    ui->women->setRowCount(0);

    file.setFileName(pathToFile);
    file.open(QIODevice::ReadWrite);
    QTextStream fileStream(&file);

    QString s;
    while (!fileStream.atEnd()) {
        QString block="";
        s = fileStream.readLine();
        while (s!="" && !fileStream.atEnd())
        {
            block+=s+'\n';
            s = fileStream.readLine();
        }
        addPerson(block, true);
    }

    file.close();
}

void MainWindow::addPerson(QString str, bool add)
{
        //str.erase(str.begin(), str.begin()+1);
        QStringList list = str.split("\n");

        Person person;
        person.ind = list[0].toInt();
        person.gen = list[1];
        person.name = list[2];
        person.age = list[3].toInt();
        person.wei = list[4].toInt();
        person.hei = list[5].toInt();
        QStringList ageRange = list[6].split(" ");
        person.l_age = ageRange[0].toInt();
        person.r_age = ageRange[1].toInt();
        QStringList weiRange = list[7].split(" ");
        person.l_wei = weiRange[0].toInt();
        person.r_wei = weiRange[1].toInt();
        QStringList heiRange = list[8].split(" ");
        person.l_hei = heiRange[0].toInt();
        person.r_hei = heiRange[1].toInt();

        if (add)
        {
        if (person.gen == "М") {
            men.push_back(person);
            m_inds.push_back(person.ind);
        } else if (person.gen == "Ж") {
            women.push_back(person);
            w_inds.push_back(person.ind);
        }
         loadTable(person, true);
        }
        else
        {
            if (person.gen == "М") {
                for (auto &el: men) if (el.ind==person.ind) el=person;

            }
            else if (person.gen == "Ж") {
                for (auto &el: women) if (el.ind==person.ind) el=person;
            }
             loadTable(person, false);
        }
}

void MainWindow::loadTable(Person p, bool add)
{
    QTableWidget* choice;
    p.gen=="М" ? choice = ui->men : choice = ui->women;
   // qDebug()<<p.gen;

    int row=0;
    for (int i = 0; i<choice->rowCount(); i++) if (choice->item(i,0)->text()==QString::number(p.ind)) {row = i; break;}

    if (add) choice->insertRow(choice->rowCount());

    QTableWidgetItem* item0 = new QTableWidgetItem();
    item0->setText(QString::number(p.ind));
    add? choice->setItem(choice->rowCount()-1, 0, item0) : choice->setItem(row, 0, item0);

    QTableWidgetItem* item1 = new QTableWidgetItem();
    item1->setText(p.name);
    add? choice->setItem(choice->rowCount()-1, 1, item1) : choice->setItem(row, 1, item1);

    QTableWidgetItem* item2 = new QTableWidgetItem();
    item2->setText(QString::number(p.age));
    add? choice->setItem(choice->rowCount()-1, 2, item2) : choice->setItem(row, 2, item2);

    QTableWidgetItem* item3 = new QTableWidgetItem();
    item3->setText(QString::number(p.wei));
    add? choice->setItem(choice->rowCount()-1, 3, item3) : choice->setItem(row, 3, item3);

    QTableWidgetItem* item4 = new QTableWidgetItem();
    item4->setText(QString::number(p.hei));
    add? choice->setItem(choice->rowCount()-1, 4, item4) : choice->setItem(row, 4, item4);

    QTableWidgetItem* item5 = new QTableWidgetItem();
    item5->setText(QString::number(p.l_age)+"-"+QString::number(p.r_age));
    add? choice->setItem(choice->rowCount()-1, 5, item5) : choice->setItem(row, 5, item5);

    QTableWidgetItem* item6 = new QTableWidgetItem();
    item6->setText(QString::number(p.l_wei)+"-"+QString::number(p.r_wei));
    add? choice->setItem(choice->rowCount()-1, 6, item6) : choice->setItem(row, 6, item6);

    QTableWidgetItem* item7 = new QTableWidgetItem();
    item7->setText(QString::number(p.l_hei)+"-"+QString::number(p.r_hei));
    add? choice->setItem(choice->rowCount()-1, 7, item7) : choice->setItem(row, 7, item7);


}

void MainWindow::checkF()
{
    ui->isW->setChecked(false);
}

void MainWindow::checkS()
{
  ui->isM->setChecked(false);
}

void MainWindow::addToFile()
{
    QFile nfile(pathToFile);

    if (!nfile.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug()<<"Fail to open";
        return;
    }
    QTextStream out(&nfile);

    QString block = "\n";

    if (firstAdd) {out<<"\n"; firstAdd=false;}

    block+=QString::number(ui->numSpin->value())+"\n";

    if (ui->isM->isChecked()) {block+="М\n"; m_inds.push_back(ui->numSpin->value());}
    else if (ui->isW->isChecked()) {block+="Ж\n"; w_inds.push_back(ui->numSpin->value());}
    else { QMessageBox::warning(this, "Error", "Select the gender"); return;}

    block+=(ui->nameEdit->toPlainText())+"\n";

    block+=QString::number(ui->ageSpin->value())+"\n";
     block+=QString::number(ui->weiSpin->value())+"\n";
     block+=QString::number(ui->heiSpin->value())+"\n";

     block+= QString::number(ui->lAge->value())+' '+QString::number(ui->rAge->value())+"\n";
     block+= QString::number(ui->lWei->value())+' '+QString::number(ui->rWei->value())+"\n";
     block+= QString::number(ui->lHei->value())+' '+QString::number(ui->rHei->value())+"\n";

     QString copyBlock = block;
     copyBlock.erase(copyBlock.begin(), copyBlock.begin()+1);

     if ((m_inds.count(ui->numSpin->value())>1 && w_inds.count(ui->numSpin->value())==0) ||
         (w_inds.count(ui->numSpin->value())>1 && m_inds.count(ui->numSpin->value())==0))
     {
         if (ui->isM->isChecked()) m_inds.pop_back();
         else if (ui->isW->isChecked()) w_inds.pop_back();
         changeBlock(copyBlock);
         addPerson(copyBlock, false);
         return;
     }

     else if (m_inds.count(ui->numSpin->value())>=1 && w_inds.count(ui->numSpin->value())>=1)
     {
         if (ui->isM->isChecked()) m_inds.pop_back();
         else if (ui->isW->isChecked()) w_inds.pop_back();
          QMessageBox::critical(nullptr, "Ошибка", "Данный номер уже присутствует во второй таблице");
         return;
     }

     out<<block;

     nfile.close();
    addPerson(copyBlock, true);

}


void MainWindow::setLimit(int val)
{
    if (val>ui->rAge->value()) ui->lAge->setValue(ui->rAge->value());
}

void MainWindow::setLimit2(int val)
{
    if (val<ui->lAge->value()) ui->rAge->setValue(ui->lAge->value());
}

void MainWindow::removeBlock() {
    QFile nfile(pathToFile);
    int indToRemove = ui->numSpin->value();
    if (!nfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл");
        return;
    }


    QTextStream in(&nfile);
    QStringList content;
    int count =9;
    bool skip= false;
    while (!in.atEnd()) {
        QString line = in.readLine();

         if (skip && count>0) {count--; continue;}

        bool ok;
        int num = line.toInt(&ok);
        //   qDebug()<<num;
        if (num==indToRemove) {skip = true;continue;}

        content.append(line);
    }

    auto it = std::find_if(men.begin(), men.end(), [indToRemove](Person a){return a.ind==indToRemove;} );
    if (it!=men.end()) men.erase(it, it+1);

    it = std::find_if(women.begin(), women.end(), [indToRemove](Person a){return a.ind==indToRemove;} );
    if (it!=women.end()) women.erase(it, it+1);

    nfile.close();

    if (!nfile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing";
        return;
    }

    QTextStream outt(&nfile);
    for (const QString &line : content)
    {
        qDebug()<<line;
        outt << line << "\n";
    }

    nfile.close();

    deleteFromTable(indToRemove);
}

void MainWindow::deleteFromTable(int i)
{
    for (int row = 0; row<ui->men->rowCount(); row++)
    {
        if (ui->men->item(row,0)->text()==QString::number(i)) ui->men->removeRow(row);
    }

    for (int row = 0; row<ui->women->rowCount(); row++)
    {
        if (ui->women->item(row,0)->text()==QString::number(i)) ui->women->removeRow(row);
    }
}

void MainWindow::changeBlock(QString block) {
    QFile nfile(pathToFile);
    int indToRemove = ui->numSpin->value();
    if (!nfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Не удалось открыть файл");
        return;
    }


    QTextStream in(&nfile);
    QStringList content;
    int count =9;
    bool skip= false;
    int pos = 0;
    int t_pos=0;
    while (!in.atEnd()) {
        QString line = in.readLine();

        if (skip && count>0) {count--; continue;}

        bool ok;
        int num = line.toInt(&ok);
        //   qDebug()<<num;
        if (num==indToRemove) {skip = true; t_pos=pos; continue;}

        content.append(line);
        pos++;

    }

    nfile.close();

    if (!nfile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing";
        return;
    }

    QTextStream outt(&nfile);

    int cnt= 0;
    for (const QString &line : content)
    {
        qDebug()<<line;
        cnt++;
        if(cnt==t_pos+1) outt<<block<<"\n";
        outt << line << "\n";
    }
    nfile.close();

    //deleteFromTable(indToRemove);
}

void MainWindow::sortTables()
{
    std::sort(men.begin(), men.end(), [](Person a, Person b){return a.age>b.age;});
    std::sort(women.begin(), women.end(), [](Person a, Person b){return a.age>b.age;});

    for(auto &el: men) {qDebug()<<el.age;}

    for (int i =0; i<men.size(); i++)
    {
        Person man = men[i];
        QTableWidgetItem* item0= new QTableWidgetItem();
        item0->setText(QString::number(man.ind));
        ui->men->setItem(i, 0, item0);

        QTableWidgetItem* item1 = new QTableWidgetItem();
        item1->setText(man.name);
        ui->men->setItem(i, 1, item1);

        QTableWidgetItem* item2 = new QTableWidgetItem();
        item2->setText(QString::number(man.age));
        ui->men->setItem(i, 2, item2);

        QTableWidgetItem* item3 = new QTableWidgetItem();
        item3->setText(QString::number(man.wei));
        ui->men->setItem(i, 3, item3);

        QTableWidgetItem* item4 = new QTableWidgetItem();
        item4->setText(QString::number(man.hei));
        ui->men->setItem(i, 4, item4);

        QTableWidgetItem* item5 = new QTableWidgetItem();
        item5->setText(QString::number(man.l_age)+"-"+QString::number(man.r_age));
        ui->men->setItem(i, 5, item5);

        QTableWidgetItem* item6 = new QTableWidgetItem();
        item6->setText(QString::number(man.l_wei)+"-"+QString::number(man.r_wei));
        ui->men->setItem(i, 6, item6);

        QTableWidgetItem* item7 = new QTableWidgetItem();
        item7->setText(QString::number(man.l_hei)+"-"+QString::number(man.r_hei));
        ui->men->setItem(i, 7, item7);


    }

    for (int i =0; i<women.size(); i++)
    {
        Person man = women[i];
        QTableWidgetItem* item0= new QTableWidgetItem();
        item0->setText(QString::number(man.ind));
        ui->women->setItem(i, 0, item0);

        QTableWidgetItem* item1 = new QTableWidgetItem();
        item1->setText(man.name);
        ui->women->setItem(i, 1, item1);

        QTableWidgetItem* item2 = new QTableWidgetItem();
        item2->setText(QString::number(man.age));
        ui->women->setItem(i, 2, item2);

        QTableWidgetItem* item3 = new QTableWidgetItem();
        item3->setText(QString::number(man.wei));
        ui->women->setItem(i, 3, item3);

        QTableWidgetItem* item4 = new QTableWidgetItem();
        item4->setText(QString::number(man.hei));
        ui->women->setItem(i, 4, item4);

        QTableWidgetItem* item5 = new QTableWidgetItem();
        item5->setText(QString::number(man.l_age)+"-"+QString::number(man.r_age));
        ui->women->setItem(i, 5, item5);

        QTableWidgetItem* item6 = new QTableWidgetItem();
        item6->setText(QString::number(man.l_wei)+"-"+QString::number(man.r_wei));
        ui->women->setItem(i, 6, item6);

        QTableWidgetItem* item7 = new QTableWidgetItem();
        item7->setText(QString::number(man.l_hei)+"-"+QString::number(man.r_hei));
        ui->women->setItem(i, 7, item7);


    }
}

void MainWindow::fillMatches()
{
    bool isOne=false;
    if (sender()==ui->candidateB) isOne = true;
    createPairs(isOne);
}

void MainWindow::createPairs(bool isOne)
{
     pairs.clear();
    ui->result->setRowCount(0);

    qDebug()<<men.size();

    for (auto&man: men) qDebug()<<man.ind;

    qDebug()<<"\n";

         for (auto&woman: women) qDebug()<<woman.ind;

    for (auto&man: men)
        for (auto&woman: women)
        {
            if (man.age>=woman.l_age && man.age<=woman.r_age
                && man.hei>=woman.l_hei && man.hei<=woman.r_hei
                && man.wei>=woman.l_wei && man.age<=woman.r_wei)
                pairs.push_back({woman, man});
            if (woman.age>=man.l_age && woman.age<=man.r_age
                && woman.hei>=man.l_hei && woman.hei<=man.r_hei
                && woman.wei>=man.l_wei && woman.age<=man.r_wei)
                pairs.push_back({man, woman});
        }

    if (isOne)
    {
        int ind = ui->choiceSpin->value();
        if (std::find_if(men.begin(), men.end(), [ind](Person a){return a.ind==ind;})==men.end()
            && std::find_if(women.begin(), women.end(), [ind](Person a){return a.ind==ind;})==women.end())
        {
              QMessageBox::critical(nullptr, "Ошибка", "Данный кандидат отсутствует в таблице");
            return;
        }
        for (auto& pair: pairs)
        {

            if (pair.first.ind==ind)
            {
                           QTableWidgetItem* item = new QTableWidgetItem();
                        item->setText(QString::number(pair.first.ind)+", "+pair.first.name
                          + " - " + QString::number(pair.second.ind)+", "+pair.second.name);
                           ui->result->insertRow(ui->result->rowCount());
                        ui->result->setItem(ui->result->rowCount()-1, 0, item);
            }
        }
     }
    else
    {
        for (auto& pair:pairs)
         {
             if (pair.first.age>=pair.second.l_age && pair.first.age<=pair.second.r_age
                 && pair.first.wei>=pair.second.l_wei && pair.first.wei<=pair.second.r_wei
                 && pair.first.hei>=pair.second.l_hei && pair.first.hei<=pair.second.r_hei)
            {
             QTableWidgetItem* item = new QTableWidgetItem();
             item->setText(QString::number(pair.first.ind)+", "+pair.first.name
                           + " - " + QString::number(pair.second.ind)+", "+pair.second.name);
             ui->result->insertRow(ui->result->rowCount());
             ui->result->setItem(ui->result->rowCount()-1, 0, item);
             }
         }
    }
}
