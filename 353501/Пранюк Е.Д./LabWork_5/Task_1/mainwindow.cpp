#include "mainwindow.h"
#include "ui_mainwindow.h"

const int SPACE = 47;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), _keyboard(new KeyboardVisualizer()), _timer(new QTimer())
{
    ui->setupUi(this);
    ui->keyboard->addWidget(_keyboard);
    setTextToWrite(_currentText);

    _timer->setInterval(1);
    connect(_timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    ui->timer->setText("00:00:00");


    ui->TextInput->setEnabled(false);
    _redF.setForeground(Qt::red);
    _greenF.setForeground(Qt::green);
    _blackF.setForeground(Qt::black);

    KeyLayout.push_back(QString::fromStdString("`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"));
    KeyLayout.push_back(QString::fromStdString("ё1234567890-=йцукенгшўзх'\\фывапролджэячсмітьбю."));
    KeyLayout.push_back(QString::fromStdString("ё1234567890-=йцукенгшўзх'\\фывапролджэячсмітьбю."));
    KeyLayout.push_back(QString::fromStdString("ذ1234567890-=ضصثقفغعهخحجد\\شسيبلاتنمكطئءؤرلاىةوزظ"));
    KeyLayout.push_back(QString::fromStdString("^1234567890ß´qwertyuiopü+#asdfghjklöäzxcvbnm,.-"));
    KeyLayout.push_back(QString::fromStdString(";1234567890-=/'קראטוןםפ][\\שדגכעיחלךף,זסבהנמצתץ."));
    KeyLayout.push_back(QString::fromStdString("`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"));
    KeyLayout.push_back(QString::fromStdString("<&é”’(§è!çà)-azertyuiop^$`qsdfghjklmùwxcvbn,;:="));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTextToWrite(QString &text)
{
    ui->TextToWrite->setText(text);
}

void MainWindow::ColorText(QChar newChar)
{
    QTextCursor cursor(ui->TextToWrite->document());
    cursor.setPosition(_charCntr, QTextCursor::MoveAnchor);

    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

    QString text = ui->TextToWrite->toPlainText();
    if (_charCntr < text.size())
    {

        if(_charCntr != _currentText.size()-1)
        {
            int index = KeyLayout.at(lang).indexOf(_currentText.at(_charCntr + 1).toLower());
            _keyboard->makeButtonBlue(index);
        }

        if (static_cast<QChar>(text.at(_charCntr)) == newChar)
        {
            cursor.mergeCharFormat(_greenF);
            int index = KeyLayout.at(lang).indexOf(text.at(_charCntr).toLower());
            if(text.at(_charCntr) == ' ')
            {
                index = SPACE;
                if(isCorrect >= 1)
                {
                    words++;
                }
                 isCorrect = 0;
            }
            else
            {
                 isCorrect++;
            }
            _keyboard->makeButtonGreen(index);
            correct++;
        }
        else
        {
            cursor.mergeCharFormat(_redF);
            int index = KeyLayout.at(lang).indexOf(text.at(_charCntr).toLower());
            if(text.at(_charCntr) == ' ')
            {
                index = SPACE;
            }
            _keyboard->makeButtonRed(index);
            isCorrect--;
            mistakes++;
        }
        ++_charCntr;
    }
    else
    {
        // handle the errors
        qDebug() << "Index out of range";
    }

}

void MainWindow::skip(int ms)
{
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, &QEventLoop::quit);
    loop.exec();
}

void MainWindow::outputStat()
{
    //float n = 100.0F*(static_cast<float>(correct))/(correct + mistakes);

    ui->label_Accuracy->setText(QString::number((100.0F*correct)/(correct + mistakes)) + "%");
    ui->label_WordsNum->setText(QString::number(((words + 1)/ (time_Msec/1000.0 + time_sec + time_min*60.0))*60.0f) + " words per minute");
    ui->symPerSecond->setText(QString::number((float)(ui->TextToWrite->toPlainText().size())/(time_sec + time_min*60.0 + time_Msec/1000.0)));
    mistakes = 0;
    words = 0;
    isCorrect = 0;
    correct = 0;
}

void MainWindow::updateTimer()
{
    time_Msec++;
    if(time_Msec >= 1000)
    {
        time_Msec = 0;
        time_sec++;
    }
    if(time_sec >= 60)
    {
        time_sec = 0;
        time_min++;
    }

    // Update the label with the new time
    ui->timer->setText(QString::number(time_min) + ":" + QString::number(time_sec) + ":" + QString::number(time_Msec));
}

void MainWindow::on_pushButton_chooseText_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open text for the keyboard writing", "", "");
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    _currentText = in.readAll();
    file.close();
    setTextToWrite(_currentText);
}

void MainWindow::on_ChangeLang_currentIndexChanged(int index)
{
    auto lang_1 = static_cast<language>(_angl + index);
    _keyboard->setLanguage(lang_1);
    switch(index)
    {
    case 0:
        _currentText = "Grisha and Kolya went to the forest. They were picking mushrooms and berries.";
        break;
    case 1:
        _currentText = "Грыша і Коля пайшлі ў лес. Яны збіралі грыбы і ягады.";
        break;
    case 2:
        _currentText = "Гриша и Коля пошли в лес. Они собирали грибы и ягоды.";
        break;
    case 3:
        _currentText = "ضصثقفغعهخحجة\شسيبلاتنمك؛ظطذدزروضضثيتبرذ،ذتدزذ،";
        break;
    case 4:
        _currentText = "Grisha und Kolya gingen in den Wald. Sie sammelten Pilze und Beeren.";
        break;
    case 5:
        _currentText = "גרישה וקוליה הלכו ליער. הם אספו פטריות ופירות יער.";
        break;
    case 6:
        //_currentText = "Mei gui shi hong se de Zi luo lan shi lan se de Tang shi tian de Ni ye shi.";
        _currentText = "你 合作 呢 突然 水電工 餓餓餓 波";
        break;
    case 7:
        _currentText = "Grisha et Kolya sont allés dans la forêt. Ils cueillaient des champignons et des baies.";
        break;
    default:
        _currentText = "Language not supported.";
        break;
    }
    setTextToWrite(_currentText);
}

void MainWindow::on_startButton_clicked()
{
    int index = KeyLayout.at(lang).indexOf(_currentText.at(0).toLower());
    _keyboard->makeButtonBlue(index);
    _charCntr = 0;
    mistakes = 0;
    correct = 0;
    setTextToWrite(_currentText);
    lang = _keyboard->getLanguage();
    lang--;
    ui->TextInput->setEnabled(true);
    ui->TextInput->setText("");
    ui->TextInput->setFocus();
    time_Msec = 0;
    time_sec = 0;
    time_min = 0;
    _timer->start(1);
}

void MainWindow::on_stopButton_clicked()
{
    _timer->stop();
    time_Msec = 0;
    time_sec = 0;
    time_min = 0;
    ui->TextInput->setEnabled(true);
    ui->TextInput->setText("");
    ui->TextInput->setFocus();
    _charCntr = 0;
    mistakes = 0;
    correct = 0;
}

void MainWindow::on_TextInput_textChanged(const QString &arg1)
{
    if(_charCntr >= ui->TextToWrite->toPlainText().size())
    {
        _timer->stop();
        outputStat();
        _charCntr = 0;
        ui->TextInput->setEnabled(false);
        _charCntr = 0;
        return;
    }

    QString text = ui->TextInput->text();
    size_t s = text.size();
    if(s != 0)
    {
    auto ch = static_cast<QChar>(text.at(s - 1));
    ColorText(ch);
    }
}

