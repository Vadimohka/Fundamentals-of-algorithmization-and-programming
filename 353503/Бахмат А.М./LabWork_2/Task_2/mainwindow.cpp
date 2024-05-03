#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    font.setStrikeOut(true);
    systemFont = QApplication::font("QMenu");
    ui -> addButton -> setEnabled(false);
    ui -> editButton -> setEnabled(false);
    ui -> sortButton -> setEnabled(false);
    ui -> findButton -> setEnabled(false);
    ui -> maleRadioButton -> setEnabled(false);
    ui -> FemaleRadioButton -> setEnabled(false);
    ui -> comboBox -> setEnabled(false);
    ui -> spinBox -> setEnabled(false);
    ui -> spinBox_2 -> setEnabled(false);
    ui -> maleRadioButton_2 -> setEnabled(false);
    ui -> femaleRadioButton_2 -> setEnabled(false);
    ui -> comboBox -> addItem("Sort By Id");
    ui -> comboBox -> addItem("Sort By Age");
    ui -> comboBox -> addItem("Sort By Height");
    ui -> comboBox -> addItem("Sort By Weight");
    ui -> tableWidget -> setColumnWidth(0, 10);
    ui -> tableWidget -> setColumnWidth(1, 80);
    ui -> tableWidget -> setColumnWidth(2, 40);
    ui -> tableWidget -> setColumnWidth(3, 60);
    ui -> tableWidget -> setColumnWidth(4, 60);
    ui -> tableWidget -> setColumnWidth(5, 100);
    ui -> tableWidget -> setColumnWidth(6, 100);
    ui -> tableWidget -> setColumnWidth(7, 65);
    ui -> tableWidget -> setColumnWidth(8, 65);
    ui -> tableWidget -> setColumnWidth(9, 90);
    ui -> tableWidget -> setColumnWidth(10, 90);
    ui -> tableWidget -> setColumnWidth(11, 90);
    ui -> tableWidget -> setColumnWidth(12, 90);
    ui -> tableWidget_2 -> setColumnWidth(0, 10);
    ui -> tableWidget_2 -> setColumnWidth(1, 80);
    ui -> tableWidget_2 -> setColumnWidth(2, 40);
    ui -> tableWidget_2 -> setColumnWidth(3, 60);
    ui -> tableWidget_2 -> setColumnWidth(4, 60);
    ui -> tableWidget_2 -> setColumnWidth(5, 100);
    ui -> tableWidget_2 -> setColumnWidth(6, 100);
    ui -> tableWidget_2 -> setColumnWidth(7, 65);
    ui -> tableWidget_2 -> setColumnWidth(8, 65);
    ui -> tableWidget_2 -> setColumnWidth(9, 90);
    ui -> tableWidget_2 -> setColumnWidth(10, 90);
    ui -> tableWidget_2 -> setColumnWidth(11, 90);
    ui -> tableWidget_2 -> setColumnWidth(12, 90);
    window1 -> setLayout(layout1);
    window1 -> setWindowTitle("new Human");
    window1 -> setGeometry(0, 0, 300, 300);
    window1 -> layout() -> addWidget(maleRadioBitton1);
    maleRadioBitton1 -> setText("Male");
    window1 -> layout() -> addWidget(femaleRadioBitton1);
    femaleRadioBitton1 -> setText("Female");
    window1 -> layout() -> addWidget(idLine1);
    idLine1 -> setPlaceholderText("Id: ");
    window1 -> layout() -> addWidget(nameLine1);
    nameLine1 -> setPlaceholderText("Name: ");
    window1 -> layout() -> addWidget(ageLine1);
    ageLine1 -> setPlaceholderText("Age: ");
    window1 -> layout() -> addWidget(heightLine1);
    heightLine1 -> setPlaceholderText("Height: ");
    window1 -> layout() -> addWidget(weightLine1);
    weightLine1 -> setPlaceholderText("Weight: ");
    window1 -> layout() -> addWidget(habitsLine1);
    habitsLine1 -> setPlaceholderText("Habits: ");
    window1 -> layout() -> addWidget(hobbyLine1);
    hobbyLine1 -> setPlaceholderText("Hobby: ");
    window1 -> layout() -> addWidget(minAgeLine1);
    minAgeLine1 -> setPlaceholderText("Min Age: ");
    window1 -> layout() -> addWidget(maxAgeLine1);
    maxAgeLine1 -> setPlaceholderText("Max Age: ");
    window1 -> layout() -> addWidget(minHeightLine1);
    minHeightLine1 -> setPlaceholderText("Min Height: ");
    window1 -> layout() -> addWidget(maxHeightLine1);
    maxHeightLine1 -> setPlaceholderText("Max Height: ");
    window1 -> layout() -> addWidget(minWeightLine1);
    minWeightLine1 -> setPlaceholderText("Min Weight: ");
    window1 -> layout() -> addWidget(maxWeightLine1);
    maxWeightLine1 -> setPlaceholderText("Max Weight: ");
    window1 -> layout() -> addWidget(button1);
    window2 -> setLayout(layout2);
    window2 -> setWindowTitle("new Human");
    window2 -> setGeometry(0, 0, 300, 300);
    window2 -> layout() -> addWidget(idLine2);
    idLine2 -> setPlaceholderText("Id: ");
    window2 -> layout() -> addWidget(nameLine2);
    nameLine2 -> setPlaceholderText("Name: ");
    window2 -> layout() -> addWidget(ageLine2);
    ageLine2 -> setPlaceholderText("Age: ");
    window2 -> layout() -> addWidget(heightLine2);
    heightLine2 -> setPlaceholderText("Height: ");
    window2 -> layout() -> addWidget(weightLine2);
    weightLine2 -> setPlaceholderText("Weight: ");
    window2 -> layout() -> addWidget(habitsLine2);
    habitsLine2 -> setPlaceholderText("Habits: ");
    window2 -> layout() -> addWidget(hobbyLine2);
    hobbyLine2 -> setPlaceholderText("Hobby: ");
    window2 -> layout() -> addWidget(minAgeLine2);
    minAgeLine2 -> setPlaceholderText("Min Age: ");
    window2 -> layout() -> addWidget(maxAgeLine2);
    maxAgeLine2 -> setPlaceholderText("Max Age: ");
    window2 -> layout() -> addWidget(minHeightLine2);
    minHeightLine2 -> setPlaceholderText("Min Height: ");
    window2 -> layout() -> addWidget(maxHeightLine2);
    maxHeightLine2 -> setPlaceholderText("Max Height: ");
    window2 -> layout() -> addWidget(minWeightLine2);
    minWeightLine2 -> setPlaceholderText("Min Weight: ");
    window2 -> layout() -> addWidget(maxWeightLine2);
    maxWeightLine2 -> setPlaceholderText("Max Weight: ");
    window2 -> layout() -> addWidget(button2);
    windowMatches -> setGeometry(0, 0, 490, 300);
    windowMatches -> setLayout(layoutMatches);
    tableMatches -> setColumnCount(7);
    tableMatches -> setColumnWidth(0, 20);
    tableMatches -> setColumnWidth(1, 80);
    tableMatches -> setColumnWidth(2, 40);
    tableMatches -> setColumnWidth(3, 60);
    tableMatches -> setColumnWidth(4, 60);
    tableMatches -> setColumnWidth(5, 100);
    tableMatches -> setColumnWidth(6, 100);
    _headerStr << "Id" << "Name" << "Age" << "Height" << "Weight" << "Habits" << "Hobby";
    tableMatches -> setHorizontalHeaderLabels(_headerStr);
    windowMatches -> layout() -> addWidget(tableMatches);
    labelMatches -> setText("Enter the number of your crush");
    windowMatches -> layout() -> addWidget(labelMatches);
    windowMatches -> layout() -> addWidget(spinBoxMatches);
    buttonMatches -> setText("Match!");
    windowMatches -> layout() -> addWidget(buttonMatches);
    connect(buttonMatches, SIGNAL(clicked()), this, SLOT(match()));
    connect(button1, SIGNAL(clicked()), this, SLOT(addHuman()));
    connect(button2, SIGNAL(clicked()), this, SLOT(editHuman()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFile_clicked()
{
    _filePath = QFileDialog::getOpenFileName(nullptr, "Выберите файл", QDir::homePath(), "Текстовые файлы (*.txt)");
    readTextFile();
}

void MainWindow::readTextFile()
{
    if (_filePath.isEmpty())
        return;

    _file.setFileName(_filePath);
    if (!_file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    ui -> tableWidget -> clearContents();
    ui -> tableWidget_2 -> clearContents();
    males.clear();
    females.clear();

    QTextStream fileStream(&_file);
    QString s;
    do
    {
        fileStream >> s;
        if(!s.isEmpty())
        {
            if(s.endsWith('\\'))
            {
                s.chop(1);
            }
            if(checkAndGetGender(s) != "")
            {
                addToVector(s);
            }
            else
            {
                QMessageBox::warning(this, "Warning", "Wrong data");
                ui-> tableWidget -> setRowCount(0);
                ui-> tableWidget_2 -> setRowCount(0);
                return;
            }
        }
    } while (!fileStream.atEnd());

    ui -> addButton -> setEnabled(true);
    ui -> editButton -> setEnabled(true);
    ui -> sortButton -> setEnabled(true);
    ui -> findButton -> setEnabled(true);
    ui -> maleRadioButton -> setEnabled(true);
    ui -> FemaleRadioButton -> setEnabled(true);
    ui -> comboBox -> setEnabled(true);
    ui -> spinBox -> setEnabled(true);
    ui -> spinBox_2 -> setEnabled(true);
    ui -> maleRadioButton_2 -> setEnabled(true);
    ui -> femaleRadioButton_2 -> setEnabled(true);

    updateTable();

    _file.close();
}

QString MainWindow::checkAndGetGender(QString line)
{
    QString gender = "", id = "", name = "", age = "", height = "", weight = "", habits = "", hobby = "", minAge = "", maxAge = "", minHeight = "", maxHeight = "", minWeight = "", maxWeight = "";
    int pos = 0;
    //qDebug() << line;
    while(line[pos] != '/' && pos < line.size())
    {
        gender += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        if(line[pos] < '0' || line[pos] > '9')
        {
            return "";
        }
        id += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        name += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        if(line[pos] < '0' || line[pos] > '9')
        {
            return "";
        }
        age += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        if(line[pos] < '0' || line[pos] > '9')
        {
            return "";
        }
        height += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        if(line[pos] < '0' || line[pos] > '9')
        {
            return "";
        }
        weight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        habits += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        hobby += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        if(line[pos] < '0' || line[pos] > '9')
        {
            return "";
        }
        minAge += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        if(line[pos] < '0' || line[pos] > '9')
        {
            return "";
        }
        maxAge += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        if(line[pos] < '0' || line[pos] > '9')
        {
            return "";
        }
        minHeight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        if(line[pos] < '0' || line[pos] > '9')
        {
            return "";
        }
        maxHeight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        if(line[pos] < '0' || line[pos] > '9')
        {
            return "";
        }
        minWeight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        if(line[pos] < '0' || line[pos] > '9')
        {
            return "";
        }
        maxWeight += line[pos];
        pos++;
    }
    pos++;

    if(gender != "f" && gender != "m")
        return "";

    if(gender == "" || id == "" || name == "" || age == "" || height == "" || weight == "" || habits == "" || hobby == "" || minAge == "" || maxAge == "" || minHeight == "" || maxHeight == "" || minWeight == "" || maxWeight == "")
    {
        return "";
    }

    return gender;
}

void MainWindow::addToVector(QString line)
{
    QString gender = "", id = "", name = "", age = "", height = "", weight = "", habits = "", hobby = "", minAge = "", maxAge = "", minHeight = "", maxHeight = "", minWeight = "", maxWeight = "";
    int pos = 0;
    while(line[pos] != '/' && pos < line.size())
    {
        gender += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        id += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        name += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        age += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        height += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        weight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        habits += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        hobby += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        minAge += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        maxAge += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        minHeight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        maxHeight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        minWeight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        maxWeight += line[pos];
        pos++;
    }

    if(gender == "m")
    {
        males.push_back(Human(id.toInt(), name, age.toInt(), height.toInt(), weight.toInt(), habits, hobby, minAge.toInt(), maxAge.toInt(), minHeight.toInt(), maxHeight.toInt(), minWeight.toInt(), maxWeight.toInt()));
    }
    else
    {
        females.push_back(Human(id.toInt(), name, age.toInt(), height.toInt(), weight.toInt(), habits, hobby, minAge.toInt(), maxAge.toInt(), minHeight.toInt(), maxHeight.toInt(), minWeight.toInt(), maxWeight.toInt()));
    }
}

void MainWindow::updateTable()
{
    ui -> tableWidget -> setRowCount(males.size());
    ui -> tableWidget_2 -> setRowCount(females.size());
    for (int i = 0; i < males.size(); ++i)
    {
        QTableWidgetItem* item0 = new QTableWidgetItem(QString::number(males[i].getId()));
        QTableWidgetItem* item1 = new QTableWidgetItem(males[i].getName());
        QTableWidgetItem* item2 = new QTableWidgetItem(QString::number(males[i].getAge()));
        QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(males[i].getHeight()));
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(males[i].getWeight()));
        QTableWidgetItem* item7 = new QTableWidgetItem(QString::number(males[i].getMinAge()));
        QTableWidgetItem* item6 = new QTableWidgetItem(males[i].getHobby());
        QTableWidgetItem* item5 = new QTableWidgetItem(males[i].getHabits());
        QTableWidgetItem* item8 = new QTableWidgetItem(QString::number(males[i].getMaxAge()));
        QTableWidgetItem* item9 = new QTableWidgetItem(QString::number(males[i].getMinHeight()));
        QTableWidgetItem* item10 = new QTableWidgetItem(QString::number(males[i].getMaxHeight()));
        QTableWidgetItem* item11 = new QTableWidgetItem(QString::number(males[i].getMinWeight()));
        QTableWidgetItem* item12 = new QTableWidgetItem(QString::number(males[i].getMaxWeight()));

        item0 -> setFont(systemFont);
        item1 -> setFont(systemFont);
        item2 -> setFont(systemFont);
        item3 -> setFont(systemFont);
        item4 -> setFont(systemFont);
        item6 -> setFont(systemFont);
        item7 -> setFont(systemFont);
        item8 -> setFont(systemFont);
        item9 -> setFont(systemFont);
        item10 -> setFont(systemFont);
        item11 -> setFont(systemFont);
        item12 -> setFont(systemFont);
        item5 -> setFont(systemFont);

        if(males[i]._isMatched)
        {
            item0 -> setFont(font);
            item1 -> setFont(font);
            item2 -> setFont(font);
            item3 -> setFont(font);
            item4 -> setFont(font);
            item6 -> setFont(font);
            item7 -> setFont(font);
            item8 -> setFont(font);
            item9 -> setFont(font);
            item10 -> setFont(font);
            item11 -> setFont(font);
            item12 -> setFont(font);
            item5 -> setFont(font);
        }

        ui -> tableWidget -> setItem(i, 0, item0);
        ui -> tableWidget -> setItem(i, 1, item1);
        ui -> tableWidget -> setItem(i, 2, item2);
        ui -> tableWidget -> setItem(i, 3, item3);
        ui -> tableWidget -> setItem(i, 4, item4);
        ui -> tableWidget -> setItem(i, 5, item5);
        ui -> tableWidget -> setItem(i, 6, item6);
        ui -> tableWidget -> setItem(i, 7, item7);
        ui -> tableWidget -> setItem(i, 8, item8);
        ui -> tableWidget -> setItem(i, 9, item9);
        ui -> tableWidget -> setItem(i, 10, item10);
        ui -> tableWidget -> setItem(i, 11, item11);
        ui -> tableWidget -> setItem(i, 12, item12);
    }

    for (int i = 0; i < females.size(); ++i)
    {
        QTableWidgetItem* item0 = new QTableWidgetItem(QString::number(females[i].getId()));
        QTableWidgetItem* item1 = new QTableWidgetItem(females[i].getName());
        QTableWidgetItem* item2 = new QTableWidgetItem(QString::number(females[i].getAge()));
        QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(females[i].getHeight()));
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(females[i].getWeight()));
        QTableWidgetItem* item7 = new QTableWidgetItem(QString::number(females[i].getMinAge()));
        QTableWidgetItem* item6 = new QTableWidgetItem(females[i].getHobby());
        QTableWidgetItem* item5 = new QTableWidgetItem(females[i].getHabits());
        QTableWidgetItem* item8 = new QTableWidgetItem(QString::number(females[i].getMaxAge()));
        QTableWidgetItem* item9 = new QTableWidgetItem(QString::number(females[i].getMinHeight()));
        QTableWidgetItem* item10 = new QTableWidgetItem(QString::number(females[i].getMaxHeight()));
        QTableWidgetItem* item11 = new QTableWidgetItem(QString::number(females[i].getMinWeight()));
        QTableWidgetItem* item12 = new QTableWidgetItem(QString::number(females[i].getMaxWeight()));

        item0 -> setFont(systemFont);
        item1 -> setFont(systemFont);
        item2 -> setFont(systemFont);
        item3 -> setFont(systemFont);
        item4 -> setFont(systemFont);
        item6 -> setFont(systemFont);
        item7 -> setFont(systemFont);
        item8 -> setFont(systemFont);
        item9 -> setFont(systemFont);
        item10 -> setFont(systemFont);
        item11 -> setFont(systemFont);
        item12 -> setFont(systemFont);
        item5 -> setFont(systemFont);

        if(females[i]._isMatched)
        {
            item0 -> setFont(font);
            item1 -> setFont(font);
            item2 -> setFont(font);
            item3 -> setFont(font);
            item4 -> setFont(font);
            item6 -> setFont(font);
            item7 -> setFont(font);
            item8 -> setFont(font);
            item9 -> setFont(font);
            item10 -> setFont(font);
            item11 -> setFont(font);
            item12 -> setFont(font);
            item5 -> setFont(font);
        }

        ui -> tableWidget_2 -> setItem(i, 0, item0);
        ui -> tableWidget_2 -> setItem(i, 1, item1);
        ui -> tableWidget_2 -> setItem(i, 2, item2);
        ui -> tableWidget_2 -> setItem(i, 3, item3);
        ui -> tableWidget_2 -> setItem(i, 4, item4);
        ui -> tableWidget_2 -> setItem(i, 5, item5);
        ui -> tableWidget_2 -> setItem(i, 6, item6);
        ui -> tableWidget_2 -> setItem(i, 7, item7);
        ui -> tableWidget_2 -> setItem(i, 8, item8);
        ui -> tableWidget_2 -> setItem(i, 9, item9);
        ui -> tableWidget_2 -> setItem(i, 10, item10);
        ui -> tableWidget_2 -> setItem(i, 11, item11);
        ui -> tableWidget_2 -> setItem(i, 12, item12);
    }
}

