#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLCD);
    startTime = QDateTime::currentMSecsSinceEpoch();
    connect(ui->start, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(ui->end, &QPushButton::clicked, this, &MainWindow::stopTimer);

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeKeyboard(int)));

    setNewKeyboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startTimer() {
    ui->value_timer->display(QString::number(0));
    ui->value_simb->display(QString::number(0));
    ui->value_accur->display(QString::number(0));
    timer->start(100);
    isTimerActiv = true;
    startTime = QDateTime::currentMSecsSinceEpoch();
}

void MainWindow::stopTimer() {
    isTimerActiv = false;
    timer->stop();

    double accuracy = 0.0;
    if (cntAllSmb > 0) {
        accuracy = static_cast<double>(cntCorrectSymbol) / cntAllSmb * 100.0;
    }

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Result");
    msgBox.setText("Time: " + QString::number(ui->value_timer->value()) + "\n"
                                                                          "Symbols typed: " + QString::number(ui->value_simb->value()) + "\n"
                                                                "Accuracy: " + QString::number(accuracy, 'f', 2) + "%");
    msgBox.exec();
}


void MainWindow::updateLCD() {
    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
    qint64 elapsedTime = currentTime - startTime;
    ui->value_timer->display(QString::number(elapsedTime / 1000.0));

    int symbolCount = ui->forText->text().size();

    ui->value_simb->display(QString::number(symbolCount));

    double accuracy = 0.0;
    if (cntAllSmb > 0) {
        accuracy = static_cast<double>(cntCorrectSymbol) / cntAllSmb * 100.0;
    }
    ui->value_accur->display(QString::number(accuracy, 'f', 2));
}


void MainWindow::changeKeyboard(int index) {
    indexOfLanguage = index;
    setNewKeyboard();
}

QVector<QVector<QString>> MainWindow::getBelarusianKeyboard() {
    QVector<QVector<QString>> belarusianKeyboard = {
        // Обычная раскладка
        {"ё", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "й", "ц", "у", "к", "е", "н", "г", "ш", "ў", "з", "х", "`", "\\",
            "caps", "ф", "ы", "в", "а", "п", "р", "о", "л", "д", "ж", "э",
            "shift", "я", "ч", "с", "м", "і", "т", "ь", "б", "ю", ".", "shift",
            "space"
        },
        // Раскладка для shift
        {"Ё", "!", "\"", "№", ";", "%", ":", "?", "*", "(", ")", "_", "+",
            "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Ў", "З", "Х", "`", "|",
            "caps", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э",
            "shift", "Я", "Ч", "С", "М", "І", "Т", "Ь", "Б", "Ю", ":", "shift",
            "space"
        },
        // Раскладка для caps
        {"Ё", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Ў", "З", "Х", "`", "\\",
            "caps", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э",
            "shift", "Я", "Ч", "С", "М", "І", "Т", "Ь", "Б", "Ю", ".", "shift",
            "space"
        }
    };

    return belarusianKeyboard;
}

QVector<QVector<QString>> MainWindow::getGermanKeyboard() {
    QVector<QVector<QString>> germanKeyboard = {
        // Обычная раскладка
        {"^", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", "´",
            "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "+",
            "caps", "a", "s", "d", "f", "g", "h", "j", "k", "l", "ö", "ä", "#",
            "shift", "<", "y", "x", "c", "v", "b", "n", "m", ",", ".", "-", "shift",
            "space"
        },
        // Раскладка для shift
        {"°", "!", "\"", "§", "$", "%", "&", "/", "(", ")", "=", "?", "`",
            "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", "*",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "'",
            "shift", ">", "Y", "X", "C", "V", "B", "N", "M", ";", ":", "_", "shift",
            "space"
        },
        // Раскладка для caps
        {"^", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", "´",
            "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", "+",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "#",
            "shift", "<", "Y", "X", "C", "V", "B", "N", "M", ",", ".", "-", "shift",
            "space"
        }
    };

    return germanKeyboard;
}

