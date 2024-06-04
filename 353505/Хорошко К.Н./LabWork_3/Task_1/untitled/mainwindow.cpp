#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000, 400);

    out.setParent(this);
    out.setStyleSheet("background-color: white; color: black;");
    input.setParent(this);
    input.setFocusPolicy(Qt::StrongFocus);
    input.setMaxLength(307);
    QObject::connect(&input, &QLineEdit::editingFinished, [&]() {
        input.clearFocus();
        QString wvod = input.text();

            bool znak = false;
            if (wvod[0] == '-'){
                znak = true;
                wvod.remove(0, 1);
            }

            if (!proverka(wvod))
            {
                input.clear();
                QMessageBox messageBox;
                messageBox.setText("Некоректное значение");
                messageBox.exec();
            }
            else
            {

            QString integer;
            QString ostatok;

            def(integer, ostatok, wvod, 0, true);

            QVector<int> int_number;
            QVector<int> ost_number;

            for (int i = 0; i < integer.size(); i++){
                int_number.push_back(integer[i].digitValue());
            }

            for (int i = 0; i < ostatok.size(); i++){
                ost_number.push_back(ostatok[i].digitValue());
            }

            QVector<int> bool_int_number;
            QVector<int> bool_ost_number;

            integ(bool_int_number, int_number);
            reverse(bool_int_number);
            ostat(bool_ost_number, ost_number, 0);

            QString ans;
            answer(bool_int_number, bool_ost_number, ans, znak);
            out.setText(ans);
        }

    });

    input.setGeometry(100, 50, 800, 50);
    out.setGeometry(100, 250, 800, 50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::perevod(long long x, QString& ans){
    long long buf = x % 2;
    x = x/2;
    ans += QString::number(buf);
    if (x > 0) {
        perevod(x, ans);
    }
    else {
        QString buf;
        for (int i = 1; i < ans.size(); i++){
            buf.push_back(ans[i]);
        }
        for (int i = 0; i < ans.size()-1; i++){
            ans[i+1] = buf[buf.size()-1-i];
        }
    }
}
bool MainWindow::proverka(QString wwod){
    bool point = true;
    for (int i = 1; i < wwod.size(); i++){
        if (wwod[i] == '.' && point){
            point = false;
        }
        else if (wwod[i] < '0' || wwod[i] > '9'){
            return false;
        }
    }
    return true;
}
void MainWindow::def(QString& integer, QString& ostatok, QString wvod, int position, bool buf){
    if (position < wvod.size()){
        if (wvod[position] != '.' && buf){
        integer += wvod[position];
        position++;
        def(integer, ostatok, wvod, position, buf);}
        else if (wvod[position] == '.'){
        buf = false;
        position++;
        def(integer, ostatok, wvod, position, buf);
        }
        else if(position < wvod.size()){
        ostatok += wvod[position];
        position++;
        def(integer, ostatok, wvod, position, buf);
        }
    }
}
void MainWindow::integ(QVector<int>& bool_int_number, QVector<int>& int_number){
    int buf = 0;
    for (int i = 0; i < int_number.size(); i++){
        buf = int_number[i] % 2;
        int_number[i] /= 2;
        if (i < int_number.size()-1){
            int_number[i+1] += buf*10;
        }
        else {
            bool_int_number.push_back(buf);
        }
    }

    while (true){
        if (int_number.size() > 0){
        if (int_number[0] == 0){
            int_number.removeFirst();
        }
        else
        {
            break;
        }
        }
        else
        {
        break;
        }
    }

    if (int_number.size() > 0){
        integ(bool_int_number, int_number);
    }
}
void MainWindow::ostat(QVector<int>& bool_ost_number, QVector<int>& ost_number, int num){
    int buf = 0;
    for (int i =  ost_number.size()-1; i >= 0; i--){
        ost_number[i] *= 2;
        ost_number[i] += buf;
        buf = ost_number[i] / 10;
        ost_number[i] %= 10;
        if (i == 0){
            bool_ost_number.push_back(buf);
        }
    }
    if (num <  150){
        num++;
        ostat(bool_ost_number, ost_number, num);
    }
}
void MainWindow::reverse(QVector<int>& bool_int_number){
    QVector<int> buf;
    for (int i = 0; i < bool_int_number.size(); i++){
        buf.push_back(bool_int_number[bool_int_number.size() - 1 - i]);
    }

    for (int i = 0; i < bool_int_number.size(); i++){
        bool_int_number[i] = buf[i];
    }
}
void MainWindow::answer(QVector<int> bool_int_number, QVector<int> bool_ost_number, QString& ans, bool znak){
    int exp = 0;
    if (bool_int_number.size() > 0){
        exp = bool_int_number.size()-1;
        if (znak){
            ans += "1";
        }
        else {
            ans += "0";
        }
        exp += 1023;
        perevod(exp, ans);
        for (int i = 1; i < bool_int_number.size(); i++){
            if (i < 53) {
                ans += QString::number(bool_int_number[i]);
            }
            else
            {
                break;
            }
        }
        int max = 53-bool_int_number.size();
        for (int i = 0; i < max; i++){
            if (i < bool_ost_number.size()) {
                ans += QString::number(bool_ost_number[i]);
            }
            else {
                ans += '0';
            }
        }
    }
    else {
        while (true){
            if (bool_ost_number[0] == 0 && bool_ost_number.size() > 0){
                bool_ost_number.erase(bool_ost_number.begin());
                exp++;
            }
            else
            {
                break;
            }
        }
        exp += 1023;
        if (znak){
            ans += "1";
        }
        else {
            ans += "0";
        }
        perevod(exp, ans);
        for (int i = 0; i < 53; i++){
            if (i < bool_ost_number.size()) {
                ans += QString::number(bool_ost_number[i]);
            }
            else {
                ans += '0';
            }
        }
    }
}
