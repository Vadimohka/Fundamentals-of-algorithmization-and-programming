#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    timer->start(1);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setVisible(false);

    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->verticalHeader()->setVisible(false);
    ui->tableView_2->horizontalHeader()->setVisible(false);

    ui->tableView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_3->verticalHeader()->setVisible(false);
    ui->tableView_3->horizontalHeader()->setVisible(false);

    ui->tableView_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_4->verticalHeader()->setVisible(false);
    ui->tableView_4->horizontalHeader()->setVisible(false);

    moving();

    drawer = new Drawer(&painter);

    changeWorkPlaceType(0);

    ui->label_12->setVisible(false);
    ui->label_11->setVisible(false);
    ui->pushButton_13->setVisible(false);
    ui->pushButton_14->setVisible(false);
    ui->lineEdit->setVisible(false);

    /*QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("/Users/genos/OneDrive/Рабочий стол/ЛМ/Random/125.mp3"));
    audioOutput->setVolume(50);
    player->play();*/
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timeout()
{
    cr = QCursor::pos() - this->pos();
    cr.setX(cr.x() - 10);
    cr.setY(cr.y() - 130);

    //ui->label_10->setText(QString::number(cr.x()) + " " + QString::number(cr.y()));

    if(ui->checkBox_3->isChecked())
    {
        drawer->color = QColor(ui->spinBox_2->value(), ui->spinBox_3->value(), ui->spinBox_4->value(), ui->spinBox_5->value());
    }

    if(WorkPlaceType == 1)
    {
        drawerCurrent = QCursor::pos() - this->pos();
        drawerCurrent.setY(drawerCurrent.y() - 30);
    }

    ui->label->setText(QString::number(drawerCurrent.x()) + " " + QString::number(drawerCurrent.y()));
    ui->label_9->setText(QString::number(setDrawerMlbClick.x()) + " " + QString::number(setDrawerMlbClick.y()));

    if(mlb && busy == nullptr)
    {
        for(int i = 0; i < sprites.size(); i++)
        {
            if(sprites[i].x <= cr.x() && sprites[i].y <= cr.y())
                if(sprites[i].x + sprites[i].w >= cr.x() && sprites[i].y + sprites[i].h >= cr.y())
                {
                    busy = &sprites[i];
                    break;
                }
        }
    }
    else if(busy != nullptr)
    {
        busy->setCords(cr.x() - busy->w/2, cr.y() - busy->h/2);

        if(busy->x < 0)
            busy->x = 0;
        else if(busy->x + busy->w > 580)
            busy->x = 580 - busy->w;

        if(busy->y < 0)
            busy->y = 0;
        else if(busy->y + busy->h > 380)
            busy->y = 380 - busy->h;

        scene->sprites = sprites;
    }

    update();
}

void Widget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    painter.begin(this);

    painter.fillRect(0, 0, this->width(), 30, QColor(150, 150, 150));

    scene->draw(&painter);

    if(WorkPlaceType == 1)
    {
        drawer->base(&painter);

        if(mlb && busy == nullptr)
        {
            if(drawerCurrent.x() > 611 && drawerCurrent.y() > 101 && drawerCurrent.x() < 611 + 909 && drawerCurrent.y() < 101 + 549)
            {
                if(drawType == 0)
                    drawer->drawPen(drawerCurrent);
                else if(drawType == 1)
                    drawer->drawErase(drawerCurrent);
                else if(drawType == 2)
                    drawer->drawRect(setDrawerMlbClick, drawerCurrent);
                else if(drawType == 3)
                    drawer->drawEllipce(setDrawerMlbClick, drawerCurrent);
                else if(drawType == 4)
                    drawer->drawLine(setDrawerMlbClick, drawerCurrent);
            }
        }

        if(!mlb && busy == nullptr)
            drawer->saveFigure();

        drawer->draw(&painter);

    }

    painter.end();
}

