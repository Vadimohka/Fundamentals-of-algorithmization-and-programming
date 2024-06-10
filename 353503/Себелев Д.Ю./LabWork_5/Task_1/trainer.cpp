#include "trainer.h"
#include "ui_trainer.h"

#include <QPalette>
#include <QThread>
#include <QMessageBox>

enum Time {
    FIFTEEN,
    THIRTY,
    SIXTY
};

Trainer::Trainer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Trainer),
    wordGenerator(new WordGenerator()),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    setFocusPolicy(Qt::StrongFocus);
    ui->textEdit->setFocusPolicy(Qt::NoFocus);

    ui->timer_label->setText(QString::number(time));

    updateButtonLanguage(BELARUSIAN);
    updateTrainingText(BELARUSIAN);
    initButtons();

    red.setForeground(Qt::red);
    red.setFontUnderline(true);
    green.setForeground(Qt::darkGreen);
    grey.setForeground(Qt::lightGray);

    connect(ui->lang_box, SIGNAL(currentIndexChanged(int)), this, SLOT(updateLanguage(int)));
    connect(ui->time_cmbbox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeTime(int)));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(changeLetterColor(QString)));
}

Trainer::~Trainer()
{
    delete ui;
    delete wordGenerator;
    delete stats;
}


void Trainer::updateLanguage(int LangIndex)
{
    if (isRunning) stopTraining();

    switch (LangIndex) {
    case BELARUSIAN:
        updateButtonLanguage(BELARUSIAN);
        updateTrainingText(BELARUSIAN);
        break;
    case RUSSIAN:
        updateButtonLanguage(RUSSIAN);
        updateTrainingText(RUSSIAN);
        break;
    case ENGLISH:
        updateButtonLanguage(ENGLISH);
        updateTrainingText(ENGLISH);
        break;
    case GERMAN:
        updateButtonLanguage(GERMAN);
        updateTrainingText(GERMAN);
        break;
    case FRENCH:
        updateButtonLanguage(FRENCH);
        updateTrainingText(FRENCH);
        break;
    case CHINESE:
        updateButtonLanguage(CHINESE);
        updateTrainingText(CHINESE);
        break;
    case ARABIC:
        updateButtonLanguage(ARABIC);
        updateTrainingText(ARABIC);
        break;
    case HEBREW:
        updateButtonLanguage(HEBREW);
        updateTrainingText(HEBREW);
        break;
    default:
        break;
    }
}

