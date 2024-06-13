#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    addButtonsFromLayout(ui->horizontalLayout);
    addButtonsFromLayout(ui->horizontalLayout_2);
    addButtonsFromLayout(ui->horizontalLayout_3);
    addButtonsFromLayout(ui->horizontalLayout_4);

    QMessageBox msgBox;
    msgBox.setInformativeText("Choose language");
    msgBox.addButton("German", QMessageBox::AcceptRole);
    msgBox.addButton("French", QMessageBox::ActionRole);
    msgBox.addButton("Arabic", QMessageBox::ApplyRole);
    msgBox.addButton("Chinese", QMessageBox::DestructiveRole);
    msgBox.addButton("Belarusian", QMessageBox::HelpRole);
    msgBox.addButton("Jewish", QMessageBox::HelpRole);

    msgBox.exec();

    if (msgBox.clickedButton()->text() == "German")
    {
        alphabet = "^1234567890ß´qwertzuiopü+#asdfghjklöäyxcvbnm,.- ";
    }

    if (msgBox.clickedButton()->text() == "French")
    {
        alphabet = "²&é\"'(-è_çà)=azertyuiop^$*qsdfghjklmùwxcvbn,;:! ";
    }

    if (msgBox.clickedButton()->text() == "Arabic")
    {
        alphabet = "ذ1234567890-=ضصثقفغعهخحجد\\شسيبلاتنمكطئءؤرلاىةوز ";
    }

    if (msgBox.clickedButton()->text() == "Chinese")
    {
        alphabet = "`1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbnm,./ ";
    }

    if (msgBox.clickedButton()->text() == "Belarusian")
    {
        alphabet = "ё1234567890-=йцукенгшўзх'\\фывапролджэячсмітьбю. ";
    }

    if (msgBox.clickedButton()->text() == "Jewish")
    {
        alphabet = ";1234567890-=/'קראטוןםפ][\\שדגכעיחלךף,זסבהנמצתץ. ";
    }

    buttons.push_back(ui->space);

    for (int i = 0;i<alphabet.size();++i)
    {
        buttons[i]->setText(QString(alphabet[i]));
    }

    QRandomGenerator rng;

    wrongPressed = 0;
    rightPressed = 0;
    prevWrongPressed = 0;
    rightWords = 0;

    for (int i = 0;i<TEXT_SIZE;i++)
    {
        textToWrite.append(alphabet[rng()%alphabet.size()]);
        if (rng() % PROBABILITY_OF_SPACE == 0)
        {
            textToWrite.append(" ");
        }
    }

    writtenText = "";

    timer.setInterval(TIMER_INTERVAL);

    connect(&timer, &QTimer::timeout, this, [this] ()
    {
        currentTime += TIMER_INTERVAL / MILLISECONDS_IN_SECOND;

        ui->textEdit_2->setPlainText(textToWrite);
        ui->textEdit->setPlainText(writtenText);

        ui->label->setText(QString::number(rightPressed / currentTime));
        ui->label_2->setText(QString::number(wrongPressed));
        ui->label_3->setText(QString::number(rightPressed));
        ui->label_4->setText(QString::number(rightWords));

        if (textToWrite == "")
        {
            QMessageBox msgBox;
            msgBox.setText("Your results : " + QString::number(rightPressed / currentTime) + " " + QString::number(wrongPressed) + " " + QString::number(rightPressed) + " " + QString::number(rightWords));

            msgBox.exec();

            delete this;
        }
    });

    timer.start();
}

void MainWindow::addButtonsFromLayout(const QLayout* layout)
{
    auto count = layout->count();
    for (int i = 0; i < count; ++i)
    {
        auto item = layout->itemAt(i);
        QPushButton* button = dynamic_cast<QPushButton*>(item->widget());

        if (button != nullptr)
        {
            buttons.push_back(button);
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->text().toLower();
    for (int i = 0;i<alphabet.size();++i)
    {
        if (alphabet[i].unicode() == event->text().toLower())
        {
            buttons[i]->setPalette(QPalette(Qt::yellow));

            if (i == alphabet.size() - 1)
            {
                if (writtenText.size() && writtenText.back() != " ")
                {
                    if (prevWrongPressed == wrongPressed)
                    {
                        rightWords++;
                    }
                    else
                    {
                        prevWrongPressed = wrongPressed;
                    }
                }

                if (event->text() != textToWrite.front())
                {
                    wrongPressed++;
                }
                else
                {
                    rightPressed++;
                }
            }
            else
            {
                if (event->text() != textToWrite.front())
                {
                    wrongPressed++;
                }
                else
                {
                    rightPressed++;
                }
            }

            writtenText.append(event->text());
            textToWrite.remove(0, 1);
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    for (int i = 0;i<alphabet.size();++i)
    {
        if (alphabet[i].unicode() == event->text().toLower())
        {
            buttons[i]->setPalette(QPalette());
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