void Widget::moving() //1
{
   blocks = new QStandardItemModel(9, 1);
   blocks->setItem(0, 0, new QStandardItem("Перейти на случайное положение"));
   blocks->setItem(1, 0, new QStandardItem("Перейти на указатель мыши"));
   blocks->setItem(2, 0, new QStandardItem("Перемещаться 1 секунд к случайному положению"));
   blocks->setItem(3, 0, new QStandardItem("Перемещаться 1 секунд к указателю мыши"));
   blocks->setItem(4, 0, new QStandardItem("Перемещаться 1 секунд в точку (0, 0)"));
   blocks->setItem(5, 0, new QStandardItem("Изменить х на 10"));
   blocks->setItem(6, 0, new QStandardItem("Изменить у на 10"));
   blocks->setItem(7, 0, new QStandardItem("Установить х в 100"));
   blocks->setItem(8, 0, new QStandardItem("Установить у в 100"));


    ui->tableView->setModel(blocks);

    ui->tableView->setColumnWidth(0, 331);
}

void Widget::operators() //7
{
   blocks = new QStandardItemModel(6, 1);

   blocks->setItem(0, 0, new QStandardItem("nothing > nothing"));
   blocks->setItem(1, 0, new QStandardItem("nothing < nothing"));
   blocks->setItem(2, 0, new QStandardItem("nothing = nothing"));
   blocks->setItem(3, 0, new QStandardItem("nothing и nothing"));
   blocks->setItem(4, 0, new QStandardItem("nothing или nothing"));
   blocks->setItem(5, 0, new QStandardItem("не nothing"));


    ui->tableView->setModel(blocks);

    ui->tableView->setColumnWidth(0, 331);
}

void Widget::vision() //2
{
   blocks = new QStandardItemModel(7, 1);
   blocks->setItem(0, 0, new QStandardItem("Изменить костюм на nothing"));
   blocks->setItem(1, 0, new QStandardItem("Следующий костюм"));
   blocks->setItem(2, 0, new QStandardItem("Переключить фон на nothing"));
   blocks->setItem(3, 0, new QStandardItem("Следующий фон"));
   blocks->setItem(4, 0, new QStandardItem("Включить видимость"));
   blocks->setItem(5, 0, new QStandardItem("Отключить видимость"));
   blocks->setItem(6, 0, new QStandardItem("Перейти на 1 слой"));

    ui->tableView->setModel(blocks);

    ui->tableView->setColumnWidth(0, 331);
}

void Widget::sensors() //6
{
   blocks = new QStandardItemModel(6, 1);
   blocks->setItem(0, 0, new QStandardItem("Касается указателя мыши"));
   blocks->setItem(1, 0, new QStandardItem("Расстояние до указателя мыши"));
   blocks->setItem(2, 0, new QStandardItem("Клавиша nothing нажата"));
   blocks->setItem(3, 0, new QStandardItem("Мышь нажата"));
   blocks->setItem(4, 0, new QStandardItem("Перетаскивать можно"));
   blocks->setItem(5, 0, new QStandardItem("Перетаскивать нельзя"));

    ui->tableView->setModel(blocks);

    ui->tableView->setColumnWidth(0, 331);
}

void Widget::sounds() //3
{
   blocks = new QStandardItemModel(4, 1);
   blocks->setItem(0, 0, new QStandardItem("Включить звук nothing"));
   blocks->setItem(1, 0, new QStandardItem("Остановить все звуки"));
   blocks->setItem(2, 0, new QStandardItem("Изменить громкость на 10"));
   blocks->setItem(3, 0, new QStandardItem("Установить громкость 100%"));

    ui->tableView->setModel(blocks);

    ui->tableView->setColumnWidth(0, 331);
}

