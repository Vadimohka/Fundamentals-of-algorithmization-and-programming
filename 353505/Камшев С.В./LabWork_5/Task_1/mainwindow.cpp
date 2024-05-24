#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->GenerateTextRadioButton->setChecked(true);

    OpenTextButton = new QPushButton(this);
    OpenTextButton->setGeometry(0, 60, 200, 30);
    OpenTextButton->setText("Открыть файл");
    OpenTextButton->setEnabled(false);
    OpenTextButton->setVisible(false);

    QStringList ComboBoxList = {"Беларуская", "Deutsch", "Français", "中文", "עברית", "العربية"};
    LanguageComboBox = new QComboBox(this);
    LanguageComboBox->setGeometry(0, 140, 200, 30);
    LanguageComboBox->addItems(ComboBoxList);

    QFont font = ui->TextLabel->font();
    font.setPixelSize(24);
    ui->TextLabel->setFont(font);
    ui->TextLabel->setEnabled(false);

    font = ui->label_2->font();
    font.setPixelSize(24);
    ui->label_2->setFont(font);
    ui->label_2->setEnabled(false);
    ui->label_2->setPalette(Qt::green);
    ButtonsInisialisation();

    font = ui->label->font();
    font.setPixelSize(24);
    ui->label->setFont(font);
    ui->pushButton->setEnabled(false);
    ui->pushButton->setPalette(Qt::gray);
    ui->pushButton->setFocusPolicy(Qt::NoFocus);
    ui->label->setVisible(false);

    connect(OpenTextButton, &QPushButton::pressed, [=](){on_OpenTextButton_clicked();});
    timer = new QTimer;
    connect(timer, &QTimer::timeout, [&](){
        ui->TimeLabel->setText(QString::number(start.secsTo(QTime::currentTime())/60) + ":" + QString::number(start.secsTo(QTime::currentTime())%60));
        ui->SpeedLabel->setText(QString::number((NumberOfAlphas) * 60/ (start.secsTo(QTime::currentTime()))) + " знаков в минуту");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartTest()
{
    ChineInputString = "";
    ui->label->setVisible(false);
    ui->Alphaslabel->setText("");
    ui->ErrorsLabel->setText("");
    ui->ProzentLabel->setText("");
    start = QTime::currentTime();
    if (ui->GenerateTextRadioButton->isChecked()){
        NumberOfErrors = 0;
        IndexOfAlpha = 0;
        NumberOfAlphas = 0;
        isTested = true;
        ui->GenerateTextRadioButton->setEnabled(false);
        ui->OpenTextRadioButton->setEnabled(false);
        ui->StartPushButton->setEnabled(false);
        OpenTextButton->setEnabled(false);
        LanguageComboBox->setEnabled(false);

        ui->GenerateTextRadioButton->setPalette(Qt::gray);
        ui->OpenTextRadioButton->setPalette(Qt::gray);
        ui->StartPushButton->setPalette(Qt::gray);
        OpenTextButton->setPalette(Qt::gray);
        LanguageComboBox->setEnabled(false);
        LanguageComboBox->setPalette(Qt::gray);
        ui->pushButton->setEnabled(true);
        ui->pushButton->setPalette(Qt::white);

        GenerateText();
        ui->TextLabel->setText(CopyText);
        if (LanguageComboBox->currentText() == "中文") ui->label->setText(ChinaMap[Text[0]]);
        timer->start(1000);

    }
    if (ui->OpenTextRadioButton->isChecked() && Text != ""){
        CopyText = Text;
        if (LanguageComboBox->currentText() == "Беларуская") BelarusianTextGenerate();
        else if (LanguageComboBox->currentText() == "Deutsch") GermanTextGenerate();
        else if (LanguageComboBox->currentText() == "Français") FrenchTextGenerate();
        else if (LanguageComboBox->currentText() == "中文") ChineseTextGenerate();
        else if (LanguageComboBox->currentText() == "العربية") ArabianTextGenerate();
        else if (LanguageComboBox->currentText() == "עברית") HebrewTextGenerate();
        Text = CopyText;
        while (Text.back() == ' ') Text.erase(Text.end() - 1);
        CopyText = Text;
        CopyText.replace(" ", "_");
        ui->TextLabel->setText(CopyText);

        NumberOfErrors = 0;
        IndexOfAlpha = 0;
        NumberOfAlphas = 0;
        isTested = true;
        ui->GenerateTextRadioButton->setEnabled(false);
        ui->OpenTextRadioButton->setEnabled(false);
        ui->StartPushButton->setEnabled(false);
        OpenTextButton->setEnabled(false);
        LanguageComboBox->setEnabled(false);
        ui->pushButton->setEnabled(true);
        ui->pushButton->setPalette(Qt::white);

        ui->GenerateTextRadioButton->setPalette(Qt::gray);
        ui->OpenTextRadioButton->setPalette(Qt::gray);
        ui->StartPushButton->setPalette(Qt::gray);
        OpenTextButton->setPalette(Qt::gray);
        LanguageComboBox->setEnabled(false);
        LanguageComboBox->setPalette(Qt::gray);
        if (LanguageComboBox->currentText() == "中文") ui->label->setText(ChinaMap[Text[0]]);
        timer->start(1000);
    }
}

void MainWindow::EndTest()
{
    RandomOffset = 0;
    ui->label->setVisible(false);
    timer->stop();
    ui->TextLabel->setText("");
    ui->label_2->setText("");
    Text = "";
    CopyText = "";
    isTested = false;

    ui->GenerateTextRadioButton->setEnabled(true);
    ui->OpenTextRadioButton->setEnabled(true);
    ui->StartPushButton->setEnabled(true);
    OpenTextButton->setEnabled(true);
    LanguageComboBox->setEnabled(true);
    ui->pushButton->setEnabled(false);
    ui->pushButton->setPalette(Qt::gray);

    ui->GenerateTextRadioButton->setPalette(Qt::white);
    ui->OpenTextRadioButton->setPalette(Qt::white);
    ui->StartPushButton->setPalette(Qt::white);
    OpenTextButton->setPalette(Qt::white);
    LanguageComboBox->setPalette(Qt::white);

    Alphas.clear();
    LowerAlphas.clear();
    CapsAlphas.clear();
    ShiftAlphas.clear();
    Caps_ShiftAlphas.clear();

}

void MainWindow::GenerateText()
{
    Text = "";
    RandomOffset = 0;
    lengthGenerate();
    if (LanguageComboBox->currentText() == "Беларуская") BelarusianTextGenerate();
    else if (LanguageComboBox->currentText() == "Deutsch") GermanTextGenerate();
    else if (LanguageComboBox->currentText() == "Français") FrenchTextGenerate();
    else if (LanguageComboBox->currentText() == "中文") ChineseTextGenerate();
    else if (LanguageComboBox->currentText() == "العربية") ArabianTextGenerate();
    else if (LanguageComboBox->currentText() == "עברית") HebrewTextGenerate();
    if (Alphas.back().isEmpty() || Alphas.back() == " ") Alphas.pop_back();
    for (int i = 0; i <= lengthOfText; ){
        int spaceInterval = spaceIntervalGenerate();
        for (int j = 0; j < spaceInterval; ){
            i++;
            j++;
            Text += appendRandomAlpha();
            if (i == lengthOfText) break;
        }
        Text += " ";
    }
    while (Text.back() == ' ') Text.erase(Text.end() - 1);
    CopyText = Text;
    CopyText.replace(" ", "_");
}

void MainWindow::BelarusianTextGenerate()
{
    MapInizialisation("/home/stepan/Labs OAIP/5/1/ButtonsNumbersBy");
    QFile file("/home/stepan/Labs OAIP/5/1/by.txt");
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()){
        QString str = file.readAll();
        Alphas = str.split(" ");
        file.close();
    }
    Alphas.pop_back();
    ui->label_2->setGeometry(26, 52, 281, 31);
    ui->TextLabel->setGeometry(310, 52, 810, 31);
    ui->TextLabel->setAlignment(Qt::AlignLeft);
    ui->label_2->setAlignment(Qt::AlignRight);
}

void MainWindow::GermanTextGenerate()
{
    MapInizialisation("/home/stepan/Labs OAIP/5/1/ButtonsNumbersGer");
    QFile file("/home/stepan/Labs OAIP/5/1/deu.txt");
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()){
        QString str = file.readAll();
        Alphas = str.split(" ");
        file.close();
    }
    Alphas.pop_back();
    ui->label_2->setGeometry(26, 52, 281, 31);
    ui->TextLabel->setGeometry(310, 52, 810, 31);
    ui->TextLabel->setAlignment(Qt::AlignLeft);
    ui->label_2->setAlignment(Qt::AlignRight);
}

