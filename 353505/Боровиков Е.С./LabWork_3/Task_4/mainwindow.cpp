#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    upd = new bool;
    *upd = false;
    mainUpd= new bool;
    *mainUpd = false;
    nextpushButton->setParent(this);
    nextpushButton->setText("Выполнить");
    nextpushButton->setGeometry(400, 960, 200, 30);

    spinBox->setParent(this);
    spinBox->setGeometry(0, 960, 200, 30);
    spinBox->setRange(1, 10);

    table->setParent(this);


    QPushButton::connect(nextpushButton, SIGNAL(pressed()), SLOT(on_NextpushButton_clicked()));

    timer = new QTimer;
    connect(timer, &QTimer::timeout, [&](){
        if (size != spinBox->value()){
            size = spinBox->value();
            renul();

        }
        nextpushButton->setEnabled(!*mainUpd && !*upd);
        nextpushButton->setPalette(QPalette((!*mainUpd && !*upd)? Qt::white : Qt::gray));

        spinBox->setEnabled(!*mainUpd && !*upd);
        spinBox->setPalette(QPalette((!*mainUpd && !*upd)? Qt::white : Qt::gray));
        repaint();
    });
    timer->start(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hanoi(int n, int firstPost, int secondPost, QVector <QVector <int>>& vec)
{
    int c;
    if ((firstPost == 1 && secondPost == 2) || (firstPost == 2 && secondPost == 1)) c = 3;
    else if ((firstPost == 2 && secondPost == 3) || (firstPost == 3 && secondPost == 2)) c = 1;
    else c = 2;

    if (n > 1){
        hanoi(n - 1, firstPost, c, vec);
        vec.append(QVector<int>{n, firstPost, secondPost});
        hanoi(n - 1, c, secondPost,  vec);

    }
    else vec.append(QVector<int>{n, firstPost, secondPost});


}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.drawRect(200, 900, 30, -400);
    paint.drawRect(500, 900, 30, -400);
    paint.drawRect(800, 900, 30, -400);

    for (int i = 0; i < circleFigure.size(); ++i){
        paint.setBrush(QBrush(QColor(colorVec[i])));

        paint.drawRect(*circleFigure[i]);
    }

}

void MainWindow::moveUp(int index)
{
    QTimer* tm = new QTimer;
    *upd = true;

    int speedX = 0;
    int speedY = -50;

    int numbOfColonmn;

    int endX;
    if (vec[index][2] == 3) {
        endX = 800 + 15 - circleFigure[circleFigure.size() - vec[index][0]]->width() / 2;
        numbOfColonmn = numberOnThirdColumn;
        numberOnThirdColumn++;
    }
    else if (vec[index][2] == 2){
        numbOfColonmn = numberOnSecondColumn;
        numberOnSecondColumn++;
        endX = 500 + 15  - circleFigure[circleFigure.size() - vec[index][0]]->width() / 2;
    }
    else {
        numbOfColonmn = numberOnFirstColumn;
        numberOnFirstColumn++;
        endX = 200 + 15 - circleFigure[circleFigure.size() - vec[index][0]]->width() / 2;
    }

    if (vec[index][1] == 3) {
        numberOnThirdColumn--;
    }
    else if (vec[index][1] == 2){
        numberOnSecondColumn--;
    }
    else {
        numberOnFirstColumn--;
    }


    connect(tm, &QTimer::timeout, [=](){
        int speedX1 = speedX;
        int speedY1 = speedY;

        if (circleFigure[circleFigure.size() - vec[index][0]]->y() <= 400 ){
            if (vec[index][1] < vec[index][2]) speedX1 = 50;
            else speedX1 = -50;
            speedY1 = 0;
        }

        if (abs(circleFigure[circleFigure.size() - vec[index][0]]->x() - endX) <= 20){
            speedX1 = 0;
            circleFigure[circleFigure.size() - vec[index][0]]->setX(endX);
            speedY1 = 20;
        }

        if (circleFigure[circleFigure.size() - vec[index][0]]->y() < 870 - numbOfColonmn * 30 || abs(circleFigure[circleFigure.size() - vec[index][0]]->x() - endX) > 10){
            circleFigure[circleFigure.size() - vec[index][0]]->moveTo(circleFigure[circleFigure.size() - vec[index][0]]->x() + speedX1, circleFigure[circleFigure.size() - vec[index][0]]->y() + speedY1);
        }
        else{
            tm->stop();
            circleFigure[circleFigure.size() - vec[index][0]]->setRect(endX, 870 - numbOfColonmn * 30, circleFigure[circleFigure.size() - vec[index][0]]->width(), 30);
            *upd = false;
        }
    });
    tm->start(30);

}

void MainWindow::renul()
{
    vec.clear();
    hanoi(spinBox->value(), 1, 3, vec);
    table->clear();
    table->setColumnCount(3);
    table->setRowCount(vec.size());
    table->setHorizontalHeaderLabels(QStringList{"Номер кольца", "С какого столбца", "На какой столбец"});
    table->setGeometry(1000, 0, 500, 1000);
    table->setColumnWidth(0, 150);
    table->setColumnWidth(1, 150);
    table->setColumnWidth(2, 150);

    index = 0;

    circleFigure.clear();
    colorVec.clear();
    numberOnFirstColumn = spinBox->value();
    numberOnSecondColumn = 0;
    numberOnThirdColumn = 0;

    for (int i = 0; i < spinBox->value(); ++i){
        QRectF* rect = new QRectF(75 + 10 * i, 870 - 30 * i, 280 - 20 * i, 30);
        circleFigure.append(rect);

    }
    for (int i = 0; i < circleFigure.size(); ++i){
        colorVec.append(QColor(rand() % 44,rand() % 255,rand() % 55));
    }

    for (int i = 0; i < vec.size(); ++i){
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString::number(vec[i][0]));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        table->setItem(i, 0, item);

        item = new QTableWidgetItem;
        item->setText(QString::number(vec[i][1]));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        table->setItem(i, 1, item);

        item = new QTableWidgetItem;
        item->setText(QString::number(vec[i][2]));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        table->setItem(i, 2, item);
    }

}


void MainWindow::on_NextpushButton_clicked()
{
    renul();
    QTimer* mainTaimer = new QTimer;
    connect(mainTaimer, &QTimer::timeout, [=](){
        *mainUpd = true;

        if (!*upd){
            moveUp(index);
            for (int i = 0; i < table->rowCount(); ++i){
                if (index == i){
                    qDebug() << i << index;
                    table->item(i, 0)->setBackground(Qt::red);
                    table->item(i, 1)->setBackground(Qt::red);
                    table->item(i, 2)->setBackground(Qt::red);
                }
                else{
                    table->item(i, 0)->setBackground(Qt::green);
                    table->item(i, 1)->setBackground(Qt::white);
                    table->item(i, 2)->setBackground(Qt::green);
                }
            }
            if (index < vec.size() - 1) index++;
            else {
                mainTaimer->stop();
                *mainUpd = false;

            }

        }


    });
    mainTaimer->start(30);
}
