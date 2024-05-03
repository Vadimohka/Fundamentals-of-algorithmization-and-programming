#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    resize(1000,723);
    setFixedSize(1000,723);
    ui->setupUi(this);
    timer = new QTimer;
    timer2 = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=](){
        update();
        if (res1 == "" && res2 == "" && res3 == ""){
            ui->bnt_add_to_file->setEnabled(false);
            ui->bnt_add_to_file->setStyleSheet("background-color: red;");
        }
        else {
            ui->bnt_add_to_file->setEnabled(true);
            ui->bnt_add_to_file->setStyleSheet("background-color: white;");
        }
        if (ui->ln_code_of_book->text().length()!=6 || ui->ln_fam->text().isEmpty()
            || ui->ln_topic->text().isEmpty() || ui->ln_year_of_edition->text().length() != 4 || ui->ln_language->text().isEmpty()){
            ui->bnt_info_book->setEnabled(false);
            ui->bnt_info_book->setStyleSheet("background-color: red;");
        }
        else {
            ui->bnt_info_book->setEnabled(true);
            ui->bnt_info_book->setStyleSheet("background-color: white;");
        }
        if (ui->ln_code_of_reader->text().length()!=6 || !Reader::isValidFullName(ui->ln_fio->text()) || !Reader::isValidAddress(ui->ln_home_adress->text()) || ui->ln_mob_number->text().length() != 13) {
            ui->bnt_info_reader->setEnabled(false);
            ui->bnt_info_reader->setStyleSheet("background-color: red;");
        }
        else {
            ui->bnt_info_reader->setEnabled(true);
            ui->bnt_info_reader->setStyleSheet("background-color: white;");
        }
        bool xz = ui->ln_vidachi->text().length()!=10 || ui->ln_vernut->text().length() != 10
                  || ui->ln_vernul->text().length() != 10 || ui->ln_codeb->text().length() !=6 || ui->ln_coder->text().length() != 6 || !isValidDate(ui->ln_vidachi->text())
                  || !isValidDate(ui->ln_vernut->text()) || !isValidDate(ui->ln_vernul->text());
        if (xz) {
            ui->bnt_info_get_book->setEnabled(false);
            ui->bnt_info_get_book->setStyleSheet("background-color: red;");
        }
        else {
            ui->bnt_info_get_book->setEnabled(true);
            ui->bnt_info_get_book->setStyleSheet("background-color: white;");
        }
        if (ui->cbx_Sort->currentIndex() == ind_lastSort) {
            ui->bntSort->setEnabled(false);
            ui->bntSort->setStyleSheet("background-color: red;");
        }
        else {
            ui->bntSort->setEnabled(true);
            ui->bntSort->setStyleSheet("background-color: white;");
        }
        if (dolj) {
            ui->bnt_dolj->setEnabled(false);
            ui->bnt_dolj->setStyleSheet("background-color: red;");
        }
        else {
            ui->bnt_dolj->setEnabled(true);
            ui->bnt_dolj->setStyleSheet("background-color: white;");
        }
    });
    ui->bnt_rem_vib->setEnabled(false);
    ui->bnt_rem_vib->setStyleSheet("background-color: red;");
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->setStyleSheet("background-color: red;");
    timer->start(25);
    QObject::connect(timer2, &QTimer::timeout, [=](){
        dolj = 0;
    });
    timer2->start(10000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayVectorInList(const QVector<QString> &data)
{
    ui->listWidget->clear();
    if (data.size() != 0) {
        for (const QString &item : data) {
            ui->listWidget->addItem(item);
        }
    }
}

void MainWindow::addtofiles(const QString &arg1, const QString path)
{
    QFile file(path);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << arg1 << '\n';
        file.close();
    }
}

void MainWindow::removeLineFromFile(const QString &filename, int lineNumberToRemove)
{
    QFile inputFile(filename);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading.";
        return;
    }
    QList<QString> lines;
    QTextStream in(&inputFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        lines.append(line);
    }
    inputFile.close();
    if (lineNumberToRemove < 0 || lineNumberToRemove >= lines.size()) {
        qDebug() << "Invalid line number.";
        return;
    }
    lines.removeAt(lineNumberToRemove);
    if (!inputFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing.";
        return;
    }
    QTextStream out(&inputFile);
    for (const QString& line : lines) {
        out << line << "\n";
    }
    inputFile.close();
}