void MainWindow::FrenchTextGenerate()
{
    MapInizialisation("/home/stepan/Labs OAIP/5/1/ButtonsNumbersFr");
    QFile file("/home/stepan/Labs OAIP/5/1/fra.txt");
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()){
        QString str = file.readAll();
        Alphas = str.split(" ");
        file.close();
    }
    Alphas.pop_back();
    ui->label_2->setGeometry(26, 52, 281, 31);
    ui->TextLabel->setGeometry(310, 52, 810, 31);
    ui->TextLabel->setAlignment(Qt::AlignLeft);
    ui->label_2->setAlignment(Qt::AlignRight);
}

void MainWindow::ChineseTextGenerate()
{
    ui->label->setVisible(true);
    QStringList changeList;
    ChineTranclitAlphas.clear();
    Alphas.clear();
    MapInizialisation("/home/stepan/Labs OAIP/5/1/ButtonsNumbersCh");
    QFile file("/home/stepan/Labs OAIP/5/1/ch.txt");
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()){
        QString str = file.readAll();
        changeList = str.split("\n");
        file.close();
    }
    changeList.pop_back();
    foreach (QString s, changeList) {
        ChineTranclitAlphas.append(s.split(" ")[1]);
        Alphas.append(s.split(" ")[0]);
        ChinaMap[Alphas.back()] = ChineTranclitAlphas.back();
    }
    ui->label_2->setGeometry(26, 52, 281, 31);
    ui->TextLabel->setGeometry(310, 52, 810, 31);
    ui->TextLabel->setAlignment(Qt::AlignLeft);
    ui->label_2->setAlignment(Qt::AlignRight);

}