void Trainer::updateButtonLanguage(int LangIndex)
{
    if (LangIndex == BELARUSIAN) {
        ui->Q_btn->setText("Й");
        ui->W_btn->setText("Ц");
        ui->E_btn->setText("У");
        ui->R_btn->setText("К");
        ui->T_btn->setText("Е");
        ui->Y_btn->setText("Н");
        ui->U_btn->setText("Г");
        ui->I_btn->setText("Ш");
        ui->O_btn->setText("Ў");
        ui->P_btn->setText("З");
        ui->squareBracetOpen_btn->setText("Х");
        ui->squareBracetClose_btn->setText("'");
        ui->A_btn->setText("Ф");
        ui->S_btn->setText("Ы");
        ui->D_btn->setText("В");
        ui->F_btn->setText("А");
        ui->G_btn->setText("П");
        ui->H_btn->setText("Р");
        ui->J_btn->setText("О");
        ui->K_btn->setText("Л");
        ui->L_btn->setText("Д");
        ui->semicolon_btn->setText("Ж");
        ui->quotation_btn->setText("Э");
        ui->Z_btn->setText("Я");
        ui->X_btn->setText("Ч");
        ui->C_btn->setText("С");
        ui->V_btn->setText("М");
        ui->B_btn->setText("І");
        ui->N_btn->setText("Т");
        ui->M_btn->setText("Ь");
        ui->comma_btn->setText("Б");
        ui->dot_btn->setText("Ю");
        ui->slash_btn->setText(".");
    }
    else if (LangIndex == RUSSIAN) {
        ui->Q_btn->setText("Й");
        ui->W_btn->setText("Ц");
        ui->E_btn->setText("У");
        ui->R_btn->setText("К");
        ui->T_btn->setText("Е");
        ui->Y_btn->setText("Н");
        ui->U_btn->setText("Г");
        ui->I_btn->setText("Ш");
        ui->O_btn->setText("Щ");
        ui->P_btn->setText("З");
        ui->squareBracetOpen_btn->setText("Х");
        ui->squareBracetClose_btn->setText("Ъ");
        ui->A_btn->setText("Ф");
        ui->S_btn->setText("Ы");
        ui->D_btn->setText("В");
        ui->F_btn->setText("А");
        ui->G_btn->setText("П");
        ui->H_btn->setText("Р");
        ui->J_btn->setText("О");
        ui->K_btn->setText("Л");
        ui->L_btn->setText("Д");
        ui->semicolon_btn->setText("Ж");
        ui->quotation_btn->setText("Э");
        ui->Z_btn->setText("Я");
        ui->X_btn->setText("Ч");
        ui->C_btn->setText("С");
        ui->V_btn->setText("М");
        ui->B_btn->setText("И");
        ui->N_btn->setText("Т");
        ui->M_btn->setText("Ь");
        ui->comma_btn->setText("Б");
        ui->dot_btn->setText("Ю");
        ui->slash_btn->setText(".");
    }
    else if (LangIndex == ENGLISH) {
        ui->Q_btn->setText("Q");
        ui->W_btn->setText("W");
        ui->E_btn->setText("E");
        ui->R_btn->setText("R");
        ui->T_btn->setText("T");
        ui->Y_btn->setText("Y");
        ui->U_btn->setText("U");
        ui->I_btn->setText("I");
        ui->O_btn->setText("O");
        ui->P_btn->setText("P");
        ui->squareBracetOpen_btn->setText("[");
        ui->squareBracetClose_btn->setText("]");
        ui->A_btn->setText("A");
        ui->S_btn->setText("S");
        ui->D_btn->setText("D");
        ui->F_btn->setText("F");
        ui->G_btn->setText("G");
        ui->H_btn->setText("H");
        ui->J_btn->setText("J");
        ui->K_btn->setText("K");
        ui->L_btn->setText("L");
        ui->semicolon_btn->setText(";");
        ui->quotation_btn->setText("'");
        ui->Z_btn->setText("Z");
        ui->X_btn->setText("X");
        ui->C_btn->setText("C");
        ui->V_btn->setText("V");
        ui->B_btn->setText("B");
        ui->N_btn->setText("N");
        ui->M_btn->setText("M");
        ui->comma_btn->setText(",");
        ui->dot_btn->setText(".");
        ui->slash_btn->setText("/");
    }
    else if (LangIndex == GERMAN) {
        ui->Q_btn->setText("Q");
        ui->W_btn->setText("W");
        ui->E_btn->setText("E");
        ui->R_btn->setText("R");
        ui->T_btn->setText("T");
        ui->Y_btn->setText("Z");
        ui->U_btn->setText("U");
        ui->I_btn->setText("I");
        ui->O_btn->setText("O");
        ui->P_btn->setText("P");
        ui->squareBracetOpen_btn->setText("Ü");
        ui->squareBracetClose_btn->setText("+");
        ui->A_btn->setText("A");
        ui->S_btn->setText("S");
        ui->D_btn->setText("D");
        ui->F_btn->setText("F");
        ui->G_btn->setText("G");
        ui->H_btn->setText("H");
        ui->J_btn->setText("J");
        ui->K_btn->setText("K");
        ui->L_btn->setText("L");
        ui->semicolon_btn->setText("Ö");
        ui->quotation_btn->setText("Ä");
        ui->Z_btn->setText("Y");
        ui->X_btn->setText("X");
        ui->C_btn->setText("C");
        ui->V_btn->setText("V");
        ui->B_btn->setText("B");
        ui->N_btn->setText("N");
        ui->M_btn->setText("M");
        ui->comma_btn->setText(",");
        ui->dot_btn->setText(".");
        ui->slash_btn->setText("-");
    }
    else if (LangIndex == FRENCH) {
        ui->Q_btn->setText("A");
        ui->W_btn->setText("Z");
        ui->E_btn->setText("E");
        ui->R_btn->setText("R");
        ui->T_btn->setText("T");
        ui->Y_btn->setText("Y");
        ui->U_btn->setText("U");
        ui->I_btn->setText("I");
        ui->O_btn->setText("O");
        ui->P_btn->setText("P");
        ui->squareBracetOpen_btn->setText("^");
        ui->squareBracetClose_btn->setText("$");
        ui->A_btn->setText("Q");
        ui->S_btn->setText("S");
        ui->D_btn->setText("D");
        ui->F_btn->setText("F");
        ui->G_btn->setText("G");
        ui->H_btn->setText("H");
        ui->J_btn->setText("J");
        ui->K_btn->setText("K");
        ui->L_btn->setText("L");
        ui->semicolon_btn->setText("M");
        ui->quotation_btn->setText("Ù");
        ui->Z_btn->setText("W");
        ui->X_btn->setText("X");
        ui->C_btn->setText("C");
        ui->V_btn->setText("V");
        ui->B_btn->setText("B");
        ui->N_btn->setText("N");
        ui->M_btn->setText(",");
        ui->comma_btn->setText(";");
        ui->dot_btn->setText(":");
        ui->slash_btn->setText("!");
    }
    else if (LangIndex == CHINESE) {
        ui->Q_btn->setText("Q");
        ui->W_btn->setText("W");
        ui->E_btn->setText("E");
        ui->R_btn->setText("R");
        ui->T_btn->setText("T");
        ui->Y_btn->setText("Y");
        ui->U_btn->setText("U");
        ui->I_btn->setText("I");
        ui->O_btn->setText("O");
        ui->P_btn->setText("P");
        ui->squareBracetOpen_btn->setText("[");
        ui->squareBracetClose_btn->setText("]");
        ui->A_btn->setText("A");
        ui->S_btn->setText("S");
        ui->D_btn->setText("D");
        ui->F_btn->setText("F");
        ui->G_btn->setText("G");
        ui->H_btn->setText("H");
        ui->J_btn->setText("J");
        ui->K_btn->setText("K");
        ui->L_btn->setText("L");
        ui->semicolon_btn->setText(";");
        ui->quotation_btn->setText("'");
        ui->Z_btn->setText("Z");
        ui->X_btn->setText("X");
        ui->C_btn->setText("C");
        ui->V_btn->setText("V");
        ui->B_btn->setText("B");
        ui->N_btn->setText("N");
        ui->M_btn->setText("M");
        ui->comma_btn->setText(",");
        ui->dot_btn->setText(".");
        ui->slash_btn->setText("/");
    }
    else if (LangIndex == ARABIC) {
        ui->Q_btn->setText("ض");
        ui->W_btn->setText("ص");
        ui->E_btn->setText("ث");
        ui->R_btn->setText("ق");
        ui->T_btn->setText("ف");
        ui->Y_btn->setText("غ");
        ui->U_btn->setText("ع");
        ui->I_btn->setText("ه");
        ui->O_btn->setText("خ");
        ui->P_btn->setText("ح");
        ui->squareBracetOpen_btn->setText("ج");
        ui->squareBracetClose_btn->setText("د");
        ui->A_btn->setText("ش");
        ui->S_btn->setText("س");
        ui->D_btn->setText("ي");
        ui->F_btn->setText("ب");
        ui->G_btn->setText("ل");
        ui->H_btn->setText("ا");
        ui->J_btn->setText("ت");
        ui->K_btn->setText("ن");
        ui->L_btn->setText("م");
        ui->semicolon_btn->setText("ك");
        ui->quotation_btn->setText("ط");
        ui->Z_btn->setText("ظ");
        ui->X_btn->setText("ز");
        ui->C_btn->setText("ر");
        ui->V_btn->setText("ذ");
        ui->B_btn->setText("ؤ");
        ui->N_btn->setText("ء");
        ui->M_btn->setText("ئ");
        ui->comma_btn->setText("و");
        ui->dot_btn->setText("ز");
        ui->slash_btn->setText("ظ");
    }
    else if (LangIndex == HEBREW) {
        ui->Q_btn->setText("/");
        ui->W_btn->setText("'");
        ui->E_btn->setText("ק");
        ui->R_btn->setText("ר");
        ui->T_btn->setText("א");
        ui->Y_btn->setText("ט");
        ui->U_btn->setText("ו");
        ui->I_btn->setText("ן");
        ui->O_btn->setText("ם");
        ui->P_btn->setText("פ");
        ui->squareBracetOpen_btn->setText("[");
        ui->squareBracetClose_btn->setText("]");
        ui->A_btn->setText("ש");
        ui->S_btn->setText("ד");
        ui->D_btn->setText("ג");
        ui->F_btn->setText("כ");
        ui->G_btn->setText("ע");
        ui->H_btn->setText("י");
        ui->J_btn->setText("ח");
        ui->K_btn->setText("ל");
        ui->L_btn->setText("ך");
        ui->semicolon_btn->setText("ף");
        ui->quotation_btn->setText(",");
        ui->Z_btn->setText("ז");
        ui->X_btn->setText("ס");
        ui->C_btn->setText("ב");
        ui->V_btn->setText("ה");
        ui->B_btn->setText("נ");
        ui->N_btn->setText("מ");
        ui->M_btn->setText("צ");
        ui->comma_btn->setText("ת");
        ui->dot_btn->setText("ץ");
        ui->slash_btn->setText(".");
    }
}

