#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    date = new Date(this);
    date->readDate(ui->textEdit);

    connect(ui->NextDay, &QPushButton::clicked, date, &Date::onNextDayClicked);
    connect(date, &Date::nextDayChanged, this, &MainWindow::updateNextDayTable);
    connect(ui->PreviousDay, &QPushButton::clicked, date, &Date::onPreviousDayClicked);
    connect(date, &Date::previousDayChanged, this, &MainWindow::updatePreviousDayTable);
    connect(ui->IsLeap, &QPushButton::clicked, date, &Date::onIsLeapClicked);
    connect(date, &Date::isLeapChanged, this, &MainWindow::updateIsLeapTable);
    connect(ui->WeekNumber, &QPushButton::clicked, date, &Date::weekNumber);
    connect(date, &Date::weekNumberChanged, this, &MainWindow::updateWeekNumberTable);
    connect(ui->DaysTillYourBirthday, &QPushButton::clicked, this, &MainWindow::calculateDaysTillBirthday);




ui->textEdit->setPlaceholderText("ДД.ММ.ГГГГ");


 ui->textEdit_4->setPlaceholderText("дд.мм");


ui->textEdit_3->setPlaceholderText("X");

 ui->textEdit_2->setPlaceholderText("ДД.ММ.ГГГГ");



// Установка стиля для QLCDNumber
ui->lcdNumber->setStyleSheet(
    "QLCDNumber {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #8B4513;" // Цвет рамки и ее толщина
    "border-radius: 5px;" // Закругление углов
    "}"
    );

// Установка стиля для QCalendarWidget
ui->calendarWidget->setStyleSheet(
    "QCalendarWidget {"
    "background-color: #F5DEB3;" // Цвет фона
    "color: #2F4F4F;" // Цвет текста
    "border: 2px solid #8B4513;" // Цвет рамки и ее толщина
    "border-radius: 5px;" // Закругление углов
    "}"
    );


// Установка стиля для QTabWidget
ui->tabWidget->setStyleSheet(
    "QTabWidget::pane {"
    "border: 2px solid #8B4513;" // Цвет рамки и ее толщина
    "border-radius: 5px;" // Закругление углов
    "}"
    "QTabBar::tab {"
    "background-color: #8B4513;" // Цвет фона вкладки
    "color: #FFFFFF;" // Цвет текста вкладки
    "padding: 5px;" // Отступы внутри вкладки
    "}"
    "QTabBar::tab:selected {"
    "background-color: #A0522D;" // Цвет фона выбранной вкладки
    "}"
    );

// Установка стиля для QTableWidget
ui->tableWidget->setStyleSheet(
    "QTableWidget {"
    "background-color: #F5DEB3;" // Цвет фона
    "alternate-background-color: #D2B48C;" // Цвет фона для четных строк
    "color: #2F4F4F;" // Цвет текста
    "border: 2px solid #8B4513;" // Цвет рамки и ее толщина
    "border-radius: 5px;" // Закругление углов
    "}"
    "QTableWidget::item:hover {"
    "background-color: #FFDAB9;" // Цвет фона при наведении
    "}"
    );
ui->tableWidget_2->setStyleSheet(
    "QTableWidget {"
    "background-color: #F5DEB3;" // Цвет фона
    "alternate-background-color: #D2B48C;" // Цвет фона для четных строк
    "color: #2F4F4F;" // Цвет текста
    "border: 2px solid #8B4513;" // Цвет рамки и ее толщина
    "border-radius: 5px;" // Закругление углов
    "}"
    "QTableWidget::item:hover {"
    "background-color: #FFDAB9;" // Цвет фона при наведении
    "}"
    );

// ---------------------------------------------------------------------------------------
ui->NextDay->setStyleSheet(
    "QPushButton {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #F5DEB3;" // Бежевая обводка и ее толщина
    "border-radius: 5px;" // Закругление углов
    "padding: 5px 10px;" // Отступы внутри кнопки
    "}"
    "QPushButton:hover {"
    "background-color: #A0522D;" // Цвет фона при наведении мыши
    "}"
    "QPushButton:pressed {"
    "background-color: #CD853F;" // Цвет фона при нажатии
    "}"
    );

ui->readfiledata->setStyleSheet(
    "QPushButton {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #F5DEB3;" // Бежевая обводка и ее толщина
    "border-radius: 5px;" // Закругление углов
    "padding: 5px 10px;" // Отступы внутри кнопки
    "}"
    "QPushButton:hover {"
    "background-color: #A0522D;" // Цвет фона при наведении мыши
    "}"
    "QPushButton:pressed {"
    "background-color: #CD853F;" // Цвет фона при нажатии
    "}"
    );

