#include "widget.h"

widget::widget(QWidget *parent) : QWidget(parent)
{
    name = new QLabel("Ф.И.О", this);
    mat = new QLabel("Математика", this);
    phys = new QLabel("Физика", this);
    rus = new QLabel("Русский", this);
    atestat = new QLabel("Аттестат", this);
    matText = new QLabel("100", this);
    physText = new QLabel("100", this);
    rusText = new QLabel("100", this);
    atestatText = new QLabel("100", this);
    nameBox = new QComboBox(this);
    deleteButton = new QPushButton("Удалить", this);
    resizeButton = new QPushButton("Изменить", this);
    addButton = new QPushButton("Добавить", this);
    sortButton = new QPushButton("Сортировка", this);
    searchButton = new QPushButton("Найти", this);
    table = new QTableWidget(this);

    QString style = "background-color: white; color: black;";

    matText->setStyleSheet(style);
    matText->setAlignment(Qt::AlignCenter);
    atestatText->setStyleSheet(style);
    atestatText->setAlignment(Qt::AlignCenter);
    physText->setStyleSheet(style);
    physText->setAlignment(Qt::AlignCenter);
    rusText->setStyleSheet(style);
    rusText->setAlignment(Qt::AlignCenter);
    nameBox->setStyleSheet(style);

    table->setColumnCount(2);
    QStringList headerLables;

    headerLables << "Фамилия Имя Отчество" << "Средний балл";

    table->setHorizontalHeaderLabels(headerLables);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setStyleSheet("QTableWidget { "
                              "background-color: white;"
                              "color : black;"
                              "}");

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &widget::resizeTimer);
    timer->setInterval(10);

    connect(nameBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
    if (index >= 0 && index < stud.size()) { // Проверяем, что индекс в пределах списка студентов
        matText->setText(QString::number(stud[index].mat()));
        physText->setText(QString::number(stud[index].phys()));
        rusText->setText(QString::number(stud[index].rus()));
        atestatText->setText(QString::number(stud[index].at()));
    }
});

    connect(addButton, &QPushButton::clicked, this, &widget::showInputDialog);
    connect(deleteButton, &QPushButton::clicked, this, &widget::delet);
    connect(resizeButton, &QPushButton::clicked, this, &widget::resize);
    connect(sortButton,  &QPushButton::clicked, this, &widget::butsort);
    connect(searchButton,  &QPushButton::clicked, this, &widget::search);
}

void widget::showEvent(QShowEvent *event){
    QWidget::showEvent(event);

    int width = this->width();
    int height = this->height();

    name->setGeometry(width / 20, height / 10, width / 9, height / 20);
    mat->setGeometry(width / 20, height * 2 / 10, width / 9, height / 20);
    phys->setGeometry(width / 20, height * 3 / 10, width / 9, height / 20);
    rus->setGeometry(width / 20, height * 4 / 10, width / 9, height / 20);
    atestat->setGeometry(width / 20, height * 5 / 10, width / 9, height / 20);
    deleteButton->setGeometry(width / 20, height * 7 / 10, width / 9, height / 20);
    resizeButton->setGeometry(width / 20, height * 8 / 10, width / 9, height / 20);
    nameBox->setGeometry(width / 7, height / 10, width / 3, height / 20);
    matText->setGeometry(width / 5, height *2 / 10, width / 10, height / 20);
    physText->setGeometry(width / 5, height *3 / 10, width / 10, height / 20);
    rusText->setGeometry(width / 5, height *4 / 10, width / 10, height / 20);
    atestatText->setGeometry(width / 5, height *5 / 10, width / 10, height / 20);
    table->setGeometry(width / 2, height / 10, width / 2, height / 2);
    table->setColumnWidth(0, table->width() *3/5);
    table->setColumnWidth(1, table->width() *2/5);
    addButton->setGeometry(width / 2, height * 7 / 10, width / 9, height / 20);
    sortButton->setGeometry(width / 2, height * 8 / 10, width / 9, height / 20);
    searchButton->setGeometry(width / 2, height * 9 / 10, width / 9, height / 20);
}