void Trainer::updateTrainingText(int LangIndex)
{
    charIndex = 0;

    QStringList textForTraining = wordGenerator->shuffleWords(LangIndex);

    // Set spaces between words
    QString text = "";

    for (int i = 0; i < textForTraining.size(); i++) {
        text += textForTraining[i] + " ";
    }

    ui->textEdit->setTextColor(Qt::lightGray);
    ui->textEdit->setText(text);
}

void Trainer::initButtons()
{
    buttons.append(ui->Q_btn);
    buttons.append(ui->W_btn);
    buttons.append(ui->E_btn);
    buttons.append(ui->R_btn);
    buttons.append(ui->T_btn);
    buttons.append(ui->Y_btn);
    buttons.append(ui->U_btn);
    buttons.append(ui->I_btn);
    buttons.append(ui->O_btn);
    buttons.append(ui->P_btn);
    buttons.append(ui->squareBracetOpen_btn);
    buttons.append(ui->squareBracetClose_btn);
    buttons.append(ui->A_btn);
    buttons.append(ui->S_btn);
    buttons.append(ui->D_btn);
    buttons.append(ui->F_btn);
    buttons.append(ui->G_btn);
    buttons.append(ui->H_btn);
    buttons.append(ui->J_btn);
    buttons.append(ui->K_btn);
    buttons.append(ui->L_btn);
    buttons.append(ui->semicolon_btn);
    buttons.append(ui->quotation_btn);
    buttons.append(ui->Z_btn);
    buttons.append(ui->X_btn);
    buttons.append(ui->C_btn);
    buttons.append(ui->V_btn);
    buttons.append(ui->B_btn);
    buttons.append(ui->N_btn);
    buttons.append(ui->M_btn);
    buttons.append(ui->comma_btn);
    buttons.append(ui->slash_btn);
}