void MainWindow::updateTableMatches()
{
    tableMatches -> setRowCount(matches.size());
    for(int i = 0; i < matches.size(); ++i)
    {
        QTableWidgetItem* item0 = new QTableWidgetItem(QString::number(matches[i].getId()));
        QTableWidgetItem* item1 = new QTableWidgetItem(matches[i].getName());
        QTableWidgetItem* item2 = new QTableWidgetItem(QString::number(matches[i].getAge()));
        QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(matches[i].getHeight()));
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(matches[i].getWeight()));
        QTableWidgetItem* item5 = new QTableWidgetItem(matches[i].getHabits());
        QTableWidgetItem* item6 = new QTableWidgetItem(matches[i].getHobby());
        tableMatches -> setItem(i, 0, item0);
        tableMatches -> setItem(i, 1, item1);
        tableMatches -> setItem(i, 2, item2);
        tableMatches -> setItem(i, 3, item3);
        tableMatches -> setItem(i, 4, item4);
        tableMatches -> setItem(i, 5, item5);
        tableMatches -> setItem(i, 6, item6);
    }
}

QString MainWindow::checkAddAndGetQString()
{
    bool isMale = maleRadioBitton1 -> isChecked();
    QString s = "";
    if(isMale)
    {
        s += "m/";
    }
    else
    {
        s += "f/";
    }
    s += idLine1 -> text();
    s += "/";
    s += nameLine1 -> text();
    s += "/";
    s += ageLine1 -> text();
    s += "/";
    s += heightLine1 -> text();
    s += "/";
    s += weightLine1 -> text();
    s += "/";
    s += habitsLine1 -> text();
    s += "/";
    s += hobbyLine1 -> text();
    s += "/";
    s += minAgeLine1 -> text();
    s += "/";
    s += maxAgeLine1 -> text();
    s += "/";
    s += minHeightLine1 -> text();
    s += "/";
    s += maxHeightLine1 -> text();
    s += "/";
    s += minWeightLine1 -> text();
    s += "/";
    s += maxWeightLine1 -> text();
    s += "/";
    if(checkAndGetGender(s) != "")
    {
        return s;
    }
    else
    {
        return "";
    }
}