ui->nextdayfile->setStyleSheet(
    "QPushButton {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #F5DEB3;" // Бежевая обводка и ее толщина
    "border-radius: 5px;" // Закругление углов
    "padding: 5px 10px;" // Отступы внутри кнопки
    "}"
    "QPushButton:hover {"
    "background-color: #A0522D;" // Цвет фона при наведении мыши
    "}"
    "QPushButton:pressed {"
    "background-color: #CD853F;" // Цвет фона при нажатии
    "}"
    );

ui->DaysTillYourBirthday->setStyleSheet(
    "QPushButton {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #F5DEB3;" // Бежевая обводка и ее толщина
    "border-radius: 5px;" // Закругление углов
    "padding: 5px 10px;" // Отступы внутри кнопки
    "}"
    "QPushButton:hover {"
    "background-color: #A0522D;" // Цвет фона при наведении мыши
    "}"
    "QPushButton:pressed {"
    "background-color: #CD853F;" // Цвет фона при нажатии
    "}"
    );

ui->calculateDaysToBirthday->setStyleSheet(
    "QPushButton {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #F5DEB3;" // Бежевая обводка и ее толщина
    "border-radius: 5px;" // Закругление углов
    "padding: 5px 10px;" // Отступы внутри кнопки
    "}"
    "QPushButton:hover {"
    "background-color: #A0522D;" // Цвет фона при наведении мыши
    "}"
    "QPushButton:pressed {"
    "background-color: #CD853F;" // Цвет фона при нажатии
    "}"
    );

ui->PreviousDay->setStyleSheet(
    "QPushButton {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #F5DEB3;" // Бежевая обводка и ее толщина
    "border-radius: 5px;" // Закругление углов
    "padding: 5px 10px;" // Отступы внутри кнопки
    "}"
    "QPushButton:hover {"
    "background-color: #A0522D;" // Цвет фона при наведении мыши
    "}"
    "QPushButton:pressed {"
    "background-color: #CD853F;" // Цвет фона при нажатии
    "}"
    );

ui->WeekNumber->setStyleSheet(
    "QPushButton {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #F5DEB3;" // Бежевая обводка и ее толщина
    "border-radius: 5px;" // Закругление углов
    "padding: 5px 10px;" // Отступы внутри кнопки
    "}"
    "QPushButton:hover {"
    "background-color: #A0522D;" // Цвет фона при наведении мыши
    "}"
    "QPushButton:pressed {"
    "background-color: #CD853F;" // Цвет фона при нажатии
    "}"
    );

ui->adddays->setStyleSheet(
    "QPushButton {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #F5DEB3;" // Бежевая обводка и ее толщина
    "border-radius: 5px;" // Закругление углов
    "padding: 5px 10px;" // Отступы внутри кнопки
    "}"
    "QPushButton:hover {"
    "background-color: #A0522D;" // Цвет фона при наведении мыши
    "}"
    "QPushButton:pressed {"
    "background-color: #CD853F;" // Цвет фона при нажатии
    "}"
    );

ui->removeDate->setStyleSheet(
    "QPushButton {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #F5DEB3;" // Бежевая обводка и ее толщина
    "border-radius: 5px;" // Закругление углов
    "padding: 5px 10px;" // Отступы внутри кнопки
    "}"
    "QPushButton:hover {"
    "background-color: #A0522D;" // Цвет фона при наведении мыши
    "}"
    "QPushButton:pressed {"
    "background-color: #CD853F;" // Цвет фона при нажатии
    "}"
    );

ui->IsLeap->setStyleSheet(
    "QPushButton {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #F5DEB3;" // Бежевая обводка и ее толщина
    "border-radius: 5px;" // Закругление углов
    "padding: 5px 10px;" // Отступы внутри кнопки
    "}"
    "QPushButton:hover {"
    "background-color: #A0522D;" // Цвет фона при наведении мыши
    "}"
    "QPushButton:pressed {"
    "background-color: #CD853F;" // Цвет фона при нажатии
    "}"
    );

ui->differenceDay->setStyleSheet(
    "QPushButton {"
    "background-color: #8B4513;" // Цвет фона
    "color: #FFFFFF;" // Цвет текста
    "border: 2px solid #F5DEB3;" // Бежевая обводка и ее толщина
    "border-radius: 5px;" // Закругление углов
    "padding: 5px 10px;" // Отступы внутри кнопки
    "}"
    "QPushButton:hover {"
    "background-color: #A0522D;" // Цвет фона при наведении мыши
    "}"
    "QPushButton:pressed {"
    "background-color: #CD853F;" // Цвет фона при нажатии
    "}"
    );