void MainWindow::ArabianTextGenerate()
{
    MapInizialisation("/home/stepan/Labs OAIP/5/1/ButtonsNumbersArab");
    QFile file("/home/stepan/Labs OAIP/5/1/arab.txt");
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()){
        QString str = file.readAll();
        Alphas = str.split(" ");
        file.close();
    }
    Alphas.pop_back();
    ui->label_2->setGeometry(839, 52, 281, 31);
    ui->TextLabel->setGeometry(26, 52, 810, 31);
    ui->label_2->setAlignment(Qt::AlignRight);

}

void MainWindow::HebrewTextGenerate()
{
    MapInizialisation("/home/stepan/Labs OAIP/5/1/ButtonsNumbersHebr");
    QFile file("/home/stepan/Labs OAIP/5/1/ivrit.txt");
    file.open(QIODevice::ReadOnly);
    if (file.isOpen()){
        QString str = file.readAll();
        Alphas = str.split(" ");
        file.close();
    }
    Alphas.pop_back();
    ui->label_2->setGeometry(839, 52, 281, 31);
    ui->TextLabel->setGeometry(26, 52, 810, 31);
    ui->label_2->setAlignment(Qt::AlignRight);
}

void MainWindow::lengthGenerate()
{
    QRandomGenerator rand(QTime(0,0,0).msecsTo(QTime::currentTime()) + RandomOffset);
    RandomOffset++;
    lengthOfText = rand.bounded(80, 101);
}

int MainWindow::spaceIntervalGenerate()
{
    QRandomGenerator rand(QTime(0,0,0).msecsTo(QTime::currentTime()) + RandomOffset);
    RandomOffset++;
    return rand.bounded(1, 8);
}

QString MainWindow::appendRandomAlpha()
{
    QRandomGenerator rand(QTime(0,0,0).msecsTo(QTime::currentTime()) + RandomOffset);
    RandomOffset++;
    return Alphas[rand.bounded(0, Alphas.size())];
}

