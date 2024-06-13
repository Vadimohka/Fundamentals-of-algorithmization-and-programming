#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->timerBrowser->setText("00:00");
    currentLanguage = language->getMap(0);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimeout);
    connect(lightningTimer, &QTimer::timeout, this, &MainWindow::onLightningTimerTimeout);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startTraining);
    connect(ui->finishButton, &QPushButton::clicked, this, &MainWindow::finishTraining);

    // push keys into vector

    keys.resize(65);
    //
    keys[0] = ui->key0;
    keys[49] = ui->key49;
    keys[10] = ui->key10;
    keys[11] = ui->key11;
    keys[12] = ui->key12;
    keys[13] = ui->key13;
    keys[14] = ui->key14;
    keys[15] = ui->key15;
    keys[16] = ui->key16;
    keys[17] = ui->key17;
    keys[18] = ui->key18;
    keys[19] = ui->key19;
    keys[20] = ui->key20;
    keys[21] = ui->key21;
    //
    keys[24] = ui->key24;
    keys[25] = ui->key25;
    keys[26] = ui->key26;
    keys[27] = ui->key27;
    keys[28] = ui->key28;
    keys[29] = ui->key29;
    keys[30] = ui->key30;
    keys[31] = ui->key31;
    keys[32] = ui->key32;
    keys[33] = ui->key33;
    keys[34] = ui->key34;
    keys[35] = ui->key35;
    //
    keys[38] = ui->key38;
    keys[39] = ui->key39;
    keys[40] = ui->key40;
    keys[41] = ui->key41;
    keys[42] = ui->key42;
    keys[43] = ui->key43;
    keys[44] = ui->key44;
    keys[45] = ui->key45;
    keys[46] = ui->key46;
    keys[47] = ui->key47;
    keys[48] = ui->key48;
    //
    keys[52] = ui->key52;
    keys[53] = ui->key53;
    keys[54] = ui->key54;
    keys[55] = ui->key55;
    keys[56] = ui->key56;
    keys[57] = ui->key57;
    keys[58] = ui->key58;
    keys[59] = ui->key59;
    keys[60] = ui->key60;
    keys[61] = ui->key61;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    QString letter = "";
    int index = e->nativeScanCode();
    if (e->key() == Qt::Key_Space) index = 0;
    letter.push_back(part[0]);
    if (currentLanguage[index] == letter)
    {
        ui->testBrowser->setStyleSheet(GREEN_COLOR_MODE);
        lightningTimer->start(1000/20);
        if (pos != test.size())
        {
            for (int i = 1; i < 70; ++i)
            {
                part[i-1] = part[i];
            }
            part[69] = test[pos];
            ++pos;
        }
        else
        {
            for (int i = 1; i < part.size(); ++i)
            {
                part[i-1] = part[i];
            }
            part.remove(part.size() - 1, 1);
        }
        ui->testBrowser->setText(part);
    }
    else
    {
        ui->testBrowser->setStyleSheet(RED_COLOR_MODE);
        lightningTimer->start(1000/20);
    }
    if (part.size() == 1)
    {
        finishTraining();
    }
    letter = "";
    letter.push_back(part[0]);
    if (letter == " " || letter == "\n")
    {
        ++currentNumberOfWords;
        double currentMinutes = min + (sec/60.0);
        int numberOfWordsInOneMinutes = static_cast<int>(currentNumberOfWords / currentMinutes);
        ui->numberOfWordsBrowser->setText(QString::number(numberOfWordsInOneMinutes));
    }
}

void MainWindow::onTimeout()
{
    ++tics;

    if (tics == 20)
    {
        tics = 0;
        ++sec;
        if (sec == 60)
        {
            sec = 0;
            ++min;
        }
        seconds = "";
        minutes = "";
        time = "";
        if (sec < 10) seconds = "0";
        if (min < 10) minutes = "0";
        seconds += QString::number(sec);
        minutes += QString::number(min);
        time = minutes + ":" + seconds;
        ui->timerBrowser->setText(time);
    }
}

void MainWindow::onLightningTimerTimeout()
{
    ++lights;
    if (lights == 2)
    {
        lights = 0;
        lightningTimer->stop();
        ui->testBrowser->setStyleSheet(DEFAULT_COLOR_MODE);
    }
}

void MainWindow::startTraining()
{
    QString path = "";
    path = QFileDialog::getOpenFileName(this, "Chose file", "/home/vlad/QTprojects/Lab_5__Task_1/");
    if (path == "") return;
    test = readFromFile(path);
    if (test.size() < 70)
    {
        part = test;
        pos = test.size();
    }
    else
    {
        part.resize(70);
        for (int i = 0; i < 70; ++i)
        {
            part[i] = test[i];
        }
        pos = 70;
    }
    ui->testBrowser->setText(part);
    timer->start(1000/20);
    ui->startButton->setEnabled(false);
}

void MainWindow::finishTraining()
{
    test = "";
    part = "";
    min = 0;
    sec = 0;
    tics = 0;
    lights = 0;
    pos = 0;
    currentNumberOfWords = 0;
    timer->stop();
    ui->testBrowser->setText("");
    ui->startButton->setEnabled(true);
}

QString MainWindow::readFromFile(QString path)
{
    QFile file(path);
    if (file.exists()) qDebug() << "File exists";
    else qDebug() << "File not found";

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) qDebug() << "File has opened";
    else throw 1;

    QString ans = "";
    ans = file.readLine();
    file.close();

    return ans;
}

void MainWindow::on_languageBox_activated(int index)
{
    currentLanguage = language->getMap(index);

    // change keyboard

    QVector<QString> textForKeys = language->getKeys(index);
    QString temp = "";

    temp.push_back(textForKeys[0][0]);
    keys[49]->setText(temp);
    temp = "";

    for (int i = 10; i <= 21; ++i)
    {
        temp = "";
        temp.push_back(textForKeys[0][i-9]);
        keys[i]->setText(temp);
    }
    for (int i = 24; i <= 35; ++i)
    {
        temp = "";
        temp.push_back(textForKeys[1][i-24]);
        keys[i]->setText(temp);
    }
    for (int i = 38; i <= 48; ++i)
    {
        temp = "";
        temp.push_back(textForKeys[2][i-38]);
        keys[i]->setText(temp);
    }
    for (int i = 52; i <= 61; ++i)
    {
        temp = "";
        temp.push_back(textForKeys[3][i-52]);
        keys[i]->setText(temp);
    }

}

