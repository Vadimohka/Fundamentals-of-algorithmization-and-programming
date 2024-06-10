#include "keyboard.h"
#include "ui_keyboard.h"

Keyboard::Keyboard(QWidget *parent) :
        QWidget(parent), ui(new Ui::Keyboard) {
    ui->setupUi(this);
    destroyAllFocuses();

    isShift = false;

    language = German;

    languages = {
            //German
            {
                    {"^1234567890ß´qwertzuiopü+asdfghjklöäyxcvbnm,.-"},
                    {"°!\"§$%&/()=?`QWERTZUIOPÜ*ASDFGHJKLÖÄYXCVBNM;:_"}
            },
            //French
            {
                    {"²&é\"'(-è_çà)=azertyuiop^$qsdfghjklmùwxcvbn,;:!"},
                    {"~!@#$%^&*)(_+QWERTYUIOP}{ASDFGHJKL:\"ZXCVBNM><?"}
            },
            //Arabic
            {
                    {"١٢٣٤٥٦٧٨٩٠-=\\ضصثقفغعهخحجشسيبلاتنمكطئءرزظدوجرلاتوةظط."},
                    {"ّ!@#$%^&*)(_+ًٌَُلإإ`÷×؛<>ٍِ][لأأـ،/:\"~ْ}{لآآ',.؟"}/*{"!@#$%^&*()_+|ًٍَُإيِلأآـْ]ِّ\""}*/
            },
            //Chinese
            {
                    {"`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./"},
                    {"āáǎàēéěèīíǐìōóǒòūúǔùǖǘǚǜQWRTYOPSDFGHJKLZXCVBNM"}
            },
            //Belorussian
            {
                    {"ё1234567890-=йцукенгшўзх'фывапролджэячсмітьбю."},
                    {"Ё!\"№;%:?*()_+ЙЦУКЕНГШЎЗХ'ФЫВАПРОЛДЖЭЯЧСМІТЬБЮ,"}
            },
            //Hebrew
            {
                    {";123456789-=/'קראטוןםפ][שדגכעיחלךף,זסבהנמצתץ."},
                    {"~!@#$%^&*)(_+QWERTYUIOP}{ASDFGHJKL:\"ZXCVBNM><?"}
            }
    };

    updateKeyboard();
}

Keyboard::~Keyboard() {
    delete ui;
}

