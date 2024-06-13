#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (auto language : avaliableLanguages)
       ui->languageBox->addItem(language);

    readFromFile(filename);
    ui->timeEdit->setDisplayFormat("HH:mm:ss");
    fillTextEdit();
    fillButMap();
    QTimer* shiftchecker = new QTimer;
    shiftchecker->start(15);
    QObject::connect(shiftchecker, &QTimer::timeout, this, &MainWindow::setShiftModiferState);

    QObject::connect(ui->textEnterEdit, &QTextEdit::textChanged, this, &MainWindow::setCurrentWordFromEdit);
    QObject::connect(ui->textEnterEdit, &QTextEdit::textChanged, this, &MainWindow::calcSpeed);

    setTypingIsCorrect(true);
    QObject::connect(ui->languageBox, &QComboBox::currentIndexChanged, this, &MainWindow::changeLanguage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::fillButMap()
{
    but['q'] = ui->QLetter;
    but['a'] = ui->ALetter;
    but['z'] = ui->ZLetter;
    but['w'] = ui->WLetter;
    but['s'] = ui->SLetter;
    but['x'] = ui->XLetter;
    but['e'] = ui->ELetter;
    but['d'] = ui->DLetter;
    but['c'] = ui->CLetter;
    but['r'] = ui->RLetter;
    but['f'] = ui->FLetter;
    but['v'] = ui->VLetter;
    but['t'] = ui->TLetter;
    but['g'] = ui->GLetter;
    but['b'] = ui->BLetter;
    but['y'] = ui->YLetter;
    but['h'] = ui->HLetter;
    but['n'] = ui->NLetter;
    but['u'] = ui->ULetter;
    but['j'] = ui->JLetter;
    but['m'] = ui->MLetter;
    but['i'] = ui->ILetter;
    but['k'] = ui->KLetter;
    but[','] = ui->CommaLetter;
    but['o'] = ui->OLetter;
    but['l'] = ui->LLetter;
    but['.'] = ui->DotLetter;
    but['p'] = ui->PLetter;
    but[';'] = ui->CommaDotLetter;
    but[':'] = ui->CommaDotLetter;
    but[' '] = ui->SpaceLetter;
    but['\n'] = ui->EnterLetter;
    but['1'] = ui->Letter_1;
    but['2'] = ui->Letter_2;
    but['3'] = ui->Letter_3;
    but['4'] = ui->Letter_4;
    but['5'] = ui->Letter_5;
    but['6'] = ui->Letter_6;
    but['7'] = ui->Letter_7;
    but['8'] = ui->Letter_8;
    but['9'] = ui->Letter_9;
    but['0'] = ui->Letter_0;
    but['/'] = ui->SlashLetter;
    but['?'] = ui->SlashLetter;
    but[QChar(39)] = ui->QuotesLetter;
    but[QChar(34)] = ui->QuotesLetter;
    but[QChar(92)]  = ui->RevSlashLetter;
    but[QChar(124)] = ui->RevSlashLetter;
    but['['] = ui->LeftSquareBracketsLetter;
    but['{'] = ui->LeftSquareBracketsLetter;
    but[']'] = ui->RightSquareBracketsLetter;
    but['}'] = ui->RightSquareBracketsLetter;
    but['('] = ui->Letter_9;
    but[')'] = ui->Letter_0;
    but['-'] = ui->MinusLetter;
    but['_'] = ui->MinusLetter;
    but['='] = ui->EqualsLetter;
    but['+'] = ui->EqualsLetter;
    but['!'] = ui->Letter_1;
    but['@'] = ui->Letter_2;
    but['#'] = ui->Letter_3;
    but['$'] = ui->Letter_4;
    but['%'] = ui->Letter_5;
    but['^'] = ui->Letter_6;
    but['&'] = ui->Letter_7;
    but['*'] = ui->Letter_8;
    but['~'] = ui->ApostrofLetter;
    but['`'] = ui->ApostrofLetter;
    but['<'] = ui->CommaLetter;
    but['>'] = ui->DotLetter;
    but[QChar(254)] = ui->BackspaceLetter;
    but['\t'] = ui->TabLetter;

    //by
    but[QString("й")[0]] = ui->QLetter;
    but[QString("ф")[0]] = ui->ALetter;
    but[QString("я")[0]] = ui->ZLetter;
    but[QString("ц")[0]] = ui->WLetter;
    but[QString("ы")[0]] = ui->SLetter;
    but[QString("ч")[0]] = ui->XLetter;
    but[QString("у")[0]] = ui->ELetter;
    but[QString("в")[0]] = ui->DLetter;
    but[QString("с")[0]] = ui->CLetter;
    but[QString("к")[0]] = ui->RLetter;
    but[QString("а")[0]] = ui->FLetter;
    but[QString("м")[0]] = ui->VLetter;
    but[QString("е")[0]] = ui->TLetter;
    but[QString("п")[0]] = ui->GLetter;
    but[QString("и")[0]] = ui->BLetter;
    but[QString("н")[0]] = ui->YLetter;
    but[QString("р")[0]] = ui->HLetter;
    but[QString("т")[0]] = ui->NLetter;
    but[QString("г")[0]] = ui->ULetter;
    but[QString("о")[0]] = ui->JLetter;
    but[QString("ь")[0]] = ui->MLetter;
    but[QString("ш")[0]] = ui->ILetter;
    but[QString("л")[0]] = ui->KLetter;
    but[QString("б")[0]] = ui->CommaLetter;
    but[QString("щ")[0]] = ui->OLetter;
    but[QString("д")[0]] = ui->LLetter;
    but[QString(".")[0]] = ui->DotLetter;
    but[QString("з")[0]] = ui->PLetter;
    but[QString("ж")[0]] = ui->CommaDotLetter;

    but[QString("э")[0]] = ui->QuotesLetter;
    but[QString("х")[0]] = ui->LeftSquareBracketsLetter;
    but[QString("ъ")[0]] = ui->RightSquareBracketsLetter;
    but[QString("ю")[0]] = ui->DotLetter;

    //but[QChar(34)] = ui->QuotesLetter;
    //but["\"]  = ui->RevSlashLetter;
    but[QChar(124)] = ui->RevSlashLetter;

    //but['}'] = ui->RightSquareBracketsLetter;


}


void MainWindow::readFromFile(QString filename)
{
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
            QString in;
            in = stream.readLine();
            HoleText.push_back(in.split(" ", Qt::SkipEmptyParts));
        }
        file.close();
    }
    ui->timeEdit->setTime(QTime(0, 0));

    sec = 0;
    wordCount = 0;
    timer.start(1000);
    connect(&timer, SIGNAL(timeout()), this, SLOT(slotTimeout()));
    //QTime stratTime = ui->timeEdit->time();

}