bool MainWindow::isValidDate(const QString &dateString)
{
    QDate date = QDate::fromString(dateString, "dd.MM.yyyy");
    return date.isValid();
}

void MainWindow::my_style_button()
{
    ui->ln_code_of_book->setReadOnly(false);
    ui->ln_code_of_reader->setReadOnly(false);
    ui->ln_home_adress->setReadOnly(false);
    ui->ln_language->setReadOnly(false);
    ui->ln_vernul->setReadOnly(false);
    ui->ln_vidachi->setReadOnly(false);
    ui->ln_vernut->setReadOnly(false);
    ui->ln_year_of_edition->setReadOnly(false);
    ui->ln_mob_number->setReadOnly(false);
    ui->ln_codeb->setReadOnly(false);
    ui->ln_coder->setReadOnly(false);
    ui->ln_fio->setReadOnly(false);
    ui->ln_topic->setReadOnly(false);
    ui->ln_fam->setReadOnly(false);
    ui->ln_code_of_book->setProperty("state5", "2");
    style()->polish(ui->ln_code_of_book);
    ui->ln_code_of_reader->setProperty("state7", "2");
    style()->polish(ui->ln_code_of_reader);
    ui->ln_home_adress->setStyleSheet("background-color: white;");
    ui->ln_language->setStyleSheet("background-color: white;");
    ui->ln_vernul->setProperty("state3", "2");
    style()->polish(ui->ln_vernul);
    ui->ln_vidachi->setProperty("state1", "2");
    style()->polish(ui->ln_vidachi);
    ui->ln_vernut->setProperty("state2", "2");
    style()->polish(ui->ln_vernut);
    ui->ln_year_of_edition->setProperty("state6", "2");
    style()->polish(ui->ln_year_of_edition);
    ui->ln_mob_number->setProperty("state4", "2");
    style()->polish(ui->ln_mob_number);
    ui->ln_codeb->setProperty("state8", "2");
    style()->polish(ui->ln_codeb);
    ui->ln_coder->setProperty("state9", "2");
    style()->polish(ui->ln_coder);
    ui->ln_fio->setStyleSheet("background-color: white;");
    ui->ln_topic->setStyleSheet("background-color: white;");
    ui->ln_fam->setStyleSheet("background-color: white;");
}

void MainWindow::my_style_button2()
{
    ui->ln_code_of_book->setReadOnly(true);
    ui->ln_code_of_book->setProperty("state5", "0");
    style()->polish(ui->ln_code_of_book);
    ui->ln_code_of_reader->setReadOnly(true);
    ui->ln_code_of_reader->setProperty("state7", "0");
    style()->polish(ui->ln_code_of_reader);
    ui->ln_home_adress->setReadOnly(true);
    ui->ln_home_adress->setStyleSheet("background-color: red;");
    ui->ln_language->setReadOnly(true);
    ui->ln_language->setStyleSheet("background-color: red;");
    ui->ln_vernul->setReadOnly(true);
    ui->ln_vernul->setProperty("state3", "0");
    style()->polish(ui->ln_vernul);
    ui->ln_vidachi->setReadOnly(true);
    ui->ln_vidachi->setProperty("state1", "0");
    style()->polish(ui->ln_vidachi);
    ui->ln_vernut->setReadOnly(true);
    ui->ln_vernut->setProperty("state2", "0");
    style()->polish(ui->ln_vernut);
    ui->ln_year_of_edition->setReadOnly(true);
    ui->ln_year_of_edition->setProperty("state6", "0");
    style()->polish(ui->ln_year_of_edition);
    ui->ln_mob_number->setReadOnly(true);
    ui->ln_mob_number->setProperty("state4", "0");
    style()->polish(ui->ln_mob_number);
}

