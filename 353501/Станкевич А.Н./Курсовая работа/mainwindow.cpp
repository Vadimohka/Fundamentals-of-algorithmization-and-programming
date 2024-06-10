#include "mainwindow.h"
#include "Coin.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QTableWidgetItem>
#include <QRandomGenerator>
#include <QApplication>
#include <QRandomGenerator>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFocusPolicy(Qt::StrongFocus);
    ui->setupUi(this);
    count = 0;
    timeRemaining = 80;
    scene = new QGraphicsScene();
    player = new HEROE();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //scene->setSceneRect((ui->graphicsView->width() - 20) / -2, -20, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
        scene->setSceneRect(-250,-250,500,500);

        scene->addLine(-250, 0, 250, 0,QPen(Qt::black));
        scene->addLine(0, -250, 0, 250,QPen(Qt::black));

        scene->addLine(-250,-250, 250,-250, QPen(Qt::black));
        scene->addLine(-250, 250, 250, 250, QPen(Qt::black));
        scene->addLine(-250,-250,-250, 250, QPen(Qt::black));
        scene->addLine( 250,-250, 250, 250, QPen(Qt::black));

        generateRandomWalls(scene, -250, -250, 250, 250);


    scene -> addItem(player);
    player -> setPos(0, 0);


    timer = new QTimer();
   connect(timer, &QTimer::timeout, player, &HEROE::mySlot);

    timer->start(1000);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimerTimeout);


   timerCreateCoin = new QTimer();
   connect(timerCreateCoin, &QTimer::timeout, this, &MainWindow::slotCreateCoin);
   timerCreateCoin->start(1000);

   connect(enemy, &Enemy::signalCheckGameOver, this, &MainWindow::slotGameOver);

//   enemy = new Enemy(player);  // Инициализируем паука
  // scene->addItem(enemy);         // Добавляем паука на сцену
   //enemy->setPos(180,180);

   player->setFlags(QGraphicsItem::ItemIsFocusable);
   player->setFocus();
   connect(player, &HEROE::signalCheckItem, this, &MainWindow::slotDeleteCoin);

   gameState = GAME_STOPED;


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateRandomWalls(QGraphicsScene* scene, int minX, int minY, int maxX, int maxY) {
    // Очистить существующие стенки
    scene->clear();

    // Установить размер игрового поля
    scene->setSceneRect(minX, minY, maxX - minX, maxY - minY);

    // Генерация случайных координат для стенок
    int wallThickness = 10; // Толщина стенок

    // Генерация горизонтальных стенок
    int y1 = QRandomGenerator::global()->bounded(minY + wallThickness, maxY - wallThickness);
    int y2 = QRandomGenerator::global()->bounded(minY + wallThickness, maxY - wallThickness);
    scene->addLine(minX, y1, maxX, y1, QPen(Qt::black, wallThickness));
    scene->addLine(minX, y2, maxX, y2, QPen(Qt::black, wallThickness));

    // Генерация вертикальных стенок
    int x1 = QRandomGenerator::global()->bounded(minX + wallThickness, maxX - wallThickness);
    int x2 = QRandomGenerator::global()->bounded(minX + wallThickness, maxX - wallThickness);
    scene->addLine(x1, minY, x1, maxY, QPen(Qt::black, wallThickness));
    scene->addLine(x2, minY, x2, maxY, QPen(Qt::black, wallThickness));

    // Добавить четыре угловые стенки
    scene->addLine(minX, minY, minX, minY + wallThickness, QPen(Qt::black, wallThickness));
    scene->addLine(minX, minY, minX + wallThickness, minY, QPen(Qt::black, wallThickness));
    scene->addLine(maxX - wallThickness, minY, maxX, minY, QPen(Qt::black, wallThickness));
    scene->addLine(maxX, minY, maxX, minY + wallThickness, QPen(Qt::black, wallThickness));
    scene->addLine(minX, maxY - wallThickness, minX, maxY, QPen(Qt::black, wallThickness));
    scene->addLine(minX, maxY, minX + wallThickness, maxY, QPen(Qt::black, wallThickness));
    scene->addLine(maxX - wallThickness, maxY, maxX, maxY, QPen(Qt::black, wallThickness));
    scene->addLine(maxX, maxY - wallThickness, maxX, maxY, QPen(Qt::black, wallThickness));
}