void Widget::ifers() //5
{
   blocks = new QStandardItemModel(10, 1);
   blocks->setItem(0, 0, new QStandardItem("Ждать 1 секунд"));
   blocks->setItem(1, 0, new QStandardItem("Повторить 10 раз"));
   blocks->setItem(2, 0, new QStandardItem("Если nothing, то"));
   blocks->setItem(3, 0, new QStandardItem("Иначе"));
   blocks->setItem(4, 0, new QStandardItem("Ждать до nothing"));
   blocks->setItem(5, 0, new QStandardItem("Повторять пока не nothing"));
   blocks->setItem(6, 0, new QStandardItem("Повторять всегда"));
   blocks->setItem(7, 0, new QStandardItem("Остановить всё"));
   blocks->setItem(8, 0, new QStandardItem("Остановить этот скрипт"));
   blocks->setItem(9, 0, new QStandardItem("Прервать"));

    ui->tableView->setModel(blocks);

    ui->tableView->setColumnWidth(0, 331);
}

void Widget::doings() //4
{
   blocks = new QStandardItemModel(5, 1);
   blocks->setItem(0, 0, new QStandardItem("Когда кнопка ПУСК нажата"));
   blocks->setItem(1, 0, new QStandardItem("Когда клавиша nothing нажата"));
   blocks->setItem(2, 0, new QStandardItem("Когда спрайт нажат"));
   blocks->setItem(3, 0, new QStandardItem("Когда я получу сообщение 1"));
   blocks->setItem(4, 0, new QStandardItem("Передать сообщение 1"));

    ui->tableView->setModel(blocks);

    ui->tableView->setColumnWidth(0, 331);
}

void Widget::variables() //8
{
   blocks = new QStandardItemModel(18, 1);

    blocks->setItem(0, 0, new QStandardItem("Громкость звука"));
    blocks->setItem(1, 0, new QStandardItem("х мыши"));
    blocks->setItem(2, 0, new QStandardItem("у мыши"));
    blocks->setItem(3, 0, new QStandardItem("Костюм номер"));
    blocks->setItem(4, 0, new QStandardItem("Фон номер"));
    blocks->setItem(5, 0, new QStandardItem("nothing + nothing"));
    blocks->setItem(6, 0, new QStandardItem("nothing - nothing"));
    blocks->setItem(7, 0, new QStandardItem("nothing * nothing"));
    blocks->setItem(8, 0, new QStandardItem("nothing / nothing"));
    blocks->setItem(9, 0, new QStandardItem("nothing mod nothing"));
    blocks->setItem(10, 0, new QStandardItem("округлить nothing"));
    blocks->setItem(11, 0, new QStandardItem("Выдать случайное от nothing до nothing"));
    blocks->setItem(12, 0, new QStandardItem("Модуль nothing"));
    blocks->setItem(13, 0, new QStandardItem("Целое меньшее от nothing"));
    blocks->setItem(14, 0, new QStandardItem("Целое большее от nothing"));
    blocks->setItem(15, 0, new QStandardItem("Квадратный корень от nothing"));
    blocks->setItem(16, 0, new QStandardItem("Положение x"));
    blocks->setItem(17, 0, new QStandardItem("Положение у"));

    ui->tableView->setModel(blocks);

    ui->tableView->setColumnWidth(0, 331);
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    ui->label->setText(QString::number(e->key()));

    if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Enter - 1)
    {
        if(WorkPlaceType == 0)
        {
            if(ui->comboBox->currentIndex() == 7 || ui->comboBox->currentIndex() == 6)
                return;

            QModelIndex chsd = ui->tableView->currentIndex();
            QModelIndex t2chsd = ui->tableView_2->currentIndex();

            if(chsd.row() != -1)
            {
                if(ui->checkBox->isChecked())
                    script->appendRow(blocks->item(chsd.row())->clone());
                else if(t2chsd.row() != -1)
                    script->insertRow(t2chsd.row() + 1, blocks->item(chsd.row())->clone());


                ui->tableView_2->setModel(script);

                ui->tableView_2->setColumnWidth(0, 571);
            }
        }
    }
    else if(e->key() == Qt::Key_Delete)
    {
        if(WorkPlaceType == 0)
        {
            QModelIndex chsd = ui->tableView_2->currentIndex();

            if(chsd.row() != -1)
            {
                script->removeRow(chsd.row());
            }
        }
    }
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        mlb = true;
        setDrawerMlbClick = drawerCurrent;
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        mlb = false;
        busy = nullptr;
    }
}

