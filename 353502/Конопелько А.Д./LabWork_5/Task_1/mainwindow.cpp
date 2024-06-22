#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myDialog = new Dialog();
    connect(myDialog, &Dialog::signalStart, this, &MainWindow::startSlot);
    myDialog->setModal(true);
    myDialog->exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startSlot(int ind)
{
    delete(myDialog);
    myDialog = nullptr;

    addButtonsFromLayout(ui->horizontalLayout);
    addButtonsFromLayout(ui->horizontalLayout_2);
    addButtonsFromLayout(ui->horizontalLayout_3);
    addButtonsFromLayout(ui->horizontalLayout_4);

    switch(ind){
    case 0:
        keyBoard = "¹1234567890ß´qwertzuiopü+#asdfghjklöäyxcvbnm,.- ";
        break;
    case 1:
        keyBoard = "@àéèê()‘’«»'^azertyuiop-+*qsdfghjklm/wxcvbn.,:; ";
        break;
    case 2:
        keyBoard = "ذ&é\"'(-è_çà)=ضصثقفغعهخحجد\شسيبلاتنمكطئءؤرلاىةوزظ ";
        break;
    case 3:
        keyBoard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ";
        break;
    case 4:
        keyBoard = "ё1234567890-=йцукенгшўзх’\фывапролджэячсмітьбю. ";
        break;
    case 5:
        keyBoard = ";1234567890-=/'קראטוןםפ][\שדגכעיחלךף,זסבהנמצתץ. ";
        break;
    }

    qDebug() << "keyBoard  = " << keyBoard;
    buttons.push_back(ui->space);

    for (int i = 0; i < keyBoard.size(); i++)
    {
        buttons[i]->setText(QString(keyBoard[i]));
    }
    indexLang = ind;
    qDebug() << indexLang;
    QString lang[6] = {"German", "French", "Arab", "Chinese", "Belarusian", "Hebrew"};
    ui->label_2->setText(lang[ind]);
    ui->lineEdit->setText(texts[ind]);
    ui->lineEdit->setCursorPosition(0);
}

void MainWindow::addButtonsFromLayout(const QLayout* layout)
{
    auto count = layout->count();
    for (int i = 0; i < count; i++){
        auto item = layout->itemAt(i);
        QPushButton* button = dynamic_cast<QPushButton*>(item->widget());
        if (button != nullptr){
            buttons.push_back(button);
        }
    }
}

int MainWindow::find(QChar ch)
{
    for(int i = 0; i < keyBoard.size(); i++){
        if(keyBoard[i].unicode() == ch.unicode())
            return i;
    }
    return -1;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(firstLetter){
        timer = new QTimer();
        connect(timer, &QTimer::timeout, this, [=](){
            ui->lineEdit_2->setText(QDateTime::fromTime_t(secTime).toUTC().toString("hh:mm:ss"));
            secTime++;
        });
        timer->start(1000/60);
        firstLetter = false;
    }
    this->update();
    qDebug() << event->text()[0].unicode() << " " << ui->lineEdit->text()[indCursor].unicode();

    if(event->text()[0].unicode() == ui->lineEdit->text()[indCursor].unicode()){
        if(find(event->text()[0]) == -1)
            return;
        buttons[find(event->text()[0])]->setPalette(QPalette(Qt::green));
        int val = (ui->spinBox_cor->value()) + 1;
        ui->spinBox_cor->setValue(val);
        ui->lineEdit->cursorForward(1);
        indCursor++;
    }
    else{
        if(find(event->text()[0]) == -1)
            return;
        buttons[find(event->text()[0])]->setPalette(QPalette(Qt::red));
        int valInc = (ui->spinBox_inc->value()) + 1;
        ui->spinBox_inc->setValue(valInc);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->text().isEmpty())
        return;
    if(find(event->text()[0]) >= 0 && find(event->text()[0]) < 51)
        buttons[find(event->text()[0])]->setPalette(QPalette());
}

