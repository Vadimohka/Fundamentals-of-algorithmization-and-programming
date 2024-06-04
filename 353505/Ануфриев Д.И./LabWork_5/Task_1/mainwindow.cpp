#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

    keyboard = new Keyboard();
    timer = new QTimer();
    textEdit = new CustomTextEdit();

    textEdit->setFont(QFont("Sans", 20, QFont::Bold));

    elapsedTime = 0;
    inputedWords = 0;
    incorrectCharsCount = 0;
    correctCharsCount = 0;

    keyboard->setTextEdit(textEdit);
    ui->widgetForKeyboard->setLayout(keyboard);
    ui->verticalLayout->addWidget(textEdit);

    initializeDictionaries();

    connect(textEdit, &CustomTextEdit::keyPressed, [this](QKeyEvent* event){
        keyboard->keyPressEvent(event);
    });

    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    connect(textEdit, &CustomTextEdit::oneWordWasInputed, this, &MainWindow::oneWordPlus);
    connect(textEdit, &CustomTextEdit::endOfInput, this, &MainWindow::endOfInput);
    connect(textEdit, &CustomTextEdit::inputCorrectChar, this, &MainWindow::addCorrectCharsCount);
    connect(textEdit, &CustomTextEdit::inputIncorrectChar, this, &MainWindow::addIncorrectCharsCount);

    ui->comboLanguage->addItem("None");
    ui->comboLanguage->addItem("Беларуская мова");
    ui->comboLanguage->addItem("Deutsch");
    ui->comboLanguage->addItem("Français");
    ui->comboLanguage->addItem("عرب");
    ui->comboLanguage->addItem("עִברִית");
    ui->comboLanguage->addItem("拼音");

    ui->comboMode->addItem("From file");
    ui->comboMode->addItem("Random generation");

    connect(ui->comboLanguage, &QComboBox::currentIndexChanged, this, [=](int index)
    {
        textEdit->clear();
        QTextCharFormat format;
        QTextCursor cursor = textEdit->textCursor();

        format.setForeground(QColor(Qt::black));
        cursor.setCharFormat(format);

        textEdit->setTextCursor(cursor);

        textEdit->setPlainText("Выберите язык для начала тренировки, включите соответствующую раскладку клавиатуры нажмите 'Start'");

        if(index == 0)
        {
            keyboard->clear();
            ui->beginButton->setEnabled(false);

            ui->labelTimer->setText("--:--.---");
            ui->labelPrecision->setText("-%");
            ui->labelWords->setText("-");

            elapsedTime = 0;
            inputedWords = 0;
            incorrectCharsCount = 0;
            correctCharsCount = 0;
        }
        else
        {
            ui->labelTimer->setText("00:00.000");
            ui->labelPrecision->setText("100%");
            ui->labelWords->setText("0 wpm");

            ui->beginButton->setEnabled(true);

            if(index == 1)
            {
                keyboard->setBelaruisan();
            }
            if(index == 2)
            {
                keyboard->setGerman();
            }
            if(index == 3)
            {
                keyboard->setFrench();
            }
            if(index == 4)
            {
                keyboard->setArabic();
            }
            if(index == 5)
            {
                keyboard->setHebrew();
            }
            if(index == 6)
            {
                keyboard->setChinese();
            }
        }

    });

    ui->comboLanguage->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    ui->comboMode->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    textEdit->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    textEdit->setPlainText("Выберите язык для начала тренировки, включите соответствующую раскладку клавиатуры нажмите 'Start'");
    textEdit->setContextMenuPolicy(Qt::NoContextMenu);

    QTextCursor cursor = textEdit->textCursor();

    cursor.setPosition(0);
    textEdit->setTextCursor(cursor);

    ui->widget->setFocus();

    ui->comboLanguage->currentIndexChanged(0);
    //textEdit->setFocus();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    keyboard->keyPressEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openNewFile()
{   
    openedFileName = "";
    openedFileName = QFileDialog::getOpenFileName(this, "Выберите файл", "/home/deviyan/QTprojects/LabWork_5/Task_1/files/texts", "Текстовые файлы (*.txt)");
    QFile *openedFile = new QFile(openedFileName);

    if(openedFile->open(QIODevice::ReadWrite))
    {
        QTextCursor cursor = textEdit->textCursor();

        textEdit->clear();
        cursor.setPosition(0);
        textEdit->setTextCursor(cursor);

        QTextStream in(openedFile);
        textEdit->clear();

        while(!in.atEnd())
        {
            QString text = in.readLine();
            textEdit->setPlainText(text);
        }

        // textEdit->setFocus();
    }

    openedFile->close();
}