void Widget::changeWorkPlaceType(int index)
{
    WorkPlaceType = index;

    if(index == 0)
    {
        ui->tableView->setVisible(true);
        ui->tableView_2->setVisible(true);

        ui->comboBox->clear();
        ui->comboBox->addItem("Движение");
        ui->comboBox->addItem("Внешний вид");
        ui->comboBox->addItem("Звук");
        ui->comboBox->addItem("События");
        ui->comboBox->addItem("Управление");
        ui->comboBox->addItem("Сенсоры");
        ui->comboBox->addItem("Операторы");
        ui->comboBox->addItem("Переменные");

        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->checkBox->setVisible(true);
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);
        ui->comboBox_3->setVisible(false);
        ui->spinBox->setVisible(false);
        ui->pushButton_3->setVisible(false);

        ui->pushButton_4->setVisible(false);
        ui->pushButton_5->setVisible(false);
        ui->pushButton_6->setVisible(false);
        ui->pushButton_7->setVisible(false);
        ui->pushButton_8->setVisible(false);
        ui->pushButton_9->setVisible(false);
        ui->pushButton_10->setVisible(false);
        ui->pushButton_11->setVisible(false);
        ui->pushButton_12->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->label_7->setVisible(false);
        ui->label_8->setVisible(false);
        ui->spinBox_2->setVisible(false);
        ui->spinBox_3->setVisible(false);
        ui->spinBox_4->setVisible(false);
        ui->spinBox_5->setVisible(false);
        ui->checkBox_2->setVisible(false);
        ui->checkBox_3->setVisible(false);
        ui->tableView_4->setVisible(false);
    }
    else if(index == 1)
    {
        ui->label_3->setVisible(true);
        ui->label_4->setVisible(true);
        ui->comboBox_3->setVisible(true);
        ui->spinBox->setVisible(true);
        ui->pushButton_3->setVisible(true);

        ui->tableView->setVisible(false);
        ui->tableView_2->setVisible(false);

        ui->comboBox->clear();
        ui->comboBox->addItem("Выбрать действие");
        ui->comboBox->addItem("Сохранить новый спрайт");
        ui->comboBox->addItem("Изменить костюм");
        ui->comboBox->addItem("Добавить костюм");

        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->checkBox->setVisible(false);

        ui->pushButton_4->setVisible(true);
        ui->pushButton_5->setVisible(true);
        ui->pushButton_6->setVisible(true);
        ui->pushButton_7->setVisible(true);
        ui->pushButton_8->setVisible(true);
        ui->pushButton_9->setVisible(true);
        ui->pushButton_10->setVisible(true);
        ui->pushButton_11->setVisible(true);
        ui->pushButton_12->setVisible(true);
        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
        ui->label_7->setVisible(true);
        ui->label_8->setVisible(true);
        ui->spinBox_2->setVisible(true);
        ui->spinBox_3->setVisible(true);
        ui->spinBox_4->setVisible(true);
        ui->spinBox_5->setVisible(true);
        ui->checkBox_2->setVisible(true);
        ui->checkBox_3->setVisible(true);
        ui->tableView_4->setVisible(false);
    }

    if(index == 2)
    {
        ui->tableView_4->setVisible(true);

        ui->comboBox->clear();
        ui->comboBox->addItem("Выбрать опцию");
        ui->comboBox->addItem("Добавить звук");
        ui->comboBox->addItem("Удалить звук");

        ui->tableView->setVisible(false);
        ui->tableView_2->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->checkBox->setVisible(false);
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);
        ui->comboBox_3->setVisible(false);
        ui->spinBox->setVisible(false);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(false);
        ui->pushButton_5->setVisible(false);
        ui->pushButton_6->setVisible(false);
        ui->pushButton_7->setVisible(false);
        ui->pushButton_8->setVisible(false);
        ui->pushButton_9->setVisible(false);
        ui->pushButton_10->setVisible(false);
        ui->pushButton_11->setVisible(false);
        ui->pushButton_12->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->label_7->setVisible(false);
        ui->label_8->setVisible(false);
        ui->spinBox_2->setVisible(false);
        ui->spinBox_3->setVisible(false);
        ui->spinBox_4->setVisible(false);
        ui->spinBox_5->setVisible(false);
        ui->checkBox_2->setVisible(false);
        ui->checkBox_3->setVisible(false);
    }
}

