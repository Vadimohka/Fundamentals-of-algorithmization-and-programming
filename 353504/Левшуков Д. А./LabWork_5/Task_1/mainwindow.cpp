#include "mainwindow.h"
#include "ui_mainwindow.h"

#define Button(x) ui->b##x

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setBelarussian();


    timer = new QTimer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBelarussian()
{
    alphabet="Ё            ЙЦУКЕНГШЎЗХ'ФЫВАПРОЛДЖЭЯЧСМІТЬБЮ ё            йцукенгшўзх'фывапролджэячсмітьбю ";

    qDebug()<<alphabet[24];
    clearKeyboard();
}

void MainWindow::setDeutsch()
{
    alphabet="           ß QWERTZUIOPÜ ASDFGHJKLÖÄYXCVBNM              ß qwertzuiopü asdfghjklöäyxcvbnm   ";

    //qDebug()<<alphabet.size();
    clearKeyboard();
}

void MainWindow::setHebrew()
{
    alphabet="               קראטוןםפ  ";
    alphabet+="שדגכע חלךף";
    alphabet+=" ";
    alphabet+="זסבהנמצתץ";
    alphabet+=" ";
    alphabet=alphabet+alphabet;

    clearKeyboard();
}

void MainWindow::setArabic()
{
    alphabet="ذ١٢٣٤٥٦٧٨٩   ضصثقفغعهخحجدشسيبلاتنمكطئءؤرﻻىةوزظ";
    alphabet+="ذ            ضصثقفغعهخحجدشسيبلاتنمكطئءؤرﻻىةوزظ";

    clearKeyboard();
}

void MainWindow::setChinese()
{
    alphabet="             手田水口廿卜山戈人心  日尸木火土竹十大中  重内金女月弓    ";
    alphabet=alphabet+alphabet;

    clearKeyboard();
}

void MainWindow::setFrench()
{
    alphabet="             AZERTYUIOP¨ QSDFGHJKLM WXCVBN           è çà  azertyuiop^ qsdfghjklmùwxcvbn    ";
    qDebug()<<alphabet.size();
    clearKeyboard();
}

void MainWindow::correct_file(QString &file)
{
    QString extension;
    for(int i=file.size()-3;i<file.size();i++)
        extension+=file[i];

    if(extension==".by")
        setBelarussian();
    if(extension==".fr")
        setFrench();
    if(extension==".ch")
        setChinese();
    if(extension==".he")
        setHebrew();
    if(extension==".de")
        setDeutsch();
    if(extension==".ar")
        setArabic();

    QFile File(file);
    if (!File.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this,"Bad file","Crashed file");
        return;
    }

    QTextStream in(&File);

    bool wrong=false;
    int lines=0;
    QString s;

    while (!in.atEnd()) {

        lines++;
        if(lines==2)
        {
            qDebug()<<"LINES";
            wrong==true;
            break;
        }

        s = in.readLine();

        for(auto& i:s)
        {
            short j=0;
            QString b=i;
            qDebug()<<b;
            for(;j<delta*2;j++)
                if(alphabet[j]==i)
                    break;

            if(j!=delta*2)
                continue;
            else
            {
                wrong=true;
                break;
            }
        }


    }

    File.close();


    if(wrong)
    {
        QMessageBox::warning(this,"Bad file","Incorrect file contents");
        on_comboBox_currentIndexChanged(ui->comboBox->currentIndex());
        return;
    }


    if(extension==".by")
        ui->comboBox->setCurrentIndex(0);
    if(extension==".fr")
        ui->comboBox->setCurrentIndex(5);
    if(extension==".ch")
        ui->comboBox->setCurrentIndex(4);
    if(extension==".he")
        ui->comboBox->setCurrentIndex(1);
    if(extension==".de")
        ui->comboBox->setCurrentIndex(2);
    if(extension==".ar")
        ui->comboBox->setCurrentIndex(3);

    text=s;
    file="";

    QMessageBox::information(this,"Succesful","File upload. Push start button to start test");
    //ui->comboBox->

}

