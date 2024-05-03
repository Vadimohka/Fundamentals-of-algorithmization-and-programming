#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gridLayout->addWidget(keyboard, 7, 0, 7, 5);

    on_languageChangeComboBox_currentIndexChanged(Local::FRA);
    setFocus();

    ui->startButton->setStyleSheet("QPushButton {"
                                   "  background-color: #008631;"
                                   "}"
                                   "QPushButton:disabled {"
                                   "  background-color: #CCCCCC;"
                                   "  color: #666666;"
                                   "}");
    ui->stopButton->setStyleSheet("QPushButton {"
                                  "  background-color: #008631;"
                                  "}"
                                  "QPushButton:disabled {"
                                  "  background-color: #CCCCCC;"
                                  "  color: #666666;"
                                  "}");
    ui->openTestButton->setStyleSheet("QPushButton {"
                                      "  background-color: #008631;"
                                      "}"
                                      "QPushButton:disabled {"
                                      "  background-color: #CCCCCC;"
                                      "  color: #666666;"
                                      "}");
    ui->languageChangeComboBox->setStyleSheet("QComboBox {"
                                              "  background-color: #008631;"
                                              "}"
                                              "QComboBox:disabled {"
                                              "  background-color: #CCCCCC;"
                                              "  color: #666666;"
                                              "}");
    setButtons();

    updateTimer->start(100);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateInfo);
    timer->start();

    ui->testLabel->setFont(QFont("arial", 40));

    this->setFixedSize(this->size());

    setWindowTitle("Тренажёр");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (!isTesting) return;
    keyboard->keyPressEvent(event);
    if (codeSymbolNumber.contains(event->nativeScanCode()))
    {
        workWithEvent(event);
        return;
    }
    if (event->key() == Qt::Key_Space)
    {
        workWithEvent(event);
        return;
    }
    if (codeSymbolNumber.contains(event->text().toInt())) {
        QKeyEvent* newEvent = new QKeyEvent(QEvent::KeyPress, 0, Qt::KeyboardModifier::NoModifier, keys[currLocal][codeSymbolNumber[event->text().toInt()]]);
        workWithEvent(newEvent);
        delete newEvent;
    }

}

void MainWindow::on_languageChangeComboBox_currentIndexChanged(int index)
{
    keyboard->setKeys(index);
    currTest = {};
    ui->testLabel->setText("");
    currLocal = index;
    setFocus();
    setButtons();
}

void MainWindow::on_stopButton_clicked()
{
    isTesting = false;
    setButtons();
    setFocus();
    ui->testLabel->setText("");
}

void MainWindow::on_startButton_clicked()
{
    words = 0;
    rightSymbols = 0;
    allSymbols = 0;
    if (currTest.size() == 0)
    {
        QMessageBox::critical(0,tr("Ошибка"),tr("Выберите тест!"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }
    isTesting = true;
    currNeededSimb = 0;
    currTestNum = 0;
    setText();
    setButtons();
    setFocus();
    timer->restart();
}


void MainWindow::on_openTestButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие"), "//", tr("Текстовые документы (*.txt)"));
    QFile openedFile(fileName);
    QTextStream in(&openedFile);

    if (!openedFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    if (in.atEnd())
    {
        QMessageBox::critical(0,tr("Ошибка"),tr("Пустой файл!"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }

    currTest = {};
    while (!in.atEnd())
        currTest.append(in.readLine());
    if (!checkTest())
    {
        QMessageBox::critical(0,tr("Ошибка"),tr("Недопустимые символы!"),QMessageBox::Ok|QMessageBox::NoButton);
        currTest = {};
        return;
    }

    QMessageBox::information(0,tr("Успех"),tr("Тестовый текст добавлен!"),QMessageBox::Ok|QMessageBox::NoButton);
    setButtons();

    setFocus();
}

bool MainWindow::checkTest()
{
    for (auto str : currTest)
    {
        if (str.size() > 30) return false;
        for (auto simb : str)
        {
            if (!allowedSimbols[currLocal].contains(QString(simb)) && simb != '\n')
                return false;
        }
    }
    return true;
}

void MainWindow::setButtons()
{
    ui->startButton->setDisabled(currTest.size() == 0 || isTesting);
    ui->stopButton->setEnabled(isTesting);
    ui->openTestButton->setDisabled(isTesting);
    ui->languageChangeComboBox->setDisabled(isTesting);
    keyboard->setDisabled(!isTesting);
}

void MainWindow::updateInfo()
{
    if (!isTesting) return;
    ui->wpmLCD->display(1. * words * 60000 / timer->elapsed());
    ui->timerLCD->display((int)timer->elapsed() / 100);
    ui->accuracyLCD->display(100. * rightSymbols / (allSymbols == 0 ? 1 : allSymbols));
}

void MainWindow::workWithEvent(QKeyEvent *event)
{
    QString a = keys[currLocal][codeSymbolNumber[event->nativeScanCode()]],
        b = QString(ui->testLabel->text()[currNeededSimb * 28 + 20]) ;
    QString oldText = ui->testLabel->text();
    QString eventText = event->text();
    ui->testLabel->setText(
        oldText.first(currNeededSimb * 28) +
        "<font color=" +
        (event->text() == b || a == b ? "\"green\"" : "\"red  \"") +
        ">" + oldText[currNeededSimb * 28 + 20] + "</font>" +
        oldText.last(oldText.size() - currNeededSimb * 28 - 28)
    );

    allSymbols++;
    if (event->text() == QString(ui->testLabel->text()[currNeededSimb * 28 + 20]) || a == b) rightSymbols++;

    words = 1. * rightSymbols / 5;

    currNeededSimb++;
    if (currNeededSimb == currTest[currTestNum].size())
    {
        currNeededSimb = 0;
        currTestNum++;
        if (currTestNum == currTest.size() - 1)
        {
            on_stopButton_clicked();
            QMessageBox::information(0,tr("Успех"),tr("Тест пройден!"),QMessageBox::Ok|QMessageBox::NoButton);
            return;
        }
        setText();
    }
}

void MainWindow::setText()
{
    QString text = "";
    for (auto simb : currTest[currTestNum])
    {
        text += "<font color=\"black\">" + QString(simb) + "</font>";
    }
    ui->testLabel->setText(text);
}
