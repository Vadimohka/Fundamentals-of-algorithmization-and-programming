#include "keyboard.h"
Keyboard::Keyboard()
{
    isCorrectWord = true;

    this->setSpacing(3);
    this->setContentsMargins(0,0,0,0);
    this->setAlignment(Qt::AlignCenter);

    initializeKeyButtonVector();

    firstRow = new QHBoxLayout();
    secondRow = new QHBoxLayout();
    thirdRow = new QHBoxLayout();
    fourthRow = new QHBoxLayout();
    fifthRow = new QHBoxLayout();

    for(int i = 0; i < 13; i++)
    {
        firstRow->addWidget(buttons[i]);
    }
    for(int i = 13; i < 13 + 14; i++)
    {
        if(buttons[i] == tabButton) buttons[i]->setFixedSize(75, 50);
        secondRow->addWidget(buttons[i]);
    }
    for(int i = 27; i < 27 + 13; i++)
    {
        if(buttons[i] == capsLockButton) buttons[i]->setFixedSize(88, 50);
        if(buttons[i] == enterButton) buttons[i]->setFixedSize(88, 50);
        thirdRow->addWidget(buttons[i]);
    }
    for(int i = 40; i < 40 + 12; i++)
    {
        if(buttons[i] == leftShiftButton) buttons[i]->setFixedSize(113, 50);
        if(buttons[i] == rightShiftButton) buttons[i]->setFixedSize(113, 50);
        fourthRow->addWidget(buttons[i]);
    }
    for(int i = 52; i < 52 + 8; i++)
    {
        if(buttons[i] == spaceButton) buttons[i]->setFixedSize(375, 50);
        fifthRow->addWidget(buttons[i]);
    }

    this->addLayout(firstRow);
    this->addLayout(secondRow);
    this->addLayout(thirdRow);
    this->addLayout(fourthRow);
    this->addLayout(fifthRow);
}


