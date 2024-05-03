#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setMinimumSize(1600, 500);
    ui->setupUi(this);

    QFile file("/home/kirill/Qt/lb2/date.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug() << "Не удалось открыть файл";
    }

    QTextStream stream(&file);

    parce(stream, dat);

    n = dat.size();

    /*for (int i = 0; i < n; i++){
        qDebug() << dat[i].day << " " << dat[i].month << " " << dat[i].year << "\n";
    }*/

    tableWidget.setColumnCount(6);
    tableWidget.setRowCount(n);

    QStringList headerLables;

    headerLables << "" <<  "День" << "Месяц"
                 << "Год" << "След. день" << "Кол-во дней до след.";

    tableWidget.setHorizontalHeaderLabels(headerLables);
    tableWidget.setParent(this);

    myTable(tableWidget, dat, 0, dat.size());

    tableWidget.setGeometry(10, 10, this->width()*4/5, this->height());
    tableWidget.setColumnWidth(0, tableWidget.width() * 0.01);
    tableWidget.setColumnWidth(1, tableWidget.width() * 0.19);
    tableWidget.setColumnWidth(2, tableWidget.width() * 0.19);
    tableWidget.setColumnWidth(3, tableWidget.width() * 0.19);
    tableWidget.setColumnWidth(4, tableWidget.width() * 0.19);
    tableWidget.setColumnWidth(5, tableWidget.width() * 0.19);
    tableWidget.setStyleSheet("QTableWidget { "
                              "background-color: white;"
                              "color : black;"
                              "}");
    tableWidget.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::resizeTimer);
    timer->setInterval(10);
    connection = connect(&tableWidget, &QTableWidget::itemChanged, this, [=](QTableWidgetItem *item) {
        chang_slot(item); // Передача аргументов в слот
    });

    previousButton = new QPushButton("Прошлый день", this);
    leapButton = new QPushButton("IsLeap", this);
    weekButton = new QPushButton("Номер недели", this);
    bithdayButton = new QPushButton("Дни до др",this);
    durationButton = new QPushButton("Дни до даты", this);
    addButton = new QPushButton("Добавить", this);
    deleteButton = new QPushButton("Удалить", this);
    openButton = new QPushButton("Открыть файлы", this);

    dateEdit1.setParent(this);
    dateEdit1.setFocusPolicy(Qt::StrongFocus);
    QObject::connect(&dateEdit1, &QLineEdit::editingFinished, [&]() {
        dateEdit1.clearFocus();
        QString text = dateEdit1.text();
        bool ok = isDate(text, bithday, dateEdit1);
        if (bithday.year > 2024)
            {
            ok = false;
            dateEdit1.clear();
            }

        if (!ok){
            QMessageBox messageBox;
            messageBox.setText("Некоректная дата");
            messageBox.exec();
        }
    });

    dateEdit2.setParent(this);
    dateEdit2.setFocusPolicy(Qt::StrongFocus);
    QObject::connect(&dateEdit2, &QLineEdit::editingFinished, [&]() {
        dateEdit2.clearFocus();
        QString text = dateEdit2.text();
        bool ok = isDate(text, usrdate, dateEdit2);
        if (!ok){
            QMessageBox messageBox;
            messageBox.setText("Некоректная дата");
            messageBox.exec();
        }
    });

    dr.setText("Др:");
    usrDay.setText("Day:");

    dr.setParent(this);
    usrDay.setParent(this);

    previousButton->setGeometry(this->width()*9/10, 0, this->width()/10, this->height()/20);
    leapButton->setGeometry(this->width()*9/10, this->height()/15, this->width()/10, this->height()/20);
    weekButton->setGeometry(this->width()*9/10, this->height()*2/15, this->width()/10, this->height()/20);
    bithdayButton->setGeometry(this->width()*9/10, this->height()*3/15, this->width()/10, this->height()/20);
    durationButton->setGeometry(this->width()*9/10, this->height()*5/15, this->width()/10, this->height()/20);
    dateEdit1.setGeometry(this->width()*9/10 + this->width()/30, this->height()*4/15, this->width()/15, this->height()/20);
    dateEdit2.setGeometry(this->width()*9/10 + this->width()/30, this->height()*6/15, this->width()/15, this->height()/20);
    dr.setGeometry(this->width()*9/10, this->height()*4/15, this->width()/30, this->height()/20);
    usrDay.setGeometry(this->width()*9/10, this->height()*6/15, this->width()/30, this->height()/20);
    addButton->setGeometry(this->width()*9/10, this->height()*7/15, this->width()/10, this->height()/20);
    deleteButton->setGeometry(this->width()*9/10, this->height()*8/15, this->width()/10, this->height()/20);
    openButton->setGeometry(this->width()*9/10, this->height()*9/15, this->width()/10, this->height()/20);

    connect(previousButton, &QPushButton::clicked, this, &MainWindow::previousCliced);
    connect(leapButton, &QPushButton::clicked, this, &MainWindow::leapClick);
    connect(weekButton, &QPushButton::clicked, this, &MainWindow::weekClick);
    connect(bithdayButton, &QPushButton::clicked, this, &MainWindow::bithClick);
    connect(durationButton, &QPushButton::clicked, this, &MainWindow::durationclick);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addClick);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteClick);
    connect(openButton, &QPushButton::clicked, this, &MainWindow::openClick);

}

    void MainWindow::resizeTimer()
{
    timer->stop();
    tableWidget.setGeometry(10, 10, this->width()*9/10-20, this->height());
    tableWidget.setColumnWidth(0, tableWidget.width() * 0.01);
    tableWidget.setColumnWidth(1, tableWidget.width() * 0.19);
    tableWidget.setColumnWidth(2, tableWidget.width() * 0.19);
    tableWidget.setColumnWidth(3, tableWidget.width() * 0.19);
    tableWidget.setColumnWidth(4, tableWidget.width() * 0.21);
    tableWidget.setColumnWidth(5, tableWidget.width() * 0.19);
    previousButton->setGeometry(this->width()*9/10, 0, this->width()/10, this->height()/20);
    leapButton->setGeometry(this->width()*9/10, this->height()/15, this->width()/10, this->height()/20);
    weekButton->setGeometry(this->width()*9/10, this->height()*2/15, this->width()/10, this->height()/20);
    bithdayButton->setGeometry(this->width()*9/10, this->height()*3/15, this->width()/10, this->height()/20);
    durationButton->setGeometry(this->width()*9/10, this->height()*5/15, this->width()/10, this->height()/20);
    dateEdit1.setGeometry(this->width()*9/10 + this->width()/30, this->height()*4/15, this->width()/15, this->height()/20);
    dateEdit2.setGeometry(this->width()*9/10 + this->width()/30, this->height()*6/15, this->width()/15, this->height()/20);
    dr.setGeometry(this->width()*9/10, this->height()*4/15, this->width()/30, this->height()/20);
    usrDay.setGeometry(this->width()*9/10, this->height()*6/15, this->width()/30, this->height()/20);
    addButton->setGeometry(this->width()*9/10, this->height()*7/15, this->width()/10, this->height()/20);
    deleteButton->setGeometry(this->width()*9/10, this->height()*8/15, this->width()/10, this->height()/20);
    openButton->setGeometry(this->width()*9/10, this->height()*9/15, this->width()/10, this->height()/20);

}