void MainWindow::on_addButton_clicked()
{
    if(_file.exists())
    {
        window1 -> show();
    }
}

void MainWindow::addHuman()
{
    QString s = checkAddAndGetQString();
    if(s == "")
    {
        QMessageBox::warning(this, "Warning", "Wrong data");
        this -> setEnabled(true);
        window1 -> close();
        return;
    }
    else
    {
        addToVector(s);
        if(_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream stream(&_file);
            stream << s << "\n";
            _file.close();
        }
        updateTable();
        this -> setEnabled(true);
        window1 -> close();
        ui -> tableWidget -> update();
        ui -> tableWidget_2 -> update();
    }
}

void MainWindow::on_editButton_clicked()
{
    _index = ui -> spinBox -> value();
    _isMale = ui -> maleRadioButton -> isChecked();
    if(_isMale)
    {
        _gender = 'm';
    }
    else
    {
        _gender = 'f';
    }

    if(_index < 1 || (_index > males.size() && _isMale) || (_index > females.size() && !_isMale))
    {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }

    _index--;

    if(_file.exists())
    {

        window2 -> show();
    }
}

void MainWindow::editHuman()
{
    QString s = checkAddAndGetQString2();
    if(s == "")
    {
        QMessageBox::warning(this, "Warning", "Wrong data");
        this -> setEnabled(true);
        window2 -> close();
        return;
    }
    else
    {
        editVector(s, _index);

        if(_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream stream(&_file);
            QString line;
            int currentLineNumber = 0;
            do
            {
                if(!line.isEmpty())
                {
                    stream >> line;
                    if(line[0] == _gender)
                    {
                        currentLineNumber++;
                    }
                    if(currentLineNumber == _index)
                    {
                        stream << s << "\n";
                    }
                }
            } while (!stream.atEnd());
            _file.close();
        }

        updateTable();
        this -> setEnabled(true);
        window2 -> close();
        ui -> tableWidget -> update();
        ui -> tableWidget_2 -> update();
    }
}