void Keyboard::updateKeyboard() {
    ui->extra_button->setText(QString(languages[language][isShift][0]));
    ui->number_button_1->setText(QString(languages[language][isShift][1]));
    ui->number_button_2->setText(QString(languages[language][isShift][2]));
    ui->number_button_3->setText(QString(languages[language][isShift][3]));
    ui->number_button_4->setText(QString(languages[language][isShift][4]));
    ui->number_button_5->setText(QString(languages[language][isShift][5]));
    ui->number_button_6->setText(QString(languages[language][isShift][6]));
    ui->number_button_7->setText(QString(languages[language][isShift][7]));
    ui->number_button_8->setText(QString(languages[language][isShift][8]));
    ui->number_button_9->setText(QString(languages[language][isShift][9]));
    ui->number_button_10->setText(QString(languages[language][isShift][10]));
    ui->number_button_11->setText(QString(languages[language][isShift][11]));
    ui->number_button_12->setText(QString(languages[language][isShift][12]));
    ui->symbol_button_1->setText(QString(languages[language][isShift][13]));
    ui->symbol_button_2->setText(QString(languages[language][isShift][14]));
    ui->symbol_button_3->setText(QString(languages[language][isShift][15]));
    ui->symbol_button_4->setText(QString(languages[language][isShift][16]));
    ui->symbol_button_5->setText(QString(languages[language][isShift][17]));
    ui->symbol_button_6->setText(QString(languages[language][isShift][18]));
    ui->symbol_button_7->setText(QString(languages[language][isShift][19]));
    ui->symbol_button_8->setText(QString(languages[language][isShift][20]));
    ui->symbol_button_9->setText(QString(languages[language][isShift][21]));
    ui->symbol_button_10->setText(QString(languages[language][isShift][22]));
    ui->symbol_button_11->setText(QString(languages[language][isShift][23]));
    ui->symbol_button_12->setText(QString(languages[language][isShift][24]));
    ui->symbol_button_13->setText(QString(languages[language][isShift][25]));
    ui->symbol_button_14->setText(QString(languages[language][isShift][26]));
    ui->symbol_button_15->setText(QString(languages[language][isShift][27]));
    ui->symbol_button_16->setText(QString(languages[language][isShift][28]));
    ui->symbol_button_17->setText(QString(languages[language][isShift][29]));
    ui->symbol_button_18->setText(QString(languages[language][isShift][30]));
    ui->symbol_button_19->setText(QString(languages[language][isShift][31]));
    ui->symbol_button_20->setText(QString(languages[language][isShift][32]));
    ui->symbol_button_21->setText(QString(languages[language][isShift][33]));
    ui->symbol_button_22->setText(QString(languages[language][isShift][34]));
    ui->symbol_button_23->setText(QString(languages[language][isShift][35]));
    ui->symbol_button_24->setText(QString(languages[language][isShift][36]));
    ui->symbol_button_25->setText(QString(languages[language][isShift][37]));
    ui->symbol_button_26->setText(QString(languages[language][isShift][38]));
    ui->symbol_button_27->setText(QString(languages[language][isShift][39]));
    ui->symbol_button_28->setText(QString(languages[language][isShift][40]));
    ui->symbol_button_29->setText(QString(languages[language][isShift][41]));
    ui->symbol_button_30->setText(QString(languages[language][isShift][42]));
    ui->symbol_button_31->setText(QString(languages[language][isShift][43]));
    ui->symbol_button_32->setText(QString(languages[language][isShift][44]));
    ui->symbol_button_33->setText(QString(languages[language][isShift][45]));
}