void MainWindow::parce(QTextStream& stream,  QVector<Date>& dat){
    QString parce = stream.readAll();

    qDebug() << parce;

    int position = 0;
    int par = 0;
    while(true)
    {
        Date buf;
        while(true){
            if (parce[position]!= '.' && parce[position] != '\n'){
                par *= 10;
                par += parce[position].digitValue();
                position++;
            }
            else {
                position++;
                break;
            }
        }
        buf.setDay(par);
        par = 0;
        while(true){
            if (parce[position]!= '.' && parce[position] != '\n'){
                par *= 10;
                par += parce[position].digitValue();
                position++;
            }
            else {
                position++;
                break;
            }
        }
        buf.setMonth(par);
        par = 0;
        while(true){
            if (parce[position]!= '.' && parce[position] != '\n'){
                par *= 10;
                par += parce[position].digitValue();
                position++;
            }
            else {
                position++;
                break;
            }
        }
        buf.setYear(par);
        par = 0;
        dat.push_back(buf);
        if(position == parce.size()){
            break;
        }
    }
}

void MainWindow::addClick(){
    QFile file("/home/kirill/Qt/lb2/date.txt");

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
    }
    file.seek(file.size());

    QDate curren(1,1,1);

    QString cur = curren.toString("dd.MM.yyyy");

    cur += '\n';

    qDebug() << cur;

    QTextStream out(&file);
    out << cur;
    file.close();

    QFile File("/home/kirill/Qt/lb2/date.txt");

    if (!File.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
    }

    QTextStream str(&File);
    disconnect(connection);
    dat.clear();
    parce(str, dat);
    tableWidget.setRowCount(dat.size());
    for (int i = 0; i < dat.size(); i++){
        qDebug() << dat[i].day << " " << dat[i].month << " " << dat[i].year << "\n";
    }
    radio = true;
    myTable(tableWidget, dat, 0, dat.size());
    connection = connect(&tableWidget, &QTableWidget::itemChanged, this, [=](QTableWidgetItem *item) {
        chang_slot(item); // Передача аргументов в слот
    });
    File.close();
}

