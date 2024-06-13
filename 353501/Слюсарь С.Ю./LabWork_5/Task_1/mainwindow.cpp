#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(900, 650);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLCD);
    startTime = 0;
    ui->lcd_timer->display("0");
    connect(ui->bnt_start, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(ui->bnt_end, &QPushButton::clicked, this, &MainWindow::stopTimer);
    currKeyboard = getGermanKeyboard();
    setNewKeyBoard();
    setupPopularWords();
}

MainWindow::~MainWindow()
{
    delete ui;
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

QVector<QVector<QString> > MainWindow::getEnglishKeyboard()
{
    QVector<QVector<QString>> englishKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'", "`", "shift", "\\", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "~", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", "shift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "{", "}", "a", "s", "d", "f", "g", "h", "j", "k", "l", ":", "\"", "~", "shift", "|", "z", "x", "c", "v", "b", "n", "m", "<", ">", "?", "shift", "space", "caps"}
    };
    return englishKeyboard;
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

QVector<QVector<QString>> MainWindow::getHerbewKeyboard(){
    QVector<QVector<QString>> herbewKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "/", "'", "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "]", "[", "ש", "ד", "ג", "כ", "ע", "י", "ח", "ל", "ך", "ף", ",", ";", "shift", "\\", "ז", "ס", "ב", "ה", "נ", "מ", "צ", "ת", "ץ", ".", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "}", "{", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "~", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", ">", "<", "?", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "]", "[", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", ";", "shift", "\\", "Z", "X", "C", "V", "B", "N", "M", ">", "<", ".", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "/", "'", "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "}", "{", "ש", "ד", "ג", "כ", "ע", "י", "ח", "ל", "ך", "ף", "\"", "~", "shift", "|", "ז", "ס", "ב", "ה", "נ", "מ", "צ", "ת", "ץ", "?", "shift", "space", "caps"}
    };
    return herbewKeyboard;
}

QVector<QVector<QString>> MainWindow::getChinaseKeyboard(){
    QVector<QVector<QString>> chinaseKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "【", "】", "a", "s", "d", "f", "g", "h", "j", "k", "l", "；", "‘", "`", "shift", "、", "z", "x", "c", "v", "b", "n", "m", "，", "。", "/", "shift", "space", "caps"},
        {"！", "@", "#", "￥", "%", "…", "&&", "*", "（", "）", "——", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "『", "』", "A", "S", "D", "F", "G", "H", "J", "K", "L", "：", "“", "～", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", "《", "》", "？", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "【", "】", "A", "S", "D", "F", "G", "H", "J", "K", "L", "；", "’", "`", "shift", "、", "Z", "X", "C", "V", "B", "N", "M", "，", "。", "/", "shift", "space", "caps"},
        {"！", "@", "#", "￥", "%", "…", "&&", "*", "（", "）", "——", "+", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "『", "』", "a", "s", "d", "f", "g", "h", "j", "k", "l", "：", "”", "～", "shift", "|", "z", "x", "c", "v", "b", "n", "m", "《", "》", "？", "shift", "space", "caps"}
    };
    return chinaseKeyboard;
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
    if (index == 0) {
        currKeyboard = getGermanKeyboard();
        ui->ln_training->setAlignment(Qt::AlignLeft);
    }
    else if (index == 1) {
        currKeyboard = getFranchKeyboard();
        ui->ln_training->setAlignment(Qt::AlignLeft);
    }
    else if (index == 2) {
        currKeyboard = getArabicKeyboard();
        ui->ln_training->setAlignment(Qt::AlignLeft);
    }
    else if (index == 3) {
        currKeyboard = getEnglishKeyboard();
        ui->ln_training->setAlignment(Qt::AlignLeft);
    }
    else if (index == 4) {
        currKeyboard = getBelarussianKeyboard();
        ui->ln_training->setAlignment(Qt::AlignLeft);
    }
    else if (index == 5) {
        currKeyboard = getHerbewKeyboard();
        ui->ln_training->setAlignment(Qt::AlignLeft);
    }
    else if (index == 6) {
        currKeyboard = getChinaseKeyboard();
        ui->ln_training->setAlignment(Qt::AlignLeft);
    }
    setNewKeyBoard();
    ui->ln_training->clear();
    on_bnt_end_clicked();
    setFocus();
}

void MainWindow::on_pushButton_clicked()
{
    ui->ln_training->clear();
    on_bnt_end_clicked();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Ошибка при открытии файла";
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


void MainWindow::on_bnt_start_clicked()
{
    oldStr = "";
    isActiveTrain = true;
    currIndOfText = 0;
    cntAllStmbol = 0;
    cntCorrectSymbol = 0;
    setFocus();
    if (ui->checkBox->isChecked() || currString == "") generateText();
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

void MainWindow::startTimer()
{
    startTime = QDateTime::currentMSecsSinceEpoch();
    ui->lcd_timer->display(QString::number(0));
    ui->lcd_symbols->display(QString::number(0));
    ui->lcd_accuracy->display(QString::number(0));
    timer->start(100);
}

void MainWindow::stopTimer()
{
    isActiveTrain = false;
    timer->stop();
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Результат тренировки                  ");
    msgBox.setText("<html>"
                   "<b>Время: " + QString::number(ui->lcd_timer->value()) + "</b><br>"
                                                               "<b>Слов в минуту: "+ QString::number(ui->lcd_symbols->value()) + "</b><br>"
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
    int sym = cntCorrectSymbol * ((long double)600 / tenthsOfSeconds);
    ui->lcd_symbols->display(QString::number(sym));
    int acc = 0;
    if (cntAllStmbol)  acc = (long double)cntCorrectSymbol/cntAllStmbol * 100;
    ui->lcd_accuracy->display(QString::number(acc));
}

void MainWindow::changeColorAtIndex(int index, const QString &color)
{
    oldStr = ui->ln_training->text();
    ui->ln_training->setText(oldStr.first(index * 28) + "<font color=" + "\"" + color + "\""  + ">" + oldStr[index * 28 + 20] + "</font>" +
                             oldStr.last(oldStr.size() - index * 28 - 28));
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
    QStringList folderPaths = {":/popularwords/deutchWords.txt",
                               ":/popularwords/franceWords.txt",
                               ":/popularwords/arabianWords.txt",
                               ":/popularwords/englishWords.txt",
                               ":/popularwords/belarusianWords.txt",
                               ":/popularwords/herbewWords.txt",
                               ":/popularwords/chinasesWords.txt"};

    popularWords.resize(7);
    QString line;
    for (int i = 0; i < folderPaths.size(); ++i) {
        QFile file(folderPaths[i]);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Ошибка открытия файла" << folderPaths[i];
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            popularWords[i].push_back(line);
        }
        file.close();
    }
}

void MainWindow::generateText()
{
    QString randomText = "";
    int count_of_words = 50;
    if (indexOfLanguage == 2 || indexOfLanguage == 5 || indexOfLanguage == 6) {
        count_of_words = 13;
    }
    QRandomGenerator generator;
    for (int i = 0; i < count_of_words; ++i) {
        QString randomWord = popularWords[indexOfLanguage][(generator.bounded(popularWords.size()) + rand()) % 1000];
        randomText += randomWord;
        if (i < 99 && count_of_words != 13) {
            randomText += " ";
        }
    }
    if (count_of_words == 13) {
        randomText += " ";
    }
    QString t = "";
    for (auto simb : randomText) {
        t += "<font color=\"black\">" + QString(simb) + "</font>";
    }
    ui->ln_training->setText(t);
    currString = randomText;
}
