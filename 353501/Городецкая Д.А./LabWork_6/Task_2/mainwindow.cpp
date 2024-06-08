#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(start()));
    timer.start(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::start()
{
    QTextStream s;
    bool costyl=1;
    int n;
    while(costyl)

    {
        timer.start(100);
        QCoreApplication::processEvents();
        timer.stop();
        QPixmap pixmap("/home/diana/Documents/labs_oaip/LabWork_6/Task_2/New Folder/images.jpeg");
        ui->label_4->setPixmap(pixmap);
        ui->label_3;
        // ui->label_3->setStyleSheet("color: #000000;");
        ui->label_3->update();
        ui->label_4->update();
        bool ok=0;

        n = QInputDialog::getInt(nullptr, "Ввод числа", "Введите число (номер курса):", 0, 0, 10, 1, &ok);

        switch (n){
        case 1:
        {
            QString text = QInputDialog::getText(nullptr, "Ввод строки", "Введите символы, прекращение ввода - энтер");
            QString path = "/home/diana/Documents/labs_oaip/LabWork_6/Task_2/New Folder/ГородецкаяЛаб20.txt";
            QFile file(path);
            if (file.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&file);
                out << text << "\n"; // Write the entire QString to the file
                file.close();
            } else {
                QMessageBox::critical(nullptr, "Error", "Unable to open file: " + file.errorString());
            }
            break;
        }
        case 2:
        {
            QString path="/home/diana/Documents/labs_oaip/LabWork_6/Task_2/New Folder/ГородецкаяЛаб20.txt";
            QFile file(path);
            QTextStream in(&file);
            QString s;
            qDebug() << sizeof(file);
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            while(!in.atEnd()){
                in >> s;
            }
            file.close();
            ui->label_2->setText(s);
            ui->label_2->update();
            break;
        }
        case 3:
        {
            bool fl1=1;
            while(fl1){
                QString text = QInputDialog::getText(nullptr, "Ввод строки", "Введите массив ushort c разделяющим элементом *, прекращение ввода - энтер");
                for(int i=0;i<text.size();++i)
                {
                    if(i==text.size())
                    {
                        fl1=0;
                        break;
                    }
                    if(text[i]=='*' && i==0)
                    {
                        QMessageBox::warning(nullptr, "Alert","Error");
                        break;
                    }
                    else
                    {
                        if(text[0]=='-')
                        {
                            int tmp=0;
                            bool l=0;
                            while(i!=text.size() && tmp<-32768 && text[i]!='*' )
                            {
                                char a=text[i].toLatin1();
                                tmp=tmp-a+'0';
                                if(a<'0' || a>'0')
                                {
                                    l=1;

                                }
                                ++i;
                            }
                            if(tmp<-32768 || l)
                            {
                                QMessageBox::warning(nullptr, "Alert","Error");
                                break;
                            }

                        }
                        else
                        {

                            int tmp=0;
                            bool l=0;
                            while(i!=text.size() && tmp<32768 && text[i]!='*')
                            {
                                char a=text[i].toLatin1();
                                if(a<'0' || a>'9')
                                {
                                    l=1;

                                }
                                tmp=tmp+a+'0';
                                ++i;
                            }
                            if(tmp>32768 ||l)
                            {
                                QMessageBox::warning(nullptr, "Alert","Error");
                                break;
                            }
                        }
                        if(i==text.size()) fl1=0;
                    }
                }

                QString path="/home/diana/Documents/labs_oaip/LabWork_6/Task_2/New Folder/ГородецкаяЛаб20_0.txt";
                QFile file(path);
                QTextStream in(&file);
                // QString s;
                file.open(QIODevice::WriteOnly | QIODevice::Text);

                in << text;

                file.close();

            }
        }
        case 4:
        {
            QString path="/home/diana/Documents/labs_oaip/LabWork_6/Task_2/New Folder/ГородецкаяЛаб20_0.txt";
            QFile file(path);
            QTextStream in(&file);
            QString s;
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            while(!in.atEnd()){
                in >> s;
            }
            file.close();
            for (int i=0;i<s.length();++i)
            {
                if(i%2!=0)
                {
                    s[i]=' ';
                }
            }
            ui->label_2->setText(s);
            ui->label_2->update();
            break;
        }
        case 5:
        {
            std::string aa="";
            bool ok;
            bool fl1=1;
            while(fl1){
                int number = QInputDialog::getInt(nullptr, "Ввод числа", "Введите число (номер курса):", 0, 0, 100000, 1, &ok);
                if (ok) {
                    fl1=0;
                    QMessageBox::information(nullptr, "Число", QString("Вы ввели число: %1").arg(number));
                    pl1.course_number=number;
                } else {
                    fl1=1;
                    QMessageBox::warning(nullptr, "Alert","Error");
                }

            }
            fl1=1;
            double number1 = QInputDialog::getDouble(nullptr, "Ввод числа", "Введите число (время полета):", 0, 0.0, 100000.0, 1, &ok);
            while(fl1){
                if (ok) {
                    fl1=0;
                    QMessageBox::information(nullptr, "Число", QString("Вы ввели число: %1").arg(number1));
                    pl1.time_duartion=number1;
                }
                else {
                    fl1=1;
                    QMessageBox::warning(nullptr, "Alert","Error");
                }
            }
            fl1=1;
            while(fl1){
                QString text = QInputDialog::getText(nullptr, "Ввод символа", "Введите один символ( тип самолета):");
                QChar symbol;
                if (!text.isEmpty() && text.length() == 1) {
                    symbol = text.at(0);
                    pl1.type=symbol.toLatin1();
                    fl1=0;
                    QMessageBox::information(nullptr, "Символ", QString("Вы ввели символ: %1").arg(symbol));

                    aa+=pl1.type;
                }
                else {
                    fl1=1;
                    QMessageBox::warning(nullptr, "Alert","Error");
                }
            }
            fl1=1;
            QString text;
            while(fl1){
                text = QInputDialog::getText(nullptr, "Ввод символа", "Введите имя самолета  не более 10 символов");
                QChar symbol;
                if (!text.isEmpty() && text.length() <= 10) {
                    symbol = text.at(0);
                    fl1=0;
                    QMessageBox::information(nullptr, "Символ", QString("Вы ввели символ: %1").arg(symbol));
                }
                else {
                    fl1=1;
                    QMessageBox::warning(nullptr, "Alert","Error");
                }
                for(int i=0;i<text.length();++i)
                {
                    pl1.name[i]=text[i].toLatin1();
                }
            }

            for(int i=0;i<3;++i){
                int number = QInputDialog::getInt(nullptr, "Ввод числа", "Введите число (колво пассажиров):", 0, 0, 100000, 1, &ok);
                if (ok) {
                    fl1=0;
                    QMessageBox::information(nullptr, "Число", QString("Вы ввели число: %1").arg(number));
                    pl1.people_amount[i]=number;
                } else {
                    fl1=1;
                    --i;
                    QMessageBox::warning(nullptr, "Alert","Error");
                }
                fl1=0;
            }
            QString path="/home/diana/Documents/labs_oaip/LabWork_6/Task_2/New Folder/ГородецкаяЛаб20_1.txt";
            QFile file(path);
            QTextStream in(&file);
            // QString s;
            file.open(QIODevice::Append | QIODevice::Text);

            in << pl1.course_number << " ";
            in << pl1.time_duartion << " ";
            in << pl1.type<< " ";
            for(int i=0;i<3;++i)
            {
                in << pl1.people_amount[i] << " ";
            }
            for(int i=0;i<text.length();++i)
            {
                in << pl1.name[i] << " ";
            }
            in << "\n";
            file.close();
        }
        case 6:
        {
            QString path="/home/diana/Documents/labs_oaip/LabWork_6/Task_2/New Folder/ГородецкаяЛаб20_1.txt";
            QFile file(path);
            QTextStream in(&file);
            QString s;
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            while(!in.atEnd()){
                in >> s;
                s+" | ";
                ui->label_2->setText(s);
                s.clear();
            }

        }
        case 7:
        {
            std::string aa="";
            bool ok;
            bool fl1=1;
            while(fl1){
                int number = QInputDialog::getInt(nullptr, "Ввод числа", "Введите число (номер курса):", 0, 0, 100000, 1, &ok);
                if (ok) {
                    fl1=0;
                    QMessageBox::information(nullptr, "Число", QString("Вы ввели число: %1").arg(number));
                    pl1.course_number=number;
                } else {
                    fl1=1;
                    QMessageBox::warning(nullptr, "Alert","Error");
                }

            }
            fl1=1;
            double number1 = QInputDialog::getDouble(nullptr, "Ввод числа", "Введите число (время полета):", 0, 0.0, 100000.0, 1, &ok);
            while(fl1){
                if (ok) {
                    fl1=0;
                    QMessageBox::information(nullptr, "Число", QString("Вы ввели число: %1").arg(number1));
                    pl1.time_duartion=number1;
                }
                else {
                    fl1=1;
                    QMessageBox::warning(nullptr, "Alert","Error");
                }
            }
            fl1=1;
            while(fl1){
                QString text = QInputDialog::getText(nullptr, "Ввод символа", "Введите один символ( тип самолета):");
                QChar symbol;
                if (!text.isEmpty() && text.length() == 1) {
                    symbol = text.at(0);
                    pl1.type=symbol.toLatin1();
                    fl1=0;
                    QMessageBox::information(nullptr, "Символ", QString("Вы ввели символ: %1").arg(symbol));

                    aa+=pl1.type;
                }
                else {
                    fl1=1;
                    QMessageBox::warning(nullptr, "Alert","Error");
                }
            }
            fl1=1;
            QString text;
            while(fl1){
                text = QInputDialog::getText(nullptr, "Ввод символа", "Введите имя самолета  не более 10 символов");
                QChar symbol;
                if (!text.isEmpty() && text.length() <= 10) {
                    symbol = text.at(0);
                    fl1=0;
                    QMessageBox::information(nullptr, "Символ", QString("Вы ввели символ: %1").arg(symbol));
                }
                else {
                    fl1=1;
                    QMessageBox::warning(nullptr, "Alert","Error");
                }
                for(int i=0;i<text.length();++i)
                {
                    pl1.name[i]=text[i].toLatin1();
                }
            }

            for(int i=0;i<3;++i){
                int number = QInputDialog::getInt(nullptr, "Ввод числа", "Введите число (колво пассажиров):", 0, 0, 100000, 1, &ok);
                if (ok) {
                    fl1=0;
                    QMessageBox::information(nullptr, "Число", QString("Вы ввели число: %1").arg(number));
                    pl1.people_amount[i]=number;
                } else {
                    fl1=1;
                    --i;
                    QMessageBox::warning(nullptr, "Alert","Error");
                }
                fl1=0;
            }
            QString path="/home/diana/Documents/labs_oaip/LabWork_6/Task_2/New Folder/ГородецкаяЛаб20_2.bin";
            QFile file(path);
            QTextStream in(&file);
            // QString s;
            file.open(QIODevice::Append | QIODevice::Text);
            file.write(reinterpret_cast<char*>(&pl1), sizeof(pl1));
            file.close();

        }
        case 8:
        {

            QString path="/home/diana/Documents/labs_oaip/LabWork_6/Task_2/New Folder/ГородецкаяЛаб20_2.bin";
            QFile file(path);
            qint64 fileSize = file.size();
            qint64 structSize = sizeof(pl1);
            int numStructs = fileSize / structSize;
            QTextStream in(&file);
            QString s;
            std::string aa;
            PLANE pl2;
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            while(numStructs>0)
            {
                file.read(reinterpret_cast<char*>(&pl2), sizeof(pl1));
                numStructs--;
                s+=QString::number(pl2.course_number);
                s+=QString::number(pl2.time_duartion);
                aa=pl2.type;
                s+=QString::fromStdString(aa);
                for(int i=0;i<sizeof(pl1.name);++i)
                {
                    s+=pl1.name[i];
                }
                for(int i=0;i<sizeof(pl1.people_amount);++i)
                {
                    s+=QString::number(pl1.people_amount[i]);
                }
                s+=" ; ";
            }


            file.close();
            ui->label_2->setText(s);
        }
        case 9:
        {
            QString path="/home/diana/Documents/labs_oaip/LabWork_6/Task_2/New Folder/ГородецкаяЛаб20_3.txt";
            QFile file(path);
            QTextStream in(&file);
            file.open(QIODevice::Append | QIODevice::Text);
            QString text;
            text = QInputDialog::getText(nullptr, "Ввод ", "Введите строку");
            in << text;
            file.close();


        }
        case 10:
        {
            QString path="/home/diana/Documents/labs_oaip/LabWork_6/Task_2/New Folder/ГородецкаяЛаб20_3.txt";
            QFile file(path);
            QTextStream in(&file);
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QString text;

            while(!in.atEnd())
            {
                in >> text;
            }
            ui->label_2->setText(text);
            file.close();
        }
        default:
        {
            costyl=0;
            break;
            timer.stop();

        }
        }
    }
}