void widget::resizeTimer(){
    timer->stop();
    int width = this->width();
    int height = this->height();

    name->setGeometry(width / 20, height / 10, width / 9, height / 20);
    mat->setGeometry(width / 20, height * 2 / 10, width / 9, height / 20);
    phys->setGeometry(width / 20, height * 3 / 10, width / 9, height / 20);
    rus->setGeometry(width / 20, height * 4 / 10, width / 9, height / 20);
    atestat->setGeometry(width / 20, height * 5 / 10, width / 9, height / 20);
    deleteButton->setGeometry(width / 20, height * 7 / 10, width / 9, height / 20);
    resizeButton->setGeometry(width / 20, height * 8 / 10, width / 9, height / 20);
    nameBox->setGeometry(width / 7, height / 10, width / 3, height / 20);
    matText->setGeometry(width / 5, height *2 / 10, width / 10, height / 20);
    physText->setGeometry(width / 5, height *3 / 10, width / 10, height / 20);
    rusText->setGeometry(width / 5, height *4 / 10, width / 10, height / 20);
    atestatText->setGeometry(width / 5, height *5 / 10, width / 10, height / 20);
    table->setGeometry(width / 2, height / 10, width / 2, height / 2);
    table->setColumnWidth(0, table->width() *3/5);
    table->setColumnWidth(1, table->width() *2/5);
    addButton->setGeometry(width / 2, height * 7 / 10, width / 9, height / 20);
    sortButton->setGeometry(width / 2, height * 8 / 10, width / 9, height / 20);
    searchButton->setGeometry(width / 2, height * 9 / 10, width / 9, height / 20);
}

void widget::setFileName(QString name){
    filename = name;
}

void widget::resizeEvent(QResizeEvent *event)
{
    timer->start();
    Q_UNUSED(event)
}

void widget::parce(){

    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug() << "Не удалось открыть файл";
    }

    QTextStream stream(&file);

    QString parce = stream.readAll();

    qDebug() << parce;
    int position = 0;

    while (position < parce.length()){
    student buffer;

    QString buf;

    while (parce[position] != ' '){
        buf += parce[position];
        position++;
    }

    position++;
    buf += " ";

    while (parce[position] != ' '){
        buf += parce[position];
        position++;
    }

    position++;
    buf += " ";

    while (parce[position] != ' '){
        buf += parce[position];
        position++;
    }
    position++;
    buffer.setFio(buf);

    buf.clear();

    int bal = 0;

    while (parce[position] != ' '){
        bal *= 10;
        bal += parce[position].digitValue();
        position++;
    }

    position++;
    buffer.setMat(bal);
    bal = 0;

    while (parce[position] != ' '){
        bal *= 10;
        bal += parce[position].digitValue();
        position++;
    }

    position++;
    buffer.setPhys(bal);
    bal = 0;

    while (parce[position] != ' '){
        bal *= 10;
        bal += parce[position].digitValue();
        position++;
    }
    position++;
    buffer.setRus(bal);
    bal = 0;

    while (parce[position] != '\n'){
        bal *= 10;
        bal += parce[position].digitValue();
        position++;
    }
    position++;
    buffer.setAt(bal);

    stud.push_back(buffer);
    }
}

void widget::addComboBox(QString fio){
    nameBox->addItem(fio);
}

void widget::studTable(){
    table->setRowCount(stud.size());
    for (int i = 0; i < stud.size(); i++){
    QTableWidgetItem *nameItem = new QTableWidgetItem(stud[i].fio());
    QTableWidgetItem *average = new QTableWidgetItem(QString::number(stud[i].avarage()));
    nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
    average->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
    average->setTextAlignment(Qt::AlignCenter);
    table->setItem(i, 0, nameItem);
    table->setItem(i, 1, average);

    }
}

void widget::showInputDialog(){
    dialog dia(this);

    if (dia.exec() == QDialog::Accepted){
    student buf;
    buf.setFio(dia.getFio());
    buf.setMat(dia.getMath());
    buf.setPhys(dia.getPhys());
    buf.setRus(dia.getRus());
    buf.setAt(dia.getAtestat());
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
    }
    file.seek(file.size());
    QString New;
    New += buf.fio();
    New += " ";
    New += QString::number(buf.mat());
    New += " ";
    New += QString::number(buf.phys());
    New += " ";
    New += QString::number(buf.rus());
    New += " ";
    New += QString::number(buf.at());
    New += "\n";
    QTextStream out(&file);
    out << New;
    file.close();
    stud.clear();
    parce();
    addComboBox(stud[stud.size()-1].fio());
    studTable();
    }
}

void widget::delet(){
    int k = nameBox->currentIndex();

    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
    qDebug() << "Не удалось открыть файл";
    }

    QTextStream in(&file);

    int numLine = -1;
    qint64 currentPos = in.pos();

    while (true){
    currentPos = in.pos();
    in.readLine();
    numLine++;
    if (numLine == k){
        break;
    }
    }
    file.seek(in.pos());
    QByteArray buffer = file.readAll();
    qDebug() << QString::fromUtf8(buffer);

    // Записываем в файл сначала строку k, а затем остаток буфера
    file.seek(currentPos);
    file.write(buffer);
    file.resize(file.pos()); // Обрезаем файл до текущей позиции
    file.close();

    stud.clear();
    parce();
    nameBox->clear();
    for (int i = 0; i < stud.size(); i++){
    addComboBox(stud[i].fio());
    }
    studTable();
}