void MainWindow::on_beginButton_clicked()
{
    bool isStarted = false;

    if(ui->comboMode->currentIndex() == 0)
    {
        openNewFile();
        if(!openedFileName.isEmpty()) isStarted = true;
    }
    else
    {
        generateRandomWords(20);
        isStarted = true;

    }

    if(isStarted)
    {
        ui->labelTimer->setText("00:00.000");
        ui->labelPrecision->setText("100%");
        ui->labelWords->setText("0 wpm");

        ui->beginButton->setEnabled(false);
        ui->comboLanguage->setEnabled(false);
        ui->comboMode->setEnabled(false);

        elapsedTime = 0;
        inputedWords = 0;
        incorrectCharsCount = 0;
        correctCharsCount = 0;
        timer->start(10);

        textEdit->setFocus();
    }

}

void MainWindow::updateTime()
{
    // Увеличиваем счетчик времени
    elapsedTime++;

    // Вычисляем часы, минуты и секунды
    int minutes = (elapsedTime / 6000) % 60;
    int seconds = (elapsedTime / 100) % 60;
    int miliseconds = elapsedTime % 100;

    // Форматируем время в виде строки
    QString timeStr = QString("%1:%2.%3")
                          .arg(minutes, 2, 10, QLatin1Char('0'))
                          .arg(seconds, 2, 10, QLatin1Char('0'))
                          .arg(miliseconds, 3, 10, QLatin1Char('0'));

    // Обновляем текст QLabel
    ui->labelTimer->setText(timeStr);

}

void MainWindow::oneWordPlus()
{
    inputedWords++;
    ui->labelWords->setText(QString::number(60 / (elapsedTime /100.0) * inputedWords, 'f', 2) + " wpm");
}

void MainWindow::endOfInput()
{
    timer->stop();
    QMessageBox::information(this, "End of writting", "It's end of text!");

    ui->beginButton->setEnabled(true);
    ui->comboLanguage->setEnabled(true);
    ui->comboMode->setEnabled(true);

    ui->widget->setFocus();
}

void MainWindow::addCorrectCharsCount()
{
    correctCharsCount++;
    ui->labelPrecision->setText(QString::number(100.0 * correctCharsCount / (correctCharsCount + incorrectCharsCount), 'f', 2) + "%");

    ui->labelWords->setText(QString::number(60 / (elapsedTime /100.0) * inputedWords, 'f', 2) + " wpm");
}

void MainWindow::addIncorrectCharsCount()
{
    incorrectCharsCount++;
    ui->labelPrecision->setText(QString::number(100.0 * correctCharsCount / (correctCharsCount + incorrectCharsCount), 'f', 2) + "%");

    ui->labelWords->setText(QString::number(60 / (elapsedTime /100.0) * inputedWords, 'f', 2) + " wpm");
}

void MainWindow::generateRandomWords(int count)
{
    QTextCursor cursor = textEdit->textCursor();

    textEdit->clear();
    cursor.setPosition(0);
    textEdit->setTextCursor(cursor);



    for(int i = 0; i < count; i++)
    {
        if(ui->comboLanguage->currentIndex() == 1)
        {
            textEdit->setText(textEdit->toPlainText() + (textEdit->toPlainText().size() != 0 ? " " : "")
                                  + DictionariesVector[ui->comboLanguage->currentIndex()][rand() % 37922]);
        }
        else
        {
            textEdit->setText(textEdit->toPlainText() + (textEdit->toPlainText().size() != 0 ? " " : "")
                                  + DictionariesVector[ui->comboLanguage->currentIndex()][rand() % 300]);
        }
    }

    // textEdit->setFocus();

}

void MainWindow::initializeDictionaries()
{
    QString dictionaries[] = {"", "../../files/belarusianDictionary.txt", "../../files/germanDictionary.txt",
                               "../../files/frenchDictionary.txt", "../../files/arabicDictionary.txt",
                              "../../files/hebrewDictionary.txt", "../../files/chineseDictionary.txt"};

    for(int i = 1; i < 7; i++)
    {
        QString dictionaryFile = dictionaries[i];
        QFile *openedFile = new QFile(dictionaryFile);

        if(openedFile->open(QIODevice::ReadOnly) && DictionariesVector[i].isEmpty())
        {
            QTextStream in(openedFile);
            textEdit->clear();

            while(!in.atEnd())
            {
                QString text = in.readLine();
                DictionariesVector[i].push_back(text);
            }

            openedFile->close();
        }
    }


}

