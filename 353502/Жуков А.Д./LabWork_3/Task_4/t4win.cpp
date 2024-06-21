#include "t4win.h"
#include "ui_t4win.h"

enum LayersXOffset
{
    layA = 110,
    layB = 100,
    layC = 90,
    layD = 80,
    layE = 70,
    layF = 60,
    layG = 50,
    layH = 40,
    layI = 30,
    layJ = 20,
    layK = 10,
    layL = 0,
};

constexpr int BUTTON_H = 50;
constexpr int BUTTON_MAX_W = 360;
constexpr int ASCII_A = 64;
constexpr int MS = 1000;
constexpr int SLIDER_STEP = 25;
constexpr int FIRST_TOWER_X = 40;
constexpr int SECOND_TOWER_X = 450;
constexpr int THIRD_TOWER_X = 860;
constexpr int FIRST_RING_Y = 670;

T4Win::T4Win(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::T4Win)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    Towers firstStep;
    for (char i = ASCII_A + 3; i != ASCII_A; i--)
    {
        firstStep.first.append(i);
    }
    steps.append(firstStep);
    visualize();
    hanoi(ui->spinBox->value(), 1, 3, 2);
}

T4Win::~T4Win()
{
    delete ui;
}


void T4Win::hanoi(int n, int from, int to, int buffer) {
    if (steps.first().first == steps.last().third)
    {
        ui->solveButton->setEnabled(true);
        ui->spinBox->setEnabled(true);
    }
    if (n > 0) {
        hanoi(n - 1, from, buffer, to);

        steps << steps.last();

        QChar buf;
        switch (from) {
        case 1:
            buf = steps.last().first.back();
            steps.last().first.chop(1);
            break;
        case 2:
            buf = steps.last().second.back();
            steps.last().second.chop(1);
            break;
        case 3:
            buf = steps.last().third.back();
            steps.last().third.chop(1);
            break;
        default:
            return;
        }

        switch (to) {
        case 1:
            steps.last().first.append(buf);
            break;
        case 2:
            steps.last().second.append(buf);
            break;
        case 3:
            steps.last().third.append(buf);
            break;
        default:
            return;
        }

        return hanoi(n - 1, buffer, to, from);
    }
}


void T4Win::visualize()
{
    clearList(tower1Buttons);
    clearList(tower2Buttons);
    clearList(tower3Buttons);

    for (int y = FIRST_RING_Y, x = FIRST_TOWER_X, w = BUTTON_MAX_W, i = 0, tower = 1; i != -1; i++)
    {
        if (i > steps[step].first.length() - 1 && x < 300)
        {
            y = FIRST_RING_Y;
            x = SECOND_TOWER_X;
            i = -1;
            tower++;
            continue;
        }
        else if (i > steps[step].second.length() - 1 && x > 300 && x < 800)
        {
            y = FIRST_RING_Y;
            x = THIRD_TOWER_X;
            i = -1;
            tower++;
            continue;
        }
        else if (i > steps[step].third.length() - 1 && x > 800)
        {
            break;
        }
        y -= BUTTON_H;

        QPushButton* butt = new QPushButton(this);

        QChar currentSymbol;
        switch (tower) {
        case 1:
            x = FIRST_TOWER_X;
            currentSymbol = steps[step].first[i];
            tower1Buttons.push_back(butt);
            break;
        case 2:
            x = SECOND_TOWER_X;
            currentSymbol = steps[step].second[i];
            tower2Buttons.push_back(butt);
            break;
        case 3:
            x = THIRD_TOWER_X;
            currentSymbol = steps[step].third[i];
            tower3Buttons.push_back(butt);
            break;
        }

        switch (currentSymbol.toLatin1()) {
        case 'A':
            x += layA; w = BUTTON_MAX_W - layA * 2;
            butt->setStyleSheet("background-color: Plum;");
            break;
        case 'B':
            x += layB; w = BUTTON_MAX_W - layB * 2;
            butt->setStyleSheet("background-color: Violet;");
            break;
        case 'C':
            x += layC; w = BUTTON_MAX_W - layC * 2;
            butt->setStyleSheet("background-color: Orchid;");
            break;
        case 'D':
            x += layD; w = BUTTON_MAX_W - layD * 2;
            butt->setStyleSheet("background-color: Fuchsia;");
            break;
        case 'E':
            x += layE; w = BUTTON_MAX_W - layE * 2;
            butt->setStyleSheet("background-color: Magenta;");
            break;
        case 'F':
            x += layF; w = BUTTON_MAX_W - layF * 2;
            butt->setStyleSheet("background-color: MediumOrchid;");
            break;
        case 'G':
            x += layG; w = BUTTON_MAX_W - layG * 2;
            butt->setStyleSheet("background-color: MediumPurple;");
            break;
        case 'H':
            x += layH; w = BUTTON_MAX_W - layH * 2;
            butt->setStyleSheet("background-color: BlueViolet;");
            break;
        case 'I':
            x += layI; w = BUTTON_MAX_W - layI * 2;
            butt->setStyleSheet("background-color: DarkViolet;");
            break;
        case 'J':
            x += layJ; w = BUTTON_MAX_W - layJ * 2;
            butt->setStyleSheet("background-color: DarkOrchid;");
            break;
        case 'K':
            x += layK; w = BUTTON_MAX_W - layK * 2;
            butt->setStyleSheet("background-color: DarkMagenta;");
            break;
        case 'L':
            x += layL; w = BUTTON_MAX_W - layL * 2;
            butt->setStyleSheet("background-color: Purple;");
            break;
        }

        butt->setGeometry(x, y, w, BUTTON_H);
        butt->setEnabled(false);

        butt->show();
    }
}