void MainWindow::setup_buttons1()
{
    ui->bnt_info_book->setEnabled(false);
    ui->bnt_info_book->setStyleSheet("background-color: red;");
    ui->bnt_info_reader->setEnabled(false);
    ui->bnt_info_reader->setStyleSheet("background-color: red;");
    ui->bnt_info_get_book->setEnabled(false);
    ui->bnt_info_get_book->setStyleSheet("background-color: red;");
    ui->bnt_add_to_file->setEnabled(false);
    ui->bnt_add_to_file->setStyleSheet("background-color: red;");
    ui->bnt_vibor->setEnabled(false);
    ui->bnt_vibor->setStyleSheet("background-color: red;");
    ui->bnt_rem_vib->setEnabled(false);
    ui->bnt_rem_vib->setStyleSheet("background-color: red;");
    ui->bntSort->setEnabled(false);
    ui->bntSort->setStyleSheet("background-color: red;");
    ui->bntOpen_Files->setEnabled(false);
    ui->bntOpen_Files->setStyleSheet("background-color: red;");
    dolj = 1;
}

void MainWindow::dis_setup_buttons1()
{
    ui->bnt_info_book->setEnabled(true);
    ui->bnt_info_book->setStyleSheet("background-color: white;");
    ui->bnt_info_reader->setEnabled(true);
    ui->bnt_info_reader->setStyleSheet("background-color: white;");
    ui->bnt_info_get_book->setEnabled(true);
    ui->bnt_info_get_book->setStyleSheet("background-color: white;");
    ui->bnt_add_to_file->setEnabled(true);
    ui->bnt_add_to_file->setStyleSheet("background-color: white;");
    ui->bnt_vibor->setEnabled(true);
    ui->bnt_vibor->setStyleSheet("background-color: white;");
    ui->bntSort->setEnabled(true);
    ui->bntSort->setStyleSheet("background-color: white;");
    ui->bntOpen_Files->setEnabled(true);
    ui->bntOpen_Files->setStyleSheet("background-color: white;");
    dolj = 0;
}

void MainWindow::setup_buttons2()
{
    ui->bnt_info_book->setEnabled(false);
    ui->bnt_info_book->setStyleSheet("background-color: red;");
    ui->bnt_info_reader->setEnabled(false);
    ui->bnt_info_reader->setStyleSheet("background-color: red;");
    ui->bnt_info_get_book->setEnabled(false);
    ui->bnt_info_get_book->setStyleSheet("background-color: red;");
    ui->bnt_add_to_file->setEnabled(false);
    ui->bnt_add_to_file->setStyleSheet("background-color: red;");
    ui->pushButton->setEnabled(false);
    ui->pushButton->setStyleSheet("background-color: red;");
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->setStyleSheet("background-color: red;");
    ui->bntSort->setEnabled(false);
    ui->bntSort->setStyleSheet("background-color: red;");
    ui->bntOpen_Files->setEnabled(false);
    ui->bntOpen_Files->setStyleSheet("background-color: red;");
    dolj = 1;
}

void MainWindow::dis_setup_buttons2()
{
    ui->bnt_info_book->setEnabled(true);
    ui->bnt_info_book->setStyleSheet("background-color: white;");
    ui->bnt_info_reader->setEnabled(true);
    ui->bnt_info_reader->setStyleSheet("background-color: white;");
    ui->bnt_info_get_book->setEnabled(true);
    ui->bnt_info_get_book->setStyleSheet("background-color: white;");
    ui->bnt_add_to_file->setEnabled(true);
    ui->bnt_add_to_file->setStyleSheet("background-color: white;");
    ui->pushButton->setEnabled(true);
    ui->pushButton->setStyleSheet("background-color: white;");
    ui->bntSort->setEnabled(true);
    ui->bntSort->setStyleSheet("background-color: white;");
    ui->bntOpen_Files->setEnabled(true);
    ui->bntOpen_Files->setStyleSheet("background-color: white;");
    dolj = 0;
}

void MainWindow::on_bntOpen_Files_clicked()
{
    QString str;
    short temp = ui->cbxFiles->currentIndex();
    if (temp == 0) str = QFileDialog::getOpenFileName(this, "Выбрать файл", path_book);
    else if (temp == 1) str = QFileDialog::getOpenFileName(this, "Выбрать файл", path_reader);
    else str = QFileDialog::getOpenFileName(this, "Выбрать файл", path_borrowing);
    QDesktopServices::openUrl(QUrl::fromLocalFile(str));
}

