#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);

    QStringList horizontalHeaderLabels;
    horizontalHeaderLabels << "Date" << "Next Day" << "Difference" << "Days Until Birthday";
    model->setHorizontalHeaderLabels(horizontalHeaderLabels);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 779 / 4);
    ui->tableView->setColumnWidth(1, 779 / 4);
    ui->tableView->setColumnWidth(2, 779 / 4);
    ui->tableView->setColumnWidth(3, 779 / 4);

    QPushButton *openFile = new QPushButton("open file", this);
    QLabel *date = new QLabel(QDate::currentDate().toString("dd.MM.yyyy"));
    drLab = new QLabel("Birth day", this);
    dateAdd = new QLineEdit(this);
    QPushButton *dateAddButton = new QPushButton("add", this);
    dr = new QCheckBox(this);

    connect(openFile, SIGNAL(clicked()), this, SLOT(opener()));
    connect(dateAddButton, SIGNAL(clicked()), this, SLOT(addDates()));
    connect(dr, &QCheckBox::stateChanged, this, &MainWindow::checkboxStateChanged);

    ui->gridLayout->addWidget(openFile, 0, 0);
    ui->gridLayout->addWidget(ui->tableView, 1, 0, 2, 0);
    ui->gridLayout->addWidget(date, 2, 0);
    ui->gridLayout->addWidget(dateAdd, 2, 1);
    ui->gridLayout->addWidget(dateAddButton, 2, 2, 1, 2);
    ui->gridLayout->addWidget(dr, 3, 3);
    ui->gridLayout->addWidget(drLab, 3, 2, Qt::AlignRight);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::opener() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Text File"), QDir::homePath(), tr("Text Files (*.txt)"));

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "+";
            QTextStream in(&file);
            QStringList rowData;
            while (!in.atEnd()) {
                QString line = in.readLine();
                rowData = line.split("\n");
                QList<QStandardItem *> items;
                for (const QString &data : rowData) {
                    items.append(new QStandardItem(data));
                    numDates++;
                }
                model->appendRow(items);
            }
            nextDates();
            difference();
            file.close();
        } else {
            qDebug() << "-";
        }
    }
}

void MainWindow::nextDates() {
    for (int row = 0; row < model->rowCount(); ++row) {
        QStandardItem *dateItem = model->item(row, 0);
        QString dateString = dateItem->text();
        QDate currentDate = QDate::fromString(dateString, "dd.MM.yyyy");
        QDate nextDay = Date::nextDay(currentDate);
        QStandardItem *nextDayItem = new QStandardItem(nextDay.toString("dd.MM.yyyy"));
        model->setItem(row, 1, nextDayItem);
    }
}

void MainWindow::difference() {
    for (int row = 0; row < model->rowCount() - 1; ++row) {
        QStandardItem *dateItem = model->item(row, 0);
        QStandardItem *nextdateItem = model->item(row + 1, 0);
        QString dateString = dateItem->text();
        QString nextdateString = nextdateItem->text();
        QDate currentDate = QDate::fromString(dateString, "dd.MM.yyyy");
        QDate nextDate = QDate::fromString(nextdateString, "dd.MM.yyyy");

        int differenceInDays = currentDate.daysTo(nextDate);
        QStandardItem *diffItem = new QStandardItem(QString::number(differenceInDays));
        model->setItem(row, 2, diffItem);
    }
}

void MainWindow::addDates() {
    if (drBool == 0)
    {
        QDate date = QDate::fromString(dateAdd->text(), "dd.MM.yyyy");
        if (date.isValid())
        {
            QStandardItem *item = new QStandardItem(date.toString("dd.MM.yyyy"));
            model->setItem(numDates, 0, item);
            numDates++;
            nextDates();
            difference();
        } else
        {
            qDebug() << "Invalid date";
        }
    }
    else
    {
        QDate birthday = QDate::fromString(dateAdd->text(), "dd.MM.yyyy");
        if (birthday.isValid())
        {
            for (int row = 0; row < model->rowCount(); ++row)
            {
                QStandardItem *dateItem = model->item(row, 0);
                QString dateString = dateItem->text();
                QDate currentDate = QDate::fromString(dateString, "dd.MM.yyyy");
                if (currentDate.isValid())
                {
                    int daysUntilBirthday = Date::calculateBirth(currentDate, birthday);
                    model->setItem(row, 3, new QStandardItem(QString::number(daysUntilBirthday)));
                }
            }
        }
        else
        {
            qDebug() << "Invalid date";
        }
    }
}


void MainWindow::checkboxStateChanged(int state)
{
    if (state == Qt::Checked)
    {
        drBool = 1;
    } else {
        drBool = 0;
    }
}