QString MainWindow::checkAddAndGetQString2()
{
    QString s = "";
    if(_isMale)
    {
        s += "m/";
    }
    else
    {
        s += "f/";
    }
    s += idLine2 -> text();
    s += "/";
    s += nameLine2 -> text();
    s += "/";
    s += ageLine2 -> text();
    s += "/";
    s += heightLine2 -> text();
    s += "/";
    s += weightLine2 -> text();
    s += "/";
    s += habitsLine2 -> text();
    s += "/";
    s += hobbyLine2 -> text();
    s += "/";
    s += minAgeLine2 -> text();
    s += "/";
    s += maxAgeLine2 -> text();
    s += "/";
    s += minHeightLine2 -> text();
    s += "/";
    s += maxHeightLine2 -> text();
    s += "/";
    s += minWeightLine2 -> text();
    s += "/";
    s += maxWeightLine2 -> text();
    s += "/";
    if(checkAndGetGender(s) != "")
    {
        return s;
    }
    else
    {
        return "";
    }
}

void MainWindow::editVector(QString line, int i)
{
    QString gender = "", id = "", name = "", age = "", height = "", weight = "", habits = "", hobby = "", minAge = "", maxAge = "", minHeight = "", maxHeight = "", minWeight = "", maxWeight = "";
    int pos = 0;
    while(line[pos] != '/' && pos < line.size())
    {
        gender += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        id += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        name += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        age += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        height += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        weight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        habits += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        hobby += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        minAge += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        maxAge += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        minHeight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        maxHeight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        minWeight += line[pos];
        pos++;
    }
    pos++;
    while(line[pos] != '/' && pos < line.size())
    {
        maxWeight += line[pos];
        pos++;
    }

    if(gender == "m")
    {
        males[i] = (Human(id.toInt(), name, age.toInt(), height.toInt(), weight.toInt(), habits, hobby, minAge.toInt(), maxAge.toInt(), minHeight.toInt(), maxHeight.toInt(), minWeight.toInt(), maxWeight.toInt()));
    }
    else
    {
        females[i] = (Human(id.toInt(), name, age.toInt(), height.toInt(), weight.toInt(), habits, hobby, minAge.toInt(), maxAge.toInt(), minHeight.toInt(), maxHeight.toInt(), minWeight.toInt(), maxWeight.toInt()));
    }
}