void MainWindow::deleteClick(){
    int k = 0;
    for (int i = 0; i < tableWidget.rowCount(); i++){
        QRadioButton *radioButton = qobject_cast<QRadioButton*>(tableWidget.cellWidget(i, 0));
        if (radioButton && radioButton->isChecked()) {
            qDebug() << "Выбрана строка:" << i;
            k = i;
        }
    }
    QFile file("/home/kirill/Qt/lb2/date.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug() << "Не удалось открыть файл";
    }

    QTextStream in(&file);

    int numLine = -1;
    QString line;
    qint64 linePos = -1;
    qint64 linePosEnd = -1;

    while(true){
        QString thisLine = in.readLine();
        numLine++;
        qDebug() << "numLine: " << numLine;
        if (numLine == k){
            line = thisLine;
            linePosEnd = in.pos();
            linePos = in.pos() - thisLine.length()-1;
            qDebug() << "line : " << line << " lintPos: " << linePos;
            break;
        }
    }
    QByteArray buffer;
    file.seek(linePosEnd);
    buffer = file.readAll();
    file.seek(linePos);
    file.write(buffer);
    int charCount = QString::fromUtf8(buffer).length();
    linePos += charCount;
    file.seek(linePos);
    file.resize(file.pos());

    file.close();

    QFile File("/home/kirill/Qt/lb2/date.txt");

    if (!File.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
    }

    QTextStream str(&File);
    disconnect(connection);
    dat.clear();
    parce(str, dat);
    tableWidget.setRowCount(dat.size());
    for (int i = 0; i < dat.size(); i++){
        qDebug() << dat[i].day << " " << dat[i].month << " " << dat[i].year << "\n";
    }
    radio = true;
    myTable(tableWidget, dat, 0, dat.size());
    connection = connect(&tableWidget, &QTableWidget::itemChanged, this, [=](QTableWidgetItem *item) {
        chang_slot(item); // Передача аргументов в слот
    });
    File.close();

}

void MainWindow::myTable(QTableWidget &tableWidget, QVector<Date> &dat, int x0, int x1){
    for (int i = x0; i < x1; i++){
        QDate currentDate(dat[i].year, dat[i].month, dat[i].day);

        QRadioButton *radioButton = new QRadioButton();
        if (radio){
            radioButton->setChecked(true);
            radio = false;
        }

        radioButton->setStyleSheet(
            "QRadioButton::checked { color: red; }"
            );

        QTableWidgetItem *dayItem = new QTableWidgetItem(QString("%1").arg(currentDate.day(), 2, 10, QChar('0')));
        dayItem->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem *monthItem = new QTableWidgetItem(QString("%1").arg(currentDate.month(), 2, 10, QChar('0')));
        monthItem->setTextAlignment(Qt::AlignCenter);
        QTableWidgetItem *yearItem;
        if (currentDate.year() < 9999)
        {
            yearItem = new QTableWidgetItem(QString("%1").arg(currentDate.year(), 4, 10, QChar('0')));
        }
        else
        {
            yearItem = new QTableWidgetItem(QString("%1").arg(currentDate.year()));
        }
        yearItem->setTextAlignment(Qt::AlignCenter);
        Date day1;
        day1 = dat[i].NextDay();
        currentDate.setDate(day1.year, day1.month, day1.day);
        QString cur;
        cur += QString("%1").arg(currentDate.day(), 2, 10, QChar('0'));
        cur += '.';
        cur += QString("%1").arg(currentDate.month(), 2, 10, QChar('0'));
        cur += '.';
        if (currentDate.year() < 9999)
        {
            cur += QString("%1").arg(currentDate.year(), 4, 10, QChar('0'));
        }
        else
        {
            cur += QString("%1").arg(currentDate.year());
        }
        QTableWidgetItem *nextDay = new QTableWidgetItem(cur);
        nextDay->setFlags(nextDay->flags() & ~Qt::ItemIsEditable);
        nextDay->setTextAlignment(Qt::AlignCenter);
        int dayTo;
        if (i < dat.size()-1){
            dayTo = dat[i].Duration(dat[i+1]);
        }
        else
        {
            dayTo = dat[i].Duration(dat[0]);
        }
        cur = QString::number(dayTo);
        currentDate.setDate(day1.day, day1.month, day1.year);
        QTableWidgetItem *duration = new QTableWidgetItem(cur);
        duration->setFlags(duration->flags() & ~Qt::ItemIsEditable);
        duration->setTextAlignment(Qt::AlignCenter);

        tableWidget.setCellWidget(i, 0, radioButton);
        tableWidget.setItem(i, 1, dayItem);
        tableWidget.setItem(i, 2, monthItem);
        tableWidget.setItem(i, 3, yearItem);
        tableWidget.setItem(i, 4, nextDay);
        tableWidget.setItem(i, 5, duration);
    }
}

