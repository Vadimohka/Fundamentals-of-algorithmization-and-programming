#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(975, 550);
    setFixedSize(975, 550);
    ui->tableWidget->setWindowTitle("Table Widget");
    fillTableWidget(ui->tableWidget);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    scene->setSceneRect(-200, -200, 600, 400);
    ui->graphicsView->setScene(scene);
    scene->addRect(-125, -100, 16, 300);
    scene->addRect(75, -100, 16, 300);
    scene->addRect(275, -100, 16, 300);
    //QMessageBox::warning(this, tr("Title"), tr("Hello, World!"));
    timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=](){
        update();
        if (wasAnimation) {
            ui->pushButton->setEnabled(false);
            ui->spinBox->setEnabled(false);
            ui->pushButton->setStyleSheet("background-color: gray;");
        }
        else {
            ui->pushButton->setEnabled(true);
            ui->spinBox->setEnabled(true);
            ui->pushButton->setStyleSheet("background-color: white;");
            ui->tableWidget->setRangeSelected(QTableWidgetSelectionRange(ui->tableWidget->rowCount() - 1, 0, ui->tableWidget->rowCount() - 1, 1), false);
        }
    });
    timer->start(25);
    diskSetup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillTableWidget(QTableWidget *tableWidget)
{
    tableWidget->clear();
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(2);
    QStringList headers;
    headers << "Откуда" << "Куда";
    tableWidget->setHorizontalHeaderLabels(headers);
}

void MainWindow::moveDisk(const QString &sourceTowerName, const QString &destTowerName)
{
    QList<Disk*>* sourceTower;
    QPointF sourcePos;
    QPointF destPos;
    if (sourceTowerName == "I") {
        sourceTower = &tower1;
        sourcePos = QPointF(-125, -200);
    }
    else if (sourceTowerName == "II") {
        sourceTower = &tower2;
        sourcePos = QPointF(75, -200);
    }
    else {
        sourceTower = &tower3;
        sourcePos = QPointF(275, -200);
    }
    Disk* topDisk = sourceTower->back();
    QPointF startPos = topDisk->pos();

    if (destTowerName == "I")
        destPos = QPointF(-125, 200 - (tower1.size() + 1) * 20);
    else if (destTowerName == "II")
        destPos = QPointF(75, 200 - (tower2.size() + 1) * 20);
    else if (destTowerName == "III")
        destPos = QPointF(275, 200 - (tower3.size() + 1) * 20);

    QTimeLine *timeLine = new QTimeLine(1250);
    timeLine->setFrameRange(0, 100);
    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    animation->setTimeLine(timeLine);
    animation->setItem(topDisk);

    animation->setPosAt(0, startPos);
    animation->setPosAt(0.3333, QPointF(startPos.x(), sourcePos.y()));
    animation->setPosAt(0.6666, QPointF(startPos.x() + destPos.x() - sourcePos.x(), sourcePos.y()));
    animation->setPosAt(1, QPointF(startPos.x() + destPos.x() - sourcePos.x(), destPos.y()));

    QObject::connect(timeLine, &QTimeLine::finished, [=]() {
        sourceTower->removeLast();
        if (destTowerName == "I")
            tower1.push_back(topDisk);
        else if (destTowerName == "II")
            tower2.push_back(topDisk);
        else if (destTowerName == "III")
            tower3.push_back(topDisk);
    });

    timeLine->start();
}

void MainWindow::diskSetup()
{
    ui->tableWidget->setRowCount(0);
    hanoiSolver.solve(cnt_of_ring, "I", "II", "III", ui->tableWidget);
    for (Disk* disk : tower1) {
        scene->removeItem(disk);
        delete disk;
    }
    tower1.clear();
    for (Disk* disk : tower2) {
        scene->removeItem(disk);
        delete disk;
    }
    tower2.clear();
    for (Disk* disk : tower3) {
        scene->removeItem(disk);
        delete disk;
    }
    tower3.clear();

    int diskHeight = 20;
    int diskStartWidth = 200;
    int x = -212;
    int y = 200;
    for (int i = cnt_of_ring; i > 0; --i) {
        int width = diskStartWidth - (cnt_of_ring - i) * 15;
        Disk *disk = new Disk(width, diskHeight, i);
        disk->setPos(x, y - diskHeight);
        scene->addItem(disk);
        tower1.push_back(disk);
        y -= diskHeight;
        x += 7;
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    cnt_of_ring = ui->spinBox->value();
    diskSetup();
}

void MainWindow::on_pushButton_clicked()
{
    diskSetup();
    int rowCount = ui->tableWidget->rowCount();
    int delay = 0;
    for (int row = 0; row < rowCount; ++row) {
        QTableWidgetItem *item1 = ui->tableWidget->item(row, 0);
        QTableWidgetItem *item2 = ui->tableWidget->item(row, 1);
        QString str1 = item1->text();
        QString str2 = item2->text();
        QTimer *new_timer = new QTimer(this);
        QObject::connect(new_timer, &QTimer::timeout, [=]() {
            if (row != 0) ui->tableWidget->setRangeSelected(QTableWidgetSelectionRange(row - 1, 0, row - 1, 1), false);
            ui->tableWidget->setRangeSelected(QTableWidgetSelectionRange(row, 0, row, 1), true);
            moveDisk(str1, str2);
            wasAnimation = true;
            new_timer->deleteLater();
        });
        new_timer->start(delay);
        delay += 2200;
    }
    delay -= 750;
    QTimer *new_timer = new QTimer(this);
    QObject::connect(new_timer, &QTimer::timeout, [=]() {
        wasAnimation = false;
        new_timer->deleteLater();
    });
    new_timer->start(delay);
}