QVector<QVector<QString>> MainWindow::getFrenchKeyboard() {
    QVector<QVector<QString>> frenchKeyboard = {
        // Обычная раскладка
        {"²", "&", "é", "\"", "'", "(", "-", "è", "_", "ç", "à", ")", "=",
            "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "^", "$",
            "caps", "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "ù", "*",
            "shift", "<", "w", "x", "c", "v", "b", "n", ",", ";", ":", "!", "shift",
            "space"
        },
        // Раскладка для shift
        {"É", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+",
            "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "¨", "£",
            "caps", "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "%", "µ",
            "shift", ">", "W", "X", "C", "V", "B", "N", "?", ".", "/", "§", "shift",
            "space"
        },
        // Раскладка для caps
        {"²", "&", "É", "\"", "'", "(", "-", "È", "_", "Ç", "À", ")", "=",
            "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "^", "$",
            "caps", "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "Ù", "*",
            "shift", "<", "W", "X", "C", "V", "B", "N", ",", ";", ":", "!", "shift",
            "space"
        }
    };

    return frenchKeyboard;
}

QVector<QVector<QString>> MainWindow::getEnglishKeyboard() {
    QVector<QVector<QString>> englishKeyboard = {
        // Обычная раскладка
        {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "\\",
            "caps", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'",
            "shift", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "shift",
            "space"
        },
        // Раскладка для shift
        {"~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+",
            "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "|",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"",
            "shift", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", "shift",
            "space"
        },
        // Раскладка для caps
        {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "\\",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'",
            "shift", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "shift",
            "space"
        }
    };

    return englishKeyboard;
}

QVector<QVector<QString>> MainWindow::getChinesseKeyboard() {
    QVector<QVector<QString>> chinesseKeyboard = {
        // Обычная раскладка
        {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "\\",
            "caps", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'",
            "shift", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "shift",
            "space"
        },
        // Раскладка для shift
        {"~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+",
            "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "|",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"",
            "shift", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", "shift",
            "space"
        },
        // Раскладка для caps
        {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "\\",
            "caps", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'",
            "shift", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "shift",
            "space"
        }
    };

    return chinesseKeyboard;
}

QVector<QVector<QString>> MainWindow::getArabicKeyboard() {
    QVector<QVector<QString>> arabicKeyboard = {
        // Обычная раскладка
        {"ذ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ", "ح", "ج", "د", "\\",
            "caps", "ش", "س", "ي", "ب", "ل", "ا", "ت", "ن", "م", "ك", "ط",
            "shift", "ئ", "ء", "ؤ", "ر", "ى", "ة", "و", "ز", "ظ", ".", "shift",
            "space"
        },
        // Раскладка для shift
        {"ّ", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+",
            "َ", "ً", "ُ", "ٌ", "لإ", "إ", "‘", "÷", "×", "؛", "<", ">", "|",
            "caps", "ِ", "ٍ", "]", "[", "لأ", "أ", "ـ", "،", "/", ":", "\"",
            "shift", "~", "ْ", "}", "{", "؟", ".", ",", "،", "؛", "٠", "shift",
            "space"
        },
        // Раскладка для caps
        {"ذ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ", "ح", "ج", "د", "\\",
            "caps", "ش", "س", "ي", "ب", "ل", "ا", "ت", "ن", "م", "ك", "ط",
            "shift", "ئ", "ء", "ؤ", "ر", "ى", "ة", "و", "ز", "ظ", ".", "shift",
            "space"
        }
    };

    return arabicKeyboard;
}

QVector<QVector<QString>> MainWindow::getHebrewKeyboard() {
    QVector<QVector<QString>> hebrewKeyboard = {
        // Обычная раскладка
        {";", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "ש", "ד", "ג", "כ", "\\",
            "caps", "ע", "י", "ח", "ל", "ך", "ף", ",", "ז", "ס", "ב", "ה",
            "shift", "נ", "מ", "צ", "ת", "ץ", ".", "ז", "ס", "ב", "ה", "shift",
            "space"
        },
        // Раскладка для shift
        {"~", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+",
            "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "ש", "ד", "ג", "כ", "|",
            "caps", "ע", "י", "ח", "ל", "ך", "ף", ",", "ז", "ס", "ב", "ה",
            "shift", "נ", "מ", "צ", "ת", "ץ", ".", "ז", "ס", "ב", "ה", "shift",
            "space"
        },
        // Раскладка для caps
        {"`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
            "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "ש", "ד", "ג", "כ", "\\",
            "caps", "ע", "י", "ח", "ל", "ך", "ף", ",", "ז", "ס", "ב", "ה",
            "shift", "נ", "מ", "צ", "ת", "ץ", ".", "ז", "ס", "ב", "ה", "shift",
            "space"
        }
    };

    return hebrewKeyboard;
}