void MainWindow::slotDeleteCoin(QGraphicsItem *item)
{
    foreach (QGraphicsItem *coin, coins) {
        if(coin == item){
            scene->removeItem(coin);
            coins.removeOne(item);
            delete coin;

            int randomNumber = QRandomGenerator::global()->generate() % 100;

            // Если случайное число меньше 25, то игрок получает дополнительные монетки
            if (randomNumber < 10) {
                // Генерируем случайное число от 2 до 5
                int extraCoins = QRandomGenerator::global()->generate() % 4 + 2;
                count += extraCoins;
                ui->lcdNumber->display(count);

                // Выводим сообщение в QMessageBox
                QMessageBox::information(this, "Случайное событие!", QString("Вы получили на %1 монеток больше!").arg(extraCoins));
            } else {
                ui->lcdNumber->display(count++);
            }




            // Если счетчик монет кратен 20, выполняем дополнительную логику
            if (count / 20 == 1 || count / 20 == 2 || count / 20 == 3 || count / 20 == 4) {
                // Удаляем объект enemy
                enemy->deleteLater();
                QTimer::singleShot(2000, [this]()
                 {
                // Выводим сообщение "Вы откупились от врага"
                QMessageBox::information(this, "Событие!", "Вы откупились от врага!");

                // Создаем новый объект enemy в случайной позиции
 // Замените на ваш класс врага
                int x = QRandomGenerator::global()->generate() % static_cast<int>(scene->width());
                int y = QRandomGenerator::global()->generate() % static_cast<int>(scene->height());
                enemy = new Enemy(player);
                enemy->setPos(x, y);
                scene->addItem(enemy);
                QMessageBox::information(this, "Событие!", "Появился новый враг!");
                });
            }
            else if(count / 20 == 5){
                enemy->deleteLater();
            }
        }

    }
}

void MainWindow::slotCreateCoin()
{
    Coin *coin = new Coin(); // Создаём яблоко
    scene->addItem(coin);      // Помещаем его в сцену со случайной позицией
    coin->setPos((qrand() % (251)) * ((qrand()%2 == 1)?1:-1),
                  (qrand() % (251)) * ((qrand()%2 == 1)?1:-1));
    coin->setZValue(-1);       /* Помещаем яблоко ниже Мухи, то есть Муха
                                 * на сцене будет выше яблок
                                 * */
    coins.append(coin);       // Добавляем Яблоко в Список
}

void MainWindow::on_pushButton_clicked()
{


    enemy = new Enemy(player);  // Инициализируем паука
    scene->addItem(enemy);         // Добавляем паука на сцену
    enemy->setPos(180,180);       // Устанавливаем позицию паука

    /* Подключаем сигнал от паука на проверку состояния GameOver
     * */
    //connect(enemy, &Enemy::signalCheckGameOver, this, &MainWindow::slotGameOver);

    /** Инициализируем таймер и вызываем слот обработки сигнала таймера
     * у Треугольника 100 раз в секунду.
     * Управляя скоростью отсчётов, соответственно управляем скоростью
     * изменения состояния графической сцены
     * */
    //connect(timer, &QTimer::timeout, player, &HEROE::slotGameTimer);
    //timer->start(1000 / 100);

    /** Раз в секунду отсылаем сигнал на создание яблока в игре
     * */
    connect(timerCreateCoin, &QTimer::timeout, this, &MainWindow::slotCreateCoin);
    timerCreateCoin->start(1000);

    /** Подключаем сигнал от Мухи, в котором передаются Объекты, на которые
     * наткнулась Муха
     * */
    //connect(triangle, &Triangle::signalCheckItem, this, &Widget::slotDeleteApple);

    ui->pushButton->setEnabled(false);

    gameState = GAME_STARTED;
}
void MainWindow::slotGameEnd(){
    QMessageBox::warning(this,
                         "Game End",
                         " Вы прошли игру");
}

void MainWindow::slotGameOver()
{
    /* Если игра окончена
     * Отключаем все таймеры
     * */
    timer->stop();
    timerCreateCoin->stop();
    QMessageBox::warning(this,
                         "Game Over",
                         "Мои соболезнования, но Вас только что слопали");

}

void MainWindow::slotPause()
{
    /* Выполняем проверку на состояние игры,
     * если игра не запущена, то игнорируем Паузу.
     * В противном случае или запускаем, или останавливаем все таймеры
     * */
    if(gameState == GAME_STARTED){
        if(timer->isActive()){
            timer->stop();
            timerCreateCoin->stop();
            enemy->pause();
        } else {
            timer->start(1000/100);
            timerCreateCoin->start(1000);
            enemy->pause();
        }
    }
}

void MainWindow::slotLcdNumberChanged(int value)
{
//    // Проверяем, кратно ли значение 10
//    if (value % 10 == 0 && value != 0)
//    {
//        QMessageBox::warning(this,
//                             "Game Over",
//                             "Мои соболезнования, но вы проиграли");
//    }
}


void MainWindow::on_pushButton_3_clicked()
{


        this->close();

        // Получаем параметры запуска приложения
        QStringList arguments = QCoreApplication::arguments();

        // Запускаем приложение заново с теми же параметрами
        QProcess::startDetached(QCoreApplication::applicationFilePath(), arguments);

        // Выходим из текущего экземпляра приложения
        QCoreApplication::exit();
}

void MainWindow::onTimerTimeout() {
        timeRemaining--;
        ui->label->setText(QString::number(timeRemaining));

        if (timeRemaining == 0) {
        timer->stop();
        if (count < 100) {
            slotGameOver();
        }
        else {
            slotGameEnd();
        }
        }
}