void MainWindow::goToNextWord()
{
    if (currentWordInd >= textForTyping.size() - 1) return;

    fillTextEdit(currentLine, ++currentWordInd);
    wordCount++;

}

void MainWindow::goToNextLine()
{
    if (currentLine >= HoleText.size() - 2){
        ui->textFromFile->clear();
        ui->textEnterEdit->setReadOnly(true);
        return;
    }

    fillTextEdit(++currentLine, 0);
    currentWordInd = 0;
    wordCount++;
}


void MainWindow::fillTextEdit(int line, int ind)
{

    //line = 0;
    textForTyping = HoleText[line];
    ui->textFromFile->clear();
    for (int i = 0; i < textForTyping.size(); i++){
        if (i == ind)
            ui->textFromFile->insertHtml("<font color='red'>" + textForTyping.at(i) + "</font>" + " ");
        else
            ui->textFromFile->insertHtml(textForTyping.at(i) + " ");
    }
    QTextCursor cursor = ui->textFromFile->textCursor();
    cursor.movePosition(QTextCursor::End); // Move cursor to the end
    cursor.deletePreviousChar(); // Delete the last character
    //cursor.movePosition(QTextCursor::Start);
}


void MainWindow::setTypingIsCorrect(bool isCorrect)
{
    typingIsCorrect = isCorrect;
    if (typingIsCorrect)
        ui->indicator->setStyleSheet("QLabel { background-color: green; }");
    else
        ui->indicator->setStyleSheet("QLabel { background-color: red; }");
}


