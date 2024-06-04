#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->text->setAlignment(Qt::AlignLeft);
    rowsGer << "Q W E R T Z U I O P Ü"
         << "A S D F G H J K L Ö Ä"
         << "Y X C V B N M";
    rowsFr << "A Z E R T Y U I O P"
         << "Q S D F G H J K L M"
         << "W X C V B N , ; : !";
    rowsAra << "ض ص ث ق ف غ ع ه خ ح ج د"
         << "ش س ي ب ل ا ت ن م ك ط"
         << "ئ ء ؤ ر لا ى ة و ز ظ";
    rowsBel << "Й Ц У К Е Н Г Ш Ў З Х Ї"
         << "Ф Ы В А П Р О Л Д Ж Э"
         << "Я Ч С М І Т Ь Б Ю";
    rowsIvr << "ק ר א ט ו ן ם פ"
         << "ש ד ג כ ע י ח ל ך ף"
         << "ז ס ב ה נ מ צ ת";
    ui->comboBox->setFocusPolicy(Qt::NoFocus);
    ui->centralwidget->setFocusPolicy(Qt::NoFocus);
    ui->Space->setFocusPolicy(Qt::NoFocus);
    timer = new QTimer();
    time = QTime(0, 0);
    ui->timer->setText(time.toString());
    connect(timer, SIGNAL(timeout()), this, SLOT(addSec()));
    ui->pushButton->setFocusPolicy(Qt::NoFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == Qt::ShiftModifier) return;
    if (event->key() == Qt::Key_Meta) return;
    if (input.size() == 1) timer->start(1000);
    if (output.size() == 0)
    {
        QStringList words = outtext.split(" ");
        int num = words.size();
        ui->words->setText(QString::number(num / (time.second() / 60.0)));
        timer->stop();
        return;
    }
    input += event->text();
    if (event->key() == Qt::Key_Space)
    {
        ui->Space->animateClick();
        if (input[input.size() - 1] == output.front())
        {
            ui->text->setStyleSheet("QLabel { border: 1px solid green; }");
        }
        else
        {
            ui->text->setStyleSheet("QLabel { border: 1px solid red; }");
        }
        output.remove(0, 1);
        ui->text->setText(output);
        return;
    }
    for (QPushButton* button : buttons)
    {
        if (button->text() == event->text().toUpper())
        {
            button->animateClick();
            if (input[input.size() - 1] == output.front())
            {
                ui->text->setStyleSheet("QLabel { border: 1px solid green; }");
            }
            else
            {
                ui->text->setStyleSheet("QLabel { border: 1px solid red; }");
            }
            output.remove(0, 1);
            ui->text->setText(output);
            return;
        }
    }
    if (input[input.size() - 1] == output.front())
    {
        ui->text->setStyleSheet("QLabel { border: 1px solid green; }");
    }
    else
    {
        ui->text->setStyleSheet("QLabel { border: 1px solid red; }");
    }
    ui->text->setText(output);
    output.remove(0, 1);
}

void MainWindow::addSec()
{
    time = time.addSecs(1);
    ui->timer->setText(time.toString());
    update();
}

void MainWindow::on_comboBox_activated(int index)
{
    timer->stop();
    time = QTime(0, 0);
    update();
    input.clear();
    buttons.clear();
    QLayoutItem* item;
    while ((item = ui->gridLayout->takeAt(0)) != nullptr)
    {
        delete item->widget();
        delete item;
    }
    QStringList row;
    switch (index)
    {
    case 0:
        row = rowsBel;
        output = bel;
        break;
    case 1:
        row = rowsGer;
        output = ger;
        break;
    case 2:
        row = rowsIvr;
        output = ivr;
        break;
    case 3:
        row = rowsAra;
        output = ara;
        break;
    case 4:
        row = rowsFr;
        output = fra;
        break;
    }
    for (int i = 0; i < row.size(); ++i)
    {
        QStringList letters = row[i].split(' ');
        for (int j = 0; j < letters.size(); ++j)
        {
            QPushButton *button = new QPushButton(letters[j]);
            buttons.push_back(button);
            ui->gridLayout->addWidget(button, i, j);
            button->setFocusPolicy(Qt::NoFocus);
        }
    }
    ui->text->setText(output);
    outtext = output;
    ui->pushButton->setEnabled(true);
}


void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    QFile file;
    file.setFileName(path);
    if (file.exists())
    {
        file.open(QIODevice::ReadWrite);
        output = file.readAll();
        ui->text->setText(output);
    }
    outtext = output;
    update();
}

