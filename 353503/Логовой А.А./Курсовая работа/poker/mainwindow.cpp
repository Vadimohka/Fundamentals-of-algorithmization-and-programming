#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameboard.h"
#include <QVBoxLayout>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    rulesDialog(new QDialog)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    showMaximized();

    stackedWidget  = new QStackedWidget(this);

    QTextEdit *rulesText = new QTextEdit(rulesDialog);
     rulesText->setFontPointSize(16);
     rulesText->setReadOnly(true);

    rulesText->setText("Позиции за столом: В Техасском Холдеме обычно играют от 4 до 6 участников. Позиция “дилер” (или “баттон”)"
" обозначает, кто сдает карты. В казино за столом сидит профессиональный дилер, но фишка дилера все равно передается от игрока к игроку.Блайнды (слепые ставки): Дв"
"а игрока слева от дилера делают обязательные ставки, известные как блайнды.Малый блайнд” - это полови"
"на минимальной ставки, а “большой блайнд” - это полная минимальная ставка.Раздача карт: Каждому игроку раздаю"
"т по две закрытые карты, известные как “карманные карты”. Цель игры - собрать лучшую комбинацию из пяти карт.Этапы игры:Префлоп: Первый круг торгов начинается с игрока слева от большого блайнда.Флоп: На стол выкладыв"
"аются три общие карты.Терн: Выкладывается четвертая общая карта.Ривер: Выкладывается пятая и последняя общая карта.Шоудаун: Игроки, оставшиеся в игре, показываю"
"т свои карты, чтобы определить победителя.Комбинации карт от самой сильной к самой слабой:Роял Флеш - самая сильная комбинация, состоящая "
                       "из последовательности карт одной масти от десятки до туза."
                       "Стрит Флеш - пять последовательных карт одной масти.Каре - четыре карты одного номинала."
                       "Фулл Хаус - комбинация из трех карт одного номинала и двух карт другого.Флеш - любые пять карт одной масти."
                       "Стрит - пять последовательных карт разных мастей.Сет - три карты одного номинала.Две пары - две карты одного номинала и две карты другого."
                       "Пара - две карты одного номинала.Старшая карта - если ни у кого нет комбинаций, выигрывает игрок с картой высшего номинала.");

    QVBoxLayout *layout = new QVBoxLayout(rulesDialog);
    layout->addWidget(rulesText);
    rulesDialog->setAutoFillBackground(true);
    rulesDialog->setStyleSheet("background-color:white;");
    rulesDialog->hide();
    rulesDialog->resize(800, 600);
    connect(ui->info_btn, &QPushButton::clicked, this, &MainWindow::showRules);
    connect(ui->winers_btn,&QPushButton::clicked, this, &MainWindow::showWinners);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_game_start_clicked()
{
    gameBoard  = new GameBoard(stackedWidget);
    stackedWidget->addWidget(gameBoard);
   stackedWidget->setCurrentWidget(gameBoard);
}

void MainWindow::on_end_game_clicked()
{
    this->close();
}

void MainWindow::showWinners()
{
    QDialog *winnersDialog = new QDialog;
    winnersDialog->setAutoFillBackground(true);
    winnersDialog->setStyleSheet("background-color:white;");

    QTextEdit *winnersText = new QTextEdit(winnersDialog);
    winnersText->setReadOnly(true);
    winnersDialog->setMinimumSize(800, 600);


    QFile file("winners.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            winnersText->append(line);
        }
        file.close();
    }

    QVBoxLayout *layout = new QVBoxLayout(winnersDialog);
    layout->addWidget(winnersText);
    winnersDialog->show();
}


void MainWindow::showRules()
{
    if (rulesDialog->isVisible())
    {
        rulesDialog->hide();
    }
    else {
        rulesDialog->show();
    }
}
