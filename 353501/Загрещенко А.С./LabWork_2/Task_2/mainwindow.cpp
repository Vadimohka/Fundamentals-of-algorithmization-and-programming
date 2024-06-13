#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central_widget = new QWidget(this);
    this->setCentralWidget(central_widget);

    layout = new QGridLayout(central_widget);
    central_widget->setLayout(layout);


    QRegularExpressionValidator *intValidator = new QRegularExpressionValidator(QRegularExpression("[0-9]\\d{0,8}"));


    list = new QListWidget(this);
    memo = new QTextEdit(this);
    memo->setReadOnly(true);

    //Кнопки
    add_button = new QPushButton(this);
    add_button->setText("Добавить");
    open_file_button = new QPushButton(this);
    open_file_button->setText("Открыть файл");
    save_file_button = new QPushButton(this);
    save_file_button->setText("Сохранить файл");
    sort_button = new QPushButton(this);
    sort_button->setText("Сортировать");
    delete_button = new QPushButton(this);
    delete_button->setText("Удалить");
    edit_button = new QPushButton(this);
    edit_button->setText("Изменить");

    //Строки ввода
    min_price_line = new QLineEdit(this);
    min_price_line->setPlaceholderText("мин. цена");
    min_price_line->setValidator(intValidator);

    max_price_line = new QLineEdit(this);
    max_price_line->setPlaceholderText("макс. цена");
    max_price_line->setValidator(intValidator);

    search_line = new QLineEdit(this);
    search_line->setPlaceholderText("Поиск товара");

    name_line = new QLineEdit(this);
    name_line->setPlaceholderText("Наименование");

    code_line = new QLineEdit(this);
    code_line->setPlaceholderText("Код товара");
    code_line->setValidator(intValidator);

    group_line = new QLineEdit(this);
    group_line->setPlaceholderText("Группа товаров");

    model_line = new QLineEdit(this);
    model_line->setPlaceholderText("Модель товара");

    price_line = new QLineEdit(this);
    price_line->setPlaceholderText("Цена");
    price_line->setValidator(intValidator);

    count_line = new QLineEdit(this);
    count_line->setPlaceholderText("Количесвто");
    count_line->setValidator(intValidator);


    //Переходы
    setTabOrder(price_line, count_line);
    setTabOrder(model_line, price_line);
    setTabOrder(group_line, model_line);
    setTabOrder(code_line, group_line);
    setTabOrder(name_line, code_line);


    //Расположение
    layout->addWidget(search_line, 0, 0, 1, 4);
    layout->addWidget(min_price_line, 1, 0, 1, 2);

    layout->addWidget(max_price_line, 1, 2, 1, 2);
    layout->addWidget(list, 2, 0, 17, 4);
    layout->addWidget(sort_button, 19, 0, 1, 4);
    layout->addWidget(memo, 2, 4, 17, 6);
    layout->addWidget(delete_button, 19, 4, 1, 3);
    layout->addWidget(edit_button, 19, 7, 1, 3);
    layout->addWidget(name_line, 2, 10, 1, 3);
    layout->addWidget(code_line, 3, 10, 1, 3);
    layout->addWidget(group_line, 4, 10, 1, 3);
    layout->addWidget(model_line, 5, 10, 1, 3);
    layout->addWidget(price_line, 6, 10, 1, 3);
    layout->addWidget(count_line, 7, 10, 1, 3);
    layout->addWidget(add_button, 8, 10, 1, 3);
    layout->addWidget(open_file_button, 17, 10, 1, 3);
    layout->addWidget(save_file_button, 18, 10, 1, 3);


    //Соединения
    connect(add_button, &QPushButton::clicked, this, &MainWindow::AddButtonClick);
    connect(list, &QListWidget::clicked, this, &MainWindow::DisplayInformation);
    connect(sort_button, &QPushButton::clicked, this, &MainWindow::SortByName);
    connect(delete_button, &QPushButton::clicked, this, &MainWindow::DeleteButtonClick);
    connect(edit_button, &QPushButton::clicked, this, &MainWindow::EditButtonClick);
    connect(save_file_button, &QPushButton::clicked, this, &MainWindow::SaveFileButtonClick);
    connect(open_file_button, &QPushButton::clicked, this, &MainWindow::OpenFileButtonClick);

    connect(search_line, &QLineEdit::textChanged, this, &MainWindow::FilterByName);
    connect(min_price_line, &QLineEdit::textChanged, this, &MainWindow::FilterByPrice);
    connect(max_price_line, &QLineEdit::textChanged, this, &MainWindow::FilterByPrice);
}

MainWindow::~MainWindow()
{
    delete layout;
    delete list;
    delete edit_dialog;

    for (int i = 0; i < goods.size(); i++) {
        delete goods[i];
    }

    delete group_label;
    delete code_label;
    delete name_label;
    delete model_label;
    delete price_label;
    delete count_label;

    delete search_line;
    delete group_line;
    delete code_line;
    delete name_line;
    delete model_line;
    delete price_line;
    delete count_line;
    delete min_price_line;
    delete max_price_line;
    delete memo;

    delete add_button;
    delete exit_button;
    delete sort_button;
    delete save_button;
    delete save_file_button;
    delete open_file_button;
    delete search_button;
    delete delete_button;
    delete edit_button;

}

