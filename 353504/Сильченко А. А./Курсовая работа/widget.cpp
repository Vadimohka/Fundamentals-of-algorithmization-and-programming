#include "widget.h"
#include "ui_widget.h"

/* Функция для получения рандомного числа
     * в диапазоне от минимального до максимального
     * */
static int randomBetween(int low, int high)
{
    return (QRandomGenerator::global()->generate()%((high + 1) - low) + low);
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Косметическая подготовка приложения
    //this->resize(840,840);          // Устанавливаем размеры окна приложения
    //this->setFixedSize(840,840);
    //this->showMaximized();

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    w=randomBetween(0,500)+1100;
    h=randomBetween(0,340)+1000;
    this->resize(w,h);
    ui->graphicsView->resize(w,h);
    ui->graphicsView->showMaximized();
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    //scene->setSceneRect(0,0,900,500); // Устанавливаем размер сцены
    //QPixmap pixBoard("/home/oblachko/Projects/CourseProject/background.jpg");
    back=randomBetween(1,3);
    qDebug()<<back;
    if(back==1)
    {
        QPixmap pixBoard("/home/oblachko/Projects/Курсовая работа/resource/background1.jpg");
        pixBoard = pixBoard.scaled((this->size()), Qt::KeepAspectRatioByExpanding);
        QGraphicsPixmapItem *ite = new QGraphicsPixmapItem(pixBoard);
        scene->addItem(ite);
    }
    else if(back==2)
    {
        QPixmap pixBoard("/home/oblachko/Projects/Курсовая работа/resource/background2.jpg");
        pixBoard = pixBoard.scaled((this->size()), Qt::KeepAspectRatioByExpanding);
        QGraphicsPixmapItem *ite = new QGraphicsPixmapItem(pixBoard);
        scene->addItem(ite);
    }
    else
    {
        QPixmap pixBoard("/home/oblachko/Projects/Курсовая работа/resource/background3.jpg");
        pixBoard = pixBoard.scaled((this->size()), Qt::KeepAspectRatioByExpanding);
        QGraphicsPixmapItem *ite = new QGraphicsPixmapItem(pixBoard);
        scene->addItem(ite);
    }

    QPalette p(this->palette());
    p.setColor(QPalette::Window, QColor(210, 220, 247));
    this->setAutoFillBackground(true);
    this->setPalette(p);
    timer=new QTimer();
    //ui->graphicsView->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(start==false)
    {
        start=true;
        ui->pushButton->setText("Стоп");
        item->setPos(500,500);
        scene->addItem(item);    // Добавляем элемент на графическую сцену
        //fishes(it);
        //if(eat(it))
        it = new Fishes();
        if(randomBetween(1,2)==1)
            it->setPos(0,randomBetween(30,930));
        else
            it->setPos(1000,randomBetween(30,930));

        scene->addItem(it);
        fishes(it);
       /*        for(int i=it->x; i<600; ++i)
        {
            it->setPos(i, it->y);
        }*/
        /*        while(points!=500)
        {
            if(eat(it))
            {
                points+=10;
                ui->spinBox->setValue(points);
            }
        }*/
        QPainter*painter;
        //if(eat(it))
        {
            points+=10;
            //item->growFish(painter, option, this, 10);
        }

    }
    else
    {
        start=false;
        ui->pushButton->setText("Начать");
        scene->update();
    }
}

void Widget::fishes(Fishes *it)
{
    for(int i=0; i<N; ++i)
    {
        it = new Fishes();
        if(randomBetween(0,1)==0)
        it->setPos(0,randomBetween(30,930));
        else
        it->setPos(0,randomBetween(30,930));

        scene->addItem(it);
        //it->pathGeneration();
    }
}

bool Widget::eat(Fishes *it)
{
    bool xinside=*(it->midxi)>=*(item->xj)&&*(it->midxi)<=(*(item->xj)+*(item->wj));
    bool yinside=*(it->midyi)>=*(item->yj)&&*(it->midyi)<=(*(item->yj)+*(item->hj));
    bool bigger=*(it->wi)<=*(item->wj);
    if(bigger&&xinside&&yinside)
    {
        item->points+=10;
        it->destroyed();
        return true;
    }
    else
    {
        item->destroyed();
        return false;
    }
}

/*void Widget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    item->setPos((event->pos()));
}*/


void Widget::on_exitButton_clicked()
{
    exit(true);
}

void Widget::keyPressEvent(QKeyEvent *ke)
{
    qDebug()<<ke->key()<<" "<<(int)Qt::LeftArrow;
    if (ke->key()== 16777234&&!Right)
    {
        qDebug()<<"Left press";
        Left=true;
        for(int i=item->x; i>0;i--)
            item->setPos(i, item->y);
        //connect(timer,SIGNAL(timeout()),this,SLOT(move_left()));
        //timer->start(5);

    }
    if (ke->key()== 16777236&&!Left)
    {
        qDebug()<<"Right press";
        Right=true;
        connect(timer,SIGNAL(timeout()),this,SLOT(move_right()));
        timer->start(5);

    }
}

void Widget::keyReleaseEvent(QKeyEvent *ke)
{
    if (!(ke->modifiers() & Qt::LeftArrow))
    {
        //qDebug()<<"Left realese";
        //disconnect(timer,SIGNAL(timeout()),this,SLOT(move_left()));
        //timer->stop();
        //Left=false;
    }
    if (!(ke->modifiers() & Qt::RightArrow))
    {
        //qDebug()<<"Right realese";
        //disconnect(timer,SIGNAL(timeout()),this,SLOT(move_right()));
        //timer->stop();
        //Right=false;
    }
}

void Widget::move_left()
{
    for(int i=item->x; i>0;i--)
        item->setPos(i, item->y);
    item->move(-1);
    update();
}

void Widget::move_right()
{
    item->move(+1);
    update();
}