void MainWindow::setCurrentWordFromEdit()
{
    if (ui->textEnterEdit->toPlainText().size() == 0){
        setTypingIsCorrect(true);
        return;
    }
    QChar lastSymbol = ui->textEnterEdit->toPlainText().at(ui->textEnterEdit->toPlainText().length() - 1);

    if (ui->textEnterEdit->toPlainText().size() < currentWord.size()){
        buttonClicked(QChar(254));
        currentWord = ui->textEnterEdit->toPlainText();
    }
    else
        buttonClicked(lastSymbol);

    if (lastSymbol == '\t'){
        goBack();
        return;
    }
    if (lastSymbol != ' ' && lastSymbol != '\n'){
        currentWord = ui->textEnterEdit->toPlainText();

        setTypingIsCorrect(textForTyping.at(currentWordInd).startsWith(currentWord));
    }
    else{

        if (textForTyping[currentWordInd] == currentWord){
            currentWord.resize(0);
            ui->textEnterEdit->clear();

            if (lastSymbol == ' ' && currentWordInd != textForTyping.size() - 1){
                goToNextWord();
                currentWord.resize(0);
                ui->textEnterEdit->clear();
            }
            else if (lastSymbol == '\n' && currentWordInd == textForTyping.size() - 1){
                currentWord.resize(0);
                ui->textEnterEdit->clear();
                goToNextLine();

            }
            else{
                goBack();
            }
        }
        else{
            goBack();
        }
    }
}


void MainWindow::setShiftModiferState()
{

    if ((QGuiApplication::queryKeyboardModifiers().testFlag(Qt::ShiftModifier))){
        if (but['1']->text() == "1"){
            but['1']->setText("!");
            but['2']->setText("@");
            but['3']->setText("#");
            but['4']->setText("$");
            but['5']->setText("%");
            but['6']->setText("$");
            but['7']->setText("&&");
            but['8']->setText("*");
            but['9']->setText("(");
            but['0']->setText(")");
            but['-']->setText("_");
            but['=']->setText("+");
            but[',']->setText("<");
            but['.']->setText(">");
            but['/']->setText("?");
            but[';']->setText(":");

            but['[']->setText("{");
            but[']']->setText("}");
            but['`']->setText("~");
            but['|']->setText("|");
            but[QChar(34)]->setText(QString(QChar(34)));
        }
    }
    else if (but['1']->text() == "!"){
        but['1']->setText("1");
        but['2']->setText("2");
        but['3']->setText("3");
        but['4']->setText("4");
        but['5']->setText("5");
        but['6']->setText("6");
        but['7']->setText("7");
        but['8']->setText("8");
        but['9']->setText("9");
        but['0']->setText("0");
        but['-']->setText("-");
        but['=']->setText("=");
        but[',']->setText(",");
        but['.']->setText(".");
        but['/']->setText("/");
        but[';']->setText(";");
        but['[']->setText("[");
        but[']']->setText("]");
        but['`']->setText("1");
        but['|']->setText("/");
        but[QChar(34)]->setText("'");
    }
}


void MainWindow::buttonClicked(QChar letter)
{
    if (lastClickedLetter != QChar(255))
        but[lastClickedLetter.toLower()]->setStyleSheet(lastStyleSheet);

    lastStyleSheet = but[letter.toLower()]->styleSheet();
    but[letter.toLower()]->setStyleSheet("QPushButton{ background-color: white; color: black; text-align:center;}");
    lastClickedLetter = letter;
}