void Keyboard::initializeKeyButtonVector()
{
    graveButton = new QPushButton("`");
    num1Button = new QPushButton("1");
    num2Button = new QPushButton("2");
    num3Button = new QPushButton("3");
    num4Button = new QPushButton("4");
    num5Button = new QPushButton("5");
    num6Button = new QPushButton("6");
    num7Button = new QPushButton("7");
    num8Button = new QPushButton("8");
    num9Button = new QPushButton("9");
    num0Button = new QPushButton("0");
    minusButton = new QPushButton("-");
    equalButton = new QPushButton("=");

    idsOfButtons[49] = graveButton;
    idsOfButtons[10] = num1Button;
    idsOfButtons[11] = num2Button;
    idsOfButtons[12] = num3Button;
    idsOfButtons[13] = num4Button;
    idsOfButtons[14] = num5Button;
    idsOfButtons[15] = num6Button;
    idsOfButtons[16] = num7Button;
    idsOfButtons[17] = num8Button;
    idsOfButtons[18] = num9Button;
    idsOfButtons[19] = num0Button;
    idsOfButtons[20] = minusButton;
    idsOfButtons[21] = equalButton;


    tabButton = new QPushButton("Tab");
    qButton = new QPushButton("q");
    wButton = new QPushButton("w");
    eButton = new QPushButton("e");
    rButton = new QPushButton("r");
    tButton = new QPushButton("t");
    yButton = new QPushButton("y");
    uButton = new QPushButton("u");
    iButton = new QPushButton("i");
    oButton = new QPushButton("o");
    pButton = new QPushButton("p");
    leftSquareScopeButton = new QPushButton("[");
    rightSquareScopeButton = new QPushButton("]");
    backSlashButton = new QPushButton("\\");

    idsOfButtons[23] = tabButton;
    idsOfButtons[24] = qButton;
    idsOfButtons[25] = wButton;
    idsOfButtons[26] = eButton;
    idsOfButtons[27] = rButton;
    idsOfButtons[28] = tButton;
    idsOfButtons[29] = yButton;
    idsOfButtons[30] = uButton;
    idsOfButtons[31] = iButton;
    idsOfButtons[32] = oButton;
    idsOfButtons[33] = pButton;
    idsOfButtons[34] = leftSquareScopeButton;
    idsOfButtons[35] = rightSquareScopeButton;
    idsOfButtons[51] = backSlashButton;


    idsOfButtons[23] = tabButton;
    idsOfButtons[24] = qButton;
    idsOfButtons[25] = wButton;
    idsOfButtons[26] = eButton;
    idsOfButtons[27] = rButton;
    idsOfButtons[28] = tButton;
    idsOfButtons[29] = yButton;
    idsOfButtons[30] = uButton;
    idsOfButtons[31] = iButton;
    idsOfButtons[32] = oButton;
    idsOfButtons[33] = pButton;
    idsOfButtons[34] = leftSquareScopeButton;
    idsOfButtons[35] = rightSquareScopeButton;
    idsOfButtons[51] = backSlashButton;



    capsLockButton = new QPushButton("Caps Lock");
    aButton = new QPushButton("a");
    sButton = new QPushButton("s");
    dButton = new QPushButton("d");
    fButton = new QPushButton("f");
    gButton = new QPushButton("g");
    hButton = new QPushButton("h");
    jButton = new QPushButton("j");
    kButton = new QPushButton("k");
    lButton = new QPushButton("l");
    semicolonButton = new QPushButton(";");
    apostropheButton = new QPushButton("'");
    enterButton = new QPushButton("Enter");

    idsOfButtons[66] = capsLockButton;
    idsOfButtons[38] = aButton;
    idsOfButtons[39] = sButton;
    idsOfButtons[40] = dButton;
    idsOfButtons[41] = fButton;
    idsOfButtons[42] = gButton;
    idsOfButtons[43] = hButton;
    idsOfButtons[44] = jButton;
    idsOfButtons[45] = kButton;
    idsOfButtons[46] = lButton;
    idsOfButtons[47] = semicolonButton;
    idsOfButtons[48] = apostropheButton;
    idsOfButtons[36] = enterButton;


    leftShiftButton = new QPushButton("Shift");
    zButton = new QPushButton("z");
    xButton = new QPushButton("x");
    cButton = new QPushButton("c");
    vButton = new QPushButton("v");
    bButton = new QPushButton("b");
    nButton = new QPushButton("n");
    mButton = new QPushButton("m");
    commaButton = new QPushButton(",");
    dotButton = new QPushButton(".");
    slashButton = new QPushButton("/");
    rightShiftButton = new QPushButton("Shift");

    idsOfButtons[50] = leftShiftButton;
    idsOfButtons[52] = zButton;
    idsOfButtons[53] = xButton;
    idsOfButtons[54] = cButton;
    idsOfButtons[55] = vButton;
    idsOfButtons[56] = bButton;
    idsOfButtons[57] = nButton;
    idsOfButtons[58] = mButton;
    idsOfButtons[59] = commaButton;
    idsOfButtons[60] = dotButton;
    idsOfButtons[61] = slashButton;
    idsOfButtons[62] = rightShiftButton;


    leftCtrlButton = new QPushButton("Ctrl");
    leftFnButton = new QPushButton("Fn");
    winButton = new QPushButton("⊞");
    leftAltButton = new QPushButton("Alt");
    spaceButton = new QPushButton("");
    rightAltButton = new QPushButton("Alt");
    rightFnButton = new QPushButton("Fn");
    rightCtrlButton  = new QPushButton("Ctrl");

    idsOfButtons[37] = leftCtrlButton;
    idsOfButtons[64] = leftAltButton;
    idsOfButtons[65] = spaceButton;
    idsOfButtons[108] = rightAltButton;
    idsOfButtons[105] = rightCtrlButton;


    buttons.push_back(graveButton);
    buttons.push_back(num1Button);
    buttons.push_back(num2Button);
    buttons.push_back(num3Button);
    buttons.push_back(num4Button);
    buttons.push_back(num5Button);
    buttons.push_back(num6Button);
    buttons.push_back(num7Button);
    buttons.push_back(num8Button);
    buttons.push_back(num9Button);
    buttons.push_back(num0Button);
    buttons.push_back(minusButton);
    buttons.push_back(equalButton);


    buttons.push_back(tabButton);
    buttons.push_back(qButton);
    buttons.push_back(wButton);
    buttons.push_back(eButton);
    buttons.push_back(rButton);
    buttons.push_back(tButton);
    buttons.push_back(yButton);
    buttons.push_back(uButton);
    buttons.push_back(iButton);
    buttons.push_back(oButton);
    buttons.push_back(pButton);
    buttons.push_back(leftSquareScopeButton);
    buttons.push_back(rightSquareScopeButton);
    buttons.push_back(backSlashButton);


    buttons.push_back(capsLockButton);
    buttons.push_back(aButton);
    buttons.push_back(sButton);
    buttons.push_back(dButton);
    buttons.push_back(fButton);
    buttons.push_back(gButton);
    buttons.push_back(hButton);
    buttons.push_back(jButton);
    buttons.push_back(kButton);
    buttons.push_back(lButton);
    buttons.push_back(semicolonButton);
    buttons.push_back(apostropheButton);
    buttons.push_back(enterButton);



    buttons.push_back(leftShiftButton);
    buttons.push_back(zButton);
    buttons.push_back(xButton);
    buttons.push_back(cButton);
    buttons.push_back(vButton);
    buttons.push_back(bButton);
    buttons.push_back(nButton);
    buttons.push_back(mButton);
    buttons.push_back(commaButton);
    buttons.push_back(dotButton);
    buttons.push_back(slashButton);
    buttons.push_back(rightShiftButton);


    buttons.push_back(leftCtrlButton);
    buttons.push_back(leftFnButton);
    buttons.push_back(winButton);
    buttons.push_back(leftAltButton);
    buttons.push_back(spaceButton);
    buttons.push_back(rightAltButton);
    buttons.push_back(rightFnButton);
    buttons.push_back(rightCtrlButton);

    for(int i = 0; i < buttons.size(); i++)
    {
        buttons[i]->setFixedSize(50,50);
        buttons[i]->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    }


}
void Keyboard::setBelaruisan()
{
    graveButton->setText("ё");
    num1Button->setText("1");
    num2Button->setText("2");
    num3Button->setText("3");
    num4Button->setText("4");
    num5Button->setText("5");
    num6Button->setText("6");
    num7Button->setText("7");
    num8Button->setText("8");
    num9Button->setText("9");
    num0Button->setText("0");
    minusButton->setText("-");
    equalButton->setText("=");


    qButton->setText("й");
    wButton->setText("ц");
    eButton->setText("у");
    rButton->setText("к");
    tButton->setText("е");
    yButton->setText("н");
    uButton->setText("г");
    iButton->setText("ш");
    oButton->setText("ў");
    pButton->setText("з");

    leftSquareScopeButton->setText("х");
    rightSquareScopeButton->setText("'");
    backSlashButton->setText("\\");

    aButton->setText("ф");
    sButton->setText("ы");
    dButton->setText("в");
    fButton->setText("а");
    gButton->setText("п");
    hButton->setText("р");
    jButton->setText("о");
    kButton->setText("л");
    lButton->setText("д");
    semicolonButton->setText("ж");
    apostropheButton->setText("э");

    zButton->setText("я");
    xButton->setText("ч");
    cButton->setText("с");
    vButton->setText("м");
    bButton->setText("і");
    nButton->setText("т");
    mButton->setText("ь");
    commaButton->setText("б");
    dotButton->setText("ю");
    slashButton->setText(".");
}
void Keyboard::setGerman()
{
    graveButton->setText("^");
    num1Button->setText("1");
    num2Button->setText("2");
    num3Button->setText("3");
    num4Button->setText("4");
    num5Button->setText("5");
    num6Button->setText("6");
    num7Button->setText("7");
    num8Button->setText("8");
    num9Button->setText("9");
    num0Button->setText("0");
    minusButton->setText("ß");
    equalButton->setText("´");

    qButton->setText("q");
    wButton->setText("w");
    eButton->setText("e");
    rButton->setText("r");
    tButton->setText("t");
    yButton->setText("z");
    uButton->setText("u");
    iButton->setText("i");
    oButton->setText("o");
    pButton->setText("p");
    leftSquareScopeButton->setText("ü");
    rightSquareScopeButton->setText("+");
    backSlashButton->setText("#");

    aButton->setText("a");
    sButton->setText("s");
    dButton->setText("d");
    fButton->setText("f");
    gButton->setText("g");
    hButton->setText("h");
    jButton->setText("j");
    kButton->setText("k");
    lButton->setText("l");
    semicolonButton->setText("ö");
    apostropheButton->setText("ä");

    zButton->setText("y");
    xButton->setText("x");
    cButton->setText("c");
    vButton->setText("v");
    bButton->setText("b");
    nButton->setText("n");
    mButton->setText("m");
    commaButton->setText(",");
    dotButton->setText(".");
    slashButton->setText("-");
}
void Keyboard::setFrench()
{
    graveButton->setText("²");
    num1Button->setText("&&");
    num2Button->setText("é");
    num3Button->setText("\"");
    num4Button->setText("'");
    num5Button->setText("(");
    num6Button->setText("-");
    num7Button->setText("è");
    num8Button->setText("_");
    num9Button->setText("ç");
    num0Button->setText("à");
    minusButton->setText(")");
    equalButton->setText("=");

    qButton->setText("a");
    wButton->setText("z");
    eButton->setText("e");
    rButton->setText("r");
    tButton->setText("t");
    yButton->setText("y");
    uButton->setText("u");
    iButton->setText("i");
    oButton->setText("o");
    pButton->setText("p");
    leftSquareScopeButton->setText("^");
    rightSquareScopeButton->setText("$");
    backSlashButton->setText("*");

    aButton->setText("q");
    sButton->setText("s");
    dButton->setText("d");
    fButton->setText("f");
    gButton->setText("g");
    hButton->setText("h");
    jButton->setText("j");
    kButton->setText("k");
    lButton->setText("l");
    semicolonButton->setText("m");
    apostropheButton->setText("ù");

    zButton->setText("w");
    xButton->setText("x");
    cButton->setText("c");
    vButton->setText("v");
    bButton->setText("b");
    nButton->setText("n");
    mButton->setText(",");
    commaButton->setText(";");
    dotButton->setText(":");
    slashButton->setText("!");
}
void Keyboard::setArabic()
{
    graveButton->setText("ذ");
    num1Button->setText("1");
    num2Button->setText("2");
    num3Button->setText("3");
    num4Button->setText("4");
    num5Button->setText("5");
    num6Button->setText("6");
    num7Button->setText("7");
    num8Button->setText("8");
    num9Button->setText("9");
    num0Button->setText("0");
    minusButton->setText("-");
    equalButton->setText("=");

    qButton->setText("ض");
    wButton->setText("ص");
    eButton->setText("ث");
    rButton->setText("ق");
    tButton->setText("ف");
    yButton->setText("غ");
    uButton->setText("ع");
    iButton->setText("ه");
    oButton->setText("خ");
    pButton->setText("ح");
    leftSquareScopeButton->setText("ج");
    rightSquareScopeButton->setText("د");
    backSlashButton->setText("\\");

    aButton->setText("ش");
    sButton->setText("س");
    dButton->setText("ي");
    fButton->setText("ب");
    gButton->setText("ل");
    hButton->setText("ا");
    jButton->setText("ت");
    kButton->setText("ن");
    lButton->setText("م");
    semicolonButton->setText("ك");
    apostropheButton->setText("ط");

    zButton->setText("ئ");
    xButton->setText("ء");
    cButton->setText("ؤ");
    vButton->setText("ر");
    bButton->setText("ﻻ");
    nButton->setText("ى");
    mButton->setText("ة");
    commaButton->setText("و");
    dotButton->setText("ز");
    slashButton->setText("ظ");
}
void Keyboard::setHebrew()
{
    graveButton->setText(";");
    num1Button->setText("1");
    num2Button->setText("2");
    num3Button->setText("3");
    num4Button->setText("4");
    num5Button->setText("5");
    num6Button->setText("6");
    num7Button->setText("7");
    num8Button->setText("8");
    num9Button->setText("9");
    num0Button->setText("0");
    minusButton->setText("-");
    equalButton->setText("=");

    qButton->setText("/");
    wButton->setText("'");
    eButton->setText("ק");
    rButton->setText("ר");
    tButton->setText("א");
    yButton->setText("ט");
    uButton->setText("ו");
    iButton->setText("ן");
    oButton->setText("ם");
    pButton->setText("פ");
    leftSquareScopeButton->setText("]");
    rightSquareScopeButton->setText("[");
    backSlashButton->setText("\\");

    aButton->setText("ש");
    sButton->setText("ד");
    dButton->setText("ג");
    fButton->setText("כ");
    gButton->setText("ע");
    hButton->setText("י");
    jButton->setText("ח");
    kButton->setText("ל");
    lButton->setText("ך");
    semicolonButton->setText("ף");
    apostropheButton->setText(",");

    zButton->setText("ז");
    xButton->setText("ס");
    cButton->setText("ב");
    vButton->setText("ה");
    bButton->setText("נ");
    nButton->setText("מ");
    mButton->setText("צ");
    commaButton->setText("ת");
    dotButton->setText("ץ");
    slashButton->setText(".");
}
void Keyboard::setChinese()
{
    graveButton->setText("`");
    num1Button->setText("1");
    num2Button->setText("2");
    num3Button->setText("3");
    num4Button->setText("4");
    num5Button->setText("5");
    num6Button->setText("6");
    num7Button->setText("7");
    num8Button->setText("8");
    num9Button->setText("9");
    num0Button->setText("0");
    minusButton->setText("-");
    equalButton->setText("=");

    tabButton->setText("Tab");
    qButton->setText("q");
    wButton->setText("w");
    eButton->setText("e");
    rButton->setText("r");
    tButton->setText("t");
    yButton->setText("y");
    uButton->setText("u");
    iButton->setText("i");
    oButton->setText("o");
    pButton->setText("p");
    leftSquareScopeButton->setText("[");
    rightSquareScopeButton->setText("]");
    backSlashButton->setText("\\");

    capsLockButton->setText("Caps Lock");
    aButton->setText("a");
    sButton->setText("s");
    dButton->setText("d");
    fButton->setText("f");
    gButton->setText("g");
    hButton->setText("h");
    jButton->setText("j");
    kButton->setText("k");
    lButton->setText("l");
    semicolonButton->setText(";");
    apostropheButton->setText("'");
    enterButton->setText("Enter");

    leftShiftButton->setText("Shift");
    zButton->setText("z");
    xButton->setText("x");
    cButton->setText("c");
    vButton->setText("v");
    bButton->setText("b");
    nButton->setText("n");
    mButton->setText("m");
    commaButton->setText(",");
    dotButton->setText(".");
    slashButton->setText("/");
    rightShiftButton->setText("Shift");

    leftCtrlButton->setText("Ctrl");
    leftFnButton->setText("Fn");
    winButton->setText("⊞");
    leftAltButton->setText("Alt");
    spaceButton->setText("");
    rightAltButton->setText("Alt");
    rightFnButton->setText("Fn");
    rightCtrlButton->setText("Ctrl");
}
void Keyboard::clear()
{
    graveButton->setText("");
    num1Button->setText("");
    num2Button->setText("");
    num3Button->setText("");
    num4Button->setText("");
    num5Button->setText("");
    num6Button->setText("");
    num7Button->setText("");
    num8Button->setText("");
    num9Button->setText("");
    num0Button->setText("");
    minusButton->setText("");
    equalButton->setText("");

    qButton->setText("");
    wButton->setText("");
    eButton->setText("");
    rButton->setText("");
    tButton->setText("");
    yButton->setText("");
    uButton->setText("");
    iButton->setText("");
    oButton->setText("");
    pButton->setText("");
    leftSquareScopeButton->setText("");
    rightSquareScopeButton->setText("");
    backSlashButton->setText("");

    aButton->setText("");
    sButton->setText("");
    dButton->setText("");
    fButton->setText("");
    gButton->setText("");
    hButton->setText("");
    jButton->setText("");
    kButton->setText("");
    lButton->setText("");
    semicolonButton->setText("");
    apostropheButton->setText("");

    zButton->setText("");
    xButton->setText("");
    cButton->setText("");
    vButton->setText("");
    bButton->setText("");
    nButton->setText("");
    mButton->setText("");
    commaButton->setText("");
    dotButton->setText("");
    slashButton->setText("");
}
void Keyboard::setTextEdit(QTextEdit *textEdit)
{
    this->textEdit = textEdit;
}