QPushButton *MainWindow::getButton(int ind)
{
    if(ind==1)
        return Button(1);
    if(ind==2)
        return Button(2);
    if(ind==3)
        return Button(3);
    if(ind==4)
        return Button(4);
    if(ind==5)
        return Button(5);
    if(ind==6)
        return Button(6);
    if(ind==7)
        return Button(7);
    if(ind==8)
        return Button(8);
    if(ind==9)
        return Button(9);
    if(ind==10)
        return Button(10);
    if(ind==11)
        return Button(11);
    if(ind==12)
        return Button(12);
    if(ind==13)
        return Button(13);
    if(ind==14)
        return Button(14);
    if(ind==15)
        return Button(15);
    if(ind==16)
        return Button(16);
    if(ind==17)
        return Button(17);
    if(ind==18)
        return Button(18);
    if(ind==19)
        return Button(19);
    if(ind==20)
        return Button(20);
    if(ind==21)
        return Button(21);
    if(ind==22)
        return Button(22);
    if(ind==23)
        return Button(23);
    if(ind==24)
        return Button(24);
    if(ind==25)
        return Button(25);
    if(ind==26)
        return Button(26);
    if(ind==27)
        return Button(27);
    if(ind==28)
        return Button(28);
    if(ind==29)
        return Button(29);
    if(ind==30)
        return Button(30);
    if(ind==31)
        return Button(31);
    if(ind==32)
        return Button(32);
    if(ind==33)
        return Button(33);
    if(ind==34)
        return Button(34);
    if(ind==35)
        return Button(35);
    if(ind==36)
        return Button(36);
    if(ind==37)
        return Button(37);
    if(ind==38)
        return Button(38);
    if(ind==39)
        return Button(39);
    if(ind==40)
        return Button(40);
    if(ind==41)
        return Button(41);
    if(ind==42)
        return Button(42);
    if(ind==43)
        return Button(43);
    if(ind==44)
        return Button(44);
    if(ind==45)
        return Button(45);
    if(ind==46)
        return Button(46);
    //Caps
    if(ind==47)
        return ui->CapsLock;
    //Shift
    if(ind==48)
        return ui->Shift;
    //Shift
    if(ind==49)
        return ui->Space;
    return Button(0);
}

void MainWindow::clearKeyboard()
{
    Caps_on=Shift_on=false;

    setKeyboard(delta);

    for(int i=1;i<=49;i++)
        getButton(i)->setStyleSheet(default_button);
}

int MainWindow::key_to_ind(int key)
{
    if(key==96||key==126)
        return 1;

    if(key==49)
        return 2;
    if(key==50)
        return 3;
    if(key==51)
        return 4;
    if(key==52)
        return 5;
    if(key==53)
        return 6;
    if(key==54)
        return 7;
    if(key==55)
        return 8;
    if(key==56)
        return 9;
    if(key==57)
        return 10;
    if(key==48)
        return 11;

    if(key==45||key==95)
        return 12;
    if(key==61)
        return 13;

    if(key==81)
        return 14;
    if(key==87)
        return 15;
    if(key==69)
        return 16;
    if(key==82)
        return 17;
    if(key==84)
        return 18;
    if(key==89)
        return 19;
    if(key==85)
        return 20;
    if(key==73)
        return 21;
    if(key==79)
        return 22;
    if(key==80)
        return 23;
    if(key==91||key==123)
        return 24;
    if(key==93||key==125)
        return 25;

    if(key==65)
        return 26;
    if(key==83)
        return 27;
    if(key==68)
        return 28;
    if(key==70)
        return 29;
    if(key==71)
        return 30;
    if(key==72)
        return 31;
    if(key==74)
        return 32;
    if(key==75)
        return 33;
    if(key==76)
        return 34;
    if(key==59||key==58)
        return 35;
    if(key==39||key==34)
        return 36;

    if(key==90)
        return 37;
    if(key==88)
        return 38;
    if(key==67)
        return 39;
    if(key==86)
        return 40;
    if(key==66)
        return 41;
    if(key==78)
        return 42;
    if(key==77)
        return 43;
    if(key==44||key==60)
        return 44;
    if(key==46||key==62)
        return 45;
    if(key==47||key==63)
        return 46;

    if(key==Qt::Key_CapsLock)
        return 47;
    if(key==Qt::Key_Shift)
        return 48;
    if(key==Qt::Key_Space)
        return 49;

    return 0;
}