void Keyboard::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_QuoteLeft:
        case Qt::Key_AsciiTilde:
            emit ui->extra_button->pressed();
            break;
        case Qt::Key_1:
        case Qt::Key_Exclam:
            emit ui->number_button_1->pressed();
            break;
        case Qt::Key_2:
        case Qt::Key_At:
            emit ui->number_button_2->pressed();
            break;
        case Qt::Key_3:
        case Qt::Key_NumberSign:
            emit ui->number_button_3->pressed();
            break;
        case Qt::Key_4:
        case Qt::Key_Dollar:
            emit ui->number_button_4->pressed();
            break;
        case Qt::Key_5:
        case Qt::Key_Percent:
            emit ui->number_button_5->pressed();
            break;
        case Qt::Key_6:
        case Qt::Key_AsciiCircum:
            emit ui->number_button_6->pressed();
            break;
        case Qt::Key_7:
        case Qt::Key_Ampersand:
            emit ui->number_button_7->pressed();
            break;
        case Qt::Key_8:
        case Qt::Key_Asterisk:
            emit ui->number_button_8->pressed();
            break;
        case Qt::Key_9:
        case Qt::Key_ParenLeft:
            emit ui->number_button_9->pressed();
            break;
        case Qt::Key_0:
        case Qt::Key_ParenRight:
            emit ui->number_button_10->pressed();
            break;
        case Qt::Key_Minus:
        case Qt::Key_Underscore:
            emit ui->number_button_11->pressed();
            break;
        case Qt::Key_Equal:
        case Qt::Key_Plus:
            emit ui->number_button_12->pressed();
            break;
        case Qt::Key_Shift:
            emit ui->shift_button_1->pressed();
            emit ui->shift_button_2->pressed();
            break;
        case Qt::Key_Space:
            emit ui->space_button->pressed();
            break;
        case Qt::Key_Q:
            emit ui->symbol_button_1->pressed();
            break;
        case Qt::Key_W:
            emit ui->symbol_button_2->pressed();
            break;
        case Qt::Key_E:
            emit ui->symbol_button_3->pressed();
            break;
        case Qt::Key_R:
            emit ui->symbol_button_4->pressed();
            break;
        case Qt::Key_T:
            emit ui->symbol_button_5->pressed();
            break;
        case Qt::Key_Y:
            emit ui->symbol_button_6->pressed();
            break;
        case Qt::Key_U:
            emit ui->symbol_button_7->pressed();
            break;
        case Qt::Key_I:
            emit ui->symbol_button_8->pressed();
            break;
        case Qt::Key_O:
            emit ui->symbol_button_9->pressed();
            break;
        case Qt::Key_P:
            emit ui->symbol_button_10->pressed();
            break;
        case Qt::Key_BraceLeft:
        case Qt::Key_BracketLeft:
            emit ui->symbol_button_11->pressed();
            break;
        case Qt::Key_BraceRight:
        case Qt::Key_BracketRight:
            emit ui->symbol_button_12->pressed();
            break;
        case Qt::Key_A:
            emit ui->symbol_button_13->pressed();
            break;
        case Qt::Key_S:
            emit ui->symbol_button_14->pressed();
            break;
        case Qt::Key_D:
            emit ui->symbol_button_15->pressed();
            break;
        case Qt::Key_F:
            emit ui->symbol_button_16->pressed();
            break;
        case Qt::Key_G:
            emit ui->symbol_button_17->pressed();
            break;
        case Qt::Key_H:
            emit ui->symbol_button_18->pressed();
            break;
        case Qt::Key_J:
            emit ui->symbol_button_19->pressed();
            break;
        case Qt::Key_K:
            emit ui->symbol_button_20->pressed();
            break;
        case Qt::Key_L:
            emit ui->symbol_button_21->pressed();
            break;
        case Qt::Key_Semicolon:
        case Qt::Key_Colon:
            emit ui->symbol_button_22->pressed();
            break;
        case Qt::Key_QuoteDbl:
        case Qt::Key_Apostrophe:
            emit ui->symbol_button_23->pressed();
            break;
        case Qt::Key_Z:
            emit ui->symbol_button_24->pressed();
            break;
        case Qt::Key_X:
            emit ui->symbol_button_25->pressed();
            break;
        case Qt::Key_C:
            emit ui->symbol_button_26->pressed();
            break;
        case Qt::Key_V:
            emit ui->symbol_button_27->pressed();
            break;
        case Qt::Key_B:
            emit ui->symbol_button_28->pressed();
            break;
        case Qt::Key_N:
            emit ui->symbol_button_29->pressed();
            break;
        case Qt::Key_M:
            emit ui->symbol_button_30->pressed();
            break;
        case Qt::Key_Less:
        case Qt::Key_Comma:
            emit ui->symbol_button_31->pressed();
            break;
        case Qt::Key_Greater:
        case Qt::Key_Period:
            emit ui->symbol_button_32->pressed();
            break;
        case Qt::Key_Slash:
        case Qt::Key_Question:
            emit ui->symbol_button_33->pressed();
            break;
    }
    QWidget::keyPressEvent(event);
}

