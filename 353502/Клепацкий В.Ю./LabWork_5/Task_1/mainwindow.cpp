#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setText(
        "Вожыкі жывуць ва ўсіх мясцінах Беларусі. Іх можна сустрэць у садзе, парку, непадалёку ад "
        "хлява для свойскай жывёлы. Гэта адзін з самых адважных звяркоў. Ён не спяшаецца ўцякаць, "
        "калі сустрэне каго-небудзь на сцяжынцы. Натапырыць свае вострыя калючкі і сярдзіта "
        "пыхкае. Калі ж крыўдзіцель нападзе, звярок умомант згорнецца ў клубок. Няшмат знойдзецца "
        "ахвотнікаў пагуляць з такім калючым мячыкам. Вожык - смелы паляўнічы. Ён знішчае шкодных "
        "жукоў, слімакоў, бурыць мышыныя і кратовыя гнёзды. Ніколі не абміне гадзюку. Змяя ўмела "
        "бароніцца, але вожыка надзейна засцерагаюць вострыя калючкі. Вожыкі нараджаюцца з "
        "іголкамі. Аднак напачатку яны мяккія і белыя. Замест іх праз два-тры тыдні вырастаюць "
        "цёмныя і калючыя. Малако для вожыка - самы смачны ласунак.");
    cursor = ui->textEdit->textCursor();
    dictant = ui->textEdit->toPlainText();
    ui->label_ClavaG->hide();
    //ui->textEdit->setTextCursor(cursor);
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(increment()));
    timer.start(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    text = ui->lineEdit->text();
    int razmer = text.length();
    if (razmer > 0 && razmer <= dictant.length()) {
        for (int i = razmer - 1; i < razmer; ++i) {
            if (text[i] == dictant[i]) {
                cursor.setPosition(i);
                cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
                QTextCharFormat format;
                format.setForeground(QBrush(Qt::green));
                cursor.mergeCharFormat(format);
            } else {
                cursor.setPosition(i);
                cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
                QTextCharFormat format;
                format.setForeground(QBrush(Qt::red));
                cursor.mergeCharFormat(format);
                numbermistakes++;
            }
        }
    }
    if (razmer == dictant.length()) {
        int procent = 100 * (razmer - numbermistakes) / razmer;
        ui->label_Correct->setText(QString::number(procent));
        //double time = second / 60000;
        yourSpeedu = razmer / (second / 1000.0);
        ui->label_Speed->setText(QString::number(yourSpeedu));

        cursor.select(QTextCursor::Document);
        QTextCharFormat format;
        format.setForeground(QBrush(Qt::white));
        cursor.mergeCharFormat(format);
        ui->lineEdit->clear();
        second = 0;
        numbermistakes = 0;
    }
}

void MainWindow::increment()
{
    ++second;
    return;
}

void MainWindow::on_pushButtonBelarusian_clicked()
{
    numbermistakes = 0;
    second = 0;
    ui->lineEdit->clear();
    ui->label_ClavaB->setVisible(true);
    ui->label_ClavaG->hide();
    //cursor = ui->textEdit->textCursor();
    ui->textEdit->setText(
        "Вожыкі жывуць ва ўсіх мясцінах Беларусі. Іх можна сустрэць у садзе, парку, непадалёку ад "
        "хлява для свойскай жывёлы. Гэта адзін з самых адважных звяркоў. Ён не спяшаецца ўцякаць, "
        "калі сустрэне каго-небудзь на сцяжынцы. Натапырыць свае вострыя калючкі і сярдзіта "
        "пыхкае. Калі ж крыўдзіцель нападзе, звярок умомант згорнецца ў клубок. Няшмат знойдзецца "
        "ахвотнікаў пагуляць з такім калючым мячыкам. Вожык - смелы паляўнічы. Ён знішчае шкодных "
        "жукоў, слімакоў, бурыць мышыныя і кратовыя гнёзды. Ніколі не абміне гадзюку. Змяя ўмела "
        "бароніцца, але вожыка надзейна засцерагаюць вострыя калючкі. Вожыкі нараджаюцца з "
        "іголкамі. Аднак напачатку яны мяккія і белыя. Замест іх праз два-тры тыдні вырастаюць "
        "цёмныя і калючыя. Малако для вожыка - самы смачны ласунак.");
    dictant = ui->textEdit->toPlainText();
    cursor.select(QTextCursor::Document);
    QTextCharFormat format;
    format.setForeground(QBrush(Qt::white));
    cursor.mergeCharFormat(format);
}

void MainWindow::on_pushButtonGermany_clicked()
{
    ui->textEdit->setTextCursor(cursor);
    numbermistakes = 0;
    second = 0;
    ui->lineEdit->clear();
    ui->label_ClavaG->setVisible(true);
    ui->label_ClavaB->hide();
    //cursor = ui->textEdit->textCursor();
    ui->textEdit->setText("Apfel, Haus, Auto, Blume, Tisch, Stadt, Buch, Freund, Wasser, Schule, "
                          "Katze, Hund, Mutter, Vater, Sonne, Mond, Straße, Telefon, Fenster, "
                          "Kaffee, Musik, Stuhl, Brot, Schlüssel, Zeit");
    dictant = ui->textEdit->toPlainText();
    cursor.select(QTextCursor::Document);
    QTextCharFormat format;
    format.setForeground(QBrush(Qt::white));
    cursor.mergeCharFormat(format);
}

void MainWindow::readFromFile(QString filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        ui->textEdit->setText(stream.readAll());
        file.close();
    }
}
void MainWindow::on_pushButton_clicked()
{
    readFromFile(
        QFileDialog::getOpenFileName(nullptr, "Open Files", "../Files", "txt file (*.txt);;"));
    dictant = ui->textEdit->toPlainText();
}