void MainWindow::on_sortButton_clicked()
{
    int index = ui -> comboBox -> currentIndex();
    switch(index)
    {
    case 0:
        for(int i = 1; i < males.size(); i++)
        {
            for(int j = i; j > 0 && males[j - 1]._id > males[j]._id; j--)
            {
                Human tmp = males[j - 1];
                males[j - 1] = males[j];
                males[j] = tmp;
            }
        }
        for(int i = 1; i < females.size(); i++)
        {
            for(int j = i; j > 0 && females[j - 1]._id > females[j]._id; j--)
            {
                Human tmp = females[j - 1];
                females[j - 1] = females[j];
                females[j] = tmp;
            }
        }
        updateTable();
        ui -> tableWidget -> update();
        ui -> tableWidget_2 -> update();
        break;

    case 1:
        for(int i = 1; i < males.size(); i++)
        {
            for(int j = i; j > 0 && males[j - 1]._age > males[j]._age; j--)
            {
                Human tmp = males[j - 1];
                males[j - 1] = males[j];
                males[j] = tmp;
            }
        }
        for(int i = 1; i < females.size(); i++)
        {
            for(int j = i; j > 0 && females[j - 1]._age > females[j]._age; j--)
            {
                Human tmp = females[j - 1];
                females[j - 1] = females[j];
                females[j] = tmp;
            }
        }
        updateTable();
        ui -> tableWidget -> update();
        ui -> tableWidget_2 -> update();
        break;

    case 2:
        for(int i = 1; i < males.size(); i++)
        {
            for(int j = i; j > 0 && males[j - 1]._height > males[j]._height; j--)
            {
                Human tmp = males[j - 1];
                males[j - 1] = males[j];
                males[j] = tmp;
            }
        }
        for(int i = 1; i < females.size(); i++)
        {
            for(int j = i; j > 0 && females[j - 1]._height > females[j]._height; j--)
            {
                Human tmp = females[j - 1];
                females[j - 1] = females[j];
                females[j] = tmp;
            }
        }
        updateTable();
        ui -> tableWidget -> update();
        ui -> tableWidget_2 -> update();
        break;

    case 3:
        for(int i = 1; i < males.size(); i++)
        {
            for(int j = i; j > 0 && males[j - 1]._weight > males[j]._weight; j--)
            {
                Human tmp = males[j - 1];
                males[j - 1] = males[j];
                males[j] = tmp;
            }
        }
        for(int i = 1; i < females.size(); i++)
        {
            for(int j = i; j > 0 && females[j - 1]._weight > females[j]._weight; j--)
            {
                Human tmp = females[j - 1];
                females[j - 1] = females[j];
                females[j] = tmp;
            }
        }
        updateTable();
        ui -> tableWidget -> update();
        ui -> tableWidget_2 -> update();
        break;
    }
}

