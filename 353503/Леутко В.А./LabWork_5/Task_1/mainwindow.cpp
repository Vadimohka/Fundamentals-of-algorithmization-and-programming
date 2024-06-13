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
        = "This text includes common English words and phrases, as well as the pangram is "
          "The quick brown fox jumps over the lazy dog which uses every letter of the alphabet."
          "Practicing typing this text can help improve your overall keyboard proficiency.";
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
                                         + "%\nВремя: " + QString::number(seconds) + " current");

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
    if (index == Keyboard::eng) {
        currText
            = "This text includes common English words and phrases, as well as the pangram is "
              "The quick brown fox jumps over the lazy dog which uses every letter of the alphabet."
              "Practicing typing this text can help improve your overall keyboard proficiency.";
    } else if (index == Keyboard::arab) {
        currText = "القرد البني السريع يقفز فوق الكلب الكسول";
    } else if (index == Keyboard::ger) {
        currText = "Der schnelle braune Fuchs springt über den faulen Hund";
    } else if (index == Keyboard::fre) {
        currText = "Le renard brun rapide saute par-dessus le chien paresseux";
    } else if (index == Keyboard::chin) {
        currText = "xin1 xi1 wan2 mei3 li4 gu3 ji4 cheng2 wei2 shi4 jie4 zui4 jia1 you2 xi4 qu1";
    } else if (index == Keyboard::heb) {
        currText = "העכבר העברי קופץ מעל הכלב העצלן";
    } else if (index == Keyboard::ru) {
        currText = "Дождливым вечером Петя сидел за компьютером и печатал важный отчет для начальника."
                   "Его пальцы быстро и ловко перебирали клавиши, легко находя нужные буквы на клавиатуре."
                   "Петя старался не смотреть на экран, а полностью сосредоточиться на процессе печати.";
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
            }
          else  if (mask[i] == 'r') {
               format.setForeground(Qt::darkRed);
           }
        else if (mask[i] == 'g') {
            format.setForeground(Qt::darkGreen);
        }
        cursor.setCharFormat(format);
        cursor.insertText(QString(currText[i]));
    }
}
