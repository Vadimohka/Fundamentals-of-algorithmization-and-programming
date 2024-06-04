#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton {"
                                  "background-color: #4CAF50;"
                                  "border: none;"
                                  "color: white;"
                                  "padding: 15px 32px;"
                                  "text-align: center;"
                                  "text-decoration: none;"
                                  "font-size: 16px;"
                                  "margin: 4px 2px;"
                                  "border-radius: 10px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: #45a049;"
                                  "}");
    ui->pushButton_2->setStyleSheet("QPushButton {"
                                  "background-color: #4CAF50;"
                                  "border: none;"
                                  "color: white;"
                                  "padding: 15px 32px;"
                                  "text-align: center;"
                                  "text-decoration: none;"
                                  "font-size: 16px;"
                                  "margin: 4px 2px;"
                                  "border-radius: 10px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: #45a049;"
                                  "}");
    ui->pushButton_3->setStyleSheet("QPushButton {"
                                  "background-color: #4CAF50;"
                                  "border: none;"
                                  "color: white;"
                                  "padding: 15px 32px;"
                                  "text-align: center;"
                                  "text-decoration: none;"
                                  "font-size: 16px;"
                                  "margin: 4px 2px;"
                                  "border-radius: 10px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: #45a049;"
                                  "}");
    ui->pushButton_4->setStyleSheet("QPushButton {"
                                  "background-color: #4CAF50;"
                                  "border: none;"
                                  "color: white;"
                                  "padding: 15px 32px;"
                                  "text-align: center;"
                                  "text-decoration: none;"
                                  "font-size: 16px;"
                                  "margin: 4px 2px;"
                                  "border-radius: 10px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: #45a049;"
                                  "}");
    ui->pushButton_5->setStyleSheet("QPushButton {"
                                  "background-color: #4CAF50;"
                                  "border: none;"
                                  "color: white;"
                                  "padding: 15px 32px;"
                                  "text-align: center;"
                                  "text-decoration: none;"
                                  "font-size: 16px;"
                                  "margin: 4px 2px;"
                                  "border-radius: 10px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: #45a049;"
                                  "}");
    ui->pushButton_6->setStyleSheet("QPushButton {"
                                    "background-color: #4CAF50;"
                                    "border: none;"
                                    "color: white;"
                                    "padding: 15px 32px;"
                                    "text-align: center;"
                                    "text-decoration: none;"
                                    "font-size: 16px;"
                                    "margin: 4px 2px;"
                                    "border-radius: 10px;"
                                    "}"
                                    "QPushButton:hover {"
                                    "background-color: #45a049;"
                                    "}");
    ch1.push_back(ui->checkBox);
     ch2.push_back(ui->pushButton);
    for(int i=0;i<28;++i)
    {
        QString h="checkBox_"+QString::number(i+1);
        QCheckBox *ch=this->findChild<QCheckBox*>(h);
        if(ch)
        {

            ch1.push_back(ch);
        }
        QObject::connect(ch1[i], &QCheckBox::clicked, [=]() {
            for (QCheckBox *btn : ch1) {
                if (btn != ch1[i]) {
                    btn->hide();
                }
            }
        });
    }
    for(int i=1;i<6;++i)
    {
        QString h="pushButton_"+QString::number(i+1);
        QPushButton *ch=this->findChild<QPushButton*>(h);
        if(ch)
        {

            ch2.push_back(ch);
        }
    }
    for(int i=0;i<28;++i)
    {

        ch1[i]->setVisible(false);
        ch1[i]->setEnabled(false);
    }
    ui->pushButton_6->setVisible(false);


    state.resize(28);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


    Download h;

    h.Hide(ch2,ch1);


    fl1=1;
    fl2=0;
    fl3=0;


}


void MainWindow::on_pushButton_2_clicked()
{



    st_info.resize(28);
    st_info[0]=500;
    st_info[1]=1500;
    st_info[2]=410;
    st_info[3]=380;
    st_info[4]=114;
    st_info[5]=50.5;
    st_info[6]=2000;
    st_info[7]=78;
    st_info[8]=3000;
    st_info[9]= 180;
    st_info[10]=5.3;
    st_info[11]= 59.46;
    st_info[12]=10.5;
    st_info[13]=4.48;
    st_info[14]=120;
    st_info[15]=85.57;
    st_info[16]=1640;
    st_info[17]=20;
    st_info[18] =69.9;
    st_info[19]=112;
    st_info[20]=70;
    st_info[21]=1700;
    st_info[22]=200;
    st_info[23]=50;
    st_info[24] =64.7;
    st_info[25] =365;
    st_info[26] = 38;
    st_info[27]=20;
    Download_nv h;

    h.Hide(ch2,ch1,st_info);

    fl1=0;
    fl2=1;
    fl3=0;

}