void MainWindow::setKeyboard(int delta)
{
    for(int i=1;i<=46;i++)
    {
        getButton(i)->setText(alphabet[i-1+delta]);
    }
}

void MainWindow::genText()
{
    std::mt19937 gen(time(0));
    size=600+gen()%401;
    text=" ";
    int k=2;
    if(ui->comboBox->currentIndex()==1&&ui->comboBox->currentIndex()==4)
        k=1;
    while(text[0]==' ')
    {
        text[0]=alphabet[gen()%(delta*k)];
    }
    qDebug()<<text;


    for(int i=1;i<size-1;i++)
    {
        if(text.back()==QString("¨"))
        {
            qDebug()<<i;
            int rnd=gen()%11;
            switch(rnd)
            {
            case 0:
                text+="a";
                break;
            case 1:
                text+="e";
                break;
            case 2:
                text+="u";
                break;
            case 3:
                text+="i";
                break;
            case 4:
                text+="o";
                break;
            case 5:
                text+="y";
                break;
            case 6:
                text+="A";
                break;
            case 7:
                text+="E";
                break;
            case 8:
                text+="U";
                break;
            case 9:
                text+="I";
                break;
            case 10:
                text+="O";
                break;
            }
        }else
            if(text.back()==QString('^'))
        {
            int rnd=gen()%10;
            switch(rnd)
            {
            case 0:
                text+="a";
                break;
            case 1:
                text+="e";
                break;
            case 2:
                text+="u";
                break;
            case 3:
                text+="i";
                break;
            case 4:
                text+="o";
                break;
            case 5:
                text+="A";
                break;
            case 6:
                text+="E";
                break;
            case 7:
                text+="U";
                break;
            case 8:
                text+="I";
                break;
            case 9:
                text+="O";
                break;
            }
        }else
        text+=alphabet[gen()%(k*delta)];
        if(text.back()==text[i-1]&&text.back()==' ')
        {
            while(text.back()==' ')
                text.back()=alphabet[gen()%(k*delta)];
        }
    }
    text+=" ";
    while(text.back()==' '||text.back()==QChar('¨')||text.back()==QChar('^'))
    {
        text.back()=alphabet[gen()%(k*delta)];
    }

}

void MainWindow::setTaskText()
{
    qDebug()<<ui->label->text();
    if(text.size()==0)
    {
        Finish();
        return;
    }
    ui->label->setText(text[0]);
    QString s="";
    for(int i=1;i<text.size();i++)s+=text[i];
    ui->textBrowser->setText(s);
    update();
}

void MainWindow::change(QChar &q)
{
    for(int i=0;i<46;i++)
    {
        if(q==alphabet[i])
            q=alphabet[i+delta],qDebug()<<i+delta;
    }
}

void MainWindow::Finish()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(update_gui()));
    timer->stop();
    ui->StartButton->setText("Start");

    ui->label->clear();
    ui->textBrowser->clear();

    clearKeyboard();
    QMessageBox::information(this,"Keyboard Trainer","You finished the test and did great work!");

    GiveResult();

    text="";
}

void MainWindow::GiveResult()
{
    if(ui->accuracy->text().toDouble()>80&&ui->chars_per_second->text().toDouble()>=1)
    {
        ui->Result->setPixmap(QPixmap(":main/resource/chief happy.png"));
    }
    else
        if(ui->accuracy->text().toDouble()==2||ui->chars_per_second->text().toDouble()==2)
            ui->Result->setPixmap(QPixmap(":main/resource/2.png"));
    else
        ui->Result->setPixmap(QPixmap(":main/resource/clown.jpg"));
}

void MainWindow::check(int key)
{
    QString q=getButton(key_to_ind(key))->text();
    chars++;
    QChar c1=c;
    c='|';
    if(q==' '||q=="")
    {
        ui->label->setStyleSheet(Wrong);
        er++;
        return;
    }else
        if(q!="Space")
        {
            c=q[0];

            if((Shift_on&&!Caps_on)||(!Shift_on&&Caps_on))
            {
                qDebug()<<Shift_on<<" "<<Caps_on;
            }
            else if(c!='^')
                change(c);
        }
        else c=' ';
    qDebug()<<c<<" "<<ui->label->text();

    if(c==ui->label->text())
    {
        ui->label->setStyleSheet(Correct);
        text.erase(text.begin(),text.begin()+1);
        setTaskText();
        ui->label->setStyleSheet(Just);
        cor++;
    }
    else
    {
        ui->label->setStyleSheet(Wrong);
        er++;
        return;
    }

}


