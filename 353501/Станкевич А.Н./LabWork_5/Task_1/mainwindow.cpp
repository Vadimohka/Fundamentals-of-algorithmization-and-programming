#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLCD);
    startTime = 0;
    ui->lcd_timer->display("0");

    currKeyboard = getGermanKeyboard();
    setNewKeyBoard();
    setupPopularWords();
    connect(ui->bnt_start, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(ui->bnt_end, &QPushButton::clicked, this, &MainWindow::stopTimer);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QVector<QVector<QString>> MainWindow::getBelarussianKeyboard(){
    QVector<QVector<QString>> belarussianKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "й", "ц", "у", "к", "е", "н", "г", "ш", "ў", "з", "х", "'", "ф", "ы", "в", "а", "п", "р", "о", "л", "д", "ж", "э", "ё", "shift", "\\", "я", "ч", "с", "м", "і", "т", "ь", "б", "ю", ".", "shift", "space", "caps"},
         {"!", "\"", "№", ";", "%", ":", "?", "*", "(", ")", "_", "+", "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Ў", "З", "Х", "'", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э", "Ё", "shift", "/", "Я", "Ч", "С", "М", "І", "Т", "Ь", "Б", "Ю", ".", "shift", "space", "caps"},
         {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Ў", "З", "Х", "'", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э", "Ё", "shift", "\\", "Я", "Ч", "С", "М", "І", "Т", "Ь", "Б", "Ю", ".", "shift", "space", "caps"},
          {"!", "\"", "№", ";", "%", ":", "?", "*", "(", ")", "_", "+", "й", "ц", "у", "к", "е", "н", "г", "ш", "ў", "з", "х", "'", "ф", "ы", "в", "а", "п", "р", "о", "л", "д", "ж", "э", "ё", "shift", "/", "я", "ч", "с", "м", "і", "т", "ь", "б", "ю", ",", "shift", "space", "caps"}
    };
    return belarussianKeyboard;
}

QVector<QVector<QString>> MainWindow::getChinaseKeyboard(){
    QVector<QVector<QString>> chinaseKeyboard = {
                                                 {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "	阿", "贝", "非", "给", "	得", "	也", "用", "热", "赛", "伊", "【", "】", "	伊可罗肯", "卡", "艾了", "艾姆", "恩", "哦", "佩", "可", "阿", "；", "‘", "`", "shift", "、", "也", "卡", "艾了", "艾姆", "恩", "哦", "佩", "，", "。", "/", "shift", "space", "caps"},
                                                 {"！", "@", "#", "￥", "%", "…", "&&", "*", "（", "）", "——", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "『", "』", "A", "S", "D", "F", "G", "H", "J", "K", "L", "：", "“", "～", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", "《", "》", "？", "shift", "space", "caps"},
                                                 {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "【", "】", "A", "S", "D", "F", "G", "H", "J", "K", "L", "；", "’", "`", "shift", "、", "Z", "X", "C", "V", "B", "N", "M", "，", "。", "/", "shift", "space", "caps"},
                                                 {"！", "@", "#", "￥", "%", "…", "&&", "*", "（", "）", "——", "+", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "『", "』", "a", "s", "d", "f", "g", "h", "j", "k", "l", "：", "”", "～", "shift", "|", "z", "x", "c", "v", "b", "n", "m", "《", "》", "？", "shift", "space", "caps"}
    };
    return chinaseKeyboard;
}

QVector<QVector<QString>> MainWindow::getGermanKeyboard() {
    QVector<QVector<QString>> germanKeyboard = {
        {
            "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", "´",
            "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "+", "a",
            "s", "d", "f", "g", "h", "j", "k", "l", "ö", "ä",
            "^", "shift", "#", "y", "x", "c", "v", "b", "n", "m", ",", ".", "-", "shift",
            "space", "caps"
        },
        {
            "!", "\"", "§", "$", "%", "&&", "/", "(", ")", "=", "?", "`",
            "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}",
            "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä",
            "°", "shift", "|", "Y", "X", "C", "V", "B", "N", "M", ";", ":", "_", "shift",
            "space", "caps"
        },
        {
            "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", "´",
            "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", "+", "#",
            "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "^", "shift", "#", "Y", "X",
            "C", "V", "B", "N", "M", ",", ".", "-", "shift", "space", "caps"
        },
        {
            "!", "\"", "§", "$", "%", "&&", "/", "(", ")", "=", "?", "`",
            "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "*", "'",
            "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "°", "shift", "|", "y", "x",
            "c", "v", "b", "n", "m", ";", ":", "_", "shift", "space", "caps"
        }
    };
    return germanKeyboard;
}
QVector<QVector<QString>> MainWindow::getFranchKeyboard() {
    QVector<QVector<QString>> franchKeyboard = {
        {
            "&&", "é", "\"", "'", "(", "-", "è", "_", "ç", "à", ")", "=",
            "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "^", "$",
            "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "ù", "²",
            "shift", "*", "w", "x", "c", "v", "b", "n", ",", ";", ":", "!", "shift",
            "space", "caps"
        },
        {
            "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+",
            "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "¨", "£",
            "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "%", "~",
            "shift", "µ", "W", "X", "C", "V", "B", "N", "?", ".", "/", "§", "shift",
            "space", "caps"
        },
        {
            "&&", "É", "\"", "'", "(", "-", "È", "_", "Ç", "À", ")", "=",
            "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "^", "$",
            "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "Ù", "²",
            "shift", "*", "W", "X", "C", "V", "B", "N", ",", ";", ":", "!", "shift",
            "space", "caps"
        },
        {
            "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+",
            "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "¨", "£",
            "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "%", "~",
            "shift", "", "w", "x", "c", "v", "b", "n", "?", ".", "/", "§", "shift",
            "space", "caps"
        }
    };
    return franchKeyboard;
}

QVector<QVector<QString>> MainWindow::getArabicKeyboard() {
    QVector<QVector<QString>> arabicKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ", "ح", "ج", "د", "ش", "س", "ي", "ب", "ل", "ا", "ت", "ن", "م", "ك", "ط", "ذ", "shift", "\\", "ئ", "ء", "ؤ", "ر", "ﻻ", "ى", "ة", "و", "ز", "ظ", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", ")", "(", "_", "+", "َّ", "ً", "ُ", "ٌ", "ﻹ", "إ", "`", "÷", "×", "؛", "<", ">", "ِ", "ٍ", "]", "[", "ﻷ", "أ", "ـ", "،", "/", ":", "\"", "ّ", "shift", "…", "~", "ْ", "}", "{", "ﻵ", "آ", "'", ",", ".", "؟", "shift", "space", "caps"},
         {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ", "ح", "ج", "د", "ش", "س", "ي", "ب", "ل", "ا", "ت", "ن", "م", "ك", "ط", "ذ", "shift", "\\", "ئ", "ء", "ؤ", "ر", "ﻻ", "ى", "ة", "و", "ز", "ظ", "shift", "space", "caps"},
         {"!", "@", "#", "$", "%", "^", "&&", "*", ")", "(", "_", "+", "َ", "ً", "ُ", "ٌ", "ﻹ", "إ", "`", "÷", "×", "؛", "<", ">", "ِ", "ٍٍ", "]", "[", "ﻷ", "أ", "ـ", "،", "/", ":", "\"", "ّ", "shift", "…", "~", "ْ", "}", "{", "ﻵ", "آ", "'", ",", ".", "؟", "shift", "space", "caps"}
         };
    return arabicKeyboard;
}


QVector<QVector<QString>> MainWindow::getHerbewKeyboard(){
    QVector<QVector<QString>> herbewKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "/", "'", "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "]", "[", "ש", "ד", "ג", "כ", "ע", "י", "ח", "ל", "ך", "ף", ",", ";", "shift", "\\", "ז", "ס", "ב", "ה", "נ", "מ", "צ", "ת", "ץ", ".", "shift", "space", "caps"},
         {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "}", "{", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "~", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", ">", "<", "?", "shift", "space", "caps"},
         {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "]", "[", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", ";", "shift", "\\", "Z", "X", "C", "V", "B", "N", "M", ">", "<", ".", "shift", "space", "caps"},
         {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "/", "'", "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "}", "{", "ש", "ד", "ג", "כ", "ע", "י", "ח", "ל", "ך", "ף", "\"", "~", "shift", "|", "ז", "ס", "ב", "ה", "נ", "מ", "צ", "ת", "ץ", "?", "shift", "space", "caps"}
         };
    return herbewKeyboard;
}


QVector<QPushButton*> MainWindow::getButtons()
{
    QVector<QPushButton*> buttons = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
        ui->bnt_10,ui->bnt_11,ui->bnt_12,ui->bnt_13,ui->bnt_14,ui->bnt_15,ui->bnt_16,
        ui->bnt_17,ui->bnt_18,ui->bnt_19,ui->bnt_20,ui->bnt_21,nullptr,nullptr,
        ui->bnt_24,ui->bnt_25,ui->bnt_26,ui->bnt_27,ui->bnt_28,ui->bnt_29,ui->bnt_30,
        ui->bnt_31,ui->bnt_32,ui->bnt_33,ui->bnt_34,ui->bnt_35,nullptr,nullptr,
        ui->bnt_38,ui->bnt_39,ui->bnt_40,ui->bnt_41,ui->bnt_42,ui->bnt_43,ui->bnt_44,
        ui->bnt_45,ui->bnt_46,ui->bnt_47,ui->bnt_48,ui->bnt_49,ui->bnt_50,ui->bnt_51,
        ui->bnt_52,ui->bnt_53,ui->bnt_54,ui->bnt_55,ui->bnt_56,ui->bnt_57,ui->bnt_58,
        ui->bnt_59,ui->bnt_60,ui->bnt_61,ui->bnt_62,nullptr,nullptr,ui->bnt_65,ui->bnt_66
    };
    return buttons;
}

void MainWindow::setNewKeyBoard()
{
    QVector<QPushButton*> currButtons = getButtons();
    int index;
    if (!currCaps && !currShift) index = 0;
    if (!currCaps && currShift) index = 1;
    if (currCaps && !currShift) index = 2;
    if (currCaps && currShift) index = 3;
    int j = 0;
    for (int  i = 0; i < 66; ++i) {
        if(currButtons[i] != nullptr && currButtons[i]) {
            currButtons[i]->setText(currKeyboard[index][j]);
            j++;
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    indexOfLanguage = index;

    // Устанавливаем новую клавиатуру в зависимости от выбранного языка
    switch (index)
    {
    case 0:
        currKeyboard = getGermanKeyboard();
        break;
    case 1:
        currKeyboard = getFranchKeyboard();
        break;
    case 2:
        currKeyboard = getArabicKeyboard();
        break;
    case 3:
        currKeyboard = getBelarussianKeyboard();
        break;
    case 4:
        currKeyboard = getHerbewKeyboard();
        break;
    case 5:
        currKeyboard = getChinaseKeyboard();
        break;
    default:
        break;
    }

    ui->ln_training->setAlignment(Qt::AlignLeft);

    setNewKeyBoard();

    ui->ln_training->clear();
    on_bnt_end_clicked();

    ui->ln_training->setFocus();
}

void MainWindow::on_pushButton_clicked()
{
    ui->ln_training->clear();
    on_bnt_end_clicked();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
    QString t = "";
    for (auto simb : text) {
        t += "<font color=\"black\">" + QString(simb) + "</font>";
    }
    ui->ln_training->setText(t);
    currString = text;
    setFocus();
}

void MainWindow::startTimer()
{
    startTime = QDateTime::currentMSecsSinceEpoch();
    ui->lcd_timer->display(QString::number(0));
    ui->lcd_symbols->display(QString::number(0));
    ui->lcd_accuracy->display(QString::number(0));
    timer->start(100);
}


void MainWindow::on_bnt_start_clicked()
{
    oldStr = "";
    isActiveTrain = true;
    currIndOfText = 0;
    cntAllStmbol = 0;
    cntCorrectSymbol = 0;
    setFocus();
    if (ui->checkBox->isChecked() || currString == "");
    else {
        QString t = "";
        for (auto simb : currString) {
            t += "<font color=\"black\">" + QString(simb) + "</font>";
        }
        ui->ln_training->setText(t);
    }
}


void MainWindow::on_bnt_end_clicked()
{
    isActiveTrain = false;
    timer->stop();
    setFocus();
}


void MainWindow::stopTimer()
{
    isActiveTrain = false;
    timer->stop();
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Result                  ");
    msgBox.setText("<html>"
                   "<b>Время: " + QString::number(ui->lcd_timer->value()) + "</b><br>"
                                                               "<b>Words per minute: "+ QString::number(ui->lcd_symbols->value()) + "</b><br>"
                   "<b>Точность: "+ QString::number(ui->lcd_accuracy->value()) + "</b><br>"
                                                                                          "</html>");
    msgBox.exec();
}

void MainWindow::updateLCD()
{
    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
    qint64 elapsedTime = currentTime - startTime;


    int tenthsOfSeconds = static_cast<int>(elapsedTime / 100);


    ui->lcd_timer->display(QString::number(tenthsOfSeconds));


    int symbolsPerMinute = static_cast<int>(cntCorrectSymbol * ((static_cast<long double>(600)) / tenthsOfSeconds));
    ui->lcd_symbols->display(QString::number(symbolsPerMinute));


    int accuracy = 0;
    if (cntAllStmbol > 0)
    {
        accuracy = static_cast<int>(static_cast<long double>(cntCorrectSymbol) / cntAllStmbol * 100);
    }
    ui->lcd_accuracy->display(QString::number(accuracy));
}

void MainWindow::changeColorAtIndex(int index, const QString &color)
{
    QString oldStr = ui->ln_training->text();
    ui->ln_training->setText(oldStr.left(index * 28) + "<font color=" + "\"" + color + "\""  + ">" + oldStr.mid(index * 28 + 20, 1) + "</font>" +
                             oldStr.mid(index * 28 + 28));
}

void MainWindow::checkIsCorrectSymbol(QString ch)
{
    if (currIndOfText >= 30) {
        QString subStr = currString.mid(30, currString.size() - 30);
        currString = subStr;
        currIndOfText -= 30;
        QString t = "";
        for (auto simb : currString) {
            t += "<font color=\"black\">" + QString(simb) + "</font>";
        }
        ui->ln_training->setText(t);
    }
    if (currString[currIndOfText] == ch[0]) {
        cntCorrectSymbol++;
        changeColorAtIndex(currIndOfText, "green");
    }
    else {
        changeColorAtIndex(currIndOfText, "red  ");
    }
    cntAllStmbol++;
    currIndOfText++;
}

void MainWindow::setupPopularWords()
{
    const QStringList folderPaths = {
        ":/words/deutchWords.txt",
        ":/words/franceWords.txt",
        ":/words/arabianWords.txt",
        ":/words/belarusianWords.txt",
        ":/words/herbewWords.txt",
        ":/words/chinasesWords.txt"
    };

    popularWords.resize(folderPaths.size());
    for (int i = 0; i < folderPaths.size(); ++i)
    {
        QFile file(folderPaths[i]);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                popularWords[i].push_back(line);
            }
            file.close();
        }
        else
        {

        }
    }
}