void MainWindow::on_pushButton_4_clicked()
{
    Update h;
    for(int i=0;i<28;++i)
    {
        ch1[i]->setChecked(false);
    }
    std::string maine;
    maine=h.process();
    QMessageBox::information(nullptr,"Обновление","Все приложения будут обновлены, ожидайте 20 минут");
    QString program = "powershell.exe";
    QStringList arguments;
    arguments  << "-Command" << "Start-Process powershell -Verb runAs -ArgumentList '" << QString::fromStdString(maine)+"'";  ;
    process.start(program, arguments);
}


void MainWindow::on_pushButton_5_clicked()
{

    h.process();
    h.show();





}


void MainWindow::on_pushButton_3_clicked()
{
    Delete h;

    h.Hide(ch2,ch1);
    fl1=0;
    fl2=0;
    fl3=1;
}


void MainWindow::on_pushButton_6_clicked()
{
    if(fl1)
    {
        std::string maine;
        Download h;


        for(int i=0;i<28;++i)
        {
            if(ch1[i]->isChecked())
            {
              maine=  h.process(i);
                QString program = "powershell.exe";
                QStringList arguments;
                arguments  << "-Command" << "Start-Process powershell -Verb runAs -ArgumentList '" << QString::fromStdString(maine)+"'";  ;
                process.start(program, arguments);
                state[i]=1;


            }
            else {
                state[i]=0;
            }

        }
        qDebug() << process.state();
        QFile file("../../logs.txt");
        QTextStream out(&file);
        QString tmp;
        file.open(QIODevice::ReadOnly);
        while(!out.atEnd())
        {
            tmp = out.readLine();
        }
        file.close();
        QDate curr=QDate::currentDate();

        QTextStream in(&file);
        file.open(QIODevice::Append);
        in << curr.toString(Qt::ISODate) << "\n";
        for(int i=0;i<28;++i)
        {
            if(state[i])
            {
                tmp[i]='1';
            }
        }
        in << tmp;
        in << "\n";



    }
    else if(fl2)
    {
        std::string maine;
        Download_nv h;


        for(int i=0;i<28;++i)
        {
            if(ch1[i]->isChecked())
            {
                maine=  h.process(i);
                QString program = "powershell.exe";
                QStringList arguments;
                arguments  << "-Command" << "Start-Process powershell -Verb runAs -ArgumentList '" << QString::fromStdString(maine)+"'";  ;
                process.start(program, arguments);
                state[i]=1;


            }
            else {
                state[i]=0;
            }

        }
        qDebug() << process.state();
        QFile file("../../logs.txt");
        QTextStream out(&file);
        QString tmp;
        file.open(QIODevice::ReadOnly);
        while(!out.atEnd())
        {
            tmp = out.readLine();
        }
        file.close();
        QDate curr=QDate::currentDate();

        QTextStream in(&file);
        file.open(QIODevice::Append);
        in << curr.toString(Qt::ISODate) << "\n";
        for(int i=0;i<28;++i)
        {
            if(state[i])
            {
                tmp[i]='1';
            }
        }
        in << tmp;
        in << "\n";
    }
    else if(fl3)
    {
        std::string maine;
        Delete h;


        for(int i=0;i<28;++i)
        {
            if(ch1[i]->isChecked())
            {
                maine=  h.process(i);
                QString program = "powershell.exe";
                QStringList arguments;
                arguments  << "-Command" << "Start-Process powershell -Verb runAs -ArgumentList '" << QString::fromStdString(maine)+"'";  ;
                process.start(program, arguments);
                state[i]=2;


            }
        }
        qDebug() << process.state();
        QFile file("../../logs.txt");
        QTextStream out(&file);
        QString tmp;
        file.open(QIODevice::ReadOnly);
        while(!out.atEnd())
        {
            tmp = out.readLine();
        }
        file.close();
        QDate curr=QDate::currentDate();

        QTextStream in(&file);
        file.open(QIODevice::Append);
        in << curr.toString(Qt::ISODate) << "\n";
        for(int i=0;i<28;++i)
        {
            if(tmp[i]=='1' && state[i]==2)
            {
                tmp[i]='0';
            }
        }
        in << tmp;
        in << "\n";
    }
    for(int i=0;i<28;++i)
    {

        ch1[i]->setVisible(false);
        ch1[i]->setEnabled(false);
    }
    ui->pushButton_6->setVisible(false);
    for(int i=0;i<5;++i)
    {
        ch2[i]->setVisible(true);
    }
}