void MainWindow::ButtonsInisialisation()
{

    VectorOfButtons.append(ui->pushButton_1);
    VectorOfButtons.append(ui->pushButton_2);
    VectorOfButtons.append(ui->pushButton_3);
    VectorOfButtons.append(ui->pushButton_4);
    VectorOfButtons.append(ui->pushButton_5);
    VectorOfButtons.append(ui->pushButton_6);
    VectorOfButtons.append(ui->pushButton_7);
    VectorOfButtons.append(ui->pushButton_8);
    VectorOfButtons.append(ui->pushButton_9);
    VectorOfButtons.append(ui->pushButton_10);
    VectorOfButtons.append(ui->pushButton_11);
    VectorOfButtons.append(ui->pushButton_12);
    VectorOfButtons.append(ui->pushButton_13);
    VectorOfButtons.append(ui->pushButton_14);
    VectorOfButtons.append(ui->pushButton_15);
    VectorOfButtons.append(ui->pushButton_16);
    VectorOfButtons.append(ui->pushButton_17);
    VectorOfButtons.append(ui->pushButton_18);
    VectorOfButtons.append(ui->pushButton_19);
    VectorOfButtons.append(ui->pushButton_20);
    VectorOfButtons.append(ui->pushButton_21);
    VectorOfButtons.append(ui->pushButton_22);
    VectorOfButtons.append(ui->pushButton_23);
    VectorOfButtons.append(ui->pushButton_24);
    VectorOfButtons.append(ui->pushButton_25);
    VectorOfButtons.append(ui->pushButton_26);
    VectorOfButtons.append(ui->pushButton_27);
    VectorOfButtons.append(ui->pushButton_28);
    VectorOfButtons.append(ui->pushButton_29);
    VectorOfButtons.append(ui->pushButton_30);
    VectorOfButtons.append(ui->pushButton_31);
    VectorOfButtons.append(ui->pushButton_32);
    VectorOfButtons.append(ui->pushButton_33);
    VectorOfButtons.append(ui->pushButton_34);
    VectorOfButtons.append(ui->shiftPushButton);
    VectorOfButtons.append(ui->spacePushButton);
    VectorOfButtons.append(ui->CapsLushButton);
    VectorOfButtons.append(ui->pushButton_35);
    VectorOfButtons.append(ui->pushButton_36);
    VectorOfButtons.append(ui->pushButton_37);
    VectorOfButtons.append(ui->pushButton_38);
    VectorOfButtons.append(ui->pushButton_39);
    VectorOfButtons.append(ui->pushButton_40);
    VectorOfButtons.append(ui->pushButton_41);
    VectorOfButtons.append(ui->pushButton_42);
    VectorOfButtons.append(ui->pushButton_43);
    VectorOfButtons.append(ui->pushButton_44);
    VectorOfButtons.append(ui->pushButton_45);
    VectorOfButtons.append(ui->pushButton_46);
    VectorOfButtons.append(ui->pushButton_47);

    foreach (QPushButton* i, VectorOfButtons) {
        i->setEnabled(false);
    }

}

void MainWindow::MapInizialisation(QString FileName)
{
    ButtonsMap.clear();
    QFile file(FileName);
    file.open(QIODevice::ReadOnly);
    QString str = file.readAll();
    file.close();
    QStringList NumbersPair = str.split("\n");
    if (NumbersPair.back() == "") NumbersPair.pop_back();
    foreach (QString i, NumbersPair) {
        ButtonsMap[i.split(" ")[0].toInt()] = i.split(" ")[1].toInt();
        LowerAlphas.append(i.split(" ")[2]);
        CapsAlphas.append(i.split(" ")[3]);
        ShiftAlphas.append(i.split(" ")[4]);
        Caps_ShiftAlphas.append(i.split(" ")[5]);
        VectorOfButtons[i.split(" ")[1].toInt()]->setText(i.split(" ")[2]);
    }
}