void Widget::SpriteSort(QVector<Sprite> array)
{
    bool swapped = true;
    int start = 0;
    int end = array.size() - 1;
    QString temp;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; ++i)
        {
            if (array[i].name > array[i + 1].name)
            {
                temp = array[i].name;
                array[i].name = array[i + 1].name;
                array[i + 1].name = temp;
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i)
        {
            if (array[i].name > array[i + 1].name)
            {
                temp = array[i].name;
                array[i].name = array[i + 1].name;
                array[i + 1].name = temp;
                swapped = true;
            }
        }

        ++start;
    }
}

void Widget::on_comboBox_currentIndexChanged(int index)
{
    if(WorkPlaceType == 0)
    {
        if(index == 0)
            moving();
        else if(index == 1)
            vision();
        else if (index == 2)
            sounds();
        else if (index == 3)
            doings();
        else if (index == 4)
            ifers();
        else if (index == 5)
            sensors();
        else if (index == 6)
            operators();
        else if (index == 7)
            variables();
    }
    else if(WorkPlaceType == 1)
    {
        if(index == 1)
        {
            ui->comboBox->setCurrentIndex(0);

            if(drawer->saveNewSprite().name == "ERRORSPRITE")
                return;

            ui->label_12->setVisible(true);
            ui->label_11->setVisible(true);
            ui->pushButton_13->setVisible(true);
            ui->pushButton_14->setVisible(true);
            ui->lineEdit->setVisible(true);

        }
    }
    else if(WorkPlaceType == 2)
    {
        if(index == 1)
        {
            ui->comboBox->setCurrentIndex(0);

            QString str = "";
            str = QFileDialog::getOpenFileName(this, "Выбрать звук", "", "MP3 File (*.mp3)");

            if(str == "")
            {
                return;
            }

            sound_ar.append(str);

            QString name = "";

            for(int i = str.size() - 5; i >= 0; i--)
            {
                if(str[i] == '/' || str[i] == '\\')
                    break;

                name = str[i] + name;
            }

            sound->appendRow(new QStandardItem(name));

            ui->tableView_4->setModel(sound);

            ui->tableView_4->setColumnWidth(0, 331);
        }
    }
}


void Widget::on_pushButton_clicked() // Добавить
{
    if(WorkPlaceType == 0)
    {
        if(ui->comboBox->currentIndex() == 7 || ui->comboBox->currentIndex() == 6)
            return;

        QModelIndex chsd = ui->tableView->currentIndex();
        QModelIndex t2chsd = ui->tableView_2->currentIndex();

        if(chsd.row() != -1)
        {
            if(ui->checkBox->isChecked())
                script->appendRow(blocks->item(chsd.row())->clone());
            else if(t2chsd.row() != -1)
                script->insertRow(t2chsd.row() + 1, blocks->item(chsd.row())->clone());


            ui->tableView_2->setModel(script);

            ui->tableView_2->setColumnWidth(0, 571);
        }
    }
}


void Widget::on_pushButton_2_clicked() // Удалить
{
    if(WorkPlaceType == 0)
    {
        QModelIndex chsd = ui->tableView_2->currentIndex();

        if(chsd.row() != -1)
        {
            script->removeRow(chsd.row());
        }
    }
}


void Widget::on_comboBox_2_currentIndexChanged(int index)
{
    changeWorkPlaceType(index);
}


void Widget::on_spinBox_valueChanged(int arg1)
{
    drawer->penWidth = arg1;
}


void Widget::on_comboBox_3_currentIndexChanged(int index)
{
    drawType = index;
}


