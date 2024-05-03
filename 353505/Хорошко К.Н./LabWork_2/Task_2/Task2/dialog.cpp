#include "dialog.h"

dialog::dialog(QWidget *parent = nullptr) : QDialog(parent)
{
    layout = new QGridLayout(this);

    labelSurname = new QLabel("Фамилия", this);
    labelName = new QLabel("Имя", this);
    labelFather = new QLabel("Отчество", this);
    labelMat = new QLabel("Математика", this);
    labelPhys = new QLabel("Физика", this);
    labelRus = new QLabel("Русский", this);
    labelAtestat = new QLabel("Аттестат", this);

    surname = new QLineEdit(this);
    name = new QLineEdit(this);
    father = new QLineEdit(this);
    mat = new QLineEdit(this);
    phys = new QLineEdit(this);
    rus = new QLineEdit(this);
    atestat = new QLineEdit(this);
    surname->setFocusPolicy(Qt::StrongFocus);

    layout->addWidget(labelSurname, 0, 0);
    layout->addWidget(surname, 0, 1);
    layout->addWidget(labelName, 1, 0);
    layout->addWidget(name, 1, 1);
    layout->addWidget(labelFather, 2, 0);
    layout->addWidget(father, 2, 1);
    layout->addWidget(labelMat, 3, 0);
    layout->addWidget(mat, 3, 1);
    layout->addWidget(labelPhys, 4, 0);
    layout->addWidget(phys, 4, 1);
    layout->addWidget(labelRus, 5, 0);
    layout->addWidget(rus, 5, 1);
    layout->addWidget(labelAtestat, 6, 0);
    layout->addWidget(atestat, 6, 1);

    connect(surname, &QLineEdit::returnPressed, [this](){ name->setFocus(); });
    connect(name, &QLineEdit::returnPressed, [this](){ father->setFocus(); });
    connect(father, &QLineEdit::returnPressed, [this](){ mat->setFocus(); });
    connect(mat, &QLineEdit::returnPressed, [this](){ phys->setFocus(); });
    connect(phys, &QLineEdit::returnPressed, [this](){ rus->setFocus(); });
    connect(rus, &QLineEdit::returnPressed, [this](){ atestat->setFocus(); });
    connect(atestat, &QLineEdit::returnPressed, this, &dialog::enableOkButton);

    connect(surname, &QLineEdit::textChanged, this, &dialog::disableOkButton);
    connect(name, &QLineEdit::textChanged, this, &dialog::disableOkButton);
    connect(father, &QLineEdit::textChanged, this, &dialog::disableOkButton);
    connect(mat, &QLineEdit::textChanged, this, &dialog::disableOkButton);
    connect(phys, &QLineEdit::textChanged, this, &dialog::disableOkButton);
    connect(rus, &QLineEdit::textChanged, this, &dialog::disableOkButton);

    okButton = new QPushButton("ОК",this);
    cancelButton = new QPushButton("Отмена", this);

    layout->addWidget(okButton, 7, 0, 1, 2);
    layout->addWidget(cancelButton, 8, 0, 1, 2);

    connect(okButton, &QPushButton::clicked, this, &dialog::myAccept);
    connect(cancelButton, &QPushButton::clicked, this, &dialog::reject);
}

void dialog::enableOkButton() {
    okButton->setEnabled(true);
}

void dialog::disableOkButton() {
    okButton->setEnabled(false);
}

QString dialog::getFio(){
    return fio;
}

int dialog::getMath(){
    return Mat;
}

int dialog::getPhys(){
    return Phys;
}

int dialog::getRus(){
    return Rus;
}

int dialog::getAtestat(){
    return Atestat;
}

void dialog::myAccept(){
    bool res = true;

    QRegularExpression regex("[а-яА-Я]+");
    regex.match(surname->text()).hasMatch();
    if (!regex.match(surname->text()).hasMatch()){
        res = false;
    }
    regex.match(name->text()).hasMatch();
    if (!regex.match(name->text()).hasMatch()){
        res = false;
    }
    regex.match(father->text()).hasMatch();
    if (!regex.match(father->text()).hasMatch()){
        res = false;
    }
    bool isNum;
    mat->text().toInt(&isNum);
    if (!isNum || mat->text().toInt(&isNum) > 100){
        res = false;
    }
    phys->text().toInt(&isNum);
    if (!isNum || phys->text().toInt(&isNum) > 100){
        res = false;
    }
    rus->text().toInt(&isNum);
    if (!isNum || rus->text().toInt(&isNum) > 100){
        res = false;
    }
    atestat->text().toInt(&isNum);
    if (!isNum || atestat->text().toInt(&isNum) > 100){
        res = false;
    }

    if (res){
        fio += surname->text();
        fio += " ";
        fio += name->text();
        fio += " ";
        fio += father->text();
        Mat = mat->text().toInt();
        Phys = phys->text().toInt();
        Rus = rus->text().toInt();
        Atestat = atestat->text().toInt();
        accept();
    }
    else {
        qDebug() << "adgasg";
        QString errorMessage = "Неверный ввод!";
        QMessageBox::critical(this, "Ошибка", errorMessage);
        cancelButton->click();
    }
}

void dialog::begin(QString fio, int matText, int physText, int rusText, int atText){
    QString surnameText;
    int position = 0;
    while (fio[position] != ' '){
        surnameText += fio[position];
        position++;
    }
    position++;
    QString nameText;
    while (fio[position] != ' '){
        nameText += fio[position];
        position++;
    }
    position++;
    QString fatherText;
    while (position != fio.length()){
        fatherText += fio[position];
        position++;
    }

    surname->setPlaceholderText(surnameText);
    name->setPlaceholderText(nameText);
    father->setPlaceholderText(fatherText);
    mat->setPlaceholderText(QString::number(matText));
    phys->setPlaceholderText(QString::number(physText));
    rus->setPlaceholderText(QString::number(rusText));
    atestat->setPlaceholderText(QString::number(atText));
}