//--------------------------------------------------------------------------------
setStyleSheet(
    "background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,"
    "stop: 0 #8B4513, stop: 1 #D2B48C);" // Градиент от коричневого к бежевому
    );

ui->textEdit->setStyleSheet(
    "font-size: 20pt;"
    "background-color: #FFF8DC; " // Кремовый фон
    "border: 1px solid #8B4513; " // Коричневая рамка
    "color: #2F4F4F; " // Темный цвет текста
    );
ui->textEdit_2->setStyleSheet(
    "font-size: 20pt;"
    "background-color: #FFF8DC; " // Кремовый фон
    "border: 1px solid #8B4513; " // Коричневая рамка
    "color: #2F4F4F; " // Темный цвет текста
    );
ui->textEdit_3->setStyleSheet(
    "font-size: 20pt;"
    "background-color: #FFF8DC; " // Кремовый фон
    "border: 1px solid #8B4513; " // Коричневая рамка
    "color: #2F4F4F; " // Темный цвет текста
    );
ui->textEdit_4->setStyleSheet(
    "font-size: 20pt;"
    "background-color: #FFF8DC; " // Кремовый фон
    "border: 1px solid #8B4513; " // Коричневая рамка
    "color: #2F4F4F; " // Темный цвет текста
    );


}

MainWindow::~MainWindow()
{
    delete ui;
    delete date; // Освобождаем память, выделенную для объекта Date
}


void MainWindow::calculateDaysTillBirthday() {
    QDate birthdayDate = ui->calendarWidget->selectedDate(); // Получаем дату дня рождения из QCalendarWidget
    int daysTillBirthday = date->Daysduration(birthdayDate);

    if (daysTillBirthday == -1) {
        QMessageBox::critical(this, "Ошибка", "Некорректный формат даты в текстовом поле!");
    } else {
        ui->lcdNumber->display(daysTillBirthday);
    }
}

void MainWindow::updateNextDayTable(const QString &nextDay)
{
    int rowCount = ui->tableWidget->rowCount();
    if(rowCount == 15){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        rowCount = 0; // Устанавливаем rowCount в 0, поскольку мы очистили таблицу
    }
    if (rowCount == 15) {
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
    }

    QTableWidgetItem *leapItem = new QTableWidgetItem(nextDay);
    ui->tableWidget->insertRow(rowCount); // Вставляем новую строку
    ui->tableWidget->setItem(rowCount, 0, leapItem);
}

void MainWindow::updatePreviousDayTable(const QString &previousDay)
{
    int rowCount = ui->tableWidget->rowCount();
    if(rowCount == 15){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        rowCount = 0; // Устанавливаем rowCount в 0, поскольку мы очистили таблицу
    }
    if (rowCount == 15) {
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
    }

    QTableWidgetItem *leapItem = new QTableWidgetItem(previousDay);
    ui->tableWidget->insertRow(rowCount); // Вставляем новую строку
    ui->tableWidget->setItem(rowCount, 1, leapItem);
}

void MainWindow::updateIsLeapTable(const QString &leapStatus)
{
    int rowCount = ui->tableWidget->rowCount();
    if(rowCount == 15){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        rowCount = 0; // Устанавливаем rowCount в 0, поскольку мы очистили таблицу
    }
    if (rowCount == 15) {
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
    }

    QTableWidgetItem *leapItem = new QTableWidgetItem(leapStatus);
    ui->tableWidget->insertRow(rowCount); // Вставляем новую строку
    ui->tableWidget->setItem(rowCount, 2, leapItem); // Записываем статус в столбец isLeap
}

void MainWindow::updateWeekNumberTable(short weekNumber)
{
    int rowCount = ui->tableWidget->rowCount();
    if (rowCount == 15) {
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
    }
    if (rowCount == 15) {
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
    }

    QTableWidgetItem *weekItem = new QTableWidgetItem(QString::number(weekNumber));
    ui->tableWidget->insertRow(rowCount); // Вставляем новую строку
    ui->tableWidget->setItem(rowCount, 3, weekItem); // Записываем номер недели в столбец "Week Number"
}



