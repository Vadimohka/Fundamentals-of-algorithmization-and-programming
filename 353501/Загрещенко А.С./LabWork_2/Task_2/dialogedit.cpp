#include "dialogedit.h"
#include "QMessageBox"

DialogEdit::DialogEdit(QWidget *parent) : QDialog(parent)
{
    this->resize(300, 300);

    QRegularExpressionValidator *intValidator = new QRegularExpressionValidator(QRegularExpression("[1-9]\\d{0,8}"));

    group_line = new QLineEdit(this);
    code_line = new QLineEdit(this);
    code_line->setValidator(intValidator);
    name_line = new QLineEdit(this);
    model_line = new QLineEdit(this);
    price_line = new QLineEdit(this);
    price_line->setValidator(intValidator);
    count_line = new QLineEdit(this);
    count_line->setValidator(intValidator);

    group_label = new QLabel(this);
    code_label = new QLabel(this);
    name_label = new QLabel(this);
    model_label = new QLabel(this);
    price_label = new QLabel(this);
    count_label = new QLabel(this);

    group_label->setText("Группа товара");
    code_label->setText("Код товара");
    name_label->setText("Наименование");
    model_label->setText("Модель товара");
    price_label->setText("Цена товара");
    count_label->setText("Количество");

    save_button = new QPushButton(this);
    save_button->setText("Изменить");
    cancel_button = new QPushButton(this);
    cancel_button->setText("Отмена");

    layout = new QGridLayout(this);

    layout->addWidget(name_line, 1, 0, 1, 2);
    layout->addWidget(code_line, 3, 0, 1, 2);
    layout->addWidget(group_line, 5, 0, 1, 2);
    layout->addWidget(model_line, 7, 0, 1, 2);
    layout->addWidget(price_line, 9, 0, 1, 2);
    layout->addWidget(count_line, 11, 0, 1, 2);

    layout->addWidget(name_label, 0, 0, 1, 2);
    layout->addWidget(code_label, 2, 0, 1, 2);
    layout->addWidget(group_label, 4, 0, 1, 2);
    layout->addWidget(model_label, 6, 0, 1, 2);
    layout->addWidget(price_label, 8, 0, 1, 2);
    layout->addWidget(count_label, 10, 0, 1, 2);

    layout->addWidget(cancel_button, 12, 0, 1, 1);
    layout->addWidget(save_button, 12, 1, 1, 1);

    this->setLayout(layout);

    connect(cancel_button, &QPushButton::clicked, this, &DialogEdit::reject);
    connect(save_button, &QPushButton::clicked, this, &DialogEdit::SaveButtonClick);


}

DialogEdit::DialogEdit(Statement *good, int number, QWidget *parent): DialogEdit(parent)
{
    this->number = number;
    group_line->setText(good->getGroup());
    code_line->setText(QString::number(good->getCode()));
    name_line->setText(good->getName());
    model_line->setText(good->getModel());
    price_line->setText(QString::number(good->getPrice()));
    count_line->setText(QString::number(good->getCount()));
}

DialogEdit::~DialogEdit()
{
    delete group_line;
    delete code_line;
    delete name_line;
    delete model_line;
    delete price_line;
    delete count_line;

    delete group_label;
    delete code_label;
    delete name_label;
    delete model_label;
    delete price_label;
    delete count_label;

    delete save_button;
    delete cancel_button;

    delete layout;
}

bool DialogEdit::CheckAddLinesCorrect()
{
    bool fl = true;
    if (code_line->text().toInt() < 0 || count_line->text().toInt() < 0 || price_line->text().toInt() < 0) {
        return false;
    }
    fl = fl && CheckStrCorrect(group_line->text());
    fl = fl && CheckStrCorrect(code_line->text());
    fl = fl && CheckStrCorrect(name_line->text());
    fl = fl && CheckStrCorrect(price_line->text());
    fl = fl && CheckStrCorrect(count_line->text());
    fl = fl && CheckStrCorrect(model_line->text());
    return fl;
}

void DialogEdit::SaveButtonClick()
{
    if (CheckAddLinesCorrect()) {
        int count = count_line->text().toInt();
        int price = price_line->text().toInt();
        QString model = model_line->text();
        QString name = name_line->text();
        int code = code_line->text().toInt();
        QString group = group_line->text();
        emit EditSignal(count, price, model, name, code, group, number);
        this->accept();
    }
    else {
        QMessageBox::critical(nullptr, "Неверные данные", "Неверные данные");
    }
}
