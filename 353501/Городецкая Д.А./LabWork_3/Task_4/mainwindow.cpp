#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создание чекбоксов и настройка
    updCheckBox = new QCheckBox(this);
    updCheckBox->setChecked(false);
    mainUpdCheckBox = new QCheckBox(this);
    mainUpdCheckBox->setChecked(false);

    // Создание кнопки, установка родительского виджета и текста
    nextPushButton = new QPushButton("Click Me", ui->centralwidget);
    nextPushButton->setGeometry(550, 160, 200, 30);

    // Создание спинбокса, установка родительского виджета и диапазона значений
    spinBox = new QSpinBox(ui->centralwidget);
    spinBox->setGeometry(250, 160, 200, 30);
    spinBox->setRange(1, 10);

    // Создание таблицы и установка родительского виджета
    tableWidget = new QTableWidget(ui->centralwidget);

    // Подключение сигнала кнопки к слоту
    connect(nextPushButton, SIGNAL(pressed()), SLOT(on_nextPushButton_clicked()));

    // Создание таймера и его настройка
    timer = new QTimer;
    connect(timer, &QTimer::timeout, [&]() {
        if (size != spinBox->value()) {
            size = spinBox->value();
            renul();
        }
        nextPushButton->setEnabled(!mainUpdCheckBox->isChecked() && !updCheckBox->isChecked());
        nextPushButton->setPalette(QPalette((!mainUpdCheckBox->isChecked() && !updCheckBox->isChecked()) ? Qt::white : Qt::gray));

        spinBox->setEnabled(!mainUpdCheckBox->isChecked() && !updCheckBox->isChecked());
        spinBox->setPalette(QPalette((!mainUpdCheckBox->isChecked() && !updCheckBox->isChecked()) ? Qt::white : Qt::gray));
        repaint();
    });
    timer->start(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::centerObjects()
{
    // Получение размеров окна
    int windowWidth = width();
    int windowHeight = height();

    // Центральные координаты окна
    int centerX = windowWidth / 2;
    int centerY = windowHeight / 2;

    // Центрирование кнопки
    int buttonWidth = nextPushButton->width();
    int buttonHeight = nextPushButton->height();
    int buttonX = centerX - buttonWidth / 2;
    int buttonY = centerY - buttonHeight / 2;
    nextPushButton->move(buttonX, buttonY);

    // Центрирование спинбокса
    int spinBoxWidth = spinBox->width();
    int spinBoxHeight = spinBox->height();
    int spinBoxX = centerX - spinBoxWidth / 2;
    int spinBoxY = centerY - spinBoxHeight / 2;
    spinBox->move(spinBoxX, spinBoxY);

    // Центрирование таблицы
    int tableWidth = tableWidget->width();
    int tableHeight = tableWidget->height();
    int tableX = centerX - tableWidth / 2;
    int tableY = centerY - tableHeight / 2;
    tableWidget->move(tableX, tableY);
}

void MainWindow::hanoi(int n, int firstPost, int secondPost, QVector<QVector<int>>& vec)
{
    int c;
    if ((firstPost == 1 && secondPost == 2) || (firstPost == 2 && secondPost == 1))
        c = 3;
    else if ((firstPost == 2 && secondPost == 3) || (firstPost == 3 && secondPost == 2))
        c = 1;
    else
        c = 2;

    if (n > 1) {
        hanoi(n - 1, firstPost, c, vec);
        vec.append(QVector<int>{n, firstPost, secondPost});
        hanoi(n - 1, c, secondPost, vec);
    } else
        vec.append(QVector<int>{n, firstPost, secondPost});
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.drawRect(200, 700, 30, -400);
    paint.drawRect(500, 700, 30, -400);
    paint.drawRect(800, 700, 30, -400);

    for (int i = 0; i < circleFigure.size(); ++i) {
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
    } else if (vec[index][2] == 2) {
        numbOfColonmn = numberOnSecondColumn;
        numberOnSecondColumn++;
        endX = 500 + 15 - circleFigure[circleFigure.size() - vec[index][0]]->width() / 2;
    } else {
        numbOfColonmn = numberOnFirstColumn;
        numberOnFirstColumn++;
        endX = 200 + 15 - circleFigure[circleFigure.size() - vec[index][0]]->width() / 2;
    }

    if (vec[index][1] == 3) {
        numberOnThirdColumn--;
    } else if (vec[index][1] == 2) {
        numberOnSecondColumn--;
    } else {
        numberOnFirstColumn--;
    }

    connect(tm, &QTimer::timeout, [=]() {
        int speedX1 = speedX;
        int speedY1 = speedY;

        if (circleFigure[circleFigure.size() - vec[index][0]]->y() <= 400) {
            if (vec[index][1] < vec[index][2])
                speedX1 = 50;
            else
                speedX1 = -50;
            speedY1 = 0;
        }

        if (abs(circleFigure[circleFigure.size() - vec[index][0]]->x() - endX) <= 20) {
            speedX1 = 0;
            circleFigure[circleFigure.size() - vec[index][0]]->setX(endX);
            speedY1 = 20;
        }

        if (circleFigure[circleFigure.size() - vec[index][0]]->y() < 670 - numbOfColonmn * 30 ||
            abs(circleFigure[circleFigure.size() - vec[index][0]]->x() - endX) > 10) {
            circleFigure[circleFigure.size() - vec[index][0]]->moveTo(
                circleFigure[circleFigure.size() - vec[index][0]]->x() + speedX1,
                circleFigure[circleFigure.size() - vec[index][0]]->y() + speedY1);
        } else {
            tm->stop();
            circleFigure[circleFigure.size() - vec[index][0]]->setRect(endX, 670 - numbOfColonmn * 30,
                                                                       circleFigure[circleFigure.size() -
                                                                                    vec[index][0]]->width(), 30);
            *upd = false;
        }
    });
    tm->start(30);
}

void MainWindow::renul()
{
    vec.clear();
    hanoi(spinBox->value(), 1, 3, vec);
    tableWidget->clear();
    tableWidget->setColumnCount(3);
    tableWidget->setRowCount(vec.size());
    tableWidget->setHorizontalHeaderLabels(QStringList{"Number", "From", "To"});
    tableWidget->setGeometry(1000, 0, 325, 1000);
    tableWidget->setColumnWidth(0, 100);
    tableWidget->setColumnWidth(1, 100);
    tableWidget->setColumnWidth(2, 100);

    index = 0;

    circleFigure.clear();
    colorVec.clear();
    numberOnFirstColumn = spinBox->value();
    numberOnSecondColumn = 0;
    numberOnThirdColumn = 0;

    for (int i = 0; i < spinBox->value(); ++i) {
        QRectF* rect = new QRectF(75 + 10 * i, 670 - 30 * i, 280 - 20 * i, 30);
        circleFigure.append(rect);
    }

    QColor blackColor(Qt::black);
    QColor redColor(Qt::red);

    for (int i = 0; i < circleFigure.size(); ++i) {
        colorVec.append(redColor);
    }

    for (int i = 0; i < vec.size(); ++i) {
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(QString::number(vec[i][0]));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        item->setTextColor(blackColor);
        tableWidget->setItem(i, 0, item);

        item = new QTableWidgetItem;
        item->setText(QString::number(vec[i][1]));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        item->setTextColor(blackColor);
        tableWidget->setItem(i, 1, item);

        item = new QTableWidgetItem;
        item->setText(QString::number(vec[i][2]));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        item->setTextColor(blackColor);
        tableWidget->setItem(i, 2, item);
    }
}

void MainWindow::on_nextPushButton_clicked()
{
    renul();
    QTimer* mainTaimer = new QTimer;
    connect(mainTaimer, &QTimer::timeout, [=]() {
        mainUpdCheckBox->setChecked(true);

        if (!updCheckBox->isChecked()) {
            moveUp(index);
            for (int i = 0; i < tableWidget->rowCount(); ++i) {
                if (index == i) {
                    tableWidget->item(i, 0)->setBackground(Qt::green);
                    tableWidget->item(i, 1)->setBackground(Qt::green);
                    tableWidget->item(i, 2)->setBackground(Qt::green);
                } else {
                    tableWidget->item(i, 0)->setBackground(Qt::white);
                    tableWidget->item(i, 1)->setBackground(Qt::white);
                    tableWidget->item(i, 2)->setBackground(Qt::white);
                }
            }
            if (index < vec.size() - 1)
                index++;
            else {
                mainTaimer->stop();
                mainUpdCheckBox->setChecked(false);
            }
        }
    });
    mainTaimer->start(1000);
}
