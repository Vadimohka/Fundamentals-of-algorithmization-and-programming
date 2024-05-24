#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _keyboard(new Keyboard(this))
    , _analizer(new Input("", _keyboard, Bel, this))
{


    ui->setupUi(this);
    ui->verticalLayout_2->addWidget(_keyboard);
    ui->checkTextEdit->installEventFilter(_analizer);

    ui->checkTextEdit->setReadOnly(true);
    ui->wordsBox->setReadOnly(true);
    ui->timerBox->setReadOnly(true);

    connect(ui->langBox, SIGNAL(currentIndexChanged(int)), SLOT(slotChangeLang(int)));
    connect(ui->startBtn, SIGNAL(clicked(bool)), SLOT(slotStartCheck()));
    connect(_analizer, SIGNAL(endCheck()), SLOT(slotFinishCheck()));
    connect(_analizer, SIGNAL(updateStat()), SLOT(slotUpdateInfo()));
    connect(_analizer, SIGNAL(textChanged(QChar)), SLOT(slotColorText(QChar)));

    _redF.setForeground(Qt::red);
    _greenF.setForeground(Qt::green);
    _blackF.setForeground(Qt::black);

    presets();
    ui->aimTextEdit->setText(_presets.at(_languge));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushAlarm_clicked()
{
    if(!bimage)
    {
        ui->pushAlarm->setStyleSheet("background-color:green");
        QPixmap pix("/home/oblachko/Projects/LabWork_5/Task_1/cat.jpg");
        ui->label_2->setPixmap(pix);
        ui->pushAlarm->setText("Всё хорошо");
    }
    else
    {
        ui->pushAlarm->setStyleSheet("background-color:red");
        ui->label_2->setText(" ");
        ui->pushAlarm->setText("Нажать, когда всё плохо");
    }

    bimage=!bimage;
}


void MainWindow::presets()
{
    _presets.at(0) = "Darf ich mich vorstellen? Ich heiße Inna, bin Studentin und 20 Jahre alt. Vor zwei Jahren habe ich angefangen, Germanistik zu studieren. Das Studium macht mir großen Spaß und ich spreche schon gut Deutsch. In meiner Freizeit lese ich gerne. Zu Hause habe ich viele Bücher. Am liebsten lese ich Abenteuerromane, da sie sehr spannend sind. Oft verbringe ich abends einige Stunden beim Lesen.";
    _presets.at(1) = "Je m’appelle Jessica. Je suis une fille, je suis française et j’ai treize ans. Je vais à l’école à Nice, mais j’habite à Cagnes-Sur-Mer. J’ai deux frères. Le premier s’appelle Thomas, il a quatorze ans. Le second s’appelle Yann et il a neuf ans. Mon papa est italien et il est fleuriste. Ma mère est allemande et est avocate. Mes frères et moi parlons français, italien et allemand à la maison. Nous avons une grande maison avec un chien, un poisson et deux chats.";
    _presets.at(2) = " شخص الحق في التعلم. ويجب أن يكون التعليم في مراحله الأولى والأساسية على الأقل بالمجان، وأن يكون التعليم الأولي إلزاميا وينبغي أن يعمم التعليم الفني والمهني، وأن ييسر القبول للتعليم العالي على قدم المساواة التامة للجميع وعلى أساس الكفاءة.";
    _presets.at(3) = "Shi wo zuo le shen me Rang tian shi sheng qi Hai shi wang le zuo shen me Rang xing fu yuan linYe xu gai yao zhen de xiang xin Shi you zhong ai jiao yuan yuan guan xin Tong que you geng zhu hu xi.";
    _presets.at(4) = "Колькi шуму было тут на гэты час, колькi рознагалосага спеву! Працавiтыя пчолкi, усялякiя мушкi гулi так, што здавалася, нiбы лiпа - гэта нейкi дзiўны музыкальны iнструмент i тут адбываецца iгрышча. Але адцвiла лiпа, пачало спець насенне. Расло адно зернетка на самай высокай галiнцы. Можа, гэтая высачыня i была прычынаю таго, што маладому насенню захацелася кiнуць тутэйшы грунт i перабрацца туды. I якое павiнна быць шчасце жыць там, калi ад аднаго толькi погляду на прыволле гэтай далi рабiлася светла i радасна на душы.";
    _presets.at(5) = "פגישה עם צב צָב קָטַן מָצָאתִי  נִפחָד עָמבא אלי קָרָאתִ אך הוא נִשאַר עוֹ";
}

bool MainWindow::isReadOnly() const
{
    return _isReadOnly;
}

void MainWindow::setReadOnly(bool newStatus)
{
    _isReadOnly = newStatus;

    ui->checkTextEdit->setReadOnly(!newStatus);
    ui->aimTextEdit->setReadOnly(newStatus);
}

void MainWindow::slotChangeLang(int newLangIndex)
{
    _languge = static_cast<Language>(newLangIndex);
    _keyboard->setLanguage(_languge);
    _analizer->setLanguage(_languge);
    ui->aimTextEdit->setText(_presets.at(_languge));
}

void MainWindow::slotStartCheck()
{
    if (_analizer->isRunning()) {
        _analizer->finishCheck();
        return;
    }

    setReadOnly(true);
    ui->checkTextEdit->clear();
    ui->checkTextEdit->setFocus();

    _text = ui->aimTextEdit->toPlainText();
    _charCntr = 0;

    QTextCursor cursor = ui->aimTextEdit->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(_blackF);

    _analizer->setText(ui->aimTextEdit->toPlainText());
    _analizer->slotStartCheck();
    slotUpdateInfo();
}

void MainWindow::slotFinishCheck()
{
    setReadOnly(false);
    ui->langBox->setFocus();
    slotUpdateInfo();
}

void MainWindow::slotColorText(QChar newChar)
{
    QTextCursor cursor(ui->aimTextEdit->document());
    cursor.setPosition(_charCntr, QTextCursor::MoveAnchor);

    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

    if (ui->aimTextEdit->toPlainText().at(_charCntr) == newChar){
        cursor.mergeCharFormat(_greenF);
    } else {
        cursor.mergeCharFormat(_redF);
    }

    ++_charCntr;
}

void MainWindow::slotInsertPreset()
{
    ui->aimTextEdit->setText(_presets.at(static_cast<int>(_languge)));
}

void MainWindow::slotUpdateInfo()
{
    ui->wordsBox->setValue(_analizer->words());
    ui->timerBox->setValue(_analizer->seconds());
}

void MainWindow::slotOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open Text File", "", "");
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    _text = in.readAll();
    file.close();

    ui->aimTextEdit->setText(_text);
}