void Widget::on_pushButton_3_clicked()
{
    drawer->clear();
}


void Widget::on_pushButton_4_clicked() // Цвет 1
{
    if(!ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked())
    {
        drawer->color = ui->pushButton_4->palette().color(ui->pushButton_4->backgroundRole());
    }
    else if(ui->checkBox_2->isChecked())
    {
        ui->pushButton_4->setStyleSheet("background-color:rgba(" + QString::number(ui->spinBox_2->value()) + ", " + QString::number(ui->spinBox_3->value()) + ", " + QString::number(ui->spinBox_4->value()) + ", " + QString::number(ui->spinBox_5->value()) + ")");
    }
}


void Widget::on_pushButton_6_clicked() // Цвет 2
{
    if(!ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked())
    {
        drawer->color = ui->pushButton_6->palette().color(ui->pushButton_6->backgroundRole());
    }
    else if(ui->checkBox_2->isChecked())
    {
        ui->pushButton_6->setStyleSheet("background-color:rgba(" + QString::number(ui->spinBox_2->value()) + ", " + QString::number(ui->spinBox_3->value()) + ", " + QString::number(ui->spinBox_4->value()) + ", " + QString::number(ui->spinBox_5->value()) + ")");
    }
}


void Widget::on_pushButton_11_clicked() // Цвет 3
{
    if(!ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked())
    {
        drawer->color = ui->pushButton_11->palette().color(ui->pushButton_11->backgroundRole());
    }
    else if(ui->checkBox_2->isChecked())
    {
        ui->pushButton_11->setStyleSheet("background-color:rgba(" + QString::number(ui->spinBox_2->value()) + ", " + QString::number(ui->spinBox_3->value()) + ", " + QString::number(ui->spinBox_4->value()) + ", " + QString::number(ui->spinBox_5->value()) + ")");
    }
}


void Widget::on_pushButton_5_clicked() // Цвет 4
{
    if(!ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked())
    {
        drawer->color = ui->pushButton_5->palette().color(ui->pushButton_5->backgroundRole());
    }
    else if(ui->checkBox_2->isChecked())
    {
        ui->pushButton_5->setStyleSheet("background-color:rgba(" + QString::number(ui->spinBox_2->value()) + ", " + QString::number(ui->spinBox_3->value()) + ", " + QString::number(ui->spinBox_4->value()) + ", " + QString::number(ui->spinBox_5->value()) + ")");
    }
}


void Widget::on_pushButton_7_clicked() // Цвет 5
{
    if(!ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked())
    {
        drawer->color = ui->pushButton_7->palette().color(ui->pushButton_7->backgroundRole());
    }
    else if(ui->checkBox_2->isChecked())
    {
        ui->pushButton_7->setStyleSheet("background-color:rgba(" + QString::number(ui->spinBox_2->value()) + ", " + QString::number(ui->spinBox_3->value()) + ", " + QString::number(ui->spinBox_4->value()) + ", " + QString::number(ui->spinBox_5->value()) + ")");
    }
}


void Widget::on_pushButton_12_clicked() // Цвет 6
{
    if(!ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked())
    {
        drawer->color = ui->pushButton_12->palette().color(ui->pushButton_12->backgroundRole());
    }
    else if(ui->checkBox_2->isChecked())
    {
        ui->pushButton_12->setStyleSheet("background-color:rgba(" + QString::number(ui->spinBox_2->value()) + ", " + QString::number(ui->spinBox_3->value()) + ", " + QString::number(ui->spinBox_4->value()) + ", " + QString::number(ui->spinBox_5->value()) + ")");
    }
}


void Widget::on_pushButton_10_clicked() // Цвет 7
{
    if(!ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked())
    {
        drawer->color = ui->pushButton_10->palette().color(ui->pushButton_10->backgroundRole());
    }
    else if(ui->checkBox_2->isChecked())
    {
        ui->pushButton_10->setStyleSheet("background-color:rgba(" + QString::number(ui->spinBox_2->value()) + ", " + QString::number(ui->spinBox_3->value()) + ", " + QString::number(ui->spinBox_4->value()) + ", " + QString::number(ui->spinBox_5->value()) + ")");
    }
}


