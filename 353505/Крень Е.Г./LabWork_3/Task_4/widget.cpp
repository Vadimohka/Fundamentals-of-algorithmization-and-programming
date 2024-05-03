#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , timer()
    , movingRing(1, 0)
{
    ui->setupUi(this);
    ui->spinBox->setRange(1, 10);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList{"Номер кольца", "С какого столбца", "На какой столбец"});
    roads.push_back(QVector<Ring>());
    roads.push_back(QVector<Ring>());
    roads.push_back(QVector<Ring>());
    roads[0].push_back(Ring(1, 1));
    QWidget::update();


    connect(ui->spinBox, &QSpinBox::valueChanged, this,[this](){
        refresh();
        ui->tableWidget->setHorizontalHeaderLabels(QStringList{"Номер кольца", "С какого столбца", "На какой столбец"});
        roads.push_back(QVector<Ring>());
        roads.push_back(QVector<Ring>());
        roads.push_back(QVector<Ring>());
        for(int i = 1; i<=ui->spinBox->value(); ++i){
            roads[0].push_back(Ring(i, 1));
        }
        QWidget::update();
    });

    connect(ui->refreshButton, &QPushButton::clicked, this, [this](){
        ui->performButton->setDisabled(0);
        ui->spinBox->setDisabled(0);
        refresh();
        ui->spinBox->setValue(1);
        ui->tableWidget->clear();
        ui->tableWidget->setHorizontalHeaderLabels(QStringList{"Номер кольца", "С какого столбца", "На какой столбец"});
        roads.push_back(QVector<Ring>());
        roads.push_back(QVector<Ring>());
        roads.push_back(QVector<Ring>());
        roads[0].push_back(Ring(1, 1));
        QWidget::update();
    });

    connect(ui->performButton, &QPushButton::clicked, this, [this](){
        ui->performButton->setDisabled(1);
        ui->spinBox->setDisabled(1);
        currentPosInTable=0;
        ringsInRoads[0] = ui->spinBox->value();
        ui->tableWidget->setRowCount(pow(2, ui->spinBox->value())-1);
        moveTower(ui->spinBox->value(), '1', '3', '2');

        phase=0;
        currentPosInTable = 0;
        sourseRoad = ui->tableWidget->item(0, 1)->text().toInt()-1;
        movingRing = roads[sourseRoad].last();
        destinationRoad = ui->tableWidget->item(0, 2)->text().toInt()-1;
        roads[sourseRoad].pop_back();
        timer.start(10);
    });

    connect(&timer, &QTimer::timeout, this, [this](){
        switch (phase) {
        case 0:
            if(movingRing.Y()!=300){
                movingRing.y_pos_incr(-10);
            }
            else{
                ringsInRoads[sourseRoad]--;
                phase++;
            }
            break;
        case 1:
            if(movingRing.X()!= 215 + (destinationRoad)*400 - movingRing.Width()/2){
                movingRing.x_pos_incr(sourseRoad<destinationRoad ? 10 : -10);
            }
            else{
                phase++;
            }
            break;
        case 2:
            if(movingRing.Y()<670 - (ringsInRoads[destinationRoad])*30){
                movingRing.y_pos_incr(10);
            }
            else{
                phase ++;
                currentPosInTable++;
                roads[destinationRoad].push_back(movingRing);
                ringsInRoads[destinationRoad]++;
            }
            break;
        default:
            phase=0;
            if(currentPosInTable<ui->tableWidget->rowCount()){
                sourseRoad = ui->tableWidget->item(currentPosInTable, 1)->text().toInt()-1;
                movingRing = roads[sourseRoad].last();
                destinationRoad = ui->tableWidget->item(currentPosInTable, 2)->text().toInt()-1;
                roads[sourseRoad].pop_back();
            }
            else{
                timer.stop();
                return;
            }
            break;
        }
        QWidget::update();
        timer.start(10);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::moveTower(int n, char source, char destination, char auxiliary) {
    if (n == 1) {

        ui->tableWidget->setItem(currentPosInTable, 0, new QTableWidgetItem(QString::number(n)));
        ui->tableWidget->setItem(currentPosInTable, 1, new QTableWidgetItem(QString(source)));
        ui->tableWidget->setItem(currentPosInTable, 2, new QTableWidgetItem(QString(destination)));
        currentPosInTable++;
        return;
    }


    moveTower(n - 1, source, auxiliary, destination);

    ui->tableWidget->setItem(currentPosInTable, 0, new QTableWidgetItem(QString::number(n)));
    ui->tableWidget->setItem(currentPosInTable, 1, new QTableWidgetItem(QString(source)));
    ui->tableWidget->setItem(currentPosInTable, 2, new QTableWidgetItem(QString(destination)));

    currentPosInTable++;

    moveTower(n - 1, auxiliary, destination, source);
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(100,700, 1100, 20);
    painter.setBrush(QBrush(Qt::darkGray));
    painter.drawRect(200,370, 30, 330);
    painter.drawRect(1000,370, 30, 330);
    painter.setBrush(QBrush(Qt::gray));
    painter.drawRect(600,370, 30, 330);
    painter.setBrush(QBrush(movingRing.getColor()));
    painter.drawRect(movingRing.get_rect());

    for(int i = 0; i<roads.size(); ++i){
        for(int j = 0; j<roads[i].size(); ++j){

            painter.setBrush(QBrush(roads[i][j].getColor()));
            painter.drawRect(roads[i][j].get_rect());
        }
    }
}

void Widget::refresh(){
    currentPosInTable = 0;
    sourseRoad = 0;
    destinationRoad = 0;
    ringsInRoads[0] = 0;
    ringsInRoads[1] = 0;
    ringsInRoads[2] = 0;
    roads.clear();
    movingRing = Ring(1,0);
    timer.stop();
    QWidget::update();
}