void widget::resize(){
    int k = nameBox->currentIndex();

    dialog dia(this);

    dia.begin(stud[k].fio(), stud[k].mat(), stud[k].phys(), stud[k].rus(), stud[k].at());

    if (dia.exec() == QDialog::Accepted){
    student buf;
    buf.setFio(dia.getFio());
    buf.setMat(dia.getMath());
    buf.setPhys(dia.getPhys());
    buf.setRus(dia.getRus());
    buf.setAt(dia.getAtestat());
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
    }
    QString New;
    New += buf.fio();
    New += " ";
    New += QString::number(buf.mat());
    New += " ";
    New += QString::number(buf.phys());
    New += " ";
    New += QString::number(buf.rus());
    New += " ";
    New += QString::number(buf.at());
    New += "\n";
    QTextStream in(&file);

    int numLine = -1;
    qint64 currentPos = in.pos();

    while (true){
        currentPos = in.pos();
        in.readLine();
        numLine++;
        if (numLine == k){
            break;
        }
    }
    file.seek(in.pos());
    QByteArray buffer = file.readAll();
    qDebug() << QString::fromUtf8(buffer);

    // Записываем в файл сначала строку k, а затем остаток буфера
    file.seek(currentPos);
    file.write(New.toUtf8());
    file.write(buffer);
    file.resize(file.pos()); // Обрезаем файл до текущей позиции
    file.close();

    stud.clear();
    parce();
    nameBox->clear();
    for (int i = 0; i < stud.size(); i++){
        addComboBox(stud[i].fio());
    }
    studTable();
    }
}

void widget::sort(int* a, int* b, int left, int right){
    int l = left;
    int r = right;
    int pos = a[(l+r)/2];
    while (l < r){
    while (a[l] < pos){
        l++;
    }
    while (a[r] > pos){
        r--;
    }
    if (l <= r){
        int buf = a[l];
        a[l] = a[r];
        a[r] = buf;
        buf = b[l];
        b[l] = b[r];
        b[r] = buf;
        r--;
        l++;
    }
    }

    if (r > left) {
    widget::sort(a, b, left, r);
    }
    if (l < right){
    widget::sort(a, b, l, right);
    }
}

void widget::butsort(){

    int *a = new int[stud.size()];
    int *b = new int[stud.size()];

    for (int i = 0; i < stud.size(); i++){
    a[i] = stud[i].avarage();
    b[i] = i;
    }

    sort(a, b, 0, stud.size()-1);

    QVector<student> buffer;

    for (int i = 0; i < stud.size(); i++){
        buffer.push_back(stud[b[i]]);
    }

    for (int i = 0; i < stud.size(); i++){
        stud[i] = buffer[i];
    }

    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        // Файл успешно открыт для записи и содержимое очищено
    } else {
        // Обработка ошибки открытия файла
    }
    file.close();

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
    }
    for (int i = 0; i < stud.size(); i++){
    file.seek(file.size());
    QString New;
    New += stud[i].fio();
    New += " ";
    New += QString::number(stud[i].mat());
    New += " ";
    New += QString::number(stud[i].phys());
    New += " ";
    New += QString::number(stud[i].rus());
    New += " ";
    New += QString::number(stud[i].at());
    New += "\n";
    QTextStream out(&file);
    out << New;
    }
    file.close();
    stud.clear();
    parce();
    nameBox->clear();
    for (int i = 0; i < stud.size(); i++){
    addComboBox(stud[i].fio());
    }
    studTable();
}

void widget::search(){

    // Отображение диалогового окна и получение ввода от пользователя
    QString input = QInputDialog::getText(this, tr("Введите данные"), tr("Пожалуйста, введите фамилию, имя и отчество:"));

    while (true){
    if (input[input.size()-1] == ' '){
        input.chop(1);
    }
    else {
        break;
    }
    }

    int pos = 0;
    bool tr = false;

    for (int i = 0; i < stud.size(); i++){
    if (input == stud[i].fio()){
        pos = i;
        tr = true;
        break;
    }
    }
    if (tr){
    nameBox->setCurrentIndex(pos);
    }
    else {
    QString errorMessage = "Нет такого учащегося";
    QMessageBox::critical(this, "Ошибка", errorMessage);
    }
}