void MainWindow::goBack()
{
    ui->textEnterEdit->setText(currentWord);
    QTextCursor cursor = ui->textEnterEdit->textCursor();
    cursor.movePosition(QTextCursor::End);

    ui->textEnterEdit->setTextCursor(cursor);
}

void MainWindow::on_openFile_clicked()
{
    textForTyping.resize(0);
    HoleText.resize(0);
    readFromFile(QFileDialog::getOpenFileName(nullptr, "Open Files", "/home/lidskae/Lab5_Klava", "txt file (*.txt);;"));

    fillTextEdit();
    fillButMap();
}

void MainWindow::changeLanguage()
{
    if (ui->languageBox->currentIndex() == 1){
        but[QString("й")[0]]->setText("Й");
        but[QString("ц")[0]]->setText("Ц");
        but[QString("у")[0]]->setText("У");
        but[QString("к")[0]]->setText("К");
        but[QString("е")[0]]->setText("Е");
        but[QString("н")[0]]->setText("Н");
        but[QString("г")[0]]->setText("Г");
        but[QString("ш")[0]]->setText("Ш");
        but[QString("щ")[0]]->setText("Щ");
        but[QString("з")[0]]->setText("З");
        but[QString("х")[0]]->setText("Х");
        but[QString("ъ")[0]]->setText("Ъ");
        but[QString("ф")[0]]->setText("Ф");
        but[QString("ы")[0]]->setText("Ы");
        but[QString("в")[0]]->setText("В");
        but[QString("а")[0]]->setText("А");
        but[QString("п")[0]]->setText("П");
        but[QString("р")[0]]->setText("Р");
        but[QString("о")[0]]->setText("О");
        but[QString("л")[0]]->setText("Л");
        but[QString("д")[0]]->setText("Д");
        but[QString("ж")[0]]->setText("Ж");
        but[QString("э")[0]]->setText("Э");
        but[QString("я")[0]]->setText("Я");
        but[QString("ч")[0]]->setText("Ч");
        but[QString("с")[0]]->setText("С");
        but[QString("м")[0]]->setText("М");
        but[QString("и")[0]]->setText("И");
        but[QString("т")[0]]->setText("Т");
        but[QString("ь")[0]]->setText("Ь");
        but[QString("б")[0]]->setText("Б");
        but[QString("ю")[0]]->setText("Ю");
        but[QString(".")[0]]->setText(".");
    }
    if (ui->languageBox->currentIndex() == 0){
        but['q']->setText("Q");
        but['w']->setText("W");
        but['e']->setText("E");
        but['r']->setText("R");
        but['t']->setText("T");
        but['y']->setText("Y");
        but['u']->setText("U");
        but['i']->setText("I");
        but['o']->setText("O");
        but['p']->setText("P");
        but['[']->setText("[");
        but[']']->setText("]");
        but['a']->setText("A");
        but['s']->setText("S");
        but['d']->setText("D");
        but['f']->setText("F");
        but['g']->setText("G");
        but['h']->setText("H");
        but['j']->setText("J");
        but['k']->setText("K");
        but['l']->setText("L");
        but[';']->setText(";");
        but[QChar(32)]->setText(QString(QChar(32)));
        but['z']->setText("Z");
        but['x']->setText("X");
        but['c']->setText("C");
        but['v']->setText("V");
        but['b']->setText("B");
        but['n']->setText("N");
        but['m']->setText("M");
        but[',']->setText(",");
        but['.']->setText(".");
        but['/']->setText("/");

    }
}

void MainWindow::calcSpeed()
{
    ui->speedEdit->setText(QString::number(60 * (double)wordCount / sec));
}

void MainWindow::slotTimeout()
{
    qDebug() << "ok";
    ui->timeEdit->setTime(ui->timeEdit->time().addSecs(1));
    sec++;
}

