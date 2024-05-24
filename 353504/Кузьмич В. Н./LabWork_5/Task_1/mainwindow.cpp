#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QInputMethod>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    button.resize(34);
    isPressbutton.resize(34);
    button[0] =  ui->pushButton_5;
    button[1] =  ui->pushButton_6;
    button[2] =  ui->pushButton_7;
    button[3] =  ui->pushButton_8;
    button[4] =  ui->pushButton_9;
    button[5] =  ui->pushButton_10;
    button[6] =  ui->pushButton_11;
    button[7] =  ui->pushButton_12;
    button[8] =  ui->pushButton_13;
    button[9] =  ui->pushButton_14;
    button[10] =  ui->pushButton_15;
    button[11] =  ui->pushButton_16;
    button[12] =  ui->pushButton_17;
    button[13] =  ui->pushButton_18;
    button[14] =  ui->pushButton_19;
    button[15] =  ui->pushButton_20;
    button[16] =  ui->pushButton_21;
    button[17] =  ui->pushButton_22;
    button[18] =  ui->pushButton_23;
    button[19] =  ui->pushButton_24;
    button[20] =  ui->pushButton_25;
    button[21] =  ui->pushButton_26;
    button[22] =  ui->pushButton_27;
    button[23] =  ui->pushButton_28;
    button[24] =  ui->pushButton_29;
    button[25] =  ui->pushButton_30;
    button[26] =  ui->pushButton_31;
    button[27] =  ui->pushButton_32;
    button[28] =  ui->pushButton_33;
    button[29] =  ui->pushButton_34;
    button[30] =  ui->pushButton_35;
    button[31] =  ui->pushButton_36;
    button[32] =  ui->pushButton_37;
    button[33] =  ui->pushButton_38;

    for (int i = 0; i < button.size(); i++){
        button[i]->setEnabled(false);
        isPressbutton[i] = false;
        button[i]->setStyleSheet("color: black;");
    }
    QString line;
    simvols.resize(7);
    SIMVOLS.resize(7);
    SIMVOLS[0] = "Q W E R T Y U I O P { } A S D F G H J K L : \" Z X C V B N M < > ?";
    SIMVOLS[1] = "Q W E R T Z U I O P Ü * A S D F G H J K L Ö Ä Y X C V B N M ; : _";
    SIMVOLS[2] = "A Z E R T Y U I O P ¨ £ Q S D F G H J K L M Ù W X C V B N ? . / §";
    SIMVOLS[3] = "Q W E R T Y U I O P } { A S D F G H J K L : \" Z X C V B N M > < ?";
    SIMVOLS[4] = "َ ً ُ ٌ   إ ` ÷ × ؛ < > ِ ٍ ] [   أ ـ ، / : \" ~ ْ } {   آ ' , . ؟";
    SIMVOLS[5] = "快 過 恩 見 時 鬥 少 送 還 攜 抱 奶 挑 頗 展 肩 訪 寸 燒 千 路 合 味 直 至 趕 場 腳 別 意 路 但 為";
    SIMVOLS[6] = "Й Ц У К Е Н Г Ш Ў З Х ' Ф Ы В А П Р О Л Д Ж Э Я Ч С М І Т Ь Б Ю ,";

    simvols[0] = "q w e r t y u i o p [ ] a s d f g h j k l ; ' z x c v b n m , . /";
    simvols[1] = "q w e r t z u i o p ü + a s d f g h j k l ö ä y x c v b n m , . -";
    simvols[2] = "a z e r t y u i o p ^ $ q s d f g h j k l m ù w x c v b n , ; : !";
    simvols[3] = "/ ' ק ר א ט ו ן ם פ ] [ ש ד ג כ ע י ח ל ך ף , ז ס ב ה נ מ צ ת ץ .";
    simvols[4] = "ض ص ث ق ف غ ع ه خ ح ج د ش س ي ب ل ا ت ن م ك ط ئ ء ؤ ر   ى ة و ز ظ";
    simvols[5] = "理 翼 分 享 詞 斷 物 質 語 言 站 小 數 貿 易 害 怕 吃 物 質 語 言 沙 喊 枝 死 事 實 想 像 磅 聽 到";
    simvols[6] = "й ц у к е н г ш ў з х ' ф ы в а п р о л д ж э я ч с м і т ь б ю .";

    words.resize(7);
    {
        QFile file("/home/vlad/Laba5_T1/Words/eng.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            words[0].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/vlad/Laba5_T1/Words/ger.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            words[1].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/vlad/Laba5_T1/Words/fra.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            words[2].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/vlad/Laba5_T1/Words/her.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            words[3].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/vlad/Laba5_T1/Words/ara.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            words[4].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/vlad/Laba5_T1/Words/chn.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            words[5].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/vlad/Laba5_T1/Words/bel.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            words[6].push_back(line);
        }
        file.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    str = "";
    int n = ui->spinBox->value();
    int m = words[numLanguage].size();
    for (int i = 0; i < n; ++i) {
        str += words[numLanguage][QRandomGenerator::global()->bounded(0, m)];
        if (i+1 < n) str += " ";
    }
    ui -> textEdit -> setText(str);
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}