void T4Win::animate()
{
    if (step >= steps.length())
    {
        timer->stop();
        ui->spinBox->setEnabled(true);
        ui->solveButton->setEnabled(true);
        ui->previousStepButton->setEnabled(true);
        ui->nextStepButton->setEnabled(true);
        ui->lineEdit->setEnabled(true);
        ui->lineEdit->setText(QString::number(steps.length()));
        return;
    }

    QPushButton* buff;
    int fromID, toID, fromTower, toTower;
    int x, y, w;

    if (steps[step - 1].first != steps[step].first) {
        if (steps[step - 1].first > steps[step].first) {
            fromID = steps[step - 1].first.length() - 1;
            fromTower = 1;
        }
        else {
            toID = steps[step].first.length() - 1;
            toTower = 1;
        }
    }
    if (steps[step - 1].second != steps[step].second) {
        if (steps[step - 1].second > steps[step].second) {
            fromID = steps[step - 1].second.length() - 1;
            fromTower = 2;
        }
        else {
            toID = steps[step].second.length() - 1;
            toTower = 2;
        }
    }
    if (steps[step - 1].third != steps[step].third) {
        if (steps[step - 1].third > steps[step].third) {
            fromID = steps[step - 1].third.length() - 1;
            fromTower = 3;
        }
        else {
            toID = steps[step].third.length() - 1;
            toTower = 3;
        }
    }

    switch (fromTower) {
    case 1:
        animation = new QPropertyAnimation(tower1Buttons[fromID], "geometry");
        animation->setStartValue(tower1Buttons[fromID]->geometry());
        buff = tower1Buttons[fromID];
        w = tower1Buttons[fromID]->width();
        break;
    case 2:
        animation = new QPropertyAnimation(tower2Buttons[fromID], "geometry");
        animation->setStartValue(tower2Buttons[fromID]->geometry());
        buff = tower2Buttons[fromID];
        w = tower2Buttons[fromID]->width();
        break;
    case 3:
        animation = new QPropertyAnimation(tower3Buttons[fromID], "geometry");
        animation->setStartValue(tower3Buttons[fromID]->geometry());
        buff = tower3Buttons[fromID];
        w = tower3Buttons[fromID]->width();
        break;
    }

    switch (toTower) {
    case 1:
        x = FIRST_TOWER_X;
        tower1Buttons.insert(toID, buff);
        break;
    case 2:
        x = SECOND_TOWER_X;
        tower2Buttons.insert(toID, buff);
        break;
    case 3:
        x = THIRD_TOWER_X;
        tower3Buttons.insert(toID, buff);
        break;
    }

    x += (BUTTON_MAX_W - w) / 2;
    y = FIRST_RING_Y - (toID + 1) * BUTTON_H;

    buff->setGeometry(x, y, w, BUTTON_H);

    animation->setDuration(timer->interval());
    animation->setEndValue(buff->geometry());
    animation->start();

    //qDebug() << fromTower << toTower << fromID << toID;
}


void T4Win::clearList(QList<QPushButton *> & towerButtons)
{
    while (!towerButtons.empty())
    {
        qDebug() << towerButtons.size();
        towerButtons.last()->hide();
        towerButtons.removeLast();
        //towerButtons.resize(towerButtons.size() - 1);
    }
}

///////////////SLOTS

void T4Win::on_spinBox_valueChanged(int arg1)
{
    steps.clear();
    Towers firstStep;
    for (char i = ASCII_A + arg1; i != ASCII_A; i--)
    {
        firstStep.first.append(i);
    }
    steps.append(firstStep);

    ui->solveButton->setEnabled(false);
    ui->spinBox->setEnabled(false);
    ui->lineEdit->setText("1");

    step = 0;
    visualize();
    hanoi(ui->spinBox->value(), 1, 3, 2);
}

void T4Win::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setText(QString::number(((double)(int)(value/SLIDER_STEP * SLIDER_STEP))/MS));
    timer->setInterval(value);
    ui->horizontalSlider->setValue(value/SLIDER_STEP * SLIDER_STEP);
}


void T4Win::on_lineEdit_textEdited(const QString &arg1)
{
    bool ok;
    if (arg1.toInt(&ok) > 0 && ok && arg1.toInt() < steps.size())
    {
        step = arg1.toInt() - 1;
        visualize();
    }
}


void T4Win::on_solveButton_clicked()
{
    step = 0;
    visualize();

    ui->solveButton->setEnabled(false);
    ui->spinBox->setEnabled(false);
    ui->previousStepButton->setEnabled(false);
    ui->nextStepButton->setEnabled(false);
    ui->lineEdit->setEnabled(false);

    timer = new QTimer(this);
    timer->start(ui->horizontalSlider->value());

    connect(timer, QTimer::timeout, this, [this]
            {
                step++;
                animate();
            });
}


void T4Win::on_previousStepButton_clicked()
{
    if (ui->lineEdit->text().toInt() > 1)
    {
        ui->lineEdit->setText(QString::number(ui->lineEdit->text().toInt() - 1));
        step = ui->lineEdit->text().toInt() - 1;
        qDebug() << step << steps.length();
        visualize();
    }
}


void T4Win::on_nextStepButton_clicked()
{
    if (ui->lineEdit->text().toInt() < steps.size())
    {
        ui->lineEdit->setText(QString::number(ui->lineEdit->text().toInt() + 1));
        step = ui->lineEdit->text().toInt() - 1;
        qDebug() << step << steps.length();
        visualize();
    }
}