void MainWindow::on_ln_vidachi_textChanged(const QString &arg1)
{
    QString state1 = "0";
    QString expectedMask = "\\d{2}\\.\\d{2}\\.\\d{4}"; // Маска для даты в формате 00.00.0000
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->ln_vidachi->text()=="..") {
        state1 = "2";
    }
    else if (match.hasMatch()) {
        state1 = "1";
    }
    else {
        state1 = "0";
    }
    ui->ln_vidachi->setProperty("state1", state1);
    style()->polish(ui->ln_vidachi);
}

void MainWindow::on_ln_vernut_textChanged(const QString &arg1)
{
    QString state2 = "0";
    QString expectedMask = "\\d{2}\\.\\d{2}\\.\\d{4}"; // Маска для даты в формате 00.00.0000
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->ln_vernut->text()=="..") {
        state2 = "2";
    }
    else if (match.hasMatch()) {
        state2 = "1";
    }
    else {
        state2 = "0";
    }
    ui->ln_vernut->setProperty("state2", state2);
    style()->polish(ui->ln_vernut);
}

void MainWindow::on_ln_vernul_textChanged(const QString &arg1)
{
    QString state3 = "0";
    QString expectedMask = "\\d{2}\\.\\d{2}\\.\\d{4}"; // Маска для даты в формате 00.00.0000
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->ln_vernul->text()=="..") {
        state3 = "2";
    }
    else if (match.hasMatch()) {
        state3 = "1";
    }
    else {
        state3 = "0";
    }
    ui->ln_vernul->setProperty("state3", state3);
    style()->polish(ui->ln_vernul);
}

void MainWindow::on_bnt_info_book_clicked()
{
    QString codeb = ui->ln_code_of_book->text();
    QString fam = ui->ln_fam->text();
    QString topic = ui->ln_topic->text();
    QString year = ui->ln_year_of_edition->text();
    QString lang = ui->ln_language->text();
    QString res = QString(codeb + ';' + fam + ';' + topic + ';' + year + ';' + lang);
    if (codeb.length()!=6 || fam.isEmpty() || topic.isEmpty() || year.length() != 4 || lang.isEmpty()) {
        ui->ln_error1->setText("<html>Данные введены<br/>некорректно!!!</html>");
        res1 = "";
    }
    else {
        ui->ln_error1->setText("<html>Данные введены<br/>корректно!</html>");
        res1 = res;
    }
}

void MainWindow::on_bnt_info_reader_clicked()
{
    QString coder = ui->ln_code_of_reader->text();
    QString FIO = ui->ln_fio->text();
    QString adress = ui->ln_home_adress->text();
    QString number = ui->ln_mob_number->text();
    QString res = QString(coder + ';' + FIO + ';' + adress + ';' + number);
    if (coder.length()!=6 || !Reader::isValidFullName(FIO) || !Reader::isValidAddress(adress) || number.length() != 13) {
        ui->ln_error2->setText("<html>Данные введены<br/>некорректно!!!</html>");
        res2 = "";
    }
    else {
        ui->ln_error2->setText("<html>Данные введены<br/>корректно!</html>");
        res2 = res;
    }
}

void MainWindow::on_bnt_info_get_book_clicked()
{
    QString dateString1 = ui->ln_vidachi->text();
    QString dateString2 = ui->ln_vernut->text();
    QString dateString3 = ui->ln_vernul->text();
    QString codeb = ui->ln_codeb->text();
    QString coder = ui->ln_coder->text();
    QString res = QString(coder + ';' + codeb + ';' + dateString1 + ';' + dateString2 + ';' + dateString3);
    //l.loadBooksFromFile();
    //l.loadReadersFromFile();
    //QVector<int>test1 = l.getCodeBooks();
    //QVector<int>test2 = l.getCodeReaders();
    //|| test1.indexOf(codeb.toInt()) == -1 || test2.indexOf(coder.toInt()) == -1
    bool xz = dateString1.length()!=10 || dateString2.length() != 10
              || dateString3.length() != 10 || codeb.length() !=6 || coder.length() != 6 || !isValidDate(dateString1)
              || !isValidDate(dateString2) || !isValidDate(dateString3);
    if (xz) {
        ui->ln_error3->setText("<html>Данные введены<br/>некорректно!!!</html>");
        res3 = "";
    }
    else {
        ui->ln_error3->setText("<html>Данные введены<br/>корректно!</html>");
        res3 = res;
    }
}