void MainWindow::chang_slot(QTableWidgetItem *item)
{
    int row = item->row();
    int column = item->column();
    QString value = item->text();
    bool conversion;
    int intValue = value.toInt(&conversion);
    if (conversion){
    qDebug() << "Изменение в ячейке [" << row << ", " << column << "]. Новое значение: " << value;
    QDate current(dat[row].year, dat[row].month, dat[row].day);
    switch (column){
    case 1:
            if (intValue <= current.daysInMonth() && intValue > 0){
        dat[row].setDay(intValue);
            }
        break;
    case 2:
        if (intValue < 13 && intValue >= 0){
        dat[row].setMonth(intValue);
        if (!(dat[row].day < current.daysInMonth())){
            dat[row].setDay(1);
        }
        }

        break;
    case 3:
        if (intValue > 0){
        dat[row].setYear(intValue);
        }
        break;
    }
    disconnect(connection);
    myTable(tableWidget, dat, row, row+1);
    fileMod(row);
    qDebug() << row;
    connection = connect(&tableWidget, &QTableWidget::itemChanged, this, [=](QTableWidgetItem *item) {
        chang_slot(item); // Передача аргументов в слот
    });
    for (int i = 0; i < n; i++){
        qDebug() << dat[i].day << " " << dat[i].month << " " << dat[i].year << "\n";
    }
    }
    else
    {
    disconnect(connection);
    myTable(tableWidget, dat, row, row+1);
    connection = connect(&tableWidget, &QTableWidget::itemChanged, this, [=](QTableWidgetItem *item) {
        chang_slot(item); // Передача аргументов в слот
    });
    }
}

void MainWindow::fileMod(int position){
    QFile file("/home/kirill/Qt/lb2/date.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
    qDebug() << "Не удалось открыть файл";
    }

    QTextStream in(&file);

    int numLine = -1;
    QString line;
    qint64 linePos = -1;
    qint64 linePosEnd = -1;

    while(true){
    QString thisLine = in.readLine();
    numLine++;
    qDebug() << "numLine: " << numLine;
    if (numLine == position){
        line = thisLine;
        linePosEnd = in.pos();
        linePos = in.pos() - thisLine.length()-1;
        qDebug() << "line : " << line << " lintPos: " << linePos;
        break;
    }
    }

    QDate currentDate(dat[position].year, dat[position].month, dat[position].day);
    QString cur;
    cur += QString("%1").arg(currentDate.day(), 2, 10, QChar('0'));
    cur += '.';
    cur += QString("%1").arg(currentDate.month(), 2, 10, QChar('0'));
    cur += '.';
    if (currentDate.year() < 9999)
    {
    cur += QString("%1").arg(currentDate.year(), 4, 10, QChar('0'));
    }
    else
    {
    cur += QString("%1").arg(currentDate.year());
    }
    qDebug() << "cur:" <<  cur;
    QByteArray buffer;
    if (linePos != -1){
        if (file.seek(linePosEnd)){
            buffer = file.readAll();
        qDebug() << "buffer" << buffer;
        }
        else
        {
        qDebug() << "Не удалось переместить указатель для буфера в файле";
        }
        if (file.seek(linePos)){
            file.write(cur.toUtf8());
            file.write("\n");
            linePos += cur.length() + 1;
        }
        else {
            qDebug() << "Не удалось переместить указатель в файле";
        }
        file.write(buffer);
        int charCount = QString::fromUtf8(buffer).length();
        linePos += charCount;
        file.seek(linePos);
        file.resize(file.pos());
    }
    else {
        qDebug() << "Строка не найдена";
    }
    file.close();
}

void MainWindow::previousCliced(){
    int k = 0;
    for (int i = 0; i < tableWidget.rowCount(); i++){
        QRadioButton *radioButton = qobject_cast<QRadioButton*>(tableWidget.cellWidget(i, 0));
        if (radioButton && radioButton->isChecked()) {
            qDebug() << "Выбрана строка:" << i;
            k = i;
        }
    }
    Date previous = dat[k].PreviousDay();
    QDate current(previous.year, previous.month, previous.day);
    QString cur = current.toString("dd.MM.yyyy");
    QMessageBox messageBox;
    if (previous.year == -1){
      messageBox.setText("Не существует");
    }
    else
    {
      messageBox.setText(cur);
    }
    messageBox.exec();
}