void Keyboard::keyPressEvent(QKeyEvent *event)
{
    bool isFinded = false;
    int index;

    for(int i = 0; i < buttons.size(); i++)
    {
        if(buttons[i]->text() == event->text())
        {
            isFinded = true;
            index = i;

            break;
        }
    }

    if(isFinded || (event->key() != Qt::Key_unknown && idsOfButtons.contains(event->nativeScanCode())))
    {
        if(isFinded) buttons[index]->animateClick();
        else idsOfButtons[event->nativeScanCode()]->animateClick();

        // if(event->key() != Qt::Key_CapsLock && event->key() != Qt::Key_Shift && event->key() != Qt::Key_Backspace && event->key() != Qt::Key_Tab
        //     && event->key() != Qt::Key_Enter && event->key() != Qt::Key_Control && event->key() != Qt::Key_Alt && event->modifiers() != Qt::GroupSwitchModifier
        //     && !(event->modifiers() == (Qt::AltModifier | Qt::GroupSwitchModifier))
        //     && !(event->modifiers() == (Qt::ShiftModifier | Qt::MetaModifier))
        //     && !(event->modifiers() == (Qt::ShiftModifier | Qt::GroupSwitchModifier)))
        // {
        //     QTextCharFormat format;
        //     QTextCursor cursor = textEdit->textCursor();
        //     QString text = textEdit->toPlainText();


        //     if(cursor.position() < text.size())
        //     {
        //         cursor.setPosition(cursor.position() + 1, QTextCursor::KeepAnchor);

        //         if(QChar(text[cursor.position() - 1]) == event->text())
        //         {
        //             format.setForeground(QColor("#52F24D")); // Устанавливаем красный цвет
        //             cursor.setCharFormat(format);

        //             emit inputCorrectChar();
        //         }
        //         else
        //         {
        //             if(!QString(" ,.;:()[]{}。").contains(text[cursor.position() - 1]))
        //             {
        //                 isCorrectWord = false;
        //             }

        //             format.setForeground(QColor("#D20000")); // Устанавливаем красный цвет
        //             cursor.setCharFormat(format);

        //             emit inputIncorrectChar();
        //         }

        //         cursor.setPosition(cursor.position());
        //         textEdit->setTextCursor(cursor);
        //     }

        //     if(cursor.position() == text.size()) //&& text[text.size() - 1] != '.'
        //     {
        //         if(isCorrectWord) emit oneWordWasInputed();
        //         emit endOfInput();
        //     }

        //     if(cursor.position() < text.size() &&
        //         !QString(" ,.;:()[]{}。").contains(text[cursor.position() - 1]) &&
        //         QString(" ,.;:()[]{}。").contains(text[cursor.position()]))
        //     {
        //         if(isCorrectWord) emit oneWordWasInputed();

        //         isCorrectWord = true;
        //     }
        // }

        //else if(event->key() == Qt::Key_CapsLock)
        if(event->key() == Qt::Key_CapsLock)
        {
            for(int i = 0; i < buttons.size(); i++)
            {
                if(buttons[i] != tabButton && buttons[i] != capsLockButton && buttons[i] != enterButton
                    && buttons[i] != tabButton && buttons[i] != leftShiftButton && buttons[i] != rightShiftButton
                    && buttons[i] != leftCtrlButton && buttons[i] != rightCtrlButton
                    && buttons[i] != leftAltButton && buttons[i] != rightAltButton && buttons[i] != leftFnButton && buttons[i] != rightFnButton
                    && buttons[i] != minusButton)
                {
                    if(buttons[i]->text().isLower()) buttons[i]->setText((buttons[i]->text()).toUpper());
                    else buttons[i]->setText((buttons[i]->text()).toLower());
                }
            }
        }

    }
}