void MainWindow::ChangeAlphas(int ind)
{
    int j = 0;
    if (ind == 1){
        for (int i = 0; i < LowerAlphas.size(); ) {
            if (VectorOfButtons[j] != ui->CapsLushButton && VectorOfButtons[j] != ui->spacePushButton && VectorOfButtons[j] != ui->shiftPushButton){
                VectorOfButtons[j]->setText(LowerAlphas[i]);
                i++;
            }
            j++;
        }
    }
    else if (ind == 2){

        for (int i = 0; i < LowerAlphas.size();) {
            if (VectorOfButtons[j] != ui->CapsLushButton && VectorOfButtons[j] != ui->spacePushButton && VectorOfButtons[j] != ui->shiftPushButton){
                VectorOfButtons[j]->setText(CapsAlphas[i]);
                i++;
            }
            j++;
        }
    }
    else if (ind == 3){
        for (int i = 0; i < LowerAlphas.size();) {
            if (VectorOfButtons[j] != ui->CapsLushButton && VectorOfButtons[j] != ui->spacePushButton && VectorOfButtons[j] != ui->shiftPushButton){
                VectorOfButtons[j]->setText(ShiftAlphas[i]);
                i++;
            }
            j++;
        }
    }
    else {
        for (int i = 0; i < LowerAlphas.size();) {
            if (VectorOfButtons[j] != ui->CapsLushButton && VectorOfButtons[j] != ui->spacePushButton && VectorOfButtons[j] != ui->shiftPushButton){
                VectorOfButtons[j]->setText(Caps_ShiftAlphas[i]);
                i++;
            }
            j++;
        }
    }
}

void MainWindow::on_OpenTextButton_clicked()
{
    QString FileName = QFileDialog::getOpenFileName(this, "Выберите файл", "/home/stepan/Labs OAIP/5/1", "*.txt");
    if (!FileName.isEmpty()){
        QFile file(FileName);
        file.open(QIODevice::ReadOnly);
        if (file.isOpen()){
            Text = file.readAll();
            Text.replace("\n", " ");
            file.close();
        }
        else{
            QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
        }
    }
    else {
        QMessageBox::information(this, "Внимание", "Файл не был открыт");
    }
}


void MainWindow::on_GenerateTextRadioButton_clicked()
{
    OpenTextButton->setEnabled(false);
    OpenTextButton->setVisible(false);
}