void MainWindow::keyPressEvent(QKeyEvent *ke)
{
    qDebug()<<"+"<<ke->key();
    getButton(key_to_ind(ke->key()))->setStyleSheet(pressed_button);
        if(ke->key()==Qt::Key_Shift)
        {
            Shift_on=true;

            //if(ui->comboBox->currentIndex()!=3&&ui->comboBox->currentIndex()!=1)
                setKeyboard(0);
        }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ke)
{
    qDebug()<<"-"<<ke->key();
    getButton(key_to_ind(ke->key()))->setStyleSheet(default_button);

    if(ke->key()==Qt::Key_CapsLock)
    {
        if(Caps_on!=true)
        {
            getButton(key_to_ind(ke->key()))->setStyleSheet(CapsOn);
            Caps_on=true;

            ////if(ui->comboBox->currentIndex()!=3&&ui->comboBox->currentIndex()!=1)
                setKeyboard(0);
        }
        else
        {
            Caps_on=false;

            ////if(ui->comboBox->currentIndex()!=3&&ui->comboBox->currentIndex()!=1)
                setKeyboard(delta);
        }
    }
    else
    if(ke->key()==Qt::Key_Shift)
    {
        Shift_on=false;

        ////if(ui->comboBox->currentIndex()!=3&&ui->comboBox->currentIndex()!=1)
            setKeyboard(delta);
    }
    else if(ui->StartButton->text()=="Stop test")
    {
        check(ke->key());
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(ui->StartButton->text()=="Stop test")
        Finish();

    if(index==0)
        setBelarussian();
    if(index==1)
        setHebrew();
    if(index==2)
        setDeutsch();
    if(index==3)
        setArabic();
    if(index==4)
        setChinese();
    if(index==5)
        setFrench();

}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1==2)
        for(int i=1;i<=49;i++)
        {
            if(getButton(i)->text()==" ")
                getButton(i)->hide();
        }
    else
        for(int i=1;i<=49;i++)
        {
                getButton(i)->show();
        }
}

void MainWindow::on_StartButton_clicked()
{
    if(ui->StartButton->text()=="Start")
    {

    ui->StartButton->setText("Stop test");

    er=cor=0;

    ui->label->setStyleSheet(Just);
    ui->progressBar->setValue(0);
    ui->Result->clear();

    if(text=="")
    genText();
    setTaskText();

    ms=0;
    connect(timer, SIGNAL(timeout()), this, SLOT(update_gui()));
    timer->start(1);


    }
    else
    {
        Finish();
    }

}

void MainWindow::update_gui()
{
    ms++;
    ui->ms->display(ms%1000);
    int s=ms/1000;
    int m=s/60;
    if(s%60==0)
        chars=0;

    int ch=m/60;
    ui->h->display(ch);
    ui->m->display(m%60);
    ui->s->display(s%60);

    if(s!=0)
    {
        long double chps=(long double)chars/((long double)s);
        ui->chars_per_second->setText(QString::fromStdString(std::to_string(chps)));
    }

    ui->progressBar->setValue((size-text.size())/6);

    if(cor+er!=0)
    {
        long double ac=cor;
        ac/=(cor+er);
        ui->accuracy->setText(QString::fromStdString(std::to_string(ac)));
    }

}

void MainWindow::on_OpenFileButton_clicked()
{
    if(ui->StartButton->text()=="Stop test")
    {
        QMessageBox::warning(this,"Bro...","Firstly finish task");
        return;
    }

    QString filename=QFileDialog::getOpenFileName(this,tr("Open Task"), "", tr("Task Files (*.by *.ch *.fr *.he *.de *.ar)"));

    if(filename=="")
    {
        QMessageBox::information(this,"AHAHAHAHA","You don't open file");
        return;
    }

    //check
    correct_file(filename);
}