void MainWindow::UpdateList()
{
    list->clear();
    for (int i = 0; i < goods.size(); i++) {
        list->addItem(goods[i]->getName());
    }
}

void MainWindow::AddButtonClick()
{
    if (CheckAddLinesCorrect()) {
        int price = price_line->text().toInt();
        QString group = group_line->text();
        QString name = name_line->text();
        int code = code_line->text().toInt();
        QString model = model_line->text();
        int count = count_line->text().toInt();
        Statement *good = new Statement(count, price, model, name, code, group);
        goods.push_back(good);
        UpdateList();
        ClearAddLines();
    }
    else {
        QMessageBox::critical(nullptr, "Неверные данные", "Неверные данные");
    }
}



void MainWindow::DisplayInformation()
{
    int number = list->currentIndex().row();
    memo->setText("Наименование: " + goods[number]->getName() + "\n"
                  "Код товара: " + QString::number(goods[number]->getCode()) + "\n"
                  "Группа товара: " + goods[number]->getGroup() + "\n"
                  "Модель товара: " + goods[number]->getModel() + "\n"
                  "Цена товара: " + QString::number(goods[number]->getPrice()) + "\n"
                  "Количество: " + QString::number(goods[number]->getCount()) + "\n");
}

void MainWindow::SortByName()
{
    std::sort(goods.begin(), goods.end(), lessThan);
    UpdateList();
}

void MainWindow::FilterByName()
{
    for (int i = 0; i < list->count(); ++i) {
        QListWidgetItem* item = list->item(i);
        if (item) {
            QString itemText = item->text();
            if (itemText.contains(search_line->text(), Qt::CaseInsensitive)) {
                item->setHidden(false);
            } else {
                item->setHidden(true);
            }
        }
    }
}

void MainWindow::FilterByPrice()
{
    int min = 0;
    int max = 1000000000;
    if (min_price_line->text() != "") {
        min = min_price_line->text().toInt();
    }
    if (max_price_line->text() != "") {
        max = max_price_line->text().toInt();
    }

    for (int i = 0; i < goods.size(); ++i) {
        QListWidgetItem* item = list->item(i);
        if (item) {
            int price = goods[i]->getPrice();
            if (price <= max && price >= min) {
                item->setHidden(false);
            } else {
                item->setHidden(true);
            }
        }
    }

}

void MainWindow::ClearAddLines()
{
    group_line->clear();
    code_line->clear();
    name_line->clear();
    price_line->clear();
    count_line->clear();
    model_line->clear();
}

bool MainWindow::CheckAddLinesCorrect()
{
    bool fl = true;
    fl = fl && CheckStrCorrect(group_line->text());
    fl = fl && CheckStrCorrect(code_line->text());
    fl = fl && CheckStrCorrect(name_line->text());
    fl = fl && CheckStrCorrect(price_line->text());
    fl = fl && CheckStrCorrect(count_line->text());
    fl = fl && CheckStrCorrect(model_line->text());

    return fl;
}

void MainWindow::DeleteButtonClick()
{
    int number = list->currentIndex().row();
    if (list->currentIndex().row() != -1) {
        delete goods[number];
        goods.erase(goods.begin() + number);
        memo->clear();
        UpdateList();
    }
}

void MainWindow::EditButtonClick()
{
    int number = list->currentIndex().row();
    if (number != -1) {
        edit_dialog = new DialogEdit(goods[number],number, this);
        connect(edit_dialog, &DialogEdit::EditSignal, this, &MainWindow::HandleEdit);
        edit_dialog->exec();
    }
}

void MainWindow::SaveFileButtonClick()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "*");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            QDataStream out(&file);
            for (const auto& obj : goods) {
                out << obj->getCount() << obj->getPrice() << obj->getModel() << obj->getName() << obj->getCode() << obj->getGroup();
            }
            file.close();
        }
    }
}

void MainWindow::OpenFileButtonClick()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл", "", "*");

    int count;
    int price;
    QString model;
    QString name;
    int code;
    QString group;

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        goods.clear();
        QDataStream in(&file);
        if (file.open(QIODevice::ReadOnly)) {
            while (!in.atEnd()) {
                in >> count >> price >> model >> name >> code >> group;
                Statement* obj = new Statement(count, price, model, name, code, group);
                goods.push_back(obj);
            }
            file.close();
        }
    }
    UpdateList();
}

void MainWindow::HandleEdit(int count, int price, QString model, QString name, int code, QString group, int number)
{
    goods[number]->setCount(count);
    goods[number]->setPrice(price);
    goods[number]->setModel(model);
    goods[number]->setName(name);
    goods[number]->setCode(code);
    goods[number]->setGroup(group);
    UpdateList();
    memo->setText("Наименование: " + goods[number]->getName() + "\n"
                  "Код товара: " + QString::number(goods[number]->getCode()) + "\n"
                  "Группа товара: " + goods[number]->getGroup() + "\n"
                  "Модель товара: " + goods[number]->getModel() + "\n"
                  "Цена товара: " + QString::number(goods[number]->getPrice()) + "\n"
                  "Количество: " + QString::number(goods[number]->getCount()) + "\n");

}





