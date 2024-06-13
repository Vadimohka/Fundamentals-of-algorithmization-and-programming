#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , keyboard(new Keyboard)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(keyboard);
    ui->graphicsView->setSceneRect(0, 0, 900, 300);

    ui->mainText->setFocusPolicy(Qt::NoFocus);
    ui->OpenButton->setFocusPolicy(Qt::ClickFocus);
    ui->comboBox->setFocusPolicy(Qt::ClickFocus);
    cursor = ui->mainText->textCursor();
    cursor.setCharFormat(format);

    connect(&timer, &QTimer::timeout, this, &MainWindow::slotSecondsUpdate);

    currText = "Зусім неяк мы забыліся і пра тое, што Навагрудак пэўны час быў галоўнай рэзідэнцыяйкіеўскага праваслаўнага мітрапаліта,пад уладай якога знаходзілісярускія землі ад Полацка да крымскіхстэпаў. Гэта сведчыць і аб важнасці горадаяк праваслаўнага цэнтра, і аб яго цесныхсувязях з іншымі рускімі землямі.";
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
    keyboard->hightlight(e);
    qDebug() << e->text();
    if (!e->text().isEmpty() && e->text() != '\b') {
        if (currIndex == currText.size()) {
            isProcess = false;
            timer.stop();
            mask.fill('c', currText.size());

            keyboard->antiHighlight();

            double accurancy = currText.size() >= mistakes ? (currText.size() - mistakes) * 100 / currText.size() : 0;
            QMessageBox::information(this,"Congratulations!", "Werbs: " + QString::number(words)+ "\nAvg speed: " + QString::number(60 * words / seconds) + "\nAccuracy: " + QString::number(accurancy) + "%\nTime: " + QString::number(seconds) + " c.");

        } else if (e->text() == currText[currIndex]) {
            mask[currIndex] = 'g';
            currIndex++;
            if (e->key() == Qt::Key_Space && currText[currIndex-2] == ui->mainText->toPlainText()[currIndex-2]) {
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
    ui->graphicsView->setFocus();
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
        currText = "Зусім неяк мы забыліся і пра тое, што Навагрудак пэўны час быў галоўнай рэзідэнцыяйкіеўскага праваслаўнага мітрапаліта,пад уладай якога знаходзілісярускія землі ад Полацка да крымскіхстэпаў. Гэта сведчыць і аб важнасці горадаяк праваслаўнага цэнтра, і аб яго цесныхсувязях з іншымі рускімі землямі.";
    }
    else if (index == arab) {
        currText = "مدرب لوحة المفاتيح الغبي";
    }
    else if (index == ger) {
        currText = "Berlin ist eine der wenigen Städte, die ein so vielfältiges Angebot "
                   "an Attraktionen bieten kann";
    }
    else if (index == fre) {
        currText = "Eh bien, mon prince. Gênes et Lucques ne sont plus que des "
                   "apanages, des, de la famille Buonaparte.";
    }
    else if (index == chin) {
        currText = "zhong1 guo2 cheng2 wei2 ya4 zhou1 zui4 jia1 lv3 you2 mu4 de di4 ";
    }
    else if (index == heb) {
        currText = "יהודים הם בחורים קשוחים, במיוחד בבדיחות";
    }
    else if (index == ru) {
        currText = "Умные указатели были созданы для устранения вышеупомянутых неудобств. По сути, они обеспечивают автоматическое управление памятью: когда умный указатель больше не используется, то есть выходит из области видимости, память, на которую он указывает, автоматически высвобождается. Традиционные указатели теперь также называют «обычными» указателями.";
    }
    else if (index == eng) {
        currText = "The standard string class provides support for such objects with an interface similar to that of a standard container of bytes, but adding features specifically designed to operate with strings of single-byte characters.";
    }
    mask.fill('c', currText.size());
    printText();
    ui->graphicsView->setFocus();
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
        ui->mainText->insertPlainText(currText);
        mask.fill('c', currText.size());
        file.close();

    } else {
        QMessageBox::critical(this, "Warning!", "File don't open or don't exist!");
    }
    ui->graphicsView->setFocus();
}

void MainWindow::slotSecondsUpdate()
{
    seconds += 0.1;
    ui->TimerLabel->setText(QString::number(seconds));
    ui->WPMLabel->setText(QString::number(static_cast<int>(60 * words / seconds)));
    if (mistakes != 0) {
        double accurancy = currText.size() >= mistakes ? (currText.size() - mistakes) * 100 / currText.size() : 0;
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
