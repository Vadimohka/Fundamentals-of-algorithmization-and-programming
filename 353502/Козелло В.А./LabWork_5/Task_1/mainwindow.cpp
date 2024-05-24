#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , keyboard(new Keyboard)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(keyboard);
    ui->graphicsView->setSceneRect(0, 0, 1190, 390);

    cursor = ui->mainText->textCursor();
    cursor.setCharFormat(format);

    connect(&timer, &QTimer::timeout, this, &MainWindow::slotSecondsUpdate);

    currText
        = "Усе галіны яе, усе вялікія расохі, да апошняга пруціка, былі ўсыпаны бурным "
          "бела-ружовым цветам. Яна кіпела, млела і раскашавалася ў пчаліным звоне, цягнула да "
          "сонца сталыя лапы і распасцірала ў яго ззянні маленькія, кволыя пальцы новых парасткаў. "
          "І была яна такая магутная і свежая, так утрапёна спрачаліся ў яе ружовым раі пчолы, "
          "што, здавалася, не будзе ёй зводу і не будзе канца.";
    mask.fill('c', currText.size());
    printText();
    isProcess = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (!isProcess) {
        isProcess = true;
        timer.start(100);
        seconds = 0;
        words = 0;
        mistakes = 0;
        currIndex = 0;
    }
    keyboard->hightlight(e->text());
    qDebug() << e->text();
    if (!e->text().isEmpty() && e->text() != '\b') {
        if (currIndex == currText.size()) {
            isProcess = false;
            timer.stop();
            mask.fill('c', currText.size());

            keyboard->antiHighlight();

            double accurancy = currText.size() >= mistakes
                                   ? (currText.size() - mistakes) * 100 / currText.size()
                                   : 0;
            QMessageBox::information(this,
                                     "Тренировка окончена",
                                     "Количесвто слов: " + QString::number(words)
                                         + "\nСредняя скорость: "
                                         + QString::number(60 * words / seconds)
                                         + " Слов в минуту\nАккуратность: "
                                         + QString::number(accurancy)
                                         + "%\nВремя: " + QString::number(seconds) + " c");

        } else if (e->text() == currText[currIndex]) {
            mask[currIndex] = 'g';
            currIndex++;
            if (e->text() == " ") {
                words++;
            }
        } else {
            mask[currIndex] = 'r';
            currIndex++;
            mistakes++;
        }
    } else if (e->key() == Qt::Key_Backspace) {
        if (currIndex != 0) {
            currIndex--;
            mask[currIndex] = 'c';
        }
    }
    printText();
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    keyboard->antiHighlight();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    isProcess = false;
    timer.stop();
    mask.fill('c', currText.size());

    keyboard->initKeboard(index);
    if (index == bel) {
        currText
            = "Усе галіны яе, усе вялікія расохі, да апошняга пруціка, былі ўсыпаны бурным "
              "бела-ружовым цветам. Яна кіпела, млела і раскашавалася ў пчаліным звоне, цягнула да "
              "сонца сталыя лапы і распасцірала ў яго ззянні маленькія, кволыя пальцы новых "
              "парасткаў. І была яна такая магутная і свежая, так утрапёна спрачаліся ў яе ружовым "
              "раі пчолы, што, здавалася, не будзе ёй зводу і не будзе канца.";
    } else if (index == arab) {
        currText = "مدرب لوحة المفاتيح الغبي";
    } else if (index == ger) {
        currText = "Berlin ist eine der wenigen Städte, die ein so vielfältiges Angebot "
                   "an Attraktionen bieten kann";
    } else if (index == fre) {
        currText = "Eh bien, mon prince. Gênes et Lucques ne sont plus que des "
                   "apanages, des, de la famille Buonaparte.";
    } else if (index == chin) {
        currText = "zhong1 guo2 cheng2 wei2 ya4 zhou1 zui4 jia1 lv3 you2 mu4 de di4 ";
    } else if (index == heb) {
        currText = "יהודים הם בחורים קשוחים, במיוחד בבדיחות";
    } else if (index == ru) {
        currText = "Так говорила в июле 1805 года известная Анна Павловна Шерер, фрейлина и "
                   "приближенная императрицы Марии Феодоровны, встречая важного и чиновного князя "
                   "Василия, первого приехавшего на ее вечер.";
    }
    mask.fill('c', currText.size());
    printText();
}

void MainWindow::on_OpenButton_clicked()
{
    isProcess = false;
    timer.stop();
    mask.fill('c', currText.size());

    QString sourseFile = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");
    QFile file(sourseFile);
    if ((file.exists()) && (file.open(QIODevice::ReadOnly))) {
        currText = file.readAll();
        ui->mainText->setText(currText);
        mask.fill('c', currText.size());
        file.close();

    } else {
        QMessageBox::critical(this, "Ошибка!", "Файл не открыт или не существует!");
    }
}

void MainWindow::slotSecondsUpdate()
{
    seconds += 0.1;
    ui->TimerLabel->setText(QString::number(seconds));
    ui->WPMLabel->setText(QString::number(static_cast<int>(60 * words / seconds)));
    if (mistakes != 0) {
        double accurancy = currText.size() >= mistakes
                               ? (currText.size() - mistakes) * 100 / currText.size()
                               : 0;
        ui->accurancy->setText(QString::number(accurancy) + "%");
    } else {
        ui->accurancy->setText("100%");
    }
}

void MainWindow::printText()
{
    ui->mainText->clear();
    for (int i = 0; i < currText.size(); i++) {
        if (mask[i] == 'c') {
            format.setForeground(Qt::gray);
        } else if (mask[i] == 'r') {
            format.setForeground(Qt::darkRed);
        } else if (mask[i] == 'g') {
            format.setForeground(Qt::darkGreen);
        }
        cursor.setCharFormat(format);
        cursor.insertText(QString(currText[i]));
    }
}
