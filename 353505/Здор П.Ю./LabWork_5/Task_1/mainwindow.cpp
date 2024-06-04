#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    installEventFilter(this);
    ui->pushButton->setEnabled(false);
    b[0]=ui->pushButton;
    ui->pushButton_2->setEnabled(false);
    b[1]=ui->pushButton_2;
    ui->pushButton_3->setEnabled(false);
    b[2]=ui->pushButton_3;
    ui->pushButton_4->setEnabled(false);
    b[3]=ui->pushButton_4;
    ui->pushButton_5->setEnabled(false);
    b[4]=ui->pushButton_5;
    ui->pushButton_6->setEnabled(false);
    b[5]=ui->pushButton_6;
    ui->pushButton_7->setEnabled(false);
    b[6]=ui->pushButton_7;
    ui->pushButton_8->setEnabled(false);
    b[7]=ui->pushButton_8;
    ui->pushButton_9->setEnabled(false);
    b[8]=ui->pushButton_9;
    ui->pushButton_10->setEnabled(false);
    b[9]=ui->pushButton_10;
    ui->pushButton_11->setEnabled(false);
    b[10]=ui->pushButton_11;
    ui->pushButton_12->setEnabled(false);
    b[11]=ui->pushButton_12;
    ui->pushButton_13->setEnabled(false);
    b[12]=ui->pushButton_13;
    ui->pushButton_14->setEnabled(false);
    b[13]=ui->pushButton_14;
    ui->pushButton_15->setEnabled(false);
    b[14]=ui->pushButton_15;
    ui->pushButton_16->setEnabled(false);
    b[15]=ui->pushButton_16;
    ui->pushButton_17->setEnabled(false);
    b[16]=ui->pushButton_17;
    ui->pushButton_18->setEnabled(false);
    b[17]=ui->pushButton_18;
    ui->pushButton_19->setEnabled(false);
    b[18]=ui->pushButton_19;
    ui->pushButton_20->setEnabled(false);
    b[19]=ui->pushButton_20;
    ui->pushButton_21->setEnabled(false);
    b[20]=ui->pushButton_21;
    ui->pushButton_22->setEnabled(false);
    b[21]=ui->pushButton_22;
    ui->pushButton_23->setEnabled(false);
    b[22]=ui->pushButton_23;
    ui->pushButton_24->setEnabled(false);
    b[23]=ui->pushButton_24;
    ui->pushButton_25->setEnabled(false);
    b[24]=ui->pushButton_25;
    ui->pushButton_26->setEnabled(false);
    b[25]=ui->pushButton_26;
    ui->pushButton_27->setEnabled(false);
    b[26]=ui->pushButton_27;
    ui->pushButton_28->setEnabled(false);
    b[27]=ui->pushButton_28;
    ui->pushButton_29->setEnabled(false);
    b[28]=ui->pushButton_29;
    ui->pushButton_30->setEnabled(false);
    b[29]=ui->pushButton_30;
    ui->pushButton_31->setEnabled(false);
    b[30]=ui->pushButton_31;
    ui->pushButton_32->setEnabled(false);
    b[31]=ui->pushButton_32;
    ui->pushButton_33->setEnabled(false);
    b[32]=ui->pushButton_33;
    ui->pushButton_34->setEnabled(false);
    b[33]=ui->pushButton_34;
    ui->pushButton_35->setEnabled(false);
    b[34]=ui->pushButton_35;
    ui->pushButton_36->setEnabled(false);
    b[35]=ui->pushButton_36;
    ui->pushButton_37->setEnabled(false);
    b[36]=ui->pushButton_37;
    ui->pushButton_38->setEnabled(false);
    b[37]=ui->pushButton_38;
    ui->pushButton_39->setEnabled(false);
    b[38]=ui->pushButton_39;
    ui->pushButton_40->setEnabled(false);
    b[39]=ui->pushButton_40;
    ui->pushButton_41->setEnabled(false);
    b[40]=ui->pushButton_41;
    ui->pushButton_42->setEnabled(false);
    b[41]=ui->pushButton_42;
    ui->pushButton_43->setEnabled(false);
    b[42]=ui->pushButton_43;
    ui->pushButton_44->setEnabled(false);
    b[43]=ui->pushButton_44;
    ui->pushButton_45->setEnabled(false);
    b[44]=ui->pushButton_45;
    ui->pushButton_46->setEnabled(false);
    b[45]=ui->pushButton_46;
    ui->pushButton_47->setEnabled(false);
    b[46]=ui->pushButton_47;
    ui->pushButton_48->setEnabled(false);
    b[47]=ui->pushButton_48;
    ui->pushButton_49->setEnabled(false);
    b[48]=ui->pushButton_49;
    ui->pushButton_50->setEnabled(false);
    b[49]=ui->pushButton_50;
    ui->pushButton_51->setEnabled(false);
    b[50]=ui->pushButton_51;
    ui->pushButton_52->setEnabled(false);
    b[51]=ui->pushButton_52;
    ui->pushButton_53->setEnabled(false);
    b[52]=ui->pushButton_53;
    ui->pushButton_54->setEnabled(false);
    b[53]=ui->pushButton_54;
    ui->pushButton_55->setEnabled(false);
    b[54]=ui->pushButton_55;
    ui->pushButton_56->setEnabled(false);
    b[55]=ui->pushButton_56;
    ui->pushButton_57->setEnabled(false);
    b[56]=ui->pushButton_57;
    ui->pushButton_58->setEnabled(false);
    b[57]=ui->pushButton_58;
    ui->pushButton_59->setEnabled(false);
    b[58]=ui->pushButton_59;
    ui->pushButton_60->setEnabled(false);
    b[59]=ui->pushButton_60;
    ui->pushButton_61->setEnabled(false);
    b[60]=ui->pushButton_61;
    ui->pushButton_62->setEnabled(false);
    b[61]=ui->pushButton_62;
    ui->pushButton_63->setEnabled(false);
    b[62]=ui->pushButton_63;
    ui->pushButton_64->setEnabled(false);
    b[63]=ui->pushButton_64;
    bb=b;
    for(int i=0;i<64;++i)
    {
        b[i]->setCheckable(false);
        b[i]->setEnabled(false);
    }
    int sch=0;
    for(int i=0x0410;i<=0x042F;++i){
        if(sch==8){
            bel+=QString::fromUtf8("\u0406");
            sch++;
        }
        else if(sch==19)
        {
            bel+=QChar(i);
            bel+=QString::fromUtf8("\u040E");
            sch++;
        }
        else if(sch==5)
        {
            bel+=QChar(i);
            bel+=QString::fromUtf8("\u0401");
            sch++;

        }
        else if(sch==25) {

            sch+=2;
            ++i;
        }
        else {
            bel+=QChar(i);
            sch++;
        }
        //QColor color(151,118,242);
       // ui->lineEdit_2->setStyleSheet(QString("background-color:%1;").arg(color.name()));

    }
    sch=31;
    for(int i=0x430;i<=0x44F;++i){
        if(sch==8+31){
            bel+=QString::fromUtf8("\u0456");
            sch++;
        }
        else if(sch==19+31)
        {
            bel+=QChar(i);
            bel+=QString::fromUtf8("\u045E");
            sch++;
        }
        else if(sch==5+31)
        {
            bel+=QChar(i);
            bel+=QString::fromUtf8("\u0451");
            sch++;

        }
        else if(sch==25+31) {

            sch+=2;
            ++i;
        }
        else {
            bel+=QChar(i);
            sch++;
        }
    }

    qDebug() << bel;
    chi+=QString::fromUtf8("｀～1！2＠3＃4￥5％6……7＆8＊9（0）－——＝＋Q手W田E水R口T廿Y卜U山I戈O人P心『「」』、｜A日S尸D木F火G土H竹J十K大L中;:'Z　X║C金V女B月N弓M一《，。》？／");
    deu+=QString::fromUtf8("°§ß´QqWwEeRrTtZzUuIiOoPpÜü*+#'AaSsDdFfGgHhJjKkLlÖöÄäYyXxCcVvBbNnMm;,:._-");
    ar+=QString::fromUtf8("ذ");
    ar+=QString::fromUtf8("ّ");
    ar+=QString::fromUtf8("1!2@3#4$5%6^7&8*9)0(_-+=َََ");
    ar+=QString::fromUtf8("َض");
    ar+=QString::fromUtf8("َ");
     ar+=QString::fromUtf8("َص");
     ar+=QString::fromUtf8("ًَ");
     ar+=QString::fromUtf8("َث");
     ar+=QString::fromUtf8("ُ");
    ar+=QString::fromUtf8("ق");
     ar+=QString::fromUtf8("ٌ");
    ar+=QString::fromUtf8("ف");
     ar+=QString::fromUtf8("لإ");
    ar+=QString::fromUtf8("غ");
      ar+=QString::fromUtf8("إ");
    ar+=QString::fromUtf8("ع");
     ar+=QString::fromUtf8("`");
    ar+=QString::fromUtf8("ه");
     ar+=QString::fromUtf8("÷");
    ar+=QString::fromUtf8("خ");
     ar+=QString::fromUtf8("×");
    ar+=QString::fromUtf8("ح");
     ar+=QString::fromUtf8("؛");
    ar+=QString::fromUtf8("<ج");
    ar+=QString::fromUtf8(">د|");
    ar+=QString::fromUtf8("\u005c");
    ar+=QString::fromUtf8("ش");
    ar+=QString::fromUtf8("ِ");
    ar+=QString::fromUtf8("س");
    ar+=QString::fromUtf8("ٍ");
    ar+=QString::fromUtf8("ي");
    ar+=QString::fromUtf8("]");
    ar+=QString::fromUtf8("[");
    ar+=QString::fromUtf8("ب");
    ar+=QString::fromUtf8("ل");
    ar+=QString::fromUtf8("لأ");
    ar+=QString::fromUtf8("أ");
    ar+=QString::fromUtf8("ا");
    ar+=QString::fromUtf8("ت");
    ar+=QString::fromUtf8("ـ");
    ar+=QString::fromUtf8("ن");
    ar+=QString::fromUtf8("،");
    ar+=QString::fromUtf8("م");
    ar+=QString::fromUtf8("/");
    ar+=QString::fromUtf8("ك");
    ar+=QString::fromUtf8(":");
    ar+=QString::fromUtf8("ط");
    ar+=QString::fromUtf8("\u0022");
    ar+=QString::fromUtf8("ئ");
    ar+=QString::fromUtf8("~");
    ar+=QString::fromUtf8("ء");
    ar+=QString::fromUtf8("ْ");
    ar+=QString::fromUtf8("ؤ");
    ar+=QString::fromUtf8("}");
    ar+=QString::fromUtf8("ر");
    ar+=QString::fromUtf8("{");
    ar+=QString::fromUtf8("لا");
    ar+=QString::fromUtf8("لآ");
    ar+=QString::fromUtf8("آ");
    ar+=QString::fromUtf8("ى");
    ar+=QString::fromUtf8("'");
    ar+=QString::fromUtf8("ة");
    ar+=QString::fromUtf8("و");
    ar+=QString::fromUtf8(",");
    ar+=QString::fromUtf8(".");
    ar+=QString::fromUtf8("ز");
    ar+=QString::fromUtf8("ظ");
    ar+=QString::fromUtf8("؟");
    fr+=QString::fromUtf8("~²1&2é34'(5-6è7_8ç9à0°)=+AaZzEeRrTtYyUuIiOoPp¨^£$*µQqSsDdFfGgHhJjKkLlMm%ùWwXxC手田水cVvBbNn?,.;/:§!");
    ivr+=QString::fromUtf8("~;1!2@3#4$5%6^7&8*9)0(-_+=Q/W'EקRרTאYטUוIןOםPפ}]{[|");
    ivr+=QString::fromUtf8("\u005c");
    ivr+=QString::fromUtf8("AשSדDגFכGעHיJחKלLך:ף,");
    ivr+=QString::fromUtf8("\u0022");
    ivr+=QString::fromUtf8("ZזXסCבVהBנNמMצ>ת<ץ?.");
    QFont font;
    font.setPointSize(20);
    ui->lineEdit->setFont(font);
   ui->lineEdit->installEventFilter(this);
    ui->textEdit->setReadOnly(true);



   ui->lineEdit->setAlignment(Qt::AlignRight);
    ui->lineEdit->setReadOnly(true);
   on_comboBox_currentIndexChanged(0);
   ui->label_3->setText(QString::number(0));


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Shift)
    {
        ui->pushButton_42->setEnabled(true);
        ui->pushButton_42->setCheckable(true);
        ui->pushButton_42->setChecked(true);
    }



}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->lineEdit) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        // Проверяем, является ли нажатая клавиша Backspace или Delete
        if ((keyEvent->key() == Qt::Key_Backspace || keyEvent->key() == Qt::Key_Delete)|| (event->type() == QEvent::MouseButtonPress)) {
            // Если поле ввода пустое и нажата клавиша Backspace или Delete, то блокируем действие
            event->ignore();
            return true; // Возвращаем true, чтобы показать, что событие обработано
        }
    }
    if (obj == ui->textEdit) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        // Проверяем, является ли нажатая клавиша Backspace или Delete
        if ((keyEvent->key() == Qt::Key_Backspace || keyEvent->key() == Qt::Key_Delete || keyEvent->key()==Qt::MouseEventFlag())) {
            // Если поле ввода пустое и нажата клавиша Backspace или Delete, то блокируем действие
            event->ignore();
            return true; // Возвращаем true, чтобы показать, что событие обработано
        }
    }


    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::check(QString arg1)
{
    if(((arg1[arg1.length()-1]==chi[0]||arg1[arg1.length()-1]==chi[1])&&flag1) || ((arg1[arg1.length()-1]==ar[0]||arg1[arg1.length()-1]==ar[1])&&flag5)|| ((arg1[arg1.length()-1]==ivr[0]||arg1[arg1.length()-1]==ivr[1])&&flag6) )
    {
        ui->pushButton->setEnabled(true);
        ui->pushButton->setCheckable(true);
        ui->pushButton->setChecked(true);

    }
    if(((arg1[arg1.length()-1]==chi[2]||arg1[arg1.length()-1]==chi[3])&&flag1) || ((arg1[arg1.length()-1]==ar[2]||arg1[arg1.length()-1]==ar[3])&&flag5)|| ((arg1[arg1.length()-1]==ivr[2]||arg1[arg1.length()-1]==ivr[3])&&flag6) )
    {
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_2->setCheckable(true);
        ui->pushButton_2->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[4]||arg1[arg1.length()-1]==chi[5])&&flag1) || ((arg1[arg1.length()-1]==ar[4]||arg1[arg1.length()-1]==ar[5])&&flag5)|| ((arg1[arg1.length()-1]==ivr[4]||arg1[arg1.length()-1]==ivr[5])&&flag6) )
    {
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_3->setCheckable(true);
        ui->pushButton_3->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[6]||arg1[arg1.length()-1]==chi[7])&&flag1) || ((arg1[arg1.length()-1]==ar[6]||arg1[arg1.length()-1]==ar[7])&&flag5)|| ((arg1[arg1.length()-1]==ivr[6]||arg1[arg1.length()-1]==ivr[7])&&flag6) )
    {
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_4->setCheckable(true);
        ui->pushButton_4->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[8]||arg1[arg1.length()-1]==chi[9])&&flag1) || ((arg1[arg1.length()-1]==ar[8]||arg1[arg1.length()-1]==ar[9])&&flag5)|| ((arg1[arg1.length()-1]==ivr[8]||arg1[arg1.length()-1]==ivr[9])&&flag6) )
    {
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_5->setCheckable(true);
        ui->pushButton_5->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[10]||arg1[arg1.length()-1]==chi[11])&&flag1) || ((arg1[arg1.length()-1]==ar[10]||arg1[arg1.length()-1]==ar[11])&&flag5)|| ((arg1[arg1.length()-1]==ivr[10]||arg1[arg1.length()-1]==ivr[11])&&flag6) )
    {
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_6->setCheckable(true);
        ui->pushButton_6->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[12]||arg1[arg1.length()-1]==(chi[13]))&&flag1) || ((arg1[arg1.length()-1]==ar[12]||arg1[arg1.length()-1]==ar[13])&&flag5)|| ((arg1[arg1.length()-1]==ivr[12]||arg1[arg1.length()-1]==ivr[13])&&flag6) )
    {
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_7->setCheckable(true);
        ui->pushButton_7->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[15]||arg1[arg1.length()-1]==chi[16])&&flag1) || ((arg1[arg1.length()-1]==ar[14]||arg1[arg1.length()-1]==ar[15])&&flag5)|| ((arg1[arg1.length()-1]==ivr[14]||arg1[arg1.length()-1]==ivr[15])&&flag6) )
    {
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_8->setCheckable(true);
        ui->pushButton_8->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[17]||arg1[arg1.length()-1]==chi[18])&&flag1) || ((arg1[arg1.length()-1]==ar[16]||arg1[arg1.length()-1]==ar[17])&&flag5)|| ((arg1[arg1.length()-1]==ivr[16]||arg1[arg1.length()-1]==ivr[17])&&flag6) )
    {
        ui->pushButton_9->setEnabled(true);
        ui->pushButton_9->setCheckable(true);
        ui->pushButton_9->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[19]||arg1[arg1.length()-1]==chi[20])&&flag1) || ((arg1[arg1.length()-1]==ar[18]||arg1[arg1.length()-1]==ar[19])&&flag5)|| ((arg1[arg1.length()-1]==ivr[18]||arg1[arg1.length()-1]==ivr[19])&&flag6) )
    {
        ui->pushButton_10->setEnabled(true);
        ui->pushButton_10->setCheckable(true);
        ui->pushButton_10->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[21]||arg1[arg1.length()-1]==chi[22])&&flag1) || ((arg1[arg1.length()-1]==ar[20]||arg1[arg1.length()-1]==ar[21])&&flag5)|| ((arg1[arg1.length()-1]==ivr[20]||arg1[arg1.length()-1]==ivr[21])&&flag6) )
    {
        ui->pushButton_11->setEnabled(true);
        ui->pushButton_11->setCheckable(true);
        ui->pushButton_11->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[23]||arg1[arg1.length()-1]==chi[24])&&flag1) || ((arg1[arg1.length()-1]==ar[22]||arg1[arg1.length()-1]==ar[23])&&flag5)|| ((arg1[arg1.length()-1]==ivr[22]||arg1[arg1.length()-1]==ivr[23])&&flag6) )
    {
        ui->pushButton_12->setEnabled(true);
        ui->pushButton_12->setCheckable(true);
        ui->pushButton_12->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[27]||arg1[arg1.length()-1]==chi[26])&&flag1) || ((arg1[arg1.length()-1]==ar[24]||arg1[arg1.length()-1]==ar[25])&&flag5)|| ((arg1[arg1.length()-1]==ivr[24]||arg1[arg1.length()-1]==ivr[25])&&flag6) )
    {
        ui->pushButton_13->setEnabled(true);
        ui->pushButton_13->setCheckable(true);
        ui->pushButton_13->setChecked(true);
    }
    /*if(arg1[arg1.length()-1]==QChar::fromLatin1(Qt::Key_Backspace))
    {
        ui->pushButton_14->setCheckable(true);
        ui->pushButton_14->setChecked(true);
    }
    if(arg1[arg1.length()-1]==QChar::fromLatin1(Qt::Key_Tab))
    {
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_15->setCheckable(true);
        ui->pushButton_15->setChecked(true);
    }*/
    if(((arg1[arg1.length()-1]==chi[28]||arg1[arg1.length()-1]==chi[29])&&flag1) || ((arg1[arg1.length()-1]==ar[30]||arg1[arg1.length()-1]==ar[31])&&flag5)|| ((arg1[arg1.length()-1]==ivr[26]||arg1[arg1.length()-1]==ivr[27])&&flag6) )
    {
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_16->setCheckable(true);
        ui->pushButton_16->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[31]||arg1[arg1.length()-1]==chi[30])&&flag1) || ((arg1[arg1.length()-1]==ar[33]||arg1[arg1.length()-1]==ar[32])&&flag5)|| ((arg1[arg1.length()-1]==ivr[28]||arg1[arg1.length()-1]==ivr[29])&&flag6) )
    {
        ui->pushButton_17->setEnabled(true);
        ui->pushButton_17->setCheckable(true);
        ui->pushButton_17->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[32]||arg1[arg1.length()-1]==chi[33])&&flag1) || ((arg1[arg1.length()-1]==ar[37]||arg1[arg1.length()-1]==ar[38])&&flag5) || ((arg1[arg1.length()-1]==ivr[30]||arg1[arg1.length()-1]==ivr[31])&&flag6))
    {
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_18->setCheckable(true);
        ui->pushButton_18->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[34]||arg1[arg1.length()-1]==chi[35])&&flag1) || ((arg1[arg1.length()-1]==ar[39]||arg1[arg1.length()-1]==ar[40])&&flag5)|| ((arg1[arg1.length()-1]==ivr[32]||arg1[arg1.length()-1]==ivr[33])&&flag6) )
    {
        ui->pushButton_19->setEnabled(true);
        ui->pushButton_19->setCheckable(true);
        ui->pushButton_19->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[36]||arg1[arg1.length()-1]==chi[37])&&flag1) || ((arg1[arg1.length()-1]==ar[41]||arg1[arg1.length()-1]==ar[43])&&flag5)|| ((arg1[arg1.length()-1]==ivr[34]||arg1[arg1.length()-1]==ivr[35])&&flag6) )
    {
        ui->pushButton_20->setEnabled(true);
        ui->pushButton_20->setCheckable(true);
        ui->pushButton_20->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[38]||arg1[arg1.length()-1]==chi[39])&&flag1) || ((arg1[arg1.length()-1]==ar[44]||arg1[arg1.length()-1]==ar[45])&&flag5)|| ((arg1[arg1.length()-1]==ivr[36]||arg1[arg1.length()-1]==ivr[37])&&flag6))
    {
        ui->pushButton_21->setEnabled(true);
        ui->pushButton_21->setCheckable(true);
        ui->pushButton_21->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[40]||arg1[arg1.length()-1]==chi[41])&&flag1) || ((arg1[arg1.length()-1]==ar[46]||arg1[arg1.length()-1]==ar[47])&&flag5)|| ((arg1[arg1.length()-1]==ivr[39]||arg1[arg1.length()-1]==ivr[38])&&flag6))
    {
        ui->pushButton_22->setEnabled(true);
        ui->pushButton_22->setCheckable(true);
        ui->pushButton_22->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[42]||arg1[arg1.length()-1]==chi[43])&&flag1) || ((arg1[arg1.length()-1]==ar[48]||arg1[arg1.length()-1]==ar[49])&&flag5)|| ((arg1[arg1.length()-1]==ivr[40]||arg1[arg1.length()-1]==ivr[41])&&flag6))
    {
        ui->pushButton_23->setEnabled(true);
        ui->pushButton_23->setCheckable(true);
        ui->pushButton_23->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[44]||arg1[arg1.length()-1]==chi[45])&&flag1) || ((arg1[arg1.length()-1]==ar[50]||arg1[arg1.length()-1]==ar[51])&&flag5)|| ((arg1[arg1.length()-1]==ivr[42]||arg1[arg1.length()-1]==ivr[43])&&flag6))
    {
        ui->pushButton_24->setEnabled(true);
        ui->pushButton_24->setCheckable(true);
        ui->pushButton_24->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[46]||arg1[arg1.length()-1]==chi[47])&&flag1) || ((arg1[arg1.length()-1]==ar[52]||arg1[arg1.length()-1]==ar[53])&&flag5)|| ((arg1[arg1.length()-1]==ivr[44]||arg1[arg1.length()-1]==ivr[45])&&flag6))
    {
        ui->pushButton_25->setEnabled(true);
        ui->pushButton_25->setCheckable(true);
        ui->pushButton_25->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[48]||arg1[arg1.length()-1]==chi[49])&&flag1) || ((arg1[arg1.length()-1]==ar[54]||arg1[arg1.length()-1]==ar[55])&&flag5)|| ((arg1[arg1.length()-1]==ivr[46]||arg1[arg1.length()-1]==ivr[47])&&flag6))
    {
        ui->pushButton_26->setEnabled(true);
        ui->pushButton_26->setCheckable(true);
        ui->pushButton_26->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[50]||arg1[arg1.length()-1]==chi[51])&&flag1) || ((arg1[arg1.length()-1]==ar[56]||arg1[arg1.length()-1]==ar[57])&&flag5)|| ((arg1[arg1.length()-1]==ivr[48]||arg1[arg1.length()-1]==ivr[49])&&flag6))
    {
        ui->pushButton_27->setEnabled(true);
        ui->pushButton_27->setCheckable(true);
        ui->pushButton_27->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[52]||arg1[arg1.length()-1]==chi[53])&&flag1) || ((arg1[arg1.length()-1]==ar[58]||arg1[arg1.length()-1]==ar[59])&&flag5)|| ((arg1[arg1.length()-1]==ivr[50]||arg1[arg1.length()-1]==ivr[51])&&flag6))
    {
        ui->pushButton_28->setEnabled(true);
        ui->pushButton_28->setCheckable(true);
        ui->pushButton_28->setChecked(true);
    }
    /*if(arg1[arg1.length()-1]==QChar::fromLatin1(Qt::Key_CapsLock))
    {
        ui->pushButton_29->setEnabled(true);
        ui->pushButton_29->setCheckable(true);
        ui->pushButton_29->setChecked(true);
    }*/
    if(((arg1[arg1.length()-1]==chi[54]||arg1[arg1.length()-1]==chi[55])&&flag1) || ((arg1[arg1.length()-1]==ar[60]||arg1[arg1.length()-1]==ar[61])&&flag5)|| ((arg1[arg1.length()-1]==ivr[52]||arg1[arg1.length()-1]==ivr[53])&&flag6))
    {
        ui->pushButton_30->setEnabled(true);
        ui->pushButton_30->setCheckable(true);
        ui->pushButton_30->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[56]||arg1[arg1.length()-1]==chi[57])&&flag1) || ((arg1[arg1.length()-1]==ar[63]||arg1[arg1.length()-1]==ar[62])&&flag5)|| ((arg1[arg1.length()-1]==ivr[54]||arg1[arg1.length()-1]==ivr[55])&&flag6))
    {
        ui->pushButton_31->setEnabled(true);
        ui->pushButton_31->setCheckable(true);
        ui->pushButton_31->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[58]||arg1[arg1.length()-1]==chi[59])&&flag1) || ((arg1[arg1.length()-1]==ar[64]||arg1[arg1.length()-1]==ar[65])&&flag5)|| ((arg1[arg1.length()-1]==ivr[56]||arg1[arg1.length()-1]==ivr[57])&&flag6))
    {
        ui->pushButton_32->setEnabled(true);
        ui->pushButton_32->setCheckable(true);
        ui->pushButton_32->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[60]||arg1[arg1.length()-1]==chi[61])&&flag1) || ((arg1[arg1.length()-1]==ar[66]||arg1[arg1.length()-1]==ar[67])&&flag5)|| ((arg1[arg1.length()-1]==ivr[58]||arg1[arg1.length()-1]==ivr[59])&&flag6))
    {
        ui->pushButton_33->setEnabled(true);
        ui->pushButton_33->setCheckable(true);
        ui->pushButton_33->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[62]||arg1[arg1.length()-1]==chi[63])&&flag1) || ((arg1[arg1.length()-1]==ar[70]||arg1[arg1.length()-1]==ar[68])&&flag5)|| ((arg1[arg1.length()-1]==ivr[60]||arg1[arg1.length()-1]==ivr[61])&&flag6))
    {
        ui->pushButton_34->setEnabled(true);
        ui->pushButton_34->setCheckable(true);
        ui->pushButton_34->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[64]||arg1[arg1.length()-1]==chi[65])&&flag1) || ((arg1[arg1.length()-1]==ar[72]||arg1[arg1.length()-1]==ar[71])&&flag5)|| ((arg1[arg1.length()-1]==ivr[62]||arg1[arg1.length()-1]==ivr[63])&&flag6))
    {
        ui->pushButton_35->setEnabled(true);
        ui->pushButton_35->setCheckable(true);
        ui->pushButton_35->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[66]||arg1[arg1.length()-1]==chi[67])&&flag1) || ((arg1[arg1.length()-1]==ar[73]||arg1[arg1.length()-1]==ar[74])&&flag5)|| ((arg1[arg1.length()-1]==ivr[64]||arg1[arg1.length()-1]==ivr[65])&&flag6))
    {
        ui->pushButton_36->setEnabled(true);
        ui->pushButton_36->setCheckable(true);
        ui->pushButton_36->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[68]||arg1[arg1.length()-1]==chi[69])&&flag1) || ((arg1[arg1.length()-1]==ar[75]||arg1[arg1.length()-1]==ar[76])&&flag5)|| ((arg1[arg1.length()-1]==ivr[66]||arg1[arg1.length()-1]==ivr[67])&&flag6))
    {
        ui->pushButton_37->setEnabled(true);
        ui->pushButton_37->setCheckable(true);
        ui->pushButton_37->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[70]||arg1[arg1.length()-1]==chi[71])&&flag1) || ((arg1[arg1.length()-1]==ar[77]||arg1[arg1.length()-1]==ar[78])&&flag5)|| ((arg1[arg1.length()-1]==ivr[68]||arg1[arg1.length()-1]==ivr[69])&&flag6))
    {
        ui->pushButton_38->setEnabled(true);
        ui->pushButton_38->setCheckable(true);
        ui->pushButton_38->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[72]||arg1[arg1.length()-1]==chi[73])&&flag1) || ((arg1[arg1.length()-1]==ar[79]||arg1[arg1.length()-1]==ar[80])&&flag5)|| ((arg1[arg1.length()-1]==ivr[70]||arg1[arg1.length()-1]==ivr[71])&&flag6))
    {
        ui->pushButton_39->setEnabled(true);
        ui->pushButton_39->setCheckable(true);
        ui->pushButton_39->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[74]||arg1[arg1.length()-1]=='\u0022')&&flag1) || ((arg1[arg1.length()-1]==ar[81]||arg1[arg1.length()-1]==ar[82])&&flag5)|| ((arg1[arg1.length()-1]==ivr[72]||arg1[arg1.length()-1]==ivr[73])&&flag6))
    {
        ui->pushButton_40->setEnabled(true);
        ui->pushButton_40->setCheckable(true);
        ui->pushButton_40->setChecked(true);
    }
    /*if(arg1[arg1.length()-1]==QChar::fromLatin1(Qt::Key_Enter))لأ
    {
        ui->pushButton_41->setEnabled(true);
        ui->pushButton_41->setCheckable(true);
        ui->pushButton_41->setChecked(true);
    }
    if(arg1[arg1.length()-1]==QChar::fromLatin1(Qt::Key_Shift))
    {
        ui->pushButton_42->setEnabled(true);
        ui->pushButton_42->setCheckable(true);
        ui->pushButton_42->setChecked(true);
    }*/
    if(((arg1[arg1.length()-1]==chi[76]||arg1[arg1.length()-1]==chi[75])&&flag1) || ((arg1[arg1.length()-1]==ar[83]||arg1[arg1.length()-1]==ar[84])&&flag5)|| ((arg1[arg1.length()-1]==ivr[74]||arg1[arg1.length()-1]==ivr[75])&&flag6))
    {
        ui->pushButton_43->setEnabled(true);
        ui->pushButton_43->setCheckable(true);
        ui->pushButton_43->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[78]||arg1[arg1.length()-1]==chi[77])&&flag1) || ((arg1[arg1.length()-1]==ar[85]||arg1[arg1.length()-1]==ar[86])&&flag5)|| ((arg1[arg1.length()-1]==ivr[76]||arg1[arg1.length()-1]==ivr[77])&&flag6))
    {
        ui->pushButton_44->setEnabled(true);
        ui->pushButton_44->setCheckable(true);
        ui->pushButton_44->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[80]||arg1[arg1.length()-1]==chi[79])&&flag1) || ((arg1[arg1.length()-1]==ar[87]||arg1[arg1.length()-1]==ar[88])&&flag5)|| ((arg1[arg1.length()-1]==ivr[78]||arg1[arg1.length()-1]==ivr[79])&&flag6))
    {
        ui->pushButton_45->setEnabled(true);
        ui->pushButton_45->setCheckable(true);
        ui->pushButton_45->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[82]||arg1[arg1.length()-1]==chi[81])&&flag1) || ((arg1[arg1.length()-1]==ar[90]||arg1[arg1.length()-1]==ar[89])&&flag5)|| ((arg1[arg1.length()-1]==ivr[80]||arg1[arg1.length()-1]==ivr[81])&&flag6))
    {
        ui->pushButton_46->setEnabled(true);
        ui->pushButton_46->setCheckable(true);
        ui->pushButton_46->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[84]||arg1[arg1.length()-1]==chi[83])&&flag1) || ((arg1[arg1.length()-1]==ar[94]||arg1[arg1.length()-1]==ar[93])&&flag5)|| ((arg1[arg1.length()-1]==ivr[82]||arg1[arg1.length()-1]==ivr[83])&&flag6))
    {
        ui->pushButton_47->setEnabled(true);
        ui->pushButton_47->setCheckable(true);
        ui->pushButton_47->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[86]||arg1[arg1.length()-1]==chi[85])&&flag1) || ((arg1[arg1.length()-1]==ar[96]||arg1[arg1.length()-1]==ar[95])&&flag5)|| ((arg1[arg1.length()-1]==ivr[84]||arg1[arg1.length()-1]==ivr[85])&&flag6))
    {
        ui->pushButton_48->setEnabled(true);
        ui->pushButton_48->setCheckable(true);
        ui->pushButton_48->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[88]||arg1[arg1.length()-1]==chi[87])&&flag1) || ((arg1[arg1.length()-1]==ar[98]||arg1[arg1.length()-1]==ar[97])&&flag5)|| ((arg1[arg1.length()-1]==ivr[86]||arg1[arg1.length()-1]==ivr[87])&&flag6))
    {
        ui->pushButton_49->setEnabled(true);
        ui->pushButton_49->setCheckable(true);
        ui->pushButton_49->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[90]||arg1[arg1.length()-1]==chi[89])&&flag1) || ((arg1[arg1.length()-1]==ar[100]||arg1[arg1.length()-1]==ar[99])&&flag5)|| ((arg1[arg1.length()-1]==ivr[88]||arg1[arg1.length()-1]==ivr[89])&&flag6))
    {
        ui->pushButton_50->setEnabled(true);
        ui->pushButton_50->setCheckable(true);
        ui->pushButton_50->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==chi[92]||arg1[arg1.length()-1]==chi[91])&&flag1) || ((arg1[arg1.length()-1]==ar[102]||arg1[arg1.length()-1]==ar[101])&&flag5)|| ((arg1[arg1.length()-1]==ivr[90]||arg1[arg1.length()-1]==ivr[91])&&flag6))
    {
        ui->pushButton_51->setEnabled(true);
        ui->pushButton_51->setCheckable(true);
        ui->pushButton_51->setChecked(true);
    }
   if(((arg1[arg1.length()-1]==chi[94]||arg1[arg1.length()-1]==chi[93])&&flag1) || ((arg1[arg1.length()-1]==ar[104]||arg1[arg1.length()-1]==ar[103])&&flag5)|| ((arg1[arg1.length()-1]==ivr[92]||arg1[arg1.length()-1]==ivr[93])&&flag6))
    {
        ui->pushButton_52->setEnabled(true);
        ui->pushButton_52->setCheckable(true);
        ui->pushButton_52->setChecked(true);
    }

