#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_menu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , menu(new Menu)
    , dice(new Dice)
    , scene(new QGraphicsScene)
{
    ui->setupUi(this);
    showFullScreen();
    player = new Player;
    combat = new Combat(player);
    world = new World(player, combat);
    form = new CreationForm(world);

    ui->background->setScaledContents(true);
    ui->background->resize(size());
    ui->background->lower();
    ui->diceView->setScene(scene);
    ui->inventory->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->inventory->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->experienceBar->setTextVisible(false);

    cursor = ui->dialog->textCursor();
    cursor.setCharFormat(format);

    connect(menu, &Menu::Close, this, &MainWindow::closeWindow);
    connect(menu, &Menu::Continue, this, &MainWindow::closeMenu);
    connect(menu, &Menu::NewGame, this, &MainWindow::newGame);
    connect(dice, &Dice::rolled, this, &MainWindow::handleDiceRoll);
    connect(form, &CreationForm::Completed, this, &MainWindow::handlePlayerCreate);
    connect(combat, &Combat::sendText, this, &MainWindow::handleTextReceived);
    connect(this, &MainWindow::DiceRolled, combat, &Combat::handleRoll);
    connect(combat, &Combat::enemyRoll, this, &MainWindow::handleEnemyRoll);
    connect(combat, &Combat::gameOver, this, &MainWindow::handleGameOver);
    connect(player, &Player::sendText, this, &MainWindow::handleTextReceived);
    connect(this, &MainWindow::SendCommand, world, &World::handleCommand);
    connect(world, &World::sendText, this, &MainWindow::handleTextReceived);
    connect(world, &World::createPlayer, this, &MainWindow::handleCreate);
    connect(world, &World::blockInput, this, &MainWindow::handleBlockInput);
    connect(this, &MainWindow::DiceRolled, world, &World::handleRoll);
    connect(world, &World::gameOver, this, &MainWindow::handleGameOver);

    format.setForeground(QColor("black"));
    cursor.insertText("Добро пожаловать в увлекательный мир \"Dungeons & Data\"!\nСперва давайте "
                      "создадим персонажа, а затем окунемся в этот неповторимый фентези "
                      "мир:\nВведите \"/create\"\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeWindow()
{
    menu->close();
    close();
}

void MainWindow::closeMenu()
{
    menu->close();
    this->setEnabled(true);
}

void MainWindow::newGame()
{
    menu->close();
    this->setEnabled(true);

    world->clearWorld();
    combat->clearInfo();
    ui->dialog->clear();
    canRoll = true;
    isCreate = false;
    ui->inputLine->setReadOnly(false);

    format.setForeground(Qt::black);
    cursor.setCharFormat(format);
    cursor.insertText("(Окно обновится после создания персонжа)\n");
    cursor.insertText("Добро пожаловать в увлекательный мир \"Dungeons & Data\"!\nСперва давайте "
                      "создадим персонажа, а затем окунемся в этот неповторимый фентези "
                      "мир:\nВведите \"/create\"\n");
    updateWindow();
}

void MainWindow::handleDiceRoll(int type, int num, bool isLast)
{
    canRoll = false;
    scene->clear();
    QPointF center(0, 0);
    double radius = 80;
    int sides = 0;
    QPen pen(Qt::black);
    if (type == D10) {
        QPolygonF polygon;
        QPointF point(center.x(), center.y() + radius * 2 / 3);
        polygon << point;
        point.setX(center.x() + radius);
        point.setY(center.y());
        polygon << point;
        point.setX(center.x());
        point.setY(center.y() - radius * 2 / 3);
        polygon << point;
        point.setX(center.x() - radius);
        point.setY(center.y());
        polygon << point;
        scene->addPolygon(polygon, pen);
    } else {
        if (type == D4) {
            sides = 3;
        } else if (type == D6) {
            sides = D4;
        } else if (type == D8) {
            sides = D6;
        } else if (type == D12) {
            sides = D10;
        } else if (type == D20) {
            sides = D6;
        }
        QPolygonF polygon;
        for (int i = 0; i < sides; ++i) {
            qreal angle = 2 * M_PI * i / sides - M_PI / 2.0;
            QPointF point(center.x() + radius * std::cos(angle),
                          center.y() + radius * std::sin(angle));
            polygon << point;
        }
        if (type == D8) {
            QLineF line1(polygon[0], polygon[2]);
            QLineF line2(polygon[2], polygon[4]);
            QLineF line3(polygon[4], polygon[0]);
            scene->addLine(line1, pen);
            scene->addLine(line2, pen);
            scene->addLine(line3, pen);
        }
        scene->addPolygon(polygon, QPen(Qt::black));
    }
    QFont font("Caskaydia Cove Nerd Font", 30);
    QString text = QString::number(num);
    QGraphicsTextItem *textItem = new QGraphicsTextItem(text);
    textItem->setFont(font);
    textItem->setDefaultTextColor(Qt::black);

    QRectF bounds = textItem->boundingRect();
    qreal textWidth = bounds.width();
    qreal textHeight = bounds.height();

    textItem->setPos(-textWidth / 2, -textHeight / 2);
    scene->addItem(textItem);

    canRoll = isLast;
    //qDebug() << canRoll;
    if (isLast) {
        currRoll.first = num;
        currRoll.second = type;
        QTimer::singleShot(1000, [&]() { emit DiceRolled(currRoll.second, currRoll.first); });
    }
}

void MainWindow::handlePlayerCreate(Player *newPlayer)
{
    player->setup(newPlayer);
    form->close();
    this->setEnabled(true);
    isCreate = true;
    updateWindow();

    format.setForeground(QColor(Qt::darkGreen));
    cursor.setCharFormat(format);
    cursor.insertText("Вы благополучно создали персонажа\n");
    format.setForeground(QColor(Qt::black));
    cursor.setCharFormat(format);
    cursor.insertText(
        "В далеких землях Понии, где магия пронизывает воздух и приключения ждут за каждым "
        "поворотом, древние силы снова пробуждаются. Земли трясутся под угрозой злодеев, "
        "темные тени нависают над миром, а герои — как новые, так и старые — снова выбвигаются "
        "в дорогу, чтобы противостоять этому злу. Ваше приключение начинается здесь, в мире, где "
        "каждый выбор имеет значение, а каждый шаг ведет к новым опасностям и возможностям. "
        "Приготовься, путник, тебя ждет удивительное путешествие, полное тайн, битв и "
        "волшебства.\n");
    emit SendCommand("/i");
    ui->dialog->ensureCursorVisible();
}

void MainWindow::on_menuButton_clicked()
{
    menu->show();
    this->setEnabled(false);
}

void MainWindow::on_rollButton_clicked()
{
    QString str = ui->diceBox->currentText();
    str.remove(0, 1);
    int d = str.toInt();
    if (canRoll) {
        dice->startRolling(d);
    }
}

void MainWindow::on_enterButton_clicked()
{
    QString text = ui->inputLine->text();
    if (!text.isEmpty()) {
        ui->dialog->clear();
        format.setForeground(QColor(Qt::darkGray));
        cursor.setCharFormat(format);
        cursor.insertText(text + '\n');
        ui->dialog->ensureCursorVisible();

        ui->inputLine->clear();
        emit SendCommand(text);
    }
}

void MainWindow::on_inputLine_returnPressed()
{
    QString text = ui->inputLine->text();
    if (!text.isEmpty()) {
        ui->dialog->clear();

        format.setForeground(QColor(Qt::darkGray));
        cursor.setCharFormat(format);
        cursor.insertText(text + '\n');
        ui->dialog->ensureCursorVisible();

        ui->inputLine->clear();
        emit SendCommand(text);
    }
}

void MainWindow::updateWindow()
{
    ui->healthLabel->setText(QString::number(player->getHealth()));
    ui->armorLabel->setText(QString::number(player->getDefence()));
    ui->initiativeLabel->setText(QString::number(player->getMod(DEXTERITY)));
    ui->lvl->setText(QString::number(player->getLvl()));
    ui->experienceBar->setValue(player->getExp() * 100 / player->getMaxExp());
    ui->name->setText(player->getName());
    ui->gameClass->setText(player->getGameClass());
    ui->race->setText(player->getRace());
    ui->damage->setText("D" + QString::number(player->getDamage()));

    ui->stats->setColumnCount(1);
    ui->stats->setItem(0, 0, new QTableWidgetItem(QString::number(player->getMod(STRENGTH))));
    ui->stats->setItem(1, 0, new QTableWidgetItem(QString::number(player->getMod(DEXTERITY))));
    ui->stats->setItem(2, 0, new QTableWidgetItem(QString::number(player->getMod(CONSTITUTION))));
    ui->stats->setItem(3, 0, new QTableWidgetItem(QString::number(player->getMod(INTELLEGENCE))));
    ui->stats->setItem(4, 0, new QTableWidgetItem(QString::number(player->getMod(WISDOM))));
    ui->stats->setItem(5, 0, new QTableWidgetItem(QString::number(player->getMod(CHARISMA))));

    for (int i = 0; i < player->inventory.size(); i++) {
        ui->inventory->setRowCount(i + 1);
        ui->inventory->setItem(i, 0, new QTableWidgetItem(player->inventory[i]->getName()));
        ui->inventory->setItem(i, 1, new QTableWidgetItem(player->inventory[i]->getDescription()));
    }
}

void MainWindow::handleTextReceived(QString text, QColor color)
{
    format.setForeground(color);
    cursor.setCharFormat(format);
    cursor.insertText(text);

    ui->dialog->verticalScrollBar()->setValue(ui->dialog->verticalScrollBar()->maximum());
    if (isCreate) {
        updateWindow();
    }
}

void MainWindow::handleEnemyRoll(int d)
{
    if (canRoll) {
        dice->startRolling(d);
    }
}

void MainWindow::handleGameOver()
{
    format.setForeground(QColor(Qt::red));
    cursor.setCharFormat(format);
    cursor.insertText("\nИгра окончена\n");
    menu->show();
    this->setEnabled(false);
}

void MainWindow::handleCreate()
{
    form->show();
    this->setEnabled(false);
}

void MainWindow::handleBlockInput(bool state)
{
    ui->inputLine->setReadOnly(state);
}

void MainWindow::on_useButton_clicked()
{
    QList<QTableWidgetItem *> selectedItems = ui->inventory->selectedItems();
    if (!selectedItems.isEmpty()) {
        int index = ui->inventory->currentRow();
        int type = player->inventory[index]->getType();
        qDebug() << index;
        player->useItem(index);
        if (type == HEAL) {
            format.setForeground(QColor(Qt::darkGreen));
            cursor.setCharFormat(format);
            cursor.insertText("Вы восстановили " + QString::number(player->inventory[index]->use())
                              + " здоровья\n");
            player->inventory.removeAt(index);
        } else {
            format.setForeground(QColor(Qt::darkGreen));
            cursor.setCharFormat(format);
            cursor.insertText("Вы экипировали " + player->inventory[index]->getName() + "\n");
        }
        ui->inventory->clearSelection();
        updateWindow();
        ui->dialog->ensureCursorVisible();
    }
}

void MainWindow::on_infoButton_clicked()
{
    QMessageBox::information(this,
                             "Информация",
                             "/create - cоздать персонажа\n"
                             "/info - информация о том, куда можно пойти\n"
                             "/go (название места) - отправиться в выбранное место\n"
                             "/talk (имя) - поговорить с \"имя\"\n"
                             "/fight (имя) - сразиться с \"имя\"\n"
                             "/choose (число) - выбрать вариант ответа");
}