void Keyboard::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_QuoteLeft:
        case Qt::Key_AsciiTilde:
            emit ui->extra_button->released();
            break;
        case Qt::Key_1:
        case Qt::Key_Exclam:
            emit ui->number_button_1->released();
            break;
        case Qt::Key_2:
        case Qt::Key_At:
            emit ui->number_button_2->released();
            break;
        case Qt::Key_3:
        case Qt::Key_NumberSign:
            emit ui->number_button_3->released();
            break;
        case Qt::Key_4:
        case Qt::Key_Dollar:
            emit ui->number_button_4->released();
            break;
        case Qt::Key_5:
        case Qt::Key_Percent:
            emit ui->number_button_5->released();
            break;
        case Qt::Key_6:
        case Qt::Key_AsciiCircum:
            emit ui->number_button_6->released();
            break;
        case Qt::Key_7:
        case Qt::Key_Ampersand:
            emit ui->number_button_7->released();
            break;
        case Qt::Key_8:
        case Qt::Key_Asterisk:
            emit ui->number_button_8->released();
            break;
        case Qt::Key_9:
        case Qt::Key_ParenLeft:
            emit ui->number_button_9->released();
            break;
        case Qt::Key_0:
        case Qt::Key_ParenRight:
            emit ui->number_button_10->released();
            break;
        case Qt::Key_Minus:
        case Qt::Key_Underscore:
            emit ui->number_button_11->released();
            break;
        case Qt::Key_Equal:
        case Qt::Key_Plus:
            emit ui->number_button_12->released();
            break;
        case Qt::Key_Shift:
            emit ui->shift_button_1->released();
            emit ui->shift_button_2->released();
            break;
        case Qt::Key_Space:
            emit ui->space_button->released();
            break;
        case Qt::Key_Q:
            emit ui->symbol_button_1->released();
            break;
        case Qt::Key_W:
            emit ui->symbol_button_2->released();
            break;
        case Qt::Key_E:
            emit ui->symbol_button_3->released();
            break;
        case Qt::Key_R:
            emit ui->symbol_button_4->released();
            break;
        case Qt::Key_T:
            emit ui->symbol_button_5->released();
            break;
        case Qt::Key_Y:
            emit ui->symbol_button_6->released();
            break;
        case Qt::Key_U:
            emit ui->symbol_button_7->released();
            break;
        case Qt::Key_I:
            emit ui->symbol_button_8->released();
            break;
        case Qt::Key_O:
            emit ui->symbol_button_9->released();
            break;
        case Qt::Key_P:
            emit ui->symbol_button_10->released();
            break;
        case Qt::Key_BraceLeft:
        case Qt::Key_BracketLeft:
            emit ui->symbol_button_11->released();
            break;
        case Qt::Key_BraceRight:
        case Qt::Key_BracketRight:
            emit ui->symbol_button_12->released();
            break;
        case Qt::Key_A:
            emit ui->symbol_button_13->released();
            break;
        case Qt::Key_S:
            emit ui->symbol_button_14->released();
            break;
        case Qt::Key_D:
            emit ui->symbol_button_15->released();
            break;
        case Qt::Key_F:
            emit ui->symbol_button_16->released();
            break;
        case Qt::Key_G:
            emit ui->symbol_button_17->released();
            break;
        case Qt::Key_H:
            emit ui->symbol_button_18->released();
            break;
        case Qt::Key_J:
            emit ui->symbol_button_19->released();
            break;
        case Qt::Key_K:
            emit ui->symbol_button_20->released();
            break;
        case Qt::Key_L:
            emit ui->symbol_button_21->released();
            break;
        case Qt::Key_Semicolon:
        case Qt::Key_Colon:
            emit ui->symbol_button_22->released();
            break;
        case Qt::Key_QuoteDbl:
        case Qt::Key_Apostrophe:
            emit ui->symbol_button_23->released();
            break;
        case Qt::Key_Z:
            emit ui->symbol_button_24->released();
            break;
        case Qt::Key_X:
            emit ui->symbol_button_25->released();
            break;
        case Qt::Key_C:
            emit ui->symbol_button_26->released();
            break;
        case Qt::Key_V:
            emit ui->symbol_button_27->released();
            break;
        case Qt::Key_B:
            emit ui->symbol_button_28->released();
            break;
        case Qt::Key_N:
            emit ui->symbol_button_29->released();
            break;
        case Qt::Key_M:
            emit ui->symbol_button_30->released();
            break;
        case Qt::Key_Less:
        case Qt::Key_Comma:
            emit ui->symbol_button_31->released();
            break;
        case Qt::Key_Greater:
        case Qt::Key_Period:
            emit ui->symbol_button_32->released();
            break;
        case Qt::Key_Slash:
        case Qt::Key_Question:
            emit ui->symbol_button_33->released();
            break;
    }
    QWidget::keyPressEvent(event);
}


void Keyboard::keyPressed(QPushButton *button, int key) {
    button->setStyleSheet("background-color: grey;");

}