if(flag1){
    if(get[k].length()==tp){
        ui->textEdit->clear();
        k++;
        QFont font;
        font.setPointSize(20);
        ui->textEdit->setFont(font);
        ui->textEdit->setText(get[k]);
        tp=0;
        ui->lineEdit->clear();
    }
}
}
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
     ui->textEdit->setReadOnly(true);
    if(arg1.length()!=0){
    for(int i=0;i<64;++i)
    {
        b[i]->setCheckable(false);
        b[i]->setEnabled(false);
    }

    QString ff=ui->textEdit->toPlainText();
    if(arg1[arg1.length()-1]!=ff[tp]){

        QTextDocument *doc = ui->textEdit->document();

        // Создаем курсор для работы с текстом
        QTextCursor cursor(doc);

        // Устанавливаем позицию курсора перед символом
        int position = tp; // Номер буквы, которую вы хотите изменить
        cursor.setPosition(position);

        // Создаем формат для изменения цвета
        QTextCharFormat format;
        format.setForeground(QColor("red")); // Задаем цвет
cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor);
        // Применяем формат только к символу, на который указывает курсор
        cursor.setCharFormat(format);
    }
    else
    {

        QTextDocument *doc = ui->textEdit->document();

        // Создаем курсор для работы с текстом
        QTextCursor cursor(doc);

        // Устанавливаем позицию курсора перед символом
        int position = tp; // Номер буквы, которую вы хотите изменить
        cursor.setPosition(position);

        // Создаем формат для изменения цвета
        QTextCharFormat format;
        format.setForeground(QColor("green")); // Задаем цвет
        cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor);
        // Применяем формат только к символу, на который указывает курсор
        cursor.setCharFormat(format);
        corr++;
    }
      ui->textEdit->setReadOnly(true);
    if(flag1 || flag5 || flag6){
    check(arg1);
    }
    if(flag5||flag6)
    {
        ui->lineEdit->setAlignment(Qt::AlignLeft);
    }
    if(((arg1[arg1.length()-1]==bel[38] ||  arg1[arg1.length()-1]==bel[6]) && flag4) || ((arg1[arg1.length()-1]=='`' ||  arg1[arg1.length()-1]==deu[0]) && flag3)|| ((arg1[arg1.length()-1]==fr[0] ||  arg1[arg1.length()-1]==fr[1]) && flag2))
    {
        ui->pushButton->setEnabled(true);
        ui->pushButton->setCheckable(true);
        ui->pushButton->setChecked(true);

    }
    if(((arg1[arg1.length()-1]=='1' || arg1[arg1.length()-1]=='!') && (flag4 || flag3))|| ((arg1[arg1.length()-1]==fr[2] ||  arg1[arg1.length()-1]==fr[3]) && flag2))
    {
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_2->setCheckable(true);
        ui->pushButton_2->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='2' || arg1[arg1.length()-1]=='@') && flag4)|| ((arg1[arg1.length()-1]=='2' || arg1[arg1.length()-1]=='"') && flag3)|| ((arg1[arg1.length()-1]==fr[4] ||  arg1[arg1.length()-1]==fr[5]) && flag2))
    {
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_3->setCheckable(true);
        ui->pushButton_3->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='3' || arg1[arg1.length()-1]=='#') && flag4) || ((arg1[arg1.length()-1]=='3' || arg1[arg1.length()-1]==deu[1]) && flag3)|| ((arg1[arg1.length()-1]==fr[6] ||  arg1[arg1.length()-1]=='\u0022') && flag2))
    {
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_4->setCheckable(true);
        ui->pushButton_4->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='4' || arg1[arg1.length()-1]=='$') && (flag4||flag3))|| ((arg1[arg1.length()-1]==fr[7] ||  arg1[arg1.length()-1]==fr[8]) && flag2))
    {
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_5->setCheckable(true);
        ui->pushButton_5->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='5' || arg1[arg1.length()-1]=='%') && (flag4||flag3))||((arg1[arg1.length()-1]=='6' || arg1[arg1.length()-1]=='&') && flag3)|| ((arg1[arg1.length()-1]==fr[9] ||  arg1[arg1.length()-1]==fr[10]) && flag2))
    {
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_6->setCheckable(true);
        ui->pushButton_6->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='6' || arg1[arg1.length()-1]==':') && flag4)|| ((arg1[arg1.length()-1]=='7' || arg1[arg1.length()-1]=='/') && flag3)|| ((arg1[arg1.length()-1]==fr[11] ||  arg1[arg1.length()-1]==fr[12]) && flag2))
    {
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_7->setCheckable(true);
        ui->pushButton_7->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='7' || arg1[arg1.length()-1]=='&') && flag4)|| ((arg1[arg1.length()-1]=='6' || arg1[arg1.length()-1]=='(') && flag3)|| ((arg1[arg1.length()-1]==fr[13] ||  arg1[arg1.length()-1]==fr[14]) && flag2))
    {
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_8->setCheckable(true);
        ui->pushButton_8->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='8' || arg1[arg1.length()-1]=='*') && flag4)|| ((arg1[arg1.length()-1]=='9' || arg1[arg1.length()-1]==')') && flag3) || ((arg1[arg1.length()-1]==fr[15] ||  arg1[arg1.length()-1]==fr[16]) && flag2))
    {
        ui->pushButton_9->setEnabled(true);
        ui->pushButton_9->setCheckable(true);
        ui->pushButton_9->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='9' || arg1[arg1.length()-1]=='(')&& flag4) || ((arg1[arg1.length()-1]=='0' || arg1[arg1.length()-1]=='=') && flag3)|| ((arg1[arg1.length()-1]==fr[17] ||  arg1[arg1.length()-1]==fr[18]) && flag2) )
    {
        ui->pushButton_10->setEnabled(true);
        ui->pushButton_10->setCheckable(true);
        ui->pushButton_10->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='0' || arg1[arg1.length()-1]==')') && flag4)|| ((arg1[arg1.length()-1]==deu[2] || arg1[arg1.length()-1]=='?') && flag3)|| ((arg1[arg1.length()-1]==fr[19] ||  arg1[arg1.length()-1]==fr[20]) && flag2))
    {
        ui->pushButton_11->setEnabled(true);
        ui->pushButton_11->setCheckable(true);
        ui->pushButton_11->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='_' || arg1[arg1.length()-1]=='-') && flag4)|| ((arg1[arg1.length()-1]==deu[2] || arg1[arg1.length()-1]=='?') && flag3)|| ((arg1[arg1.length()-1]==fr[21] ||  arg1[arg1.length()-1]==fr[22]) && flag2))
    {
        ui->pushButton_12->setEnabled(true);
        ui->pushButton_12->setCheckable(true);
        ui->pushButton_12->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='=' || arg1[arg1.length()-1]=='+') && flag4)|| ((arg1[arg1.length()-1]=='`' || arg1[arg1.length()-1]==deu[3]) && flag3)|| ((arg1[arg1.length()-1]==fr[23] ||  arg1[arg1.length()-1]==fr[24]) && flag2))
    {
        ui->pushButton_13->setEnabled(true);
        ui->pushButton_13->setCheckable(true);
        ui->pushButton_13->setChecked(true);
    }
    /*if(arg1[arg1.length()-1]==QChar::fromLatin1(Qt::Key_Backspace))
    {
        ui->pushButton_14->setCheckable(true);
        ui->pushButton_14->setChecked(true);
    }
    if(arg1[arg1.length()-1]==QChar::fromLatin1(Qt::Key_Tab))
    {
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_15->setCheckable(true);
        ui->pushButton_15->setChecked(true);
    }*/
    if(((arg1[arg1.length()-1]==bel[10] ||  arg1[arg1.length()-1]==bel[42])&& flag4)|| ((arg1[arg1.length()-1]==deu[4] || arg1[arg1.length()-1]==deu[5]) && flag3)|| ((arg1[arg1.length()-1]==fr[25] ||  arg1[arg1.length()-1]==fr[26]) && flag2))
    {
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_16->setCheckable(true);
        ui->pushButton_16->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[24] ||  arg1[arg1.length()-1]==bel[56])&& flag4)|| ((arg1[arg1.length()-1]==deu[6] || arg1[arg1.length()-1]==deu[7]) && flag3)|| ((arg1[arg1.length()-1]==fr[27] ||  arg1[arg1.length()-1]==fr[28]) && flag2))
    {
        ui->pushButton_17->setEnabled(true);
        ui->pushButton_17->setCheckable(true);
        ui->pushButton_17->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[20] ||  arg1[arg1.length()-1]==bel[52])&& flag4)|| ((arg1[arg1.length()-1]==deu[8] || arg1[arg1.length()-1]==deu[9]) && flag3)|| ((arg1[arg1.length()-1]==fr[29] ||  arg1[arg1.length()-1]==fr[30]) && flag2))
    {
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_18->setCheckable(true);
        ui->pushButton_18->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[11] ||  arg1[arg1.length()-1]==bel[43])&& flag4)|| ((arg1[arg1.length()-1]==deu[10] || arg1[arg1.length()-1]==deu[11]) && flag3)|| ((arg1[arg1.length()-1]==fr[31] ||  arg1[arg1.length()-1]==fr[32]) && flag2))
    {
        ui->pushButton_19->setEnabled(true);
        ui->pushButton_19->setCheckable(true);
        ui->pushButton_19->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[5] ||  arg1[arg1.length()-1]==bel[37])&& flag4)|| ((arg1[arg1.length()-1]==deu[12] || arg1[arg1.length()-1]==deu[13]) && flag3)|| ((arg1[arg1.length()-1]==fr[33] ||  arg1[arg1.length()-1]==fr[34]) && flag2))
    {
        ui->pushButton_20->setEnabled(true);
        ui->pushButton_20->setCheckable(true);
        ui->pushButton_20->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[14] ||  arg1[arg1.length()-1]==bel[46])&& flag4)|| ((arg1[arg1.length()-1]==deu[14] || arg1[arg1.length()-1]==deu[15]) && flag3)|| ((arg1[arg1.length()-1]==fr[35] ||  arg1[arg1.length()-1]==fr[36]) && flag2))
    {
        ui->pushButton_21->setEnabled(true);
        ui->pushButton_21->setCheckable(true);
        ui->pushButton_21->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[3] ||  arg1[arg1.length()-1]==bel[35])&& flag4)|| ((arg1[arg1.length()-1]==deu[16] || arg1[arg1.length()-1]==deu[17]) && flag3)|| ((arg1[arg1.length()-1]==fr[37] ||  arg1[arg1.length()-1]==fr[38]) && flag2))
    {
        ui->pushButton_22->setEnabled(true);
        ui->pushButton_22->setCheckable(true);
        ui->pushButton_22->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[26] ||  arg1[arg1.length()-1]==bel[58])&& flag4)|| ((arg1[arg1.length()-1]==deu[18] || arg1[arg1.length()-1]==deu[19]) && flag3)|| ((arg1[arg1.length()-1]==fr[39] ||  arg1[arg1.length()-1]==fr[40]) && flag2))
    {
        ui->pushButton_23->setEnabled(true);
        ui->pushButton_23->setCheckable(true);
        ui->pushButton_23->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[21] ||  arg1[arg1.length()-1]==bel[53])&& flag4)|| ((arg1[arg1.length()-1]==deu[20] || arg1[arg1.length()-1]==deu[21]) && flag3)|| ((arg1[arg1.length()-1]==fr[41] ||  arg1[arg1.length()-1]==fr[42]) && flag2))
    {
        ui->pushButton_24->setEnabled(true);
        ui->pushButton_24->setCheckable(true);
        ui->pushButton_24->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[8] ||  arg1[arg1.length()-1]==bel[40])&& flag4)|| ((arg1[arg1.length()-1]==deu[22] || arg1[arg1.length()-1]==deu[23]) && flag3)|| ((arg1[arg1.length()-1]==fr[43] ||  arg1[arg1.length()-1]==fr[44]) && flag2))
    {
        ui->pushButton_25->setEnabled(true);
        ui->pushButton_25->setCheckable(true);
        ui->pushButton_25->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[23] ||  arg1[arg1.length()-1]==bel[55])&& flag4)|| ((arg1[arg1.length()-1]==deu[24] || arg1[arg1.length()-1]==deu[25]) && flag3)|| ((arg1[arg1.length()-1]==fr[45] ||  arg1[arg1.length()-1]==fr[46]) && flag2))
    {
        ui->pushButton_26->setEnabled(true);
        ui->pushButton_26->setCheckable(true);
        ui->pushButton_26->setChecked(true);
    }
    if((arg1[arg1.length()-1]==spec[0]&& flag4)|| ((arg1[arg1.length()-1]==deu[26] || arg1[arg1.length()-1]==deu[27]) && flag3)|| ((arg1[arg1.length()-1]==fr[47] ||  arg1[arg1.length()-1]==fr[48]) && flag2))
    {
        ui->pushButton_27->setEnabled(true);
        ui->pushButton_27->setCheckable(true);
        ui->pushButton_27->setChecked(true);
    }
    if(arg1[arg1.length()-1]=='|' || arg1[arg1.length()-1]==QChar::fromLatin1('\u005c') || ((arg1[arg1.length()-1]==deu[28] || arg1[arg1.length()-1]==deu[29]) && flag3)|| ((arg1[arg1.length()-1]==fr[49] ||  arg1[arg1.length()-1]==fr[50]) && flag2))
    {
        ui->pushButton_28->setEnabled(true);
        ui->pushButton_28->setCheckable(true);
        ui->pushButton_28->setChecked(true);
    }
    /*if(arg1[arg1.length()-1]==QChar::fromLatin1(Qt::Key_CapsLock))
    {
        ui->pushButton_29->setEnabled(true);
        ui->pushButton_29->setCheckable(true);
        ui->pushButton_29->setChecked(true);
    }*/
    if(((arg1[arg1.length()-1]==bel[22] ||  arg1[arg1.length()-1]==bel[54])&& flag4)||((arg1[arg1.length()-1]==deu[30] || arg1[arg1.length()-1]==deu[31]) && flag3)|| ((arg1[arg1.length()-1]==fr[51] ||  arg1[arg1.length()-1]==fr[52]) && flag2))
    {
        ui->pushButton_30->setEnabled(true);
        ui->pushButton_30->setCheckable(true);
        ui->pushButton_30->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[27] ||  arg1[arg1.length()-1]==bel[59])&& flag4)||((arg1[arg1.length()-1]==deu[32] || arg1[arg1.length()-1]==deu[33]) && flag3)|| ((arg1[arg1.length()-1]==fr[53] ||  arg1[arg1.length()-1]==fr[54]) && flag2))
    {
        ui->pushButton_31->setEnabled(true);
        ui->pushButton_31->setCheckable(true);
        ui->pushButton_31->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[2] ||  arg1[arg1.length()-1]==bel[34])&& flag4)||((arg1[arg1.length()-1]==deu[35] || arg1[arg1.length()-1]==deu[34]) && flag3)|| ((arg1[arg1.length()-1]==fr[55] ||  arg1[arg1.length()-1]==fr[56]) && flag2))
    {
        ui->pushButton_32->setEnabled(true);
        ui->pushButton_32->setCheckable(true);
        ui->pushButton_32->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[0] ||  arg1[arg1.length()-1]==bel[32])&& flag4)||((arg1[arg1.length()-1]==deu[36] || arg1[arg1.length()-1]==deu[37]) && flag3)|| ((arg1[arg1.length()-1]==fr[57] ||  arg1[arg1.length()-1]==fr[58]) && flag2))
    {
        ui->pushButton_33->setEnabled(true);
        ui->pushButton_33->setCheckable(true);
        ui->pushButton_33->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[16] ||  arg1[arg1.length()-1]==bel[48])&& flag4)||((arg1[arg1.length()-1]==deu[39] || arg1[arg1.length()-1]==deu[38]) && flag3)|| ((arg1[arg1.length()-1]==fr[59] ||  arg1[arg1.length()-1]==fr[60]) && flag2))
    {
        ui->pushButton_34->setEnabled(true);
        ui->pushButton_34->setCheckable(true);
        ui->pushButton_34->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[17] ||  arg1[arg1.length()-1]==bel[49])&& flag4)||((arg1[arg1.length()-1]==deu[40] || arg1[arg1.length()-1]==deu[41]) && flag3)|| ((arg1[arg1.length()-1]==fr[61] ||  arg1[arg1.length()-1]==fr[62]) && flag2))
    {
        ui->pushButton_35->setEnabled(true);
        ui->pushButton_35->setCheckable(true);
        ui->pushButton_35->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[15] ||  arg1[arg1.length()-1]==bel[47])&& flag4)||((arg1[arg1.length()-1]==deu[42] || arg1[arg1.length()-1]==deu[43]) && flag3)|| ((arg1[arg1.length()-1]==fr[63] ||  arg1[arg1.length()-1]==fr[64]) && flag2))
    {
        ui->pushButton_36->setEnabled(true);
        ui->pushButton_36->setCheckable(true);
        ui->pushButton_36->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[12] ||  arg1[arg1.length()-1]==bel[44])&& flag4)||((arg1[arg1.length()-1]==deu[44] || arg1[arg1.length()-1]==deu[45]) && flag3)|| ((arg1[arg1.length()-1]==fr[65] ||  arg1[arg1.length()-1]==fr[66]) && flag2))
    {
        ui->pushButton_37->setEnabled(true);
        ui->pushButton_37->setCheckable(true);
        ui->pushButton_37->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[4] ||  arg1[arg1.length()-1]==bel[36])&& flag4)||((arg1[arg1.length()-1]==deu[46] || arg1[arg1.length()-1]==deu[47]) && flag3)|| ((arg1[arg1.length()-1]==fr[67] ||  arg1[arg1.length()-1]==fr[68]) && flag2))
    {
        ui->pushButton_38->setEnabled(true);
        ui->pushButton_38->setCheckable(true);
        ui->pushButton_38->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[7] ||  arg1[arg1.length()-1]==bel[39])&& flag4)||((arg1[arg1.length()-1]==deu[48] || arg1[arg1.length()-1]==deu[49]) && flag3)|| ((arg1[arg1.length()-1]==fr[69] ||  arg1[arg1.length()-1]==fr[70]) && flag2))
    {
        ui->pushButton_39->setEnabled(true);
        ui->pushButton_39->setCheckable(true);
        ui->pushButton_39->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[29] ||  arg1[arg1.length()-1]==bel[61])&& flag4)||((arg1[arg1.length()-1]==deu[50] || arg1[arg1.length()-1]==deu[51]) && flag3)|| ((arg1[arg1.length()-1]==fr[71] ||  arg1[arg1.length()-1]==fr[72]) && flag2))
    {
        ui->pushButton_40->setEnabled(true);
        ui->pushButton_40->setCheckable(true);
        ui->pushButton_40->setChecked(true);
    }
    /*if(arg1[arg1.length()-1]==QChar::fromLatin1(Qt::Key_Enter))
    {
        ui->pushButton_41->setEnabled(true);
        ui->pushButton_41->setCheckable(true);
        ui->pushButton_41->setChecked(true);
    }
    if(arg1[arg1.length()-1]==QChar::fromLatin1(Qt::Key_Shift))
    {
        ui->pushButton_42->setEnabled(true);
        ui->pushButton_42->setCheckable(true);
        ui->pushButton_42->setChecked(true);
    }*/
    if(((arg1[arg1.length()-1]==bel[31] ||  arg1[arg1.length()-1]==bel[63])&& flag4)||((arg1[arg1.length()-1]==deu[52] || arg1[arg1.length()-1]==deu[53]) && flag3)|| ((arg1[arg1.length()-1]==fr[73] ||  arg1[arg1.length()-1]==fr[74]) && flag2))
    {
        ui->pushButton_43->setEnabled(true);
        ui->pushButton_43->setCheckable(true);
        ui->pushButton_43->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[25] ||  arg1[arg1.length()-1]==bel[57])&& flag4)||((arg1[arg1.length()-1]==deu[54] || arg1[arg1.length()-1]==deu[55]) && flag3)|| ((arg1[arg1.length()-1]==fr[75] ||  arg1[arg1.length()-1]==fr[76]) && flag2))
    {
        ui->pushButton_44->setEnabled(true);
        ui->pushButton_44->setCheckable(true);
        ui->pushButton_44->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[18] ||  arg1[arg1.length()-1]==bel[50])&& flag4)||((arg1[arg1.length()-1]==deu[56] || arg1[arg1.length()-1]==deu[57]) && flag3)|| ((arg1[arg1.length()-1]==fr[77] ||  arg1[arg1.length()-1]==fr[78]) && flag2))
    {
        ui->pushButton_45->setEnabled(true);
        ui->pushButton_45->setCheckable(true);
        ui->pushButton_45->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[13] ||  arg1[arg1.length()-1]==bel[45])&& flag4)||((arg1[arg1.length()-1]==deu[58] || arg1[arg1.length()-1]==deu[59]) && flag3)|| ((arg1[arg1.length()-1]==fr[79] ||  arg1[arg1.length()-1]==fr[80]) && flag2))
    {
        ui->pushButton_46->setEnabled(true);
        ui->pushButton_46->setCheckable(true);
        ui->pushButton_46->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[9] ||  arg1[arg1.length()-1]==bel[41])&& flag4)||((arg1[arg1.length()-1]==deu[60] || arg1[arg1.length()-1]==deu[61]) && flag3)|| ((arg1[arg1.length()-1]==fr[81] ||  arg1[arg1.length()-1]==fr[82]) && flag2))
    {
        ui->pushButton_47->setEnabled(true);
        ui->pushButton_47->setCheckable(true);
        ui->pushButton_47->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[19] ||  arg1[arg1.length()-1]==bel[51])&& flag4)||((arg1[arg1.length()-1]==deu[62] || arg1[arg1.length()-1]==deu[63]) && flag3)|| ((arg1[arg1.length()-1]==fr[83] ||  arg1[arg1.length()-1]==fr[84]) && flag2))
    {
        ui->pushButton_48->setEnabled(true);
        ui->pushButton_48->setCheckable(true);
        ui->pushButton_48->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[28] ||  arg1[arg1.length()-1]==bel[60])&& flag4)||((arg1[arg1.length()-1]==deu[64] || arg1[arg1.length()-1]==deu[65]) && flag3)|| ((arg1[arg1.length()-1]==fr[85] ||  arg1[arg1.length()-1]==fr[86]) && flag2))
    {
        ui->pushButton_49->setEnabled(true);
        ui->pushButton_49->setCheckable(true);
        ui->pushButton_49->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[1] ||  arg1[arg1.length()-1]==bel[33])&& flag4)||((arg1[arg1.length()-1]==deu[66] || arg1[arg1.length()-1]==deu[67]) && flag3)|| ((arg1[arg1.length()-1]==fr[87] ||  arg1[arg1.length()-1]==fr[88]) && flag2))
    {
        ui->pushButton_50->setEnabled(true);
        ui->pushButton_50->setCheckable(true);
        ui->pushButton_50->setChecked(true);
    }
    if(((arg1[arg1.length()-1]==bel[30] ||  arg1[arg1.length()-1]==bel[62])&& flag4)||((arg1[arg1.length()-1]==deu[68] || arg1[arg1.length()-1]==deu[69]) && flag3)|| ((arg1[arg1.length()-1]==fr[89] ||  arg1[arg1.length()-1]==fr[90]) && flag2))
    {
        ui->pushButton_51->setEnabled(true);
        ui->pushButton_51->setCheckable(true);
        ui->pushButton_51->setChecked(true);
    }
    if(((arg1[arg1.length()-1]=='?'|| arg1[arg1.length()-1]==spec[1])&& flag4)||((arg1[arg1.length()-1]==deu[70] || arg1[arg1.length()-1]==deu[71]) && flag3)|| ((arg1[arg1.length()-1]==fr[91] ||  arg1[arg1.length()-1]==fr[92]) && flag2))
    {
        ui->pushButton_52->setEnabled(true);
        ui->pushButton_52->setCheckable(true);
        ui->pushButton_52->setChecked(true);
    }
    tp++;
}
    if(flag4){
    if(bl[k].length()==tp){
    ui->textEdit->clear();
    k++;
    QFont font;
    font.setPointSize(20);
    if(k>bl.size()-1)
    {
        k=0;
        ui->textEdit->setFont(font);
        ui->textEdit->setText(bl[k]);
        ui->lineEdit->clear();
        on_pushButton_66_clicked();
        QMessageBox::information(nullptr,"Input","End");

    }
    else {
    ui->textEdit->setText(bl[k]);
    ui->lineEdit->clear();
    }
    tp=0;
    }
    }
    if(flag3){
        if(get[k].length()==tp){
            ui->textEdit->clear();
            k++;
            QFont font;
            font.setPointSize(20);
            if(k>get.size()-1)
            {
                k=0;
                ui->textEdit->setFont(font);
                ui->textEdit->setText(get[k]);
                ui->lineEdit->clear();
                on_pushButton_66_clicked();
                QMessageBox::information(nullptr,"Input","End");
            }
            else{
            ui->textEdit->setFont(font);
            ui->textEdit->setText(get[k]);
            }
            tp=0;
            ui->lineEdit->clear();
        }
    }
    if(flag2){
        if(fer[k].length()==tp){
            ui->textEdit->clear();
            k++;
            QFont font;
            font.setPointSize(20);
            if(k>fer.size()-1)
            {
                k=0;
                ui->textEdit->setFont(font);
                ui->textEdit->setText(fer[k]);
                ui->lineEdit->clear();
                on_pushButton_66_clicked();
                QMessageBox::information(nullptr,"Input","End");
            }
            else{
            ui->textEdit->setFont(font);
            ui->textEdit->setText(fer[k]);
            }
            tp=0;
            ui->lineEdit->clear();
        }
    }
    if(flag1){
        if(get[k].length()==tp){
            ui->textEdit->clear();
            k++;
            QFont font;
            font.setPointSize(20);
            if(k>get.size()-1)
            {
                k=0;
                ui->textEdit->setFont(font);
                ui->textEdit->setText(get[k]);
                ui->lineEdit->clear();
                on_pushButton_66_clicked();
                QMessageBox::information(nullptr,"Input","End");

            }
            else{
            ui->textEdit->setFont(font);
                ui->textEdit->setText(get[k]);
            }
            tp=0;
            ui->lineEdit->clear();
        }
    }
    if(flag5){
        if(bl[k].length()==tp){
            ui->textEdit->clear();
            k++;
            QFont font;
            font.setPointSize(20);
            if(k>bl.size()-1)
            {
                k=0;
                ui->textEdit->setFont(font);
                ui->textEdit->setText(bl[k]);
                ui->lineEdit->clear();
                on_pushButton_66_clicked();
                QMessageBox::information(nullptr,"Input","End");

            }
            else {
            ui->textEdit->setFont(font);
            ui->textEdit->setText(bl[k]);
            }
            tp=0;
            ui->lineEdit->clear();
        }
    }
    if(flag6){
        if(bl[k].length()==tp){
            ui->textEdit->clear();
            k++;
            QFont font;
            font.setPointSize(20);
            if(k>bl.size()-1)
            {
                k=0;
                ui->textEdit->setFont(font);
                ui->textEdit->setText(bl[k]);
                ui->lineEdit->clear();
                on_pushButton_66_clicked();
                QMessageBox::information(nullptr,"Input","End");

            }
            else {
            ui->textEdit->setFont(font);
            ui->textEdit->setText(bl[k]);
            }
            tp=0;
            ui->lineEdit->clear();
        }
    }
    aaa++;
    ui->label_3->setText(QString::number(corr/aaa*100));
}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->lineEdit->setReadOnly(false);
    switch (index){
    case 0:
    {
        ui->lineEdit->setAlignment(Qt::AlignLeft);
        flag1=0;
        flag2=1;
        flag3=0;
        flag4=0;
        flag5=0;
        flag6=0;
        f.change_fre(b,fr,bb);
        fer=f.read_fre();
        QFont font1;
        font1.setPointSize(20);
        ui->textEdit->setFont(font1);
        ui->textEdit->setText(fer[0]);
        tp=0;
        ui->lineEdit->setFocus();
        break;
    }
    case 1:
    {
        ui->lineEdit->setAlignment(Qt::AlignLeft);
        flag1=0;
        flag2=0;
        flag3=1;
        flag4=0;
        flag5=0;
        flag6=0;
        ger.change_ger(b,deu,bb);
        get=ger.read_ger();
        QFont font1;
        font1.setPointSize(20);
        ui->textEdit->setFont(font1);
        ui->textEdit->setText(get[0]);
        tp=0;
        ui->lineEdit->setFocus();
        break;
    }
    case 2:
    {
        ui->lineEdit->setAlignment(Qt::AlignLeft);
        flag1=1;
        flag2=0;
        flag3=0;
        flag4=0;
        flag5=0;
        flag6=0;
        chin.change_ch(b,chi,bb);
        get=chin.read_ch();
        QFont font1;
        font1.setPointSize(20);
        ui->textEdit->setFont(font1);
        ui->textEdit->setText(get[0]);
        tp=0;
        ui->lineEdit->setFocus();
        break;
    }
    case 3:
    {
        ui->lineEdit->setAlignment(Qt::AlignLeft);
        flag1=0;
        flag2=0;
        flag3=0;
        flag4=1;
        flag5=0;
        flag6=0;
        qDebug() << bel;
        blr.change_bel(b,bel,bb);
        bl=blr.read_bel();
        QFont font;
        font.setPointSize(20);
        ui->textEdit->setFont(font);
        ui->textEdit->setText(bl[0]);
        tp=0;
        ui->lineEdit->setFocus();
        break;
    }
    case 5:
    {
       ui->lineEdit->setAlignment(Qt::AlignLeft);
        flag1=0;
        flag2=0;
        flag3=0;
        flag4=0;
        flag5=1;
        flag6=0;
        qDebug() << bel;
        ara.change_arab(b,bel,bb);
        bl=ara.read_arab();
        QFont font;
        font.setPointSize(20);
        ui->textEdit->setFont(font);
        ui->textEdit->setText(bl[0]);
        tp=0;
        ui->lineEdit->setFocus();
        break;
    }
    case 4:
    {
        ui->lineEdit->setAlignment(Qt::AlignLeft);
        flag1=0;
        flag2=0;
        flag3=0;
        flag4=0;
        flag5=0;
        flag6=1;
        h.change_hebrew(b,fr,bb);
        bl=h.read_hebrew();
        QFont font1;
        font1.setPointSize(20);
        ui->textEdit->setFont(font1);
        ui->textEdit->setText(bl[0]);
        tp=0;
        ui->lineEdit->setFocus();
        break;
    }
    }
}

void MainWindow::change()
{
    ttt++;
    QTime curr=QTime(0,ttt);
    ui->timeEdit->setTime(curr);


}
void MainWindow::on_pushButton_65_clicked()
{
    aaa=1;
    corr=1;
    ui->pushButton_66->setHidden(false);
    disconnect(&timerr,SIGNAL(timeout()),this,SLOT(change()));
    timerr.stop();
    ttt=0;
    QTime currentTime=QTime(0,0);
     ui->timeEdit->setTime(currentTime);
    timerr.setInterval(1000);
    connect(&timerr,SIGNAL(timeout()),this,SLOT(change()));
    timerr.start();
}




void MainWindow::on_pushButton_66_clicked()
{
    aaa=1;
    corr=1;
    disconnect(&timerr,SIGNAL(timeout()),this,SLOT(change()));
    timerr.stop();
    ttt=0;
    QTime currentTime=QTime(0,0);
    ui->timeEdit->setTime(currentTime);
    ui->pushButton_66->setHidden(true);
}