void MainWindow::on_findButton_clicked()
{
    _index = ui -> spinBox_2 -> value();
    _isMale = ui -> maleRadioButton_2 -> isChecked();
    if(_isMale)
    {
        _gender = 'm';
    }
    else
    {
        _gender = 'f';
    }

    if(_index < 1 || (_index > males.size() && _isMale) || (_index > females.size() && !_isMale) || (males[_index-1]._isMatched  && _isMale) || (females[_index-1]._isMatched  && !_isMale))
    {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }

    _index--;
    matches.clear();
    candidatsNumber.clear();

    if(_isMale)
    {
        for(int i = 0; i < females.size(); ++i)
        {
            if(females[i]._height >= males[_index]._minHeight && females[i]._height <= males[_index]._maxHeight &&
                females[i]._weight >= males[_index]._minWeight && females[i]._weight <= males[_index]._maxWeight &&
                females[i]._age >= males[_index]._minAge && females[i]._age <= males[_index]._maxAge && !females[i]._isMatched)
            {
                matches.push_back(females[i]);
                candidatsNumber.push_back(i);
            }
        }
    }
    else
    {
        for(int i = 0; i < males.size(); ++i)
        {
            if(males[i]._height >= females[_index]._minHeight && males[i]._height <= females[_index]._maxHeight &&
                males[i]._weight >= females[_index]._minWeight && males[i]._weight <= females[_index]._maxWeight &&
                males[i]._age >= females[_index]._minAge && males[i]._age <= females[_index]._maxAge && !males[i]._isMatched)
            {
                matches.push_back(males[i]);
                candidatsNumber.push_back(i);
            }
        }
    }

    updateTableMatches();

    windowMatches -> show();
}

void MainWindow::match()
{
    int index = spinBoxMatches -> value();
    if(index < 1 || index > matches.size())
    {
        QMessageBox::warning(this, "Warning", "Wrong data");
        windowMatches -> close();
        return;
    }
    index--;
    if(_isMale)
    {
        males[_index]._isMatched = true;
        females[candidatsNumber[index]]._isMatched = true;
    }
    else
    {
        females[_index]._isMatched = true;
        males[candidatsNumber[index]]._isMatched = true;
    }
    windowMatches -> close();
    updateTable();
}

