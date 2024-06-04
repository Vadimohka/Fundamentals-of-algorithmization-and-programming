#include "keyboardwidget.h"
#include "ui_keyboardwidget.h"

KeyboardWidget::KeyboardWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KeyboardWidget)
{
    ui->setupUi(this);

    buttonsMap = QMap<int, QPushButton*>{
        {49, ui->buttonSt},
        {10, ui->button1},
        {11, ui->button2},
        {12, ui->button3},
        {13, ui->button4},
        {14, ui->button5},
        {15, ui->button6},
        {16, ui->button7},
        {17, ui->button8},
        {18, ui->button9},
        {19, ui->button0},
        {20, ui->buttonMin},
        {21, ui->buttonEq},
        {24, ui->buttonq},
        {25, ui->buttonw},
        {26, ui->buttone},
        {27, ui->buttonr},
        {28, ui->buttont},
        {29, ui->buttony},
        {30, ui->buttonu},
        {31, ui->buttoni},
        {32, ui->buttono},
        {33, ui->buttonp},
        {34, ui->buttonSqBrOp},
        {35, ui->buttonSqBrCl},
        {51, ui->buttonBackSlash},
        {38, ui->buttona},
        {39, ui->buttons},
        {40, ui->buttond},
        {41, ui->buttonf},
        {42, ui->buttong},
        {43, ui->buttonh},
        {44, ui->buttonj},
        {45, ui->buttonk},
        {46, ui->buttonl},
        {47, ui->buttonDots},
        {48, ui->buttonBr},
        {52, ui->buttonz},
        {53, ui->buttonx},
        {54, ui->buttonc},
        {55, ui->buttonv},
        {56, ui->buttonb},
        {57, ui->buttonn},
        {58, ui->buttonm},
        {59, ui->buttonComma},
        {60, ui->buttonDot},
        {61, ui->buttonSlash},
        {100, ui->buttonSpace}
    };

    for (auto key : buttonsMap.keys())
        if (key != 100) buttonsMap[key]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    for (auto button : buttonsMap.values()) {
        connect(button, &QPushButton::clicked, this, &KeyboardWidget::handleButtonClicked);
    }

    ui->gridLayout->setHorizontalSpacing(0);
    ui->gridLayout->setVerticalSpacing(0);

    setFocusPolicy(Qt::StrongFocus);
}

KeyboardWidget::~KeyboardWidget()
{
    delete ui;
}

void KeyboardWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        QPushButton *button = buttonsMap[100];
        button->setStyleSheet("background-color: green");
        QTimer::singleShot(200, button, [button]() {
            button->setStyleSheet("");
        });
        parentWidget()->setFocus();
        return;
    }
    int key = event->nativeScanCode();
    if (buttonsMap.contains(key)) {
        QPushButton *button = buttonsMap[key];
        button->setStyleSheet("background-color: green");
        QTimer::singleShot(200, button, [button]() {
            button->setStyleSheet("");
        });
        parentWidget()->setFocus();
        return;
    }
    key = event->text().toInt();
    if (buttonsMap.contains(key)) {
        QPushButton *button = buttonsMap[key];
        button->setStyleSheet("background-color: green");
        QTimer::singleShot(200, button, [button]() {
            button->setStyleSheet("");
        });
    }
    parentWidget()->setFocus();
}

void KeyboardWidget::setKeys(int local)
{
    for (auto key : buttonsMap.keys()) buttonsMap[key]->setText(keys[local][codeSymbolNumber[key]]);
}

void KeyboardWidget::handleButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    int buttonIndex = buttonsMap.key(button);

    QKeyEvent *keyEvent = new QKeyEvent(QEvent::KeyPress, 0, Qt::KeyboardModifier::NoModifier, QString::number(buttonIndex));

    QCoreApplication::postEvent(parentWidget(), keyEvent);
    parentWidget()->setFocus();
}