void MainWindow::on_comboBox_activated(int index)
{
    numLanguage = index;
}

void MainWindow::on_pushButton_4_clicked()
{
    if (ui->textEdit->toPlainText() == "") return;
    ui->stackedWidget->setCurrentWidget(ui -> page_2);
    ui->textEdit_2->setText(str);
    for (int i = 0; i < button.size() - 1; i++){
        button[i]->setText(simvols[numLanguage].at(i * 2));
    }
    if (numLanguage == 4){
        button[27]->setText("لا");
    }
    connect(time, SIGNAL(timeout()), this, SLOT(fun()));
    time->start(10);
}

void MainWindow::fun(){
    time_t += 0.01;
    ui -> label_2 -> setText(QString::number(roundf(time_t * 100) / 100));
    ui -> label_3 -> setText(QString::number(round((kol_words / time_t) * 60)));
    if (correctPresses != 0 || incorrectPresses != 0) ui -> label_4 -> setText(QString::number((double)correctPresses / (correctPresses + incorrectPresses) * 100));
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key() == Qt::Key_Space) {
            if (!isPressbutton[33]){
                if (str[numSimvol] == QChar::Space){
                button[33]->setStyleSheet("background-color: green;");
                correctPresses++;
                numSimvol++;
            }
            else{ button[33]->setStyleSheet("background-color: red;");
            incorrectPresses++;
            }
            isPressbutton[33] = true;
            }
        }
        else{
            int a = keyEvent->nativeScanCode();
            if (a == 50){
                for (int i = 0; i < button.size() - 1; i++){
                    button[i]->setText(SIMVOLS[numLanguage].at(i * 2));
                }
                if (numLanguage == 4){
                    button[4]->setText("لإ");
                    button[16]->setText("لأ");
                    button[27]->setText("لآ");
                }
            }
            if (a < 24 || a == 36 || a == 37 || a == 49 || a == 50 || a == 51 || a > 65 || a == 62 || a == 63 || a == 64) return false;
            if (a >= 38 && a <= 48) a -= 2;
            if (a >= 52) a -= 5;
            a -= 24;
            keyCode = a;
            if(!isPressbutton[keyCode]){
            if (button[keyCode]->text() == str[numSimvol]){
                button[keyCode]->setStyleSheet("background-color: green;");
                    correctPresses++;
                QTextCursor cursor = ui->textEdit_2->textCursor();
                cursor.setPosition(numSimvol);
                cursor.setPosition(++numSimvol, QTextCursor::KeepAnchor);
                QTextCharFormat format;
                format.setForeground(Qt::green);
                cursor.setCharFormat(format);
                if (str[numSimvol] == " " || numSimvol == str.size()){
                    kol_words++;
                }
            }
            else{ button[keyCode]->setStyleSheet("background-color: red;");
            incorrectPresses++;
            }
            isPressbutton[keyCode] = true;
            }
        }
    }
    else if (event->type() == QEvent::KeyRelease){
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if(keyEvent->key() == Qt::Key_Space) {
                button[33]->setStyleSheet("color: black;");
                isPressbutton[33] = false;
            }
            else{
            int a = keyEvent->nativeScanCode();
            if (a == 50){
                for (int i = 0; i < button.size() - 1; i++){
                    button[i]->setText(simvols[numLanguage].at(i * 2));
                }
                if (numLanguage == 4){
                    button[27]->setText("لا");
                }
            }
            else{
                if (a < 24 || a == 36 || a == 37 || a == 49 || a == 50 || a == 51 || a > 65 || a == 62 || a == 63 || a == 64) return false;
                if (a >= 38 && a <= 48) a -= 2;
                if (a >= 52) a -= 5;
                a -= 24;
                keyCode = a;
                button[keyCode]->setStyleSheet("color: black;");
            }
            isPressbutton[keyCode] = false;
            }
            if (numSimvol == str.size()){
            disconnect(time, SIGNAL(timeout()), this, SLOT(fun()));
            time -> stop();
            }
    }
    return false;
}


void MainWindow::on_pushButton_39_clicked()
{
    close();
}


void MainWindow::on_pushButton_40_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui -> page);
    disconnect(time, SIGNAL(timeout()), this, SLOT(fun()));
    time->stop();
    keyCode = 1;
    numSimvol = 0;
    keyIsPressed = true;
    time_t = 0;
    kol_words = 0, correctPresses = 0, incorrectPresses = 0;
    QTextCursor cursor = ui->textEdit_2->textCursor();
    cursor.movePosition(QTextCursor::Start);
    cursor.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    QTextCharFormat defaultFormat;
    cursor.setCharFormat(defaultFormat);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString line;
    QString file_id = QFileDialog::getOpenFileName(this, tr("Открыттие файла"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(file_id);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
            line = in.readLine();
            str += line;
            str += " ";
            ui -> textEdit -> setText(str);
    }
    file.close();
}