Date** MainWindow::readDatesFromFile(const QString& filePath, int& count) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
        return nullptr;
    }

    QList<Date*> datesList; // Создаем список объектов класса Date

    QTextStream in(&file);
    bool readingDates = true; // Флаг, указывающий на то, что мы все еще читаем даты
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed(); // Читаем строку из файла и удаляем пробельные символы по краям
        if (line.isEmpty()) {
            if (readingDates) {
                continue; // Пропускаем пустые строки до тех пор, пока читаем даты
            } else {
                break; // Выходим из цикла, если встретили пустую строку после дат
            }
        }

        QStringList dateParts = line.split("."); // Разбиваем строку на части по точке

        if (dateParts.size() == 3) { // Проверяем, что количество частей верное
            int day = dateParts[0].toInt();
            int month = dateParts[1].toInt();
            int year = dateParts[2].toInt();
            Date* date = new Date(); // Создаем новый объект класса Date
            date->setDate(day, month, year); // Устанавливаем дату в объекте Date
            datesList.append(date); // Добавляем объект в список
            readingDates = true; // Указываем, что мы все еще читаем даты
        } else {
            qDebug() << "Некорректный формат даты: " << line;
            readingDates = false; // Указываем, что встретилась некорректная строка после дат
        }
    }
    file.close();

    // Преобразуем список в динамический массив и возвращаем его
    count = datesList.size();
    Date** datesArray = new Date*[count];
    for (int i = 0; i < count; ++i) {
        datesArray[i] = datesList.at(i);
    }

    return datesArray;
}



void MainWindow::on_readfiledata_clicked()
{
    QString initialPath = QDir::homePath() + "/Downloads";
    QString filePath = QFileDialog::getOpenFileName(this, "Открыть файл", initialPath, "Текстовые файлы (*.txt)");
    if (filePath.isEmpty()) {
        return;
    }

    int count = 0;
    Date** datesArray = readDatesFromFile(filePath, count);
    if (!datesArray) {
        qDebug() << "Ошибка чтения данных из файла";
        return;
    }

    ui->tableWidget_2->setRowCount(count); // Устанавливаем количество строк в таблице

    // Записываем содержимое массива datesArray в таблицу
    for (int i = 0; i < count; ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(datesArray[i]->toString());
        ui->tableWidget_2->setItem(i, 0, item);
    }

    // Освобождаем память, выделенную для объектов
    for (int i = 0; i < count; ++i) {
        delete datesArray[i];
    }
    delete[] datesArray;
}


void MainWindow::on_nextdayfile_clicked()
{
    QString initialPath = QDir::homePath() + "/Downloads";
    QString filePath = QFileDialog::getOpenFileName(this, "Открыть файл", initialPath, "Текстовые файлы (*.txt)");
    if (filePath.isEmpty()) {
        return;
    }

    int count = 0;
    Date** datesArray = readDatesFromFile(filePath, count);
    if (!datesArray) {
        qDebug() << "Ошибка чтения данных из файла";
        return;
    }

    qDebug() << "Прочитано объектов класса Date:" << count;

   ui->tableWidget_2->setRowCount(count * (count - 1));

    for (int i = 0; i < count; ++i) {
        Date* currentDate = datesArray[i];
        currentDate->addOneDay(); // Добавляем один день к текущей дате
        QTableWidgetItem *item = new QTableWidgetItem(currentDate->toString());
        ui->tableWidget_2->setItem(i, 1, item); // Устанавливаем текст в 2 столбец таблицы
    }

    // Освобождаем память, выделенную для объектов
    for (int i = 0; i < count; ++i) {
        delete datesArray[i];
    }
    delete[] datesArray;
}


void MainWindow::on_differenceDay_clicked()
{
    QString initialPath = QDir::homePath() + "/Downloads";
    QString filePath = QFileDialog::getOpenFileName(this, "Открыть файл", initialPath, "Текстовые файлы (*.txt)");
    if (filePath.isEmpty()) {
        return;
    }

    // Считываем даты из файла
    int count = 0;
    Date** datesArray = readDatesFromFile(filePath, count);
    if (!datesArray) {
        qDebug() << "Ошибка чтения данных из файла";
        return;
    }

    // Очистка таблицы перед началом вывода

    ui->tableWidget_2->setRowCount(count * (count - 1)); // Установка количества строк

    int rowIndex = 0; // Индекс строки в таблице

    // Вывод разницы в днях между всеми парами дат в один столбец tableWidget_2
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            if (i != j) {
                QTableWidgetItem *itemIndex = new QTableWidgetItem(QString::number(i + 1) + " и " + QString::number(j + 1));
                ui->tableWidget_2->setItem(rowIndex, 2, itemIndex);

                int difference = datesArray[i]->daysDifference(*datesArray[j]);
                QTableWidgetItem *itemDifference = new QTableWidgetItem(QString::number(difference) + " дней");
                ui->tableWidget_2->setItem(rowIndex, 3, itemDifference);

                rowIndex++;
            }
        }
    }
    // Освобождаем память, выделенную для объектов
    for (int i = 0; i < count; ++i) {
        delete datesArray[i];
    }
    delete[] datesArray;
}

