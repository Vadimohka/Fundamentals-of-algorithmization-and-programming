#include "mainwindow.h"
#include <QRegularExpression>
#include "fstream"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), _ui(new Ui::MainWindow) {
    _ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete _ui;
}

auto MainWindow::readDatesFromFile(const std::string &filename) -> std::vector<Date> {
    std::ifstream file(filename);
    std::vector<Date> dates;
    std::string dateStr;
    QRegularExpression dateRegEx(R"(^\d{2}-\d{2}-\d{4}$)");


    while (std::getline(file, dateStr)) {
        // Проверяем, соответствует ли строка формату dd-mm-yyyy
        if (!dateRegEx.match(QString::fromStdString(dateStr)).hasMatch()) {
            qDebug() << "Неверный формат даты";
            continue;
        }

        QStringList dateParts = QString::fromStdString(dateStr).split("-");
        Date date(dateParts[0].toInt(), dateParts[1].toInt(), dateParts[2].toInt());
        dates.push_back(date);
    }

    if (!file.eof()) {
        qDebug() << "Ошибка формата";
    }

    return dates;
}

void MainWindow::addDateFromFile() {
    QString dateStr = _ui->lineEdit->text();
    QRegularExpression dateRegEx(R"(^\d{2}-\d{2}-\d{4}$)");

    // Проверяем, соответствует ли строка формату dd-mm-yyyy
    if (!dateRegEx.match(dateStr).hasMatch()) {
        qDebug() << "Неверный формат даты";
        return;
    }

    QStringList dateParts = dateStr.split("-");
    int day = dateParts[0].toInt();
    int month = dateParts[1].toInt();
    int year = dateParts[2].toInt();

    // Проверяем, является ли день допустимым для данного месяца
    if (day > Date::DaysInMonth(month, year)) {
        qDebug() << "Недопустимое количество дней в месяце";
        return;
    }

    Date date(day, month, year);

    // Добавляем дату в вектор
    _dates.push_back(date);
}

void MainWindow::addDateToFile() {
    std::ofstream file(_filePath.toStdString(), std::ios::app);
    if (file.is_open()) {
        file << std::setw(2) << std::setfill('0') << _dates[_currentIndex].getDay() << '-'
             << std::setw(2) << std::setfill('0') << _dates[_currentIndex].getMonth()
             << '-' << std::setw(4) << std::setfill('0') << _dates[_currentIndex].getYear() << ' ';
        file.close();
    } else {
        qDebug() << "Unable to open file";
    }
}

void MainWindow::removeLastDateFromFile() {
    std::ifstream fileIn(_filePath.toStdString());
    std::vector<std::string> lines;
    std::string line;

    // Читаем все строки из файла в вектор
    while (std::getline(fileIn, line)) {
        lines.push_back(line);
    }
    fileIn.close();

    // Удаляем последнюю строку из вектора
    if (!lines.empty()) {
        lines.pop_back();
        --_currentIndex;
    }

    // Записываем все строки обратно в файл
    std::ofstream fileOut(_filePath.toStdString());
    for (const auto &line: lines) {
        fileOut << line << "\n";
    }
    fileOut.close();
}

void MainWindow::on_openFileButton_clicked() {
    _filePath = QFileDialog::getOpenFileName(this, "Выберите нужный файл", "/home/dmitry/Date", "TXT File (*.txt)");
    _dates = readDatesFromFile(_filePath.toStdString());
    if (!_dates.empty()) {
        _ui->birthdayInput->setText(_dates[0].toQString());
        _currentIndex = 0;
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1) {
    if (!_dates.empty() and arg1 < _dates.size()) {
        _ui->birthdayInput->setText(_dates[arg1].toQString());
        _currentIndex = arg1;
    }
    _ui->spinBox->setValue(_currentIndex);
    qDebug() << arg1;
}

void MainWindow::on_pushButton_6_clicked() {
    addDateFromFile();
    addDateToFile();
}

void MainWindow::on_pushButton_7_clicked() {
    removeLastDateFromFile();
}

void MainWindow::on_pushButton_clicked() {
    if (!_dates.empty()) {
        _ui->label_2->setText(_dates[_currentIndex].nextDay());
    }
}

void MainWindow::on_calculateButton_clicked() {
    if (!_dates.empty()) {
        _ui->label_4->setText(QString("%1").arg
                (_dates[_currentIndex].daysTillYourBithday(_dates[_currentIndex])));
    }
}

void MainWindow::on_pushButton_2_clicked() {
    if (!_dates.empty()) {
        _ui->label_3->setText(_dates[_currentIndex].previousDay());
    }
}

void MainWindow::on_pushButton_3_clicked() {
    if (!_dates.empty()) {
        if (_dates[_currentIndex].isLeap()) {
            _ui->label->setText("YES");
        } else {
            _ui->label->setText("NO");
        }
    }
}

void MainWindow::on_pushButton_4_clicked() {
    /* Получаем текущую дату */
    time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);

    /* Создаем объект Date для текущей даты */
    Date currentDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);

    if (!_dates.empty()) {
        _ui->label_5->setText(QString("%1").arg(_dates[_currentIndex].duration(currentDate)));
    }
}

void MainWindow::on_pushButton_5_clicked() {
    if (!_dates.empty()) {
        _ui->label_6->setText(QString("%1").arg(_dates[_currentIndex].weekNumber()));
    }
}

