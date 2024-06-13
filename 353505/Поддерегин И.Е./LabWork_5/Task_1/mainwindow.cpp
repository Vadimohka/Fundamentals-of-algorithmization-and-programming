#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    timer = new QTimer(this);
    ui->text_label->setFont(QFont("", 20));
    startTime = 0;
    ui->time_label->setText("0");
    currKeyboard = getEnglishKeyboard();
    setNewKeyBoard();


    connect(timer, &QTimer::timeout, this,[this](){
        startTime += 0.1;
        ui->time_label->setText(QString::number(startTime));

        int sym = cntCorrectSymbol * 60 / startTime;
        ui->spm_label->setText(QString::number(sym));

        int acc = 0;
        if (cntAllStmbol)  acc = (long double)cntCorrectSymbol/cntAllStmbol * 100;
        ui->accuracy_label->setText(QString::number(acc));
    });

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
            "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "{", "}",
            "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä",
            "°", "shift", "|", "Y", "X", "C", "V", "B", "N", "M", ";", ":", "_", "shift",
            "space", "caps"
        },
        {
            "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", "´",
            "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", "+",
            "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "^", "shift", "#", "Y", "X",
            "C", "V", "B", "N", "M", ",", ".", "-", "shift", "space", "caps"
        },
        {
            "!", "\"", "§", "$", "%", "&&", "/", "(", ")", "=", "?", "`",
            "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "*", "'",
            "s", "d", "f", "g", "h", "j", "k", "l", "ö", "ä", "°", "shift", "|", "y", "x",
            "c", "v", "b", "n", "m", ";", ":", "_", "shift", "space", "caps"
        }
    };
    return germanKeyboard;
}
QVector<QVector<QString>> MainWindow::getFranchKeyboard() {
    QVector<QVector<QString>> franchKeyboard = {
        {"&&", "é", "\"", "'", "(", "-", "è", "_", "ç", "à", ")", "=","a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "^", "$","q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "ù", "²","shift", "*", "w", "x", "c", "v", "b", "n", ",", ";", ":", "!", "shift","space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+","A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "¨", "£","Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "%", "~","shift", "µ", "W", "X", "C", "V", "B", "N", "?", ".", "/", "§", "shift","space", "caps"},
        {"&&", "É", "\"", "'", "(", "-", "È", "_", "Ç", "À", ")", "=","A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "^", "$","Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "Ù", "²","shift", "*", "W", "X", "C", "V", "B", "N", ",", ";", ":", "!", "shift","space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+","a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "¨", "£","q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "%", "~","shift", "", "w", "x", "c", "v", "b", "n", "?", ".", "/", "§", "shift","space", "caps"}
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
QVector<QVector<QString>> MainWindow::getchineseKeyboard(){
    QVector<QVector<QString>> chineseKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "【", "】", "a", "s", "d", "f", "g", "h", "j", "k", "l", "；", "‘", "`", "shift", "、", "z", "x", "c", "v", "b", "n", "m", "，", "。", "/", "shift", "space", "caps"},
        {"！", "@", "#", "￥", "%", "…", "&&", "*", "（", "）", "——", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "『", "』", "A", "S", "D", "F", "G", "H", "J", "K", "L", "：", "“", "～", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", "《", "》", "？", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "【", "】", "A", "S", "D", "F", "G", "H", "J", "K", "L", "；", "’", "`", "shift", "、", "Z", "X", "C", "V", "B", "N", "M", "，", "。", "/", "shift", "space", "caps"},
        {"！", "@", "#", "￥", "%", "…", "&&", "*", "（", "）", "——", "+", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "『", "』", "a", "s", "d", "f", "g", "h", "j", "k", "l", "：", "”", "～", "shift", "|", "z", "x", "c", "v", "b", "n", "m", "《", "》", "？", "shift", "space", "caps"}
    };

    return chineseKeyboard;
}

QVector<QPushButton*> MainWindow::getButtons()
{
    QVector<QPushButton*> buttons = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,
                                    ui->pushButton_10,ui->pushButton_11,ui->pushButton_12,ui->pushButton_13,ui->pushButton_14,ui->pushButton_15,ui->pushButton_16,
                                    ui->pushButton_17,ui->pushButton_18,ui->pushButton_19,ui->pushButton_20,ui->pushButton_21,nullptr,nullptr,
                                    ui->pushButton_24,ui->pushButton_25,ui->pushButton_26,ui->pushButton_27,ui->pushButton_28,ui->pushButton_29,ui->pushButton_30,
                                    ui->pushButton_31,ui->pushButton_32,ui->pushButton_33,ui->pushButton_34,ui->pushButton_35,nullptr,nullptr,
                                    ui->pushButton_38,ui->pushButton_39,ui->pushButton_40,ui->pushButton_41,ui->pushButton_42,ui->pushButton_43,ui->pushButton_44,
                                    ui->pushButton_45,ui->pushButton_46,ui->pushButton_47,ui->pushButton_48,ui->pushButton_49,ui->pushButton_50,ui->pushButton_51,
                                    ui->pushButton_52,ui->pushButton_53,ui->pushButton_54,ui->pushButton_55,ui->pushButton_56,ui->pushButton_57,ui->pushButton_58,
                                    ui->pushButton_59,ui->pushButton_60,ui->pushButton_61,ui->pushButton_62,nullptr,nullptr,ui->pushButton_65,ui->pushButton_66
    };
    return buttons;
}

void MainWindow::setNewKeyBoard()
{
    QVector<QPushButton*> currButtons = getButtons();
    int stateKeyboard;
    if (!currCaps && !currShift) stateKeyboard = 0;
    if (!currCaps && currShift) stateKeyboard = 1;
    if (currCaps && !currShift) stateKeyboard = 2;
    if (currCaps && currShift) stateKeyboard = 3;
    int j = 0;
    for (int  i = 0; i < 66; ++i) {
        if(currButtons[i] != nullptr && currButtons[i]) {
            currButtons[i]->setText(currKeyboard[stateKeyboard][j]);
            j++;
        }
    }
}


void MainWindow::startTraining()
{

    if(isActiveTrain)return;
    ui->label->setText("Press ESC to end training");
    QString t = "";
    for (auto simb : TrainingText) {
        t += "<font color=\"black\">" + QString(simb) + "</font>";
    }
    ui->text_label->setText(t);
    ui->text_label->setAlignment(Qt::AlignLeft);
    currString = TrainingText;
    startTime = 0;
    oldStr = "";
    isActiveTrain = true;
    currIndOfText = 0;
    cntAllStmbol = 0;
    cntCorrectSymbol = 0;
    setFocus();
    timer->start(100);
}

void MainWindow::endTraining()
{

    if(!isActiveTrain) return;
    ui->label->setText("Press ENTER to start training");
    isActiveTrain = false;
    timer->stop();
    setFocus();
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Результат тренировки                  ");
    msgBox.setText("<html>"
                   "<b>Время: " + ui->time_label->text() + "</b><br>"
                                              "<b>Символов в минуту: " + ui->spm_label->text() + "</b><br>"
                                             "<b>Точность: "+ ui->accuracy_label->text() + "</b><br>"
                                                  "</html>");
    msgBox.exec();
}

void MainWindow::changeColorAtIndex(int index, const QString &color)
{
    oldStr = ui->text_label->text();
    ui->text_label->setText(oldStr.left(index * 28) + "<font color=" + "\"" + color + "\""  + ">" + oldStr[index * 28 + 20] + "</font>" +
                            oldStr.right(oldStr.size() - index * 28 - 28));




}

bool MainWindow::checkIsCorrectSymbol(QString ch)
{
    if (currIndOfText >= 30) {
        QString subStr = currString.mid(30, currString.size() - 30);
        currString = subStr;
        currIndOfText -= 30;
        QString t = "";
        for (auto simb : currString) {
            t += "<font color=\"black\">" + QString(simb) + "</font>";
        }
        ui->text_label->setText(t);
    }


    if (currString[currIndOfText] == ch[0]) {
        cntCorrectSymbol++;
        changeColorAtIndex(currIndOfText, "green");
        cntAllStmbol++;
        currIndOfText++;
        return true;
    }
    else {
        changeColorAtIndex(currIndOfText, "red  ");
        cntAllStmbol++;
        currIndOfText++;
        return false;
    }

}
void MainWindow::keyPressEvent(QKeyEvent *event)
{


    if (event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete ||
        event->key() == Qt::Key_Left || event->key() == Qt::Key_Right ||
        event->key() == Qt::Key_Up || event->key() == Qt::Key_Down ||
        event->key() == Qt::Key_Tab)
    {
        return;
    }


    if(ui->comboBox->currentIndex()==6)
    {

    }
    int code = event->nativeScanCode();
    if(code == 36)
    {

        startTraining();

    }
    else if(code == 9)
    {
        endTraining();
    }
    QVector<QPushButton*> currButtons = getButtons();
    if (code == -1) return;

    if (code == 66) {
        currCaps = !currCaps;
        if(currCaps) currButtons[code - 1]->setStyleSheet("background-color: blue;");
        else currButtons[code - 1]->setStyleSheet("background-color: white;");
        setNewKeyBoard();
    }
    else if (code == 50 || code == 62)
    {
        currButtons[49]->setStyleSheet("background-color: blue;");
        currButtons[61]->setStyleSheet("background-color: blue;");
        currShift = true;
        setNewKeyBoard();
    }
    else if (code >= 1 && code <= 66)
    {

        QPushButton* button = currButtons[code - 1];
        if (button != nullptr)
        {
            button->setStyleSheet("background-color: red;");
            if (isActiveTrain && (currIndOfText < currString.size() - 1))
            {
                if(checkIsCorrectSymbol(event->text())) button->setStyleSheet("background-color: green;");
                else button->setStyleSheet("background-color: red;");

            }
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    int code = event->nativeScanCode();
    QVector<QPushButton*> currButtons = getButtons();
    if (code < 67 && currButtons[code - 1] != nullptr && currButtons[code - 1]) {
        if (code != 66) {
            if (code == 50 || code == 62) {

                currButtons[49]->setStyleSheet("background-color: white");
                currButtons[61]->setStyleSheet("background-color: white;");
                currShift = false;
                setNewKeyBoard();
            } else {

                currButtons[code - 1]->setStyleSheet("background-color: white;");
            }
        }
    }
    if (isActiveTrain && (currIndOfText >= currString.size() - 1)) endTraining();
}


void MainWindow::on_comboBox_activated(int index)
{

    QString fileName;
    switch (ui->comboBox->currentIndex()) {
    case 1:
        currKeyboard = getEnglishKeyboard();
        setNewKeyBoard();
        fileName = ("/home/poddubny/Test/Eng.txt");
        break;

    case 2:
        currKeyboard = getFranchKeyboard();
        setNewKeyBoard();
        fileName = ("/home/poddubny/Test/Frn.txt");
        break;

    case 3:

        currKeyboard = getBelarussianKeyboard();
        setNewKeyBoard();
        fileName = ("/home/poddubny/Test/Bel.txt");
        break;

    case 4:
        currKeyboard = getGermanKeyboard();
        setNewKeyBoard();
        fileName = ("/home/poddubny/Test/Deu.txt");
        break;

    case 5:
        currKeyboard = getHerbewKeyboard();
        setNewKeyBoard();
        fileName = ("/home/poddubny/Test/Her.txt");
        break;

    case 6:
        currKeyboard = getchineseKeyboard();
        setNewKeyBoard();
        fileName = ("/home/poddubny/Test/Chn.txt");
        break;

    case 7:
        currKeyboard = getArabicKeyboard();
        setNewKeyBoard();
        fileName = ("/home/poddubny/Test/A.txt");
        break;

    default:
        break;
    }
    if(isActiveTrain)endTraining();
    QFile file (fileName);
    file.open(QFile::ReadOnly);
    QTextStream in(&file);
    TrainingText = in.readAll();
    file.close();
    QString t = "";
    for (auto simb : TrainingText) {
        t += "<font color=\"black\">" + QString(simb) + "</font>";
    }
    ui->text_label->setText(t);
    ui->text_label->setAlignment(Qt::AlignLeft);
    currString = TrainingText;
    setFocus();

}