void MainWindow::leapClick(){
    int k = 0;
    for (int i = 0; i < tableWidget.rowCount(); i++){
        QRadioButton *radioButton = qobject_cast<QRadioButton*>(tableWidget.cellWidget(i, 0));
        if (radioButton && radioButton->isChecked()) {
            qDebug() << "Выбрана строка:" << i;
            k = i;
        }
    }
    QString cur;
    if (dat[k].ISLeap()){
        cur = "Yes";
    }
    else
    {
        cur = "No";
    }
    QMessageBox messageBox;
    messageBox.setText(cur);
    messageBox.exec();
}

void MainWindow::openClick(){
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Открыть файл", "/home/kirill/Qt/lb2/");
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    if (!QDesktopServices::openUrl(fileUrl)) {
        qDebug() << "Не удалось открыть файл";
    }
}

void MainWindow::weekClick(){
    int k = 0;
    for (int i = 0; i < tableWidget.rowCount(); i++){
        QRadioButton *radioButton = qobject_cast<QRadioButton*>(tableWidget.cellWidget(i, 0));
        if (radioButton && radioButton->isChecked()) {
            qDebug() << "Выбрана строка:" << i;
            k = i;
        }
    }
    QString cur;
    cur = QString::number(dat[k].WeekNumber());
    QMessageBox messageBox;
    messageBox.setText(cur);
    messageBox.exec();
}

void MainWindow::bithClick(){
    int k = 0;
    for (int i = 0; i < tableWidget.rowCount(); i++){
        QRadioButton *radioButton = qobject_cast<QRadioButton*>(tableWidget.cellWidget(i, 0));
        if (radioButton && radioButton->isChecked()) {
            qDebug() << "Выбрана строка:" << i;
            k = i;
        }
    }
    QString cur;
    if (dateEdit1.text().isEmpty()){
        cur = "Заполните дату";
    }
    else {
    cur = QString::number(dat[k].DaysTillYourBithday(bithday));
    }
    QMessageBox messageBox;
    messageBox.setText(cur);
    messageBox.exec();
}

void MainWindow::durationclick() {
    int k = 0;
    for (int i = 0; i < tableWidget.rowCount(); i++){
        QRadioButton *radioButton = qobject_cast<QRadioButton*>(tableWidget.cellWidget(i, 0));
        if (radioButton && radioButton->isChecked()) {
            qDebug() << "Выбрана строка:" << i;
            k = i;
        }
    }
    QString cur;
    if (dateEdit2.text().isEmpty()){
        cur = "Заполните дату";
    }
    else{
    cur = QString::number(dat[k].Duration(usrdate));
    }
    QMessageBox messageBox;
    messageBox.setText(cur);
    messageBox.exec();
}


bool MainWindow::isDate(QString text, Date &date, QLineEdit& dateEdit){
    int parce = 0;
    int point = 0;
    for (int i = 0; i < text.size(); i++){
        if (text[i] >= '0' && text[i] <= '9' && i < text.size()-1){
            parce *= 10;
            parce += text[i].digitValue();
        }
        else if (text[i] == '.' && point < 3 && i < text.size()-1 && text[i+1] >= '0' && text[i+1] <='9'){
            point++;
            if (point == 1){
            date.setDay(parce);
            qDebug() << "   " << date.day;
            parce = 0;
            }
            if (point == 2){
            date.setMonth(parce);
            qDebug() << "   " << date.month;
            point++;
            parce = 0;
            }
        }
        else if (i == text.size()-1 && point == 3){
            parce *= 10;
            parce += text[i].digitValue();
            date.setYear(parce);
            qDebug() << "   " << date.year;
        }
        else {
            dateEdit.clear();
            return false;
        }
    }
    QDate userInputDate(date.year, date.month, date.day);
    QString data;

    if (userInputDate.isValid()) {
        data += QString("%1").arg(userInputDate.day(), 2, 10, QChar('0'));
        data += '.';
        data += QString("%1").arg(userInputDate.month(), 2, 10, QChar('0'));
        data += '.';
        if (userInputDate.year() < 9999)
        {
           data += QString("%1").arg(userInputDate.year(), 4, 10, QChar('0'));
        }
        else
        {
            data += QString("%1").arg(userInputDate.year());
        }
        dateEdit.setText(data);
        return true;
    } else {
        dateEdit.clear();
        return false;
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start();
    QMainWindow::resizeEvent(event);
}
MainWindow::~MainWindow()
{
    delete ui;
}

