#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Light = new QTimer(this);
    Timer = new QTimer(this);
    connect(Light, SIGNAL(timeout()), this, SLOT(Light_slot()));
    connect(Timer, SIGNAL(timeout()), this, SLOT(Timer_slot()));
    ui->textEdit->setText(Text[0]);
    fmt = ui->textEdit->currentCharFormat();
    //qDebug() << alphabet[3][29] << alphabet[3][40] << alphabet[3][28] << alphabet[3][39];
    k[96] = 0;
    k[49] = 1;
    k[50] = 2;
    k[51] = 3;
    k[52] = 4;
    k[53] = 5;
    k[54] = 6;
    k[55] = 7;
    k[56] = 8;
    k[57] = 9;
    k[48] = 10;
    k[45] = 11;
    k[61] = 12;
    k[81] = 13;
    k[87] = 14;
    k[69] = 15;
    k[82] = 16;
    k[84] = 17;
    k[89] = 18;
    k[85] = 19;
    k[73] = 20;
    k[79] = 21;
    k[80] = 22;
    k[91] = 23;
    k[93] = 24;
    k[65] = 25;
    k[83] = 26;
    k[68] = 27;
    k[70] = 28;
    k[71] = 29;
    k[72] = 30;
    k[74] = 31;
    k[75] = 32;
    k[76] = 33;
    k[59] = 34;
    k[39] = 35;
    k[90] = 36;
    k[88] = 37;
    k[67] = 38;
    k[86] = 39;
    k[66] = 40;
    k[78] = 41;
    k[77] = 42;
    k[44] = 43;
    k[46] = 44;
    k[47] = 45;
    k[Qt::Key_Space] = 46;
    m[0] = ui->pushButton1;
    m[1] = ui->pushButton2;
    m[2] = ui->pushButton3;
    m[3] = ui->pushButton4;
    m[4] = ui->pushButton5;
    m[5] = ui->pushButton6;
    m[6] = ui->pushButton7;
    m[7] = ui->pushButton8;
    m[8] = ui->pushButton9;
    m[9] = ui->pushButton10;
    m[10] = ui->pushButton11;
    m[11] = ui->pushButton12;
    m[12] = ui->pushButton13;
    m[13] = ui->pushButton14;
    m[14] = ui->pushButton15;
    m[15] = ui->pushButton16;
    m[16] = ui->pushButton17;
    m[17] = ui->pushButton18;
    m[18] = ui->pushButton19;
    m[19] = ui->pushButton20;
    m[20] = ui->pushButton21;
    m[21] = ui->pushButton22;
    m[22] = ui->pushButton23;
    m[23] = ui->pushButton24;
    m[24] = ui->pushButton25;
    m[25] = ui->pushButton26;
    m[26] = ui->pushButton27;
    m[27] = ui->pushButton28;
    m[28] = ui->pushButton29;
    m[29] = ui->pushButton30;
    m[30] = ui->pushButton31;
    m[31] = ui->pushButton32;
    m[32] = ui->pushButton33;
    m[33] = ui->pushButton34;
    m[34] = ui->pushButton35;
    m[35] = ui->pushButton36;
    m[36] = ui->pushButton37;
    m[37] = ui->pushButton38;
    m[38] = ui->pushButton39;
    m[39] = ui->pushButton40;
    m[40] = ui->pushButton41;
    m[41] = ui->pushButton42;
    m[42] = ui->pushButton43;
    m[43] = ui->pushButton44;
    m[44] = ui->pushButton45;
    m[45] = ui->pushButton46;
    m[46] = ui->pushButton47;
}

void MainWindow::Timer_slot()
{
    sec += 50;
}

void MainWindow::Light_slot()
{
    if (light_flag) {
        m[curr_button]->setStyleSheet("background-color: white;");
        flag2 = true;
        light_flag = false;
    }
    light_flag = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    alphabet_index = index;
    ui->textEdit->setText(Text[index]);
    for (int i = 0; i < 47; i++) {
        m[i]->setText(alphabet[index][i]);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (flag && flag2 && event->key() < 100000) {
        all++;
        curr_button = k[event->key()];
        if (alphabet[alphabet_index][k[event->key()]] == Text[alphabet_index][right]) {
            right_text = Text[alphabet_index].mid(0, right + 1);
            other_text = Text[alphabet_index].mid(right + 1, Text[alphabet_index].size());
            ui->textEdit->clear();
            fmt.setForeground(QBrush(Qt::green));
            ui->textEdit->setCurrentCharFormat(fmt);
            ui->textEdit->append(right_text);
            fmt.clearForeground();
            ui->textEdit->setCurrentCharFormat(fmt);
            ui->textEdit->append(other_text);
            right++;
            m[k[event->key()]]->setStyleSheet("background-color: green;");
            //Light->start(30);
            flag2 = false;
            if (right == Text[alphabet_index].size()) {
                on_pushButton_2_clicked();
                //flag2 = true;
            }
        } else {
            qDebug() << alphabet[alphabet_index][k[event->key()]] << Text[alphabet_index][right];
            m[k[event->key()]]->setStyleSheet("background-color: red;");
            //Light->start(30);
            flag2 = false;
        }
        qDebug() << event->key();
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (!flag) {
        ui->textEdit->setText(Text[alphabet_index]);
        sec = 0;
        right = 0;
        all = 0;
        Timer->start(50);
        flag = true;
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->comboBox->setEnabled(false);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (flag) {
        flag = false;
        m[curr_button]->setStyleSheet("background-color: white;");
        flag2 = true;
        //qDebug() << 1;
        Timer->stop();
        //qDebug() << 3;
        if (all == 0) {
            msgbox.setText("Время: " + QString::number(double(sec) / 1000)
                           + "\nКоличество символов в минуту: "
                           + QString::number(double(right) / sec * 60000)
                           + "\nТочность: " + QString::number(0));
        } else {
            msgbox.setText("Время: " + QString::number(double(sec) / 1000)
                           + "\nКоличество символов в минуту: "
                           + QString::number(double(right) / sec * 60000)
                           + "\nТочность: " + QString::number(double(right) / all * 100));
        }
        //qDebug() << 2;
        ui->comboBox->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        msgbox.exec();
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (!flag2) {
        m[curr_button]->setStyleSheet("background-color: white;");
        flag2 = true;
        //light_flag = false;
    }
}