void MainWindow::on_ln_mob_number_textChanged(const QString &arg1)
{
    QString state4 = "0";
    QString expectedMask = "\\+375\\d{9}";
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->ln_mob_number->text()=="+375"){
        state4 = "2";
    }
    else if (match.hasMatch()) {
        state4 = "1";
    }
    else {
        state4 = "0";
    }
    ui->ln_mob_number->setProperty("state4", state4);
    style()->polish(ui->ln_mob_number);
}

void MainWindow::on_ln_coder_textChanged(const QString &arg1)
{
    QString state9 = "0";
    QString expectedMask = "\\d{6}";
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->ln_coder->text().isEmpty()) {
        state9 = "2";
    }
    else if (match.hasMatch()) {
        state9 = "1";
    }
    else {
        state9 = "0";
    }
    ui->ln_coder->setProperty("state9", state9);
    style()->polish(ui->ln_coder);
}

void MainWindow::on_ln_codeb_textChanged(const QString &arg1)
{
    QString state8 = "0";
    QString expectedMask = "\\d{6}";
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->ln_codeb->text().isEmpty()) {
        state8 = "2";
    }
    else if (match.hasMatch()) {
        state8 = "1";
    }
    else {
        state8 = "0";
    }
    ui->ln_codeb->setProperty("state8", state8);
    style()->polish(ui->ln_codeb);
}

void MainWindow::on_ln_code_of_reader_textChanged(const QString &arg1)
{
    QString state7 = "0";
    QString expectedMask = "\\d{6}";
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->ln_code_of_reader->text().isEmpty()) {
        state7 = "2";
    }
    else if (match.hasMatch()) {
        state7 = "1";
    }
    else {
        state7 = "0";
    }
    ui->ln_code_of_reader->setProperty("state7", state7);
    style()->polish(ui->ln_code_of_reader);
}

void MainWindow::on_ln_year_of_edition_textChanged(const QString &arg1)
{
    QString state6 = "0";
    QString expectedMask = "\\d{4}";
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->ln_year_of_edition->text().isEmpty()) {
        state6 = "2";
    }
    else if (match.hasMatch()) {
        state6 = "1";
    }
    else {
        state6 = "0";
    }
    ui->ln_year_of_edition->setProperty("state6", state6);
    style()->polish(ui->ln_year_of_edition);
}

void MainWindow::on_ln_code_of_book_textChanged(const QString &arg1)
{
    QString state5 = "0";
    QString expectedMask = "\\d{6}";
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->ln_code_of_book->text().isEmpty()) {
        state5 = "2";
    }
    else if (match.hasMatch()) {
        state5 = "1";
    }
    else {
        state5 = "0";
    }
    ui->ln_code_of_book->setProperty("state5", state5);
    style()->polish(ui->ln_code_of_book);
}

void MainWindow::on_bnt_add_to_file_clicked()
{
    QString textik = "";
    if (res1.isEmpty() && res2.isEmpty() && res3.isEmpty()) {
        ui->ln_error->setText("Данные не были добавлены!!!");
    }
    else if (!res1.isEmpty() && !res2.isEmpty() && !res3.isEmpty()) {
        addtofiles(res1, path_book);
        addtofiles(res2, path_reader);
        addtofiles(res3, path_borrowing);
        ui->ln_error->setText("Данные успешно добавлены!!!");
        ui->ln_error1->clear();
        ui->ln_error2->clear();
        ui->ln_error3->clear();
    }
    else {
        QString textik = "";
        if (!res1.isEmpty()) {
            addtofiles(res1, path_book);
            textik += "Книга была добавлена; ";
            ui->ln_error1->clear();
        }
        else if (!res2.isEmpty()) {
            addtofiles(res2, path_reader);
            textik += "Читатель был добавлен; ";
            ui->ln_error2->clear();
        }
        else if (!res3.isEmpty()) {
            addtofiles(res3, path_borrowing);
            textik += "Зависимость была добавлена; ";
            ui->ln_error3->clear();
        }
        ui->ln_error->setText(textik);
    }
}