void MainWindow::setNewKeyboard() {
    if (indexOfLanguage == 0) {
        currKeyboard = getBelarusianKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    } else if (indexOfLanguage == 1) {
        currKeyboard = getGermanKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    } else if (indexOfLanguage == 2) {
        currKeyboard = getFrenchKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    } else if (indexOfLanguage == 3) {
        currKeyboard = getEnglishKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    } else if (indexOfLanguage == 4) {
        currKeyboard = getChinesseKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    } else if (indexOfLanguage == 5) {
        currKeyboard = getArabicKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    } else if (indexOfLanguage == 6) {
        currKeyboard = getHebrewKeyboard();
        ui->forText->setAlignment(Qt::AlignLeft);
    }

    setNewBoard();
    ui->forText->clear();
    timer->stop();
    setFocus();
}

void MainWindow::setNewBoard() {
    int index;
    if (!currCaps && !currShift) index = 0;
    if (currShift) index = 1;
    if (currCaps) index = 2;

    QVector<QString> layout = currKeyboard[index];
    for (int i = 0; i < layout.size(); i++) {
        QString key = layout[i];
        QPushButton *button;
        if(i == layout.size() - 1){
            button = this->findChild<QPushButton *>("space");
            if (button) {
                button->setText(key);
            }
            break;
        }
        button = this->findChild<QPushButton *>("bnt_" + QString::number(i));
        if (button) {
            button->setText(key);
        }
    }
}

void MainWindow::on_openFile_clicked()
{
    ui->forText->clear();
    timer->stop();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open"), "//", tr("Text document (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error";
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
    ui->forText->setText(text);
    currString = text;
    setFocus();
}

QPushButton *lastPressedButton = nullptr;

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete ||
        event->key() == Qt::Key_Left || event->key() == Qt::Key_Right ||
        event->key() == Qt::Key_Up || event->key() == Qt::Key_Down ||
        event->key() == Qt::Key_Tab)
    {
        return;
    }

    if (event->key() == Qt::Key_Shift)
    {
        ui->bnt_38->setStyleSheet("background-color: blue; border-radius: 20px; border: 2px solid #094065;");
        ui->bnt_49->setStyleSheet("background-color: blue; border-radius: 20px; border: 2px solid #094065;");
        currShift = true;
        setNewBoard();
        return;
    } else if (event->key() == Qt::Key_CapsLock) {
        currCaps = !currCaps;
        setNewBoard();
        if (currCaps) {
            ui->bnt_26->setStyleSheet("background-color: blue; border-radius: 20px; border: 2px solid #094065;");
        } else {
            ui->bnt_26->setStyleSheet("border-radius: 20px; border: 2px solid #094065; background-color: rgb(246, 245, 244);");
        }
    } else if (event->key() == Qt::Key_Space) {
        currSpace = !currSpace;
        if (currSpace) {
            ui->space->setStyleSheet("background-color: red; border-radius: 20px; border: 2px solid #094065;");
        }
    } else {
        QString key = event->text();
        for (int i = 0; i < currKeyboard[0].size(); i++) {
            if (currKeyboard[0][i] == key || currKeyboard[1][i] == key || currKeyboard[2][i] == key) {
                QPushButton *button = this->findChild<QPushButton *>("bnt_" + QString::number(i));
                if (button)
                {
                    button->click();
                    checkIsCorrectSymbol(button->text());
                }
                break;
            }
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Shift) {
        ui->bnt_38->setStyleSheet("border-radius: 20px; border: 2px solid #094065; background-color: rgb(246, 245, 244);");
        ui->bnt_49->setStyleSheet("border-radius: 20px; border: 2px solid #094065; background-color: rgb(246, 245, 244);");
        currShift = false;
        setNewBoard();
    }
    if (event->key() == Qt::Key_Space) {
        ui->space->setStyleSheet("border-radius: 20px; border: 2px solid #094065; background-color: rgb(246, 245, 244);");
        currSpace = false;
    }
}

void MainWindow::changeColorOfText(const QColor &color)
{
    QPalette palette = ui->forText->palette();
    palette.setColor(QPalette::Text, color);
    ui->forText->setPalette(palette);
}

void MainWindow::checkIsCorrectSymbol(QString ch)
{
    if (ch == ui->forText->text())
    {
        cntCorrectSymbol++;
        changeColorOfText(Qt::green);
    }
    else changeColorOfText(Qt::red);
    cntAllSmb++;
    currIndOfText++;
}