void Widget::on_pushButton_9_clicked() // Цвет 8
{
    if(!ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked())
    {
        drawer->color = ui->pushButton_9->palette().color(ui->pushButton_9->backgroundRole());
    }
    else if(ui->checkBox_2->isChecked())
    {
        ui->pushButton_9->setStyleSheet("background-color:rgba(" + QString::number(ui->spinBox_2->value()) + ", " + QString::number(ui->spinBox_3->value()) + ", " + QString::number(ui->spinBox_4->value()) + ", " + QString::number(ui->spinBox_5->value()) + ")");
    }
}


void Widget::on_pushButton_8_clicked() // Цвет 9
{
    if(!ui->checkBox_2->isChecked() && !ui->checkBox_3->isChecked())
    {
        drawer->color = ui->pushButton_8->palette().color(ui->pushButton_8->backgroundRole());
    }
    else if(ui->checkBox_2->isChecked())
    {
        ui->pushButton_8->setStyleSheet("background-color:rgba(" + QString::number(ui->spinBox_2->value()) + ", " + QString::number(ui->spinBox_3->value()) + ", " + QString::number(ui->spinBox_4->value()) + ", " + QString::number(ui->spinBox_5->value()) + ")");
    }
}


void Widget::on_pushButton_13_clicked() // создать спрайт
{
    for(int i = 0; i < ui->lineEdit->text().size(); i++)
    {
        if(ui->lineEdit->text()[i] != ' ')
            break;
        return;
    }

    Sprite temp = drawer->saveNewSprite();

    temp.name = ui->lineEdit->text();
    if(!sprites.isEmpty())
        temp.id = sprites[sprites.size() - 1].id + 1;

    sprites.append(temp);

    QList <QStandardItem*> ttemp;

    ttemp.append(new QStandardItem(sprites[sprites.size() - 1].name));
    ttemp.append(new QStandardItem(QString::number(sprites[sprites.size() - 1].id)));

    sprits->appendRow(ttemp);
    ui->tableView_3->setModel(sprits);

    ui->tableView_3->setColumnWidth(0, 309);
    ui->tableView_3->setColumnWidth(1, 100);

    ui->label_12->setVisible(false);
    ui->label_11->setVisible(false);
    ui->pushButton_13->setVisible(false);
    ui->pushButton_14->setVisible(false);
    ui->lineEdit->setVisible(false);
}


void Widget::on_pushButton_14_clicked() // отмена создания спрайта
{
    ui->label_12->setVisible(false);
    ui->label_11->setVisible(false);
    ui->pushButton_13->setVisible(false);
    ui->pushButton_14->setVisible(false);
    ui->lineEdit->setVisible(false);
}


void Widget::on_pushButton_15_clicked() // удаление спрайта из таблицы
{
    QModelIndex chsd = ui->tableView_3->currentIndex();

    if(chsd.row() != -1)
    {
        int chsdid = sprits->item(chsd.row(), 1)->text().toInt();
        sprits->removeRow(chsd.row());

        for(int i = 0; i < sprites.size(); i++)
        {
            if(chsdid == sprites[i].id)
            {
                chsdid = i;
                break;
            }
        }

        sprites.remove(chsdid);
    }

    scene->sprites = sprites;
}


void Widget::on_pushButton_16_clicked() // добавить спрайт на сцену
{
    QModelIndex chsd = ui->tableView_3->currentIndex();

    if(chsd.row() != -1)
    {
        sprites[chsd.row()].doDraw = true;
    }

    scene->sprites = sprites;
}


void Widget::on_pushButton_17_clicked() // удалить спрайт со сцены
{
    QModelIndex chsd = ui->tableView_3->currentIndex();

    if(chsd.row() != -1)
    {
        sprites[chsd.row()].doDraw = false;
    }

    scene->sprites = sprites;
}