void MainWindow::on_pushButton_clicked()
{
    short temp = ui->cbxWhatWantFind->currentIndex();
    ui->pushButton->setEnabled(false);
    ui->pushButton->setStyleSheet("background-color: red;");
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_2->setStyleSheet("background-color: white;");
    setup_buttons1();
    my_style_button2();
    if (temp == 0) {
        ui->ln_codeb->setReadOnly(true);
        ui->ln_codeb->setProperty("state8", "0");
        style()->polish(ui->ln_codeb);
        ui->ln_coder->setReadOnly(true);
        ui->ln_coder->setProperty("state9", "0");
        style()->polish(ui->ln_coder);
        ui->ln_fio->setReadOnly(true);
        ui->ln_fio->setStyleSheet("background-color: red;");
        ui->ln_topic->setReadOnly(true);
        ui->ln_topic->setStyleSheet("background-color: red;");
    }
    else if (temp == 1) {
        ui->ln_codeb->setReadOnly(true);
        ui->ln_codeb->setProperty("state8", "0");
        style()->polish(ui->ln_codeb);
        ui->ln_coder->setReadOnly(true);
        ui->ln_coder->setProperty("state9", "0");
        style()->polish(ui->ln_coder);
        ui->ln_fio->setReadOnly(true);
        ui->ln_fio->setStyleSheet("background-color: red;");
        ui->ln_fam->setReadOnly(true);
        ui->ln_fam->setStyleSheet("background-color: red;");
    }
    else if (temp == 2) {
        ui->ln_coder->setReadOnly(true);
        ui->ln_coder->setProperty("state9", "0");
        style()->polish(ui->ln_coder);
        ui->ln_fio->setReadOnly(true);
        ui->ln_fio->setStyleSheet("background-color: red;");
        ui->ln_topic->setReadOnly(true);
        ui->ln_topic->setStyleSheet("background-color: red;");
        ui->ln_fam->setReadOnly(true);
        ui->ln_fam->setStyleSheet("background-color: red;");
    }
    else if (temp == 3) {
        ui->ln_codeb->setReadOnly(true);
        ui->ln_codeb->setProperty("state8", "0");
        style()->polish(ui->ln_codeb);
        ui->ln_fio->setReadOnly(true);
        ui->ln_fio->setStyleSheet("background-color: red;");
        ui->ln_topic->setReadOnly(true);
        ui->ln_topic->setStyleSheet("background-color: red;");
        ui->ln_fam->setReadOnly(true);
        ui->ln_fam->setStyleSheet("background-color: red;");
    }
    else if (temp == 4) {
        ui->ln_codeb->setReadOnly(true);
        ui->ln_codeb->setProperty("state8", "0");
        style()->polish(ui->ln_codeb);
        ui->ln_coder->setReadOnly(true);
        ui->ln_coder->setProperty("state9", "0");
        style()->polish(ui->ln_coder);
        ui->ln_topic->setReadOnly(true);
        ui->ln_topic->setStyleSheet("background-color: red;");
        ui->ln_fam->setReadOnly(true);
        ui->ln_fam->setStyleSheet("background-color: red;");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    short temp = ui->cbxWhatWantFind->currentIndex();
    if (temp == 0) {
        l.loadBooksFromFile();
        books = l.getBooksByAuthor(ui->ln_fam->text());
        QVector<QString> vec;
        for (int i = 0; i < books.size(); ++i) {
            vec.push_back(books[i].getTitle());
        }
        displayVectorInList(vec);
    }
    else if (temp == 1) {
        l.loadBooksFromFile();
        books = l.getBooksByTitle(ui->ln_topic->text());
        QVector<QString> vec;
        for (int i = 0; i < books.size(); ++i) {
            vec.push_back(QString(books[i].getAuthor()));
        }
        displayVectorInList(vec);
    }
    else if (temp == 2) {
        l.loadBooksFromFile();
        Book* book = l.getBookByCode((ui->ln_codeb->text()).toInt());
        if (book != nullptr) {
            QVector<QString> vec;
            vec.push_back(book->getTitle());
            displayVectorInList(vec);
        }
    }
    else if (temp == 3) {
        l.loadBooksFromFile();
        l.loadReadersFromFile();
        l.loadBorrowingsFromFile();
        int coderCode = ui->ln_coder->text().toInt();
        Reader* coder = l.getReaderByCode(coderCode);
        if (coder != nullptr) {
            books = l.getBooksByReader(coder);
            QVector<QString> vec;
            for (int i = 0; i < books.size(); ++i) {
                vec.push_back(QString(books[i].getTitle()));
            }
            displayVectorInList(vec);
        }
    }
    else if (temp == 4) {
        l.loadReadersFromFile();
        QString fio = ui->ln_fio->text();
        QVector<QString> vec;
        Reader* r = l.getReadersByFullName(fio);
        if (r != nullptr) {
            vec.push_back(QString::number(r->getCode()));
            displayVectorInList(vec);
        }
    }
    ui->pushButton->setEnabled(true);
    ui->pushButton->setStyleSheet("background-color: white;");
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->setStyleSheet("background-color: red;");
    dis_setup_buttons1();
    my_style_button();
}

void MainWindow::on_bnt_end_clicked()
{
    close();
}

void MainWindow::on_bnt_vibor_clicked()
{
    short temp = ui->cnxRemove->currentIndex();
    my_style_button2();
    setup_buttons2();
    ui->bnt_rem_vib->setEnabled(true);
    ui->bnt_rem_vib->setStyleSheet("background-color: white;");
    ui->bnt_vibor->setEnabled(false);
    ui->bnt_vibor->setStyleSheet("background-color: red;");
    ui->ln_fam->setReadOnly(true);
    ui->ln_fam->setStyleSheet("background-color: red;");
    if (temp == 0) {
        ui->ln_codeb->setReadOnly(true);
        ui->ln_codeb->setProperty("state8", "0");
        style()->polish(ui->ln_codeb);
        ui->ln_coder->setReadOnly(true);
        ui->ln_coder->setProperty("state9", "0");
        style()->polish(ui->ln_coder);
        ui->ln_fio->setReadOnly(true);
        ui->ln_fio->setStyleSheet("background-color: red;");
    }
    else if (temp == 1) {
        ui->ln_coder->setReadOnly(true);
        ui->ln_coder->setProperty("state9", "0");
        style()->polish(ui->ln_coder);
        ui->ln_fio->setReadOnly(true);
        ui->ln_fio->setStyleSheet("background-color: red;");
        ui->ln_topic->setReadOnly(true);
        ui->ln_topic->setStyleSheet("background-color: red;");
    }
    else if (temp == 2) {
        ui->ln_codeb->setReadOnly(true);
        ui->ln_codeb->setProperty("state8", "0");
        style()->polish(ui->ln_codeb);
        ui->ln_coder->setReadOnly(true);
        ui->ln_coder->setProperty("state9", "0");
        style()->polish(ui->ln_coder);
        ui->ln_topic->setReadOnly(true);
        ui->ln_topic->setStyleSheet("background-color: red;");
    }
    else if (temp == 3) {
        ui->ln_codeb->setReadOnly(true);
        ui->ln_codeb->setProperty("state8", "0");
        style()->polish(ui->ln_codeb);
        ui->ln_fio->setReadOnly(true);
        ui->ln_fio->setStyleSheet("background-color: red;");
        ui->ln_topic->setReadOnly(true);
        ui->ln_topic->setStyleSheet("background-color: red;");
    }
}

void MainWindow::on_bnt_rem_vib_clicked()
{
    short temp = ui->cnxRemove->currentIndex();
    my_style_button();
    dis_setup_buttons2();
    ui->bnt_vibor->setEnabled(true);
    ui->bnt_vibor->setStyleSheet("background-color: white;");
    ui->bnt_rem_vib->setEnabled(false);
    ui->bnt_rem_vib->setStyleSheet("background-color: red;");
    if (temp == 0) {
        l.loadBooksFromFile();
        l.loadBorrowingsFromFile();
        QString st = ui->ln_topic->text();
        QVector<QString> books_name = l.getNameOfBook();
        int ind1 = -1;
        for (int i = 0; i < books_name.size(); ++i) {
            if (st == books_name[i]) {
                ind1 = i;
                break;
            }
        }
        if (ind1 != -1) {
            QVector<Book> books_by_title = l.getBooksByTitle(st);
            int code = books_by_title[0].getCode();
            int ind2 = l.getIndBorrowingByCodeBook(code);
            if (ind2 != -1) {
                removeLineFromFile(path_book, ind1);
                removeLineFromFile(path_borrowing, ind2);
            }
            else removeLineFromFile(path_book, ind1);
        }
        l.loadBooksFromFile();
        l.loadBorrowingsFromFile();
    }
    else if (temp == 1) {
        l.loadBooksFromFile();
        l.loadBorrowingsFromFile();
        QString st = ui->ln_codeb->text();
        int code = st.toInt();
        int ind1, ind2;
        ind1 = l.getIndBookByCodeBook(code);
        ind2 = l.getIndBorrowingByCodeBook(code);
        if (ind1 != -1) {
            if (ind2 != -1) {
                removeLineFromFile(path_book, ind1);
                removeLineFromFile(path_borrowing, ind2);
            }
            else removeLineFromFile(path_book, ind1);
        }
        l.loadBooksFromFile();
        l.loadBorrowingsFromFile();
    }
    else if (temp == 2) {
        l.loadReadersFromFile();
        l.loadBorrowingsFromFile();
        QString st = ui->ln_fio->text();
        QVector<QString> readers_names = l.getFIOOfReader();
        int ind1 = -1;
        for (int i = 0; i < readers_names.size(); ++i) {
            if (st == readers_names[i]) {
                ind1 = i;
                break;
            }
        }
        if (ind1 != -1) {
            Reader* red = l.getReadersByFullName(st);
            int code = red->getCode();
            int ind2 = l.getIndBorrowingByCodeReader(code);
            if (ind2 != -1) {
                removeLineFromFile(path_reader, ind1);
                removeLineFromFile(path_borrowing, ind2);
            }
            else removeLineFromFile(path_reader, ind1);
        }
        l.loadReadersFromFile();
        l.loadBorrowingsFromFile();
    }
    else if (temp == 3) {
        l.loadReadersFromFile();
        l.loadBorrowingsFromFile();
        QString st = ui->ln_coder->text();
        int code = st.toInt();
        int ind1, ind2;
        ind1 = l.getIndReaderByCodeReader(code);
        ind2 = l.getIndBorrowingByCodeReader(code);
        if (ind1 != -1) {
            if (ind2 != -1) {
                removeLineFromFile(path_reader, ind1);
                removeLineFromFile(path_borrowing, ind2);
            }
            else removeLineFromFile(path_reader, ind1);
        }
        l.loadReadersFromFile();
        l.loadBorrowingsFromFile();
    }
}

void MainWindow::on_bntSort_clicked()
{
    l.loadBooksFromFile();
    l.loadReadersFromFile();
    short temp = ui->cbx_Sort->currentIndex();
    if (temp == 1 ||temp == 0 || temp == 2) {
        if (temp == 0) {
            l.bubbleSortBooksByName();
            ind_lastSort = 0;
        }
        else if (temp == 1) {
            l.bubbleSortBooksByTitle();
            ind_lastSort = 1;
        }
        else if (temp == 2) {
            l.bubbleSortBooksByYear();
            ind_lastSort = 2;
        }
        QVector<Book> vec_books = l.getBooks();
        QVector<QString> bookStrings;
        for (Book& book : vec_books) {
            QString bookString = "Автор: " + book.getAuthor() + " Название: " + book.getTitle() + " Год издания: " + QString::number(book.getYear());
            bookStrings.append(bookString);
        }
        displayVectorInList(bookStrings);
    }
    else {
        ind_lastSort = 3;
        l.bubbleSortReadersByFIO();
        QVector<Reader> vec_readers = l.getReaders();
        QVector<QString> vec;
        for (Reader& reader : vec_readers) {
            QString vecs = "ФИО: " + reader.getFullName() + " Номер телефона: " + reader.getPhoneNumber();
            vec.append(vecs);
        }
        displayVectorInList(vec);
    }
}

void MainWindow::on_bnt_dolj_clicked()
{
    dolj = 1;
    l.loadBooksFromFile();
    l.loadReadersFromFile();
    l.loadBorrowingsFromFile();
    QVector<Borrowing> overdueBorrowings = l.getOverdueBorrowings();
    QVector<QString> vec;
    for (Borrowing& borrowing : overdueBorrowings) {
        Reader* red = l.getReaderByCode(borrowing.getReaderCode());
        Book* book = l.getBookByCode(borrowing.getBookCode());
        QString str = "ФИО должника: " + red->getFullName() + " Название книги: " + book->getTitle();
        vec.append(str);
    }
    displayVectorInList(vec);
}
