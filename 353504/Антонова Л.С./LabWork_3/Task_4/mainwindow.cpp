#include "mainwindow.h"
#include "ui_mainwindow.h"

QQueue<QTimeLine*> queue;
int moves = 0;
int n = 7;

void MainWindow::Hanoi(int start, int end, int n) {
    if (n == 0) {
        return;
    }
    int other = 3 - start - end;
    Hanoi(start, other, n - 1);

    QGraphicsRectItem *disk;
    disk = dynamic_cast<QGraphicsRectItem*>(rods[start]->childItems().last());

    Move(disk, rods[start], rods[end]);

    rods[start]->childItems().removeLast();
    disk->setParentItem(rods[end]);

    qDebug() << "Move disk " << n << " from rod " << start << " to rod " << end;
    moves++;

    Hanoi(other, end, n - 1);
}

void MainWindow::Move(QGraphicsRectItem *disk, QGraphicsRectItem *fromRod, QGraphicsRectItem *toRod)
{
    QTimeLine *timeLine = new QTimeLine(1000);
    timeLine->setFrameRange(0, 100);
    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;

    animation->setTimeLine(timeLine);
    animation->setItem(disk);

    animation->setPosAt(0, QPointF(fromRod->pos().x(), disk->pos().y()));
    animation->setPosAt(0.33, QPointF(fromRod->pos().x(), -40));
    animation->setPosAt(0.66, QPointF(toRod->pos().x(), -40));
    int height = (toRod->childItems().count()) * 10 - 390;
    int width = (toRod->childItems().count()) * 5;
    animation->setPosAt(1, QPointF(toRod->pos().x() + width  - (n < 9 ? 45 : 170), toRod->pos().y() - height));

    queue.enqueue(timeLine);
    if (queue.count() == 1) {
        connect(queue.head(), &QTimeLine::finished, this, &MainWindow::nextAnimation);
        queue.head()->start();
    }
}

void MainWindow::nextAnimation() {
    queue.dequeue();
    if (!queue.isEmpty()) {
        connect(queue.head(), &QTimeLine::finished, this, &MainWindow::nextAnimation);
        queue.head()->start();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QDialog dialog(this);
    QFormLayout form(&dialog);

    // Добавление полей для ввода
    QLineEdit *nInput = new QLineEdit(&dialog);
    form.addRow("n", nInput);

    // Добавление кнопок Ок и Отмена
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Отображение диалогового окна
    if (dialog.exec() == QDialog::Accepted) {
        n = nInput->text().toInt();
    }

    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);

    QGraphicsRectItem *rod0 = new QGraphicsRectItem(0, 0, 10, 400);
    rod0->setPos(-350, 0);
    rods.append(rod0);
    QGraphicsRectItem *rod1 = new QGraphicsRectItem(0, 0, 10, 400);
    rod1->setPos(0, 0);
    rods.append(rod1);
    QGraphicsRectItem *rod2 = new QGraphicsRectItem(0, 0, 10, 400);
    rod2->setPos(350, 0);
    rods.append(rod2);

    for (QGraphicsRectItem *rod : rods) {
        rod->setBrush(QBrush(Qt::black));
        scene->addItem(rod);
    }

    for (int i = 0; i < n; ++i) {
        QGraphicsRectItem *disk;
        if(n < 9){
           disk = new QGraphicsRectItem(-350, 0, 100 - i * 10, 10);
           disk->setPos(-45 + 350 + i * 5, 390 - i * 10);
           disk->setBrush(QColor::fromHsv((i * 255) / 5, 255, 255));
        } else{
            disk = new QGraphicsRectItem(-350, 0, 350 - i * 10, 10);
            disk->setPos(-170 + 350 + i * 5, 390 - i * 10);
            disk->setBrush(QBrush(Qt::blue));
        }

        disk->setParentItem(rods[0]);
        scene->addItem(disk);
    }

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Hanoi(0, 2, n);
    ui->label->setText("Moves: " + QString::number(moves));
    moves = 0;
}