void MainWindow::on_adddays_clicked()
{
    QString newDate = ui->textEdit_2->toPlainText(); // Получаем введенную дату из textEdit
    QRegularExpression regex("^\\d{2}\\.\\d{2}\\.\\d{4}$");
    if (!regex.match(newDate).hasMatch()) {
        QMessageBox::critical(nullptr, "Ошибка", "Некорректный формат даты ДД.ММ.ГГГГ");

        return;
    }

    // Разбиваем строку на части
    QStringList dateParts = newDate.split(".");
    int day = dateParts[0].toInt();
    int month = dateParts[1].toInt();
    int year = dateParts[2].toInt();

    // Проверяем корректность значений дня, месяца и года
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Некорректная дата!\n"
                                                 "Неверно указан день");
        return;
    }

    if (newDate.isEmpty()) {
        QMessageBox::critical(nullptr, "Ошибка", "Пустая строка. Дата не была добавлена в файл.");

        return;
    }

    QString filePath = QDir::homePath() + "/Downloads/Ответы.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
        return;
    }

    QTextStream out(&file);
    out << newDate << "\n"; // Записываем новую дату в файл
    file.close();
QMessageBox::critical(nullptr, "ДД.ММ.ГГГГ", "Дата успешно добавлена в файл.");

}
void MainWindow::removeDateFromFile( int index) {
    QString filePath = QDir::homePath() + "/Downloads/Ответы.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
        return;
    }

    // Считываем все строки из файла
    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        lines.append(line);
    }

    file.close();

    // Удаляем строку с указанным индексом (индексация с нуля)
    if (index >=0 && index < lines.size()) {
          QMessageBox::critical(nullptr, "ДД.ММ.ГГГГ", "Дата была успешно удалена");
        qDebug() << "Удалена дата:" << lines[index] << "по индексу" << index;
        lines.removeAt(index);
    } else {
        QMessageBox::critical(nullptr, "Ошибка", "Некорректный индекс");
        return;
    }

    // Перезаписываем файл с обновленным списком строк
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла для записи";
        return;
    }

    QTextStream out(&file);
    for (const QString& line : lines) {
        out << line << Qt::endl;
    }

    file.close();
}

void MainWindow::on_removeDate_clicked()
{
    QString indexString = ui->textEdit_3->toPlainText();
    QRegularExpression regex("^[0-9]+$");
    if (!regex.match(indexString).hasMatch()) {
        QMessageBox::critical(nullptr, "Ошибка", "Некорректный ввод индекса");
        return;
    }

    int index = indexString.toInt();

    // Вызываем функцию для удаления даты из файла
    removeDateFromFile(index);
}


void MainWindow::on_calculateDaysToBirthday_clicked()
{
    // Получаем дату рождения из textEdit
    QString birthdayStr = ui->textEdit_4->toPlainText();

    // Проверяем, что дата рождения введена в правильном формате
    QRegularExpression regex("^\\d{2}\\.\\d{2}$");
    if (!regex.match(birthdayStr).hasMatch()) {
        QMessageBox::critical(nullptr, "Ошибка", "Некорректный формат даты рождения. Используйте формат 'дд.мм'.");
        return;
    }

    // Получаем текущую дату
    QDate currentDate = QDate::currentDate();

    // Получаем день и месяц дня рождения из строки
    QStringList parts = birthdayStr.split(".");
    int birthDay = parts[0].toInt();
    int birthMonth = parts[1].toInt();

    // Проверяем корректность введенного дня и месяца
    if (birthDay < 1 || birthDay > 31 || birthMonth < 1 || birthMonth > 12) {
        QMessageBox::critical(nullptr, "Ошибка", "Некорректно указан день или месяц рождения.");
        return;
    }
    // Получаем текущий месяц и день
    int currentMonth = currentDate.month();
    int currentDay = currentDate.day();

    // Вычисляем разницу в днях
    int daysToBirthday;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay <= birthDay)) {
        // Если текущий месяц меньше месяца рождения или текущий месяц равен месяцу рождения и текущий день меньше или равен дню рождения
        daysToBirthday = (birthMonth - currentMonth) * 30 + (birthDay - currentDay);
    } else {
        // Иначе, день рождения в следующем году
        daysToBirthday = (12 - currentMonth + birthMonth) * 30 + (birthDay - currentDay);
    }

    // Отображаем результат
    QString message = "До дня рождения осталось " + QString::number(daysToBirthday) + " дней.";
    QMessageBox::information(nullptr, "Дни до дня рождения", message);
}

