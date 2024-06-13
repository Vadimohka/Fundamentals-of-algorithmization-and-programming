#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->spinBox_2->setVisible(0);
    ui->spinBox->setRange(0, 1000);
    ui->spinBox_2->setRange(0, 1000);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        ui->label_3->setText("");
        switch (ui->comboBox->currentIndex()) {
        case 0:
            data.push_back(ui->spinBox->value());
            break;
        case 1:
            if(data.size()<=ui->spinBox->value()) ui->label_3->setText("Ошибка индексации");
            else ui->label_3->setNum(data.at(ui->spinBox->value()));
            break;
        case 2:
        {
            QString ptrStr = QString("0x%1").arg(reinterpret_cast<quintptr>(data.data()), QT_POINTER_SIZE * 2, 16, QChar('0'));
            ui->label_3->setText(ptrStr);
            break;
        }
        case 3:
            data.clear();
            break;
        case 4:
            if(data.size()>0) data.pop_back();
            break;
        case 5:
            if(data.size()>=ui->spinBox->value()) ui->label_3->setText("Ошибка");
            else data.erase(data.begin() + ui->spinBox->value());
            break;
        case 6:
            if(ui->spinBox_2->value()>data.size()) ui->label_3->setText("Ошибка индексации");
            else data.insert(data.cbegin() + ui->spinBox_2->value(), ui->spinBox->value());
            break;
        case 7:
            ui->label_3->setNum(static_cast<int>(data.capacity()));
            break;
        case 8:
            ui->label_3->setNum(static_cast<int>(data.size()));
            break;
        case 9:
            data.resize(ui->spinBox->value());
            break;
        case 10:
            ui->label_3->setText(data.empty() ? "Empty" : "no Empty");
            break;
        default:
            break;
        }

        refreshTable();
    });

    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, [this](){
        ui->label_3->setText("");
        switch (ui->comboBox->currentIndex()) {
        case 0:
            ui->label->setText("Значение");
            ui->spinBox->setVisible(1);
            ui->label_2->setText("");
            ui->spinBox_2->setVisible(0);
            break;
        case 1:
            ui->label->setText("Индекс");
            ui->spinBox->setVisible(1);
            ui->label_2->setText("");
            ui->spinBox_2->setVisible(0);
            break;
        case 2:
            ui->label->setText("");
            ui->spinBox->setVisible(0);
            ui->label_2->setText("");
            ui->spinBox_2->setVisible(0);
            break;
        case 3:
            ui->label->setText("");
            ui->spinBox->setVisible(0);
            ui->label_2->setText("");
            ui->spinBox_2->setVisible(0);
            break;
        case 4:
            ui->label->setText("");
            ui->spinBox->setVisible(0);
            ui->label_2->setText("");
            ui->spinBox_2->setVisible(0);
            break;
        case 5:
            ui->label->setText("Индекс");
            ui->spinBox->setVisible(1);
            ui->label_2->setText("");
            ui->spinBox_2->setVisible(0);
            break;
        case 6:
            ui->label->setText("Значение");
            ui->spinBox->setVisible(1);
            ui->label_2->setText("Индекс");
            ui->spinBox_2->setVisible(1);
            break;
        case 7:
            ui->label->setText("");
            ui->spinBox->setVisible(0);
            ui->label_2->setText("");
            ui->spinBox_2->setVisible(0);
            break;
        case 8:
            ui->label->setText("");
            ui->spinBox->setVisible(0);
            ui->label_2->setText("");
            ui->spinBox_2->setVisible(0);
            break;
        case 9:
            ui->label->setText("Размер");
            ui->spinBox->setVisible(1);
            ui->label_2->setText("");
            ui->spinBox_2->setVisible(0);
            break;
        case 10:
            ui->label->setText("");
            ui->spinBox->setVisible(0);
            ui->label_2->setText("");
            ui->spinBox_2->setVisible(0);
            break;
        default:
            break;
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::refreshTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(name);
    ui->tableWidget->setRowCount(data.size());
    for(int i = 0; i<data.size(); ++i)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(data[i])));
    }
}