void Trainer::startTraining()
{
    charIndex = 0;
    errors = 0;
    isRunning = true;
    timer->start(1000);
}

void Trainer::stopTraining()
{
    isRunning = false;
    timer->stop();
    ui->timer_label->setText(QString::number(time));
    ui->lineEdit->clear();
    showStats();
    updateTrainingText(ui->lang_box->currentIndex());
    QTextCursor cursor(ui->textEdit->document());
    cursor.setPosition(0, QTextCursor::MoveAnchor);
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, charIndex);
    cursor.setCharFormat(grey);
    charIndex = -1;
}

void Trainer::updateTimer()
{
    int time = ui->timer_label->text().toInt();
    time--;
    ui->timer_label->setText(QString::number(time));

    if (time == 0) {
        stopTraining();
    }
}

void Trainer::changeTime(int TimeIndex)
{
    switch(TimeIndex) {
    case FIFTEEN:
        time = 15;
        break;
    case THIRTY:
        time = 30;
        break;
    case SIXTY:
        time = 60;
    }
    ui->timer_label->setText(QString::number(time));
}

void Trainer::changeLetterColor(QString letter)
{
    if (!isRunning) {
        startTraining();
        isRunning = true;
    }

    if (letter.size() < charIndex) {
        charIndex--;

        QTextCursor cursor(ui->textEdit->document());

        cursor.setPosition(charIndex, QTextCursor::MoveAnchor);

        cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

        cursor.setCharFormat(grey);

        return;
    }

    colorizeButton(letter.at(charIndex));

    QTextCursor cursor(ui->textEdit->document());

    cursor.setPosition(charIndex, QTextCursor::MoveAnchor);

    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

    QChar ch = ui->textEdit->toPlainText().at(charIndex);

    if (ch == letter.at(charIndex)) {
        cursor.setCharFormat(green);
    } else {
        cursor.setCharFormat(red);
        errors++;
    }

    charIndex++;
}

void Trainer::backspaceClicked()
{
    charIndex--;

    QTextCursor cursor(ui->textEdit->document());

    cursor.setPosition(charIndex, QTextCursor::MoveAnchor);

    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

    cursor.setCharFormat(grey);
}

void Trainer::showStats()
{
    stats = new StatsDialog();
    stats->setInfo(errors, (charIndex - errors) * 100 / charIndex, (charIndex - errors) * 12 / time);
    stats->show();
}

void Trainer::colorizeButton(QString letter)
{
    QPushButton* tempBtn = nullptr;
    for (auto &but : buttons) {
        if (but->text() == letter.toUpper()) {
            tempBtn = but;
            QPalette pal;
            pal.setColor(QPalette::Button, QColor(Qt::red));
            tempBtn->setAutoFillBackground(true);
            tempBtn->setPalette(pal);
            tempBtn->update();
        } else if (letter == " ") {
            tempBtn = ui->space_btn;
            QPalette pal;
            pal.setColor(QPalette::Button, QColor(Qt::red));
            tempBtn->setAutoFillBackground(true);
            tempBtn->setPalette(pal);
            tempBtn->update();
        }
    }

    QCoreApplication::processEvents();
    QThread::msleep(30);

    if (tempBtn != nullptr) {
        QPalette pal;
        pal.setColor(QPalette::Button, QColor(Qt::white));
        tempBtn->setAutoFillBackground(true);
        tempBtn->setPalette(pal);
        tempBtn->update();
    }
}