void MainWindow::on_OpenTextRadioButton_clicked()
{
    OpenTextButton->setEnabled(true);
    OpenTextButton->setVisible(true);
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (isTested){
        if (LanguageComboBox->currentText() == "中文"){
            foreach (QPushButton* i, VectorOfButtons) {
                if (i != ui->CapsLushButton && i != ui->shiftPushButton) {
                    i->setPalette(Qt::white);
                    i->setStyleSheet("QPushButton {color: black}");
                }
            }
            if (event->modifiers() &Qt::ShiftModifier){
                ChangeAlphas(isCaps? 4:3);
                VectorOfButtons[34]->setPalette(Qt::green);
            }
            if (event->key() == Qt::Key_CapsLock){
                VectorOfButtons[36]->setPalette(isCaps? Qt::white :Qt::green);
                isCaps = !isCaps;
                if (!isCaps) VectorOfButtons[36]->setStyleSheet("QPushButton {color: black}");
                ChangeAlphas(isCaps? ((event->modifiers() &Qt::ShiftModifier) ? 4 : 2) : ((event->modifiers() &Qt::ShiftModifier) ? 3 : 1));
                return;
            }

            if (Text[0] == ' '){
                if (event->key() == 32){
                    ui->label_2->setText(ui->label_2->text() + Text[0]);
                    Text.erase(Text.begin(), Text.begin() + 1);
                    CopyText = Text;
                    CopyText.replace(" ", "_");
                    ui->TextLabel->setText(CopyText);
                    ui->label->setText(ChinaMap[Text[0]]);
                    NumberOfAlphas++;
                    ui->Alphaslabel->setText("Количество знаков " + QString::number(NumberOfAlphas));
                    ui->ProzentLabel->setText("Точность " + QString::number(100 * NumberOfAlphas/(double(NumberOfAlphas + NumberOfErrors))) + "%");
                    if (Text == "") EndTest();
                }
            }
            else if (ui->label->text() != "" && event->text() == ui->label->text()[0]){
                ChineInputString += event->text();
                QString str = ui->label->text();
                str.erase(str.begin(), str.begin() + 1);
                ui->label->setText(str);
            }
            else{
                if (event->key() == 32 && ui->label->text() == ""){
                    ui->label_2->setText(ui->label_2->text() + Text[0]);
                    Text.erase(Text.begin(), Text.begin() + 1);
                    CopyText = Text;
                    CopyText.replace(" ", "_");
                    ui->TextLabel->setText(CopyText);
                    if (Text != "") ui->label->setText(ChinaMap[Text[0]]);
                    NumberOfAlphas++;
                    ui->Alphaslabel->setText("Количество знаков " + QString::number(NumberOfAlphas));
                    ui->ProzentLabel->setText("Точность " + QString::number(100 * NumberOfAlphas/(double(NumberOfAlphas + NumberOfErrors))) + "%");
                    if (Text == "") EndTest();
                }
                else{
                    if (ButtonsMap.contains(event->key())) VectorOfButtons[ButtonsMap[event->key()]]->setPalette(Qt::red);
                    NumberOfErrors++;
                }
            }

        }
        else{
            foreach (QPushButton* i, VectorOfButtons) {
                if (i != ui->CapsLushButton && i != ui->shiftPushButton) {
                    i->setPalette(Qt::white);
                    i->setStyleSheet("QPushButton {color: black}");
                }
            }
            if (event->modifiers() &Qt::ShiftModifier){
                ChangeAlphas(isCaps? 4:3);
                VectorOfButtons[34]->setPalette(Qt::green);
            }
            if (event->key() == Qt::Key_CapsLock){
                VectorOfButtons[36]->setPalette(isCaps? Qt::white :Qt::green);
                isCaps = !isCaps;
                if (!isCaps) VectorOfButtons[36]->setStyleSheet("QPushButton {color: black}");
                ChangeAlphas(isCaps? ((event->modifiers() &Qt::ShiftModifier) ? 4 : 2) : ((event->modifiers() &Qt::ShiftModifier) ? 3 : 1));
                return;
            }
            if (event->text() == Text[IndexOfAlpha]){
                ui->label_2->setText(ui->label_2->text() + Text[0]);
                VectorOfButtons[36]->setPalette(!isCaps? Qt::white :Qt::green);
                if (!isCaps) VectorOfButtons[36]->setStyleSheet("QPushButton {color: black}");
                Text.erase(Text.begin(), Text.begin() + 1);
                CopyText = Text;
                CopyText.replace(" ", "_");
                ui->TextLabel->setText(CopyText);
                NumberOfAlphas++;
                ui->Alphaslabel->setText("Количество знаков " + QString::number(NumberOfAlphas));
                ui->ProzentLabel->setText("Точность " + QString::number(100 * NumberOfAlphas/(double(NumberOfAlphas + NumberOfErrors))) + "%");
                if (Text == "") EndTest();
            }
            else  {
                QString Upstr = event->text().toUpper();
                QString Lowerstr = event->text().toLower();
                if (Text[IndexOfAlpha].isUpper() && Upstr == Text[IndexOfAlpha]){
                    VectorOfButtons[34]->setPalette(Qt::red);
                    NumberOfErrors++;
                }
                else if (isCaps && Lowerstr == Text[IndexOfAlpha]){
                    VectorOfButtons[36]->setPalette(Qt::red);
                    NumberOfErrors++;
                }
                else if (Lowerstr == Text[IndexOfAlpha]){
                    VectorOfButtons[34]->setPalette(Qt::red);
                    NumberOfErrors++;
                }
                else if (event->key() != 16777248){
                    if (event->key() == 32) VectorOfButtons[35]->setPalette(Qt::red);
                    else if (ButtonsMap.contains(event->key())) VectorOfButtons[ButtonsMap[event->key()]]->setPalette(Qt::red);
                    NumberOfErrors++;
                }

                if (LanguageComboBox->currentText() == "עברית"){
                    if (isCaps){
                        VectorOfButtons[36]->setPalette(Qt::red);
                        NumberOfErrors++;
                    }
                    if (event->modifiers() &Qt::ShiftModifier){
                        VectorOfButtons[34]->setPalette(Qt::red);
                        NumberOfErrors++;
                    }
                }
            }
        }
        ui->ErrorsLabel->setText("Количество ошибок " + QString::number(NumberOfErrors));
        if (NumberOfAlphas != 0) ui->ProzentLabel->setText("Точность " + QString::number(100 * NumberOfAlphas/(double(NumberOfAlphas + NumberOfErrors))) + "%");
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == 16777248){
        ChangeAlphas(isCaps? 2:1);
        VectorOfButtons[34]->setPalette(Qt::white);
        VectorOfButtons[34]->setStyleSheet("QPushButton {color: black}");
    }
}

void MainWindow::on_StartPushButton_clicked()
{
    if (!isTested){
        StartTest();
        return;
    }
}


void MainWindow::on_pushButton_clicked()
{
    EndTest();
}

